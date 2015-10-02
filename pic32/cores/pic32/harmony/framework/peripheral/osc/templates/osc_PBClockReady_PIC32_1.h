/*******************************************************************************
  OSC Peripheral Library Template Implementation

  File Name:
    osc_PBClockReady_PIC32_1.h

  Summary:
    OSC PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : PBClockReady
    and its Variant : PIC32_1
    For following APIs :
        PLIB_OSC_ExistsPBClockReady
        PLIB_OSC_PBClockDivisorIsReady

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/

//DOM-IGNORE-END

#ifndef _OSC_PBCLOCKREADY_PIC32_1_H
#define _OSC_PBCLOCKREADY_PIC32_1_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _OSC_OSC_PB_CLOCK_READY_1_VREG(index)
    _OSC_OSC_PB_CLOCK_READY_2_VREG(index)
    _OSC_OSC_PB_CLOCK_READY_3_VREG(index)
    _OSC_OSC_PB_CLOCK_READY_4_VREG(index)
    _OSC_OSC_PB_CLOCK_READY_5_VREG(index)
    _OSC_OSC_PB_CLOCK_READY_7_VREG(index)
    _OSC_OSC_PB_CLOCK_READY_8_VREG(index)

  MASKs: 
    _OSC_OSC_PB_CLOCK_READY_1_MASK(index)
    _OSC_OSC_PB_CLOCK_READY_2_MASK(index)
    _OSC_OSC_PB_CLOCK_READY_3_MASK(index)
    _OSC_OSC_PB_CLOCK_READY_4_MASK(index)
    _OSC_OSC_PB_CLOCK_READY_5_MASK(index)
    _OSC_OSC_PB_CLOCK_READY_7_MASK(index)
    _OSC_OSC_PB_CLOCK_READY_8_MASK(index)

  POSs: 
    _OSC_OSC_PB_CLOCK_READY_1_POS(index)
    _OSC_OSC_PB_CLOCK_READY_2_POS(index)
    _OSC_OSC_PB_CLOCK_READY_3_POS(index)
    _OSC_OSC_PB_CLOCK_READY_4_POS(index)
    _OSC_OSC_PB_CLOCK_READY_5_POS(index)
    _OSC_OSC_PB_CLOCK_READY_7_POS(index)
    _OSC_OSC_PB_CLOCK_READY_8_POS(index)

  LENs: 
    _OSC_OSC_PB_CLOCK_READY_1_LEN(index)
    _OSC_OSC_PB_CLOCK_READY_2_LEN(index)
    _OSC_OSC_PB_CLOCK_READY_3_LEN(index)
    _OSC_OSC_PB_CLOCK_READY_4_LEN(index)
    _OSC_OSC_PB_CLOCK_READY_5_LEN(index)
    _OSC_OSC_PB_CLOCK_READY_7_LEN(index)
    _OSC_OSC_PB_CLOCK_READY_8_LEN(index)

*/


//******************************************************************************
/* Function :  OSC_ExistsPBClockReady_PIC32_1

  Summary:
    Implements PIC32_1 variant of PLIB_OSC_ExistsPBClockReady

  Description:
    This template implements the PIC32_1 variant of the PLIB_OSC_ExistsPBClockReady function.
*/

#define PLIB_OSC_ExistsPBClockReady PLIB_OSC_ExistsPBClockReady
PLIB_TEMPLATE bool OSC_ExistsPBClockReady_PIC32_1( OSC_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  OSC_PBClockDivisorIsReady_PIC32_1

  Summary:
    Implements PIC32_1 variant of PLIB_OSC_PBClockDivisorIsReady 

  Description:
    This template implements the PIC32_1 variant of the PLIB_OSC_PBClockDivisorIsReady function.
*/

PLIB_TEMPLATE bool OSC_PBClockDivisorIsReady_PIC32_1( OSC_MODULE_ID index , OSC_PERIPHERAL_BUS peripheralBusNumber )
{
	
	return _SFR_BIT_READ(_OSC_OSC_PB_CLOCK_READY_1_VREG(index) + (peripheralBusNumber * 0x04),
					   		 _OSC_OSC_PB_CLOCK_READY_1_POS(index) );
}


#endif /*_OSC_PBCLOCKREADY_PIC32_1_H*/

/******************************************************************************
 End of File
*/

