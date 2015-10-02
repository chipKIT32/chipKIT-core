/*******************************************************************************
  USB Peripheral Library Template Implementation

  File Name:
    usb_TokenPID_Default.h

  Summary:
    USB PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : TokenPID
    and its Variant : Default
    For following APIs :
        PLIB_USB_TokenPIDGet
        PLIB_USB_TokenPIDSet
        PLIB_USB_ExistsTokenPID

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

#ifndef _USB_TOKENPID_DEFAULT_H
#define _USB_TOKENPID_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _USB_TOKEN_PID_VREG(index)

  MASKs: 
    _USB_TOKEN_PID_MASK(index)

  POSs: 
    _USB_TOKEN_PID_POS(index)

  LENs: 
    _USB_TOKEN_PID_LEN(index)

*/


//******************************************************************************
/* Function :  USB_TokenPIDGet_Default

  Summary:
    Implements Default variant of PLIB_USB_TokenPIDGet 

  Description:
    This template implements the Default variant of the PLIB_USB_TokenPIDGet function.
*/

PLIB_TEMPLATE USB_PID USB_TokenPIDGet_Default( USB_MODULE_ID index )
{
    return (USB_PID)_SFR_FIELD_READ(_USB_TOKEN_PID_VREG(index),
                           _USB_TOKEN_PID_MASK(index),
                           _USB_TOKEN_PID_POS(index) );
}


//******************************************************************************
/* Function :  USB_TokenPIDSet_Default

  Summary:
    Implements Default variant of PLIB_USB_TokenPIDSet 

  Description:
    This template implements the Default variant of the PLIB_USB_TokenPIDSet function.
*/

PLIB_TEMPLATE void USB_TokenPIDSet_Default( USB_MODULE_ID index , USB_PID pidValue )
{
    _SFR_FIELD_WRITE(_USB_TOKEN_PID_VREG(index),
                     _USB_TOKEN_PID_MASK(index),
                     _USB_TOKEN_PID_POS(index) ,
                     pidValue                  );
}


//******************************************************************************
/* Function :  USB_ExistsTokenPID_Default

  Summary:
    Implements Default variant of PLIB_USB_ExistsTokenPID

  Description:
    This template implements the Default variant of the PLIB_USB_ExistsTokenPID function.
*/

#define PLIB_USB_ExistsTokenPID PLIB_USB_ExistsTokenPID
PLIB_TEMPLATE bool USB_ExistsTokenPID_Default( USB_MODULE_ID index )
{
    return true;
}

PLIB_TEMPLATE void USB_TokenSend_Default(USB_MODULE_ID index, USB_PID pidValue, uint8_t endpoint, uint8_t deviceAddress, bool isLowSpeed)
{
    SFR_TYPE * tokenControlRegister = _USB_TOKEN_PID_VREG(index);
    SFR_TYPE * deviceAddressRegister = _USB_DEVICE_ADDRESS_VREG(index);

    /* Set up the device address register */ 
    *deviceAddressRegister = (isLowSpeed) ? ((1 << 7)|(deviceAddress & 0x7F)) : (deviceAddress & 0x7F);

    /* Write to the token register */
    *tokenControlRegister = (pidValue << 4)|endpoint;

}

#endif /*_USB_TOKENPID_DEFAULT_H*/

/******************************************************************************
 End of File
*/

