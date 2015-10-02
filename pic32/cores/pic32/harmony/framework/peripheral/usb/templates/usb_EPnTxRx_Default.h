/*******************************************************************************
  USB Peripheral Library Template Implementation

  File Name:
    usb_EPnTxRx_Default.h

  Summary:
    USB PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : EPnTxRx
    and its Variant : Default
    For following APIs :
        PLIB_USB_EPnTxSelect
        PLIB_USB_EPnRxSelect
        PLIB_USB_EPnTxRxSelect
        PLIB_USB_ExistsEPnTxRx

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

#ifndef _USB_EPNTXRX_DEFAULT_H
#define _USB_EPNTXRX_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are

  VREGs:
    _USB_EP0_RCV_ON_VREG(index)
    _USB_EP0_XMIT_ON_VREG(index)
    _USB_EP1_RCV_ON_VREG(index)
    _USB_EP1_XMIT_ON_VREG(index)
    _USB_EP2_RCV_ON_VREG(index)
    _USB_EP2_XMIT_ON_VREG(index)
    _USB_EP3_RCV_ON_VREG(index)
    _USB_EP3_XMIT_ON_VREG(index)
    _USB_EP4_RCV_ON_VREG(index)
    _USB_EP4_XMIT_ON_VREG(index)
    _USB_EP5_RCV_ON_VREG(index)
    _USB_EP5_XMIT_ON_VREG(index)
    _USB_EP6_RCV_ON_VREG(index)
    _USB_EP6_XMIT_ON_VREG(index)
    _USB_EP7_RCV_ON_VREG(index)
    _USB_EP7_XMIT_ON_VREG(index)
    _USB_EP8_RCV_ON_VREG(index)
    _USB_EP8_XMIT_ON_VREG(index)
    _USB_EP9_RCV_ON_VREG(index)
    _USB_EP9_XMIT_ON_VREG(index)
    _USB_EP10_RCV_ON_VREG(index)
    _USB_EP10_XMIT_ON_VREG(index)
    _USB_EP11_RCV_ON_VREG(index)
    _USB_EP11_XMIT_ON_VREG(index)
    _USB_EP12_RCV_ON_VREG(index)
    _USB_EP12_XMIT_ON_VREG(index)
    _USB_EP13_RCV_ON_VREG(index)
    _USB_EP13_XMIT_ON_VREG(index)
    _USB_EP14_RCV_ON_VREG(index)
    _USB_EP14_XMIT_ON_VREG(index)
    _USB_EP15_RCV_ON_VREG(index)
    _USB_EP15_XMIT_ON_VREG(index)

  MASKs:
    _USB_EP0_RCV_ON_MASK(index)
    _USB_EP0_XMIT_ON_MASK(index)
    _USB_EP1_RCV_ON_MASK(index)
    _USB_EP1_XMIT_ON_MASK(index)
    _USB_EP2_RCV_ON_MASK(index)
    _USB_EP2_XMIT_ON_MASK(index)
    _USB_EP3_RCV_ON_MASK(index)
    _USB_EP3_XMIT_ON_MASK(index)
    _USB_EP4_RCV_ON_MASK(index)
    _USB_EP4_XMIT_ON_MASK(index)
    _USB_EP5_RCV_ON_MASK(index)
    _USB_EP5_XMIT_ON_MASK(index)
    _USB_EP6_RCV_ON_MASK(index)
    _USB_EP6_XMIT_ON_MASK(index)
    _USB_EP7_RCV_ON_MASK(index)
    _USB_EP7_XMIT_ON_MASK(index)
    _USB_EP8_RCV_ON_MASK(index)
    _USB_EP8_XMIT_ON_MASK(index)
    _USB_EP9_RCV_ON_MASK(index)
    _USB_EP9_XMIT_ON_MASK(index)
    _USB_EP10_RCV_ON_MASK(index)
    _USB_EP10_XMIT_ON_MASK(index)
    _USB_EP11_RCV_ON_MASK(index)
    _USB_EP11_XMIT_ON_MASK(index)
    _USB_EP12_RCV_ON_MASK(index)
    _USB_EP12_XMIT_ON_MASK(index)
    _USB_EP13_RCV_ON_MASK(index)
    _USB_EP13_XMIT_ON_MASK(index)
    _USB_EP14_RCV_ON_MASK(index)
    _USB_EP14_XMIT_ON_MASK(index)
    _USB_EP15_RCV_ON_MASK(index)
    _USB_EP15_XMIT_ON_MASK(index)

  POSs:
    _USB_EP0_RCV_ON_POS(index)
    _USB_EP0_XMIT_ON_POS(index)
    _USB_EP1_RCV_ON_POS(index)
    _USB_EP1_XMIT_ON_POS(index)
    _USB_EP2_RCV_ON_POS(index)
    _USB_EP2_XMIT_ON_POS(index)
    _USB_EP3_RCV_ON_POS(index)
    _USB_EP3_XMIT_ON_POS(index)
    _USB_EP4_RCV_ON_POS(index)
    _USB_EP4_XMIT_ON_POS(index)
    _USB_EP5_RCV_ON_POS(index)
    _USB_EP5_XMIT_ON_POS(index)
    _USB_EP6_RCV_ON_POS(index)
    _USB_EP6_XMIT_ON_POS(index)
    _USB_EP7_RCV_ON_POS(index)
    _USB_EP7_XMIT_ON_POS(index)
    _USB_EP8_RCV_ON_POS(index)
    _USB_EP8_XMIT_ON_POS(index)
    _USB_EP9_RCV_ON_POS(index)
    _USB_EP9_XMIT_ON_POS(index)
    _USB_EP10_RCV_ON_POS(index)
    _USB_EP10_XMIT_ON_POS(index)
    _USB_EP11_RCV_ON_POS(index)
    _USB_EP11_XMIT_ON_POS(index)
    _USB_EP12_RCV_ON_POS(index)
    _USB_EP12_XMIT_ON_POS(index)
    _USB_EP13_RCV_ON_POS(index)
    _USB_EP13_XMIT_ON_POS(index)
    _USB_EP14_RCV_ON_POS(index)
    _USB_EP14_XMIT_ON_POS(index)
    _USB_EP15_RCV_ON_POS(index)
    _USB_EP15_XMIT_ON_POS(index)

  LENs:
    _USB_EP0_RCV_ON_LEN(index)
    _USB_EP0_XMIT_ON_LEN(index)
    _USB_EP1_RCV_ON_LEN(index)
    _USB_EP1_XMIT_ON_LEN(index)
    _USB_EP2_RCV_ON_LEN(index)
    _USB_EP2_XMIT_ON_LEN(index)
    _USB_EP3_RCV_ON_LEN(index)
    _USB_EP3_XMIT_ON_LEN(index)
    _USB_EP4_RCV_ON_LEN(index)
The pins are double-bonded to general purpose I/O in Mansfield and later parts. They are not double-bonded in Charlotte and earlier parts.

Thank you D.C.
Eric

    _USB_EP4_XMIT_ON_LEN(index)
    _USB_EP5_RCV_ON_LEN(index)
    _USB_EP5_XMIT_ON_LEN(index)
    _USB_EP6_RCV_ON_LEN(index)
    _USB_EP6_XMIT_ON_LEN(index)
    _USB_EP7_RCV_ON_LEN(index)
    _USB_EP7_XMIT_ON_LEN(index)
    _USB_EP8_RCV_ON_LEN(index)
    _USB_EP8_XMIT_ON_LEN(index)
    _USB_EP9_RCV_ON_LEN(index)
    _USB_EP9_XMIT_ON_LEN(index)
    _USB_EP10_RCV_ON_LEN(index)
    _USB_EP10_XMIT_ON_LEN(index)
    _USB_EP11_RCV_ON_LEN(index)
    _USB_EP11_XMIT_ON_LEN(index)
    _USB_EP12_RCV_ON_LEN(index)
    _USB_EP12_XMIT_ON_LEN(index)
    _USB_EP13_RCV_ON_LEN(index)
    _USB_EP13_XMIT_ON_LEN(index)
    _USB_EP14_RCV_ON_LEN(index)
    _USB_EP14_XMIT_ON_LEN(index)
    _USB_EP15_RCV_ON_LEN(index)
    _USB_EP15_XMIT_ON_LEN(index)

*/


//******************************************************************************
/* Function :  USB_EPnTxSelect_Default

  Summary:
    Implements Default variant of PLIB_USB_EPnTxSelect

  Description:
    This template implements the Default variant of the PLIB_USB_EPnTxSelect function.
*/

PLIB_TEMPLATE void USB_EPnTxSelect_Default( USB_MODULE_ID index , uint8_t epValue , USB_EP_TXRX epTxRx )
{
    bool xmitOn;

    switch ( epTxRx )
    {
        case USB_EP_NOTXRX:
            xmitOn = false;
            break;

        case USB_EP_RX:
            xmitOn = false;
            break;

        case USB_EP_TX:
            xmitOn = true;
            break;

        case USB_EP_TX_RX:
            xmitOn = true;
            break;

        default:
            PLIB_ASSERT( 0, "In USB_EPnTxSelect, unknown epXmitRcv value." );
            break;
    }

    switch ( epValue )
    {
        case 0:
            _SFR_BIT_WRITE(_USB_EP0_XMIT_ON_VREG(index),
                           _USB_EP0_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 1:
            _SFR_BIT_WRITE(_USB_EP1_XMIT_ON_VREG(index),
                           _USB_EP1_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 2:
            _SFR_BIT_WRITE(_USB_EP2_XMIT_ON_VREG(index),
                           _USB_EP2_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 3:
            _SFR_BIT_WRITE(_USB_EP3_XMIT_ON_VREG(index),
                           _USB_EP3_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 4:
            _SFR_BIT_WRITE(_USB_EP4_XMIT_ON_VREG(index),
                           _USB_EP4_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 5:
            _SFR_BIT_WRITE(_USB_EP5_XMIT_ON_VREG(index),
                           _USB_EP5_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 6:
            _SFR_BIT_WRITE(_USB_EP6_XMIT_ON_VREG(index),
                           _USB_EP6_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 7:
            _SFR_BIT_WRITE(_USB_EP7_XMIT_ON_VREG(index),
                           _USB_EP7_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 8:
            _SFR_BIT_WRITE(_USB_EP8_XMIT_ON_VREG(index),
                           _USB_EP8_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 9:
            _SFR_BIT_WRITE(_USB_EP9_XMIT_ON_VREG(index),
                           _USB_EP9_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 10:
            _SFR_BIT_WRITE(_USB_EP10_XMIT_ON_VREG(index),
                           _USB_EP10_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 11:
            _SFR_BIT_WRITE(_USB_EP11_XMIT_ON_VREG(index),
                           _USB_EP11_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 12:
            _SFR_BIT_WRITE(_USB_EP12_XMIT_ON_VREG(index),
                           _USB_EP12_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 13:
            _SFR_BIT_WRITE(_USB_EP13_XMIT_ON_VREG(index),
                           _USB_EP13_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 14:
            _SFR_BIT_WRITE(_USB_EP14_XMIT_ON_VREG(index),
                           _USB_EP14_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 15:
            _SFR_BIT_WRITE(_USB_EP15_XMIT_ON_VREG(index),
                           _USB_EP15_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        default:
            PLIB_ASSERT( 0, "In USB_EPnTxSelect, unknown endpoint number." );
            break;

     }
}


//******************************************************************************
/* Function :  USB_EPnRxSelect_Default

  Summary:
    Implements Default variant of PLIB_USB_EPnRxSelect

  Description:
    This template implements the Default variant of the PLIB_USB_EPnRxSelect function.
*/

PLIB_TEMPLATE void USB_EPnRxSelect_Default( USB_MODULE_ID index , uint8_t epValue , USB_EP_TXRX epTxRx )
{
    bool rcvOn;

    switch ( epTxRx )
    {
        case USB_EP_NOTXRX:
            rcvOn  = false;
            break;

        case USB_EP_RX:
            rcvOn  = true;
            break;

        case USB_EP_TX:
            rcvOn  = false;
            break;

        case USB_EP_TX_RX:
            rcvOn  = true;
            break;

        default:
            PLIB_ASSERT( 0, "In USB_EPnRxSelect, unknown epXmitRcv value." );
            break;
    }

    switch ( epValue )
    {
        case 0:
            _SFR_BIT_WRITE(_USB_EP0_RCV_ON_VREG(index),
                           _USB_EP0_RCV_ON_POS(index) ,
                           rcvOn);
            break;

        case 1:
            _SFR_BIT_WRITE(_USB_EP1_RCV_ON_VREG(index),
                           _USB_EP1_RCV_ON_POS(index) ,
                           rcvOn);
            break;

        case 2:
            _SFR_BIT_WRITE(_USB_EP2_RCV_ON_VREG(index),
                           _USB_EP2_RCV_ON_POS(index) ,
                           rcvOn);
            break;

        case 3:
            _SFR_BIT_WRITE(_USB_EP3_RCV_ON_VREG(index),
                           _USB_EP3_RCV_ON_POS(index) ,
                           rcvOn);
            break;

        case 4:
            _SFR_BIT_WRITE(_USB_EP4_RCV_ON_VREG(index),
                           _USB_EP4_RCV_ON_POS(index) ,
                           rcvOn);
            break;

        case 5:
            _SFR_BIT_WRITE(_USB_EP5_RCV_ON_VREG(index),
                           _USB_EP5_RCV_ON_POS(index) ,
                           rcvOn);
            break;

        case 6:
            _SFR_BIT_WRITE(_USB_EP6_RCV_ON_VREG(index),
                           _USB_EP6_RCV_ON_POS(index) ,
                           rcvOn);
            break;

        case 7:
            _SFR_BIT_WRITE(_USB_EP7_RCV_ON_VREG(index),
                           _USB_EP7_RCV_ON_POS(index) ,
                           rcvOn);
            break;

        case 8:
            _SFR_BIT_WRITE(_USB_EP8_RCV_ON_VREG(index),
                           _USB_EP8_RCV_ON_POS(index) ,
                           rcvOn);
            break;

        case 9:
            _SFR_BIT_WRITE(_USB_EP9_RCV_ON_VREG(index),
                           _USB_EP9_RCV_ON_POS(index) ,
                           rcvOn);
            break;

        case 10:
            _SFR_BIT_WRITE(_USB_EP10_RCV_ON_VREG(index),
                           _USB_EP10_RCV_ON_POS(index) ,
                           rcvOn);
            break;

        case 11:
            _SFR_BIT_WRITE(_USB_EP11_RCV_ON_VREG(index),
                           _USB_EP11_RCV_ON_POS(index) ,
                           rcvOn);
            break;

        case 12:
            _SFR_BIT_WRITE(_USB_EP12_RCV_ON_VREG(index),
                           _USB_EP12_RCV_ON_POS(index) ,
                           rcvOn);
            break;

        case 13:
            _SFR_BIT_WRITE(_USB_EP13_RCV_ON_VREG(index),
                           _USB_EP13_RCV_ON_POS(index) ,
                           rcvOn);
            break;

        case 14:
            _SFR_BIT_WRITE(_USB_EP14_RCV_ON_VREG(index),
                           _USB_EP14_RCV_ON_POS(index) ,
                           rcvOn);
            break;

        case 15:
            _SFR_BIT_WRITE(_USB_EP15_RCV_ON_VREG(index),
                           _USB_EP15_RCV_ON_POS(index) ,
                           rcvOn);
            break;

        default:
            PLIB_ASSERT( 0, "In USB_EPnRxSelect, unknown endpoint number." );
            break;

     }
}


//******************************************************************************
/* Function :  USB_EPnTxRxSelect_Default

  Summary:
    Implements Default variant of PLIB_USB_EPnTxRxSelect

  Description:
    This template implements the Default variant of the PLIB_USB_EPnTxRxSelect function.
*/

PLIB_TEMPLATE void USB_EPnTxRxSelect_Default( USB_MODULE_ID index , uint8_t epValue , USB_EP_TXRX epTxRx )
{
    bool xmitOn, rcvOn;

    switch ( epTxRx )
    {
        case USB_EP_NOTXRX:
            xmitOn = false;
            rcvOn  = false;
            break;

        case USB_EP_RX:
            xmitOn = false;
            rcvOn  = true;
            break;

        case USB_EP_TX:
            xmitOn = true;
            rcvOn  = false;
            break;

        case USB_EP_TX_RX:
            xmitOn = true;
            rcvOn  = true;
            break;

        default:
            PLIB_ASSERT( 0, "In USB_EPnTxRxSelect, unknown epXmitRcv value." );
            break;
    }

    switch ( epValue )
    {
        case 0:
            _SFR_BIT_WRITE(_USB_EP0_RCV_ON_VREG(index),
                           _USB_EP0_RCV_ON_POS(index) ,
                           rcvOn);
            _SFR_BIT_WRITE(_USB_EP0_XMIT_ON_VREG(index),
                           _USB_EP0_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 1:
            _SFR_BIT_WRITE(_USB_EP1_RCV_ON_VREG(index),
                           _USB_EP1_RCV_ON_POS(index) ,
                           rcvOn);
            _SFR_BIT_WRITE(_USB_EP1_XMIT_ON_VREG(index),
                           _USB_EP1_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 2:
            _SFR_BIT_WRITE(_USB_EP2_RCV_ON_VREG(index),
                           _USB_EP2_RCV_ON_POS(index) ,
                           rcvOn);
            _SFR_BIT_WRITE(_USB_EP2_XMIT_ON_VREG(index),
                           _USB_EP2_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 3:
            _SFR_BIT_WRITE(_USB_EP3_RCV_ON_VREG(index),
                           _USB_EP3_RCV_ON_POS(index) ,
                           rcvOn);
            _SFR_BIT_WRITE(_USB_EP3_XMIT_ON_VREG(index),
                           _USB_EP3_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 4:
            _SFR_BIT_WRITE(_USB_EP4_RCV_ON_VREG(index),
                           _USB_EP4_RCV_ON_POS(index) ,
                           rcvOn);
            _SFR_BIT_WRITE(_USB_EP4_XMIT_ON_VREG(index),
                           _USB_EP4_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 5:
            _SFR_BIT_WRITE(_USB_EP5_RCV_ON_VREG(index),
                           _USB_EP5_RCV_ON_POS(index) ,
                           rcvOn);
            _SFR_BIT_WRITE(_USB_EP5_XMIT_ON_VREG(index),
                           _USB_EP5_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 6:
            _SFR_BIT_WRITE(_USB_EP6_RCV_ON_VREG(index),
                           _USB_EP6_RCV_ON_POS(index) ,
                           rcvOn);

            _SFR_BIT_WRITE(_USB_EP6_XMIT_ON_VREG(index),
                           _USB_EP6_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 7:
            _SFR_BIT_WRITE(_USB_EP7_RCV_ON_VREG(index),
                           _USB_EP7_RCV_ON_POS(index) ,
                           rcvOn);
            _SFR_BIT_WRITE(_USB_EP7_XMIT_ON_VREG(index),
                           _USB_EP7_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 8:
            _SFR_BIT_WRITE(_USB_EP8_RCV_ON_VREG(index),
                           _USB_EP8_RCV_ON_POS(index) ,
                           rcvOn);
            _SFR_BIT_WRITE(_USB_EP8_XMIT_ON_VREG(index),
                           _USB_EP8_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 9:
            _SFR_BIT_WRITE(_USB_EP9_RCV_ON_VREG(index),
                           _USB_EP9_RCV_ON_POS(index) ,
                           rcvOn);
            _SFR_BIT_WRITE(_USB_EP9_XMIT_ON_VREG(index),
                           _USB_EP9_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 10:
            _SFR_BIT_WRITE(_USB_EP10_RCV_ON_VREG(index),
                           _USB_EP10_RCV_ON_POS(index) ,
                           rcvOn);
            _SFR_BIT_WRITE(_USB_EP10_XMIT_ON_VREG(index),
                           _USB_EP10_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 11:
            _SFR_BIT_WRITE(_USB_EP11_RCV_ON_VREG(index),
                           _USB_EP11_RCV_ON_POS(index) ,
                           rcvOn);

            _SFR_BIT_WRITE(_USB_EP11_XMIT_ON_VREG(index),
                           _USB_EP11_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 12:
            _SFR_BIT_WRITE(_USB_EP12_RCV_ON_VREG(index),
                           _USB_EP12_RCV_ON_POS(index) ,
                           rcvOn);
            _SFR_BIT_WRITE(_USB_EP12_XMIT_ON_VREG(index),
                           _USB_EP12_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 13:
            _SFR_BIT_WRITE(_USB_EP13_RCV_ON_VREG(index),
                           _USB_EP13_RCV_ON_POS(index) ,
                           rcvOn);
            _SFR_BIT_WRITE(_USB_EP13_XMIT_ON_VREG(index),
                           _USB_EP13_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 14:
            _SFR_BIT_WRITE(_USB_EP14_RCV_ON_VREG(index),
                           _USB_EP14_RCV_ON_POS(index) ,
                           rcvOn);
            _SFR_BIT_WRITE(_USB_EP14_XMIT_ON_VREG(index),
                           _USB_EP14_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        case 15:
            _SFR_BIT_WRITE(_USB_EP15_RCV_ON_VREG(index),
                           _USB_EP15_RCV_ON_POS(index) ,
                           rcvOn);
            _SFR_BIT_WRITE(_USB_EP15_XMIT_ON_VREG(index),
                           _USB_EP15_XMIT_ON_POS(index) ,
                           xmitOn);
            break;

        default:
            PLIB_ASSERT( 0, "In USB_EPnTxRxSelect, unknown endpoint number." );
            break;

     }
}


//******************************************************************************
/* Function :  USB_ExistsEPnTxRx_Default

  Summary:
    Implements Default variant of PLIB_USB_ExistsEPnTxRx

  Description:
    This template implements the Default variant of the PLIB_USB_ExistsEPnTxRx function.
*/

#define PLIB_USB_ExistsEPnTxRx PLIB_USB_ExistsEPnTxRx
PLIB_TEMPLATE bool USB_ExistsEPnTxRx_Default( USB_MODULE_ID index )
{
    return true;
}


#endif /*_USB_EPNTXRX_DEFAULT_H*/

/******************************************************************************
 End of File
*/

