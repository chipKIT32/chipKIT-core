/*******************************************************************************
  USB Peripheral Library Template Implementation

  File Name:
    usb_EPnRxEnableEnhanced_PIC18.h

  Summary:
    USB PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : EPnRxEnableEnhanced
    and its Variant : PIC18
    For following APIs :
        PLIB_USB_EPnRxEnable
        PLIB_USB_EPnRxDisable
        PLIB_USB_EPnTxEnable
        PLIB_USB_EPnTxDisable
        PLIB_USB_EPnHandshakeEnable
        PLIB_USB_EPnHandshakeDisable
        PLIB_USB_EPnControlTransferEnable
        PLIB_USB_EPnControlTransferDisable
        PLIB_USB_EPnIsStalled
        PLIB_USB_EPnStallClear
        PLIB_USB_ExistsEPnRxEnable

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


#ifndef _USB_EPNRXENABLEENHANCED_PIC18_H
#define _USB_EPNRXENABLEENHANCED_PIC18_H


//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _USB_EP0_RCV_ON_VREG(index)
    _USB_EP0_XMIT_ON_EN_VREG(index)

  MASKs: 
    _USB_EP0_RCV_ON_MASK(index)
    _USB_EP0_XMIT_ON_EN_MASK(index)

  POSs: 
    _USB_EP0_RCV_ON_POS(index)
    _USB_EP0_XMIT_ON_EN_POS(index)

  LENs: 
    _USB_EP0_RCV_ON_LEN(index)
    _USB_EP0_XMIT_ON_EN_LEN(index)

*/


//******************************************************************************
/* Function :  USB_EPnRxEnable_PIC18

  Summary:
    Implements PIC18 variant of PLIB_USB_EPnRxEnable 

  Description:
    This template implements the PIC18 variant of the PLIB_USB_EPnRxEnable function.
*/

PLIB_TEMPLATE void USB_EPnRxEnable_PIC18( USB_MODULE_ID index , uint8_t endpoint )
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    epControlRegister += (1 * endpoint);

    *epControlRegister = *epControlRegister | 0x02; // The 2nd bit is the RX/IN enable bit
}


//******************************************************************************
/* Function :  USB_EPnRxDisable_PIC18

  Summary:
    Implements PIC18 variant of PLIB_USB_EPnRxDisable 

  Description:
    This template implements the PIC18 variant of the PLIB_USB_EPnRxDisable function.
*/

PLIB_TEMPLATE void USB_EPnRxDisable_PIC18( USB_MODULE_ID index , uint8_t endpoint )
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    epControlRegister += (1 * endpoint);

    *epControlRegister = *epControlRegister & ~0x02; // The 2nd bit is the RX/IN enable bit
}


//******************************************************************************
/* Function :  USB_EPnTxEnable_PIC18

  Summary:
    Implements PIC18 variant of PLIB_USB_EPnTxEnable 

  Description:
    This template implements the PIC18 variant of the PLIB_USB_EPnTxEnable function.
*/

PLIB_TEMPLATE void USB_EPnTxEnable_PIC18( USB_MODULE_ID index , uint8_t endpoint )
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    epControlRegister += (1 * endpoint);

    *epControlRegister = *epControlRegister | 0x04; // The 3rd bit is the TX/OUT enable bit
}


//******************************************************************************
/* Function :  USB_EPnTxDisable_PIC18

  Summary:
    Implements PIC18 variant of PLIB_USB_EPnTxDisable 

  Description:
    This template implements the PIC18 variant of the PLIB_USB_EPnTxDisable function.
*/

PLIB_TEMPLATE void USB_EPnTxDisable_PIC18( USB_MODULE_ID index , uint8_t endpoint )
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    epControlRegister += (1 * endpoint);

    *epControlRegister = *epControlRegister & ~0x04; // The 3rd bit is the TX/OUT enable bit
}


//******************************************************************************
/* Function :  USB_EPnHandshakeEnable_PIC18

  Summary:
    Implements PIC18 variant of PLIB_USB_EPnHandshakeEnable 

  Description:
    This template implements the PIC18 variant of the PLIB_USB_EPnHandshakeEnable function.
*/

PLIB_TEMPLATE void USB_EPnHandshakeEnable_PIC18( USB_MODULE_ID index , uint8_t endpoint )
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    epControlRegister += (1 * endpoint);

    *epControlRegister = *epControlRegister | 0x10; // The 5th bit is the HSHK enable bit
}


//******************************************************************************
/* Function :  USB_EPnHandshakeDisable_PIC18

  Summary:
    Implements PIC18 variant of PLIB_USB_EPnHandshakeDisable 

  Description:
    This template implements the PIC18 variant of the PLIB_USB_EPnHandshakeDisable function.
*/

PLIB_TEMPLATE void USB_EPnHandshakeDisable_PIC18( USB_MODULE_ID index , uint8_t endpoint )
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    epControlRegister += (1 * endpoint);

    *epControlRegister = *epControlRegister & ~0x10; // The 5th bit is the HSHK enable bit
}


//******************************************************************************
/* Function :  USB_EPnControlTransferEnable_PIC18

  Summary:
    Implements PIC18 variant of PLIB_USB_EPnControlTransferEnable 

  Description:
    This template implements the PIC18 variant of the PLIB_USB_EPnControlTransferEnable function.
*/

PLIB_TEMPLATE void USB_EPnControlTransferEnable_PIC18( USB_MODULE_ID index , uint8_t endpoint )
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    epControlRegister += (1 * endpoint);

    /* Clearing the bit enables control transfer support on the endpoint */
    *epControlRegister = *epControlRegister & ~0x08; // The 4th bit is the CT enable bit
}


//******************************************************************************
/* Function :  USB_EPnControlTransferDisable_PIC18

  Summary:
    Implements PIC18 variant of PLIB_USB_EPnControlTransferDisable 

  Description:
    This template implements the PIC18 variant of the PLIB_USB_EPnControlTransferDisable function.
*/

PLIB_TEMPLATE void USB_EPnControlTransferDisable_PIC18( USB_MODULE_ID index , uint8_t endpoint )
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    epControlRegister += (1 * endpoint);

    /* Setting the bit disables control transfer support on the endpoint */
    *epControlRegister = *epControlRegister | 0x08; // The 4th bit is the CT enable bit
}


//******************************************************************************
/* Function :  USB_EPnIsStalled_PIC18

  Summary:
    Implements PIC18 variant of PLIB_USB_EPnIsStalled 

  Description:
    This template implements the PIC18 variant of the PLIB_USB_EPnIsStalled function.
*/

PLIB_TEMPLATE bool USB_EPnIsStalled_PIC18( USB_MODULE_ID index , uint8_t endpoint )
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    epControlRegister += (1 * endpoint);

    /* Bit 1 is the stall indicator */
    return( ( ( * epControlRegister ) & 0x01 ) ? true : false );
}


//******************************************************************************
/* Function :  USB_EPnStallClear_PIC18

  Summary:
    Implements PIC18 variant of PLIB_USB_EPnStallClear 

  Description:
    This template implements the PIC18 variant of the PLIB_USB_EPnStallClear function.
*/

PLIB_TEMPLATE void USB_EPnStallClear_PIC18( USB_MODULE_ID index , uint8_t endpoint )
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    epControlRegister += (1 * endpoint);
    *epControlRegister = *epControlRegister & ~0x01; // The 1st bit is the STALL enable bit
}


//******************************************************************************
/* Function :  USB_ExistsEPnRxEnable_PIC18

  Summary:
    Implements PIC18 variant of PLIB_USB_ExistsEPnRxEnable

  Description:
    This template implements the PIC18 variant of the PLIB_USB_ExistsEPnRxEnable function.
*/

#define PLIB_USB_ExistsEPnRxEnable PLIB_USB_ExistsEPnRxEnable
PLIB_TEMPLATE bool USB_ExistsEPnRxEnable_PIC18( USB_MODULE_ID index )
{
    return true;
}


#endif /*_USB_EPNRXENABLEENHANCED_PIC18_H*/

/******************************************************************************
 End of File
*/

