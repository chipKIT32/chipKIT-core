/*******************************************************************************
  USB Peripheral Library Template Implementation

  File Name:
    usb_EPnRxEnableEnhanced_PIC32.h

  Summary:
    USB PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : EPnRxEnableEnhanced
    and its Variant : PIC32
    For following APIs :
        PLIB_USB_EPnRxEnable
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

#ifndef _USB_EPNRXENABLEENHANCED_PIC32_H
#define _USB_EPNRXENABLEENHANCED_PIC32_H

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
/* Function :  USB_EPnRxEnable_PIC32

  Summary:
    Implements PIC32 variant of PLIB_USB_EPnRxEnable 

  Description:
    This template implements the PIC32 variant of the PLIB_USB_EPnRxEnable function.
*/

PLIB_TEMPLATE void USB_EPnRxEnable_PIC32( USB_MODULE_ID index , uint8_t endpoint )
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    epControlRegister += (4 * endpoint);
    epControlRegister += 2; // This is endpoint set register
    *epControlRegister = 0x8; // The 4th bit is the RX enable bit


}
//******************************************************************************
/* Function :  USB_EPnRxDisable_PIC32

  Summary:
    Implements PIC32 variant of PLIB_USB_EPnRxDisable 

  Description:
    This template implements the PIC32 variant of the PLIB_USB_EPnRxDisable function.
*/

PLIB_TEMPLATE void USB_EPnRxDisable_PIC32( USB_MODULE_ID index , uint8_t endpoint )
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    epControlRegister += (4 * endpoint);
    epControlRegister += 1; // This is endpoint clear register
    *epControlRegister = 0x8; // The 4th bit is the RX enable/disable bit

}

//******************************************************************************
/* Function :  USB_EPnTxEnable_PIC32

  Summary:
    Implements PIC32 variant of PLIB_USB_EPnTxEnable 

  Description:
    This template implements the PIC32 variant of the PLIB_USB_EPnTxEnable function.
*/

PLIB_TEMPLATE void USB_EPnTxEnable_PIC32( USB_MODULE_ID index , uint8_t endpoint )
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    epControlRegister += (4 * endpoint);
    epControlRegister += 2; // This is endpoint set register
    *epControlRegister = 0x4; // The 3rd bit is the TX enable bit


}

//******************************************************************************
/* Function :  USB_EPnTxDisable_PIC32

  Summary:
    Implements PIC32 variant of PLIB_USB_EPnTxDisable 

  Description:
    This template implements the PIC32 variant of the PLIB_USB_EPnTxDisable function.
*/

PLIB_TEMPLATE void USB_EPnTxDisable_PIC32( USB_MODULE_ID index , uint8_t endpoint )
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    epControlRegister += (4 * endpoint);
    epControlRegister += 1; // This is endpoint clear register
    *epControlRegister = 0x4; // The 3rd bit is the TX enable/disable bit

}

//******************************************************************************
/* Function :  USB_EPnHandshakeEnable_PIC32

  Summary:
    Implements PIC32 variant of PLIB_USB_EPnTxEnable 

  Description:
    This template implements the PIC32 variant of the PLIB_USB_EPnTxEnable function.
*/

PLIB_TEMPLATE void USB_EPnHandshakeEnable_PIC32( USB_MODULE_ID index , uint8_t endpoint )
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    epControlRegister += (4 * endpoint);
    epControlRegister += 2; // This is endpoint set register
    *epControlRegister = 0x1; // Bit 0 is the handshake enable bit


}

//******************************************************************************
/* Function :  USB_EPnTxDisable_PIC32

  Summary:
    Implements PIC32 variant of PLIB_USB_EPnTxDisable 

  Description:
    This template implements the PIC32 variant of the PLIB_USB_EPnTxDisable function.
*/

PLIB_TEMPLATE void USB_EPnHandshakeDisable_PIC32( USB_MODULE_ID index , uint8_t endpoint )
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    epControlRegister += (4 * endpoint);
    epControlRegister += 1; // This is endpoint clear register
    *epControlRegister = 0x1; // Bit 0 is the handshake enable/disable bit

}

//******************************************************************************
/* Function :  USB_EPnControlTransferEnable_PIC32

  Summary:
    Implements PIC32 variant of PLIB_USB_EPnControlTransferEnable 

  Description:
    This template implements the PIC32 variant of the PLIB_USB_EPnControlTransferEnable 
    function.
*/

PLIB_TEMPLATE void USB_EPnControlTransferEnable_PIC32( USB_MODULE_ID index , uint8_t endpoint )
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    epControlRegister += (4 * endpoint);

    /* Clearing the bit enables control transfer support on the endpoint */

    *(epControlRegister + 1) = 0x10; // Bit 4 is the control transfer enable bit

    /* Also enable the TX and RX direction */

    *(epControlRegister + 2) = 0xC;


}

PLIB_TEMPLATE void USB_EPnAttributesSet_PIC32(USB_MODULE_ID index, 
        uint8_t endpoint, int direction, bool isControl, bool handshake)
{
    volatile SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    unsigned int handshake_pos = _U1EP0_EPHSHK_POSITION;
    unsigned int epcondif_pos  = _U1EP0_EPCONDIS_POSITION;
    unsigned int rx_enable_pos = _U1EP0_EPRXEN_POSITION;
    unsigned int tx_enable_pos = _U1EP0_EPTXEN_POSITION;

    epControlRegister += (4 * endpoint);
    if(isControl)
    {
        *epControlRegister &= ~(1 << epcondif_pos); //Reset EPCONDIS
        *epControlRegister |=  (1 << rx_enable_pos); //Set TX
        *epControlRegister |=  (1 << tx_enable_pos); //Set RX
        *epControlRegister |=  (1 << handshake_pos); //Set HANDSHAKE
        return;
    }
    
    /* Set the direction */
    if(direction)
    {
       *epControlRegister  |= (1 << tx_enable_pos);
    }
    else
    {
        *epControlRegister |= (1 << rx_enable_pos);
    }

    if(handshake)
    {
        *epControlRegister |= (1 << handshake_pos);
    }
    else
    {
        *epControlRegister &= ~(1 << handshake_pos);
    }
}

PLIB_TEMPLATE void USB_EPnAttributesClear_PIC32(USB_MODULE_ID index, uint8_t endpoint)
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    epControlRegister += (4 * endpoint);

    /* This clears the EP Control register */
    *(epControlRegister + 1) = 0xD;

    /* Disable SETUP packet handling. */

    *(epControlRegister + 2) = 0x10;
}

PLIB_TEMPLATE void USB_EPnDirectionDisable_PIC32(USB_MODULE_ID index, 
                                            uint8_t endpoint, int direction)
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    epControlRegister += (4 * endpoint);

    /* Clear the direction */
    *(epControlRegister + 1) = 0x8 >> direction;

}

//******************************************************************************
/* Function :  USB_EPnControlTransferDisable_PIC32

  Summary:
    Implements PIC32 variant of PLIB_USB_EPnControlTransferDisable 

  Description:
    This template implements the PIC32 variant of the PLIB_USB_EPnControlTransferDisable function.
*/

PLIB_TEMPLATE void USB_EPnControlTransferDisable_PIC32( USB_MODULE_ID index , uint8_t endpoint )
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    epControlRegister += (4 * endpoint);

    /* Setting the bit disables control transfer support on the endpoint */
    
    epControlRegister += 2; // This is endpoint set register
    *epControlRegister = 0x10; // Bit 4 is the control transfer enable/disable bit

}

//******************************************************************************
/* Function :  USB_EPnIsStalled_PIC32

  Summary:
    Implements PIC32 variant of PLIB_USB_EPnIsStalled 

  Description:
    This template implements the PIC32 variant of the PLIB_USB_EPnIsStalled 
    function.
*/

PLIB_TEMPLATE bool USB_EPnIsStalled_PIC32( USB_MODULE_ID index , uint8_t endpoint )
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    epControlRegister += (4 * endpoint);

    /* Bit 1 is the stall indicator */
    return(((*epControlRegister) & 0x2) ? true : false);
}

//******************************************************************************
/* Function :  USB_EPnStallClear_PIC32

  Summary:
    Implements PIC32 variant of PLIB_USB_EPnStallClear 

  Description:
    This template implements the PIC32 variant of the PLIB_USB_EPnStallClear 
    function.
*/

PLIB_TEMPLATE void USB_EPnStallClear_PIC32( USB_MODULE_ID index , uint8_t endpoint )
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);
    epControlRegister += (4 * endpoint);
    *epControlRegister &= 0xFD;


}


PLIB_TEMPLATE void USB_EP0HostSetup_PIC32(USB_MODULE_ID index)
{
    SFR_TYPE * epControlRegister = _USB_EP0_RCV_ON_VREG(index);

    /* Set up endpoint 0 for typical host operation.
     * Enable Transmit, Receive, Control Transfers, Handshake
     * Disable NAK Retry and Low speed connect */

    *epControlRegister = 0x4D;
}

//******************************************************************************
/* Function :  USB_ExistsEPnRxEnable_PIC32

  Summary:
    Implements PIC32 variant of PLIB_USB_ExistsEPnRxEnable

  Description:
    This template implements the PIC32 variant of the PLIB_USB_ExistsEPnRxEnable function.
*/

#define PLIB_USB_ExistsEPnRxEnable PLIB_USB_ExistsEPnRxEnable
PLIB_TEMPLATE bool USB_ExistsEPnRxEnable_PIC32( USB_MODULE_ID index )
{
    return true;
}


#endif /*_USB_EPNRXENABLEENHANCED_PIC32_H*/

/******************************************************************************
 End of File
*/

