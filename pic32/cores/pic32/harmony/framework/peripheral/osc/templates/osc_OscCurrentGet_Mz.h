/*******************************************************************************
  OSC Peripheral Library Template Implementation

  File Name:
    osc_OscCurrentGet_Mz.h

  Summary:
    OSC PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : OscCurrentGet
    and its Variant : Mz
    For following APIs :
        PLIB_OSC_ExistsOscCurrentGet
        PLIB_OSC_CurrentSysClockGet

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

#ifndef _OSC_OSCCURRENTGET_MZ_H
#define _OSC_OSCCURRENTGET_MZ_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _OSC_OSC_CURRENT_GET_VREG(index)
    _OSC_OSC_SYSPLL_INPUT_SOURCE_CLOCK_VREG(index)

  MASKs: 
    _OSC_OSC_CURRENT_GET_MASK(index)
    _OSC_OSC_SYSPLL_INPUT_SOURCE_CLOCK_MASK(index)

  POSs: 
    _OSC_OSC_CURRENT_GET_POS(index)
    _OSC_OSC_SYSPLL_INPUT_SOURCE_CLOCK_POS(index)

  LENs: 
    _OSC_OSC_CURRENT_GET_LEN(index)
    _OSC_OSC_SYSPLL_INPUT_SOURCE_CLOCK_LEN(index)

*/


//******************************************************************************
/* Function :  OSC_ExistsOscCurrentGet_Mz

  Summary:
    Implements Mz variant of PLIB_OSC_ExistsOscCurrentGet

  Description:
    This template implements the Mz variant of the PLIB_OSC_ExistsOscCurrentGet function.
*/

#define PLIB_OSC_ExistsOscCurrentGet PLIB_OSC_ExistsOscCurrentGet
PLIB_TEMPLATE bool OSC_ExistsOscCurrentGet_Mz( OSC_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  OSC_CurrentSysClockGet_Mz

  Summary:
    Implements Mz variant of PLIB_OSC_CurrentSysClockGet 

  Description:
    This template implements the Mz variant of the PLIB_OSC_CurrentSysClockGet function.
*/

PLIB_TEMPLATE OSC_SYS_TYPE OSC_CurrentSysClockGet_Mz( OSC_MODULE_ID index )
{
     OSC_SYS_TYPE oscType;

     oscType = (OSC_SYS_TYPE)_SFR_FIELD_READ(_OSC_OSC_CURRENT_GET_VREG(index),
		_OSC_OSC_CURRENT_GET_MASK(index),
		_OSC_OSC_CURRENT_GET_POS(index) );

    /* The souce is either System PLL or FRC PLL */
    if ( oscType == OSC_FRC_WITH_PLL )
    {
        if (!_SFR_BIT_READ( _OSC_OSC_SYSPLL_INPUT_SOURCE_CLOCK_VREG(index),
                                 _OSC_OSC_SYSPLL_INPUT_SOURCE_CLOCK_POS(index) ) )
        {
            return OSC_PRIMARY_WITH_PLL;
        }
    }

    return oscType;
}


#endif /*_OSC_OSCCURRENTGET_MZ_H*/

/******************************************************************************
 End of File
*/

