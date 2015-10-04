/*******************************************************************************
  USB Peripheral Library Template Implementation

  File Name:
    usb_BufferFreeze_PIC18.h

  Summary:
    USB PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : BufferFreeze
    and its Variant : PIC18
    For following APIs :
        PLIB_USB_PingPongFreeze
        PLIB_USB_PingPongUnfreeze
        PLIB_USB_PingPongReset
        PLIB_USB_ExistsBufferFreeze

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

#ifndef _USB_BUFFERFREEZE_PIC18_H
#define _USB_BUFFERFREEZE_PIC18_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _USB_FREEZE_BUFFERS_P18_VREG(index)

  MASKs: 
    _USB_FREEZE_BUFFERS_P18_MASK(index)

  POSs: 
    _USB_FREEZE_BUFFERS_P18_POS(index)

  LENs: 
    _USB_FREEZE_BUFFERS_P18_LEN(index)

*/


//******************************************************************************
/* Function :  USB_PingPongFreeze_PIC18

  Summary:
    Implements PIC18 variant of PLIB_USB_PingPongFreeze 

  Description:
    This template implements the PIC18 variant of the PLIB_USB_PingPongFreeze function.
*/

PLIB_TEMPLATE void USB_PingPongFreeze_PIC18( USB_MODULE_ID index )
{
    _SFR_BIT_SET( _USB_FREEZE_BUFFERS_P18_VREG( index ),
                  _USB_FREEZE_BUFFERS_P18_POS( index ) );
}


//******************************************************************************
/* Function :  USB_PingPongUnfreeze_PIC18

  Summary:
    Implements PIC18 variant of PLIB_USB_PingPongUnfreeze 

  Description:
    This template implements the PIC18 variant of the PLIB_USB_PingPongUnfreeze function.
*/

PLIB_TEMPLATE void USB_PingPongUnfreeze_PIC18( USB_MODULE_ID index )
{
    _SFR_BIT_CLEAR( _USB_FREEZE_BUFFERS_P18_VREG( index ),
                    _USB_FREEZE_BUFFERS_P18_POS( index ) );
}


//******************************************************************************
/* Function :  USB_PingPongReset_PIC18

  Summary:
    Implements PIC18 variant of PLIB_USB_PingPongReset 

  Description:
    This template implements the PIC18 variant of the PLIB_USB_PingPongReset function.
*/

PLIB_TEMPLATE void USB_PingPongReset_PIC18( USB_MODULE_ID index )
{
   _SFR_BIT_SET( _USB_FREEZE_BUFFERS_P18_VREG( index ),
                 _USB_FREEZE_BUFFERS_P18_POS( index ) );

   _SFR_BIT_CLEAR( _USB_FREEZE_BUFFERS_P18_VREG( index ),
                   _USB_FREEZE_BUFFERS_P18_POS( index ) );
}


//******************************************************************************
/* Function :  USB_ExistsBufferFreeze_PIC18

  Summary:
    Implements PIC18 variant of PLIB_USB_ExistsBufferFreeze

  Description:
    This template implements the PIC18 variant of the PLIB_USB_ExistsBufferFreeze function.
*/

#define PLIB_USB_ExistsBufferFreeze PLIB_USB_ExistsBufferFreeze
PLIB_TEMPLATE bool USB_ExistsBufferFreeze_PIC18( USB_MODULE_ID index )
{
    return true;
}


#endif /*_USB_BUFFERFREEZE_PIC18_H*/

/******************************************************************************
 End of File
*/

