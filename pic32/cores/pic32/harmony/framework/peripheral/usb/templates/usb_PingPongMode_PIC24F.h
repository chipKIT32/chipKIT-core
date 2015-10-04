/*******************************************************************************
  USB Peripheral Library Template Implementation

  File Name:
    usb_PingPongMode_PIC24F.h

  Summary:
    USB PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : PingPongMode
    and its Variant : PIC24F
    For following APIs :
        PLIB_USB_PingPongModeSelect
        PLIB_USB_PingPongModeGet
        PLIB_USB_ExistsPingPongMode

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

#ifndef _USB_PINGPONGMODE_PIC24F_H
#define _USB_PINGPONGMODE_PIC24F_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _USB_PIC24F_PPB_VREG(index)

  MASKs: 
    _USB_PIC24F_PPB_MASK(index)

  POSs: 
    _USB_PIC24F_PPB_POS(index)

  LENs: 
    _USB_PIC24F_PPB_LEN(index)

*/


//******************************************************************************
/* Function :  USB_PingPongModeSelect_PIC24F

  Summary:
    Implements PIC24F variant of PLIB_USB_PingPongModeSelect 

  Description:
    This template implements the PIC24F variant of the PLIB_USB_PingPongModeSelect function.
*/

PLIB_TEMPLATE void USB_PingPongModeSelect_PIC24F( USB_MODULE_ID index , USB_PING_PONG_MODE ppConfig )
{
    _SFR_FIELD_WRITE(_USB_PIC24F_PPB_VREG(index),
                     _USB_PIC24F_PPB_POS(index) ,
                     ppconfig                     );
}


//******************************************************************************
/* Function :  USB_PingPongModeGet_PIC24F

  Summary:
    Implements PIC24F variant of PLIB_USB_PingPongModeGet 

  Description:
    This template implements the PIC24F variant of the PLIB_USB_PingPongModeGet function.
*/

PLIB_TEMPLATE USB_PING_PONG_MODE USB_PingPongModeGet_PIC24F( USB_MODULE_ID index )
{
    return (  _SFR_FIELD_READ(_USB_PIC24F_PPB_VREG(index),
                              _USB_PIC24F_PPB_POS(index) )  );
}


//******************************************************************************
/* Function :  USB_ExistsPingPongMode_PIC24F

  Summary:
    Implements PIC24F variant of PLIB_USB_ExistsPingPongMode

  Description:
    This template implements the PIC24F variant of the PLIB_USB_ExistsPingPongMode function.
*/

#define PLIB_USB_ExistsPingPongMode PLIB_USB_ExistsPingPongMode
PLIB_TEMPLATE bool USB_ExistsPingPongMode_PIC24F( USB_MODULE_ID index )
{
    return true;
}


#endif /*_USB_PINGPONGMODE_PIC24F_H*/

/******************************************************************************
 End of File
*/

