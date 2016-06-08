/************************************************************************/
/*																		*/
/*	SoftSPI.cpp	--	chipKIT Software SPI Library Main File				*/
/*																		*/
/************************************************************************/
/*	Author: 	Gene Apperson											*/
/*	Copyright (c) 2011, Digilent Inc, All rights reserved				*/
/************************************************************************/
/*  Module Description: 												*/
/*																		*/
/* This is the main program module for the Digilent SoftSPI library for	*/
/* use with the chipKIT system. This library provides support for any	*/
/* number of bit-banged software SPI ports.								*/
/*																		*/
/************************************************************************/
/*  Revision History:													*/
/*																		*/
/*	11/21/2011(Gene Apperson): Created									*/
/*																		*/
/************************************************************************/
/*
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
/************************************************************************/

/* ------------------------------------------------------------ */
/*				Include File Definitions						*/
/* ------------------------------------------------------------ */

#define OPT_BOARD_INTERNAL
#include	<WProgram.h>
#include	<SoftSPI.h>


/* ------------------------------------------------------------ */
/*				Local Type and Constant Definitions				*/
/* ------------------------------------------------------------ */
#define SSPI_CORETIMER_TICKS_PER_SECOND		    (F_CPU / 2UL)
#define SSPI_CORETIMER_TICKS_PER_MICROSECOND    (SSPI_CORETIMER_TICKS_PER_SECOND / 1000000UL)

// there is an implication here, at 80MHz, 1.8MHz is about the max spi speed bit banging will go
// this is the number of nsec that is spent in the code; we need to remove this from our wait time to keep
// the spi speed accurate. This assumes and 80MHz clock so it can be measured. We scale for actual clock speed
#define SSPI_80MHZ_CODE_TIME_NANOSEC            (550UL)        // at 80MHz compiled -O2, about 550nsec; measured on a scope

// this is a non-intuitive equation. But what we are looking for is how many core timer ticks elapse while the spi transfer
// code itself executes. And the number of ticks is constant because as F_CPU increases, so does code execution at exactly the same rate.
// so tick count is independent of F_CPU.
// here is the logic...
// the actual code execution time is inversely proportional to the clock speed. If our clock speed doubles, our execuition time goes in half
// so (80MHz/F_CPU) = (adj time/80MHz time) ==> (adj time) = 80000000 * (80MHz time) / F_CPU
// then convert to ticks which is (adj time nsec) * (tick per sec) / 1000000000 nsec per sec => in ticks
// but tick per sec is F_CPU/2 == (adj time nsec) * F_CPU / 2 / 1000000000 == (80000000 * (80MHz time) / F_CPU) * (F_CPU / 2 / 1000000000)
// cross out the F_CPU and remove all of the zeros we have (8 * (80MHz time)) / 2 / 100 == 8 * (80MHz time) / 200
// now we want to split this time in half cycles, so divide by 2 and we get ticks == (8 * (80MHz time)) / 400 == (80MHz time) / 50
#define SSPI_TICK_USED_BY_CODE (SSPI_80MHZ_CODE_TIME_NANOSEC / 50UL)   
// which by the way, works out to be 11 core timer ticks for half the code execution time independent of F_CPU time

/* ------------------------------------------------------------ */
/*				Global Variables								*/
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */
/*				Local Variables									*/
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */
/*				Forward Declarations							*/
/* ------------------------------------------------------------ */
#if defined(_ALT_SD_SPI_CHIP_SELECT_)
    extern "C" void altSDInitchipSelectPin(uint8_t csPin);
    extern "C" void altSDchipSelectHigh(uint8_t csPin);
    extern "C" void altSDchipSelectLow(uint8_t csPin);
#endif

/* ------------------------------------------------------------ */
/*				Procedure Definitions							*/
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */
/*				SoftSPI Object Class Implementation				*/
/* ------------------------------------------------------------ */

/***	SoftSPI::SoftSPI
**
**	Parameters:
**		none
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		Initialize the object before use.
*/

SoftSPI::SoftSPI() {

	modCur = 0;
	cntClk = 0;
	cntDly = 0;

}

SoftSPI::SoftSPI(uint8_t pinSSt, uint8_t pinMOSIt, uint8_t pinMISOt, uint8_t pinSCKt)
{

	modCur = 0;
	cntClk = 0;
	cntDly = 0;

	/* Remember the pin numbers.
	*/
	pinSS	= pinSSt;
	pinMOSI	= pinMOSIt;
	pinMISO	= pinMISOt;
	pinSCK	= pinSCKt;

}

/***	SoftSPI::getCoreTime
**
**	Parameters:
**		none
**
**	Return Value:
**		The current core timer count
**
**	Errors:
**		none
**
**	Description:
*/
#define read_count(dest) __asm__ __volatile__("mfc0 %0,$9" : "=r" (dest))
void inline SoftSPI::waitCoreTime(uint32_t clkCnt)
{
    uint32_t startTime;
    uint32_t curTime;

    read_count(startTime);
    do
    {
        read_count(curTime);
    } while((curTime - startTime) < clkCnt);
}

/* ------------------------------------------------------------ */
/***	SoftSPI::begin
**
**	Parameters:
**		pinSSt		- digital pin to use for SS
**		pinMOSIt	- digital pin to use for MOSI
**		pinMISOt	- digital pin to use for MISO
**		pinSCKt		- digital pin to use for SCK
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		Pepare the object for use. Set the pin directions, and
**		set SS HIGH and the clock to the idle state
*/
bool
SoftSPI::begin(uint8_t pinSSt, uint8_t pinMOSIt, uint8_t pinMISOt, uint8_t pinSCKt) {

	/* Remember the pin numbers.
	*/
	pinSS	= pinSSt;
	pinMOSI	= pinMOSIt;
	pinMISO	= pinMISOt;
	pinSCK	= pinSCKt;

    return(begin());
}

bool
SoftSPI::begin(void) {

	uint8_t		port;

	/* Compute the register address and bit position for the SS pin
	*/
	if ((pinSS >= NUM_DIGITAL_PINS) || ((port = digitalPinToPort(pinSS)) == NOT_A_PIN))
	{
		return false;
	}
	iopSS = (p32_ioport *)portRegisters(port);
	bitSS = digitalPinToBitMask(pinSS);

	/* Compute the register address and bit position for the MOSI pin
	*/
	if ((pinMOSI >= NUM_DIGITAL_PINS) || ((port = digitalPinToPort(pinMOSI)) == NOT_A_PIN))
	{
		return false;
	}
	iopMOSI = (p32_ioport *)portRegisters(port);
	bitMOSI = digitalPinToBitMask(pinMOSI);

	/* Compute the register address and bit position for the MISO pin
	*/
	if ((pinSS >= NUM_DIGITAL_PINS) || ((port = digitalPinToPort(pinMISO)) == NOT_A_PIN))
	{
		return false;
	}
	iopMISO = (p32_ioport *)portRegisters(port);
	bitMISO = digitalPinToBitMask(pinMISO);

	/* Compute the register address and bit position for the SS pin
	*/
	if ((pinSCK >= NUM_DIGITAL_PINS) || ((port = digitalPinToPort(pinSCK)) == NOT_A_PIN))
	{
		return false;
	}
	iopSCK = (p32_ioport *)portRegisters(port);
	bitSCK = digitalPinToBitMask(pinSCK);

	/* Set the pin directions.
	*/
#if defined(_ALT_SD_SPI_CHIP_SELECT_)
    altSDInitchipSelectPin(pinSS);
#else
	pinMode(pinSS, OUTPUT);
#endif
	pinMode(pinMOSI, OUTPUT);
	pinMode(pinMISO, INPUT);
	pinMode(pinSCK, OUTPUT);

	/* Set the default pin states
	*/
	digitalWrite(pinSS, HIGH);
	digitalWrite(pinMOSI, LOW);

	/* Set the default mode (mode 0)
	*/
	setMode(SSPI_MODE0);

	/* Set the default shift direction (shift left)
	*/
	setDirection(SSPI_SHIFT_LEFT);

	/* Set up the default clock speed.
	*/
	setSpeed(SSPI_SPEED_DEFAULT);

	/* Set the interbyte delay to the minimum.
	*/
	setDelay(0);

    return true;
}

/* ------------------------------------------------------------ */
/***	SoftSPI::end
**
**	Parameters:
**		none
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		Deinitialize the object. Release all of the pins, by making
**		them all inputs.
*/

void
SoftSPI::end() {

	pinMode(pinSS, INPUT);
	pinMode(pinMOSI, INPUT);
	pinMode(pinMISO, INPUT);
	pinMode(pinSCK, INPUT);

}

/* ------------------------------------------------------------ */
/***	SoftSPI::setSpeed
**
**	Parameters:
**		spd			- requested SPI clock speed
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		Set the SPI clock speed to the closest supported value
**		to the requested clock speed.
*/

void
SoftSPI::setSpeed(uint32_t spd) {

    // remember, we want only half the time as we apply this
    // delay after both the rising and falling edge
    cntClk = SSPI_CORETIMER_TICKS_PER_SECOND / spd / 2;
    
    // a crude approximation to take out code execution time.
    if(cntClk > SSPI_TICK_USED_BY_CODE)
    {
        cntClk -= SSPI_TICK_USED_BY_CODE;
    }
    else
    {
        cntClk = 0;
    }
}

/* ------------------------------------------------------------ */
/***	SoftSPI::setMode
**
**	Parameters:
**		mod			- requested SPI mode
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		Set the SPI mode to the requested value. Default to mode 0
**		if an unsupported value is specified.
*/

void
SoftSPI::setMode(uint16_t mod) {

	/* Store the requested mode. The mod variable holds both SPI mode
	** and shift direction.
	*/
	modCur = (modCur & ~(SSPI_MODE3 << 1)) | ((mod & SSPI_MODE3) << 1);

	/* Set the clock pin to the correct idle state level.
	*/
	switch(mod) {
		case SSPI_MODE2:
		case SSPI_MODE3:
			digitalWrite(pinSCK, HIGH);
			break;

		case SSPI_MODE1:
		default:			// MODE 0
			digitalWrite(pinSCK, LOW);
			break;
	}

}

/* ------------------------------------------------------------ */
/***	SoftSPI::setDirection
**
**	Parameters:
**		dir			- requested shift direction
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		Set the shift direction to the requested value. Default to
**		shift left if an unsupported value is specified.
*/

void
SoftSPI::setDirection(int dir) {

	/* Store the direction in the mod variable. This variable holds
	** both the SPI mode and the shift direction.
	*/
	modCur = (modCur & ~SSPI_SHIFT_RIGHT) | (dir & SSPI_SHIFT_RIGHT);

}

/* ------------------------------------------------------------ */
/***	SoftSPI::setDelay
**
**	Parameters:
**		dly			- interbyte delay in microseconds (max 4294
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		Set the interbyte delay to the specified value.
**		The relationship between the delay count value and the
**		delay in microseconds has been determined experimentally
**		to be approximately:
**			d ~ P * (47 + 880/100 * n) where P is period of processor clock
**		This yields the delay count to be:
**
**			n = ((80*d - 47) * 100) / 880
**
**		Note: this calculations assumes that the processor clock is 80Mhz.
*/

void
SoftSPI::setDelay(int dly) {

    cntDly = (uint32_t) ((((uint64_t) SSPI_CORETIMER_TICKS_PER_SECOND) * ((uint64_t) dly)) / 1000000ULL);
}

/***	SoftSPI::setSelect
**
**	Parameters:
**		sel			- HIGH / LOW,  how to set CS
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
*/
void SoftSPI::setSelect(uint8_t sel) 
{ 
    #if defined(_ALT_SD_SPI_CHIP_SELECT_)

        if(sel == HIGH)
        {
            altSDchipSelectHigh(pinSS);
        }
        else
        {
            altSDchipSelectLow(pinSS);
        }

    #else
        digitalWrite(pinSS, sel); 
    #endif
};

/* ------------------------------------------------------------ */
/***	SoftSPI::transfer
**
**	Parameters:
**		bVal		- byte to transfer to the SPI slave device
**
**	Return Value:
**		Returns byte received from the slave
**
**	Errors:
**		none
**
**	Description:
**		Send the specified byte to the slave and return the byte
**		received from the slave.
*/

uint8_t
SoftSPI::transfer(uint8_t bVal) {

	int				cbit;
	uint8_t			bOut;
	uint8_t			bIn = 0;

	bOut = bVal;

	/* Transfer control to the case that handles the current
	** combination of SPI mode and shift direction. The shift
	** direction is in bit 0 and the SPI mode is in bits 2 & 3.
	**
	** SPI mode 0 & 2 - sample on leading edge of clock, shift on trailing edge
	** SPI mode 1 & 3 - shift on leading edge of clock, sample on trailing edge
	**
	** SPI mode 0 - clock idles low, sample on rising edge
	** SPI mode 1 - clock idles low, sample on falling edge
	** SPI mode 2 - clock idles high, sample on falling edge
	** SPI mode 3 - clock idles high, sample on rising edge
	*/
	switch(modCur) {
		case 0:		// SPI mode 0, shift left
			for (cbit = 0; cbit < 8; cbit++) {
				/* Set MOSI to the appropriate state.
				*/
				if ((bOut & 0x80) != 0) {
					iopMOSI->lat.set = bitMOSI;
				}
				else {
					iopMOSI->lat.clr = bitMOSI;
				}
				bOut <<= 1;

				/* Wait for half the clock period.
				*/
                waitCoreTime(cntClk);

				/* Set the leading edge of the clock.
				*/
				iopSCK->lat.set = bitSCK;

				/* Sample the state of the MISO pin.
				*/
				bIn = (bIn << 1) | ((iopMISO->port.reg & bitMISO) == 0 ? 0 : 1);

				/* Wait for half the clock period.
				*/
                waitCoreTime(cntClk);

				/* Set the trailing edge of the clock
				*/
				iopSCK->lat.clr = bitSCK;
			}
			break;

		case 1:		// SPI MODE 0, shift right
			for (cbit = 0; cbit < 8; cbit++) {
				/* Set MOSI to the appropriate state.
				*/
				if ((bOut & 0x01) != 0) {
					iopMOSI->lat.set = bitMOSI;
				}
				else {
					iopMOSI->lat.clr = bitMOSI;
				}
				bOut >>= 1;

				/* Wait for half the clock period.
				*/
                waitCoreTime(cntClk);

				/* Set the leading edge of the clock.
				*/
				iopSCK->lat.set = bitSCK;

				/* Sample the state of the MISO pin.
				*/
				bIn = (bIn >> 1) | ((iopMISO->port.reg & bitMISO) == 0 ? 0 : 0x80);

				/* Wait for half the clock period.
				*/
                waitCoreTime(cntClk);

				/* Set the trailing edge of the clock
				*/
				iopSCK->lat.clr = bitSCK;
			}
			break;

		case 2:		// SPI MODE 1, shift left
			for (cbit = 0; cbit < 8; cbit++) {
				/* Set the leading edge of the clock.
				*/
				iopSCK->lat.set = bitSCK;

				/* Set MOSI to the appropriate state.
				*/
				if ((bOut & 0x80) != 0) {
					iopMOSI->lat.set = bitMOSI;
				}
				else {
					iopMOSI->lat.clr = bitMOSI;
				}
				bOut <<= 1;

				/* Wait for half the clock period.
				*/
                waitCoreTime(cntClk);

				/* Set the trailing edge of the clock
				*/
				iopSCK->lat.clr = bitSCK;

				/* Sample the state of the MISO pin.
				*/
				bIn = (bIn << 1) | ((iopMISO->port.reg & bitMISO) == 0 ? 0 : 1);

				/* Wait for half the clock period.
				*/
                waitCoreTime(cntClk);
			}
			break;

		case 3:		// SPI mode 1, shift right
			for (cbit = 0; cbit < 8; cbit++) {
				/* Set the leading edge of the clock.
				*/
				iopSCK->lat.set = bitSCK;

				/* Set MOSI to the appropriate state.
				*/
				if ((bOut & 0x01) != 0) {
					iopMOSI->lat.set = bitMOSI;
				}
				else {
					iopMOSI->lat.clr = bitMOSI;
				}
				bOut >>= 1;

				/* Wait for half the clock period.
				*/
                waitCoreTime(cntClk);

				/* Set the trailing edge of the clock
				*/
				iopSCK->lat.clr = bitSCK;

				/* Sample the state of the MISO pin.
				*/
				bIn = (bIn >> 1) | ((iopMISO->port.reg & bitMISO) == 0 ? 0 : 0x80);

				/* Wait for half the clock period.
				*/
                waitCoreTime(cntClk);
			}
			break;

		case 4:		//SPI mode 2, shift left
			for (cbit = 0; cbit < 8; cbit++) {
				/* Set MOSI to the appropriate state.
				*/
				if ((bOut & 0x80) != 0) {
					iopMOSI->lat.set = bitMOSI;
				}
				else {
					iopMOSI->lat.clr = bitMOSI;
				}
				bOut <<= 1;

				/* Wait for half the clock period.
				*/
                waitCoreTime(cntClk);

				/* Set the leading edge of the clock.
				*/
				iopSCK->lat.clr = bitSCK;

				/* Sample the state of the MISO pin.
				*/
				bIn = (bIn << 1) | ((iopMISO->port.reg & bitMISO) == 0 ? 0 : 1);

				/* Wait for half the clock period.
				*/
                waitCoreTime(cntClk);

				/* Set the trailing edge of the clock
				*/
				iopSCK->lat.set = bitSCK;
			}
			break;

		case 5:		//SPI mode 2, shift right
			for (cbit = 0; cbit < 8; cbit++) {
				/* Set MOSI to the appropriate state.
				*/
				if ((bOut & 0x01) != 0) {
					iopMOSI->lat.set = bitMOSI;
				}
				else {
					iopMOSI->lat.clr = bitMOSI;
				}
				bOut >>= 1;

				/* Wait for half the clock period.
				*/
                waitCoreTime(cntClk);

				/* Set the leading edge of the clock.
				*/
				iopSCK->lat.clr = bitSCK;

				/* Sample the state of the MISO pin.
				*/
				bIn = (bIn >> 1) | ((iopMISO->port.reg & bitMISO) == 0 ? 0 : 0x80);

				/* Wait for half the clock period.
				*/
                waitCoreTime(cntClk);

				/* Set the trailing edge of the clock
				*/
				iopSCK->lat.set = bitSCK;
			}
			break;

		case 6:		//SPI mode 3, shift left
			for (cbit = 0; cbit < 8; cbit++) {
				/* Set the leading edge of the clock.
				*/
				iopSCK->lat.clr = bitSCK;

				/* Set MOSI to the appropriate state.
				*/
				if ((bOut & 0x80) != 0) {
					iopMOSI->lat.set = bitMOSI;
				}
				else {
					iopMOSI->lat.clr = bitMOSI;
				}
				bOut <<= 1;

				/* Wait for half the clock period.
				*/
                waitCoreTime(cntClk);

				/* Set the trailing edge of the clock
				*/
				iopSCK->lat.set = bitSCK;

				/* Sample the state of the MISO pin.
				*/
				bIn = (bIn << 1) | ((iopMISO->port.reg & bitMISO) == 0 ? 0 : 1);

				/* Wait for half the clock period.
				*/
                waitCoreTime(cntClk);
			}
			break;

		case 7:		//SPI mode 3, shift right
			for (cbit = 0; cbit < 8; cbit++) {
				/* Set the leading edge of the clock.
				*/
				iopSCK->lat.clr = bitSCK;

				/* Set MOSI to the appropriate state.
				*/
				if ((bOut & 0x01) != 0) {
					iopMOSI->lat.set = bitMOSI;
				}
				else {
					iopMOSI->lat.clr = bitMOSI;
				}
				bOut >>= 1;

				/* Wait for half the clock period.
				*/
                waitCoreTime(cntClk);

				/* Set the trailing edge of the clock
				*/
				iopSCK->lat.set = bitSCK;

				/* Sample the state of the MISO pin.
				*/
				bIn = (bIn >> 1) | ((iopMISO->port.reg & bitMISO) == 0 ? 0 : 0x80);

				/* Wait for half the clock period.
				*/
                waitCoreTime(cntClk);
			}
			break;

	}

	return	bIn;

}

/* ------------------------------------------------------------ */
/***	SoftSPI::transfer
**
**	Parameters:
**		cbReq		- number of bytes to transfer
**		pbSnd		- buffer containing bytes to send
**		pbRcv		- buffer to hold bytes received
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		Send the requested number of bytes, storing the bytes
**		received in the specified buffer.
*/

void
SoftSPI::transfer(uint16_t cbReq, uint8_t * pbSnd, uint8_t * pbRcv) {
	uint16_t			cbCur;

	for (cbCur = cbReq; cbCur > 0; cbCur--) {
		*pbRcv++ = transfer(*pbSnd++);
         waitCoreTime(cntDly);
	}
}

/* ------------------------------------------------------------ */
/***	SoftSPI::transfer
**
**	Parameters:
**		cbReq	- number of bytes to send to the slave
**		pbSnd	- buffer containing bytes to send
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		This function will send the requested bytes to the SPI
**		slave device, discarding the bytes received from the
**		slave.
*/

void
SoftSPI::transfer(uint16_t cbReq, uint8_t * pbSnd) {
	uint16_t			cbCur;

	for (cbCur = cbReq; cbCur > 0; cbCur--) {
		transfer(*pbSnd++);
        waitCoreTime(cntDly);
	}
}

/* ------------------------------------------------------------ */
/***	SoftSPI::transfer
**
**	Parameters:
**		cbReq	- number of bytes to receive from the slave
**		bPad	- pad byte to send to slave
**		pbRcv	- buffer to hold received bytes
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		This function will receive the specified number of bytes
**		from the slave. The given pad byte will be sent to the
**		slave to cause the received bytes to be sent.
*/

void
SoftSPI::transfer(uint16_t cbReq, uint8_t bPad, uint8_t * pbRcv) {
	uint16_t			cbCur;

	for (cbCur = cbReq; cbCur > 0; cbCur--) {
		*pbRcv++ = transfer(bPad);
         waitCoreTime(cntDly);
	}
}

/* ------------------------------------------------------------ */

/************************************************************************/

