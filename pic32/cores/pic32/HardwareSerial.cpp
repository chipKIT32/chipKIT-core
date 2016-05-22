//************************************************************************
//*	HardwareSerial.cpp
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
//*	Boston, MA  02111-1307  USA
//*	
//*	
//************************************************************************
//*		Important Note
//*			On AVR, uarts start at 0, on Pic, they start at 1
//*			So Serial is uart 1
//*			So Serial1 is really uart 2
//*			etc
//*
//************************************************************************
//*	USB support
//*		If USB is enabled, the first serial port (Serial.xxx) is redirected to USB
//*		Serial0.xxx then takes over for the 1st uart in case the programmer needs to use it as well
//************************************************************************
//*	this code is best viewed with tabs set to 4 spaces
//************************************************************************
//*	Edit History
//************************************************************************
//*	Oct 12,	2010	<MLS> Got MPLAB X working on MacOSX 1.6 for the first time
//*	Oct 12,	2010	<MLS> Discovered pic32-gcc does not support c++
//*	Oct 13,	2010	<MLS> borrowing code from "uart_interrupt.c" example from microchip
//*	Dec 13,	2010	<MLS> Interrupt must be AFTER the read
//*	Jan 22,	2011	<MLS> Working on testing serial1 -> 3
//*	Feb  6,	2011	<MLS> Uart2 working pin Pic32 starterKit (32MX360F512L)
//*	Feb  6,	2011	<MLS> Uart1B, Uart3A, Uart3B working pin Digilent MEGA (32MX795F512L)
//*	Apr 10,	2011	<MLS> Added defs for UNO board
//*	Apr 13,	2011	<MLS> Support for UART4 is NOT finished
//*	May 25, 2011	<MLS> Added support for Uart2 on UNO32
//*	Jun 17,	2011	<MLS> Added Serial4 and Serial5 for MEGA32, ISRs not finished
//*	Jun 24,	2011	<MLS> Adding USB support, code from Rich Testardi (http://www.cpustick.com/downloads.htm)
//*	Jul  3,	2011	<MLS> Fixed bug in baud rate calculation (http://www.chipkit.org/forum/viewtopic.php?f=7&t=213&p=948#p948)
//*	Sep  1,	2011	<MLS> Issue #111, #ifdefs around <plib.h>, it was being included twice
//*	Nov  1,	2011	<MLS> Issue #140, HardwareSerial not derived from Stream 
//*	Nov  1,	2011	<MLS> Also fixed some other compatibilty issues
//* Nov 12, 2012	<GeneApperson> Rewrite for board variant support
//* Sep  8, 2012    <BrianSchmalz> Fix dropping bytes on USB RX bug
//*	Jul 26, 2012	<GeneApperson> Added PPS support for PIC32MX1xx/MX2xx devices 
//* Nov 23, 2012    <BrianSchmalz> Auto-detect when to use BRGH = 1 (high baud rates)
//*	Feb  6, 2013	<GeneApperson> Removed dependencies on the Microchip plib library
//* Jan 27, 2014    <Skyler Brandt> Added support for RS485 addressing
//************************************************************************
#if !defined(__LANGUAGE_C__)
#define __LANGUAGE_C__
#endif

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

#include <p32xxxx.h>
#include <sys/attribs.h>

#include "wiring.h"
#include "wiring_private.h"

#define OPT_SYSTEM_INTERNAL
#define	OPT_BOARD_INTERNAL
#include "pins_arduino.h"

#include "HardwareSerial.h"

#if defined(_USE_USB_FOR_SERIAL_)
//	#define	_DEBUG_USB_VIA_SERIAL0_
#endif

// Definitions for a built-in TX and RX LED for USB serial.
// Relies on the board defining PIN_LED_TX and PIN_LED_RX
// Only supports active-high LEDs at the moment.
// The LED is turned on in the main code, and a timestamp
// is set for turning it off.  A task is executed every 10ms
// to turn the LED off between 10 and 20ms after it's been
// requested with xXOff(); which means that you get to actually
// see the LED in action.

#ifdef PIN_LED_TX
static volatile uint32_t gTXLedTimeout = 0;
# define TXOn() digitalWrite(PIN_LED_TX, HIGH); gTXLedTimeout = 0;
# define TXOff() gTXLedTimeout = millis();
static void TXLedSwitchOff(int id, void *tptr) {
    if (gTXLedTimeout > 0) {
        if (millis() - gTXLedTimeout >= 10) {
            digitalWrite(PIN_LED_TX, LOW);
            gTXLedTimeout = 0;
        }
    }
}
#else
# define TXOn()
# define TXOff()
#endif

#ifdef PIN_LED_RX
static volatile uint32_t gRXLedTimeout = 0;
# define RXOn() digitalWrite(PIN_LED_RX, HIGH); gRXLedTimeout = 0;
# define RXOff() gRXLedTimeout = millis();
static void RXLedSwitchOff(int id, void *tptr) {
    if (gRXLedTimeout > 0) {
        if (millis() - gRXLedTimeout >= 10) {
            digitalWrite(PIN_LED_RX, LOW);
            gRXLedTimeout = 0;
        }
    }
}
#else
# define RXOn()
# define RXOff()
#endif

extern "C"
{
void __attribute__((interrupt(),nomips16)) IntSer0Handler(void);
void __attribute__((interrupt(),nomips16)) IntSer1Handler(void);
void __attribute__((interrupt(),nomips16)) IntSer2Handler(void);
void __attribute__((interrupt(),nomips16)) IntSer3Handler(void);
void __attribute__((interrupt(),nomips16)) IntSer4Handler(void);
void __attribute__((interrupt(),nomips16)) IntSer5Handler(void);
void __attribute__((interrupt(),nomips16)) IntSer6Handler(void);
void __attribute__((interrupt(),nomips16)) IntSer7Handler(void);
}

/* ------------------------------------------------------------ */
/*			General Declarations								*/
/* ------------------------------------------------------------ */
// Baud rate above which we use high baud divisor (BRGH = 1)
#define LOW_HIGH_BAUD_SPLIT     200000

/* ------------------------------------------------------------ */
/*			HardwareSerial Object Class Implementation			*/
/* ------------------------------------------------------------ */
/***	HardwareSerial::HardwareSerial
**
**	Parameters:
**		uartP		- pointer to base register for UART
**		irqP		- base IRQ number for the UART
**		vecP		- interrupt vector number used by this UART
**		iplP		- interrupt priority level for the interrupt
**		splP		- interrupt sub-priority level
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		Object constructor. Initialize member variables, and
**		any global variables used by the object.
*/

#if defined(__PIC32_PPS__)
HardwareSerial::HardwareSerial(p32_uart * uartT, int irqT, int vecT, int iplT, int splT, isrFunc isrHandler, int pinT, int pinR, ppsFunctionType ppsT, ppsFunctionType ppsR)
#else
HardwareSerial::HardwareSerial(p32_uart * uartT, int irqT, int vecT, int iplT, int splT, isrFunc isrHandler)
#endif
{
	uart = uartT;
	irq  = irqT;
	vec  = vecT;
	irq  = (uint8_t)irqT;
	vec  = (uint8_t)vecT;
	ipl  = (uint8_t)iplT;
	spl  = (uint8_t)splT;
    isr  = isrHandler;
    rxIntr = NULL;

#if defined(__PIC32_PPS__)
	pinTx = (uint8_t)pinT;
	pinRx = (uint8_t)pinR;
	ppsTx = ppsT;
	ppsRx = ppsR;
#endif

	/* The interrupt flag and enable control register addresses and
	** the bit numbers for the flag bits can be computed from the
	** IRQ number for the UART. The irq parameter specifies the IRQ
	** for the ERR interrupt. The RX interrupt IRQ is ERR+1 and the
	** TX interrupt IRQ is ERR+2; There are 32 IRQ bits in each IFS
	** and IEC register. For each IFS register, there is a SET, CLR,
	** and INV register, so the distance (in dwords) from IFS0 to IFS1
	** is 4.
	** The interrupt priorty control register address and the priority bits
	** can be computed from the vector number. Each IPC register contains the
	** the priority bits for four vectors. Each byte of an IPC registger contains
	** the priority and sub-priority bits arranged such that  bits 0-1 are
	** the sub-priority, bits 2-4 the priority, and bits 5-7 unused.
	*/
	ifs = ((p32_regset *)&IFS0) + (irq / 32);	//interrupt flag register set
	iec = ((p32_regset *)&IEC0) + (irq / 32);	//interrupt enable control reg set

	bit_err = 1 << (irq % 32);		//error interrupt flag/enable bit
	bit_rx  = 1 << ((irq+1) % 32);	//rx interrupt flag/enable bit
	bit_tx  = 1 << ((irq+2) % 32);	//tx interrupt flag/enable bit
}

/* ------------------------------------------------------------ */
/***	HardwareSerial::begin
**
**	Parameters:
**		baudRate		- baud rate to use on port
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		Initialize the UART for use, setting the baud rate to the
**		requested value, data size of 8-bits, and no parity.
*/

void HardwareSerial::begin(unsigned long baudRate)
{
	/* Initialize the receive buffer.
	*/
	purge();

#if defined(__PIC32_PPS__)

    // set the pins to digital, just in case they 
    // are analog pins. The serial controller will not
    // set these to digital.
    pinMode(pinTx, INPUT); // let serial controller set as output, keep tri-stated for now.
    pinMode(pinRx, INPUT);

	/* Map the UART TX to the appropriate pin.
	*/
    mapPps(pinTx, ppsTx);

	/* Map the UART RX to the appropriate pin.
	*/
    mapPps(pinRx, ppsRx);

// the only UART on a non-PPS MX that conflicts with an analog
// pin is UART5 on MX 5,6,& 7 64 pin parts only.
#elif __PIC32_PINS__ == 64 && (defined(__PIC32MX5XX__) || defined(__PIC32MX6XX__)  || defined(__PIC32MX7XX__))

    // see if this is UART5
    if(uart == ((p32_uart *) _UART5_BASE_ADDRESS))
    {
        // RB8 is AN8 & U5RX
        // RB14 is AN14 & U5TX
        // set as digital pins
        AD1PCFGbits.PCFG8 = 1;
        AD1PCFGbits.PCFG14 = 1;
    }
#endif

    setIntVector(vec, isr);

	/* Set the interrupt privilege level and sub-privilege level
	*/
	setIntPriority(vec, ipl, spl);

        // MZ has 2 more vectors to worry about
#if defined(__PIC32MZXX__)

        // the MZ part works off of offset tables
        // we must fill in the tx and rx VECs to point
        // to the ERR VEC so all 3 VECs use the same ISR
        setIntVector(vec+1, isr);
        setIntVector(vec+2, isr);

        // and set the priorities for the other 2 vectors.
        setIntPriority(vec+1, ipl, spl);
        setIntPriority(vec+2, ipl, spl);
#endif

	/* Clear the interrupt flags, and set the interrupt enables for the
	** interrupts used by this UART.
	*/
	ifs->clr = bit_rx + bit_tx + bit_err;	//clear all interrupt flags

	iec->clr = bit_rx + bit_tx + bit_err;	//disable all interrupts
	iec->set = bit_rx;						//enable rx interrupts

	/* Initialize the UART itself.
	**	http://www.chipkit.org/forum/viewtopic.php?f=7&t=213&p=948#p948
    ** Use high baud rate divisor for bauds over LOW_HIGH_BAUD_SPLIT
    */
	uart->uxSta.reg = 0;
    if (baudRate < LOW_HIGH_BAUD_SPLIT)
    {
        uart->uxBrg.reg    = ((__PIC32_pbClk / 16 / baudRate) - 1);      // calculate actual BAUD generate value.
        uart->uxMode.reg = (1 << _UARTMODE_ON);                          // enable UART module
    }
    else
    {
        uart->uxBrg.reg    = ((__PIC32_pbClk / 4 / baudRate) - 1);       // calculate actual BAUD generate value.
        uart->uxMode.reg = (1 << _UARTMODE_ON) | (1 << _UARTMODE_BRGH);  // enable UART module
    }
    uart->uxSta.reg  = (1 << _UARTSTA_UTXEN) + (1 << _UARTSTA_URXEN);    // enable transmitter and receiver
}

/* ------------------------------------------------------------ */
/***	HardwareSerial::begin
**
**	Parameters:
**		baudRate		- baud rate to use on port
**      address         - address for RS485 communication
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		Initialize the UART for use, setting the baud rate to the
**		requested value, data size of 9-bits, and no parity and 
**      address detection mode
*/

void HardwareSerial::begin(unsigned long baudRate, uint8_t address) {
	/* Initialize the receive buffer.
	*/
	purge();

#if defined(__PIC32_PPS__)

    // set the pins to digital, just in case they 
    // are analog pins. The serial controller will not
    // set these to digital.
    pinMode(pinTx, INPUT); // let serial controller set as output, keep tri-stated for now.
    pinMode(pinRx, INPUT);

	/* Map the UART TX to the appropriate pin.
	*/
    mapPps(pinTx, ppsTx);

	/* Map the UART RX to the appropriate pin.
	*/
    mapPps(pinRx, ppsRx);

// the only UART on a non-PPS MX that conflicts with an analog
// pin is UART5 on MX 5,6,& 7 64 pin parts only.
#elif __PIC32_PINS__ == 64 && (defined(__PIC32MX5XX__) || defined(__PIC32MX6XX__)  || defined(__PIC32MX7XX__))

    // see if this is UART5
    if(uart == ((p32_uart *) _UART5_BASE_ADDRESS))
    {
        // RB8 is AN8 & U5RX
        // RB14 is AN14 & U5TX
        // set as digital pins
        AD1PCFGbits.PCFG8 = 1;
        AD1PCFGbits.PCFG14 = 1;
    }
#endif

    setIntVector(vec, isr);

	/* Set the interrupt privilege level and sub-privilege level
	*/
	setIntPriority(vec, ipl, spl);

        // MZ has 2 more vectors to worry about
#if defined(__PIC32MZXX__)

        // the MZ part works off of offset tables
        // we must fill in the tx and rx VECs to point
        // to the ERR VEC so all 3 VECs use the same ISR
        setIntVector(vec+1, isr);
        setIntVector(vec+2, isr);

        // and set the priorities for the other 2 vectors.
        setIntPriority(vec+1, ipl, spl);
        setIntPriority(vec+2, ipl, spl);
#endif

    /* Clear the interrupt flags, and set the interrupt enables for the
    ** interrupts used by this UART.
    */
    ifs->clr = bit_rx + bit_tx + bit_err;	//clear all interrupt flags

    iec->clr = bit_rx + bit_tx + bit_err;	//disable all interrupts
    iec->set = bit_rx;						//enable rx interrupts

    /* Initialize the UART itself.
    **	http://www.chipkit.org/forum/viewtopic.php?f=7&t=213&p=948#p948
    ** Use high baud rate divisor for bauds over LOW_HIGH_BAUD_SPLIT
    */
    uart->uxMode.reg = 0;
    uart->uxSta.reg = 0;
    if (baudRate < LOW_HIGH_BAUD_SPLIT) {
        // calculate actual BAUD generate value.
        uart->uxBrg.reg = ((__PIC32_pbClk / 16 / baudRate) - 1);  
        // set to 9 data bits, no parity
        uart->uxMode.set = 0b11 << _UARTMODE_PDSEL;                             
    } else {
        // calculate actual BAUD generate value.
        uart->uxBrg.reg = ((__PIC32_pbClk / 4 / baudRate) - 1);
        // set to 9 data bits, no parity
        uart->uxMode.set =  (1 << _UARTMODE_BRGH) + (0b11 << _UARTMODE_PDSEL); 
    }
    // set address of RS485 slave, enable transmitter and receiver and auto address detection
    uart->uxSta.set = (1 << _UARTSTA_ADM_EN) + (address << _UARTSTA_ADDR) + (1 << _UARTSTA_UTXEN) + (1 << _UARTSTA_URXEN);  
    enableAddressDetection(); // enable auto address detection
    uart->uxMode.set = 1 << _UARTMODE_ON; // enable UART module
}

/* ------------------------------------------------------------ */
/***	HardwareSerial::end
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
**		Disable the UART and UART interrupts.
*/

void HardwareSerial::end()
{
	p32_regset *	iec;	//interrupt enable control register set

	/* Disable all UART interrupts.
	*/
	iec = ((p32_regset *)&IEC0) + (irq / 32);	//interrupt enable control reg set
	iec->clr = bit_err + bit_rx + bit_tx;
	
	/* Disable the UART so that the pins can be used as general purpose I/O
	*/
	uart->uxMode.reg =	0;

    clearIntVector(vec);
}

/* ------------------------------------------------------------ */
/***	HardwareSerial.available
**
**	Parameters:
**		none
**
**	Return Value:
**		Returns the number of characters available in the receive buffer
**
**	Errors:
**		none
**
**	Description:
**		Return the number of characters currently available in the
**		receive buffer.
*/

int HardwareSerial::available(void)
{
	return (RX_BUFFER_SIZE + rx_buffer.head - rx_buffer.tail) % RX_BUFFER_SIZE;
}

/* ------------------------------------------------------------ */
/***	HardwareSerial::peek
**
**	Parameters:
**		none
**
**	Return Value:
**		returns the next character from the receive buffer
**
**	Errors:
**		returns -1 if no characters in buffer
**
**	Description:
**		This returns the next character in the receive buffer without
**		removing it from the buffer, or -1 if no characters are in the buffer.
*/

int HardwareSerial::peek()
{
	if (rx_buffer.head == rx_buffer.tail)
	{
		return -1;
	}
	else
	{
		return rx_buffer.buffer[rx_buffer.tail];
	}
}

/* ------------------------------------------------------------ */
/***	HardwareSerial::read
**
**	Parameters:
**		none
**
**	Return Value:
**		next character from the receive buffer
**
**	Errors:
**		returns -1 if no characters in buffer
**
**	Description:
**		Return the next character from the receive buffer and remove
**		it from the buffer, or -1 if no characters are available in
**		the buffer.
*/

int HardwareSerial::read(void)
{
	unsigned char theChar;

	// if the head isn't ahead of the tail, we don't have any characters
	if (rx_buffer.head == rx_buffer.tail)
	{
		return -1;
	}
	else
	{
		theChar			= rx_buffer.buffer[rx_buffer.tail];
		rx_buffer.tail	= (rx_buffer.tail + 1) % RX_BUFFER_SIZE;
		return (theChar);
	}
}

/* ------------------------------------------------------------ */
/***	HardwareSerial::flush
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
**		Empty the send buffer by waiting for the
**		fifo to empty and the transmitter to become idle
*/
void HardwareSerial::flush()
{
	while ((uart->uxSta.reg & (1 << _UARTSTA_TMRT)) == 0)	//check the TRMT bit
	{
		//* wait for the transmitter to be clear
	}
}

/* ------------------------------------------------------------ */
/***	HardwareSerial::purge
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
**		Empty the receive buffer by discarding any characters in
**		the buffer.
*/

void HardwareSerial::purge()
{
	// don't reverse this or there may be problems if the RX interrupt
	// occurs after reading the value of rx_buffer_head but before writing
	// the value to rx_buffer_tail; the previous value of rx_buffer_head
	// may be written to rx_buffer_tail, making it appear as if the buffer
	// don't reverse this or there may be problems if the RX interrupt
	// occurs after reading the value of rx_buffer_head but before writing
	// the value to rx_buffer_tail; the previous value of rx_buffer_head
	// may be written to rx_buffer_tail, making it appear as if the buffer
	// were full, not empty.
	rx_buffer.head = rx_buffer.tail;
}

/* ------------------------------------------------------------ */
/***	HardwareSerial::write
**
**	Parameters:
**		theChar		- the character to transmit
**
**	Return Value:
**		none
**
**	Errors:
**		none
**
**	Description:
**		Wait until the transmitter is idle, and then transmit the
**		specified character.
*/

size_t HardwareSerial::write(uint8_t theChar)
{

	while ((uart->uxSta.reg & (1 << _UARTSTA_UTXBF)) != 0)	//check the UTXBF bit
  {
		//* wait for the transmitter buffer to have room
	}

	uart->uxTx.reg = theChar;
    return 1;
}

// Hardware serial is always connected regardless.
HardwareSerial::operator int() {
    return 1;
}

/* ------------------------------------------------------------ */
/***	HardwareSerial::doSerialInt
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
**		This function is called by the interrupt service routine
**		for the UART being used by this object. It's purpose is
**		to process receive interrupts and place the received
**		characters into the receive buffer.
*/

void HardwareSerial::doSerialInt(void)
{
	int		bufIndex;
	uint8_t	ch;

	/* If it's a receive interrupt, get the character and store
	** it in the receive buffer.
	*/
	if ((ifs->reg & bit_rx) != 0)
	{
		ch = uart->uxRx.reg;
        if (rxIntr != NULL) {
            /* If we have had an interrupt callback routine defined then call
            ** that instead of adding the character to the queue. Pass the
            ** received character to the function for processing.
            */
            rxIntr(ch);
        } else {
            bufIndex	= (rx_buffer.head + 1) % RX_BUFFER_SIZE;
        
            /* If we should be storing the received character into the location
            ** just before the tail (meaning that the head would advance to the
            ** current location of the tail), we're about to overflow the buffer
            ** and so we don't write the character or advance the head.
            */
            if (bufIndex != rx_buffer.tail)
            {
                rx_buffer.buffer[rx_buffer.head] = ch;
                rx_buffer.head = bufIndex;
            }
        }

		/* Clear the interrupt flag.
		*/
		ifs->clr = bit_rx;
	}

	/* If it's a transmit interrupt, ignore it, as we don't current
	** have interrupt driven i/o on the transmit side.
	*/
	if ((ifs->reg & bit_tx) != 0)
	{
		/* Clear the interrupt flag.
		*/
		ifs->clr = bit_tx;
	}

}

/* Attach the interrupt by storing a function pointer in the rxIntr variable */
void HardwareSerial::attachInterrupt(void (*callback)(int)) {
    rxIntr = callback;
}

/* Detatching the interrupt is as simple as setting the rxIntr to null. */
void HardwareSerial::detachInterrupt() {
    rxIntr = NULL;
}

/* Sets the bit in the UART status register that enables address detection */
void HardwareSerial::enableAddressDetection(void) {
    uart->uxSta.set = 1 << _UARTSTA_ADDEN;
}

/* Clears the bit in the UART status register that enables address detection */
void HardwareSerial::disableAddressDetection(void) {
    uart->uxSta.clr = 1 << _UARTSTA_ADDEN;
}

/* ------------------------------------------------------------ */
/*				USBSerial Object Class Implementation			*/
/* ------------------------------------------------------------ */


//*******************************************************************************************

#if defined(_USB) && defined(_USE_USB_FOR_SERIAL_)

#include	"HardwareSerial_cdcacm.h"
#include	"HardwareSerial_usb.h"

ring_buffer rx_bufferUSB = { { 0 }, 0, 0 };

#define     USBSerialBufferFree()     (((RX_BUFFER_SIZE - 1) + rx_bufferUSB.tail - rx_bufferUSB.head) % RX_BUFFER_SIZE)

//*******************************************************************************************
// Return TRUE if we could take the character, return FALSE if there wasn't room
inline boolean store_char(unsigned char theChar, ring_buffer *rx_buffer)
{
int	bufIndex;

    // Compute the place where we want to store this byte - one beyond the head
	bufIndex	= (rx_buffer->head + 1) % RX_BUFFER_SIZE;

    // If the place where we are about to store the character is the tail, then
    // we would overflow the buffer if we put our character there. This is because
    // if head = tail, the buffer is empty. If head = tail-1, then the buffer
    // is full. So only write into the buffer if we are not writing at the tail.
	if (bufIndex != rx_buffer->tail)
	{
		rx_buffer->buffer[rx_buffer->head]	=	theChar;
		rx_buffer->head	=	bufIndex;
        return(true);
	}
    else
    {
        return(false);
	}
}

//****************************************************************
void	USBresetRoutine(void)
{
	
}

//****************************************************************
// Need to return FALSE if we need USB to hold off for awhile
boolean	USBstoreDataRoutine(const byte *buffer, int length)
{
    int	i;
    RXOn();

    // If we have a receive callback defined then repeatedly
    // call it with each character.
    if (Serial.rxIntr != NULL) {
        for (i = 0; i < length; i++) {
            Serial.rxIntr(buffer[i]);
        }
        RXOff();
        return true;
    }

    // Put each byte into the serial recieve buffer
    for (i=0; i<length; i++)
	{
        store_char(buffer[i], &rx_bufferUSB);
	}
    // If there isn't going to be enough space for a whole nother buffer, then return
    // false so USB will NAK and we won't get any more data.
    if (USBSerialBufferFree() < USB_SERIAL_MIN_BUFFER_FREE)
    {
        RXOff();
        return(false);
    }
    else
    {
        RXOff();
        return(true);
    }
}


//*******************************************************************************************
USBSerial::USBSerial(ring_buffer	*rx_buffer)
{
	_rx_buffer			=	rx_buffer;
	_rx_buffer->head	=	0;
	_rx_buffer->tail	=	0;
    rxIntr = NULL;
}

USBSerial::operator int() {
    return gCdcacm_active ? 1 : 0;
}

#ifdef _DEBUG_USB_VIA_SERIAL0_
	#define	DebugViaSerial0(x)	Serial0.println(x)
#else
	#define	DebugViaSerial0(x)
#endif


//*******************************************************************************************
void USBSerial::begin(unsigned long baudRate)
{
    // Added to remove warning about unused parameter
    (void)baudRate;
#ifdef PIN_LED_TX
    pinMode(PIN_LED_TX, OUTPUT);
    digitalWrite(PIN_LED_TX, LOW);
    createTask(TXLedSwitchOff, 10, TASK_ENABLE, NULL);
#endif

#ifdef PIN_LED_RX
    pinMode(PIN_LED_RX, OUTPUT);
    digitalWrite(PIN_LED_RX, LOW);
    createTask(RXLedSwitchOff, 10, TASK_ENABLE, NULL);
#endif

	DebugViaSerial0("USBSerial::begin");

	DebugViaSerial0("calling usb_initialize");
	usb_initialize();
	DebugViaSerial0("returned from usb_initialize");

	cdcacm_register(USBresetRoutine, USBstoreDataRoutine);
	DebugViaSerial0("returned from cdcacm_register");

	// Must enable glocal interrupts - in this case, we are using multi-vector mode
	//INTEnableSystemMultiVectoredInt();
	DebugViaSerial0("INTEnableSystemMultiVectoredInt");

}


//*******************************************************************************************
void USBSerial::end()
{
}

//*******************************************************************************************
extern "C" uint8_t *cdcacm_get_line_coding();
unsigned long USBSerial::getBaudRate() {
    uint8_t *line_coding = cdcacm_get_line_coding();
    uint32_t br = line_coding[0] | (line_coding[1] << 8) | (line_coding[2] << 16) | (line_coding[3] << 24);
    return br;
}

//*******************************************************************************************
int USBSerial::available(void)
{
	return (RX_BUFFER_SIZE + _rx_buffer->head - _rx_buffer->tail) % RX_BUFFER_SIZE;
}

//*******************************************************************************************
int USBSerial::peek()
{
	if (_rx_buffer->head == _rx_buffer->tail)
	{
		return -1;
	}
	else
	{
		return _rx_buffer->buffer[_rx_buffer->tail];
	}
}

//*******************************************************************************************
int USBSerial::read(void)
{
	unsigned char theChar;

	// If the head = tail, then the buffer is empty, so nothing to read
	if (_rx_buffer->head == _rx_buffer->tail)
	{
		return -1;
	}
	else
	{
		theChar				=	_rx_buffer->buffer[_rx_buffer->tail];
		_rx_buffer->tail	=	(_rx_buffer->tail + 1) % RX_BUFFER_SIZE;
        
        // If we just made enough room for the next packet to fit into our buffer,
        // start the packets flowing from the PC again
        if (USBSerialBufferFree() >= USB_SERIAL_MIN_BUFFER_FREE)
        {
            cdcacm_command_ack();
        }
        
		return (theChar);
	}
}

//*******************************************************************************************
void USBSerial::flush()
{
	// don't reverse this or there may be problems if the RX interrupt
	// occurs after reading the value of rx_buffer_head but before writing
	// the value to rx_buffer_tail; the previous value of rx_buffer_head
	// may be written to rx_buffer_tail, making it appear as if the buffer
	// were full, not empty.
	_rx_buffer->head	=	_rx_buffer->tail;
}

//*******************************************************************************************
size_t USBSerial::write(uint8_t theChar)
{
unsigned char	usbBuf[4];

	usbBuf[0]	=	theChar;
	
    TXOn();
	cdcacm_print(usbBuf, 1);
    TXOff();
    return 1;
}

/* Attach the interrupt by storing a function pointer in the rxIntr variable */
void USBSerial::attachInterrupt(void (*callback)(int)) {
    rxIntr = callback;
}

/* Detatching the interrupt is as simple as setting the rxIntr to null. */
void USBSerial::detachInterrupt() {
    rxIntr = NULL;
}

//*	testing showed 63 gave better speed results than 64

#define	kMaxUSBxmitPkt	63
//*******************************************************************************************
size_t USBSerial::write(const uint8_t *buffer, size_t size)
{
    TXOn();
	if (size <= kMaxUSBxmitPkt)
	{
		//*	it will fit in one transmit packet
		cdcacm_print(buffer, size);
	}
	else
	{
	//*	we can only transmit a maxium of 63 bytes at a time, break it up into 63 byte packets
	unsigned char	usbBuffer[kMaxUSBxmitPkt + 2];
	unsigned short	ii;
	size_t 			packetSize;
	
		packetSize	=	0;
		for (ii=0; ii<size; ii++)
		{
			usbBuffer[packetSize++]	=	buffer[ii];
			if (packetSize > kMaxUSBxmitPkt)
			{
				cdcacm_print(usbBuffer, packetSize);
				packetSize	=	0;
			}
		}
		if (packetSize > 0)
		{
			cdcacm_print(usbBuffer, packetSize);
		}
	}
    TXOff();
    return size;
}

//*******************************************************************************************
size_t USBSerial::write(const char *str)
{
size_t size;

	size	=	strlen(str);
	write((const uint8_t *)str, size);
    return size;
}


#endif		//	defined(_USB)



/* ------------------------------------------------------------ */
/*			UART Interrupt Service Routines						*/
/* ------------------------------------------------------------ */

//*	we need the extern C so that the interrupt handler names don't
//* get mangled by C++

extern "C" {

/* ------------------------------------------------------------ */
/***	IntSer0Handler
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
**		Interrupt service routine for the UART being used by
**		serial port 0.
*/
#if defined(_SER0_VECTOR)

#if defined(__PIC32MZXX__)
void __attribute__((nomips16,at_vector(_SER0_VECTOR),interrupt(_SER0_IPL_ISR))) IntSer0Handler(void)
#else
void __attribute__((interrupt(), nomips16)) IntSer0Handler(void)
#endif
{
#if defined(_USB) && defined(_USE_USB_FOR_SERIAL_)
	Serial0.doSerialInt();
#else
	Serial.doSerialInt();
#endif
}
#endif

/* ------------------------------------------------------------ */
/***	IntSer1Handler
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
**		Interrupt service routine for the UART being used by
**		serial port 1.
*/
#if defined(_SER1_VECTOR)

#if defined(__PIC32MZXX__)
void __attribute__((nomips16,at_vector(_SER1_VECTOR),interrupt(_SER1_IPL_ISR))) IntSer1Handler(void)
#else
void __attribute__((interrupt(), nomips16)) IntSer1Handler(void)
#endif
{
	Serial1.doSerialInt();
}
#endif

/* ------------------------------------------------------------ */
/***	IntSer2Handler
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
**		Interrupt service routine for the UART being used by
**		serial port 2.
*/
#if defined(_SER2_VECTOR)

#if defined(__PIC32MZXX__)
void __attribute__((nomips16,at_vector(_SER2_VECTOR),interrupt(_SER2_IPL_ISR))) IntSer2Handler(void)
#else
void __attribute__((interrupt(), nomips16)) IntSer2Handler(void)
#endif
{
	Serial2.doSerialInt();
}
#endif

/* ------------------------------------------------------------ */
/***	IntSer3Handler
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
**		Interrupt service routine for the UART being used by
**		serial port 3.
*/
#if defined(_SER3_VECTOR)

#if defined(__PIC32MZXX__)
void __attribute__((nomips16,at_vector(_SER3_VECTOR),interrupt(_SER3_IPL_ISR))) IntSer3Handler(void)
#else
void __attribute__((interrupt(), nomips16)) IntSer3Handler(void)
#endif
{
	Serial3.doSerialInt();
}
#endif

/* ------------------------------------------------------------ */
/***	IntSer4Handler
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
**		Interrupt service routine for the UART being used by
**		serial port 4.
*/
#if defined(_SER4_VECTOR)

#if defined(__PIC32MZXX__)
void __attribute__((nomips16,at_vector(_SER4_VECTOR),interrupt(_SER4_IPL_ISR))) IntSer4Handler(void)
#else
void __attribute__((interrupt(), nomips16)) IntSer4Handler(void)
#endif
{
	Serial4.doSerialInt();
}
#endif

/* ------------------------------------------------------------ */
/***	IntSer5Handler
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
**		Interrupt service routine for the UART being used by
**		serial port 5.
*/
#if defined(_SER5_VECTOR)

#if defined(__PIC32MZXX__)
void __attribute__((nomips16,at_vector(_SER5_VECTOR),interrupt(_SER5_IPL_ISR))) IntSer5Handler(void)
#else
 void __attribute__((interrupt(), nomips16)) IntSer5Handler(void)
#endif
{
	Serial5.doSerialInt();
}
#endif

/* ------------------------------------------------------------ */
/***	IntSer6Handler
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
**		Interrupt service routine for the UART being used by
**		serial port 6.
*/
#if defined(_SER6_VECTOR)

#if defined(__PIC32MZXX__)
void __attribute__((nomips16,at_vector(_SER6_VECTOR),interrupt(_SER6_IPL_ISR))) IntSer6Handler(void)
#else
void __attribute__((interrupt(), nomips16)) IntSer6Handler(void)
#endif
{
	Serial6.doSerialInt();
}
#endif

/* ------------------------------------------------------------ */
/***	IntSer7Handler
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
**		Interrupt service routine for the UART being used by
**		serial port 7.
*/
#if defined(_SER7_VECTOR)

#if defined(__PIC32MZXX__)
void __attribute__((nomips16,at_vector(_SER7_VECTOR),interrupt(_SER7_IPL_ISR))) IntSer7Handler(void)
#else
void __attribute__((interrupt(), nomips16)) IntSer7Handler(void)
#endif
{
	Serial7.doSerialInt();
}
#endif

};	// extern C

/* ------------------------------------------------------------ */
/*			Serial Port Object Instances						*/
/* ------------------------------------------------------------ */

#if defined(_USB) && defined(_USE_USB_FOR_SERIAL_)
/* If we're using USB for serial, the USB serial port gets
** instantiated as Serial and hardware serial port 0 gets
** instantiated as Serial0.
*/
USBSerial		Serial(&rx_bufferUSB);
#if defined(_SER0_BASE)
#if defined(__PIC32_PPS__)
HardwareSerial Serial0((p32_uart *)_SER0_BASE, _SER0_IRQ, _SER0_VECTOR, _SER0_IPL, _SER0_SPL, IntSer0Handler, _SER0_TX_PIN, _SER0_RX_PIN, _SER0_TX_OUT, _SER0_RX_IN);
#else
HardwareSerial Serial0((p32_uart *)_SER0_BASE, _SER0_IRQ, _SER0_VECTOR, _SER0_IPL, _SER0_SPL, IntSer0Handler);
#endif
#endif

#else
/* If we're not using USB for serial, then hardware serial port 0
** gets instantiated as Serial.
** NOTE: PIC32MX1xx/2xx devices only have 2 UARTS, so we're not defining more variant
** object instances for those devices.
** however MZ have 6
*/
#if defined(_SER0_BASE)
#if defined(__PIC32_PPS__)
HardwareSerial Serial((p32_uart *)_SER0_BASE, _SER0_IRQ, _SER0_VECTOR, _SER0_IPL, _SER0_SPL, IntSer0Handler, _SER0_TX_PIN, _SER0_RX_PIN, _SER0_TX_OUT, _SER0_RX_IN);
#else
HardwareSerial Serial((p32_uart *)_SER0_BASE, _SER0_IRQ, _SER0_VECTOR, _SER0_IPL, _SER0_SPL, IntSer0Handler);
#endif
#endif

#endif	//defined(_USB) && defined(_USE_USB_FOR_SERIAL_)

#if defined(_SER1_BASE)
#if defined(__PIC32_PPS__)
HardwareSerial Serial1((p32_uart *)_SER1_BASE, _SER1_IRQ, _SER1_VECTOR, _SER1_IPL, _SER1_SPL, IntSer1Handler, _SER1_TX_PIN, _SER1_RX_PIN, _SER1_TX_OUT, _SER1_RX_IN);
#else
HardwareSerial Serial1((p32_uart *)_SER1_BASE, _SER1_IRQ, _SER1_VECTOR, _SER1_IPL, _SER1_SPL, IntSer1Handler);
#endif
#endif

#if defined(_SER2_BASE)
#if defined(__PIC32MZXX__)
HardwareSerial Serial2((p32_uart *)_SER2_BASE, _SER2_IRQ, _SER2_VECTOR, _SER2_IPL, _SER2_SPL, IntSer2Handler, _SER2_TX_PIN, _SER2_RX_PIN, _SER2_TX_OUT, _SER2_RX_IN);
#else
HardwareSerial Serial2((p32_uart *)_SER2_BASE, _SER2_IRQ, _SER2_VECTOR, _SER2_IPL, _SER2_SPL, IntSer2Handler);
#endif
#endif

#if defined(_SER3_BASE)
#if defined(__PIC32MZXX__)
HardwareSerial Serial3((p32_uart *)_SER3_BASE, _SER3_IRQ, _SER3_VECTOR, _SER3_IPL, _SER3_SPL, IntSer3Handler, _SER3_TX_PIN, _SER3_RX_PIN, _SER3_TX_OUT, _SER3_RX_IN);
#else
HardwareSerial Serial3((p32_uart *)_SER3_BASE, _SER3_IRQ, _SER3_VECTOR, _SER3_IPL, _SER3_SPL, IntSer3Handler);
#endif
#endif

#if defined(_SER4_BASE)
#if defined(__PIC32MZXX__)
HardwareSerial Serial4((p32_uart *)_SER4_BASE, _SER4_IRQ, _SER4_VECTOR, _SER4_IPL, _SER4_SPL, IntSer4Handler, _SER4_TX_PIN, _SER4_RX_PIN, _SER4_TX_OUT, _SER4_RX_IN);
#else
HardwareSerial Serial4((p32_uart *)_SER4_BASE, _SER4_IRQ, _SER4_VECTOR, _SER4_IPL, _SER4_SPL, IntSer4Handler);
#endif
#endif

#if defined(_SER5_BASE)
#if defined(__PIC32MZXX__)
HardwareSerial Serial5((p32_uart *)_SER5_BASE, _SER5_IRQ, _SER5_VECTOR, _SER5_IPL, _SER5_SPL, IntSer5Handler, _SER5_TX_PIN, _SER5_RX_PIN, _SER5_TX_OUT, _SER5_RX_IN);
#else
HardwareSerial Serial5((p32_uart *)_SER5_BASE, _SER5_IRQ, _SER5_VECTOR, _SER5_IPL, _SER5_SPL, IntSer5Handler);
#endif
#endif

#if defined(_SER6_BASE)
#if defined(__PIC32MZXX__)
HardwareSerial Serial6((p32_uart *)_SER6_BASE, _SER6_IRQ, _SER6_VECTOR, _SER6_IPL, _SER6_SPL, IntSer6Handler, _SER6_TX_PIN, _SER6_RX_PIN, _SER6_TX_OUT, _SER6_RX_IN);
#else
HardwareSerial Serial6((p32_uart *)_SER6_BASE, _SER6_IRQ, _SER6_VECTOR, _SER6_IPL, _SER6_SPL, IntSer6Handler);
#endif
#endif

#if defined(_SER7_BASE)
#if defined(__PIC32MZXX__)
HardwareSerial Serial7((p32_uart *)_SER7_BASE, _SER7_IRQ, _SER7_VECTOR, _SER7_IPL, _SER7_SPL, IntSer7Handler, _SER7_TX_PIN, _SER7_RX_PIN, _SER7_TX_OUT, _SER7_RX_IN);
#else
HardwareSerial Serial7((p32_uart *)_SER7_BASE, _SER7_IRQ, _SER7_VECTOR, _SER7_IPL, _SER7_SPL, IntSer7Handler);
#endif
#endif

/* ------------------------------------------------------------ */

/************************************************************************/
