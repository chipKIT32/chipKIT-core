/*******************************************************************************
  USB Peripheral Library Template Implementation

  File Name:
    usb_ALL_Interrupt_Default.h

  Summary:
    USB PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ALL_Interrupt
    and its Variant : Default
    For following APIs :
        PLIB_USB_AllInterruptEnable
        PLIB_USB_ExistsALL_Interrupt

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

#ifndef _USB_ALL_INTERRUPT_DEFAULT_H
#define _USB_ALL_INTERRUPT_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _USB_UnIE_VAL_VREG(index)
    _USB_UnEIE_VAL_VREG(index)
    _USB_UnOTGIE_VAL_VREG(index)

  MASKs: 
    _USB_UnIE_VAL_MASK(index)
    _USB_UnEIE_VAL_MASK(index)
    _USB_UnOTGIE_VAL_MASK(index)

  POSs: 
    _USB_UnIE_VAL_POS(index)
    _USB_UnEIE_VAL_POS(index)
    _USB_UnOTGIE_VAL_POS(index)

  LENs: 
    _USB_UnIE_VAL_LEN(index)
    _USB_UnEIE_VAL_LEN(index)
    _USB_UnOTGIE_VAL_LEN(index)

*/


//******************************************************************************
/* Function :  USB_AllInterruptEnable_Default

  Summary:
    Implements Default variant of PLIB_USB_AllInterruptEnable 

  Description:
    This template implements the Default variant of the PLIB_USB_AllInterruptEnable function.
*/

PLIB_TEMPLATE void USB_AllInterruptEnable_Default( USB_MODULE_ID index , USB_INTERRUPTS usbInterruptsFlag , USB_ERROR_INTERRUPTS usbErrorInterruptsFlag , USB_OTG_INTERRUPTS otgInterruptFlag )
{
    _SFR_WRITE(_USB_UnIE_VAL_VREG(index),usbInterruptsFlag);
    _SFR_WRITE(_USB_UnEIE_VAL_VREG(index),usbErrorInterruptsFlag);
    _SFR_WRITE(_USB_UnOTGIE_VAL_VREG(index),otgInterruptFlag);

}

PLIB_TEMPLATE USB_INTERRUPTS USB_InterruptEnableGet_Default (USB_MODULE_ID index)
{
    return (USB_INTERRUPTS)(_SFR_READ(_USB_UnIE_VAL_VREG(index)));
}


//******************************************************************************
/* Function :  USB_ExistsALL_Interrupt_Default

  Summary:
    Implements Default variant of PLIB_USB_ExistsALL_Interrupt

  Description:
    This template implements the Default variant of the PLIB_USB_ExistsALL_Interrupt function.
*/

#define PLIB_USB_ExistsALL_Interrupt PLIB_USB_ExistsALL_Interrupt
PLIB_TEMPLATE bool USB_ExistsALL_Interrupt_Default( USB_MODULE_ID index )
{
    return true;
}


#endif /*_USB_ALL_INTERRUPT_DEFAULT_H*/

/******************************************************************************
 End of File
*/

