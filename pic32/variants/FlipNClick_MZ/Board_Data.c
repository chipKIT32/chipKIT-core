/************************************************************************/
/*                                                                      */
/*    Board_Data.c -- Board Customization Data for Digilent chipKIT WF32*/
/*                                                                      */
/************************************************************************/
/*    Author: Gene Apperson                                             */
/*    Copyright 2011, Digilent. All rights reserved                     */
/************************************************************************/
/*  File Description:                                                   */
/*                                                                      */
/* This file contains the board specific declartions and data structure */
/* to customize the chipKIT MPIDE for use with the Digilent chipKIT     */
/* Uno32 board.                                                         */
/*                                                                      */
/* This code is based on earlier work:                                  */
/*        Copyright (c) 2010, 2011 by Mark Sproul                       */
/*        Copyright (c) 2005, 2006 by David A. Mellis                   */
/*                                                                       */
/************************************************************************/
/*  Revision History:                                                   */
/*                                                                      */
/*    11/28/2011(GeneA): Created by splitting data out of Board_Defs.h  */
//*	Feb 17, 2012	<KeithV> Added PPS support for MZ devices
/*                                                                      */
/************************************************************************/
//*    This library is free software; you can redistribute it and/or
//*    modify it under the terms of the GNU Lesser General Public
//*    License as published by the Free Software Foundation; either
//*    version 2.1 of the License, or (at your option) any later version.
//*    
//*    This library is distributed in the hope that it will be useful,
//*    but WITHOUT ANY WARRANTY; without even the implied warranty of
//*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//*    Lesser General Public License for more details.
//*    
//*    You should have received a copy of the GNU Lesser General
//*    Public License along with this library; if not, write to the
//*    Free Software Foundation, Inc., 59 Temple Place, Suite 330,
//*    Boston, MA  02111-1307  USA
/************************************************************************/

#if !defined(BOARD_DATA_C)
#define BOARD_DATA_C

#include <inttypes.h>

/* ------------------------------------------------------------ */
/*                    Data Tables                               */
/* ------------------------------------------------------------ */
/* The following declarations define data used in pin mapping.  */
/* ------------------------------------------------------------ */

#if defined(OPT_BOARD_DATA)

/* ------------------------------------------------------------ */
/* This table is used to map from port number to the address of
** the TRIS register for the port. This is used for setting the
** pin direction.
*/
const uint32_t port_to_tris_PGM[] = {
    NOT_A_PORT,                //index value 0 is not used

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

#if defined(_PORTH)
    (uint32_t)&TRISH,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTJ)
    (uint32_t)&TRISJ,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTK)
    (uint32_t)&TRISK,
#else
    NOT_A_PORT,
#endif

    NOT_A_PORT,
};

/* ------------------------------------------------------------ */
/* This table is used to map the digital pin number to the port
** containing that pin.
*/
const uint8_t digital_pin_to_port_PGM[] = {
    _IOPORT_PD,        // 0   RD14    AN32/AETXD0/RPD14/RD14
    _IOPORT_PD,        // 1   RD15    AN33/AETXD1/RPD15/SCK6/RD15
    _IOPORT_PD,        // 2   RD00    EMDIO/AEMDIO/RPD0/RTCC/INT0/RD0
    _IOPORT_PF,        // 3   RF13    TDI/EBIA18/AN30/RPF13/SCK5/RF13
    _IOPORT_PF,        // 4   RF08    EBIRDY2/RPF8/SCL3/RF8
    _IOPORT_PF,        // 5   RF12    TDO/EBIA17/AN31/RPF12/RF12
    _IOPORT_PB,        // 6   RB15    EBIA0/AN10/ERXD3/AETXD2/RPB15/OCFB/PMA0/RB15
    _IOPORT_PC,        // 7   RC13    SOSCI/RPC13/RC13
    _IOPORT_PF,        // 8   RF03    RPF3/USBID/RF3
    _IOPORT_PF,        // 9   RF02    EBIRDY3/RPF2/SDA3/RF2
    _IOPORT_PB,        // 10   RB08    EBIA10/AN48/RPB8/PMA10/RB8
    _IOPORT_PB,        // 11   RB10    EBIA13/CVREFOUT/AN5/RPB10/PMA13/RB10
    _IOPORT_PB,        // 12   RB09    EBIA7/AN49/RPB9/PMA7/RB9
    _IOPORT_PB,        // 13   RB14    EBIA1/AN9/ERXD2/AETXD3/RPB14/SCK3/PMA1/RB14
    _IOPORT_PG,        // 14   RG15    AN23/AERXERR/RG15
    _IOPORT_PB,        // 15   RB04    AN4/C1INB/RB4
    _IOPORT_PB,        // 16   RB00    PGED1/AN0/RPB0/RB0
    _IOPORT_PB,        // 17   RB01    PGEC1/AN1/RPB1/RB1
    _IOPORT_PB,        // 18   RB02    AN2/C2INB/RPB2/RB2
    _IOPORT_PB,        // 19   RB03    AN3/C2INA/RPB3/RB3
    _IOPORT_PF,        // 20   RF05    EBIA8/RPF5/SCL5/PMA8/RF5
    _IOPORT_PF,        // 21   RF04    EBIA9/RPF4/SDA5/PMA9/RF4
    _IOPORT_PA,        // 22   RA06    TRCLK/SQICLK/RA6
    _IOPORT_PA,        // 23   RA07    TRD3/SQID3/RA7
    _IOPORT_PE,        // 24   RE00    EBID0/PMD0/RE0
    _IOPORT_PE,        // 25   RE01    EBID1/PMD1/RE1
    _IOPORT_PB,        // 26   RB11    AN6/ERXERR/AETXERR/RB11
    _IOPORT_PE,        // 27   RE02    EBID2/PMD2/RE2
    _IOPORT_PA,        // 28   RA00    TMS/EBIA16/AN24/RA0
    _IOPORT_PG,        // 29   RG06    AN14/C1IND/ECOL/RPG6/SCK2/RG6
    _IOPORT_PC,        // 30   RC04    EBIOE/AN19/RPC4/PMRD/RC4
    _IOPORT_PB,        // 31   RB05    AN45/C1INA/RPB5/RB5
    _IOPORT_PC,        // 32   RC14    SOSCO/RPC14/T1CK/RC14
    _IOPORT_PD,        // 33   RD09    EBIA15/RPD9/PMCS2/PMA15/RD9
    _IOPORT_PG,        // 34   RG09    EBIA2/AN11/C2INC/ERXCLK/EREFCLK/AERXCLK/AEREFCLK/RPG9/PMA2/RG9
    _IOPORT_PE,        // 35   RE03    EBID3/RPE3/PMD3/RE3
    _IOPORT_PA,        // 36   RA02    EBICS0/SCL2/RA2
    _IOPORT_PA,        // 37   RA03    EBIRDY1/SDA2/RA3
    _IOPORT_PE,        // 38   RE07    EBID7/AN15/PMD7/RE7
    _IOPORT_PG,        // 39   RG13    TRD0/SQID0/RG13
    _IOPORT_PE,        // 40   RE04    EBID4/AN18/PMD4/RE4
    _IOPORT_PG,        // 41   RG06    AN14/C1IND/ECOL/RPG6/SCK2/RG6
    _IOPORT_PC,        // 42   RC04    EBIOE/AN19/RPC4/PMRD/RC4
    _IOPORT_PB,        // 43   RB05    AN45/C1INA/RPB5/RB5
    _IOPORT_PG,        // 44   RG00    EBID8/RPG0/PMD8/RG0
    _IOPORT_PG,        // 45   RG01    EBID9/ETXERR/RPG1/PMD9/RG1
    _IOPORT_PF,        // 46   RF00    EBID11/ETXD1/RPF0/PMD11/RF0
    _IOPORT_PF,        // 47   RF01    EBID10/ETXD0/RPF1/PMD10/RF1
    _IOPORT_PA,        // 48   RA02    EBICS0/SCL2/RA2
    _IOPORT_PA,        // 49   RA03    EBIRDY1/SDA2/RA3
    _IOPORT_PA,        // 50   RA05    EBIA5/AN34/PMA5/RA5
    _IOPORT_PG,        // 51   RG14    TRD2/SQID2/RG14
    _IOPORT_PD,        // 52   RD12    EBID12/ETXD2/RPD12/PMD12/RD12
    _IOPORT_PD,        // 53   RD01    RPD1/SCK1/RD1
    _IOPORT_PD,        // 54   RD02    EBID14/ETXEN/RPD2/PMD14/RD2
    _IOPORT_PD,        // 55   RD03    EBID15/ETXCLK/RPD3/PMD15/RD3
    _IOPORT_PG,        // 56   RG07    EBIA4/AN13/C1INC/ECRS/RPG7/SDA4/PMA4/RG7
    _IOPORT_PD,        // 57   RD05    SQICS1/RPD5/RD5
    _IOPORT_PC,        // 58   RC01    EBIA6/AN22/RPC1/PMA6/RC1
    _IOPORT_PE,        // 59   RE05    EBID5/AN17/RPE5/PMD5/RE5
    _IOPORT_PA,        // 60   RA14    AETXCLK/RPA14/SCL1/RA14
    _IOPORT_PA,        // 61   RA15    AETXEN/RPA15/SDA1/RA15
    _IOPORT_PE,        // 62   RE06    EBID6/AN16/PMD6/RE6
    _IOPORT_PG,        // 63   RG12    TRD1/SQID1/RG12
    _IOPORT_PD,        // 64   RD13    EBID13/ETXD3/PMD13/RD13
    _IOPORT_PD,        // 65   RD01    RPD1/SCK1/RD1
    _IOPORT_PD,        // 66   RD02    EBID14/ETXEN/RPD2/PMD14/RD2
    _IOPORT_PD,        // 67   RD03    EBID15/ETXCLK/RPD3/PMD15/RD3
    _IOPORT_PG,        // 68   RG08    EBIA3/AN12/C2IND/ERXDV/ECRSDV/AERXDV/AECRSDV/RPG8/SCL4/PMA3/RG8
    _IOPORT_PD,        // 69   RD04    SQICS0/RPD4/RD4
    _IOPORT_PC,        // 70   RC03    EBIWE/AN20/RPC3/PMWR/RC3
    _IOPORT_PC,        // 71   RC02    EBIA12/AN21/RPC2/PMA12/RC2
    _IOPORT_PA,        // 72   RA14    AETXCLK/RPA14/SCL1/RA14
    _IOPORT_PA,        // 73   RA15    AETXEN/RPA15/SDA1/RA15
    _IOPORT_PD,        // 74   RD10    RPD10/SCK4/RD10
    _IOPORT_PD,        // 75   RD11    EMDC/AEMDC/RPD11/RD11
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to a bit mask
** for the corresponding bit within the port.
*/
const uint16_t digital_pin_to_bit_mask_PGM[] =
{
    _BV( 14 ),        // 0   RD14    AN32/AETXD0/RPD14/RD14
    _BV( 15 ),        // 1   RD15    AN33/AETXD1/RPD15/SCK6/RD15
    _BV( 0 ),         // 2   RD00    EMDIO/AEMDIO/RPD0/RTCC/INT0/RD0
    _BV( 13 ),        // 3   RF13    TDI/EBIA18/AN30/RPF13/SCK5/RF13
    _BV( 8 ),         // 4   RF08    EBIRDY2/RPF8/SCL3/RF8
    _BV( 12 ),        // 5   RF12    TDO/EBIA17/AN31/RPF12/RF12
    _BV( 15 ),        // 6   RB15    EBIA0/AN10/ERXD3/AETXD2/RPB15/OCFB/PMA0/RB15
    _BV( 13 ),        // 7   RC13    SOSCI/RPC13/RC13
    _BV( 3 ),         // 8   RF03    RPF3/USBID/RF3
    _BV( 2 ),         // 9   RF02    EBIRDY3/RPF2/SDA3/RF2
    _BV( 8 ),         // 10   RB08    EBIA10/AN48/RPB8/PMA10/RB8
    _BV( 10 ),        // 11   RB10    EBIA13/CVREFOUT/AN5/RPB10/PMA13/RB10
    _BV( 9 ),         // 12   RB09    EBIA7/AN49/RPB9/PMA7/RB9
    _BV( 14 ),        // 13   RB14    EBIA1/AN9/ERXD2/AETXD3/RPB14/SCK3/PMA1/RB14
    _BV( 15 ),        // 14   RG15    AN23/AERXERR/RG15
    _BV( 4 ),         // 15   RB04    AN4/C1INB/RB4
    _BV( 0 ),         // 16   RB00    PGED1/AN0/RPB0/RB0
    _BV( 1 ),         // 17   RB01    PGEC1/AN1/RPB1/RB1
    _BV( 2 ),         // 18   RB02    AN2/C2INB/RPB2/RB2
    _BV( 3 ),         // 19   RB03    AN3/C2INA/RPB3/RB3
    _BV( 5 ),         // 20   RF05    EBIA8/RPF5/SCL5/PMA8/RF5
    _BV( 4 ),         // 21   RF04    EBIA9/RPF4/SDA5/PMA9/RF4
    _BV( 6 ),         // 22   RA06    TRCLK/SQICLK/RA6
    _BV( 7 ),         // 23   RA07    TRD3/SQID3/RA7
    _BV( 0 ),         // 24   RE00    EBID0/PMD0/RE0
    _BV( 1 ),         // 25   RE01    EBID1/PMD1/RE1
    _BV( 11 ),        // 26   RB11    AN6/ERXERR/AETXERR/RB11
    _BV( 2 ),         // 27   RE02    EBID2/PMD2/RE2
    _BV( 0 ),         // 28   RA00    TMS/EBIA16/AN24/RA0
    _BV( 6 ),         // 29   RG06    AN14/C1IND/ECOL/RPG6/SCK2/RG6
    _BV( 4 ),         // 30   RC04    EBIOE/AN19/RPC4/PMRD/RC4
    _BV( 5 ),         // 31   RB05    AN45/C1INA/RPB5/RB5
    _BV( 14 ),        // 32   RC14    SOSCO/RPC14/T1CK/RC14
    _BV( 9 ),         // 33   RD09    EBIA15/RPD9/PMCS2/PMA15/RD9
    _BV( 9 ),         // 34   RG09    EBIA2/AN11/C2INC/ERXCLK/EREFCLK/AERXCLK/AEREFCLK/RPG9/PMA2/RG9
    _BV( 3 ),         // 35   RE03    EBID3/RPE3/PMD3/RE3
    _BV( 2 ),         // 36   RA02    EBICS0/SCL2/RA2
    _BV( 3 ),         // 37   RA03    EBIRDY1/SDA2/RA3
    _BV( 7 ),         // 38   RE07    EBID7/AN15/PMD7/RE7
    _BV( 13 ),        // 39   RG13    TRD0/SQID0/RG13
    _BV( 4 ),         // 40   RE04    EBID4/AN18/PMD4/RE4
    _BV( 6 ),         // 41   RG06    AN14/C1IND/ECOL/RPG6/SCK2/RG6
    _BV( 4 ),         // 42   RC04    EBIOE/AN19/RPC4/PMRD/RC4
    _BV( 5 ),         // 43   RB05    AN45/C1INA/RPB5/RB5
    _BV( 0 ),         // 44   RG00    EBID8/RPG0/PMD8/RG0
    _BV( 1 ),         // 45   RG01    EBID9/ETXERR/RPG1/PMD9/RG1
    _BV( 0 ),         // 46   RF00    EBID11/ETXD1/RPF0/PMD11/RF0
    _BV( 1 ),         // 47   RF01    EBID10/ETXD0/RPF1/PMD10/RF1
    _BV( 2 ),         // 48   RA02    EBICS0/SCL2/RA2
    _BV( 3 ),         // 49   RA03    EBIRDY1/SDA2/RA3
    _BV( 5 ),         // 50   RA05    EBIA5/AN34/PMA5/RA5
    _BV( 14 ),        // 51   RG14    TRD2/SQID2/RG14
    _BV( 12 ),        // 52   RD12    EBID12/ETXD2/RPD12/PMD12/RD12
    _BV( 1 ),         // 53   RD01    RPD1/SCK1/RD1
    _BV( 2 ),         // 54   RD02    EBID14/ETXEN/RPD2/PMD14/RD2
    _BV( 3 ),         // 55   RD03    EBID15/ETXCLK/RPD3/PMD15/RD3
    _BV( 7 ),         // 56   RG07    EBIA4/AN13/C1INC/ECRS/RPG7/SDA4/PMA4/RG7
    _BV( 5 ),         // 57   RD05    SQICS1/RPD5/RD5
    _BV( 1 ),         // 58   RC01    EBIA6/AN22/RPC1/PMA6/RC1
    _BV( 5 ),         // 59   RE05    EBID5/AN17/RPE5/PMD5/RE5
    _BV( 14 ),        // 60   RA14    AETXCLK/RPA14/SCL1/RA14
    _BV( 15 ),        // 61   RA15    AETXEN/RPA15/SDA1/RA15
    _BV( 6 ),         // 62   RE06    EBID6/AN16/PMD6/RE6
    _BV( 12 ),        // 63   RG12    TRD1/SQID1/RG12
    _BV( 13 ),        // 64   RD13    EBID13/ETXD3/PMD13/RD13
    _BV( 1 ),         // 65   RD01    RPD1/SCK1/RD1
    _BV( 2 ),         // 66   RD02    EBID14/ETXEN/RPD2/PMD14/RD2
    _BV( 3 ),         // 67   RD03    EBID15/ETXCLK/RPD3/PMD15/RD3
    _BV( 8 ),         // 68   RG08    EBIA3/AN12/C2IND/ERXDV/ECRSDV/AERXDV/AECRSDV/RPG8/SCL4/PMA3/RG8
    _BV( 4 ),         // 69   RD04    SQICS0/RPD4/RD4
    _BV( 3 ),         // 70   RC03    EBIWE/AN20/RPC3/PMWR/RC3
    _BV( 2 ),         // 71   RC02    EBIA12/AN21/RPC2/PMA12/RC2
    _BV( 14 ),        // 72   RA14    AETXCLK/RPA14/SCL1/RA14
    _BV( 15 ),        // 73   RA15    AETXEN/RPA15/SDA1/RA15
    _BV( 10 ),        // 74   RD10    RPD10/SCK4/RD10
    _BV( 11 ),        // 75   RD11    EMDC/AEMDC/RPD11/RD11
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to the output
** compare number, input capture number, and timer external clock
** input associated with that pin.
*/
const uint16_t digital_pin_to_timer_PGM[] =
{
    NOT_ON_TIMER,               // 0   RD14    AN32/AETXD0/RPD14/RD14
    NOT_ON_TIMER,               // 1   RD15    AN33/AETXD1/RPD15/SCK6/RD15
    _TIMER_IC1,                // 2   RD00    EMDIO/AEMDIO/RPD0/RTCC/INT0/RD0
    _TIMER_OC1,               // 3   RF13    TDI/EBIA18/AN30/RPF13/SCK5/RF13
    NOT_ON_TIMER,                // 4   RF08    EBIRDY2/RPF8/SCL3/RF8
    _TIMER_OC5,               // 5   RF12    TDO/EBIA17/AN31/RPF12/RF12
    _TIMER_OC8,               // 6   RB15    EBIA0/AN10/ERXD3/AETXD2/RPB15/OCFB/PMA0/RB15
    _TIMER_IC4,               // 7   RC13    SOSCI/RPC13/RC13
    _TIMER_OC2 | _TIMER_IC3,   // 8   RF03    RPF3/USBID/RF3
    _TIMER_OC9,                // 9   RF02    EBIRDY3/RPF2/SDA3/RF2
    _TIMER_IC5,                // 10   RB08    EBIA10/AN48/RPB8/PMA10/RB8
    NOT_ON_TIMER,               // 11   RB10    EBIA13/CVREFOUT/AN5/RPB10/PMA13/RB10
    NOT_ON_TIMER,                // 12   RB09    EBIA7/AN49/RPB9/PMA7/RB9
    NOT_ON_TIMER,               // 13   RB14    EBIA1/AN9/ERXD2/AETXD3/RPB14/SCK3/PMA1/RB14
    NOT_ON_TIMER,               // 14   RG15    AN23/AERXERR/RG15
    NOT_ON_TIMER,                // 15   RB04    AN4/C1INB/RB4
    NOT_ON_TIMER,                // 16   RB00    PGED1/AN0/RPB0/RB0
    NOT_ON_TIMER,                // 17   RB01    PGEC1/AN1/RPB1/RB1
    NOT_ON_TIMER,                // 18   RB02    AN2/C2INB/RPB2/RB2
    NOT_ON_TIMER,                // 19   RB03    AN3/C2INA/RPB3/RB3
    NOT_ON_TIMER,                // 20   RF05    EBIA8/RPF5/SCL5/PMA8/RF5
    NOT_ON_TIMER,                // 21   RF04    EBIA9/RPF4/SDA5/PMA9/RF4
    NOT_ON_TIMER,                // 22   RA06    TRCLK/SQICLK/RA6
    NOT_ON_TIMER,                // 23   RA07    TRD3/SQID3/RA7
    NOT_ON_TIMER,                // 24   RE00    EBID0/PMD0/RE0
    NOT_ON_TIMER,                // 25   RE01    EBID1/PMD1/RE1
    NOT_ON_TIMER,               // 26   RB11    AN6/ERXERR/AETXERR/RB11
    NOT_ON_TIMER,                // 27   RE02    EBID2/PMD2/RE2
    NOT_ON_TIMER,                // 28   RA00    TMS/EBIA16/AN24/RA0
    NOT_ON_TIMER,                // 29   RG06    AN14/C1IND/ECOL/RPG6/SCK2/RG6
    NOT_ON_TIMER,                // 30   RC04    EBIOE/AN19/RPC4/PMRD/RC4
    NOT_ON_TIMER,                // 31   RB05    AN45/C1INA/RPB5/RB5
    _TIMER_OC6,               // 32   RC14    SOSCO/RPC14/T1CK/RC14
    NOT_ON_TIMER,                // 33   RD09    EBIA15/RPD9/PMCS2/PMA15/RD9
    NOT_ON_TIMER,                // 34   RG09    EBIA2/AN11/C2INC/ERXCLK/EREFCLK/AERXCLK/AEREFCLK/RPG9/PMA2/RG9
    NOT_ON_TIMER,                // 35   RE03    EBID3/RPE3/PMD3/RE3
    NOT_ON_TIMER,                // 36   RA02    EBICS0/SCL2/RA2
    NOT_ON_TIMER,                // 37   RA03    EBIRDY1/SDA2/RA3
    NOT_ON_TIMER,                // 38   RE07    EBID7/AN15/PMD7/RE7
    NOT_ON_TIMER,               // 39   RG13    TRD0/SQID0/RG13
    NOT_ON_TIMER,                // 40   RE04    EBID4/AN18/PMD4/RE4
    NOT_ON_TIMER,                // 41   RG06    AN14/C1IND/ECOL/RPG6/SCK2/RG6
    NOT_ON_TIMER,                // 42   RC04    EBIOE/AN19/RPC4/PMRD/RC4
    NOT_ON_TIMER,                // 43   RB05    AN45/C1INA/RPB5/RB5
    _TIMER_OC7,                // 44   RG00    EBID8/RPG0/PMD8/RG0
    NOT_ON_TIMER,                // 45   RG01    EBID9/ETXERR/RPG1/PMD9/RG1
    NOT_ON_TIMER,                // 46   RF00    EBID11/ETXD1/RPF0/PMD11/RF0
    NOT_ON_TIMER,                // 47   RF01    EBID10/ETXD0/RPF1/PMD10/RF1
    NOT_ON_TIMER,                // 48   RA02    EBICS0/SCL2/RA2
    NOT_ON_TIMER,                // 49   RA03    EBIRDY1/SDA2/RA3
    NOT_ON_TIMER,                // 50   RA05    EBIA5/AN34/PMA5/RA5
    NOT_ON_TIMER,               // 51   RG14    TRD2/SQID2/RG14
    NOT_ON_TIMER,               // 52   RD12    EBID12/ETXD2/RPD12/PMD12/RD12
    NOT_ON_TIMER,                // 53   RD01    RPD1/SCK1/RD1
    NOT_ON_TIMER,                // 54   RD02    EBID14/ETXEN/RPD2/PMD14/RD2
    NOT_ON_TIMER,                // 55   RD03    EBID15/ETXCLK/RPD3/PMD15/RD3
    _TIMER_OC4,                // 56   RG07    EBIA4/AN13/C1INC/ECRS/RPG7/SDA4/PMA4/RG7
    NOT_ON_TIMER,                // 57   RD05    SQICS1/RPD5/RD5
    NOT_ON_TIMER,                // 58   RC01    EBIA6/AN22/RPC1/PMA6/RC1
    NOT_ON_TIMER,                // 59   RE05    EBID5/AN17/RPE5/PMD5/RE5
    NOT_ON_TIMER,               // 60   RA14    AETXCLK/RPA14/SCL1/RA14
    NOT_ON_TIMER,               // 61   RA15    AETXEN/RPA15/SDA1/RA15
    NOT_ON_TIMER,                // 62   RE06    EBID6/AN16/PMD6/RE6
    NOT_ON_TIMER,               // 63   RG12    TRD1/SQID1/RG12
    NOT_ON_TIMER,               // 64   RD13    EBID13/ETXD3/PMD13/RD13
    NOT_ON_TIMER,                // 65   RD01    RPD1/SCK1/RD1
    NOT_ON_TIMER,                // 66   RD02    EBID14/ETXEN/RPD2/PMD14/RD2
    NOT_ON_TIMER,                // 67   RD03    EBID15/ETXCLK/RPD3/PMD15/RD3
    _TIMER_OC3,                // 68   RG08    EBIA3/AN12/C2IND/ERXDV/ECRSDV/AERXDV/AECRSDV/RPG8/SCL4/PMA3/RG8
    NOT_ON_TIMER,                // 69   RD04    SQICS0/RPD4/RD4
    NOT_ON_TIMER,                // 70   RC03    EBIWE/AN20/RPC3/PMWR/RC3
    NOT_ON_TIMER,                // 71   RC02    EBIA12/AN21/RPC2/PMA12/RC2
    NOT_ON_TIMER,               // 72   RA14    AETXCLK/RPA14/SCL1/RA14
    NOT_ON_TIMER,               // 73   RA15    AETXEN/RPA15/SDA1/RA15
    NOT_ON_TIMER,               // 74   RD10    RPD10/SCK4/RD10
    NOT_ON_TIMER,               // 75   RD11    EMDC/AEMDC/RPD11/RD11
};

/* ------------------------------------------------------------ */
/* This table maps from a digital pin number to the corresponding
** analog pin number.
*/
const uint8_t digital_pin_to_analog_PGM[] =
{
    NOT_ANALOG_PIN,             // 0   RD14    AN32/AETXD0/RPD14/RD14
    NOT_ANALOG_PIN,             // 1   RD15    AN33/AETXD1/RPD15/SCK6/RD15
    NOT_ANALOG_PIN,             // 2   RD00    EMDIO/AEMDIO/RPD0/RTCC/INT0/RD0
    NOT_ANALOG_PIN,             // 3   RF13    TDI/EBIA18/AN30/RPF13/SCK5/RF13
    NOT_ANALOG_PIN,             // 4   RF08    EBIRDY2/RPF8/SCL3/RF8
    NOT_ANALOG_PIN,             // 5   RF12    TDO/EBIA17/AN31/RPF12/RF12
    NOT_ANALOG_PIN,             // 6   RB15    EBIA0/AN10/ERXD3/AETXD2/RPB15/OCFB/PMA0/RB15
    NOT_ANALOG_PIN,             // 7   RC13    SOSCI/RPC13/RC13
    NOT_ANALOG_PIN,             // 8   RF03    RPF3/USBID/RF3
    NOT_ANALOG_PIN,             // 9   RF02    EBIRDY3/RPF2/SDA3/RF2
    NOT_ANALOG_PIN,             // 10   RB08    EBIA10/AN48/RPB8/PMA10/RB8
    NOT_ANALOG_PIN,             // 11   RB10    EBIA13/CVREFOUT/AN5/RPB10/PMA13/RB10
    NOT_ANALOG_PIN,             // 12   RB09    EBIA7/AN49/RPB9/PMA7/RB9
    NOT_ANALOG_PIN,             // 13   RB14    EBIA1/AN9/ERXD2/AETXD3/RPB14/SCK3/PMA1/RB14
    _BOARD_AN0,                // 14   RG15    AN23/AERXERR/RG15
    _BOARD_AN1,                 // 15   RB04    AN4/C1INB/RB4
    _BOARD_AN2,                 // 16   RB00    PGED1/AN0/RPB0/RB0
    _BOARD_AN3,                 // 17   RB01    PGEC1/AN1/RPB1/RB1
    _BOARD_AN4,                 // 18   RB02    AN2/C2INB/RPB2/RB2
    _BOARD_AN5,                 // 19   RB03    AN3/C2INA/RPB3/RB3
    NOT_ANALOG_PIN,             // 20   RF05    EBIA8/RPF5/SCL5/PMA8/RF5
    NOT_ANALOG_PIN,             // 21   RF04    EBIA9/RPF4/SDA5/PMA9/RF4
    NOT_ANALOG_PIN,             // 22   RA06    TRCLK/SQICLK/RA6
    NOT_ANALOG_PIN,             // 23   RA07    TRD3/SQID3/RA7
    NOT_ANALOG_PIN,             // 24   RE00    EBID0/PMD0/RE0
    NOT_ANALOG_PIN,             // 25   RE01    EBID1/PMD1/RE1
    _BOARD_AN6,                // 26   RB11    AN6/ERXERR/AETXERR/RB11
    NOT_ANALOG_PIN,             // 27   RE02    EBID2/PMD2/RE2
    NOT_ANALOG_PIN,             // 28   RA00    TMS/EBIA16/AN24/RA0
    NOT_ANALOG_PIN,             // 29   RG06    AN14/C1IND/ECOL/RPG6/SCK2/RG6
    NOT_ANALOG_PIN,             // 30   RC04    EBIOE/AN19/RPC4/PMRD/RC4
    NOT_ANALOG_PIN,             // 31   RB05    AN45/C1INA/RPB5/RB5
    NOT_ANALOG_PIN,             // 32   RC14    SOSCO/RPC14/T1CK/RC14
    NOT_ANALOG_PIN,             // 33   RD09    EBIA15/RPD9/PMCS2/PMA15/RD9
    NOT_ANALOG_PIN,             // 34   RG09    EBIA2/AN11/C2INC/ERXCLK/EREFCLK/AERXCLK/AEREFCLK/RPG9/PMA2/RG9
    NOT_ANALOG_PIN,             // 35   RE03    EBID3/RPE3/PMD3/RE3
    NOT_ANALOG_PIN,             // 36   RA02    EBICS0/SCL2/RA2
    NOT_ANALOG_PIN,             // 37   RA03    EBIRDY1/SDA2/RA3
    _BOARD_AN7,                 // 38   RE07    EBID7/AN15/PMD7/RE7
    NOT_ANALOG_PIN,             // 39   RG13    TRD0/SQID0/RG13
    NOT_ANALOG_PIN,             // 40   RE04    EBID4/AN18/PMD4/RE4
    NOT_ANALOG_PIN,             // 41   RG06    AN14/C1IND/ECOL/RPG6/SCK2/RG6
    NOT_ANALOG_PIN,             // 42   RC04    EBIOE/AN19/RPC4/PMRD/RC4
    NOT_ANALOG_PIN,             // 43   RB05    AN45/C1INA/RPB5/RB5
    NOT_ANALOG_PIN,             // 44   RG00    EBID8/RPG0/PMD8/RG0
    NOT_ANALOG_PIN,             // 45   RG01    EBID9/ETXERR/RPG1/PMD9/RG1
    NOT_ANALOG_PIN,             // 46   RF00    EBID11/ETXD1/RPF0/PMD11/RF0
    NOT_ANALOG_PIN,             // 47   RF01    EBID10/ETXD0/RPF1/PMD10/RF1
    NOT_ANALOG_PIN,             // 48   RA02    EBICS0/SCL2/RA2
    NOT_ANALOG_PIN,             // 49   RA03    EBIRDY1/SDA2/RA3
    _BOARD_AN8,                 // 50   RA05    EBIA5/AN34/PMA5/RA5
    NOT_ANALOG_PIN,             // 51   RG14    TRD2/SQID2/RG14
    NOT_ANALOG_PIN,             // 52   RD12    EBID12/ETXD2/RPD12/PMD12/RD12
    NOT_ANALOG_PIN,             // 53   RD01    RPD1/SCK1/RD1
    NOT_ANALOG_PIN,             // 54   RD02    EBID14/ETXEN/RPD2/PMD14/RD2
    NOT_ANALOG_PIN,             // 55   RD03    EBID15/ETXCLK/RPD3/PMD15/RD3
    NOT_ANALOG_PIN,             // 56   RG07    EBIA4/AN13/C1INC/ECRS/RPG7/SDA4/PMA4/RG7
    NOT_ANALOG_PIN,             // 57   RD05    SQICS1/RPD5/RD5
    NOT_ANALOG_PIN,             // 58   RC01    EBIA6/AN22/RPC1/PMA6/RC1
    NOT_ANALOG_PIN,             // 59   RE05    EBID5/AN17/RPE5/PMD5/RE5
    NOT_ANALOG_PIN,             // 60   RA14    AETXCLK/RPA14/SCL1/RA14
    NOT_ANALOG_PIN,             // 61   RA15    AETXEN/RPA15/SDA1/RA15
    _BOARD_AN9,                 // 62   RE06    EBID6/AN16/PMD6/RE6
    NOT_ANALOG_PIN,             // 63   RG12    TRD1/SQID1/RG12
    NOT_ANALOG_PIN,             // 64   RD13    EBID13/ETXD3/PMD13/RD13
    NOT_ANALOG_PIN,             // 65   RD01    RPD1/SCK1/RD1
    NOT_ANALOG_PIN,             // 66   RD02    EBID14/ETXEN/RPD2/PMD14/RD2
    NOT_ANALOG_PIN,             // 67   RD03    EBID15/ETXCLK/RPD3/PMD15/RD3
    NOT_ANALOG_PIN,             // 68   RG08    EBIA3/AN12/C2IND/ERXDV/ECRSDV/AERXDV/AECRSDV/RPG8/SCL4/PMA3/RG8
    NOT_ANALOG_PIN,             // 69   RD04    SQICS0/RPD4/RD4
    NOT_ANALOG_PIN,             // 70   RC03    EBIWE/AN20/RPC3/PMWR/RC3
    NOT_ANALOG_PIN,             // 71   RC02    EBIA12/AN21/RPC2/PMA12/RC2
    NOT_ANALOG_PIN,             // 72   RA14    AETXCLK/RPA14/SCL1/RA14
    NOT_ANALOG_PIN,             // 73   RA15    AETXEN/RPA15/SDA1/RA15
    NOT_ANALOG_PIN,             // 74   RD10    RPD10/SCK4/RD10
    NOT_ANALOG_PIN,             // 75   RD11    EMDC/AEMDC/RPD11/RD11
};

/* ------------------------------------------------------------ */
/* This table is used to map from the analog pin number to the
** actual A/D converter channel used for that pin.
*/
const uint8_t analog_pin_to_channel_PGM[] =
{
                //*    chipKIT Pin        PIC32 Analog channel
    3,          //*    A0                       AN3
    2,          //*    A1                       AN2
    1,          //*    A2                       AN1
    0,          //*    A3                       AN0
    4,          //*    A4                       AN4
    23,         //*    A5                       AN23
    6,          //*    A6 (Click A AN)          AN6
    15,         //*    A7 (Click B AN)          AN15
    34,         //*    A8 (Click C AN)          AN34
    16,         //*    A9 (Click D AN)          AN16
};


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
const uint8_t digital_pin_to_pps_out_PGM[] =
{
    _PPS_OUT(_PPS_RPD14R),      // 0   RD14    AN32/AETXD0/RPD14/RD14
    _PPS_OUT(_PPS_RPD15R),      // 1   RD15    AN33/AETXD1/RPD15/SCK6/RD15
    _PPS_OUT(_PPS_RPD0R),       // 2   RD00    EMDIO/AEMDIO/RPD0/RTCC/INT0/RD0
    _PPS_OUT(_PPS_RPF13R),      // 3   RF13    TDI/EBIA18/AN30/RPF13/SCK5/RF13
    _PPS_OUT(_PPS_RPF8R),       // 4   RF08    EBIRDY2/RPF8/SCL3/RF8
    _PPS_OUT(_PPS_RPF12R),      // 5   RF12    TDO/EBIA17/AN31/RPF12/RF12
    _PPS_OUT(_PPS_RPB15R),      // 6   RB15    EBIA0/AN10/ERXD3/AETXD2/RPB15/OCFB/PMA0/RB15
    _PPS_OUT(_PPS_RPC13R),      // 7   RC13    SOSCI/RPC13/RC13
    _PPS_OUT(_PPS_RPF3R),       // 8   RF03    RPF3/USBID/RF3
    _PPS_OUT(_PPS_RPF2R),       // 9   RF02    EBIRDY3/RPF2/SDA3/RF2
    _PPS_OUT(_PPS_RPB8R),       // 10   RB08    EBIA10/AN48/RPB8/PMA10/RB8
    _PPS_OUT(_PPS_RPB10R),      // 11   RB10    EBIA13/CVREFOUT/AN5/RPB10/PMA13/RB10
    _PPS_OUT(_PPS_RPB9R),       // 12   RB09    EBIA7/AN49/RPB9/PMA7/RB9
    _PPS_OUT(_PPS_RPB14R),      // 13   RB14    EBIA1/AN9/ERXD2/AETXD3/RPB14/SCK3/PMA1/RB14
    NOT_PPS_PIN,               // 14   RG15    AN23/AERXERR/RG15
    NOT_PPS_PIN,               // 15   RB04    AN4/C1INB/RB4
    _PPS_OUT(_PPS_RPB0R),       // 16   RB00    PGED1/AN0/RPB0/RB0
    _PPS_OUT(_PPS_RPB1R),       // 17   RB01    PGEC1/AN1/RPB1/RB1
    _PPS_OUT(_PPS_RPB2R),       // 18   RB02    AN2/C2INB/RPB2/RB2
    _PPS_OUT(_PPS_RPB3R),       // 19   RB03    AN3/C2INA/RPB3/RB3
    _PPS_OUT(_PPS_RPF5R),       // 20   RF05    EBIA8/RPF5/SCL5/PMA8/RF5
    _PPS_OUT(_PPS_RPF4R),       // 21   RF04    EBIA9/RPF4/SDA5/PMA9/RF4
    NOT_PPS_PIN,               // 22   RA06    TRCLK/SQICLK/RA6
    NOT_PPS_PIN,               // 23   RA07    TRD3/SQID3/RA7
    NOT_PPS_PIN,               // 24   RE00    EBID0/PMD0/RE0
    NOT_PPS_PIN,               // 25   RE01    EBID1/PMD1/RE1
    NOT_PPS_PIN,               // 26   RB11    AN6/ERXERR/AETXERR/RB11
    NOT_PPS_PIN,               // 27   RE02    EBID2/PMD2/RE2
    NOT_PPS_PIN,               // 28   RA00    TMS/EBIA16/AN24/RA0
    _PPS_OUT(_PPS_RPG6R),       // 29   RG06    AN14/C1IND/ECOL/RPG6/SCK2/RG6
    _PPS_OUT(_PPS_RPC4R),       // 30   RC04    EBIOE/AN19/RPC4/PMRD/RC4
    _PPS_OUT(_PPS_RPB5R),       // 31   RB05    AN45/C1INA/RPB5/RB5
    _PPS_OUT(_PPS_RPC14R),      // 32   RC14    SOSCO/RPC14/T1CK/RC14
    _PPS_OUT(_PPS_RPD9R),       // 33   RD09    EBIA15/RPD9/PMCS2/PMA15/RD9
    _PPS_OUT(_PPS_RPG9R),       // 34   RG09    EBIA2/AN11/C2INC/ERXCLK/EREFCLK/AERXCLK/AEREFCLK/RPG9/PMA2/RG9
    _PPS_OUT(_PPS_RPE3R),       // 35   RE03    EBID3/RPE3/PMD3/RE3
    NOT_PPS_PIN,               // 36   RA02    EBICS0/SCL2/RA2
    NOT_PPS_PIN,               // 37   RA03    EBIRDY1/SDA2/RA3
    NOT_PPS_PIN,               // 38   RE07    EBID7/AN15/PMD7/RE7
    NOT_PPS_PIN,               // 39   RG13    TRD0/SQID0/RG13
    NOT_PPS_PIN,               // 40   RE04    EBID4/AN18/PMD4/RE4
    _PPS_OUT(_PPS_RPG6R),       // 41   RG06    AN14/C1IND/ECOL/RPG6/SCK2/RG6
    _PPS_OUT(_PPS_RPC4R),       // 42   RC04    EBIOE/AN19/RPC4/PMRD/RC4
    _PPS_OUT(_PPS_RPB5R),       // 43   RB05    AN45/C1INA/RPB5/RB5
    _PPS_OUT(_PPS_RPG0R),       // 44   RG00    EBID8/RPG0/PMD8/RG0
    _PPS_OUT(_PPS_RPG1R),       // 45   RG01    EBID9/ETXERR/RPG1/PMD9/RG1
    _PPS_OUT(_PPS_RPF0R),       // 46   RF00    EBID11/ETXD1/RPF0/PMD11/RF0
    _PPS_OUT(_PPS_RPF1R),       // 47   RF01    EBID10/ETXD0/RPF1/PMD10/RF1
    NOT_PPS_PIN,               // 48   RA02    EBICS0/SCL2/RA2
    NOT_PPS_PIN,               // 49   RA03    EBIRDY1/SDA2/RA3
    NOT_PPS_PIN,               // 50   RA05    EBIA5/AN34/PMA5/RA5
    NOT_PPS_PIN,               // 51   RG14    TRD2/SQID2/RG14
    _PPS_OUT(_PPS_RPD12R),      // 52   RD12    EBID12/ETXD2/RPD12/PMD12/RD12
    _PPS_OUT(_PPS_RPD1R),       // 53   RD01    RPD1/SCK1/RD1
    _PPS_OUT(_PPS_RPD2R),       // 54   RD02    EBID14/ETXEN/RPD2/PMD14/RD2
    _PPS_OUT(_PPS_RPD3R),       // 55   RD03    EBID15/ETXCLK/RPD3/PMD15/RD3
    _PPS_OUT(_PPS_RPG7R),       // 56   RG07    EBIA4/AN13/C1INC/ECRS/RPG7/SDA4/PMA4/RG7
    _PPS_OUT(_PPS_RPD5R),       // 57   RD05    SQICS1/RPD5/RD5
    _PPS_OUT(_PPS_RPC1R),       // 58   RC01    EBIA6/AN22/RPC1/PMA6/RC1
    _PPS_OUT(_PPS_RPE5R),       // 59   RE05    EBID5/AN17/RPE5/PMD5/RE5
    _PPS_OUT(_PPS_RPA14R),      // 60   RA14    AETXCLK/RPA14/SCL1/RA14
    _PPS_OUT(_PPS_RPA15R),      // 61   RA15    AETXEN/RPA15/SDA1/RA15
    NOT_PPS_PIN,               // 62   RE06    EBID6/AN16/PMD6/RE6
    NOT_PPS_PIN,               // 63   RG12    TRD1/SQID1/RG12
    NOT_PPS_PIN,               // 64   RD13    EBID13/ETXD3/PMD13/RD13
    _PPS_OUT(_PPS_RPD1R),       // 65   RD01    RPD1/SCK1/RD1
    _PPS_OUT(_PPS_RPD2R),       // 66   RD02    EBID14/ETXEN/RPD2/PMD14/RD2
    _PPS_OUT(_PPS_RPD3R),       // 67   RD03    EBID15/ETXCLK/RPD3/PMD15/RD3
    _PPS_OUT(_PPS_RPG8R),       // 68   RG08    EBIA3/AN12/C2IND/ERXDV/ECRSDV/AERXDV/AECRSDV/RPG8/SCL4/PMA3/RG8
    _PPS_OUT(_PPS_RPD4R),       // 69   RD04    SQICS0/RPD4/RD4
    _PPS_OUT(_PPS_RPC3R),       // 70   RC03    EBIWE/AN20/RPC3/PMWR/RC3
    _PPS_OUT(_PPS_RPC2R),       // 71   RC02    EBIA12/AN21/RPC2/PMA12/RC2
    _PPS_OUT(_PPS_RPA14R),      // 72   RA14    AETXCLK/RPA14/SCL1/RA14
    _PPS_OUT(_PPS_RPA15R),      // 73   RA15    AETXEN/RPA15/SDA1/RA15
    _PPS_OUT(_PPS_RPD10R),      // 74   RD10    RPD10/SCK4/RD10
    _PPS_OUT(_PPS_RPD11R),      // 75   RD11    EMDC/AEMDC/RPD11/RD11
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
const uint8_t digital_pin_to_pps_in_PGM[] =
{
    _PPS_IN(_PPS_RPD14),      // 0   RD14    AN32/AETXD0/RPD14/RD14
    _PPS_IN(_PPS_RPD15),      // 1   RD15    AN33/AETXD1/RPD15/SCK6/RD15
    _PPS_IN(_PPS_RPD0),       // 2   RD00    EMDIO/AEMDIO/RPD0/RTCC/INT0/RD0
    _PPS_IN(_PPS_RPF13),      // 3   RF13    TDI/EBIA18/AN30/RPF13/SCK5/RF13
    _PPS_IN(_PPS_RPF8),       // 4   RF08    EBIRDY2/RPF8/SCL3/RF8
    _PPS_IN(_PPS_RPF12),      // 5   RF12    TDO/EBIA17/AN31/RPF12/RF12
    _PPS_IN(_PPS_RPB15),      // 6   RB15    EBIA0/AN10/ERXD3/AETXD2/RPB15/OCFB/PMA0/RB15
    _PPS_IN(_PPS_RPC13),      // 7   RC13    SOSCI/RPC13/RC13
    _PPS_IN(_PPS_RPF3),       // 8   RF03    RPF3/USBID/RF3
    _PPS_IN(_PPS_RPF2),       // 9   RF02    EBIRDY3/RPF2/SDA3/RF2
    _PPS_IN(_PPS_RPB8),       // 10   RB08    EBIA10/AN48/RPB8/PMA10/RB8
    _PPS_IN(_PPS_RPB10),      // 11   RB10    EBIA13/CVREFOUT/AN5/RPB10/PMA13/RB10
    _PPS_IN(_PPS_RPB9),       // 12   RB09    EBIA7/AN49/RPB9/PMA7/RB9
    _PPS_IN(_PPS_RPB14),      // 13   RB14    EBIA1/AN9/ERXD2/AETXD3/RPB14/SCK3/PMA1/RB14
    NOT_PPS_PIN,              // 14   RG15    AN23/AERXERR/RG15
    NOT_PPS_PIN,              // 15   RB04    AN4/C1INB/RB4
    _PPS_IN(_PPS_RPB0),       // 16   RB00    PGED1/AN0/RPB0/RB0
    _PPS_IN(_PPS_RPB1),       // 17   RB01    PGEC1/AN1/RPB1/RB1
    _PPS_IN(_PPS_RPB2),       // 18   RB02    AN2/C2INB/RPB2/RB2
    _PPS_IN(_PPS_RPB3),       // 19   RB03    AN3/C2INA/RPB3/RB3
    _PPS_IN(_PPS_RPF5),       // 20   RF05    EBIA8/RPF5/SCL5/PMA8/RF5
    _PPS_IN(_PPS_RPF4),       // 21   RF04    EBIA9/RPF4/SDA5/PMA9/RF4
    NOT_PPS_PIN,              // 22   RA06    TRCLK/SQICLK/RA6
    NOT_PPS_PIN,              // 23   RA07    TRD3/SQID3/RA7
    NOT_PPS_PIN,              // 24   RE00    EBID0/PMD0/RE0
    NOT_PPS_PIN,              // 25   RE01    EBID1/PMD1/RE1
    NOT_PPS_PIN,              // 26   RB11    AN6/ERXERR/AETXERR/RB11
    NOT_PPS_PIN,              // 27   RE02    EBID2/PMD2/RE2
    NOT_PPS_PIN,              // 28   RA00    TMS/EBIA16/AN24/RA0
    _PPS_IN(_PPS_RPG6),       // 29   RG06    AN14/C1IND/ECOL/RPG6/SCK2/RG6
    _PPS_IN(_PPS_RPC4),       // 30   RC04    EBIOE/AN19/RPC4/PMRD/RC4
    _PPS_IN(_PPS_RPB5),       // 31   RB05    AN45/C1INA/RPB5/RB5
    _PPS_IN(_PPS_RPC14),      // 32   RC14    SOSCO/RPC14/T1CK/RC14
    _PPS_IN(_PPS_RPD9),       // 33   RD09    EBIA15/RPD9/PMCS2/PMA15/RD9
    _PPS_IN(_PPS_RPG9),       // 34   RG09    EBIA2/AN11/C2INC/ERXCLK/EREFCLK/AERXCLK/AEREFCLK/RPG9/PMA2/RG9
    _PPS_IN(_PPS_RPE3),       // 35   RE03    EBID3/RPE3/PMD3/RE3
    NOT_PPS_PIN,              // 36   RA02    EBICS0/SCL2/RA2
    NOT_PPS_PIN,              // 37   RA03    EBIRDY1/SDA2/RA3
    NOT_PPS_PIN,              // 38   RE07    EBID7/AN15/PMD7/RE7
    NOT_PPS_PIN,              // 39   RG13    TRD0/SQID0/RG13
    NOT_PPS_PIN,              // 40   RE04    EBID4/AN18/PMD4/RE4
    _PPS_IN(_PPS_RPG6),       // 41   RG06    AN14/C1IND/ECOL/RPG6/SCK2/RG6
    _PPS_IN(_PPS_RPC4),       // 42   RC04    EBIOE/AN19/RPC4/PMRD/RC4
    _PPS_IN(_PPS_RPB5),       // 43   RB05    AN45/C1INA/RPB5/RB5
    _PPS_IN(_PPS_RPG0),       // 44   RG00    EBID8/RPG0/PMD8/RG0
    _PPS_IN(_PPS_RPG1),       // 45   RG01    EBID9/ETXERR/RPG1/PMD9/RG1
    _PPS_IN(_PPS_RPF0),       // 46   RF00    EBID11/ETXD1/RPF0/PMD11/RF0
    _PPS_IN(_PPS_RPF1),       // 47   RF01    EBID10/ETXD0/RPF1/PMD10/RF1
    NOT_PPS_PIN,              // 48   RA02    EBICS0/SCL2/RA2
    NOT_PPS_PIN,              // 49   RA03    EBIRDY1/SDA2/RA3
    NOT_PPS_PIN,              // 50   RA05    EBIA5/AN34/PMA5/RA5
    NOT_PPS_PIN,              // 51   RG14    TRD2/SQID2/RG14
    _PPS_IN(_PPS_RPD12),      // 52   RD12    EBID12/ETXD2/RPD12/PMD12/RD12
    _PPS_IN(_PPS_RPD1),       // 53   RD01    RPD1/SCK1/RD1
    _PPS_IN(_PPS_RPD2),       // 54   RD02    EBID14/ETXEN/RPD2/PMD14/RD2
    _PPS_IN(_PPS_RPD3),       // 55   RD03    EBID15/ETXCLK/RPD3/PMD15/RD3
    _PPS_IN(_PPS_RPG7),       // 56   RG07    EBIA4/AN13/C1INC/ECRS/RPG7/SDA4/PMA4/RG7
    _PPS_IN(_PPS_RPD5),       // 57   RD05    SQICS1/RPD5/RD5
    _PPS_IN(_PPS_RPC1),       // 58   RC01    EBIA6/AN22/RPC1/PMA6/RC1
    _PPS_IN(_PPS_RPE5),       // 59   RE05    EBID5/AN17/RPE5/PMD5/RE5
    _PPS_IN(_PPS_RPA14),      // 60   RA14    AETXCLK/RPA14/SCL1/RA14
    _PPS_IN(_PPS_RPA15),      // 61   RA15    AETXEN/RPA15/SDA1/RA15
    NOT_PPS_PIN,              // 62   RE06    EBID6/AN16/PMD6/RE6
    NOT_PPS_PIN,              // 63   RG12    TRD1/SQID1/RG12
    NOT_PPS_PIN,              // 64   RD13    EBID13/ETXD3/PMD13/RD13
    _PPS_IN(_PPS_RPD1),       // 65   RD01    RPD1/SCK1/RD1
    _PPS_IN(_PPS_RPD2),       // 66   RD02    EBID14/ETXEN/RPD2/PMD14/RD2
    _PPS_IN(_PPS_RPD3),       // 67   RD03    EBID15/ETXCLK/RPD3/PMD15/RD3
    _PPS_IN(_PPS_RPG8),       // 68   RG08    EBIA3/AN12/C2IND/ERXDV/ECRSDV/AERXDV/AECRSDV/RPG8/SCL4/PMA3/RG8
    _PPS_IN(_PPS_RPD4),       // 69   RD04    SQICS0/RPD4/RD4
    _PPS_IN(_PPS_RPC3),       // 70   RC03    EBIWE/AN20/RPC3/PMWR/RC3
    _PPS_IN(_PPS_RPC2),       // 71   RC02    EBIA12/AN21/RPC2/PMA12/RC2
    _PPS_IN(_PPS_RPA14),      // 72   RA14    AETXCLK/RPA14/SCL1/RA14
    _PPS_IN(_PPS_RPA15),      // 73   RA15    AETXEN/RPA15/SDA1/RA15
    _PPS_IN(_PPS_RPD10),      // 74   RD10    RPD10/SCK4/RD10
    _PPS_IN(_PPS_RPD11),      // 75   RD11    EMDC/AEMDC/RPD11/RD11
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
    PIN_OC3,            
    PIN_OC4,            
    PIN_OC5,            
    PIN_OC6,            
    PIN_OC7,
    PIN_OC8,
    PIN_OC9
};

/* ------------------------------------------------------------ */
/* This table maps from an external interrupt number to the digital
** pin for that interrupt.
*/

const uint8_t external_int_to_digital_pin_PGM[] = {
    NOT_PPS_PIN,        
    PIN_INT1,            
    PIN_INT2,            
    PIN_INT3,            
    PIN_INT4            
};



/* ------------------------------------------------------------ */
/*                Board Customization Functions                    */
/* ------------------------------------------------------------ */
/*                                                                */
/* The following can be used to customize the behavior of some    */
/* of the core API functions. These provide hooks that can be    */
/* used to extend or replace the default behavior of the core    */
/* functions. To use one of these functions, add the desired    */
/* code to the function skeleton below and then set the value    */
/* of the appropriate compile switch above to 1. This will        */
/* cause the hook function to be compiled into the build and    */
/* to cause the code to call the hook function to be compiled    */
/* into the appropriate core function.                            */
/*                                                                */
/* ------------------------------------------------------------ */
/***    _board_init
**
**    Parameters:
**        none
**
**    Return Value:
**        none
**
**    Errors:
**        none
**
**    Description:
**        This function is called from the core init() function.
**        This can be used to perform any board specific init
**        that needs to be done when the processor comes out of
**        reset and before the user sketch is run.
*/
#if    (OPT_BOARD_INIT != 0)

void _board_init(void) {
    
}

#endif

/* ------------------------------------------------------------ */
/***    _board_pinMode
**
**    Parameters:
**        pin        - digital pin number to configure
**        mode    - mode to which the pin should be configured
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the pinMode
**        function. It can perform any special processing needed
**        when setting the pin mode. If this function returns zero,
**        control will pass through the normal pinMode code. If
**        it returns a non-zero value the normal pinMode code isn't
**        executed.
*/
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_pinMode(uint8_t pin, uint8_t mode) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_getPinMode
**
**    Parameters:
**        pin        - digital pin number
**        mode    - pointer to variable to receive mode value
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the getPinMode
**        function. It can perform any special processing needed
**        when getting the pin mode. If this function returns zero,
**        control will pass through the normal getPinMode code. If
**        it returns a non-zero value the normal getPinMode code isn't
**        executed.
*/
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_getPinMode(uint8_t pin, uint8_t * mode) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_digitalWrite
**
**    Parameters:
**        pin        - digital pin number
**        val        - value to write to the pin
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the digitalWrite
**        function. It can perform any special processing needed
**        in writing to the pin. If this function returns zero,
**        control will pass through the normal digitalWrite code. If
**        it returns a non-zero value the normal digitalWrite code isn't
**        executed.
*/
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_digitalWrite(uint8_t pin, uint8_t val) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_digitalRead
**
**    Parameters:
**        pin        - digital pin number
**        val        - pointer to variable to receive pin value
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the digitalRead
**        function. It can perform any special processing needed
**        in reading from the pin. If this function returns zero,
**        control will pass through the normal digitalRead code. If
**        it returns a non-zero value the normal digitalRead code isn't
**        executed.
*/
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_digitalRead(uint8_t pin, uint8_t * val) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_analogRead
**
**    Parameters:
**        pin        - analog channel number
**        val        - pointer to variable to receive analog value
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the analogRead
**        function. It can perform any special processing needed
**        in reading from the pin. If this function returns zero,
**        control will pass through the normal analogRead code. If
**        it returns a non-zero value the normal analogRead code isn't
**        executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int    _board_analogRead(uint8_t pin, int * val) {

    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_analogReference
**
**    Parameters:
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the analogReference
**        function. It can perform any special processing needed
**        to set the reference voltage. If this function returns zero,
**        control will pass through the normal analogReference code. If
**        it returns a non-zero value the normal analogReference code isn't
**        executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int    _board_analogReference(uint8_t mode) {

    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_analogWrite
**
**    Parameters:
**        pin        - pin number
**        val        - analog value to write
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the analogWrite
**        function. It can perform any special processing needed
**        in writing to the pin. If this function returns zero,
**        control will pass through the normal analogWrite code. If
**        it returns a non-zero value the normal analogWrite code isn't
**        executed.
*/
#if (OPT_BOARD_ANALOG_WRITE != 0)

int    _board_analogWrite(uint8_t pin, int val) {

    return 0;

}

#endif

#endif // OPT_BOARD_DATA

/* ------------------------------------------------------------ */

#endif    // BOARD_DATA_C

/************************************************************************/
