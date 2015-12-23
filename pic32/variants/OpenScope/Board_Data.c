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
                    //  chipKIT PIC32   PIC32 Pin Name                      chipKIT Func        OpenScope Func         
                    //  Pin#    Reg                
    _IOPORT_PC,     //  0       RC14    SOSCO/RPC14/T1CK/RC14               RX Serial Monitor   RX Serial Monitor         
    _IOPORT_PD,     //  1       RD11    EMDC/RPD11/RD11                     TX Serial Moinitor  TX Serial Moinitor     
    _IOPORT_PD,     //  2       RD0     RPD0/RTCC/INT0/RD0                  INT0,IC1,T4CK       INT0,Tin     
    _IOPORT_PF,     //  3       RF2     RPF2/SDA3/RF2                       PWM1(OC1),INT1,T9CK Pro CLK/INT1,T9CK      
    _IOPORT_PA,     //  4       RA5     EBIA5/AN34/PMA5/RA5                 GPIO                Tout        
    _IOPORT_PF,     //  5       RF4     EBIA9/RPF4/SDA5/PMA9/RF4            PWM2(OC3),RX1,SDA5  Pro SDA5,RX1,PWM1(OC3)    
    _IOPORT_PG,     //  6       RG6     AN14/C1IND/RPG6/SCK2/RG6            PWM3(OC5),SCK2      Pro SCK2,CTS1       
    _IOPORT_PD,     //  7       RD4     SQICS0/RPD4/RD4                     INT2,IC2,T8CK       Digital CLK/INT2,TCK8      
    _IOPORT_PF,     //  8       RF0     EBID11/RPF0/PMD11/RF0               INT4,SDI2,SDO2,IC4  pro SDI2,SDO2     
    _IOPORT_PD,     //  9       RD2     EBID14/RPD2/PMD14/RD2               PWM4(OC6),T2CK      DC+,OC6     
    _IOPORT_PF,     //  10      RF3     RPF3/USBID/RF3                      PWM5(OC2),SS2,IC6   Pro SS2,RTS1,PWM2(OC2)   
    _IOPORT_PC,     //  11      RC13    SOSCI/RPC13/RC13                    PWM6(OC4),T5CK      DC-,OC4     
    _IOPORT_PF,     //  12      RF5     EBIA8/RPF5/SCL5/PMA8/RF5            SDI2,SDO2,TX1,SCL5  Pro SDI2,SDO2,SCL5,TX1     
    _IOPORT_PJ,     //  13      RJ4     RJ4                                 User LED 1          User LED 1     
    _IOPORT_PB,     //  14      RB0     PGED1/AN0/RPB0/RB0                  A0                  ADC1
    _IOPORT_PB,     //  15      RB2     AN2/C2INB/RPB2/RB2                  A1                  ADC2
    _IOPORT_PA,     //  16      RA0     TMS/EBIA16/AN24/RA0                 A2                  ADC1 Offset feedback  
    _IOPORT_PA,     //  17      RA1     TCK/EBIA19/AN29/RA1                 A3                  ADC2 Offset feedback
    _IOPORT_PB,     //  18      RB11    AN6/RB11                            A4                  DC+ feedback
    _IOPORT_PB,     //  19      RB12    EBIA11/AN7/PMA11/RB12               A5                  DC- feedback  
    _IOPORT_PB,     //  20      RB13    AN8/RB13                            A6                  AWG feedback 
    _IOPORT_PJ,     //  21      RJ11    AN37/ERXCLK/EREFCLK/RJ11            A7                  USB5V0 feedback    
    _IOPORT_PG,     //  22      RG15    AN23/RG15                           A8                  VCC3V3 feedback  
    _IOPORT_PJ,     //  23      RJ8     AN35/ETXD0/RJ8                      A9                  VREF3V0 feedback 
    _IOPORT_PJ,     //  24      RJ9     AN36/ETXD1/RJ9                      A10                 VREF1V5 feedback 
    _IOPORT_PC,     //  25      RC4     EBIOE/AN19/RPC4/PMRD/RC4            A11                 VSS5V0- feedback
    _IOPORT_PE,     //  26      RE0     EBID0/PMD0/RE0                      GPIO                Digital IO 0
    _IOPORT_PE,     //  27      RE1     EBID1/PMD1/RE1                      GPIO                Digital IO 1
    _IOPORT_PE,     //  28      RE2     EBID2/SQID2/PMD2/RE2                GPIO                Digital IO 2
    _IOPORT_PE,     //  29      RE3     EBID3/RPE3/PMD3/RE3                 GPIO                Digital IO 3
    _IOPORT_PE,     //  30      RE4     EBID4/AN18/PMD4/RE4                 GPIO                Digital IO 4
    _IOPORT_PE,     //  31      RE5     EBID5/AN17/RPE5/PMD5/RE5            GPIO                Digital IO 5 
    _IOPORT_PE,     //  32      RE6     EBID6/AN16/PMD6/RE6                 GPIO                Digital IO 6
    _IOPORT_PE,     //  33      RE7     EBID7/AN15/PMD7/RE7                 GPIO                Digital IO 7  
    _IOPORT_PE,     //  34      RE8     AN25/RPE8/RE8                       GPIO                Digital IO 8
    _IOPORT_PE,     //  35      RE9     AN26/RPE9/RE9                       GPIO                Digital IO 9  
    _IOPORT_PD,     //  36      RD1     RPD1/SCK1/RD1                       PGA SCK1            PGA SCK1
    _IOPORT_PA,     //  37      RA6     TRCLK/SQICLK/RA6                    PGA CS1             PGA CS1
    _IOPORT_PA,     //  38      RA7     TRD3/SQID3/RA7                      PGA CS2             PGA CS2
    _IOPORT_PD,     //  39      RD3     EBID15/RPD3/PMD15/RD3               PGA SDO1            PGA SDO1
    _IOPORT_PA,     //  40      RA2     EBICS0/SCL2/RA2                     ADC1 EN             ADC1 EN
    _IOPORT_PA,     //  41      RA3     EBIRDY1/SDA2/RA3                    ADC2 EN             ADC2 EN
    _IOPORT_PG,     //  42      RG12    TRD1/SQID1/RG12                     DCOUT EN            DCOUT EN
    _IOPORT_PG,     //  43      RG0     EBID8/RPG0/PMD8/RG0                 AWG OFFSET          AWG OFFSET                        
    _IOPORT_PD,     //  44      RD9     EBIA15/RPD9/PMCS2/PMA15/RD9         ADC1 OFFSET         ADC1 OFFSET
    _IOPORT_PC,     //  45      RC2     EBIA12/AN21/RPC2/PMA12/RC2          ADC2 OFFSET         ADC2 OFFSET   
    _IOPORT_PA,     //  46      RA9     VREF-/CVREF-/AN27/RA9               VREF-               VREF-
    _IOPORT_PA,     //  47      RA10    VREF+/CVREF+/AN28/RA10              VREF+               VREF+           
    _IOPORT_PJ,     //  48      RJ2     EBIRDY3/RJ2                         LED2                LED2
    _IOPORT_PJ,     //  49      RJ1     EMDIO/RJ1                           LED3                LED3
    _IOPORT_PJ,     //  50      RJ0     ETXERR/RJ0                          LED4                LED4
    _IOPORT_PD,     //  51      RD15    AN33/RPD15/SCK6/RD15                uSD SCK6            uSD SCK6  
    _IOPORT_PD,     //  52      RD14    AN32/AETXD0/RPD14/RD14              uSD SS6             uSD SS6 
    _IOPORT_PD,     //  53      RD5     SQICS1/RPD5/RD5                     uSD SDI6            uSD SDI6
    _IOPORT_PD,     //  54      RD12    EBID12/RPD12/PMD12/RD12             uSD SDO6            uSD SDO6
    _IOPORT_PD,     //  55      RD10    RPD10/SCK4/RD10                     MRF24 SCK4          MRF24 SCK4
    _IOPORT_PB,     //  56      RB15    EBIA0/AN10/RPB15/OCFB/PMA0/RB15     MRF24 SS4           MRF24 SS4            
    _IOPORT_PG,     //  57      RG7     EBIA4/AN13/C1INC/RPG7/SDA4/PMA4/RG7 MRF24 SDI4          MRF24 SDI4
    _IOPORT_PA,     //  58      RA15    RPA15/SDA1/RA15                     MRF24 SDO4          MRF24 SDO4
    _IOPORT_PG,     //  59      RG8     EBIA3/AN12/C2IND/RPG8/SCL4/PMA3/RG8 MRF24 INT3          MRF24 INT3      
    _IOPORT_PD,     //  60      RD13    EBID13/PMD13/RD13                   MRF24 HIB           MRF24 HIB
    _IOPORT_PA,     //  61      RA4     EBIA14/PMCS1/PMA14/RA4              MRF24 RESET         MRF24 RESET
    _IOPORT_PA,     //  62      RA14    RPA14/SCL1/RA14                     MRF24 WP            MRF24 WP
    _IOPORT_PG,     //  63      RG13    TRD0/SQID0/RG13                     SDA5 PULLUP         SDA5 PULLUP
    _IOPORT_PG,     //  64      RG14    RD2/SQID2/RG14                      SCL5 PULLUP         SCL5 PULLUP
    _IOPORT_PH,     //  65      RH0     AN38/ETXD2/RH0                      DAC 0               DAC 0    
    _IOPORT_PH,     //  66      RH1     AN39/ETXD3/RH1                      DAC 1               DAC 1
    _IOPORT_PH,     //  67      RH4     AN40/ERXERR/RH4                     DAC 2               DAC 2  
    _IOPORT_PH,     //  68      RH5     AN41/ERXD1/RH5                      DAC 3               DAC 3  
    _IOPORT_PH,     //  69      RH6     AN42/ERXD2/RH6                      DAC 4               DAC 4   
    _IOPORT_PH,     //  70      RH8     ERXD0/RH8                           DAC 5               DAC 5
    _IOPORT_PH,     //  71      RH9     ERXD3/RH9                           DAC 6               DAC 6    
    _IOPORT_PH,     //  72      RH10    ECOL/RH10                           DAC 7               DAC 7  
    _IOPORT_PH,     //  73      RH12    ECRS/RH12                           DAC 8               DAC 8
    _IOPORT_PH,     //  74      RH13    ERXDV/ECRSDV/RH13                   DAC 9               DAC 9
    _IOPORT_PB,     //  75      RB14    EBIA1/AN9/RPB14/SCK3/PMA1/RB14      SPI DAC SCK3        SPI DAC SCK3
    _IOPORT_PB,     //  76      RB8     EBIA10/AN48/RPB8/PMA10/RB8          SPI DAC SS3         SPI DAC SS3
    _IOPORT_PB,     //  77      RB5     AN45/C1INA/RPB5/RB5                 SPI DAC SDI3        SPI DAC SDI3
    _IOPORT_PB,     //  78      RB9     EBIA7/AN49/RPB9/PMA7/RB9            SPI DAC SDO3        SPI DAC SDO3
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to a bit mask
** for the corresponding bit within the port.
*/
const uint16_t digital_pin_to_bit_mask_PGM[] = 
{
                //  chipKIT PIC32   PIC32 Pin Name                      chipKIT Func        OpenScope Func         
                //  Pin#    Reg                
    _BV( 14 ),  //  0       RC14    SOSCO/RPC14/T1CK/RC14               RX Serial Monitor   RX Serial Monitor         
    _BV( 11 ),  //  1       RD11    EMDC/RPD11/RD11                     TX Serial Moinitor  TX Serial Moinitor     
    _BV( 0 ),   //  2       RD0     RPD0/RTCC/INT0/RD0                  INT0,IC1,T4CK       INT0,Tin     
    _BV( 2 ),   //  3       RF2     RPF2/SDA3/RF2                       PWM1(OC1),INT1,T9CK Pro CLK/INT1,T9CK      
    _BV( 5 ),   //  4       RA5     EBIA5/AN34/PMA5/RA5                 GPIO                Tout        
    _BV( 4 ),   //  5       RF4     EBIA9/RPF4/SDA5/PMA9/RF4            PWM2(OC3),RX1,SDA5  Pro SDA5,RX1,PWM1(OC3)    
    _BV( 6 ),   //  6       RG6     AN14/C1IND/RPG6/SCK2/RG6            PWM3(OC5),SCK2      Pro SCK2,CTS1       
    _BV( 4 ),   //  7       RD4     SQICS0/RPD4/RD4                     INT2,IC2,T8CK       Digital CLK/INT2,TCK8      
    _BV( 0 ),   //  8       RF0     EBID11/RPF0/PMD11/RF0               INT4,SDI2,SDO2,IC4  pro SDI2,SDO2     
    _BV( 2 ),   //  9       RD2     EBID14/RPD2/PMD14/RD2               PWM4(OC6),T2CK      DC+,OC6     
    _BV( 3 ),   //  10      RF3     RPF3/USBID/RF3                      PWM5(OC2),SS2,IC6   Pro SS2,RTS1,PWM2(OC2)   
    _BV( 13 ),  //  11      RC13    SOSCI/RPC13/RC13                    PWM6(OC4),T5CK      DC-,OC4     
    _BV( 5 ),   //  12      RF5     EBIA8/RPF5/SCL5/PMA8/RF5            SDI2,SDO2,TX1,SCL5  Pro SDI2,SDO2,SCL5,TX1     
    _BV( 4 ),   //  13      RJ4     RJ4                                 User LED 1          User LED 1     
    _BV( 0 ),   //  14      RB0     PGED1/AN0/RPB0/RB0                  A0                  ADC1     
    _BV( 2 ),   //  15      RB2     AN2/C2INB/RPB2/RB2                  A1                  ADC2     
    _BV( 0 ),   //  16      RA0     TMS/EBIA16/AN24/RA0                 A2                  ADC1 Offset feedback       
    _BV( 1 ),   //  17      RA1     TCK/EBIA19/AN29/RA1                 A3                  ADC2 Offset feedback     
    _BV( 11 ),  //  18      RB11    AN6/RB11                            A4                  DC+ feedback     
    _BV( 12 ),  //  19      RB12    EBIA11/AN7/PMA11/RB12               A5                  DC- feedback       
    _BV( 13 ),  //  20      RB13    AN8/RB13                            A6                  AWG feedback      
    _BV( 11 ),  //  21      RJ11    AN37/ERXCLK/EREFCLK/RJ11            A7                  USB5V0 feedback         
    _BV( 15 ),  //  22      RG15    AN23/RG15                           A8                  VCC3V3 feedback       
    _BV( 8 ),   //  23      RJ8     AN35/ETXD0/RJ8                      A9                  VREF3V0 feedback      
    _BV( 9 ),   //  24      RJ9     AN36/ETXD1/RJ9                      A10                 VREF1V5 feedback      
    _BV( 4 ),   //  25      RC4     EBIOE/AN19/RPC4/PMRD/RC4            A11                 VSS5V0- feedback     
    _BV( 0 ),   //  26      RE0     EBID0/PMD0/RE0                      GPIO                Digital IO 0     
    _BV( 1 ),   //  27      RE1     EBID1/PMD1/RE1                      GPIO                Digital IO 1     
    _BV( 2 ),   //  28      RE2     EBID2/SQID2/PMD2/RE2                GPIO                Digital IO 2     
    _BV( 3 ),   //  29      RE3     EBID3/RPE3/PMD3/RE3                 GPIO                Digital IO 3     
    _BV( 4 ),   //  30      RE4     EBID4/AN18/PMD4/RE4                 GPIO                Digital IO 4     
    _BV( 5 ),   //  31      RE5     EBID5/AN17/RPE5/PMD5/RE5            GPIO                Digital IO 5      
    _BV( 6 ),   //  32      RE6     EBID6/AN16/PMD6/RE6                 GPIO                Digital IO 6     
    _BV( 7 ),   //  33      RE7     EBID7/AN15/PMD7/RE7                 GPIO                Digital IO 7       
    _BV( 8 ),   //  34      RE8     AN25/RPE8/RE8                       GPIO                Digital IO 8     
    _BV( 9 ),   //  35      RE9     AN26/RPE9/RE9                       GPIO                Digital IO 9       
    _BV( 1 ),   //  36      RD1     RPD1/SCK1/RD1                       PGA SCK1            PGA SCK1     
    _BV( 6 ),   //  37      RA6     TRCLK/SQICLK/RA6                    PGA CS1             PGA CS1     
    _BV( 7 ),   //  38      RA7     TRD3/SQID3/RA7                      PGA CS2             PGA CS2     
    _BV( 3 ),   //  39      RD3     EBID15/RPD3/PMD15/RD3               PGA SDO1            PGA SDO1     
    _BV( 2 ),   //  40      RA2     EBICS0/SCL2/RA2                     ADC1 EN             ADC1 EN     
    _BV( 3 ),   //  41      RA3     EBIRDY1/SDA2/RA3                    ADC2 EN             ADC2 EN     
    _BV( 12 ),  //  42      RG12    TRD1/SQID1/RG12                     DCOUT EN            DCOUT EN     
    _BV( 0 ),   //  43      RG0     EBID8/RPG0/PMD8/RG0                 AWG OFFSET          AWG OFFSET              
    _BV( 9 ),   //  44      RD9     EBIA15/RPD9/PMCS2/PMA15/RD9         ADC1 OFFSET         ADC1 OFFSET     
    _BV( 2 ),   //  45      RC2     EBIA12/AN21/RPC2/PMA12/RC2          ADC2 OFFSET         ADC2 OFFSET        
    _BV( 9 ),   //  46      RA9     VREF-/CVREF-/AN27/RA9               VREF-               VREF-     
    _BV( 10 ),  //  47      RA10    VREF+/CVREF+/AN28/RA10              VREF+               VREF+                
    _BV( 2 ),   //  48      RJ2     EBIRDY3/RJ2                         LED2                LED2     
    _BV( 1 ),   //  49      RJ1     EMDIO/RJ1                           LED3                LED3     
    _BV( 0 ),   //  50      RJ0     ETXERR/RJ0                          LED4                LED4     
    _BV( 15 ),  //  51      RD15    AN33/RPD15/SCK6/RD15                uSD SCK6            uSD SCK6       
    _BV( 14 ),  //  52      RD14    AN32/AETXD0/RPD14/RD14              uSD SS6             uSD SS6      
    _BV( 5 ),   //  53      RD5     SQICS1/RPD5/RD5                     uSD SDI6            uSD SDI6     
    _BV( 12 ),  //  54      RD12    EBID12/RPD12/PMD12/RD12             uSD SDO6            uSD SDO6     
    _BV( 10 ),  //  55      RD10    RPD10/SCK4/RD10                     MRF24 SCK4          MRF24 SCK4     
    _BV( 15 ),  //  56      RB15    EBIA0/AN10/RPB15/OCFB/PMA0/RB15     MRF24 SS4           MRF24 SS4               
    _BV( 7 ),   //  57      RG7     EBIA4/AN13/C1INC/RPG7/SDA4/PMA4/RG7 MRF24 SDI4          MRF24 SDI4     
    _BV( 15 ),  //  58      RA15    RPA15/SDA1/RA15                     MRF24 SDO4          MRF24 SDO4     
    _BV( 8 ),   //  59      RG8     EBIA3/AN12/C2IND/RPG8/SCL4/PMA3/RG8 MRF24 INT3          MRF24 INT3           
    _BV( 13 ),  //  60      RD13    EBID13/PMD13/RD13                   MRF24 HIB           MRF24 HIB     
    _BV( 4 ),   //  61      RA4     EBIA14/PMCS1/PMA14/RA4              MRF24 RESET         MRF24 RESET     
    _BV( 14 ),  //  62      RA14    RPA14/SCL1/RA14                     MRF24 WP            MRF24 WP     
    _BV( 13 ),  //  63      RG13    TRD0/SQID0/RG13                     SDA5 PULLUP         SDA5 PULLUP     
    _BV( 14 ),  //  64      RG14    RD2/SQID2/RG14                      SCL5 PULLUP         SCL5 PULLUP     
    _BV( 0 ),   //  65      RH0     AN38/ETXD2/RH0                      DAC 0               DAC 0         
    _BV( 1 ),   //  66      RH1     AN39/ETXD3/RH1                      DAC 1               DAC 1     
    _BV( 4 ),   //  67      RH4     AN40/ERXERR/RH4                     DAC 2               DAC 2       
    _BV( 5 ),   //  68      RH5     AN41/ERXD1/RH5                      DAC 3               DAC 3       
    _BV( 6 ),   //  69      RH6     AN42/ERXD2/RH6                      DAC 4               DAC 4        
    _BV( 8 ),   //  70      RH8     ERXD0/RH8                           DAC 5               DAC 5     
    _BV( 9 ),   //  71      RH9     ERXD3/RH9                           DAC 6               DAC 6         
    _BV( 10 ),  //  72      RH10    ECOL/RH10                           DAC 7               DAC 7       
    _BV( 12 ),  //  73      RH12    ECRS/RH12                           DAC 8               DAC 8     
    _BV( 13 ),  //  74      RH13    ERXDV/ECRSDV/RH13                   DAC 9               DAC 9     
    _BV( 14 ),  //  75      RB14    EBIA1/AN9/RPB14/SCK3/PMA1/RB14      SPI DAC SCK3        SPI DAC SCK3     
    _BV( 8 ),   //  76      RB8     EBIA10/AN48/RPB8/PMA10/RB8          SPI DAC SS3         SPI DAC SS3     
    _BV( 5 ),   //  77      RB5     AN45/C1INA/RPB5/RB5                 SPI DAC SDI3        SPI DAC SDI3     
    _BV( 9 ),   //  78      RB9     EBIA7/AN49/RPB9/PMA7/RB9            SPI DAC SDO3        SPI DAC SDO3     
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to the output
** compare number, input capture number, and timer external clock
** input associated with that pin.
*/
const uint16_t digital_pin_to_timer_PGM[] =
{
    _TIMER_TCK1,                //  0       RC14    SOSCO/RPC14/T1CK/RC14               RX Serial Monitor   RX Serial Monitor         
    NOT_ON_TIMER,               //  1       RD11    EMDC/RPD11/RD11                     TX Serial Moinitor  TX Serial Moinitor     
    _TIMER_IC1 | _TIMER_TCK4,   //  2       RD0     RPD0/RTCC/INT0/RD0                  INT0,IC1,T4CK       INT0,Tin     
    _TIMER_OC1 | _TIMER_TCK9,   //  3       RF2     RPF2/SDA3/RF2                       PWM1(OC1),INT1,T9CK Pro CLK/INT1,T9CK      
    NOT_ON_TIMER,               //  4       RA5     EBIA5/AN34/PMA5/RA5                 GPIO                Tout        
    _TIMER_OC3,                 //  5       RF4     EBIA9/RPF4/SDA5/PMA9/RF4            PWM2(OC3),RX1,SDA5  Pro SDA5,RX1,PWM1(OC3)    
    _TIMER_OC5,                 //  6       RG6     AN14/C1IND/RPG6/SCK2/RG6            PWM3(OC5),SCK2      Pro SCK2,CTS1       
    _TIMER_IC2 | _TIMER_TCK8,   //  7       RD4     SQICS0/RPD4/RD4                     INT2,IC2,T8CK       Digital CLK/INT2,TCK8      
    _TIMER_IC4,                 //  8       RF0     EBID11/RPF0/PMD11/RF0               INT4,SDI2,SDO2,IC4  pro SDI2,SDO2     
    _TIMER_OC6 | _TIMER_TCK2,   //  9       RD2     EBID14/RPD2/PMD14/RD2               PWM4(OC6),T2CK      DC+,OC6     
    _TIMER_OC2 | _TIMER_IC6,    //  10      RF3     RPF3/USBID/RF3                      PWM5(OC2),SS2,IC6   Pro SS2,RTS1,PWM2(OC2)   
    _TIMER_OC4 | _TIMER_TCK5,   //  11      RC13    SOSCI/RPC13/RC13                    PWM6(OC4),T5CK      DC-,OC4     
    NOT_ON_TIMER,               //  12      RF5     EBIA8/RPF5/SCL5/PMA8/RF5            SDI2,SDO2,TX1,SCL5  Pro SDI2,SDO2,SCL5,TX1     
    NOT_ON_TIMER,               //  13      RJ4     RJ4                                 User LED 1          User LED 1     
    NOT_ON_TIMER,               //  14      RB0     PGED1/AN0/RPB0/RB0                  A0                  ADC1     
    NOT_ON_TIMER,               //  15      RB2     AN2/C2INB/RPB2/RB2                  A1                  ADC2     
    NOT_ON_TIMER,               //  16      RA0     TMS/EBIA16/AN24/RA0                 A2                  ADC1 Offset feedback       
    NOT_ON_TIMER,               //  17      RA1     TCK/EBIA19/AN29/RA1                 A3                  ADC2 Offset feedback     
    NOT_ON_TIMER,               //  18      RB11    AN6/RB11                            A4                  DC+ feedback     
    NOT_ON_TIMER,               //  19      RB12    EBIA11/AN7/PMA11/RB12               A5                  DC- feedback       
    NOT_ON_TIMER,               //  20      RB13    AN8/RB13                            A6                  AWG feedback      
    NOT_ON_TIMER,               //  21      RJ11    AN37/ERXCLK/EREFCLK/RJ11            A7                  USB5V0 feedback         
    NOT_ON_TIMER,               //  22      RG15    AN23/RG15                           A8                  VCC3V3 feedback       
    NOT_ON_TIMER,               //  23      RJ8     AN35/ETXD0/RJ8                      A9                  VREF3V0 feedback      
    NOT_ON_TIMER,               //  24      RJ9     AN36/ETXD1/RJ9                      A10                 VREF1V5 feedback      
    NOT_ON_TIMER,               //  25      RC4     EBIOE/AN19/RPC4/PMRD/RC4            A11                 VSS5V0- feedback     
    NOT_ON_TIMER,               //  26      RE0     EBID0/PMD0/RE0                      GPIO                Digital IO 0     
    NOT_ON_TIMER,               //  27      RE1     EBID1/PMD1/RE1                      GPIO                Digital IO 1     
    NOT_ON_TIMER,               //  28      RE2     EBID2/SQID2/PMD2/RE2                GPIO                Digital IO 2     
    NOT_ON_TIMER,               //  29      RE3     EBID3/RPE3/PMD3/RE3                 GPIO                Digital IO 3     
    NOT_ON_TIMER,               //  30      RE4     EBID4/AN18/PMD4/RE4                 GPIO                Digital IO 4     
    NOT_ON_TIMER,               //  31      RE5     EBID5/AN17/RPE5/PMD5/RE5            GPIO                Digital IO 5      
    NOT_ON_TIMER,               //  32      RE6     EBID6/AN16/PMD6/RE6                 GPIO                Digital IO 6     
    NOT_ON_TIMER,               //  33      RE7     EBID7/AN15/PMD7/RE7                 GPIO                Digital IO 7       
    NOT_ON_TIMER,               //  34      RE8     AN25/RPE8/RE8                       GPIO                Digital IO 8     
    NOT_ON_TIMER,               //  35      RE9     AN26/RPE9/RE9                       GPIO                Digital IO 9       
    NOT_ON_TIMER,               //  36      RD1     RPD1/SCK1/RD1                       PGA SCK1            PGA SCK1     
    NOT_ON_TIMER,               //  37      RA6     TRCLK/SQICLK/RA6                    PGA CS1             PGA CS1     
    NOT_ON_TIMER,               //  38      RA7     TRD3/SQID3/RA7                      PGA CS2             PGA CS2     
    NOT_ON_TIMER,               //  39      RD3     EBID15/RPD3/PMD15/RD3               PGA SDO1            PGA SDO1     
    NOT_ON_TIMER,               //  40      RA2     EBICS0/SCL2/RA2                     ADC1 EN             ADC1 EN     
    NOT_ON_TIMER,               //  41      RA3     EBIRDY1/SDA2/RA3                    ADC2 EN             ADC2 EN     
    NOT_ON_TIMER,               //  42      RG12    TRD1/SQID1/RG12                     DCOUT EN            DCOUT EN     
    NOT_ON_TIMER,               //  43      RG0     EBID8/RPG0/PMD8/RG0                 AWG OFFSET          AWG OFFSET              
    NOT_ON_TIMER,               //  44      RD9     EBIA15/RPD9/PMCS2/PMA15/RD9         ADC1 OFFSET         ADC1 OFFSET     
    NOT_ON_TIMER,               //  45      RC2     EBIA12/AN21/RPC2/PMA12/RC2          ADC2 OFFSET         ADC2 OFFSET        
    NOT_ON_TIMER,               //  46      RA9     VREF-/CVREF-/AN27/RA9               VREF-               VREF-     
    NOT_ON_TIMER,               //  47      RA10    VREF+/CVREF+/AN28/RA10              VREF+               VREF+                
    NOT_ON_TIMER,               //  48      RJ2     EBIRDY3/RJ2                         LED2                LED2     
    NOT_ON_TIMER,               //  49      RJ1     EMDIO/RJ1                           LED3                LED3     
    NOT_ON_TIMER,               //  50      RJ0     ETXERR/RJ0                          LED4                LED4     
    NOT_ON_TIMER,               //  51      RD15    AN33/RPD15/SCK6/RD15                uSD SCK6            uSD SCK6       
    NOT_ON_TIMER,               //  52      RD14    AN32/AETXD0/RPD14/RD14              uSD SS6             uSD SS6      
    NOT_ON_TIMER,               //  53      RD5     SQICS1/RPD5/RD5                     uSD SDI6            uSD SDI6     
    NOT_ON_TIMER,               //  54      RD12    EBID12/RPD12/PMD12/RD12             uSD SDO6            uSD SDO6     
    NOT_ON_TIMER,               //  55      RD10    RPD10/SCK4/RD10                     MRF24 SCK4          MRF24 SCK4     
    NOT_ON_TIMER,               //  56      RB15    EBIA0/AN10/RPB15/OCFB/PMA0/RB15     MRF24 SS4           MRF24 SS4               
    NOT_ON_TIMER,               //  57      RG7     EBIA4/AN13/C1INC/RPG7/SDA4/PMA4/RG7 MRF24 SDI4          MRF24 SDI4     
    NOT_ON_TIMER,               //  58      RA15    RPA15/SDA1/RA15                     MRF24 SDO4          MRF24 SDO4     
    NOT_ON_TIMER,               //  59      RG8     EBIA3/AN12/C2IND/RPG8/SCL4/PMA3/RG8 MRF24 INT3          MRF24 INT3           
    NOT_ON_TIMER,               //  60      RD13    EBID13/PMD13/RD13                   MRF24 HIB           MRF24 HIB     
    NOT_ON_TIMER,               //  61      RA4     EBIA14/PMCS1/PMA14/RA4              MRF24 RESET         MRF24 RESET     
    NOT_ON_TIMER,               //  62      RA14    RPA14/SCL1/RA14                     MRF24 WP            MRF24 WP     
    NOT_ON_TIMER,               //  63      RG13    TRD0/SQID0/RG13                     SDA5 PULLUP         SDA5 PULLUP     
    NOT_ON_TIMER,               //  64      RG14    RD2/SQID2/RG14                      SCL5 PULLUP         SCL5 PULLUP     
    NOT_ON_TIMER,               //  65      RH0     AN38/ETXD2/RH0                      DAC 0               DAC 0         
    NOT_ON_TIMER,               //  66      RH1     AN39/ETXD3/RH1                      DAC 1               DAC 1     
    NOT_ON_TIMER,               //  67      RH4     AN40/ERXERR/RH4                     DAC 2               DAC 2       
    NOT_ON_TIMER,               //  68      RH5     AN41/ERXD1/RH5                      DAC 3               DAC 3       
    NOT_ON_TIMER,               //  69      RH6     AN42/ERXD2/RH6                      DAC 4               DAC 4        
    NOT_ON_TIMER,               //  70      RH8     ERXD0/RH8                           DAC 5               DAC 5     
    NOT_ON_TIMER,               //  71      RH9     ERXD3/RH9                           DAC 6               DAC 6         
    NOT_ON_TIMER,               //  72      RH10    ECOL/RH10                           DAC 7               DAC 7       
    NOT_ON_TIMER,               //  73      RH12    ECRS/RH12                           DAC 8               DAC 8     
    NOT_ON_TIMER,               //  74      RH13    ERXDV/ECRSDV/RH13                   DAC 9               DAC 9     
    NOT_ON_TIMER,               //  75      RB14    EBIA1/AN9/RPB14/SCK3/PMA1/RB14      SPI DAC SCK3        SPI DAC SCK3     
    NOT_ON_TIMER,               //  76      RB8     EBIA10/AN48/RPB8/PMA10/RB8          SPI DAC SS3         SPI DAC SS3     
    NOT_ON_TIMER,               //  77      RB5     AN45/C1INA/RPB5/RB5                 SPI DAC SDI3        SPI DAC SDI3     
    NOT_ON_TIMER,               //  78      RB9     EBIA7/AN49/RPB9/PMA7/RB9            SPI DAC SDO3        SPI DAC SDO3     
};

/* ------------------------------------------------------------ */
/* This table maps from a digital pin number to the corresponding
** analog pin number.
*/
const uint8_t digital_pin_to_analog_PGM[] = {
    NOT_ANALOG_PIN,             //  0       RC14    SOSCO/RPC14/T1CK/RC14               RX Serial Monitor   RX Serial Monitor         
    NOT_ANALOG_PIN,             //  1       RD11    EMDC/RPD11/RD11                     TX Serial Moinitor  TX Serial Moinitor     
    NOT_ANALOG_PIN,             //  2       RD0     RPD0/RTCC/INT0/RD0                  INT0,IC1,T4CK       INT0,Tin     
    NOT_ANALOG_PIN,             //  3       RF2     RPF2/SDA3/RF2                       PWM1(OC1),INT1,T9CK Pro CLK/INT1,T9CK      
    NOT_ANALOG_PIN,             //  4       RA5     EBIA5/AN34/PMA5/RA5                 GPIO                Tout        
    NOT_ANALOG_PIN,             //  5       RF4     EBIA9/RPF4/SDA5/PMA9/RF4            PWM2(OC3),RX1,SDA5  Pro SDA5,RX1,PWM1(OC3)    
    NOT_ANALOG_PIN,             //  6       RG6     AN14/C1IND/RPG6/SCK2/RG6            PWM3(OC5),SCK2      Pro SCK2,CTS1       
    NOT_ANALOG_PIN,             //  7       RD4     SQICS0/RPD4/RD4                     INT2,IC2,T8CK       Digital CLK/INT2,TCK8      
    NOT_ANALOG_PIN,             //  8       RF0     EBID11/RPF0/PMD11/RF0               INT4,SDI2,SDO2,IC4  pro SDI2,SDO2     
    NOT_ANALOG_PIN,             //  9       RD2     EBID14/RPD2/PMD14/RD2               PWM4(OC6),T2CK      DC+,OC6     
    NOT_ANALOG_PIN,             //  10      RF3     RPF3/USBID/RF3                      PWM5(OC2),SS2,IC6   Pro SS2,RTS1,PWM2(OC2)   
    NOT_ANALOG_PIN,             //  11      RC13    SOSCI/RPC13/RC13                    PWM6(OC4),T5CK      DC-,OC4     
    NOT_ANALOG_PIN,             //  12      RF5     EBIA8/RPF5/SCL5/PMA8/RF5            SDI2,SDO2,TX1,SCL5  Pro SDI2,SDO2,SCL5,TX1     
    NOT_ANALOG_PIN,             //  13      RJ4     RJ4                                 User LED 1          User LED 1     
    _BOARD_AN0,                 //  14      RB0     PGED1/AN0/RPB0/RB0                  A0                  ADC1     
    _BOARD_AN1,                 //  15      RB2     AN2/C2INB/RPB2/RB2                  A1                  ADC2     
    _BOARD_AN2,                 //  16      RA0     TMS/EBIA16/AN24/RA0                 A2                  ADC1 Offset feedback       
    _BOARD_AN3,                 //  17      RA1     TCK/EBIA19/AN29/RA1                 A3                  ADC2 Offset feedback     
    _BOARD_AN4,                 //  18      RB11    AN6/RB11                            A4                  DC+ feedback     
    _BOARD_AN5,                 //  19      RB12    EBIA11/AN7/PMA11/RB12               A5                  DC- feedback       
    _BOARD_AN6,                 //  20      RB13    AN8/RB13                            A6                  AWG feedback      
    _BOARD_AN7,                 //  21      RJ11    AN37/ERXCLK/EREFCLK/RJ11            A7                  USB5V0 feedback         
    _BOARD_AN8,                 //  22      RG15    AN23/RG15                           A8                  VCC3V3 feedback       
    _BOARD_AN9,                 //  23      RJ8     AN35/ETXD0/RJ8                      A9                  VREF3V0 feedback      
    _BOARD_AN10,                //  24      RJ9     AN36/ETXD1/RJ9                      A10                 VREF1V5 feedback      
    _BOARD_AN11,                //  25      RC4     EBIOE/AN19/RPC4/PMRD/RC4            A11                 VSS5V0- feedback     
    NOT_ANALOG_PIN,             //  26      RE0     EBID0/PMD0/RE0                      GPIO                Digital IO 0     
    NOT_ANALOG_PIN,             //  27      RE1     EBID1/PMD1/RE1                      GPIO                Digital IO 1     
    NOT_ANALOG_PIN,             //  28      RE2     EBID2/SQID2/PMD2/RE2                GPIO                Digital IO 2     
    NOT_ANALOG_PIN,             //  29      RE3     EBID3/RPE3/PMD3/RE3                 GPIO                Digital IO 3     
    NOT_ANALOG_PIN,             //  30      RE4     EBID4/AN18/PMD4/RE4                 GPIO                Digital IO 4     
    NOT_ANALOG_PIN,             //  31      RE5     EBID5/AN17/RPE5/PMD5/RE5            GPIO                Digital IO 5      
    NOT_ANALOG_PIN,             //  32      RE6     EBID6/AN16/PMD6/RE6                 GPIO                Digital IO 6     
    NOT_ANALOG_PIN,             //  33      RE7     EBID7/AN15/PMD7/RE7                 GPIO                Digital IO 7       
    NOT_ANALOG_PIN,             //  34      RE8     AN25/RPE8/RE8                       GPIO                Digital IO 8     
    NOT_ANALOG_PIN,             //  35      RE9     AN26/RPE9/RE9                       GPIO                Digital IO 9       
    NOT_ANALOG_PIN,             //  36      RD1     RPD1/SCK1/RD1                       PGA SCK1            PGA SCK1     
    NOT_ANALOG_PIN,             //  37      RA6     TRCLK/SQICLK/RA6                    PGA CS1             PGA CS1     
    NOT_ANALOG_PIN,             //  38      RA7     TRD3/SQID3/RA7                      PGA CS2             PGA CS2     
    NOT_ANALOG_PIN,             //  39      RD3     EBID15/RPD3/PMD15/RD3               PGA SDO1            PGA SDO1     
    NOT_ANALOG_PIN,             //  40      RA2     EBICS0/SCL2/RA2                     ADC1 EN             ADC1 EN     
    NOT_ANALOG_PIN,             //  41      RA3     EBIRDY1/SDA2/RA3                    ADC2 EN             ADC2 EN     
    NOT_ANALOG_PIN,             //  42      RG12    TRD1/SQID1/RG12                     DCOUT EN            DCOUT EN     
    NOT_ANALOG_PIN,             //  43      RG0     EBID8/RPG0/PMD8/RG0                 AWG OFFSET          AWG OFFSET              
    NOT_ANALOG_PIN,             //  44      RD9     EBIA15/RPD9/PMCS2/PMA15/RD9         ADC1 OFFSET         ADC1 OFFSET     
    NOT_ANALOG_PIN,             //  45      RC2     EBIA12/AN21/RPC2/PMA12/RC2          ADC2 OFFSET         ADC2 OFFSET        
    NOT_ANALOG_PIN,             //  46      RA9     VREF-/CVREF-/AN27/RA9               VREF-               VREF-     
    NOT_ANALOG_PIN,             //  47      RA10    VREF+/CVREF+/AN28/RA10              VREF+               VREF+                
    NOT_ANALOG_PIN,             //  48      RJ2     EBIRDY3/RJ2                         LED2                LED2     
    NOT_ANALOG_PIN,             //  49      RJ1     EMDIO/RJ1                           LED3                LED3     
    NOT_ANALOG_PIN,             //  50      RJ0     ETXERR/RJ0                          LED4                LED4     
    NOT_ANALOG_PIN,             //  51      RD15    AN33/RPD15/SCK6/RD15                uSD SCK6            uSD SCK6       
    NOT_ANALOG_PIN,             //  52      RD14    AN32/AETXD0/RPD14/RD14              uSD SS6             uSD SS6      
    NOT_ANALOG_PIN,             //  53      RD5     SQICS1/RPD5/RD5                     uSD SDI6            uSD SDI6     
    NOT_ANALOG_PIN,             //  54      RD12    EBID12/RPD12/PMD12/RD12             uSD SDO6            uSD SDO6     
    NOT_ANALOG_PIN,             //  55      RD10    RPD10/SCK4/RD10                     MRF24 SCK4          MRF24 SCK4     
    NOT_ANALOG_PIN,             //  56      RB15    EBIA0/AN10/RPB15/OCFB/PMA0/RB15     MRF24 SS4           MRF24 SS4               
    NOT_ANALOG_PIN,             //  57      RG7     EBIA4/AN13/C1INC/RPG7/SDA4/PMA4/RG7 MRF24 SDI4          MRF24 SDI4     
    NOT_ANALOG_PIN,             //  58      RA15    RPA15/SDA1/RA15                     MRF24 SDO4          MRF24 SDO4     
    NOT_ANALOG_PIN,             //  59      RG8     EBIA3/AN12/C2IND/RPG8/SCL4/PMA3/RG8 MRF24 INT3          MRF24 INT3           
    NOT_ANALOG_PIN,             //  60      RD13    EBID13/PMD13/RD13                   MRF24 HIB           MRF24 HIB     
    NOT_ANALOG_PIN,             //  61      RA4     EBIA14/PMCS1/PMA14/RA4              MRF24 RESET         MRF24 RESET     
    NOT_ANALOG_PIN,             //  62      RA14    RPA14/SCL1/RA14                     MRF24 WP            MRF24 WP     
    NOT_ANALOG_PIN,             //  63      RG13    TRD0/SQID0/RG13                     SDA5 PULLUP         SDA5 PULLUP     
    NOT_ANALOG_PIN,             //  64      RG14    RD2/SQID2/RG14                      SCL5 PULLUP         SCL5 PULLUP     
    NOT_ANALOG_PIN,             //  65      RH0     AN38/ETXD2/RH0                      DAC 0               DAC 0         
    NOT_ANALOG_PIN,             //  66      RH1     AN39/ETXD3/RH1                      DAC 1               DAC 1     
    NOT_ANALOG_PIN,             //  67      RH4     AN40/ERXERR/RH4                     DAC 2               DAC 2       
    NOT_ANALOG_PIN,             //  68      RH5     AN41/ERXD1/RH5                      DAC 3               DAC 3       
    NOT_ANALOG_PIN,             //  69      RH6     AN42/ERXD2/RH6                      DAC 4               DAC 4        
    NOT_ANALOG_PIN,             //  70      RH8     ERXD0/RH8                           DAC 5               DAC 5     
    NOT_ANALOG_PIN,             //  71      RH9     ERXD3/RH9                           DAC 6               DAC 6         
    NOT_ANALOG_PIN,             //  72      RH10    ECOL/RH10                           DAC 7               DAC 7       
    NOT_ANALOG_PIN,             //  73      RH12    ECRS/RH12                           DAC 8               DAC 8     
    NOT_ANALOG_PIN,             //  74      RH13    ERXDV/ECRSDV/RH13                   DAC 9               DAC 9     
    NOT_ANALOG_PIN,             //  75      RB14    EBIA1/AN9/RPB14/SCK3/PMA1/RB14      SPI DAC SCK3        SPI DAC SCK3     
    NOT_ANALOG_PIN,             //  76      RB8     EBIA10/AN48/RPB8/PMA10/RB8          SPI DAC SS3         SPI DAC SS3     
    NOT_ANALOG_PIN,             //  77      RB5     AN45/C1INA/RPB5/RB5                 SPI DAC SDI3        SPI DAC SDI3     
    NOT_ANALOG_PIN,             //  78      RB9     EBIA7/AN49/RPB9/PMA7/RB9            SPI DAC SDO3        SPI DAC SDO3     
};


/* ------------------------------------------------------------ */
/* This table is used to map from the analog pin number to the
** actual A/D converter channel used for that pin.
*/
const uint8_t analog_pin_to_channel_PGM[] =
{
                //*    chipKIT Pin        PIC32 Analog channel
    0,          //*    A0                       AN0
    2,          //*    A1                       AN2
    24,         //*    A2                       AN24
    29,         //*    A3                       AN29
    6,          //*    A4                       AN6
    7,          //*    A5                       AN7
    8,          //*    A6                       AN8
    37,         //*    A7                       AN37
    23,         //*    A8                       AN23
    35,         //*    A9                       AN35
    36,         //*    A10                      AN36
    19,         //*    A11                      AN19
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
const uint8_t digital_pin_to_pps_out_PGM[] = {
    _PPS_OUT(_PPS_RPC14R),      //  0       RC14    SOSCO/RPC14/T1CK/RC14               RX Serial Monitor   RX Serial Monitor         
    _PPS_OUT(_PPS_RPD11R),      //  1       RD11    EMDC/RPD11/RD11                     TX Serial Moinitor  TX Serial Moinitor     
    _PPS_OUT(_PPS_RPD0R),       //  2       RD0     RPD0/RTCC/INT0/RD0                  INT0,IC1,T4CK       INT0,Tin     
    _PPS_OUT(_PPS_RPF2R),       //  3       RF2     RPF2/SDA3/RF2                       PWM1(OC1),INT1,T9CK Pro CLK/INT1,T9CK      
    NOT_PPS_PIN,                //  4       RA5     EBIA5/AN34/PMA5/RA5                 GPIO                Tout        
    _PPS_OUT(_PPS_RPF4R),       //  5       RF4     EBIA9/RPF4/SDA5/PMA9/RF4            PWM2(OC3),RX1,SDA5  Pro SDA5,RX1,PWM1(OC3)    
    _PPS_OUT(_PPS_RPG6R),       //  6       RG6     AN14/C1IND/RPG6/SCK2/RG6            PWM3(OC5),SCK2      Pro SCK2,CTS1       
    _PPS_OUT(_PPS_RPD4R),       //  7       RD4     SQICS0/RPD4/RD4                     INT2,IC2,T8CK       Digital CLK/INT2,TCK8      
    _PPS_OUT(_PPS_RPF0R),       //  8       RF0     EBID11/RPF0/PMD11/RF0               INT4,SDI2,SDO2,IC4  pro SDI2,SDO2     
    _PPS_OUT(_PPS_RPD2R),       //  9       RD2     EBID14/RPD2/PMD14/RD2               PWM4(OC6),T2CK      DC+,OC6     
    _PPS_OUT(_PPS_RPF3R),       //  10      RF3     RPF3/USBID/RF3                      PWM5(OC2),SS2,IC6   Pro SS2,RTS1,PWM2(OC2)   
    _PPS_OUT(_PPS_RPC13R),      //  11      RC13    SOSCI/RPC13/RC13                    PWM6(OC4),T5CK      DC-,OC4     
    _PPS_OUT(_PPS_RPF5R),       //  12      RF5     EBIA8/RPF5/SCL5/PMA8/RF5            SDI2,SDO2,TX1,SCL5  Pro SDI2,SDO2,SCL5,TX1     
    NOT_PPS_PIN,                //  13      RJ4     RJ4                                 User LED 1          User LED 1     
    _PPS_OUT(_PPS_RPB0R),       //  14      RB0     PGED1/AN0/RPB0/RB0                  A0                  ADC1     
    _PPS_OUT(_PPS_RPB2R),       //  15      RB2     AN2/C2INB/RPB2/RB2                  A1                  ADC2     
    NOT_PPS_PIN,                //  16      RA0     TMS/EBIA16/AN24/RA0                 A2                  ADC1 Offset feedback       
    NOT_PPS_PIN,                //  17      RA1     TCK/EBIA19/AN29/RA1                 A3                  ADC2 Offset feedback     
    NOT_PPS_PIN,                //  18      RB11    AN6/RB11                            A4                  DC+ feedback     
    NOT_PPS_PIN,                //  19      RB12    EBIA11/AN7/PMA11/RB12               A5                  DC- feedback       
    NOT_PPS_PIN,                //  20      RB13    AN8/RB13                            A6                  AWG feedback      
    NOT_PPS_PIN,                //  21      RJ11    AN37/ERXCLK/EREFCLK/RJ11            A7                  USB5V0 feedback         
    NOT_PPS_PIN,                //  22      RG15    AN23/RG15                           A8                  VCC3V3 feedback       
    NOT_PPS_PIN,                //  23      RJ8     AN35/ETXD0/RJ8                      A9                  VREF3V0 feedback      
    NOT_PPS_PIN,                //  24      RJ9     AN36/ETXD1/RJ9                      A10                 VREF1V5 feedback      
    _PPS_OUT(_PPS_RPC4R),       //  25      RC4     EBIOE/AN19/RPC4/PMRD/RC4            A11                 VSS5V0- feedback     
    NOT_PPS_PIN,                //  26      RE0     EBID0/PMD0/RE0                      GPIO                Digital IO 0     
    NOT_PPS_PIN,                //  27      RE1     EBID1/PMD1/RE1                      GPIO                Digital IO 1     
    NOT_PPS_PIN,                //  28      RE2     EBID2/SQID2/PMD2/RE2                GPIO                Digital IO 2     
    _PPS_OUT(_PPS_RPE3R),       //  29      RE3     EBID3/RPE3/PMD3/RE3                 GPIO                Digital IO 3     
    NOT_PPS_PIN,                //  30      RE4     EBID4/AN18/PMD4/RE4                 GPIO                Digital IO 4     
    _PPS_OUT(_PPS_RPE5R),       //  31      RE5     EBID5/AN17/RPE5/PMD5/RE5            GPIO                Digital IO 5      
    NOT_PPS_PIN,                //  32      RE6     EBID6/AN16/PMD6/RE6                 GPIO                Digital IO 6     
    NOT_PPS_PIN,                //  33      RE7     EBID7/AN15/PMD7/RE7                 GPIO                Digital IO 7       
    _PPS_OUT(_PPS_RPE8R),       //  34      RE8     AN25/RPE8/RE8                       GPIO                Digital IO 8     
    _PPS_OUT(_PPS_RPE9R),       //  35      RE9     AN26/RPE9/RE9                       GPIO                Digital IO 9       
    _PPS_OUT(_PPS_RPD1R),       //  36      RD1     RPD1/SCK1/RD1                       PGA SCK1            PGA SCK1     
    NOT_PPS_PIN,                //  37      RA6     TRCLK/SQICLK/RA6                    PGA CS1             PGA CS1     
    NOT_PPS_PIN,                //  38      RA7     TRD3/SQID3/RA7                      PGA CS2             PGA CS2     
    _PPS_OUT(_PPS_RPD3R),       //  39      RD3     EBID15/RPD3/PMD15/RD3               PGA SDO1            PGA SDO1     
    NOT_PPS_PIN,                //  40      RA2     EBICS0/SCL2/RA2                     ADC1 EN             ADC1 EN     
    NOT_PPS_PIN,                //  41      RA3     EBIRDY1/SDA2/RA3                    ADC2 EN             ADC2 EN     
    NOT_PPS_PIN,                //  42      RG12    TRD1/SQID1/RG12                     DCOUT EN            DCOUT EN     
    _PPS_OUT(_PPS_RPG0R),       //  43      RG0     EBID8/RPG0/PMD8/RG0                 AWG OFFSET          AWG OFFSET              
    _PPS_OUT(_PPS_RPD9R),       //  44      RD9     EBIA15/RPD9/PMCS2/PMA15/RD9         ADC1 OFFSET         ADC1 OFFSET     
    _PPS_OUT(_PPS_RPC2R),       //  45      RC2     EBIA12/AN21/RPC2/PMA12/RC2          ADC2 OFFSET         ADC2 OFFSET        
    NOT_PPS_PIN,                //  46      RA9     VREF-/CVREF-/AN27/RA9               VREF-               VREF-     
    NOT_PPS_PIN,                //  47      RA10    VREF+/CVREF+/AN28/RA10              VREF+               VREF+                
    NOT_PPS_PIN,                //  48      RJ2     EBIRDY3/RJ2                         LED2                LED2     
    NOT_PPS_PIN,                //  49      RJ1     EMDIO/RJ1                           LED3                LED3     
    NOT_PPS_PIN,                //  50      RJ0     ETXERR/RJ0                          LED4                LED4     
    _PPS_OUT(_PPS_RPD15R),      //  51      RD15    AN33/RPD15/SCK6/RD15                uSD SCK6            uSD SCK6       
    _PPS_OUT(_PPS_RPD14R),      //  52      RD14    AN32/AETXD0/RPD14/RD14              uSD SS6             uSD SS6      
    _PPS_OUT(_PPS_RPD5R),       //  53      RD5     SQICS1/RPD5/RD5                     uSD SDI6            uSD SDI6     
    _PPS_OUT(_PPS_RPD12R),      //  54      RD12    EBID12/RPD12/PMD12/RD12             uSD SDO6            uSD SDO6     
    _PPS_OUT(_PPS_RPD10R),      //  55      RD10    RPD10/SCK4/RD10                     MRF24 SCK4          MRF24 SCK4     
    _PPS_OUT(_PPS_RPB15R),      //  56      RB15    EBIA0/AN10/RPB15/OCFB/PMA0/RB15     MRF24 SS4           MRF24 SS4               
    _PPS_OUT(_PPS_RPG7R),       //  57      RG7     EBIA4/AN13/C1INC/RPG7/SDA4/PMA4/RG7 MRF24 SDI4          MRF24 SDI4     
    _PPS_OUT(_PPS_RPA15R),      //  58      RA15    RPA15/SDA1/RA15                     MRF24 SDO4          MRF24 SDO4     
    _PPS_OUT(_PPS_RPG8R),       //  59      RG8     EBIA3/AN12/C2IND/RPG8/SCL4/PMA3/RG8 MRF24 INT3          MRF24 INT3           
    NOT_PPS_PIN,                //  60      RD13    EBID13/PMD13/RD13                   MRF24 HIB           MRF24 HIB     
    NOT_PPS_PIN,                //  61      RA4     EBIA14/PMCS1/PMA14/RA4              MRF24 RESET         MRF24 RESET     
    _PPS_OUT(_PPS_RPA14R),      //  62      RA14    RPA14/SCL1/RA14                     MRF24 WP            MRF24 WP     
    NOT_PPS_PIN,                //  63      RG13    TRD0/SQID0/RG13                     SDA5 PULLUP         SDA5 PULLUP     
    NOT_PPS_PIN,                //  64      RG14    RD2/SQID2/RG14                      SCL5 PULLUP         SCL5 PULLUP     
    NOT_PPS_PIN,                //  65      RH0     AN38/ETXD2/RH0                      DAC 0               DAC 0         
    NOT_PPS_PIN,                //  66      RH1     AN39/ETXD3/RH1                      DAC 1               DAC 1     
    NOT_PPS_PIN,                //  67      RH4     AN40/ERXERR/RH4                     DAC 2               DAC 2       
    NOT_PPS_PIN,                //  68      RH5     AN41/ERXD1/RH5                      DAC 3               DAC 3       
    NOT_PPS_PIN,                //  69      RH6     AN42/ERXD2/RH6                      DAC 4               DAC 4        
    NOT_PPS_PIN,                //  70      RH8     ERXD0/RH8                           DAC 5               DAC 5     
    NOT_PPS_PIN,                //  71      RH9     ERXD3/RH9                           DAC 6               DAC 6         
    NOT_PPS_PIN,                //  72      RH10    ECOL/RH10                           DAC 7               DAC 7       
    NOT_PPS_PIN,                //  73      RH12    ECRS/RH12                           DAC 8               DAC 8     
    NOT_PPS_PIN,                //  74      RH13    ERXDV/ECRSDV/RH13                   DAC 9               DAC 9     
    _PPS_OUT(_PPS_RPB14R),      //  75      RB14    EBIA1/AN9/RPB14/SCK3/PMA1/RB14      SPI DAC SCK3        SPI DAC SCK3     
    _PPS_OUT(_PPS_RPB8R),       //  76      RB8     EBIA10/AN48/RPB8/PMA10/RB8          SPI DAC SS3         SPI DAC SS3     
    _PPS_OUT(_PPS_RPB5R),       //  77      RB5     AN45/C1INA/RPB5/RB5                 SPI DAC SDI3        SPI DAC SDI3     
    _PPS_OUT(_PPS_RPB9R),       //  78      RB9     EBIA7/AN49/RPB9/PMA7/RB9            SPI DAC SDO3        SPI DAC SDO3     
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
    _PPS_IN(_PPS_RPC14),        //  0       RC14    SOSCO/RPC14/T1CK/RC14               RX Serial Monitor   RX Serial Monitor         
    _PPS_IN(_PPS_RPD11),        //  1       RD11    EMDC/RPD11/RD11                     TX Serial Moinitor  TX Serial Moinitor     
    _PPS_IN(_PPS_RPD0),         //  2       RD0     RPD0/RTCC/INT0/RD0                  INT0,IC1,T4CK       INT0,Tin     
    _PPS_IN(_PPS_RPF2),         //  3       RF2     RPF2/SDA3/RF2                       PWM1(OC1),INT1,T9CK Pro CLK/INT1,T9CK      
    NOT_PPS_PIN,                //  4       RA5     EBIA5/AN34/PMA5/RA5                 GPIO                Tout        
    _PPS_IN(_PPS_RPF4),         //  5       RF4     EBIA9/RPF4/SDA5/PMA9/RF4            PWM2(OC3),RX1,SDA5  Pro SDA5,RX1,PWM1(OC3)    
    _PPS_IN(_PPS_RPG6),         //  6       RG6     AN14/C1IND/RPG6/SCK2/RG6            PWM3(OC5),SCK2      Pro SCK2,CTS1       
    _PPS_IN(_PPS_RPD4),         //  7       RD4     SQICS0/RPD4/RD4                     INT2,IC2,T8CK       Digital CLK/INT2,TCK8      
    _PPS_IN(_PPS_RPF0),         //  8       RF0     EBID11/RPF0/PMD11/RF0               INT4,SDI2,SDO2,IC4  pro SDI2,SDO2     
    _PPS_IN(_PPS_RPD2),         //  9       RD2     EBID14/RPD2/PMD14/RD2               PWM4(OC6),T2CK      DC+,OC6     
    _PPS_IN(_PPS_RPF3),         //  10      RF3     RPF3/USBID/RF3                      PWM5(OC2),SS2,IC6   Pro SS2,RTS1,PWM2(OC2)   
    _PPS_IN(_PPS_RPC13),        //  11      RC13    SOSCI/RPC13/RC13                    PWM6(OC4),T5CK      DC-,OC4     
    _PPS_IN(_PPS_RPF5),         //  12      RF5     EBIA8/RPF5/SCL5/PMA8/RF5            SDI2,SDO2,TX1,SCL5  Pro SDI2,SDO2,SCL5,TX1     
    NOT_PPS_PIN,                //  13      RJ4     RJ4                                 User LED 1          User LED 1     
    _PPS_IN(_PPS_RPB0),         //  14      RB0     PGED1/AN0/RPB0/RB0                  A0                  ADC1     
    _PPS_IN(_PPS_RPB2),         //  15      RB2     AN2/C2INB/RPB2/RB2                  A1                  ADC2     
    NOT_PPS_PIN,                //  16      RA0     TMS/EBIA16/AN24/RA0                 A2                  ADC1 Offset feedback       
    NOT_PPS_PIN,                //  17      RA1     TCK/EBIA19/AN29/RA1                 A3                  ADC2 Offset feedback     
    NOT_PPS_PIN,                //  18      RB11    AN6/RB11                            A4                  DC+ feedback     
    NOT_PPS_PIN,                //  19      RB12    EBIA11/AN7/PMA11/RB12               A5                  DC- feedback       
    NOT_PPS_PIN,                //  20      RB13    AN8/RB13                            A6                  AWG feedback      
    NOT_PPS_PIN,                //  21      RJ11    AN37/ERXCLK/EREFCLK/RJ11            A7                  USB5V0 feedback         
    NOT_PPS_PIN,                //  22      RG15    AN23/RG15                           A8                  VCC3V3 feedback       
    NOT_PPS_PIN,                //  23      RJ8     AN35/ETXD0/RJ8                      A9                  VREF3V0 feedback      
    NOT_PPS_PIN,                //  24      RJ9     AN36/ETXD1/RJ9                      A10                 VREF1V5 feedback      
    _PPS_IN(_PPS_RPC4),         //  25      RC4     EBIOE/AN19/RPC4/PMRD/RC4            A11                 VSS5V0- feedback     
    NOT_PPS_PIN,                //  26      RE0     EBID0/PMD0/RE0                      GPIO                Digital IO 0     
    NOT_PPS_PIN,                //  27      RE1     EBID1/PMD1/RE1                      GPIO                Digital IO 1     
    NOT_PPS_PIN,                //  28      RE2     EBID2/SQID2/PMD2/RE2                GPIO                Digital IO 2     
    _PPS_IN(_PPS_RPE3),         //  29      RE3     EBID3/RPE3/PMD3/RE3                 GPIO                Digital IO 3     
    NOT_PPS_PIN,                //  30      RE4     EBID4/AN18/PMD4/RE4                 GPIO                Digital IO 4     
    _PPS_IN(_PPS_RPE5),         //  31      RE5     EBID5/AN17/RPE5/PMD5/RE5            GPIO                Digital IO 5      
    NOT_PPS_PIN,                //  32      RE6     EBID6/AN16/PMD6/RE6                 GPIO                Digital IO 6     
    NOT_PPS_PIN,                //  33      RE7     EBID7/AN15/PMD7/RE7                 GPIO                Digital IO 7       
    _PPS_IN(_PPS_RPE8),         //  34      RE8     AN25/RPE8/RE8                       GPIO                Digital IO 8     
    _PPS_IN(_PPS_RPE9),         //  35      RE9     AN26/RPE9/RE9                       GPIO                Digital IO 9       
    _PPS_IN(_PPS_RPD1),         //  36      RD1     RPD1/SCK1/RD1                       PGA SCK1            PGA SCK1     
    NOT_PPS_PIN,                //  37      RA6     TRCLK/SQICLK/RA6                    PGA CS1             PGA CS1     
    NOT_PPS_PIN,                //  38      RA7     TRD3/SQID3/RA7                      PGA CS2             PGA CS2     
    _PPS_IN(_PPS_RPD3),         //  39      RD3     EBID15/RPD3/PMD15/RD3               PGA SDO1            PGA SDO1     
    NOT_PPS_PIN,                //  40      RA2     EBICS0/SCL2/RA2                     ADC1 EN             ADC1 EN     
    NOT_PPS_PIN,                //  41      RA3     EBIRDY1/SDA2/RA3                    ADC2 EN             ADC2 EN     
    NOT_PPS_PIN,                //  42      RG12    TRD1/SQID1/RG12                     DCOUT EN            DCOUT EN     
    _PPS_IN(_PPS_RPG0),         //  43      RG0     EBID8/RPG0/PMD8/RG0                 AWG OFFSET          AWG OFFSET              
    _PPS_IN(_PPS_RPD9),         //  44      RD9     EBIA15/RPD9/PMCS2/PMA15/RD9         ADC1 OFFSET         ADC1 OFFSET     
    _PPS_IN(_PPS_RPC2),         //  45      RC2     EBIA12/AN21/RPC2/PMA12/RC2          ADC2 OFFSET         ADC2 OFFSET        
    NOT_PPS_PIN,                //  46      RA9     VREF-/CVREF-/AN27/RA9               VREF-               VREF-     
    NOT_PPS_PIN,                //  47      RA10    VREF+/CVREF+/AN28/RA10              VREF+               VREF+                
    NOT_PPS_PIN,                //  48      RJ2     EBIRDY3/RJ2                         LED2                LED2     
    NOT_PPS_PIN,                //  49      RJ1     EMDIO/RJ1                           LED3                LED3     
    NOT_PPS_PIN,                //  50      RJ0     ETXERR/RJ0                          LED4                LED4     
    _PPS_IN(_PPS_RPD15),        //  51      RD15    AN33/RPD15/SCK6/RD15                uSD SCK6            uSD SCK6       
    _PPS_IN(_PPS_RPD14),        //  52      RD14    AN32/AETXD0/RPD14/RD14              uSD SS6             uSD SS6      
    _PPS_IN(_PPS_RPD5),         //  53      RD5     SQICS1/RPD5/RD5                     uSD SDI6            uSD SDI6     
    _PPS_IN(_PPS_RPD12),        //  54      RD12    EBID12/RPD12/PMD12/RD12             uSD SDO6            uSD SDO6     
    _PPS_IN(_PPS_RPD10),        //  55      RD10    RPD10/SCK4/RD10                     MRF24 SCK4          MRF24 SCK4     
    _PPS_IN(_PPS_RPB15),        //  56      RB15    EBIA0/AN10/RPB15/OCFB/PMA0/RB15     MRF24 SS4           MRF24 SS4               
    _PPS_IN(_PPS_RPG7),         //  57      RG7     EBIA4/AN13/C1INC/RPG7/SDA4/PMA4/RG7 MRF24 SDI4          MRF24 SDI4     
    _PPS_IN(_PPS_RPA15),        //  58      RA15    RPA15/SDA1/RA15                     MRF24 SDO4          MRF24 SDO4     
    _PPS_IN(_PPS_RPG8),         //  59      RG8     EBIA3/AN12/C2IND/RPG8/SCL4/PMA3/RG8 MRF24 INT3          MRF24 INT3           
    NOT_PPS_PIN,                //  60      RD13    EBID13/PMD13/RD13                   MRF24 HIB           MRF24 HIB     
    NOT_PPS_PIN,                //  61      RA4     EBIA14/PMCS1/PMA14/RA4              MRF24 RESET         MRF24 RESET     
    _PPS_IN(_PPS_RPA14),        //  62      RA14    RPA14/SCL1/RA14                     MRF24 WP            MRF24 WP     
    NOT_PPS_PIN,                //  63      RG13    TRD0/SQID0/RG13                     SDA5 PULLUP         SDA5 PULLUP     
    NOT_PPS_PIN,                //  64      RG14    RD2/SQID2/RG14                      SCL5 PULLUP         SCL5 PULLUP     
    NOT_PPS_PIN,                //  65      RH0     AN38/ETXD2/RH0                      DAC 0               DAC 0         
    NOT_PPS_PIN,                //  66      RH1     AN39/ETXD3/RH1                      DAC 1               DAC 1     
    NOT_PPS_PIN,                //  67      RH4     AN40/ERXERR/RH4                     DAC 2               DAC 2       
    NOT_PPS_PIN,                //  68      RH5     AN41/ERXD1/RH5                      DAC 3               DAC 3       
    NOT_PPS_PIN,                //  69      RH6     AN42/ERXD2/RH6                      DAC 4               DAC 4        
    NOT_PPS_PIN,                //  70      RH8     ERXD0/RH8                           DAC 5               DAC 5     
    NOT_PPS_PIN,                //  71      RH9     ERXD3/RH9                           DAC 6               DAC 6         
    NOT_PPS_PIN,                //  72      RH10    ECOL/RH10                           DAC 7               DAC 7       
    NOT_PPS_PIN,                //  73      RH12    ECRS/RH12                           DAC 8               DAC 8     
    NOT_PPS_PIN,                //  74      RH13    ERXDV/ECRSDV/RH13                   DAC 9               DAC 9     
    _PPS_IN(_PPS_RPB14),        //  75      RB14    EBIA1/AN9/RPB14/SCK3/PMA1/RB14      SPI DAC SCK3        SPI DAC SCK3     
    _PPS_IN(_PPS_RPB8),         //  76      RB8     EBIA10/AN48/RPB8/PMA10/RB8          SPI DAC SS3         SPI DAC SS3     
    _PPS_IN(_PPS_RPB5),         //  77      RB5     AN45/C1INA/RPB5/RB5                 SPI DAC SDI3        SPI DAC SDI3     
    _PPS_IN(_PPS_RPB9),         //  78      RB9     EBIA7/AN49/RPB9/PMA7/RB9            SPI DAC SDO3        SPI DAC SDO3     
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


//#include "EFADC.c"