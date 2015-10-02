/*******************************************************************************
  OSC Peripheral Library Template Implementation

  File Name:
    osc_FRCDivisor_Default.h

  Summary:
    OSC PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : FRCDivisor
    and its Variant : Default
    For following APIs :
        PLIB_OSC_ExistsFRCDivisor
        PLIB_OSC_FRCDivisorSelect
        PLIB_OSC_FRCDivisorGet

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

#ifndef _OSC_FRCDIVISOR_DEFAULT_H
#define _OSC_FRCDIVISOR_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _OSC_OSC_FRC_DIVISOR_VREG(index)
    _OSC_OSC_REGISTER_LOCK_VREG(index)

  MASKs: 
    _OSC_OSC_FRC_DIVISOR_MASK(index)
    _OSC_OSC_REGISTER_LOCK_MASK(index)

  POSs: 
    _OSC_OSC_FRC_DIVISOR_POS(index)
    _OSC_OSC_REGISTER_LOCK_POS(index)

  LENs: 
    _OSC_OSC_FRC_DIVISOR_LEN(index)
    _OSC_OSC_REGISTER_LOCK_LEN(index)

*/


//******************************************************************************
/* Function :  OSC_ExistsFRCDivisor_Default

  Summary:
    Implements Default variant of PLIB_OSC_ExistsFRCDivisor

  Description:
    This template implements the Default variant of the PLIB_OSC_ExistsFRCDivisor function.
*/

#define PLIB_OSC_ExistsFRCDivisor PLIB_OSC_ExistsFRCDivisor
PLIB_TEMPLATE bool OSC_ExistsFRCDivisor_Default( OSC_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  OSC_FRCDivisorSelect_Default

  Summary:
    Implements Default variant of PLIB_OSC_FRCDivisorSelect 

  Description:
    This template implements the Default variant of the PLIB_OSC_FRCDivisorSelect function.
*/

PLIB_TEMPLATE void OSC_FRCDivisorSelect_Default( OSC_MODULE_ID index , OSC_FRC_DIV divisorFRC )
{
    _SFR_FIELD_WRITE(_OSC_OSC_FRC_DIVISOR_VREG(index),
                     _OSC_OSC_FRC_DIVISOR_MASK(index),
                     _OSC_OSC_FRC_DIVISOR_POS(index) ,
                     divisorFRC );
}


//******************************************************************************
/* Function :  OSC_FRCDivisorGet_Default

  Summary:
    Implements Default variant of PLIB_OSC_FRCDivisorGet

  Description:
    This template implements the Default variant of the PLIB_OSC_FRCDivisorGet function.
*/

PLIB_TEMPLATE uint16_t OSC_FRCDivisorGet_Default( OSC_MODULE_ID index )
{
    uint8_t regValue;

    regValue = _SFR_FIELD_READ(_OSC_OSC_FRC_DIVISOR_VREG(index),
                           _OSC_OSC_FRC_DIVISOR_MASK(index),
                           _OSC_OSC_FRC_DIVISOR_POS(index) );
    if ( regValue != 7 )
    {
        return ( 0x01 << regValue );
    }
    else
    {
        return 256;
    }
}


#endif /*_OSC_FRCDIVISOR_DEFAULT_H*/

/******************************************************************************
 End of File
*/

