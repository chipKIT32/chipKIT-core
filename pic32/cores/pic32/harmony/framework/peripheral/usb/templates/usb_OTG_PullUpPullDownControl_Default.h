/*******************************************************************************
  USB Peripheral Library Template Implementation

  File Name:
    usb_OTG_PullUpPullDownControl_Default.h

  Summary:
    USB PLIB Template Implementation

  Description:
    This header file contains template implementations for
    the default variant of the USB OTG_PullUpPullDownControl feature.

*******************************************************************************/

//DOM-IGNORE-BEGIN
/******************************************************************************
Copyright © 2012 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED “AS IS” WITHOUT WARRANTY OF ANY KIND,
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

#ifndef _USB_OTG_PULLUPPULLDOWNCONTROL_DEFAULT_H
#define _USB_OTG_PULLUPPULLDOWNCONTROL_DEFAULT_H

PLIB_TEMPLATE void USB_OTG_PullUpsPullDownsBySoftware_Default ( USB_MODULE_ID index )
{
    _SFR_BIT_SET(_USB_PULLUPS_PULLDNS_BY_SW_VREG(index),
                 _USB_PULLUPS_PULLDNS_BY_SW_POS(index) );
}

PLIB_TEMPLATE void USB_OTG_PullUpsPullDownsByHardware_Default ( USB_MODULE_ID index )
{
    _SFR_BIT_CLEAR(_USB_PULLUPS_PULLDNS_BY_SW_VREG(index),
                   _USB_PULLUPS_PULLDNS_BY_SW_POS(index) );
}

#endif //_USB_OTG_PULLUPPULLDOWNCONTROL_DEFAULT_H
