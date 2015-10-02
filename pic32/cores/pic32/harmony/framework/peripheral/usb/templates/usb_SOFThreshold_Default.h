/*******************************************************************************
  USB Peripheral Library Template Implementation

  File Name:
    usb_SOFThreshold_Default.h

  Summary:
    USB PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : SOFThreshold
    and its Variant : Default
    For following APIs :
        PLIB_USB_SOFThresholdGet
        PLIB_USB_SOFThresholdSet
        PLIB_USB_ExistsSOFThreshold

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

#ifndef _USB_SOFTHRESHOLD_DEFAULT_H
#define _USB_SOFTHRESHOLD_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _USB_SOF_COUNT_VREG(index)

  MASKs: 
    _USB_SOF_COUNT_MASK(index)

  POSs: 
    _USB_SOF_COUNT_POS(index)

  LENs: 
    _USB_SOF_COUNT_LEN(index)

*/


//******************************************************************************
/* Function :  USB_SOFThresholdGet_Default

  Summary:
    Implements Default variant of PLIB_USB_SOFThresholdGet 

  Description:
    This template implements the Default variant of the PLIB_USB_SOFThresholdGet function.
*/

PLIB_TEMPLATE uint8_t USB_SOFThresholdGet_Default( USB_MODULE_ID index )
{
    return _SFR_FIELD_READ(_USB_SOF_COUNT_VREG(index),
                           _USB_SOF_COUNT_MASK(index),
                           _USB_SOF_COUNT_POS(index) );
}


//******************************************************************************
/* Function :  USB_SOFThresholdSet_Default

  Summary:
    Implements Default variant of PLIB_USB_SOFThresholdSet 

  Description:
    This template implements the Default variant of the PLIB_USB_SOFThresholdSet function.
*/

PLIB_TEMPLATE void USB_SOFThresholdSet_Default( USB_MODULE_ID index , uint8_t threshold )
{
    _SFR_FIELD_WRITE(_USB_SOF_COUNT_VREG(index),
                     _USB_SOF_COUNT_MASK(index),
                     _USB_SOF_COUNT_POS(index) ,
                     threshold                  );
}


//******************************************************************************
/* Function :  USB_ExistsSOFThreshold_Default

  Summary:
    Implements Default variant of PLIB_USB_ExistsSOFThreshold

  Description:
    This template implements the Default variant of the PLIB_USB_ExistsSOFThreshold function.
*/

#define PLIB_USB_ExistsSOFThreshold PLIB_USB_ExistsSOFThreshold
PLIB_TEMPLATE bool USB_ExistsSOFThreshold_Default( USB_MODULE_ID index )
{
    return true;
}


#endif /*_USB_SOFTHRESHOLD_DEFAULT_H*/

/******************************************************************************
 End of File
*/

