/*******************************************************************************
  USB Peripheral Library Template Implementation

  File Name:
    usb_BDTBaseAddress_Default.h

  Summary:
    USB PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : BDTBaseAddress
    and its Variant : Default
    For following APIs :
        PLIB_USB_BDTBaseAddressGet
        PLIB_USB_BDTBaseAddressSet
        PLIB_USB_ExistsBDTBaseAddress

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

#ifndef _USB_BDTBASEADDRESS_DEFAULT_H
#define _USB_BDTBASEADDRESS_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _USB_BDT_BASE_ADDR_15to09_VREG(index)
    _USB_BDT_BASE_ADDR_23to16_VREG(index)
    _USB_BDT_BASE_ADDR_31to24_VREG(index)

  MASKs: 
    _USB_BDT_BASE_ADDR_15to09_MASK(index)
    _USB_BDT_BASE_ADDR_23to16_MASK(index)
    _USB_BDT_BASE_ADDR_31to24_MASK(index)

  POSs: 
    _USB_BDT_BASE_ADDR_15to09_POS(index)
    _USB_BDT_BASE_ADDR_23to16_POS(index)
    _USB_BDT_BASE_ADDR_31to24_POS(index)

  LENs: 
    _USB_BDT_BASE_ADDR_15to09_LEN(index)
    _USB_BDT_BASE_ADDR_23to16_LEN(index)
    _USB_BDT_BASE_ADDR_31to24_LEN(index)

*/


//******************************************************************************
/* Function :  USB_BDTBaseAddressGet_Default

  Summary:
    Implements Default variant of PLIB_USB_BDTBaseAddressGet 

  Description:
    This template implements the Default variant of the PLIB_USB_BDTBaseAddressGet function.
*/

PLIB_TEMPLATE void* USB_BDTBaseAddressGet_Default( USB_MODULE_ID index )
{
    return (void *)
             ( _SFR_FIELD_READ(_USB_BDT_BASE_ADDR_31to24_VREG(index),
                             _USB_BDT_BASE_ADDR_31to24_MASK(index),
                             _USB_BDT_BASE_ADDR_31to24_POS(index) ) << 24
             |
             _SFR_FIELD_READ(_USB_BDT_BASE_ADDR_23to16_VREG(index),
                             _USB_BDT_BASE_ADDR_23to16_MASK(index),
                             _USB_BDT_BASE_ADDR_23to16_POS(index) ) << 16
             |
             _SFR_FIELD_READ(_USB_BDT_BASE_ADDR_15to09_VREG(index),
                             _USB_BDT_BASE_ADDR_15to09_MASK(index),
                             _USB_BDT_BASE_ADDR_15to09_POS(index) ) << 9 );
}


//******************************************************************************
/* Function :  USB_BDTBaseAddressSet_Default

  Summary:
    Implements Default variant of PLIB_USB_BDTBaseAddressSet 

  Description:
    This template implements the Default variant of the PLIB_USB_BDTBaseAddressSet function.
*/

PLIB_TEMPLATE void USB_BDTBaseAddressSet_Default( USB_MODULE_ID index , void* address )
{
    _SFR_FIELD_WRITE(_USB_BDT_BASE_ADDR_31to24_VREG(index),
                     _USB_BDT_BASE_ADDR_31to24_MASK(index),
                     _USB_BDT_BASE_ADDR_31to24_POS(index) ,
                     0xFF&((uint32_t)address>>24)                  );

    _SFR_FIELD_WRITE(_USB_BDT_BASE_ADDR_23to16_VREG(index),
                     _USB_BDT_BASE_ADDR_23to16_MASK(index),
                     _USB_BDT_BASE_ADDR_23to16_POS(index) ,
                     0xFF&((uint32_t)address>>16)                   );

    _SFR_FIELD_WRITE(_USB_BDT_BASE_ADDR_15to09_VREG(index),
                     _USB_BDT_BASE_ADDR_15to09_MASK(index),
                     _USB_BDT_BASE_ADDR_15to09_POS(index) ,
                     0x7F&((uint32_t)address>>9)                   );
}


//******************************************************************************
/* Function :  USB_ExistsBDTBaseAddress_Default

  Summary:
    Implements Default variant of PLIB_USB_ExistsBDTBaseAddress

  Description:
    This template implements the Default variant of the PLIB_USB_ExistsBDTBaseAddress function.
*/

#define PLIB_USB_ExistsBDTBaseAddress PLIB_USB_ExistsBDTBaseAddress
PLIB_TEMPLATE bool USB_ExistsBDTBaseAddress_Default( USB_MODULE_ID index )
{
    return true;
}


#endif /*_USB_BDTBASEADDRESS_DEFAULT_H*/

/******************************************************************************
 End of File
*/

