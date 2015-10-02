/*******************************************************************************
  INT Peripheral Library Template Implementation

  File Name:
    int_SourceControl_Default.h

  Summary:
    INT PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : SourceControl
    and its Variant : Default
    For following APIs :
        PLIB_INT_ExistsSourceControl
        PLIB_INT_SourceEnable
        PLIB_INT_SourceDisable
        PLIB_INT_SourceIsEnabled

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

#ifndef _INT_SOURCECONTROL_DEFAULT_H
#define _INT_SOURCECONTROL_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _INT_INT_ENABLE_CONTROL_0_VREG(index)
    _INT_INT_ENABLE_CONTROL_1_VREG(index)
    _INT_INT_ENABLE_CONTROL_2_VREG(index)

  MASKs: 
    _INT_INT_ENABLE_CONTROL_0_MASK(index)
    _INT_INT_ENABLE_CONTROL_1_MASK(index)
    _INT_INT_ENABLE_CONTROL_2_MASK(index)

  POSs: 
    _INT_INT_ENABLE_CONTROL_0_POS(index)
    _INT_INT_ENABLE_CONTROL_1_POS(index)
    _INT_INT_ENABLE_CONTROL_2_POS(index)

  LENs: 
    _INT_INT_ENABLE_CONTROL_0_LEN(index)
    _INT_INT_ENABLE_CONTROL_1_LEN(index)
    _INT_INT_ENABLE_CONTROL_2_LEN(index)

*/


//******************************************************************************
/* Function :  INT_ExistsSourceControl_Default

  Summary:
    Implements Default variant of PLIB_INT_ExistsSourceControl

  Description:
    This template implements the Default variant of the PLIB_INT_ExistsSourceControl function.
*/

#define PLIB_INT_ExistsSourceControl PLIB_INT_ExistsSourceControl
PLIB_TEMPLATE bool INT_ExistsSourceControl_Default( INT_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  INT_SourceEnable_Default

  Summary:
    Implements Default variant of PLIB_INT_SourceEnable 

  Description:
    This template implements the Default variant of the PLIB_INT_SourceEnable function.

  Note:
    The source enum encoding is (x * 32) + y, where x is the register number 
    (IECx) and y is the bit position. 0b0xxy_yyyy
*/

PLIB_TEMPLATE void INT_SourceEnable_Default( INT_MODULE_ID index , INT_SOURCE source )
{
    _SFR_BIT_SET(_INT_INT_ENABLE_CONTROL_0_VREG(index) + ((0x10 * (source >> 5)) >> 2), source & 0x1F);
}


//******************************************************************************
/* Function :  INT_SourceDisable_Default

  Summary:
    Implements Default variant of PLIB_INT_SourceDisable 

  Description:
    This template implements the Default variant of the PLIB_INT_SourceDisable function.

  Note:
    The source enum encoding is (x * 32) + y, where x is the register number 
    (IECx) and y is the bit position. 0b0xxy_yyyy
*/

PLIB_TEMPLATE void INT_SourceDisable_Default( INT_MODULE_ID index , INT_SOURCE source )
{
    _SFR_BIT_CLEAR(_INT_INT_ENABLE_CONTROL_0_VREG(index) + ((0x10 * (source >> 5)) >> 2), source & 0x1F);
}


//******************************************************************************
/* Function :  INT_SourceIsEnabled_Default

  Summary:
    Implements Default variant of PLIB_INT_SourceIsEnabled 

  Description:
    This template implements the Default variant of the PLIB_INT_SourceIsEnabled function.

  Note:
    The source enum encoding is (x * 32) + y, where x is the register number 
    (IECx) and y is the bit position. 0b0xxy_yyyy
*/

PLIB_TEMPLATE bool INT_SourceIsEnabled_Default( INT_MODULE_ID index , INT_SOURCE source )
{
    return (1 << (source & 0x1F)) & _SFR_READ(_INT_INT_ENABLE_CONTROL_0_VREG(index) + ((0x10 * (source >> 5)) >> 2));
}


#endif /*_INT_SOURCECONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

