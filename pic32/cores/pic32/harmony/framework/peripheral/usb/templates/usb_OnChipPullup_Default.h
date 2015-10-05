/*******************************************************************************
  USB Peripheral Library Template Implementation

  File Name:
    usb_OnChipPullup_Default.h

  Summary:
    USB PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : OnChipPullup
    and its Variant : Default
    For following APIs :
        PLIB_USB_OnChipPullUpEnable
        PLIB_USB_OnChipPullUpDisable
        PLIB_USB_ExistsOnChipPullup

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

#ifndef _USB_ONCHIPPULLUP_DEFAULT_H
#define _USB_ONCHIPPULLUP_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _USB_ON_CHIP_PULLUP_VREG(index)

  MASKs: 
    _USB_ON_CHIP_PULLUP_MASK(index)

  POSs: 
    _USB_ON_CHIP_PULLUP_POS(index)

  LENs: 
    _USB_ON_CHIP_PULLUP_LEN(index)

*/


//******************************************************************************
/* Function :  USB_OnChipPullUpEnable_Default

  Summary:
    Implements Default variant of PLIB_USB_OnChipPullUpEnable 

  Description:
    This template implements the Default variant of the PLIB_USB_OnChipPullUpEnable function.
*/

PLIB_TEMPLATE void USB_OnChipPullUpEnable_Default( USB_MODULE_ID index )
{
    _SFR_BIT_SET( _USB_ON_CHIP_PULLUP_VREG( index ),
                  _USB_ON_CHIP_PULLUP_POS( index ) );
}


//******************************************************************************
/* Function :  USB_OnChipPullUpDisable_Default

  Summary:
    Implements Default variant of PLIB_USB_OnChipPullUpDisable 

  Description:
    This template implements the Default variant of the PLIB_USB_OnChipPullUpDisable function.
*/

PLIB_TEMPLATE void USB_OnChipPullUpDisable_Default( USB_MODULE_ID index )
{
    _SFR_BIT_CLEAR( _USB_ON_CHIP_PULLUP_VREG( index ),
                    _USB_ON_CHIP_PULLUP_POS( index ) );
}


//******************************************************************************
/* Function :  USB_ExistsOnChipPullup_Default

  Summary:
    Implements Default variant of PLIB_USB_ExistsOnChipPullup

  Description:
    This template implements the Default variant of the PLIB_USB_ExistsOnChipPullup function.
*/

#define PLIB_USB_ExistsOnChipPullup PLIB_USB_ExistsOnChipPullup
PLIB_TEMPLATE bool USB_ExistsOnChipPullup_Default( USB_MODULE_ID index )
{
    return true;
}


#endif /*_USB_ONCHIPPULLUP_DEFAULT_H*/

/******************************************************************************
 End of File
*/

