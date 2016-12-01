/************************************************************************/
/*																		*/
/*	Board_Data.c --	DP32 Customization Data Declarations		        */
/*																		*/
/************************************************************************/
/*	Author: Gene Apperson												*/
/*	Copyright 2011, Digilent. All rights reserved						*/
/************************************************************************/
/*  File Description:													*/
/*																		*/
/* This file contains the board specific declartions and data structure	*/
/* to customize the chipKIT MPIDE for use with a CmodCK1 board using a	*/
/* PIC32 part in a 44-pin package.										*/
/*																		*/
/* This code is based on earlier work:									*/
/*		Copyright (c) 2010, 2011 by Mark Sproul							*/
/*		Copyright (c) 2005, 2006 by David A. Mellis						*/
/*																		*/
/************************************************************************/
/*  Revision History:													*/
/*																		*/
/*	11/28/2011(GeneA): Created by splitting data out of Board_Defs.h	*/
/*  03/26/2013(KeithV): Modified for DP32 board                          */
/*																		*/
/************************************************************************/
//*	This library is free software; you can redistribute it and/or
//*	modify it under the terms of the GNU Lesser General Public
//*	License as published by the Free Software Foundation; either
//*	version 2.1 of the License, or (at your option) any later version.
//*	
//*	This library is distributed in the hope that it will be useful,
//*	but WITHOUT ANY WARRANTY; without even the implied warranty of
//*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//*	Lesser General Public License for more details.
//*	
//*	You should have received a copy of the GNU Lesser General
//*	Public License along with this library; if not, write to the
//*	Free Software Foundation, Inc., 59 Temple Place, Suite 330,
//*	Boston, MA  02111-1307  USA
/************************************************************************/

#if !defined(BOARD_DATA_C)
#define BOARD_DATA_C

#include <inttypes.h>

/* ------------------------------------------------------------ */
/*					Data Tables									*/
/* ------------------------------------------------------------ */
/* The following declarations define data used in pin mapping.	*/
/* ------------------------------------------------------------ */

#if defined(OPT_BOARD_DATA)

/* ------------------------------------------------------------ */
/* This table is used to map from port number to the address of
** the TRIS register for the port. This is used for setting the
** pin direction.
*/
const uint32_t	port_to_tris_PGM[] = {
	NOT_A_PORT,				//index value 0 is not used

#if defined(_PORTA)
	(uint32_t)&TRISA,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTB)
	(uint32_t)&TRISB,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTC)
	(uint32_t)&TRISC,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTD)
	(uint32_t)&TRISD,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTE)
	(uint32_t)&TRISE,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTF)
	(uint32_t)&TRISF,
#else
	NOT_A_PORT,
#endif

#if defined(_PORTG)
	(uint32_t)&TRISG,
#else
	NOT_A_PORT,
#endif

	NOT_A_PORT,
};

/* ------------------------------------------------------------ */
/* This table is used to map the digital pin number to the port
** containing that pin. The default mapping is to assign pin numbers
** for every possible port bit in order from PORTA to PORTG.
*/
const uint8_t	digital_pin_to_port_PGM[] = {
    _IOPORT_PC, // 0 = RC8 (RX)
    _IOPORT_PC, // 1 = RC9 (TX)
    _IOPORT_PB, // 2 = RB7 (INT0)
    _IOPORT_PC, // 3 = RC4 (INT1)
    _IOPORT_PC, // 4 = RC6 (INT2)
    _IOPORT_PB, // 5 = RB5 (INT3)
    _IOPORT_PC, // 6 = RC7 (INT4)
    _IOPORT_PA, // 7 = RA3

    _IOPORT_PC, // 8 = RC5
    _IOPORT_PC, // 9 = RC3
    _IOPORT_PC, // 10 = RC1
    _IOPORT_PB, // 11 = RB13
    _IOPORT_PB, // 12 = RB1
    _IOPORT_PB, // 13 = RB14

    _IOPORT_PA, // 14 / A0 = RA1
    _IOPORT_PB, // 15 / A1 = RB0
    _IOPORT_PC, // 16 / A2 = RC0
    _IOPORT_PC, // 17 / A3 = RC2
    _IOPORT_PB, // 18 / A4 = RB2
    _IOPORT_PB, // 19 / A5 = RB3

    _IOPORT_PA, // 20 / AREF = RA0
    _IOPORT_PB, // 21 / PROG = RB4
    _IOPORT_PA, // 22 / L = RA10
    _IOPORT_PA, // 23 / TX = RA7
    _IOPORT_PA, // 24 / RX = RA8

    _IOPORT_PA, // 25 / MISO = RA4
    _IOPORT_PB, // 26 / SCK = RB15
    _IOPORT_PA, // 27 / MOSI = RA9

    _IOPORT_PB, // 28 / SDA = B9
    _IOPORT_PB, // 29 / SCL = B8
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to a bit mask
** for the corresponding bit within the port.
*/
const uint16_t	digital_pin_to_bit_mask_PGM[] = {
    _BV( 8),    // 0 = RC8 (RX)
    _BV( 9),    // 1 = RC9 (TX)
    _BV( 7),    // 2 = RB7 (INT0)
    _BV( 4),    // 3 = RC4 (INT1)
    _BV( 6),    // 4 = RC6 (INT2)
    _BV( 5),    // 5 = RB5 (INT3)
    _BV( 7),    // 6 = RC7 (INT4)
    _BV( 3),    // 7 = RA3

    _BV( 5),    // 8 = RC5
    _BV( 3),    // 9 = RC3
    _BV( 1),    // 10 = RC1
    _BV(13),    // 11 = RB13
    _BV( 1),    // 12 = RB1
    _BV(14),    // 13 = RB14

    _BV( 1),    // A0 = RA1
    _BV( 0),    // A1 = RB0
    _BV( 0),    // A2 = RC0
    _BV( 2),    // A3 = RC2
    _BV( 2),    // A4 = RB2
    _BV( 3),    // A5 = RB3

    _BV( 0),    // AREF = RA0
    _BV( 4),    // PROG = RB4
    _BV(10),    // L = RA10
    _BV( 7),    // TX = RA7
    _BV( 8),    // RX = RA8

    _BV( 4),    // MISO = RA4
    _BV(15),    // SCK = RB15
    _BV( 9),    // MOSI = RA9

    _BV( 9),    // SDA = B9
    _BV( 8),    // SCL = B8
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to the output
** compare number, input capture number, and timer external clock
** input associated with that pin.
*/
const uint16_t	digital_pin_to_timer_PGM[] = {
    NOT_ON_TIMER,               // 0 = RC8 (RX)
    NOT_ON_TIMER,               // 1 = RC9 (TX)
    _TIMER_IC4,                 // 2 = RB7 (INT0)
    _TIMER_OC3,                 // 3 = RC4 (INT1)
    _TIMER_IC1,                 // 4 = RC6 (INT2)
    _TIMER_OC2,                 // 5 = RB5 (INT3)
    _TIMER_OC1,                 // 6 = RC7 (INT4)
    _TIMER_IC2,                 // 7 = RA3

    NOT_ON_TIMER,               // 8 = RC5
    _TIMER_OC4,                 // 9 = RC3
    _TIMER_OC5,                 // 10 = RC1
    _TIMER_IC5,                 // 11 = RB13
    _TIMER_IC3,                 // 12 = RB1
    NOT_ON_TIMER,               // 13 = RB14

    NOT_ON_TIMER,               // A0 = RA1
    NOT_ON_TIMER,               // A1 = RB0
    NOT_ON_TIMER,               // A2 = RC0
    NOT_ON_TIMER,               // A3 = RC2
    NOT_ON_TIMER,               // A4 = RB2
    NOT_ON_TIMER,               // A5 = RB3

    NOT_ON_TIMER,               // AREF = RA0
    NOT_ON_TIMER,               // PROG = RB4
    NOT_ON_TIMER,               // L = RA10
    NOT_ON_TIMER,               // TX = RA7
    NOT_ON_TIMER,               // RX = RA8

    NOT_ON_TIMER,
    NOT_ON_TIMER,
    NOT_ON_TIMER,

    NOT_ON_TIMER,
    NOT_ON_TIMER,
};

/* ------------------------------------------------------------ */
/* This table maps from a digital pin number to the corresponding
** PPS register. This register is used to select the peripheral output
** connected to the pin. The register is set to 0 to disconnedt the
** pin from any peripheral so it can be used as GPIO.
** For PIC32MX1xx/2xx series devices, the PPS output select registers
** are arranged as a contiguous series of 32 bit registers. This table
** treats these registers as an array of DWORDs an stores the index
** to the register.
*/
const uint8_t digital_pin_to_pps_out_PGM[] = {
    _PPS_OUT(_PPS_RPC8R ), // 0 = RC8 (RX)
    _PPS_OUT(_PPS_RPC9R ), // 1 = RC9 (TX)
    _PPS_OUT(_PPS_RPB7R ), // 2 = RB7 (INT0)
    _PPS_OUT(_PPS_RPC4R ), // 3 = RC4 (INT1)
    _PPS_OUT(_PPS_RPC6R ), // 4 = RC6 (INT2)
    _PPS_OUT(_PPS_RPB5R ), // 5 = RB5 (INT3)
    _PPS_OUT(_PPS_RPC7R ), // 6 = RC7 (INT4)
    _PPS_OUT(_PPS_RPA3R ), // 7 = RA3

    _PPS_OUT(_PPS_RPC5R ), // 8 = RC5
    _PPS_OUT(_PPS_RPC3R ), // 9 = RC3
    _PPS_OUT(_PPS_RPC1R ), // 10 = RC1
    _PPS_OUT(_PPS_RPB13R), // 11 = RB13
    _PPS_OUT(_PPS_RPB1R ), // 12 = RB1
    _PPS_OUT(_PPS_RPB14R), // 13 = RB14

    _PPS_OUT(_PPS_RPA1R ), // A0 = RA1
    _PPS_OUT(_PPS_RPB0R ), // A1 = RB0
    _PPS_OUT(_PPS_RPC0R ), // A2 = RC0
    _PPS_OUT(_PPS_RPC2R ), // A3 = RC2
    _PPS_OUT(_PPS_RPB2R ), // A4 = RB2
    _PPS_OUT(_PPS_RPB3R ), // A5 = RB3

    _PPS_OUT(_PPS_RPA0R ), // AREF = RA0
    _PPS_OUT(_PPS_RPB4R ), // PROG = RB4
    NOT_PPS_PIN,           // L = RA10
    NOT_PPS_PIN,           // TX = RA7
    _PPS_OUT(_PPS_RPA8R ), // RX = RA8

    _PPS_OUT(_PPS_RPA4R ),
    _PPS_OUT(_PPS_RPB15R),
    _PPS_OUT(_PPS_RPA9R ),

    _PPS_OUT(_PPS_RPB9R ),
    _PPS_OUT(_PPS_RPB8R ),
};

/* ------------------------------------------------------------ */
/* This table maps from the digital pin number to the value to be
** loaded into a PPS input select register to select that pin.
** It also maps from digital pin number to input/output pin set to 
** which the pin belongs. The set mask is in the high four bits,
** the select value is in the low four bits.
** Note: if the PIC32 device has more than four pin sets, or more than
** 16 pin mapping choices per input function, then this table will have
** to be redefined as a table of uint16_t values and the macros used to
** access the table redefined as well.
*/
const uint8_t digital_pin_to_pps_in_PGM[] = {
    _PPS_IN(_PPS_RPC8 ), // 0 = RC8 (RX)
    _PPS_IN(_PPS_RPC9 ), // 1 = RC9 (TX)
    _PPS_IN(_PPS_RPB7 ), // 2 = RD5 (INT0)
    _PPS_IN(_PPS_RPC4 ), // 3 = RC4 (INT1)
    _PPS_IN(_PPS_RPC6 ), // 4 = RC6 (INT2)
    _PPS_IN(_PPS_RPB5 ), // 5 = RB5 (INT3)
    _PPS_IN(_PPS_RPC7 ), // 6 = RC7 (INT4)
    _PPS_IN(_PPS_RPA3 ), // 7 = RA3

    _PPS_IN(_PPS_RPC5 ), // 8 = RC5
    _PPS_IN(_PPS_RPC3 ), // 9 = RC3
    _PPS_IN(_PPS_RPC1 ), // 10 = RC1
    _PPS_IN(_PPS_RPB13), // 11 = RB13
    _PPS_IN(_PPS_RPB1 ), // 12 = RB1
    _PPS_IN(_PPS_RPB14), // 13 = RB14

    _PPS_IN(_PPS_RPA1 ), // A0 = RA1
    _PPS_IN(_PPS_RPB0 ), // A1 = RB0
    _PPS_IN(_PPS_RPC0 ), // A2 = RC0
    _PPS_IN(_PPS_RPC2 ), // A3 = RC2
    _PPS_IN(_PPS_RPB2 ), // A4 = RB2
    _PPS_IN(_PPS_RPB3 ), // A5 = RB3

    _PPS_IN(_PPS_RPA0 ), // AREF = RA0
    _PPS_IN(_PPS_RPB4 ), // PROG = RB4
    NOT_PPS_PIN,         // L = RA10
    NOT_PPS_PIN,         // TX = RA7
    _PPS_IN(_PPS_RPA8 ), // RX = RA8

    _PPS_IN(_PPS_RPA4 ),
    _PPS_IN(_PPS_RPB15),
    _PPS_IN(_PPS_RPA9 ),

    _PPS_IN(_PPS_RPB9 ),
    _PPS_IN(_PPS_RPB8 ),
};

/* ------------------------------------------------------------ */
/* This table is used to map from the analog pin number to the
** actual A/D converter channel used for that pin.
** In the default case, where there is a one-to-one mapping, this
** table isn't needed as the analogInPinToChannel() macro is defined
** to provide the mapping.
*/
//#if defined(_NOT_USED_)
const uint8_t analog_pin_to_channel_PGM[] = {
			//*	Arduino Pin		PIC32 Analog channel
	1,		//*	A0				11
	2,		//*	A1              10
	6,		//*	A2              9
	8,		//*	A3              0
	4,		//*	A4              1
	5,		//*	A5              2
};
//#endif

const uint8_t digital_pin_to_analog_PGM[] = {
    // Digital pins
    NOT_ANALOG_PIN, //  0 
    NOT_ANALOG_PIN, //  1
    NOT_ANALOG_PIN, //  2 
    NOT_ANALOG_PIN, //  3 
    NOT_ANALOG_PIN, //  4 
    NOT_ANALOG_PIN, //  5 
    NOT_ANALOG_PIN, //  6 
    NOT_ANALOG_PIN, //  7 
    NOT_ANALOG_PIN, //  8 
    NOT_ANALOG_PIN, //  9 
    NOT_ANALOG_PIN, //  10 
    NOT_ANALOG_PIN, //  11 
    NOT_ANALOG_PIN, //  12 
    NOT_ANALOG_PIN, //  13 

    // Analog pins
    _BOARD_AN0,     // A0 = RA0 = 14
    _BOARD_AN1,     // A1 = RA1 = 15
    _BOARD_AN2,     // A2 = RC0 = 16
    _BOARD_AN3,     // A3 = RC2 = 17
    _BOARD_AN4,     // A4 = RB2 = 18
    _BOARD_AN5,     // A5 = RB3 = 19

    // Extra functions - LEDs, buttons, etc
    NOT_ANALOG_PIN, //  20 
    NOT_ANALOG_PIN, //  21 
    NOT_ANALOG_PIN, //  22 
    NOT_ANALOG_PIN, //  23 
    NOT_ANALOG_PIN, //  24 
    NOT_ANALOG_PIN, //  25 
    NOT_ANALOG_PIN, //  26 
    NOT_ANALOG_PIN, //  27 
    NOT_ANALOG_PIN, //  28 
    NOT_ANALOG_PIN, //  29 
};

/* ------------------------------------------------------------ */
/* This table maps from an output compare number as stored in the
** digital_pin_to_timer_PGM table to the digital pin number of the
** pin that OC is connected to. This table is only required for
** devices that support peripheral pin select (PPS), i.e. PIC32MX1xx/2xx
** devices.
*/

const uint8_t output_compare_to_digital_pin_PGM[] = {
    0,
	PIN_OC1,	        // A0, B3, B4, B15, B7  ; B15   RPB15R  = 5  	
	PIN_OC2,	        // A1, B5, B1, B11, B8  ; B8    RPB8R   = 5
	PIN_OC3,	        // A3, B14, B0, B10, B9 ; B9    RPB9R   = 5
	PIN_OC4,	        // A2, B6, A4, B13, B2  ; B2    RPB2R   = 5
	PIN_OC5,	        // A2, B6, A4, B13, B2	; B13   RPB13R  = 6
};

/* ------------------------------------------------------------ */
/* This table maps from an external interrupt number to the digital
** pin for that interrupt.
*/

const uint8_t external_int_to_digital_pin_PGM[] = {
	NOT_PPS_PIN,		// INT0 is not mappable;    RB7
	PIN_INT1,			// A3, B14, B0, B10, B9;    B9  INT1R = RPB9 = 4
	PIN_INT2,			// A2, B6, A4, B13, B2;     B2  INT2R = RPB2 = 4
	PIN_INT3,			// A1, B5, B1, B11, B8;     B8  INT3R = RPB8 = 4
	PIN_INT4			// A0, B3, B4, B15, B7;     B4  INT4R = RPB4 = 2
};

/* ------------------------------------------------------------ */
/*				Board Customization Functions					*/
/* ------------------------------------------------------------ */
/*																*/
/* The following can be used to customize the behavior of some	*/
/* of the core API functions. These provide hooks that can be	*/
/* used to extend or replace the default behavior of the core	*/
/* functions. To use one of these functions, add the desired	*/
/* code to the function skeleton below and then set the value	*/
/* of the appropriate compile switch above to 1. This will		*/
/* cause the hook function to be compiled into the build and	*/
/* to cause the code to call the hook function to be compiled	*/
/* into the appropriate core function.							*/
/*																*/
/* ------------------------------------------------------------ */
/***	_board_init
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
**		This function is called from the core init() function.
**		This can be used to perform any board specific init
**		that needs to be done when the processor comes out of
**		reset and before the user sketch is run.
*/
#if	(OPT_BOARD_INIT != 0)

void _board_init(void) {

	//	Turn Secondary oscillator off as GPIO is needed
	OSCCONCLR	=	_OSCCON_SOSCEN_MASK;
	
}

#endif

/* ------------------------------------------------------------ */
/***	_board_pinMode
**
**	Parameters:
**		pin		- digital pin number to configure
**		mode	- mode to which the pin should be configured
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the pinMode
**		function. It can perform any special processing needed
**		when setting the pin mode. If this function returns zero,
**		control will pass through the normal pinMode code. If
**		it returns a non-zero value the normal pinMode code isn't
**		executed.
*/
#if	(OPT_BOARD_DIGITAL_IO != 0)

int	_board_pinMode(uint8_t pin, uint8_t mode) {
	
	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_getPinMode
**
**	Parameters:
**		pin		- digital pin number
**		mode	- pointer to variable to receive mode value
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the getPinMode
**		function. It can perform any special processing needed
**		when getting the pin mode. If this function returns zero,
**		control will pass through the normal getPinMode code. If
**		it returns a non-zero value the normal getPinMode code isn't
**		executed.
*/
#if	(OPT_BOARD_DIGITAL_IO != 0)

int	_board_getPinMode(uint8_t pin, uint8_t * mode) {
	
	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_digitalWrite
**
**	Parameters:
**		pin		- digital pin number
**		val		- value to write to the pin
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the digitalWrite
**		function. It can perform any special processing needed
**		in writing to the pin. If this function returns zero,
**		control will pass through the normal digitalWrite code. If
**		it returns a non-zero value the normal digitalWrite code isn't
**		executed.
*/#if	(OPT_BOARD_DIGITAL_IO != 0)

int	_board_digitalWrite(uint8_t pin, uint8_t val) {
	
	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_digitalRead
**
**	Parameters:
**		pin		- digital pin number
**		val		- pointer to variable to receive pin value
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the digitalRead
**		function. It can perform any special processing needed
**		in reading from the pin. If this function returns zero,
**		control will pass through the normal digitalRead code. If
**		it returns a non-zero value the normal digitalRead code isn't
**		executed.
*/
#if	(OPT_BOARD_DIGITAL_IO != 0)

int	_board_digitalRead(uint8_t pin, uint8_t * val) {
	
	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_analogRead
**
**	Parameters:
**		pin		- analog channel number
**		val		- pointer to variable to receive analog value
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the analogRead
**		function. It can perform any special processing needed
**		in reading from the pin. If this function returns zero,
**		control will pass through the normal analogRead code. If
**		it returns a non-zero value the normal analogRead code isn't
**		executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int	_board_analogRead(uint8_t pin, int * val) {

	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_analogReference
**
**	Parameters:
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the analogReference
**		function. It can perform any special processing needed
**		to set the reference voltage. If this function returns zero,
**		control will pass through the normal analogReference code. If
**		it returns a non-zero value the normal analogReference code isn't
**		executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int	_board_analogReference(uint8_t mode) {

	return 0;

}

#endif

/* ------------------------------------------------------------ */
/***	_board_analogWrite
**
**	Parameters:
**		pin		- pin number
**		val		- analog value to write
**
**	Return Value:
**		Returns 0 if not handled, !0 if handled.
**
**	Errors:
**		none
**
**	Description:
**		This function is called at the beginning of the analogWrite
**		function. It can perform any special processing needed
**		in writing to the pin. If this function returns zero,
**		control will pass through the normal analogWrite code. If
**		it returns a non-zero value the normal analogWrite code isn't
**		executed.
*/
#if (OPT_BOARD_ANALOG_WRITE != 0)

int	_board_analogWrite(uint8_t pin, int val) {

	return 0;

}

#endif

#endif // OPT_BOARD_DATA

/* ------------------------------------------------------------ */

#endif	// BOARD_DATA_C

/************************************************************************/
