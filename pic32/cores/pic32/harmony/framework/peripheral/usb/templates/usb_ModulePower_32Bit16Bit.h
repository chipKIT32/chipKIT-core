/*******************************************************************************
  USB Peripheral Library Template Implementation

  File Name:
    usb_ModulePower_32Bit16Bit.h

  Summary:
    USB PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ModulePower
    and its Variant : 32Bit16Bit
    For following APIs :
        PLIB_USB_Enable
        PLIB_USB_Disable
        PLIB_USB_ExistsModulePower

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

#ifndef _USB_MODULEPOWER_32BIT16BIT_H
#define _USB_MODULEPOWER_32BIT16BIT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _USB_POWERED_ON_VREG(index)

  MASKs: 
    _USB_POWERED_ON_MASK(index)

  POSs: 
    _USB_POWERED_ON_POS(index)

  LENs: 
    _USB_POWERED_ON_LEN(index)

*/


//******************************************************************************
/* Function :  USB_Enable_32Bit16Bit

  Summary:
    Implements 32Bit16Bit variant of PLIB_USB_Enable 

  Description:
    This template implements the 32Bit16Bit variant of the PLIB_USB_Enable function.
*/

PLIB_TEMPLATE void USB_Enable_32Bit16Bit( USB_MODULE_ID index )
{
    SFR_TYPE * vreg  = _USB_POWERED_ON_VREG(index);
    unsigned int pos = _U1PWRC_USBPWR_POSITION;
    
    *vreg |= (1 << pos);
}


//******************************************************************************
/* Function :  USB_Disable_32Bit16Bit

  Summary:
    Implements 32Bit16Bit variant of PLIB_USB_Disable 

  Description:
    This template implements the 32Bit16Bit variant of the PLIB_USB_Disable function.
*/

PLIB_TEMPLATE void USB_Disable_32Bit16Bit( USB_MODULE_ID index )
{
    _SFR_BIT_CLEAR(_USB_POWERED_ON_VREG(index),
                   _USB_POWERED_ON_POS(index) );
}


//******************************************************************************
/* Function :  USB_ExistsModulePower_32Bit16Bit

  Summary:
    Implements 32Bit16Bit variant of PLIB_USB_ExistsModulePower

  Description:
    This template implements the 32Bit16Bit variant of the PLIB_USB_ExistsModulePower function.
*/

#define PLIB_USB_ExistsModulePower PLIB_USB_ExistsModulePower
PLIB_TEMPLATE bool USB_ExistsModulePower_32Bit16Bit( USB_MODULE_ID index )
{
    return true;
}


#endif /*_USB_MODULEPOWER_32BIT16BIT_H*/

/******************************************************************************
 End of File
*/

