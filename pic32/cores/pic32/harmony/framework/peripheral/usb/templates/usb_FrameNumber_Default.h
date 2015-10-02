/*******************************************************************************
  USB Peripheral Library Template Implementation

  File Name:
    usb_FrameNumber_Default.h

  Summary:
    USB PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : FrameNumber
    and its Variant : Default
    For following APIs :
        PLIB_USB_FrameNumberGet
        PLIB_USB_ExistsFrameNumber

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

#ifndef _USB_FRAMENUMBER_DEFAULT_H
#define _USB_FRAMENUMBER_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _USB_FRAME_NUMBER_7to0_VREG(index)
    _USB_FRAME_NUMBER_10to8_VREG(index)

  MASKs: 
    _USB_FRAME_NUMBER_7to0_MASK(index)
    _USB_FRAME_NUMBER_10to8_MASK(index)

  POSs: 
    _USB_FRAME_NUMBER_7to0_POS(index)
    _USB_FRAME_NUMBER_10to8_POS(index)

  LENs: 
    _USB_FRAME_NUMBER_7to0_LEN(index)
    _USB_FRAME_NUMBER_10to8_LEN(index)

*/


//******************************************************************************
/* Function :  USB_FrameNumberGet_Default

  Summary:
    Implements Default variant of PLIB_USB_FrameNumberGet 

  Description:
    This template implements the Default variant of the PLIB_USB_FrameNumberGet function.
*/

PLIB_TEMPLATE uint16_t USB_FrameNumberGet_Default( USB_MODULE_ID index )
{
    return ( _SFR_FIELD_READ(_USB_FRAME_NUMBER_7to0_VREG(index),
                             _USB_FRAME_NUMBER_7to0_MASK(index),
                             _USB_FRAME_NUMBER_7to0_POS(index) )
             |
             _SFR_FIELD_READ(_USB_FRAME_NUMBER_10to8_VREG(index),
                             _USB_FRAME_NUMBER_10to8_MASK(index),
                             _USB_FRAME_NUMBER_10to8_POS(index) ) << 8 );
}


//******************************************************************************
/* Function :  USB_ExistsFrameNumber_Default

  Summary:
    Implements Default variant of PLIB_USB_ExistsFrameNumber

  Description:
    This template implements the Default variant of the PLIB_USB_ExistsFrameNumber function.
*/

#define PLIB_USB_ExistsFrameNumber PLIB_USB_ExistsFrameNumber
PLIB_TEMPLATE bool USB_ExistsFrameNumber_Default( USB_MODULE_ID index )
{
    return true;
}


#endif /*_USB_FRAMENUMBER_DEFAULT_H*/

/******************************************************************************
 End of File
*/

