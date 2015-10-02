/*******************************************************************************
  OSC Peripheral Library Template Implementation

  File Name:
    osc_SlewEnableControl_Default.h

  Summary:
    OSC PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : SlewEnableControl
    and its Variant : Default
    For following APIs :
        PLIB_OSC_ExistsSlewEnableControl
        PLIB_OSC_SlewEnable
        PLIB_OSC_SlewDisable
        PLIB_OSC_SlewIsEnabled

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _OSC_SLEWENABLECONTROL_DEFAULT_H
#define _OSC_SLEWENABLECONTROL_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _OSC_OSC_UPWARD_SLEW_CONTROL_VREG(index)
    _OSC_OSC_DOWNWARD_SLEW_CONTROL_VREG(index)

  MASKs: 
    _OSC_OSC_UPWARD_SLEW_CONTROL_MASK(index)
    _OSC_OSC_DOWNWARD_SLEW_CONTROL_MASK(index)

  POSs: 
    _OSC_OSC_UPWARD_SLEW_CONTROL_POS(index)
    _OSC_OSC_DOWNWARD_SLEW_CONTROL_POS(index)

  LENs: 
    _OSC_OSC_UPWARD_SLEW_CONTROL_LEN(index)
    _OSC_OSC_DOWNWARD_SLEW_CONTROL_LEN(index)

*/


//******************************************************************************
/* Function :  OSC_ExistsSlewEnableControl_Default

  Summary:
    Implements Default variant of PLIB_OSC_ExistsSlewEnableControl

  Description:
    This template implements the Default variant of the PLIB_OSC_ExistsSlewEnableControl function.
*/

#define PLIB_OSC_ExistsSlewEnableControl PLIB_OSC_ExistsSlewEnableControl
PLIB_TEMPLATE bool OSC_ExistsSlewEnableControl_Default( OSC_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  OSC_SlewEnable_Default

  Summary:
    Implements Default variant of PLIB_OSC_SlewEnable 

  Description:
    This template implements the Default variant of the PLIB_OSC_SlewEnable function.
*/

PLIB_TEMPLATE void OSC_SlewEnable_Default( OSC_MODULE_ID index , OSC_CLOCK_SLEW_TYPE slewType )
{
    _SFR_BIT_SET(_OSC_OSC_DOWNWARD_SLEW_CONTROL_VREG(index),
                     _OSC_OSC_DOWNWARD_SLEW_CONTROL_POS(index) + slewType);
}


//******************************************************************************
/* Function :  OSC_SlewDisable_Default

  Summary:
    Implements Default variant of PLIB_OSC_SlewDisable 

  Description:
    This template implements the Default variant of the PLIB_OSC_SlewDisable function.
*/

PLIB_TEMPLATE void OSC_SlewDisable_Default( OSC_MODULE_ID index , OSC_CLOCK_SLEW_TYPE slewType )
{
    _SFR_BIT_CLEAR(_OSC_OSC_DOWNWARD_SLEW_CONTROL_VREG(index),
         _OSC_OSC_DOWNWARD_SLEW_CONTROL_POS(index)+ slewType );
}


//******************************************************************************
/* Function :  OSC_SlewIsEnabled_Default

  Summary:
    Implements Default variant of PLIB_OSC_SlewIsEnabled 

  Description:
    This template implements the Default variant of the PLIB_OSC_SlewIsEnabled function.
*/

PLIB_TEMPLATE bool OSC_SlewIsEnabled_Default( OSC_MODULE_ID index , OSC_CLOCK_SLEW_TYPE slewType )
{
   return (_SFR_BIT_READ(_OSC_OSC_DOWNWARD_SLEW_CONTROL_VREG(index),
                     _OSC_OSC_DOWNWARD_SLEW_CONTROL_POS(index) +slewType ));
}


#endif /*_OSC_SLEWENABLECONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

