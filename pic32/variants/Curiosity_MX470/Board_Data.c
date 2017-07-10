/************************************************************************/
/*                                                                      */
/*  Board_Data.c -- Default Board Customization Data Declarations       */
/*                                                                      */
/************************************************************************/
/*  Author: Gene Apperson                                               */
/*  Copyright 2011, Digilent. All rights reserved                       */
/************************************************************************/
/*  File Description:                                                   */
/*                                                                      */
/* This file contains the board specific declarations and data structure*/
/* to customize the chipKIT MPIDE for use with a generic board using a  */
/* PIC32 part in a 64-pin package.                                      */
/*                                                                      */
/* This code is based on earlier work:                                  */
/*      Copyright (c) 2010, 2011 by Mark Sproul                         */
/*      Copyright (c) 2005, 2006 by David A. Mellis                     */
/*                                                                      */
/************************************************************************/
/*  Revision History:                                                   */
/*                                                                      */
/*  11/28/2011(GeneA): Created by splitting data out of Board_Defs.h    */
/*  03/11/2012(BrianS): Modified for Fubarino board                     */
/*  02/12/2013(GeneA): removed dependency on Microchip plib library     */
/*                                                                      */
/************************************************************************/
//* This library is free software; you can redistribute it and/or
//* modify it under the terms of the GNU Lesser General Public
//* License as published by the Free Software Foundation; either
//* version 2.1 of the License, or (at your option) any later version.
//* 
//* This library is distributed in the hope that it will be useful,
//* but WITHOUT ANY WARRANTY; without even the implied warranty of
//* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//* Lesser General Public License for more details.
//* 
//* You should have received a copy of the GNU Lesser General
//* Public License along with this library; if not, write to the
//* Free Software Foundation, Inc., 59 Temple Place, Suite 330,
//* Boston, MA  02111-1307  USA
/************************************************************************/

#if !defined(BOARD_DATA_C)
#define BOARD_DATA_C

#include <inttypes.h>

/* ------------------------------------------------------------ */
/*                  Data Tables                                 */
/* ------------------------------------------------------------ */
/* The following declarations define data used in pin mapping.  */
/* ------------------------------------------------------------ */

#if defined(OPT_BOARD_DATA)

/* ------------------------------------------------------------ */
/* This table is used to map from port number to the address of
** the TRIS register for the port. This is used for setting the
** pin direction.
*/
const uint32_t  port_to_tris_PGM[] = {
    NOT_A_PORT,             //index value 0 is not used

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
const uint8_t   digital_pin_to_port_PGM[] = {
    // Pins 0 through 11 on Click Socket 1
    _IOPORT_PB, //  0  RB4
    _IOPORT_PE, //  1  RE3
    _IOPORT_PD, //  2  RD4
    _IOPORT_PD, //  3  RD2
    _IOPORT_PD, //  4  RD3
    _IOPORT_PD, //  5  RD5
    _IOPORT_PB, //  6  RB14
    _IOPORT_PD, //  7  RD1
    _IOPORT_PF, //  8  RF1
    _IOPORT_PF, //  9  RF0
    _IOPORT_PD, // 10  RD10
    _IOPORT_PD, // 11  RD9
	
	// Pins 12 through 23 on Click Socket 2
    _IOPORT_PB, // 12  RB11
    _IOPORT_PB, // 13  RB15
    _IOPORT_PG, // 14  RG9
    _IOPORT_PG, // 15  RG6
    _IOPORT_PG, // 16  RG7
    _IOPORT_PG, // 17  RG8
    _IOPORT_PD, // 18  RD8
    _IOPORT_PD, // 19  RD0
    _IOPORT_PB, // 20  RB9
    _IOPORT_PE, // 21  RE5
    _IOPORT_PF, // 22  RF5
    _IOPORT_PF, // 23  RF4

    // Pins 24 through 28 on the external header and BM64
    _IOPORT_PB, // 24  RB0
    _IOPORT_PB, // 25  RB1
    _IOPORT_PB, // 26  RB2
    _IOPORT_PB, // 27  RB13
    _IOPORT_PB, // 28  RB12
	
	// Pins 29 through 34 are the LEDs
    _IOPORT_PE, // 29  RE4
    _IOPORT_PE, // 30  RE6
    _IOPORT_PE, // 31  RE7
    _IOPORT_PB, // 32  RB10
    _IOPORT_PB, // 33  RB3
    _IOPORT_PB, // 34  RB2
	
	// Pin 35 is the Switch (S1)
    _IOPORT_PD, // 35  RD6
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to a bit mask
** for the corresponding bit within the port.
*/
const uint16_t  digital_pin_to_bit_mask_PGM[] = {
    _BV( 4 ) ,   //  0  RB4
    _BV( 3 ) ,   //  1  RE3
    _BV( 4 ),    //  2  RD4 
    _BV( 2 ),    //  3  RD2
    _BV( 3 ) ,   //  4  RD3
    _BV( 5 ),    //  5  RD5
    _BV( 14 ),   //  6  RB14
    _BV( 1 ) ,   //  7  RD1
    _BV( 1 ) ,   //  8  RF1
    _BV( 0 ) ,   //  9  RF0
    _BV( 10 ),   // 10  RD10
    _BV( 9 ) ,   // 11  RD9
    _BV( 11 ),   // 12  RB11
    _BV( 15 ),   // 13  RB15
    _BV( 9 ) ,   // 14  RG9
    _BV( 6 ) ,   // 15  RG6
    _BV( 7 ) ,   // 16  RG7
    _BV( 8 ) ,   // 17  RG8
    _BV( 8 ) ,   // 18  RD8
    _BV( 0 ) ,   // 19  RD0
    _BV( 9 ) ,   // 20  RB9
    _BV( 5 ) ,   // 21  RE5
    _BV( 5 ) ,   // 22  RF5
    _BV( 4 ) ,   // 23  RF4
    _BV( 0 ) ,   // 24  RB0
    _BV( 1 ) ,   // 25  RB1
    _BV( 2 ) ,   // 26  RB2
    _BV( 13 ),   // 27  RB13
    _BV( 12 ),   // 28  RB12
    _BV( 4 ) ,   // 29  RE4
    _BV( 6 ) ,   // 30  RE6
    _BV( 7 ) ,   // 31  RE7
    _BV( 10 ),   // 32  RB10
    _BV( 3 ) ,   // 33  RB3
    _BV( 2 ) ,   // 34  RB2
    _BV( 6 ) ,   // 35  RD6
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to the output
** compare number, input capture number, and timer external clock
** input associated with that pin.
*/
const uint16_t  digital_pin_to_timer_PGM[] = {
    _TIMER_IC1 ,    // 0  RD8
    _TIMER_IC2 ,    // 1  RD9
    _TIMER_IC3 ,    // 2  RD10
    _TIMER_IC4 ,    // 3  RD11
    _TIMER_OC1 ,    // 4  RD0
    NOT_ON_TIMER ,  // 5  RC13
    _TIMER_TCK1 ,   // 6  RC14
    _TIMER_OC2 ,    // 7  RD1
    _TIMER_OC3 ,    // 8  RD2
    _TIMER_OC4 ,    // 9 RD3
    _TIMER_OC5 | _TIMER_IC5,    // 10 RD4
    NOT_ON_TIMER ,  // 11 RD5
    NOT_ON_TIMER ,  // 12 RD6
    NOT_ON_TIMER ,  // 13 RD7
    NOT_ON_TIMER ,  // 14 RF0
    NOT_ON_TIMER ,  // 15 RF1
    NOT_ON_TIMER ,  // 16 RE0
    NOT_ON_TIMER ,  // 17 RE2
    NOT_ON_TIMER ,  // 18 RE3
    NOT_ON_TIMER ,  // 19 RE4
    NOT_ON_TIMER ,  // 20 RE5
    NOT_ON_TIMER ,  // 21 RE6
    NOT_ON_TIMER ,  // 22 RE7
    NOT_ON_TIMER ,  // 23 RG6
    NOT_ON_TIMER ,  // 24 RG7
    NOT_ON_TIMER ,  // 25 RG8
    NOT_ON_TIMER ,  // 26 RG9
    NOT_ON_TIMER ,  // 27 RF4
    NOT_ON_TIMER ,  // 28 RF5
    NOT_ON_TIMER ,  // 29 RB5
    NOT_ON_TIMER ,  // 30 RB4
    NOT_ON_TIMER ,  // 31 RB3
    NOT_ON_TIMER ,  // 32 RB2
    NOT_ON_TIMER ,  // 33 RB1
    NOT_ON_TIMER ,  // 34 RB0
    NOT_ON_TIMER ,  // 35 RB7
    NOT_ON_TIMER ,  // 36 RB6
    NOT_ON_TIMER ,  // 37 RB8
    NOT_ON_TIMER ,  // 38 RB9
    NOT_ON_TIMER ,  // 39 RB10
    NOT_ON_TIMER ,  // 40 RB11
    NOT_ON_TIMER ,  // 41 RB12
    NOT_ON_TIMER ,  // 42 RB13
    NOT_ON_TIMER ,  // 43 RB14
    NOT_ON_TIMER ,  // 44 RB15
};

/* ------------------------------------------------------------ */
/* This table maps from a digital pin number to the corresponding
** analog pin number.
*/
//#if defined(_NOT_USED_)
const uint8_t digital_pin_to_analog_PGM[] = {
    _BOARD_AN4, //   0  RD8
    NOT_ANALOG_PIN, //   1  RD9
    NOT_ANALOG_PIN, //   2  RD10
    NOT_ANALOG_PIN, //   3  RD11
    NOT_ANALOG_PIN, //   4  RD0
    NOT_ANALOG_PIN, //   5  RC13
    NOT_ANALOG_PIN, //   6  RC14
    NOT_ANALOG_PIN, //   7  RD1
    NOT_ANALOG_PIN, //   8  RD2
    NOT_ANALOG_PIN, //   9  RD3
    NOT_ANALOG_PIN, //  10  RD4
    NOT_ANALOG_PIN, //  11  RD5
    _BOARD_AN11, //  12  RD6
    NOT_ANALOG_PIN, //  13  RD7
    NOT_ANALOG_PIN, //  14  RF0
    NOT_ANALOG_PIN, //  15  RF1
    NOT_ANALOG_PIN, //  16  RE0
    NOT_ANALOG_PIN, //  17  RE1
    NOT_ANALOG_PIN, //  18  RE2
    NOT_ANALOG_PIN, //  19  RE3
    NOT_ANALOG_PIN, //  20  RE4
    NOT_ANALOG_PIN, //  21  RE5
    NOT_ANALOG_PIN, //  22  RE6
    NOT_ANALOG_PIN, //  23  RE7
    NOT_ANALOG_PIN, //  24  RG6
    NOT_ANALOG_PIN, //  25  RG7
    NOT_ANALOG_PIN, //  26  RG8
    NOT_ANALOG_PIN, //  27  RG9
    NOT_ANALOG_PIN, //  28  RF4
    NOT_ANALOG_PIN, //  29  RF5
    NOT_ANALOG_PIN,     //  30  RB4   A14
    NOT_ANALOG_PIN,     //  31  RB3   A13
    NOT_ANALOG_PIN,     //  32  RB2   A12
    NOT_ANALOG_PIN,     //  33  RB1   A11
    NOT_ANALOG_PIN,     //  34  RB0   A10
    NOT_ANALOG_PIN,     //  35  RB7   A9
    NOT_ANALOG_PIN,     //  36  RB6   A8
    NOT_ANALOG_PIN,     //  37  RB8   A7
    NOT_ANALOG_PIN,     //  38  RB9   A6
    NOT_ANALOG_PIN,    //  39  RB10  A5
    NOT_ANALOG_PIN,    //  40  RB11  A4
    NOT_ANALOG_PIN,    //  41  RB12  A3
    NOT_ANALOG_PIN,    //  42  RB13  A2
    NOT_ANALOG_PIN,    //  43  RB14  A1
    NOT_ANALOG_PIN,    //  44  RB15  A0
};
//#endif

/* ------------------------------------------------------------ */
/* This table is used to map from the analog pin number to the
** actual A/D converter channel used for that pin.
** In the default case, where there is a one-to-one mapping, this
** table isn't needed as the analogInPinToChannel() macro is defined
** to provide the mapping.
*/
//#if defined(_NOT_USED_)
const uint8_t analog_pin_to_channel_PGM[] = {
            //* Arduino Pin     PIC32 Analog channel
    0,      //* A0              1 to 1 mapping
    1,      //* A1
};
//#endif

/* ------------------------------------------------------------ */
/*                PPS Mappings                                    */
/* ------------------------------------------------------------ */


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
    NOT_PPS_PIN,                //  0   RB04    AN4/C1INB/RB4 
    _PPS_OUT(_PPS_RPE3R),       //  1   RE03    RPE3/CTPLS/PMD3/RE3
    _PPS_OUT(_PPS_RPD4R),       //  2   RD04    RPD4/PMWR/RD4
    _PPS_OUT(_PPS_RPD2R),       //  3   RD02    AN25/RPD2/SCK1/RD2
    _PPS_OUT(_PPS_RPD3R),       //  4   RD03    AN26/RPD3/RD3
    _PPS_OUT(_PPS_RPD5R),       //  5   RD05    RPD5/PMRD/RD5
    _PPS_OUT(_PPS_RPB14R),      //  6   RB14    AN14/RPB14/CTED5/PMA1/RB14    
    _PPS_OUT(_PPS_RPD1R),       //  7   RD01    AN24/RPD1/RD1  
    _PPS_OUT(_PPS_RPF1R),       //  8   RF01    RPF1/RF1 
    _PPS_OUT(_PPS_RPF0R),       //  9   RF00    RPF0/RF0   
    _PPS_OUT(_PPS_RPD10R),      //  10  RD10    RPD10/SCL1/PMCS2/RD10  
    _PPS_OUT(_PPS_RPD9R),       //  11  RD09    RPD9/SDA1/RD9
    NOT_PPS_PIN,                //  12  RB11    TDO/AN11/PMA12/RB11
    _PPS_OUT(_PPS_RPB15R),      //  13  RB15    AN15/RPB15/OCFB/CTED6/PMA0/RB15
    _PPS_OUT(_PPS_RPG9R),       //  14  RG09    AN19/C2INC/RPG9/PMA2/RG9       
    _PPS_OUT(_PPS_RPG6R),       //  15  RG06    AN16/C1IND/RPG6/SCK2/PMA5/RG6  
    _PPS_OUT(_PPS_RPG7R),       //  16  RG07    AN17/C1INC/RPG7/PMA4/RG7       
    _PPS_OUT(_PPS_RPG8R),       //  17  RG08    AN18/C2IND/RPG8/PMA3/RG8
    _PPS_OUT(_PPS_RPD8R),       //  18  RD08    RPD8/RTCC/RD8    
    _PPS_OUT(_PPS_RPD0R),       //  19  RD00    RPD0/INT0/RD0
    _PPS_OUT(_PPS_RPB9R),       //  20  RB09    AN9/RPB9/CTED4/PMA7/RB9
    _PPS_OUT(_PPS_RPE5R),       //  21  RE05    AN22/RPE5/PMD5/RE5
    _PPS_OUT(_PPS_RPF5R),       //  22  RF05    RPF5/SCL2/PMA8/RF5
    _PPS_OUT(_PPS_RPF4R),       //  23  RF04    RPF4/SDA2/PMA9/RF4
    _PPS_OUT(_PPS_RPB0R),       //  24  RB00    PGED1/VREF+/CVREF+/AN0/RPB0/PMA6/RB0 
    _PPS_OUT(_PPS_RPB1R),       //  25  RB01    PGEC1/VREF-/CVREF-/AN1/RPB1/CTED12/RB1 
    _PPS_OUT(_PPS_RPB2R),       //  26  RB02    PGEC3/AN2/C2INB/RPB2/CTED13/RB2
    NOT_PPS_PIN,                //  27  RB13    TDI/AN13/PMA10/RB13  
    NOT_PPS_PIN,                //  28  RB12    TCK/AN12/PMA11/RB12
    NOT_PPS_PIN,                //  29  RE04    AN21/PMD4/RE4   
    NOT_PPS_PIN,                //  30  RE06    AN23/PMD6/RE6  
    NOT_PPS_PIN,                //  31  RE07    AN27/PMD7/RE7
    _PPS_OUT(_PPS_RPB2R),       //  32  RB10    TMS/CVREFOUT/AN10/RPB10/CTED11//PMA13/RB10
    _PPS_OUT(_PPS_RPB2R),       //  33  RB03    PGED3/AN3/C2INA/RPB3/RB3 
    _PPS_OUT(_PPS_RPB2R),       //  34  RB02    PGEC3/AN2/C2INB/RPB2/CTED13/RB2
    NOT_PPS_PIN,                //  35  RD06    RD6
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
    NOT_PPS_PIN,                //  0   RB04    AN4/C1INB/RB4 
    _PPS_IN(_PPS_RPE3),         //  1   RE03    RPE3/CTPLS/PMD3/RE3
    _PPS_IN(_PPS_RPD4),         //  2   RD04    RPD4/PMWR/RD4
    _PPS_IN(_PPS_RPD2),         //  3   RD02    AN25/RPD2/SCK1/RD2
    _PPS_IN(_PPS_RPD3),         //  4   RD03    AN26/RPD3/RD3
    _PPS_IN(_PPS_RPD5),         //  5   RD05    RPD5/PMRD/RD5
    _PPS_IN(_PPS_RPB14),        //  6   RB14    AN14/RPB14/CTED5/PMA1/RB14    
    _PPS_IN(_PPS_RPD1),         //  7   RD01    AN24/RPD1/RD1
    _PPS_IN(_PPS_RPF1),         //  8   RF01    RPF1/RF1 
    _PPS_IN(_PPS_RPF0),         //  9   RF00    RPF0/RF0   
    _PPS_IN(_PPS_RPD10),        //  10  RD10    RPD10/SCL1/PMCS2/RD10  
    _PPS_IN(_PPS_RPD9),         //  11  RD09    RPD9/SDA1/RD9
    NOT_PPS_PIN,                //  12  RB11    TDO/AN11/PMA12/RB11
    _PPS_IN(_PPS_RPB15),        //  13  RB15    AN15/RPB15/OCFB/CTED6/PMA0/RB15
    _PPS_IN(_PPS_RPG9),         //  14  RG09    AN19/C2INC/RPG9/PMA2/RG9       
    _PPS_IN(_PPS_RPG6),         //  15  RG06    AN16/C1IND/RPG6/SCK2/PMA5/RG6  
    _PPS_IN(_PPS_RPG7),         //  16  RG07    AN17/C1INC/RPG7/PMA4/RG7       
    _PPS_IN(_PPS_RPG8),         //  17  RG08    AN18/C2IND/RPG8/PMA3/RG8
    _PPS_IN(_PPS_RPD8),         //  18  RD08    RPD8/RTCC/RD8    
    _PPS_IN(_PPS_RPD0),         //  19  RD00    RPD0/INT0/RD0
    _PPS_IN(_PPS_RPB9),         //  20  RB09    AN9/RPB9/CTED4/PMA7/RB9
    _PPS_IN(_PPS_RPE5),         //  21  RE05    AN22/RPE5/PMD5/RE5
    _PPS_IN(_PPS_RPF5),         //  22  RF05    RPF5/SCL2/PMA8/RF5
    _PPS_IN(_PPS_RPF4),         //  23  RF04    RPF4/SDA2/PMA9/RF4
    _PPS_IN(_PPS_RPB0),         //  24  RB00    PGED1/VREF+/CVREF+/AN0/RPB0/PMA6/RB0 
    _PPS_IN(_PPS_RPB1),         //  25  RB01    PGEC1/VREF-/CVREF-/AN1/RPB1/CTED12/RB1 
    _PPS_IN(_PPS_RPB2),         //  26  RB02    PGEC3/AN2/C2INB/RPB2/CTED13/RB2
    NOT_PPS_PIN,                //  27  RB13    TDI/AN13/PMA10/RB13  
    NOT_PPS_PIN,                //  28  RB12    TCK/AN12/PMA11/RB12
    NOT_PPS_PIN,                //  29  RE04    AN21/PMD4/RE4   
    NOT_PPS_PIN,                //  30  RE06    AN23/PMD6/RE6  
    NOT_PPS_PIN,                //  31  RE07    AN27/PMD7/RE7
    _PPS_IN(_PPS_RPB10),        //  32  RB10    TMS/CVREFOUT/AN10/RPB10/CTED11//PMA13/RB10
    _PPS_IN(_PPS_RPB3),         //  33  RB03    PGED3/AN3/C2INA/RPB3/RB3 
    _PPS_IN(_PPS_RPB2),         //  34  RB02    PGEC3/AN2/C2INB/RPB2/CTED13/RB2
    NOT_PPS_PIN,                //  35  RD06    RD6
};

/* ------------------------------------------------------------ */
/* This table maps from an output compare number as stored in the
** digital_pin_to_timer_PGM table to the digital pin number of the
** pin that OC is connected to. This table is only required for
** devices that support peripheral pin select (PPS), i.e. PIC32MX1xx/2xx
** devices.
*/

const uint8_t output_compare_to_digital_pin_PGM[] = {
    NOT_PPS_PIN,
    PIN_OC1,                  
    PIN_OC2,            
};

/* ------------------------------------------------------------ */
/* This table maps from an external interrupt number to the digital
** pin for that interrupt.
*/

const uint8_t external_int_to_digital_pin_PGM[] = {
    NOT_PPS_PIN,        
    PIN_INT1,            
    PIN_INT2,            
};



/* ------------------------------------------------------------ */
/*      Include Files for Board Customization Functions         */
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */
/*              Board Customization Functions                   */
/* ------------------------------------------------------------ */
/*                                                              */
/* The following can be used to customize the behavior of some  */
/* of the core API functions. These provide hooks that can be   */
/* used to extend or replace the default behavior of the core   */
/* functions. To use one of these functions, add the desired    */
/* code to the function skeleton below and then set the value   */
/* of the appropriate compile switch above to 1. This will      */
/* cause the hook function to be compiled into the build and    */
/* to cause the code to call the hook function to be compiled   */
/* into the appropriate core function.                          */
/*                                                              */
/* ------------------------------------------------------------ */
/***    _board_init
**
**  Parameters:
**      none
**
**  Return Value:
**      none
**
**  Errors:
**      none
**
**  Description:
**      This function is called from the core init() function.
**      This can be used to perform any board specific init
**      that needs to be done when the processor comes out of
**      reset and before the user sketch is run.
*/
#if (OPT_BOARD_INIT != 0)

void _board_init(void) {

    /*  Turn off Secondary oscillator so pins can be used as GPIO
    */
    OSCCONCLR   =   _OSCCON_SOSCEN_MASK;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_pinMode
**
**  Parameters:
**      pin     - digital pin number to configure
**      mode    - mode to which the pin should be configured
**
**  Return Value:
**      Returns 0 if not handled, !0 if handled.
**
**  Errors:
**      none
**
**  Description:
**      This function is called at the beginning of the pinMode
**      function. It can perform any special processing needed
**      when setting the pin mode. If this function returns zero,
**      control will pass through the normal pinMode code. If
**      it returns a non-zero value the normal pinMode code isn't
**      executed.
*/
#if (OPT_BOARD_DIGITAL_IO != 0)

int _board_pinMode(uint8_t pin, uint8_t mode) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_getPinMode
**
**  Parameters:
**      pin     - digital pin number
**      mode    - pointer to variable to receive mode value
**
**  Return Value:
**      Returns 0 if not handled, !0 if handled.
**
**  Errors:
**      none
**
**  Description:
**      This function is called at the beginning of the getPinMode
**      function. It can perform any special processing needed
**      when getting the pin mode. If this function returns zero,
**      control will pass through the normal getPinMode code. If
**      it returns a non-zero value the normal getPinMode code isn't
**      executed.
*/
#if (OPT_BOARD_DIGITAL_IO != 0)

int _board_getPinMode(uint8_t pin, uint8_t * mode) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_digitalWrite
**
**  Parameters:
**      pin     - digital pin number
**      val     - value to write to the pin
**
**  Return Value:
**      Returns 0 if not handled, !0 if handled.
**
**  Errors:
**      none
**
**  Description:
**      This function is called at the beginning of the digitalWrite
**      function. It can perform any special processing needed
**      in writing to the pin. If this function returns zero,
**      control will pass through the normal digitalWrite code. If
**      it returns a non-zero value the normal digitalWrite code isn't
**      executed.
*/#if   (OPT_BOARD_DIGITAL_IO != 0)

int _board_digitalWrite(uint8_t pin, uint8_t val) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_digitalRead
**
**  Parameters:
**      pin     - digital pin number
**      val     - pointer to variable to receive pin value
**
**  Return Value:
**      Returns 0 if not handled, !0 if handled.
**
**  Errors:
**      none
**
**  Description:
**      This function is called at the beginning of the digitalRead
**      function. It can perform any special processing needed
**      in reading from the pin. If this function returns zero,
**      control will pass through the normal digitalRead code. If
**      it returns a non-zero value the normal digitalRead code isn't
**      executed.
*/
#if (OPT_BOARD_DIGITAL_IO != 0)

int _board_digitalRead(uint8_t pin, uint8_t * val) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_analogRead
**
**  Parameters:
**      pin     - analog channel number
**      val     - pointer to variable to receive analog value
**
**  Return Value:
**      Returns 0 if not handled, !0 if handled.
**
**  Errors:
**      none
**
**  Description:
**      This function is called at the beginning of the analogRead
**      function. It can perform any special processing needed
**      in reading from the pin. If this function returns zero,
**      control will pass through the normal analogRead code. If
**      it returns a non-zero value the normal analogRead code isn't
**      executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int _board_analogRead(uint8_t pin, int * val) {

    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_analogReference
**
**  Parameters:
**
**  Return Value:
**      Returns 0 if not handled, !0 if handled.
**
**  Errors:
**      none
**
**  Description:
**      This function is called at the beginning of the analogReference
**      function. It can perform any special processing needed
**      to set the reference voltage. If this function returns zero,
**      control will pass through the normal analogReference code. If
**      it returns a non-zero value the normal analogReference code isn't
**      executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int _board_analogReference(uint8_t mode) {

    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_analogWrite
**
**  Parameters:
**      pin     - pin number
**      val     - analog value to write
**
**  Return Value:
**      Returns 0 if not handled, !0 if handled.
**
**  Errors:
**      none
**
**  Description:
**      This function is called at the beginning of the analogWrite
**      function. It can perform any special processing needed
**      in writing to the pin. If this function returns zero,
**      control will pass through the normal analogWrite code. If
**      it returns a non-zero value the normal analogWrite code isn't
**      executed.
*/
#if (OPT_BOARD_ANALOG_WRITE != 0)

int _board_analogWrite(uint8_t pin, int val) {

    return 0;

}

#endif

#endif // OPT_BOARD_DATA

/* ------------------------------------------------------------ */

#endif  // BOARD_DATA_C

/************************************************************************/
