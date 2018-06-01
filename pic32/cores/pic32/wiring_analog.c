//************************************************************************
//*	wiring_analog.c
//*
//*	Arduino core files for PIC32
//*		Copyright (c) 2010, 2011 by Mark Sproul
//*	
//*	
//************************************************************************
//*	this code is based on code Copyright (c) 2005-2006 David A. Mellis
//*	
//*	This library is free software; you can redistribute it and/or
//*	modify it under the terms of the GNU Lesser General Public
//*	License as published by the Free Software Foundation; either
//*	version 2.1 of the License, or (at your option) any later version.
//*	
//*	This library is distributed in the hope that it will be useful,
//*	but WITHOUT ANY WARRANTY; without even the implied warranty of
//*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.//*	See the GNU
//*	Lesser General Public License for more details.
//*	
//*	You should have received a copy of the GNU Lesser General
//*	Public License along with this library; if not, write to the
//*	Free Software Foundation, Inc., 59 Temple Place, Suite 330,
//*	Boston, MA 02111-1307 USA
//*	
//*	
//************************************************************************
//*	Edit History
//************************************************************************
//*	Oct 15,	2010	<MLS> Started on wiring_analog.c
//*	Oct 17,	2010	<MLS> analogRead working
//*	Oct 19,	2010	<MLS> analogWrite (PWM) working
//*	Oct 19,	2010	<MLS> turnOffPWM moved to wiring_analog.c from wiring_digital.c
//*	Apr 26,	2011	<MLS> Errata sheet PIC32MX5XX-6XX-7XX Errata.pdf item #26
//*	May  5,	2011	<MLS> Uno board does not have 1 to 1 pin mapping for analog, added analogInPinToBit
//*	May 18,	2011	<MLS> JP4 on the uno board must be in the RD9 position for PWM to work on pin 10
//*	May 23,	2011	<MLS> Added support for pin numbers to be remaped to analog numbers, (left out in iniitial version)
//*	Aug  7,	2011	<MarcMaccomb> fixed bug in Anaglog Read (Issue (#67)
//*	Aug  7,	2011	<Gene Apperson> fixed bug in Anaglog Write (Issue #70)
//*	Aug  7,	2011	<Gene Apperson> Added necessary code for analogReference (Issue #69)
//* Nov 12, 2011	<Gene Apperson> modified for board variant support
//*	Jul 26, 2012	<GeneApperson> Added PPS support for PIC32MX1xx/MX2xx devices
//	Feb  6, 2013	<Gene Apperson> Removed dependencies on the Microchip plib library
//*	Feb 17, 2012	<KeithV> Added PPS support for MZ devices
//************************************************************************

#include <p32xxxx.h>

#include "wiring_private.h"
#ifndef OPT_BOARD_INTERNAL
#define OPT_BOARD_INTERNAL  //pull in internal symbol definitons
#endif
#include "p32_defs.h"
#include "pins_arduino.h"
#include "Board_Defs.h"

uint32_t	analog_reference = 0;	//default to AVDD, AVSS

uint16_t    pwm_active = 0;			//keeps track of active PWM outputs

static uint32_t _pwmFrequency = 490; // 490Hz default
static uint32_t _pwmResolution = 8;  // 8 bit resolution
static uint32_t _pwmPeriod = 637;

static void configurePWM();

//*********************************************************************
void analogReference(uint8_t mode)
{

#if (OPT_BOARD_ANALOG_READ != 0)
	/* Peform any board specific processing.
	*/
int _board_analogReference(uint8_t mode);

	if (_board_analogReference(mode) != 0)
	{
		return;
	}
#endif

	// can't actually set the register here because the default setting
	// will connect AVCC and the AREF pin, which would cause a short if
	// there's something connected to AREF.
//	analog_reference	=	mode;
    switch(mode)
    {
        case EXTERNAL:		//select Vref+,AVSS
            analog_reference	=	0x2000;
            break;

        case EXTMINUS:		//select AVDD, Vref-
            analog_reference	=	0x4000;
            break;

        case EXTPLUSMINUS:	//select Vref+, Vref-
            analog_reference	=	0x6000;
            break;

        case DEFAULT:
        default:			//select AVDD, AVSS
            analog_reference	=	0x0000;
            break;
    }

}

#if defined(__PIC32MZEFADC__)
/* ------------------------------------------------------------ */
/***	convertWiFIREadcEFConversionStart
**
**	Parameters:
**		channelNumber - The PIC32 analog channel number as in the PIC32 datasheet
**
**	Return Value:
**      true if successfull
**
**	Errors:
**     return false if error may have occured
**
**	Description:
**      Starts the conversion process for an PIC32MZxxxxEFG chip
*/
// These two globals were created to allow breaking up the convertWiFIREadcEF() into pieces that need to share informaiton. 
// Only needed for MZ EFG chips, I'm not sure if the compier will optimize out for non MZ EFG chips
uint8_t _analogRead_vcn;
uint32_t	_analogRead_adcTRGmode; // breaking up analogRead required making a shared global 

uint8_t convertWiFIREadcEFConversionStart(uint8_t channelNumber)
{ 
    _analogRead_vcn = channelNumber;        // assume our vitual channel number is the real one
    _analogRead_adcTRGmode = ADCTRGMODE;   // save trigger mode

    // see if we are using alternate inputs
    switch(_analogRead_vcn)
    {
        case 43:
        case 44:
        case 50:
            return(0);
            break;

        case 45:
            ADCTRGMODEbits.SH0ALT = 1;
            _analogRead_vcn -= 45;
            break;

        case 46:
            ADCTRGMODEbits.SH1ALT = 1;
            _analogRead_vcn -= 45;
            break;

        case 47:
            ADCTRGMODEbits.SH2ALT = 1;
            _analogRead_vcn -= 45;
            break;

        case 48:
            ADCTRGMODEbits.SH3ALT = 1;
            _analogRead_vcn -= 45;
            break;

        case 49:
            ADCTRGMODEbits.SH4ALT = 1;
            _analogRead_vcn -= 45;
            break;

        default:
            break;
    }

    ADCCON3bits.ADINSEL   = _analogRead_vcn;            // say which channel to manually trigger
    ADCCON3bits.RQCNVRT  = 1;               // manually trigger it.
    
    return 1; // true
}

/* ------------------------------------------------------------ */
/***	convertWiFIREadcEFConversionComplete
**
**	Parameters:
**		none
**
**	Return Value:
**      zero if complete, non-zero if complete
**
**	Errors:
**     No error checking
**
**	Description:
**      Coverts the analog signal to a digital value
*/
uint32_t convertWiFIREadcEFConversionComplete()
{ 
    // wait for completion of the conversion
    if(_analogRead_vcn < 32)
    {
        uint32_t mask = 0x1 << _analogRead_vcn;
        return (ADCDSTAT1 & mask);
    }
    else
    {
        uint32_t mask = 0x1 << (_analogRead_vcn - 32);
        return (ADCDSTAT2 & mask);
    }    
}

/* ------------------------------------------------------------ */
/***	convertWiFIREadcEFConversion
**
**	Parameters:
**		none
**
**	Return Value:
**      result from last conversion
**
**	Errors:
**     No error checking
**
**	Description:
**      Checks PIC32 ADC status bits for a PIC32MZxxxx EFG for conversion complete
*/
int convertWiFIREadcEFConversion()
{ 
    // return the trigger mode to what it was
    ADCTRGMODE = _analogRead_adcTRGmode;

    // return the converted data
    return((int) ((uint32_t *) &ADCDATA0)[_analogRead_vcn]);
}

#endif

//*********************************************************************
//*	Marc McComb Aug 2011
//*	Found bug with analogRead(). When using more than one ADC input in a program, 
//*	only one result will be read with that value being mirrored in the second result.
//*	I commented out the code using the Microchip PIC32 Peripheral Libraries and substituted 
//*	direct writes to the registers as shown below. This fixed all problems and works great:
//*********************************************************************
//* These analogRead functions are to speed up the analogRead functions
//* of the chipKIT-core by allowing for non-blocking calls to 
//* analogReadConversionComplete() from our loop() while at the same
//* time not breaking existing analogRead functionality.
//* -J. Christ Nov 2016
//*********************************************************************
uint8_t	_analogRead_channelNumber; // breaking up analogRead required making a shared global 

uint8_t analogReadConversionStart(uint8_t pin){
  uint8_t ain;

	/* Check if pin number is in valid range.
	*/
	if (pin >= NUM_DIGITAL_PINS_EXTENDED)
	{
		return 0;
	}

#if (OPT_BOARD_ANALOG_READ != 0)
	/* Peform any board specific processing.
	*/
int _board_analogRead(uint8_t pin, int * val);
int	tmp;

	if (_board_analogRead(pin, &tmp) != 0)
	{
		return tmp;
	}
#endif		// OPT_BOARD_ANALOG_READ

	/* Pin number is allowed to be either the digital pin number or the
	** analog pin number. Map the input so that it is guaranteed to be
	** an analog pin number.
	*/
	ain = (pin < NUM_DIGITAL_PINS) ? digitalPinToAnalog(pin) : NOT_ANALOG_PIN;
	if (ain == NOT_ANALOG_PIN) {
		return 0;
	}

	/* Map the analog pin number to the correct analog mux channel in the
	** A/D converter. In some cases this is a direct mapping. In that case,
	** the conversion macro just returns it parameter.
	*/
	_analogRead_channelNumber = analogInPinToChannel(ain);

	/* Ensure that the pin associated with the analog channel is in analog
	** input mode, and select the channel in the input mux.
	*/
#if defined(__PIC32_PPS__)
	p32_ioport *	iop;
	uint16_t		bit;

    // here is a nasty bug. In Arduino, the pin number passed in can be a digital pin
    // or it can be an analog pin; we don't know what was passed in.
    // so check to see if an analog pin was passed in, and if it was
    // we have to manually find the actual digital pin so we can set the PIC registers.

    // if this doesn't map, than the analog pin was passed in.
    if( ain != digital_pin_to_analog_PGM[pin])
    {
        int i = 0;

        // painstakingly find the digital pin
        for(i=0; i<NUM_DIGITAL_PINS; i++)
        {
            // we found the pin
            if(ain == digital_pin_to_analog_PGM[i])
            {
                pin = i;
                break;
            }
        }

        // did not find it
        if(i == NUM_DIGITAL_PINS)
        {
            return(0);
        }
    }

	/* In MX1/MX2/MZXX devices, there is a control register ANSEL associated with
	**  each io port. We need to set the appropriate bit in the ANSEL register
	**  for the io port associated with this pin to ensure that it is in analog
	**  input mode.
	**
	** Obtain pointer to the registers for this io port.
	*/
	iop = portRegisters(digitalPinToPort(pin));             // THIS is way we needed to know the ACTUAL digital pin number.

	/* Obtain bit mask for the specific bit for this pin.
	*/
	bit = digitalPinToBitMask(pin);                         // THIS is way we needed to know the ACTUAL digital pin number.

	/* Set the bit in the ANSELx register to ensure that the pin is in
	** analog input mode.
	*/
	iop->ansel.set = bit;
#else
	/* In the other PIC32 devices, all of the analog input capable pins are
	**  in PORTB, and the AD1PCFG register is used to set the pins associated
	**  with PORTB to analog input or digital input mode. Clear the appropriate
	**  bit in AD1PCFG.
	*/
	AD1PCFGCLR = (1 << _analogRead_channelNumber);
#endif		// defined(__PIC32_PPS__)

#if defined(__PIC32MZXX__)

// If alternate ADC implementation
#if defined(__ALT_ADC_IMPL__)
    // As of this writing only WiFire and OpenScope use this feature.
    // for now, return true and let _analogReadConversion be blocking for these boards
    return true;

// EC MZ ADC code
#elif defined(__PIC32MZECADC__)
    #warning return true and let _analogReadConversion be blocking for these chips
    return true;

#elif defined(__PIC32MZEFADC__)
    return convertWiFIREadcEFConversionStart(_analogRead_channelNumber);
#else
    #error ADC code for this MZ must be added in WSystems.c and wiring_analog.c
#endif

#else
	AD1CHS = (_analogRead_channelNumber & 0xFFFF) << 16;
	AD1CON1	=	0; //Ends sampling, and starts converting

	/* Set up for manual sampling
	*/
	AD1CSSL	=	0;
	AD1CON3	=	0x000B;	//Tad = internal 22 Tpb
	AD1CON2	=	analog_reference;

	/* Turn on ADC
	*/
	AD1CON1SET	=	0x8000;
	
	/* Start sampling
	*/
	AD1CON1SET	=	0x0002;
	
	/* Delay for a bit
	*/
	delayMicroseconds(2);

	/* Start conversion
	*/
	AD1CON1CLR	=	0x0002;
	
#endif

  return true; // assume everthing worked until we have time to write better code.
}

uint32_t analogReadConversionComplete(){

#if defined(__PIC32MZXX__)

// If alternate ADC implementation
#if defined(__ALT_ADC_IMPL__)
    // As of this writing only WiFire and OpenScope use this feature.
    // for now, return true and let _analogReadConversion be blocking for these chips
    return true;

// EC MZ ADC code
#elif defined(__PIC32MZECADC__)
    #warning return true and let _analogReadConversion be blocking for these chips
    return true;
#elif defined(__PIC32MZEFADC__)
    return convertWiFIREadcEFConversionComplete();
#else
    #error ADC code for this MZ must be added in WSystems.c and wiring_analog.c
#endif

#else
	// Wait for conversion to finish
	return (AD1CON1 & 0x0001);
#endif
  
}

uint32_t analogReadConversion(){

	int analogValue = 0;

#if defined(__PIC32MZXX__)

// If alternate ADC implementation
#if defined(__ALT_ADC_IMPL__)
    analogValue = convertADC(_analogRead_channelNumber);

// EC MZ ADC code
#elif defined(__PIC32MZECADC__)
{ 
    int i,k         = 0;
    uint8_t vcn     = _analogRead_channelNumber;

    #define KVA_2_PA(v)             (((uint32_t) (v)) & 0x1fffffff)
    static uint16_t __attribute__((coherent)) ovsampValue;

    // set the channel trigger for GSWTRG source triggering
    if(_analogRead_channelNumber == 43 || _analogRead_channelNumber == 44 || _analogRead_channelNumber >= 50)
    {
        return(0);
    }
    else if(_analogRead_channelNumber >= 45 )
    {
        vcn = _analogRead_channelNumber - 45;
        AD1IMOD |= 1 << ((vcn * 2) + 16);               // say use the alt; set SHxALT
    }

    AD1CON3bits.ADINSEL = vcn;                      // manually trigger the conversion
    AD1CON1bits.FILTRDLY = AD1CON2bits.SAMC + 5;    // strictly not needed, but set the timing anyway

    // set up for 16x oversample
    AD1FLTR6            = 0;        // clear oversampling
    AD1FLTR6bits.OVRSAM = 1;        // say 16x oversampling
    AD1FLTR6bits.CHNLID = vcn;      // the ANx channel

    // setup DMA
    IEC4bits.DMA7IE = 0;    // disable DMA channel 4 interrupts
    IFS4bits.DMA7IF = 0;    // clear existing DMA channel 4 interrupt flag

    // setup DMA channel x
    DMACONbits.ON       = 1;                        // make sure the DMA is ON
    DCH7CON             = 0;                        // clear DMA channel CON
    DCH7ECON            = 0;                        // clear DMA ECON
    DCH7ECONbits.CABORT = 1;                        // reset the DMA channel
    while(DCH7CONbits.CHEN == 1);                   // make sure DMA is not enabled
    while(DCH7CONbits.CHBUSY == 1);                 // make sure DMA is not busy
    DCH7CONbits.CHPRI   = 3;                        // use highest priority
    DCH7ECONbits.CHSIRQ = _ADC1_DF6_VECTOR;         // say the ADC filter complete triggers the DMA
    DCH7ECONbits.SIRQEN = 1;                        // enable the IRQ event for triggering
    DCH7SSA             = KVA_2_PA(&AD1FLTR6);      // address of the source
    DCH7SSIZ            = 2;                        // source size is 2 bytes
    DCH7CSIZ            = 2;                        // cell size transfer
    DCH7DSA             = KVA_2_PA(&ovsampValue);   // destination address
    DCH7DSIZ            = sizeof(ovsampValue);      // destination size

    // must throw out first 16 samples
    // keep the 17th. We can not access any ADC registers
    // however we can look at the DMA to see when things complete
    for(i=0; i<17; i++)
    {
        do {

            DCH7ECONbits.CABORT = 1;                    // reset the DMA channel
            AD1FLTR6bits.AFEN   = 0;                    // make sure oversampling is OFF
            while(DCH7CONbits.CHEN == 1);               // wait for DMA to stop
            while(DCH7CONbits.CHBUSY == 1);             // wait for DMA not to be busy
            DCH7INT             = 0;                    // clear all interrupts
            DCH7CONbits.CHEN    = 1;                    // enable the DMA channel
            AD1FLTR6bits.AFEN   = 1;                    // enable oversampling

            AD1CON3bits.RQCONVRT = 1;                   // start conversion

            // we have noticed problems that the DMA channel is not always
            // triggered, so after a time out value, just try again.
            // fundamentally the problem is that AD1FLTR6bits.AFEN must
            // be reset for each oversample conversion, disable and reenabled.

            // we know a conversion is going to take 8000ns * 16, or 128 us
            // we don't want to check too often so DMA and ADC can work
            // but we don't want to wait too long and hold things up

            for(k=0; k<20; k++)                         // this is more than enough time for the conversion, 
            {                                           // really 8 should be good enough
                delayMicroseconds(16);                  // this will cause us to check about 8 times
                if(DCH7INTbits.CHBCIF == 1)
                {
                    break;                              // DMA completed and copied the oversampled result
                }
            }
        } while(DCH7INTbits.CHBCIF == 0);               // if the conversion did not finish, try again
    }
    analogValue = ovsampValue >> 2;                     // 16 oversample gets you 2 extra bits

    // we are done, clean up the DMA, oversampling filter, and ADC
    DCH7CON             = 0;
    while(DCH7CONbits.CHBUSY == 1);
    AD1CON3bits.ADINSEL = 0;
    AD1FLTR6            = 0;

    if(_analogRead_channelNumber >= 45 )
    {
        AD1IMOD &= ~(0b11 << ((vcn * 2) + 16));               // don't use alt
    }
}

#elif defined(__PIC32MZEFADC__)
    analogValue	=	convertWiFIREadcEFConversion();
#else
    #error ADC code for this MZ must be added in WSystems.c and wiring_analog.c
#endif

#else
	// Read the ADC Value
	analogValue	=	ADC1BUF0;
#endif

	return (analogValue);
}

int analogRead(uint8_t pin)
{
  if (!analogReadConversionStart(pin)) return 0;
  while( ! analogReadConversionComplete() );
  return analogReadConversion();
}

//*********************************************************************
//*	PWM output only works on the pins with hardware support. 
//*	These are defined in the appropriate pins_*.c file.
//*	For the rest of the pins, we default to digital output.
//*********************************************************************
//*	Gene Apperson Aug 2011
//*	analogWrite resets timer 2 each time it is called. 
//*	This causes the PWM to fail if it is called repeatedly with a short interval between calls.
//*	This is the suggested fixed version of analogWrite.
//*********************************************************************
void analogWrite(uint8_t pin, int val)
{
	uint16_t	timer;
	uint16_t	pwm_mask;
	p32_oc *	ocp;

	/* Check if pin number is in valid range.
	*/
	if (pin >= NUM_DIGITAL_PINS_EXTENDED)
	{
		return;
	}

#if (OPT_BOARD_ANALOG_WRITE != 0)
	/* Perform any board specific processing.
	*/
int	_board_analogWrite(uint8_t pin, int val);

	if (_board_analogWrite(pin, val) != 0)
	{
		return;
	}
#endif		// OPT_BOARD_ANALOG_WRITE

	/* Determine if this is actually a PWM capable pin or not.
	** The value in timer will be the output compare number associated with
	** the pin, or NOT_ON_TIMER if no OC is connected to the pin.
	** The values 0 or >=255 have the side effect of turning off PWM on
	** pins that are PWM capable.
	*/
	timer = digitalPinToTimerOC(pin) >> _BN_TIMER_OC;

	if ((timer == NOT_ON_TIMER) || (val == 0) || (val >= ((1 << _pwmResolution) - 1)))
	{
            /* We're going to be setting the pin to a steady state.
            ** Make sure it is set as a digital output. And then set
            ** it LOW or HIGH depending on the value requested to be
            ** written. The digitalWrite function has the side effect
            ** of turning off PWM on the pin if it happens to be a
            ** PWM capable pin.
            */
            pinMode(pin, OUTPUT);

	    if (val < ((1 << _pwmResolution) / 2))
	    {
	        digitalWrite(pin, LOW);
	    }
	    else
	    {
	        digitalWrite(pin, HIGH);
	    }
	}

	else
	{
            /* It's a PWM capable pin. Timer 2 is used for the time base
            ** for analog output, so if no PWM are currently active then
            ** Timer 2 needs to be initialized
            */
            if (pwm_active == 0)
            {
                configurePWM();
            }

            /* Generate bit mask for this output compare.
            */
            pwm_mask = (1 << (timer - (_TIMER_OC1 >> _BN_TIMER_OC)));

            /* Obtain a pointer to the output compare being being used
            ** NOTE: as of 11/15/2011 All existing PIC32 devices
            ** (PIC32MX1XX/2XX/3XX/4XX/5XX/6XX/7XX) have the output compares
            ** in consecutive locations. The base address is _OCMP1_BASE_ADDRESS
            ** and the distance between their addresses is 0x200.
            */
            ocp = (p32_oc *)(_OCMP1_BASE_ADDRESS + (0x200 * (timer - (_TIMER_OC1 >> _BN_TIMER_OC))));

            /* If the requested PWM isn't active, init its output compare. Enabling
            ** the output compare takes over control of pin direction and forces the
            ** pin to be an output.
            */
            if ((pwm_active & pwm_mask) == 0)
            {

#if defined(__PIC32_PPS__)
                volatile uint32_t *	pps;

                /* On devices with peripheral pin select, it is necessary to connect
                ** the output compare to the pin.
                */
                pps = ppsOutputRegister(pin);
                *pps = ppsOutputSelect(timerOCtoOutputSelect(timer));
#endif
                ocp->ocxR.reg   = (_pwmPeriod * val) / (1 << _pwmResolution) ;
                ocp->ocxCon.reg = OCCON_SRC_TIMER2 | OCCON_PWM_FAULT_DISABLE;
                ocp->ocxCon.set = OCCON_ON;

                pwm_active |= pwm_mask;
            }

            /* Set the duty cycle register for the requested output compare
            */
            ocp->ocxRs.reg = (_pwmPeriod * val) / (1 << _pwmResolution);
        }
}


//************************************************************************
void turnOffPWM(uint8_t timer)
{
	p32_oc *	ocp;
    uint16_t	pwm_mask = (1 << (timer - (_TIMER_OC1 >> _BN_TIMER_OC)));

    // only process this if the PWM was ON
    if((pwm_active & pwm_mask) != 0)
    {
        /* Disable the output compare.
        */
        ocp = (p32_oc *)(_OCMP1_BASE_ADDRESS + (0x200 * (timer - (_TIMER_OC1 >> _BN_TIMER_OC))));
        ocp->ocxCon.clr = OCCON_ON;

        // Turn off the bit saying that this PWM is active.
        pwm_active &= ~pwm_mask;

        // If no PWM are active, turn off the timer.
        if (pwm_active == 0)
        {
            T2CONbits.ON = 0;
        }
    }
}

static const uint32_t psval[8] = {1, 2, 4, 6, 16, 32, 64, 256};


static void configurePWM() {
    T2CONbits.ON = 0; // turn off while we make adjustments
#if defined(__PIC32MZXX__)
    CFGCONbits.OCACLK = 0;
#endif

    uint32_t baseClock = getPeripheralClock();

    uint32_t ps = 0;

    for (ps = 0; ps < 8; ps++) {
        _pwmPeriod = (baseClock / psval[ps]) / (_pwmFrequency);
        if (_pwmPeriod <= 0xFFFF) {
            break;
        }
    }

    if (_pwmPeriod > 0xFFFF) { // Impossible to make this work!
        _pwmPeriod = 0xFFFF;
        ps = 7;
    }

    T2CONbits.TCKPS = ps;
    TMR2 = 0;
    PR2 = _pwmPeriod;
    T2CONbits.ON = 1;
}

// This macro will take the existing value from the OCRS register, back-calculate
// what the supplied value to analogWrite() was, re-scale it to fit the new
// period and resolution, and re-apply it to OCRS. This should keep the duty
// cycle the same no matter what you do with the frequency and the resolution
// on a live system.

#define FIX_PWM(OC) OC = OC * (1 << oldResolution) / oldPeriod * (1 << _pwmResolution) / (1 << oldResolution) * _pwmPeriod / (1 << _pwmResolution);


void analogWriteFrequency(uint32_t f) {
    uint32_t oldPeriod = _pwmPeriod;
    uint32_t oldResolution = _pwmResolution;
    _pwmFrequency = f;

    if (pwm_active) {

        configurePWM();

#ifdef _OCMP1_BASE_ADDRESS
        FIX_PWM(OC1RS)
#endif
            
#ifdef _OCMP2_BASE_ADDRESS
        FIX_PWM(OC2RS)
#endif
            
#ifdef _OCMP3_BASE_ADDRESS
        FIX_PWM(OC3RS)
#endif
            
#ifdef _OCMP4_BASE_ADDRESS
        FIX_PWM(OC4RS)
#endif
            
#ifdef _OCMP5_BASE_ADDRESS
        FIX_PWM(OC5RS)
#endif
            
#ifdef _OCMP6_BASE_ADDRESS
        FIX_PWM(OC6RS)
#endif
            
#ifdef _OCMP7_BASE_ADDRESS
        FIX_PWM(OC7RS)
#endif
            
#ifdef _OCMP8_BASE_ADDRESS
        FIX_PWM(OC8RS)
#endif
            
#ifdef _OCMP9_BASE_ADDRESS
        FIX_PWM(OC9RS)
#endif
            
    }
}

void analogWriteResolution(uint8_t r) {
    uint32_t oldPeriod = _pwmPeriod;
    uint32_t oldResolution = _pwmResolution;
    _pwmResolution = min(r, 16);
    if (pwm_active) {
        configurePWM();

#ifdef _OCMP1_BASE_ADDRESS
        FIX_PWM(OC1RS)
#endif
            
#ifdef _OCMP2_BASE_ADDRESS
        FIX_PWM(OC2RS)
#endif
            
#ifdef _OCMP3_BASE_ADDRESS
        FIX_PWM(OC3RS)
#endif
            
#ifdef _OCMP4_BASE_ADDRESS
        FIX_PWM(OC4RS)
#endif
            
#ifdef _OCMP5_BASE_ADDRESS
        FIX_PWM(OC5RS)
#endif
            
#ifdef _OCMP6_BASE_ADDRESS
        FIX_PWM(OC6RS)
#endif
            
#ifdef _OCMP7_BASE_ADDRESS
        FIX_PWM(OC7RS)
#endif
            
#ifdef _OCMP8_BASE_ADDRESS
        FIX_PWM(OC8RS)
#endif
            
#ifdef _OCMP9_BASE_ADDRESS
        FIX_PWM(OC9RS)
#endif
    }
}
