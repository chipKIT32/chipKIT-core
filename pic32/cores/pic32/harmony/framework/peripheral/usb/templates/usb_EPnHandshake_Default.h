/*******************************************************************************
  USB Peripheral Library Template Implementation

  File Name:
    usb_EPnHandshake_Default.h

  Summary:
    USB PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : EPnHandshake
    and its Variant : Default
    For following APIs :
        PLIB_USB_EPnHandshakeEnable
        PLIB_USB_EPnHandshakeDisable
        PLIB_USB_ExistsEPnHandshake

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

#ifndef _USB_EPNHANDSHAKE_DEFAULT_H
#define _USB_EPNHANDSHAKE_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are

  VREGs:
    _USB_EP0_HANDSHAKE_ON_VREG(index)
    _USB_EP1_HANDSHAKE_ON_VREG(index)
    _USB_EP2_HANDSHAKE_ON_VREG(index)
    _USB_EP3_HANDSHAKE_ON_VREG(index)
    _USB_EP4_HANDSHAKE_ON_VREG(index)
    _USB_EP5_HANDSHAKE_ON_VREG(index)
    _USB_EP6_HANDSHAKE_ON_VREG(index)
    _USB_EP7_HANDSHAKE_ON_VREG(index)
    _USB_EP8_HANDSHAKE_ON_VREG(index)
    _USB_EP9_HANDSHAKE_ON_VREG(index)
    _USB_EP10_HANDSHAKE_ON_VREG(index)
    _USB_EP11_HANDSHAKE_ON_VREG(index)
    _USB_EP12_HANDSHAKE_ON_VREG(index)
    _USB_EP13_HANDSHAKE_ON_VREG(index)
    _USB_EP14_HANDSHAKE_ON_VREG(index)
    _USB_EP15_HANDSHAKE_ON_VREG(index)

  MASKs:
    _USB_EP0_HANDSHAKE_ON_MASK(index)
    _USB_EP1_HANDSHAKE_ON_MASK(index)
    _USB_EP2_HANDSHAKE_ON_MASK(index)
    _USB_EP3_HANDSHAKE_ON_MASK(index)
    _USB_EP4_HANDSHAKE_ON_MASK(index)
    _USB_EP5_HANDSHAKE_ON_MASK(index)
    _USB_EP6_HANDSHAKE_ON_MASK(index)
    _USB_EP7_HANDSHAKE_ON_MASK(index)
    _USB_EP8_HANDSHAKE_ON_MASK(index)
    _USB_EP9_HANDSHAKE_ON_MASK(index)
    _USB_EP10_HANDSHAKE_ON_MASK(index)
    _USB_EP11_HANDSHAKE_ON_MASK(index)
    _USB_EP12_HANDSHAKE_ON_MASK(index)
    _USB_EP13_HANDSHAKE_ON_MASK(index)
    _USB_EP14_HANDSHAKE_ON_MASK(index)
    _USB_EP15_HANDSHAKE_ON_MASK(index)

  POSs:
    _USB_EP0_HANDSHAKE_ON_POS(index)
    _USB_EP1_HANDSHAKE_ON_POS(index)
    _USB_EP2_HANDSHAKE_ON_POS(index)
    _USB_EP3_HANDSHAKE_ON_POS(index)
    _USB_EP4_HANDSHAKE_ON_POS(index)
    _USB_EP5_HANDSHAKE_ON_POS(index)
    _USB_EP6_HANDSHAKE_ON_POS(index)
    _USB_EP7_HANDSHAKE_ON_POS(index)
    _USB_EP8_HANDSHAKE_ON_POS(index)
    _USB_EP9_HANDSHAKE_ON_POS(index)
    _USB_EP10_HANDSHAKE_ON_POS(index)
    _USB_EP11_HANDSHAKE_ON_POS(index)
    _USB_EP12_HANDSHAKE_ON_POS(index)
    _USB_EP13_HANDSHAKE_ON_POS(index)
    _USB_EP14_HANDSHAKE_ON_POS(index)
    _USB_EP15_HANDSHAKE_ON_POS(index)

  LENs:
    _USB_EP0_HANDSHAKE_ON_LEN(index)
    _USB_EP1_HANDSHAKE_ON_LEN(index)
    _USB_EP2_HANDSHAKE_ON_LEN(index)
    _USB_EP3_HANDSHAKE_ON_LEN(index)
    _USB_EP4_HANDSHAKE_ON_LEN(index)
    _USB_EP5_HANDSHAKE_ON_LEN(index)
    _USB_EP6_HANDSHAKE_ON_LEN(index)
    _USB_EP7_HANDSHAKE_ON_LEN(index)
    _USB_EP8_HANDSHAKE_ON_LEN(index)
    _USB_EP9_HANDSHAKE_ON_LEN(index)
    _USB_EP10_HANDSHAKE_ON_LEN(index)
    _USB_EP11_HANDSHAKE_ON_LEN(index)
    _USB_EP12_HANDSHAKE_ON_LEN(index)
    _USB_EP13_HANDSHAKE_ON_LEN(index)
    _USB_EP14_HANDSHAKE_ON_LEN(index)
    _USB_EP15_HANDSHAKE_ON_LEN(index)

*/


//******************************************************************************
/* Function :  USB_EPnHandshakeEnable_Default

  Summary:
    Implements Default variant of PLIB_USB_EPnHandshakeEnable

  Description:
    This template implements the Default variant of the PLIB_USB_EPnHandshakeEnable function.
*/

PLIB_TEMPLATE void USB_EPnHandshakeEnable_Default( USB_MODULE_ID index , uint8_t epValue )
{
    switch ( epValue )
    {
        case 0:
            _SFR_BIT_SET(_USB_EP0_HANDSHAKE_ON_VREG(index),
                         _USB_EP0_HANDSHAKE_ON_POS(index) );
            break;

        case 1:
            _SFR_BIT_SET(_USB_EP1_HANDSHAKE_ON_VREG(index),
                         _USB_EP1_HANDSHAKE_ON_POS(index) );
            break;

        case 2:
            _SFR_BIT_SET(_USB_EP2_HANDSHAKE_ON_VREG(index),
                         _USB_EP2_HANDSHAKE_ON_POS(index) );
            break;

        case 3:
            _SFR_BIT_SET(_USB_EP3_HANDSHAKE_ON_VREG(index),
                         _USB_EP3_HANDSHAKE_ON_POS(index) );
            break;

        case 4:
            _SFR_BIT_SET(_USB_EP4_HANDSHAKE_ON_VREG(index),
                         _USB_EP4_HANDSHAKE_ON_POS(index) );
            break;

        case 5:
            _SFR_BIT_SET(_USB_EP5_HANDSHAKE_ON_VREG(index),
                         _USB_EP5_HANDSHAKE_ON_POS(index) );
            break;

        case 6:
            _SFR_BIT_SET(_USB_EP6_HANDSHAKE_ON_VREG(index),
                         _USB_EP6_HANDSHAKE_ON_POS(index) );
            break;

        case 7:
            _SFR_BIT_SET(_USB_EP7_HANDSHAKE_ON_VREG(index),
                         _USB_EP7_HANDSHAKE_ON_POS(index) );
            break;

        case 8:
            _SFR_BIT_SET(_USB_EP8_HANDSHAKE_ON_VREG(index),
                         _USB_EP8_HANDSHAKE_ON_POS(index) );
            break;

        case 9:
            _SFR_BIT_SET(_USB_EP9_HANDSHAKE_ON_VREG(index),
                         _USB_EP9_HANDSHAKE_ON_POS(index) );
            break;

        case 10:
            _SFR_BIT_SET(_USB_EP10_HANDSHAKE_ON_VREG(index),
                         _USB_EP10_HANDSHAKE_ON_POS(index) );
            break;

        case 11:
            _SFR_BIT_SET(_USB_EP11_HANDSHAKE_ON_VREG(index),
                         _USB_EP11_HANDSHAKE_ON_POS(index) );
            break;

        case 12:
            _SFR_BIT_SET(_USB_EP12_HANDSHAKE_ON_VREG(index),
                         _USB_EP12_HANDSHAKE_ON_POS(index) );
            break;

        case 13:
            _SFR_BIT_SET(_USB_EP13_HANDSHAKE_ON_VREG(index),
                         _USB_EP13_HANDSHAKE_ON_POS(index) );
            break;

        case 14:
            _SFR_BIT_SET(_USB_EP14_HANDSHAKE_ON_VREG(index),
                         _USB_EP14_HANDSHAKE_ON_POS(index) );
            break;

        case 15:
            _SFR_BIT_SET(_USB_EP15_HANDSHAKE_ON_VREG(index),
                         _USB_EP15_HANDSHAKE_ON_POS(index) );
            break;

        default:
            PLIB_ASSERT( 0, "In USB_EPnHandshakeEnable, unknown endpoint number." );
            break;

     }
}


//******************************************************************************
/* Function :  USB_EPnHandshakeDisable_Default

  Summary:
    Implements Default variant of PLIB_USB_EPnHandshakeDisable

  Description:
    This template implements the Default variant of the PLIB_USB_EPnHandshakeDisable function.
*/

PLIB_TEMPLATE void USB_EPnHandshakeDisable_Default( USB_MODULE_ID index , uint8_t epValue )
{
    switch ( epValue )
    {
        case 0:
            _SFR_BIT_CLEAR(_USB_EP0_HANDSHAKE_ON_VREG(index),
                           _USB_EP0_HANDSHAKE_ON_POS(index) );
            break;

        case 1:
            _SFR_BIT_CLEAR(_USB_EP1_HANDSHAKE_ON_VREG(index),
                           _USB_EP1_HANDSHAKE_ON_POS(index) );
            break;

        case 2:
            _SFR_BIT_CLEAR(_USB_EP2_HANDSHAKE_ON_VREG(index),
                           _USB_EP2_HANDSHAKE_ON_POS(index) );
            break;

        case 3:
            _SFR_BIT_CLEAR(_USB_EP3_HANDSHAKE_ON_VREG(index),
                           _USB_EP3_HANDSHAKE_ON_POS(index) );
            break;

        case 4:
            _SFR_BIT_CLEAR(_USB_EP4_HANDSHAKE_ON_VREG(index),
                           _USB_EP4_HANDSHAKE_ON_POS(index) );
            break;

        case 5:
            _SFR_BIT_CLEAR(_USB_EP5_HANDSHAKE_ON_VREG(index),
                           _USB_EP5_HANDSHAKE_ON_POS(index) );
            break;

        case 6:
            _SFR_BIT_CLEAR(_USB_EP6_HANDSHAKE_ON_VREG(index),
                           _USB_EP6_HANDSHAKE_ON_POS(index) );
            break;

        case 7:
            _SFR_BIT_CLEAR(_USB_EP7_HANDSHAKE_ON_VREG(index),
                           _USB_EP7_HANDSHAKE_ON_POS(index) );
            break;

        case 8:
            _SFR_BIT_CLEAR(_USB_EP8_HANDSHAKE_ON_VREG(index),
                           _USB_EP8_HANDSHAKE_ON_POS(index) );
            break;

        case 9:
            _SFR_BIT_CLEAR(_USB_EP9_HANDSHAKE_ON_VREG(index),
                           _USB_EP9_HANDSHAKE_ON_POS(index) );
            break;

        case 10:
            _SFR_BIT_CLEAR(_USB_EP10_HANDSHAKE_ON_VREG(index),
                           _USB_EP10_HANDSHAKE_ON_POS(index) );
            break;

        case 11:
            _SFR_BIT_CLEAR(_USB_EP11_HANDSHAKE_ON_VREG(index),
                           _USB_EP11_HANDSHAKE_ON_POS(index) );
            break;

        case 12:
            _SFR_BIT_CLEAR(_USB_EP12_HANDSHAKE_ON_VREG(index),
                           _USB_EP12_HANDSHAKE_ON_POS(index) );
            break;

        case 13:
            _SFR_BIT_CLEAR(_USB_EP13_HANDSHAKE_ON_VREG(index),
                           _USB_EP13_HANDSHAKE_ON_POS(index) );
            break;

        case 14:
            _SFR_BIT_CLEAR(_USB_EP14_HANDSHAKE_ON_VREG(index),
                           _USB_EP14_HANDSHAKE_ON_POS(index) );
            break;

        case 15:
            _SFR_BIT_CLEAR(_USB_EP15_HANDSHAKE_ON_VREG(index),
                           _USB_EP15_HANDSHAKE_ON_POS(index) );
            break;

        default:
            PLIB_ASSERT( 0, "In USB_EPnHandshakeDisable, unknown endpoint number." );
            break;

     }
}


//******************************************************************************
/* Function :  USB_ExistsEPnHandshake_Default

  Summary:
    Implements Default variant of PLIB_USB_ExistsEPnHandshake

  Description:
    This template implements the Default variant of the PLIB_USB_ExistsEPnHandshake function.
*/

#define PLIB_USB_ExistsEPnHandshake PLIB_USB_ExistsEPnHandshake
PLIB_TEMPLATE bool USB_ExistsEPnHandshake_Default( USB_MODULE_ID index )
{
    return true;
}


#endif /*_USB_EPNHANDSHAKE_DEFAULT_H*/

/******************************************************************************
 End of File
*/

