/*******************************************************************************
  USB Peripheral Library Template Implementation

  File Name:
    usb_OTG_InterruptStatus_Default.h

  Summary:
    USB PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : OTG_InterruptStatus
    and its Variant : Default
    For following APIs :
        PLIB_USB_OTG_InterruptFlagSet
        PLIB_USB_OTG_InterruptFlagClear
        PLIB_USB_OTG_InterruptFlagGet
        PLIB_USB_ExistsOTG_InterruptStatus

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

#ifndef _USB_OTG_INTERRUPTSTATUS_DEFAULT_H
#define _USB_OTG_INTERRUPTSTATUS_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _USB_UnOTGIR_VAL_VREG(index)

  MASKs: 
    _USB_UnOTGIR_VAL_MASK(index)

  POSs: 
    _USB_UnOTGIR_VAL_POS(index)

  LENs: 
    _USB_UnOTGIR_VAL_LEN(index)

*/


//******************************************************************************
/* Function :  USB_OTG_InterruptFlagSet_Default

  Summary:
    Implements Default variant of PLIB_USB_OTG_InterruptFlagSet 

  Description:
    This template implements the Default variant of the PLIB_USB_OTG_InterruptFlagSet function.
*/

PLIB_TEMPLATE void USB_OTG_InterruptFlagSet_Default( USB_MODULE_ID index , USB_OTG_INTERRUPTS     interruptFlag )
{
    _SFR_SET(_USB_UnOTGIR_VAL_VREG(index),interruptFlag);
}


//******************************************************************************
/* Function :  USB_OTG_InterruptFlagClear_Default

  Summary:
    Implements Default variant of PLIB_USB_OTG_InterruptFlagClear 

  Description:
    This template implements the Default variant of the PLIB_USB_OTG_InterruptFlagClear function.
*/

PLIB_TEMPLATE void USB_OTG_InterruptFlagClear_Default( USB_MODULE_ID index , USB_OTG_INTERRUPTS     interruptFlag )
{
    _SFR_WRITE(_USB_UnOTGIR_VAL_VREG(index),interruptFlag);
}


//******************************************************************************
/* Function :  USB_OTG_InterruptFlagGet_Default

  Summary:
    Implements Default variant of PLIB_USB_OTG_InterruptFlagGet 

  Description:
    This template implements the Default variant of the PLIB_USB_OTG_InterruptFlagGet function.
*/

PLIB_TEMPLATE bool USB_OTG_InterruptFlagGet_Default( USB_MODULE_ID index , USB_OTG_INTERRUPTS     interruptFlag )
{
    return ( _SFR_READ(_USB_UnOTGIR_VAL_VREG(index)) & interruptFlag ? 1 : 0 );
}


//******************************************************************************
/* Function :  USB_ExistsOTG_InterruptStatus_Default

  Summary:
    Implements Default variant of PLIB_USB_ExistsOTG_InterruptStatus

  Description:
    This template implements the Default variant of the PLIB_USB_ExistsOTG_InterruptStatus function.
*/

#define PLIB_USB_ExistsOTG_InterruptStatus PLIB_USB_ExistsOTG_InterruptStatus
PLIB_TEMPLATE bool USB_ExistsOTG_InterruptStatus_Default( USB_MODULE_ID index )
{
    return true;
}


#endif /*_USB_OTG_INTERRUPTSTATUS_DEFAULT_H*/

/******************************************************************************
 End of File
*/

