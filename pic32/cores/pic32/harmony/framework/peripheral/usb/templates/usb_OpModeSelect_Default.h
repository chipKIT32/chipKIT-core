/*******************************************************************************
  USB Peripheral Library Template Implementation

  File Name:
    usb_OpModeSelect_Default.h

  Summary:
    USB PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : OpModeSelect
    and its Variant : Default
    For following APIs :
        PLIB_USB_OperatingModeSelect
        PLIB_USB_ExistsOpModeSelect

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

#ifndef _USB_OPMODESELECT_DEFAULT_H
#define _USB_OPMODESELECT_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are

  VREGs:
    _USB_HOST_ENABLE_VREG(index)
    _USB_OTG_ENABLE_VREG(index)
    _USB_DEVICE_ENABLE_VREG(index)

  MASKs:
    _USB_HOST_ENABLE_MASK(index)
    _USB_OTG_ENABLE_MASK(index)
    _USB_DEVICE_ENABLE_MASK(index)

  POSs:
    _USB_HOST_ENABLE_POS(index)
    _USB_OTG_ENABLE_POS(index)
    _USB_DEVICE_ENABLE_POS(index)

  LENs:
    _USB_HOST_ENABLE_LEN(index)
    _USB_OTG_ENABLE_LEN(index)
    _USB_DEVICE_ENABLE_LEN(index)

*/


//******************************************************************************
/* Function :  USB_OperatingModeSelect_Default

  Summary:
    Implements Default variant of PLIB_USB_OperatingModeSelect

  Description:
    This template implements the Default variant of the PLIB_USB_OperatingModeSelect function.
*/

PLIB_TEMPLATE void USB_OperatingModeSelect_Default( USB_MODULE_ID index , USB_OPMODES opMode )
{
    SFR_TYPE * devHostEnableVreg  = _USB_DEVICE_ENABLE_VREG(index);
    unsigned int devEnablePos     = _U1CON_USBEN_SOFEN_POSITION;
    unsigned int hostEnablePos    = _U1CON_HOSTEN_POSITION;
    SFR_TYPE * otgEnableVreg      = _USB_OTG_ENABLE_VREG(index);
    unsigned int otgEnablePos     = _U1OTGCON_OTGEN_POSITION;

    switch ( opMode )
    {
        case USB_OPMODE_NONE:
            *devHostEnableVreg  &= ~(1 << devEnablePos);
            *devHostEnableVreg  &= ~(1 << hostEnablePos);
            *otgEnableVreg      &= ~(1 << otgEnablePos);
            break;
        case USB_OPMODE_DEVICE:
            *devHostEnableVreg  |=  (1 << devEnablePos);
            *devHostEnableVreg  &= ~(1 << hostEnablePos);
            *otgEnableVreg      &= ~(1 << otgEnablePos);
            break;

        case USB_OPMODE_HOST:
            *devHostEnableVreg  &= ~(1 << devEnablePos);
            *devHostEnableVreg  |=  (1 << hostEnablePos);
            *otgEnableVreg      &= ~(1 << otgEnablePos);
            break;

        case USB_OPMODE_OTG:
            *devHostEnableVreg  &= ~(1 << devEnablePos);
            *devHostEnableVreg  &= ~(1 << hostEnablePos);
            *otgEnableVreg      |=  (1 << otgEnablePos);
            break;

        default:
            PLIB_ASSERT( 0, "In USB_OperatingModeSelect, unknown operating mode!" );
            break;
    }
}


//******************************************************************************
/* Function :  USB_ExistsOpModeSelect_Default

  Summary:
    Implements Default variant of PLIB_USB_ExistsOpModeSelect

  Description:
    This template implements the Default variant of the PLIB_USB_ExistsOpModeSelect function.
*/

#define PLIB_USB_ExistsOpModeSelect PLIB_USB_ExistsOpModeSelect
PLIB_TEMPLATE bool USB_ExistsOpModeSelect_Default( USB_MODULE_ID index )
{
    return true;
}


#endif /*_USB_OPMODESELECT_DEFAULT_H*/

/******************************************************************************
 End of File
*/

