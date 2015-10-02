/*******************************************************************************
  OSC Peripheral Library Template Implementation

  File Name:
    osc_PBClockOutputEnable_Default.h

  Summary:
    OSC PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : PBClockOutputEnable
    and its Variant : Default
    For following APIs :
        PLIB_OSC_ExistsPBClockOutputEnable
        PLIB_OSC_PBOutputClockEnable
        PLIB_OSC_PBOutputClockDisable
        PLIB_OSC_PBOutputClockIsEnabled

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

#ifndef _OSC_PBCLOCKOUTPUTENABLE_DEFAULT_H
#define _OSC_PBCLOCKOUTPUTENABLE_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _OSC_OSC_PB_CLOCK_ENABLE_2_VREG(index)
    _OSC_OSC_PB_CLOCK_ENABLE_3_VREG(index)
    _OSC_OSC_PB_CLOCK_ENABLE_4_VREG(index)
    _OSC_OSC_PB_CLOCK_ENABLE_5_VREG(index)
    _OSC_OSC_PB_CLOCK_ENABLE_7_VREG(index)
    _OSC_OSC_PB_CLOCK_ENABLE_8_VREG(index)
    _OSC_OSC_REGISTER_LOCK_VREG(index)

  MASKs: 
    _OSC_OSC_PB_CLOCK_ENABLE_2_MASK(index)
    _OSC_OSC_PB_CLOCK_ENABLE_3_MASK(index)
    _OSC_OSC_PB_CLOCK_ENABLE_4_MASK(index)
    _OSC_OSC_PB_CLOCK_ENABLE_5_MASK(index)
    _OSC_OSC_PB_CLOCK_ENABLE_7_MASK(index)
    _OSC_OSC_PB_CLOCK_ENABLE_8_MASK(index)
    _OSC_OSC_REGISTER_LOCK_MASK(index)

  POSs: 
    _OSC_OSC_PB_CLOCK_ENABLE_2_POS(index)
    _OSC_OSC_PB_CLOCK_ENABLE_3_POS(index)
    _OSC_OSC_PB_CLOCK_ENABLE_4_POS(index)
    _OSC_OSC_PB_CLOCK_ENABLE_5_POS(index)
    _OSC_OSC_PB_CLOCK_ENABLE_7_POS(index)
    _OSC_OSC_PB_CLOCK_ENABLE_8_POS(index)
    _OSC_OSC_REGISTER_LOCK_POS(index)

  LENs: 
    _OSC_OSC_PB_CLOCK_ENABLE_2_LEN(index)
    _OSC_OSC_PB_CLOCK_ENABLE_3_LEN(index)
    _OSC_OSC_PB_CLOCK_ENABLE_4_LEN(index)
    _OSC_OSC_PB_CLOCK_ENABLE_5_LEN(index)
    _OSC_OSC_PB_CLOCK_ENABLE_7_LEN(index)
    _OSC_OSC_PB_CLOCK_ENABLE_8_LEN(index)
    _OSC_OSC_REGISTER_LOCK_LEN(index)

*/


//******************************************************************************
/* Function :  OSC_ExistsPBClockOutputEnable_Default

  Summary:
    Implements Default variant of PLIB_OSC_ExistsPBClockOutputEnable

  Description:
    This template implements the Default variant of the PLIB_OSC_ExistsPBClockOutputEnable function.
*/

#define PLIB_OSC_ExistsPBClockOutputEnable PLIB_OSC_ExistsPBClockOutputEnable
PLIB_TEMPLATE bool OSC_ExistsPBClockOutputEnable_Default( OSC_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  OSC_PBOutputClockEnable_Default

  Summary:
    Implements Default variant of PLIB_OSC_PBOutputClockEnable 

  Description:
    This template implements the Default variant of the PLIB_OSC_PBOutputClockEnable function.
*/

PLIB_TEMPLATE void OSC_PBOutputClockEnable_Default( OSC_MODULE_ID index , OSC_PERIPHERAL_BUS peripheralBusNumber )
{

    if (peripheralBusNumber == OSC_PERIPHERAL_BUS_1)
    {
    	PLIB_ASSERT(false, "Peripheral Bus 1 is always enabled by default");
    }
    else
    {
        _SFR_BIT_SET(_OSC_OSC_PB_CLOCK_ENABLE_2_VREG(index) + ((peripheralBusNumber-1) * 0x04),
					   _OSC_OSC_PB_CLOCK_ENABLE_2_POS(index) );
    }
}


//******************************************************************************
/* Function :  OSC_PBOutputClockDisable_Default

  Summary:
    Implements Default variant of PLIB_OSC_PBOutputClockDisable 

  Description:
    This template implements the Default variant of the PLIB_OSC_PBOutputClockDisable function.
*/

PLIB_TEMPLATE void OSC_PBOutputClockDisable_Default( OSC_MODULE_ID index , OSC_PERIPHERAL_BUS peripheralBusNumber )
{
    
    if (peripheralBusNumber == OSC_PERIPHERAL_BUS_1)
    {
    	PLIB_ASSERT(false, "Peripheral Bus 1 can not be disabled");
    }
    else
    {
        _SFR_BIT_CLEAR(_OSC_OSC_PB_CLOCK_ENABLE_2_VREG(index) + ((peripheralBusNumber-1) * 0x04),
					   _OSC_OSC_PB_CLOCK_ENABLE_2_POS(index) );
    }
    
}


//******************************************************************************
/* Function :  OSC_PBOutputClockIsEnabled_Default

  Summary:
    Implements Default variant of PLIB_OSC_PBOutputClockIsEnabled 

  Description:
    This template implements the Default variant of the PLIB_OSC_PBOutputClockIsEnabled function.
*/

PLIB_TEMPLATE bool OSC_PBOutputClockIsEnabled_Default( OSC_MODULE_ID index , OSC_PERIPHERAL_BUS peripheralBusNumber )
{
	
    if (peripheralBusNumber == OSC_PERIPHERAL_BUS_1)
    {
    	PLIB_ASSERT(false, "Peripheral Bus 1 is always enabled");
		return true;
    }
    else
    {
        return _SFR_BIT_READ(_OSC_OSC_PB_CLOCK_ENABLE_2_VREG(index) + ((peripheralBusNumber - 1) * 0x04) ,
					   		 _OSC_OSC_PB_CLOCK_ENABLE_2_POS(index) );
    }
	
}


#endif /*_OSC_PBCLOCKOUTPUTENABLE_DEFAULT_H*/

/******************************************************************************
 End of File
*/

