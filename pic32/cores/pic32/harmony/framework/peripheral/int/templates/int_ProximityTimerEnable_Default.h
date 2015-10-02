/*******************************************************************************
  INT Peripheral Library Template Implementation

  File Name:
    int_ProximityTimerEnable_Default.h

  Summary:
    INT PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ProximityTimerEnable
    and its Variant : Default
    For following APIs :
        PLIB_INT_ExistsProximityTimerEnable
        PLIB_INT_ProximityTimerEnable
        PLIB_INT_ProximityTimerDisable

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2012 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _INT_PROXIMITYTIMERENABLE_DEFAULT_H
#define _INT_PROXIMITYTIMERENABLE_DEFAULT_H


//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _INT_PROXIMITY_TIMER_ENABLE_VREG(index)

  MASKs: 
    _INT_PROXIMITY_TIMER_ENABLE_MASK(index)

  POSs: 
    _INT_PROXIMITY_TIMER_ENABLE_POS(index)

  LENs: 
    _INT_PROXIMITY_TIMER_ENABLE_LEN(index)

*/


//******************************************************************************
/* Function :  INT_ExistsProximityTimerEnable_Default

  Summary:
    Implements Default variant of PLIB_INT_ExistsProximityTimerEnable

  Description:
    This template implements the Default variant of the PLIB_INT_ExistsProximityTimerEnable function.
*/

#define PLIB_INT_ExistsProximityTimerEnable PLIB_INT_ExistsProximityTimerEnable
PLIB_TEMPLATE bool INT_ExistsProximityTimerEnable_Default( INT_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  INT_ProximityTimerEnable_Default

  Summary:
    Implements Default variant of PLIB_INT_ProximityTimerEnable 

  Description:
    This template implements the Default variant of the PLIB_INT_ProximityTimerEnable function.
*/

PLIB_TEMPLATE void INT_ProximityTimerEnable_Default( INT_MODULE_ID index , INT_PRIORITY_LEVEL priority )
{
    _SFR_FIELD_WRITE(_INT_PROXIMITY_TIMER_ENABLE_VREG(index),_INT_PROXIMITY_TIMER_ENABLE_MASK(index),_INT_PROXIMITY_TIMER_ENABLE_POS(index),priority);
}


//******************************************************************************
/* Function :  INT_ProximityTimerDisable_Default

  Summary:
    Implements Default variant of PLIB_INT_ProximityTimerDisable 

  Description:
    This template implements the Default variant of the PLIB_INT_ProximityTimerDisable function.
*/

PLIB_TEMPLATE void INT_ProximityTimerDisable_Default( INT_MODULE_ID index )
{
     _SFR_FIELD_CLEAR(_INT_PROXIMITY_TIMER_ENABLE_VREG(index),_INT_PROXIMITY_TIMER_ENABLE_MASK(index),_INT_PROXIMITY_TIMER_ENABLE_POS(index),0xFFFFFFFF);
}


#endif /*_INT_PROXIMITYTIMERENABLE_DEFAULT_H*/

/******************************************************************************
 End of File
*/

