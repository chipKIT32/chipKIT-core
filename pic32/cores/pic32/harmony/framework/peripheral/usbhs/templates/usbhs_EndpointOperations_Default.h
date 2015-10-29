/*******************************************************************************
  USBHS Peripheral Library Template Implementation

  File Name:
    usbhs_EndpointOperations_Default.h

  Summary:
    USBHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : EndpointOperations
    and its Variant : Default
    For following APIs :
        PLIB_USBHS_EndpointRxRequestEnable
        PLIB_USBHS_EndpointRxRequestClear
        PLIB_USBHS_HostRxEndpointConfigure
        PLIB_USBHS_HostTxEndpointConfigure
        PLIB_USBHS_HostTxEndpointDataToggleClear
        PLIB_USBHS_HostRxEndpointDataToggleClear
        PLIB_USBHS_DeviceRxEndpointConfigure
        PLIB_USBHS_DeviceTxEndpointConfigure
        PLIB_USBHS_DeviceRxEndpointStallEnable
        PLIB_USBHS_DeviceTxEndpointStallEnable
        PLIB_USBHS_DeviceRxEndpointStallDisable
        PLIB_USBHS_DeviceTxEndpointStallDisable
        PLIB_USBHS_DeviceTxEndpointPacketReady
        PLIB_USBHS_ExistsEndpointOperations

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _USBHS_ENDPOINTOPERATIONS_DEFAULT_H
#define _USBHS_ENDPOINTOPERATIONS_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _USBHS_BASE_ADDRESS_VREG(index)
    _USBHS_ENDPOINT_BASE_ADDRESS_VREG(index)

  MASKs: 
    _USBHS_BASE_ADDRESS_MASK(index)
    _USBHS_ENDPOINT_BASE_ADDRESS_MASK(index)

  POSs: 
    _USBHS_BASE_ADDRESS_POS(index)
    _USBHS_ENDPOINT_BASE_ADDRESS_POS(index)

  LENs: 
    _USBHS_BASE_ADDRESS_LEN(index)
    _USBHS_ENDPOINT_BASE_ADDRESS_LEN(index)

*/


//******************************************************************************
/* Function :  USBHS_EndpointRxRequestEnable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EndpointRxRequestEnable 

  Description:
    This template implements the Default variant of the PLIB_USBHS_EndpointRxRequestEnable function.
*/

PLIB_TEMPLATE void USBHS_EndpointRxRequestEnable_Default( USBHS_MODULE_ID index , uint8_t endpoint )
{
    /* Sets the Receive Packet Request bit causing an 
     * IN endpoint to send an IN token */

    volatile uint8_t * endpoint0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    *(endpoint0BaseAddress + (endpoint * 0x10) + 0x6) |= 0x20;

}

//******************************************************************************
/* Function :  USBHS_EndpointRxRequestClear_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EndpointRxRequestClear 

  Description:
    This template implements the Default variant of the PLIB_USBHS_EndpointRxRequestClear function.
*/

PLIB_TEMPLATE void USBHS_EndpointRxRequestClear_Default( USBHS_MODULE_ID index , uint8_t endpoint )
{
    /* Sets the Receive Packet Request bit causing an 
     * IN endpoint to send an IN token */

    volatile uint8_t * endpoint0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    *(endpoint0BaseAddress + (endpoint * 0x10) + 0x6) &= 0xDF;

}


//******************************************************************************
/* Function :  USBHS_HostRxEndpointConfigure_Default

  Summary:
    Implements Default variant of PLIB_USBHS_HostRxEndpointConfigure 

  Description:
    This template implements the Default variant of the PLIB_USBHS_HostRxEndpointConfigure function.
*/

PLIB_TEMPLATE void USBHS_HostRxEndpointConfigure_Default
( 
    USBHS_MODULE_ID index , 
    uint8_t hostEndpoint , 
    uint32_t speed , 
    uint32_t pipeType , 
    uint16_t endpointSize , 
    uint16_t receiveFIFOAddress , 
    uint8_t fifoSize , 
    uint8_t  targetEndpoint , 
    uint8_t  targetDevice , 
    uint8_t  targetHub , 
    uint8_t  targetHubPort, 
    uint8_t nakInterval 
)
{
    /* This function sets up the endpoint size, receive FIFO address,
     * receive FIFO size, pipe type, speed, target endpoint, target device
     * target hub and target hub port for host receive endpoint. This
     * function is called by the driver pipe setup function. This function
     * also clears up the receive fifo if there is any stale data, nak interval
     * and then finally enables the interrupt */

    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
    uint8_t moduleSpeed;
    uint8_t indexBackup;

    /* Backup the index register and set it to the
     * host endpoint that is to be configured */

    indexBackup = *(usbBaseAddress + 0x0E);
    *(usbBaseAddress +0xE) = hostEndpoint;

    /* Convert the speed to the module speed */
    if(4 == speed) { moduleSpeed = 1 ;}
    else if(2 == speed) { moduleSpeed = 2; }
    else { moduleSpeed = 3; }

    /* Setup the endpoint size */
    *((uint16_t *)(usbBaseAddress + 0x14)) = endpointSize;

    /* Setup the receive fifo address */
    *((uint16_t *)(usbBaseAddress + 0x66)) = receiveFIFOAddress;

    /* Setup the receive FIFO size */
    *(usbBaseAddress + 0x63) = fifoSize;

    /* Setup the pipe type, speed and target endpoint */
    *(usbBaseAddress + 0x1C) = (( moduleSpeed << 6) | (pipeType << 4) | (targetEndpoint));

    /* Setup device address */
    *(usbBaseAddress + (0x84 + (8 * hostEndpoint))) = targetDevice;

    /* Setup target Hub address */
    *(usbBaseAddress + (0x86 + (8 * hostEndpoint))) = targetHub;

    /* Setup target Hub port */
    *(usbBaseAddress + (0x87 + (8 * hostEndpoint))) = targetHubPort;

    /* Clear the data toggle if it is set */
    *(usbBaseAddress + 0x16) |= 0x80;

    /* If there is stale data in the fifo, then flush the fifo */

    if(*(usbBaseAddress + 0x16) & 0x1)
    {
        /* Flush the fifo */
        *(usbBaseAddress + 0x16) |= 0x10;
    }

    /* For bulk pipes setup up the NAK interval and
     * for interrupt pipes set up the transaction 
     * interval */

    *(usbBaseAddress + 0x1D) = nakInterval;

    /* Enable the RX endpoint interrupt */
    *(usbBaseAddress + 0x8) |= (1 << hostEndpoint);

    /* Restore the index register before exiting */
    *(usbBaseAddress + 0xE) = indexBackup;

}


//******************************************************************************
/* Function :  USBHS_HostTxEndpointConfigure_Default

  Summary:
    Implements Default variant of PLIB_USBHS_HostTxEndpointConfigure 

  Description:
    This template implements the Default variant of the PLIB_USBHS_HostTxEndpointConfigure function.
*/

PLIB_TEMPLATE void USBHS_HostTxEndpointConfigure_Default
(
    USBHS_MODULE_ID index , 
    uint8_t hostEndpoint , 
    uint32_t speed , 
    uint32_t pipeType , 
    uint16_t endpointSize , 
    uint16_t receiveFIFOAddress , 
    uint8_t  fifoSize , 
    uint8_t  targetEndpoint , 
    uint8_t  targetDevice , 
    uint8_t  targetHub , 
    uint8_t  targetHubPort,
    uint8_t  nakInterval
)
{
    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
    uint8_t moduleSpeed;
    uint8_t indexBackup;

    /* Backup the index register and set it to the
     * host endpoint that is to be configured */

    indexBackup = *(usbBaseAddress + 0x0E);
    *(usbBaseAddress +0xE) = hostEndpoint;

    /* Convert the speed to the module speed */
    if(4 == speed) { moduleSpeed = 1 ;}
    else if(2 == speed) { moduleSpeed = 2; }
    else { moduleSpeed = 3; }

    /* Setup the endpoint size */
    *((uint16_t *)(usbBaseAddress + 0x10)) = endpointSize;

    /* Setup the transmit fifo address */
    *((uint16_t *)(usbBaseAddress + 0x64)) = receiveFIFOAddress;

    /* Setup the transmit FIFO size */
    *(usbBaseAddress + 0x62) = fifoSize;
 
    /* Setup the pipe type, speed and target endpoint */
    *(usbBaseAddress + 0x1A) = (( moduleSpeed << 6) | (pipeType << 4) | (targetEndpoint));

    /* Setup device address */
    *(usbBaseAddress + (0x80 + (8 * hostEndpoint))) = targetDevice;

    /* Setup target Hub address */
    *(usbBaseAddress + (0x82 + (8 * hostEndpoint))) = targetHub;

    /* Setup target Hub port */
    *(usbBaseAddress + (0x83 + (8 * hostEndpoint))) = targetHubPort;

    /* Clear the data toggle if it is set */
    *(usbBaseAddress + 0x12) |= 0x40;

    /* If there is stale data in the fifo, then flush the fifo */

    if(*(usbBaseAddress + 0x12) & 0x2)
    {
        /* Flush the fifo */
        *(usbBaseAddress + 0x12) |= 0x08;
    }

    /* For bulk pipes setup up the NAK interval and
     * for interrupt pipes set up the transaction 
     * interval */

    *(usbBaseAddress + 0x1B) = nakInterval;

    /* Enable the RX endpoint interrupt */
    *(usbBaseAddress + 0x6) |= (1 << hostEndpoint);

    /* Restore the index register before exiting */
    *(usbBaseAddress + 0xE) = indexBackup;


}


//******************************************************************************
/* Function :  USBHS_HostTxEndpointDataToggleClear_Default

  Summary:
    Implements Default variant of PLIB_USBHS_HostTxEndpointDataToggleClear 

  Description:
    This template implements the Default variant of the PLIB_USBHS_HostTxEndpointDataToggleClear function.
*/

PLIB_TEMPLATE void USBHS_HostTxEndpointDataToggleClear_Default( USBHS_MODULE_ID index , uint8_t hostEndpoint )
{
	volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    *(ep0BaseAddress + (hostEndpoint * 0x10) + 0x2) |= 0x40;
}


//******************************************************************************
/* Function :  USBHS_HostRxEndpointDataToggleClear_Default

  Summary:
    Implements Default variant of PLIB_USBHS_HostRxEndpointDataToggleClear 

  Description:
    This template implements the Default variant of the PLIB_USBHS_HostRxEndpointDataToggleClear function.
*/

PLIB_TEMPLATE void USBHS_HostRxEndpointDataToggleClear_Default( USBHS_MODULE_ID index , uint8_t hostEndpoint )
{
	volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    *(ep0BaseAddress + (hostEndpoint * 0x10) + 0x6) |= 0x80;
}


//******************************************************************************
/* Function :  USBHS_DeviceTxEndpointConfigure_Default

  Summary:
    Implements Default variant of PLIB_USBHS_DeviceTxEndpointConfigure 

  Description:
    This template implements the Default variant of the PLIB_USBHS_DeviceTxEndpointConfigure function.
*/

PLIB_TEMPLATE void USBHS_DeviceTxEndpointConfigure_Default
(
    USBHS_MODULE_ID index,
    uint8_t endpoint,
    uint16_t endpointSize,
    uint16_t fifoAddress,
    uint8_t fifoSize,
    uint32_t transferType
)
{
    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
    uint8_t indexBackup;

    /* This function configure the TX endpoint for device mode
     * operation. Start by setting up the index register */

    indexBackup = *(usbBaseAddress + 0xE);
    *(usbBaseAddress + 0xE) = endpoint;

    /* Configure the Endpoint size */
    *((unsigned short int * )(usbBaseAddress + 0x10)) = endpointSize;

    /* Set up the fifo address */
    *((unsigned short int * )(usbBaseAddress + 0x64)) = fifoAddress;

    /* Clear the data toggle */
    *(usbBaseAddress + 0x12) |= 0x40;

    /* Set up the FIFO size */
    *(usbBaseAddress + 0x62) = fifoSize;

    if(1 == transferType)
    {
        /* Enable ISOC operation */
        *(usbBaseAddress + 0x13) |= 0x40;
    }
    else
    {
        /* Enable handshake */
        *(usbBaseAddress + 0x13) &= 0xBF;
    }

    /* Restore the index register */
    *(usbBaseAddress + 0xE) = indexBackup;

    /* Enable the interrupt */
    *(usbBaseAddress + 0x6) |= (1 << endpoint);
}

//******************************************************************************
/* Function :  USBHS_DeviceRxEndpointConfigure_Default

  Summary:
    Implements Default variant of PLIB_USBHS_DeviceTxEndpointConfigure 

  Description:
    This template implements the Default variant of the PLIB_USBHS_DeviceTxEndpointConfigure function.
*/

PLIB_TEMPLATE void USBHS_DeviceRxEndpointConfigure_Default
(
    USBHS_MODULE_ID index,
    uint8_t endpoint,
    uint16_t endpointSize,
    uint16_t fifoAddress,
    uint8_t fifoSize,
    uint32_t transferType
)
{
    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
    uint8_t indexBackup;

    /* This function configures the RX endpoint for device mode
     * operation. Start by setting up the index register */

    indexBackup = *(usbBaseAddress + 0xE);
    *(usbBaseAddress + 0xE) = endpoint;

    /* Configure the Endpoint size */
    *((unsigned short int * )(usbBaseAddress + 0x14)) = endpointSize;

    /* Set up the fifo address */
    *((unsigned short int * )(usbBaseAddress + 0x66)) = fifoAddress;

    /* Clear the data toggle */
    *(usbBaseAddress + 0x16) |= 0x80;

    /* Set up the FIFO size */
    *(usbBaseAddress + 0x63) = fifoSize;

    if(transferType == 1)
    {
        /* For Isochronous endpoints, handshaking must
         * be disabled*/

        *(usbBaseAddress + 0x17) |= 0x40;

    }
    else if(transferType == 3)
    {
        /* For interrupt endpoints, handshaking must
         * be enabled by NYET should be disabled */

        *(usbBaseAddress + 0x17) |= 0x10;
        *(usbBaseAddress + 0x17) &= 0xBF;
        
    }
    else
    {
        /* For bulk endpoints, handshaking must
         * enabled and NYET should be enabled */

        *(usbBaseAddress + 0x17) &= 0xAF;
    }

    /* Restore the index register */
    *(usbBaseAddress + 0xE) = indexBackup;

    /* Enable the endpoint interrupt */
    *(usbBaseAddress + 0x8) |= (1 << endpoint);

}

//******************************************************************************
/* Function :  USBHS_DeviceRxEndpointStallEnable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_DeviceTxEndpointStallEnable 

  Description:
    This template implements the Default variant of the PLIB_USBHS_DeviceTxEndpointStallEnable function.
*/

PLIB_TEMPLATE void USBHS_DeviceRxEndpointStallEnable_Default(USBHS_MODULE_ID index, uint8_t endpoint)
{
    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    *(ep0BaseAddress + (endpoint * 0x10) + 0x6) |= 0x20;
}

//******************************************************************************
/* Function :  USBHS_DeviceTxEndpointStallEnable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_DeviceTxEndpointStallEnable 

  Description:
    This template implements the Default variant of the PLIB_USBHS_DeviceTxEndpointStallEnable function.
*/

PLIB_TEMPLATE void USBHS_DeviceTxEndpointStallEnable_Default(USBHS_MODULE_ID index, uint8_t endpoint)
{
    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    *(ep0BaseAddress + (endpoint * 0x10) + 0x2) |= 0x10;
}

//******************************************************************************
/* Function :  USBHS_DeviceRxEndpointStallDisable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_DeviceTxEndpointStallDisable 

  Description:
    This template implements the Default variant of the PLIB_USBHS_DeviceTxEndpointStallDisable function.
*/

PLIB_TEMPLATE void USBHS_DeviceRxEndpointStallDisable_Default(USBHS_MODULE_ID index, uint8_t endpoint)
{
    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    *(ep0BaseAddress + (endpoint * 0x10) + 0x6) &= 0x9F;
    *(ep0BaseAddress + (endpoint * 0x10) + 0x6) |= 0x80;
}

//******************************************************************************
/* Function :  USBHS_DeviceTxEndpointStallDisable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_DeviceTxEndpointStallDisable 

  Description:
    This template implements the Default variant of the PLIB_USBHS_DeviceTxEndpointStallDisable function.
*/

PLIB_TEMPLATE void USBHS_DeviceTxEndpointStallDisable_Default(USBHS_MODULE_ID index, uint8_t endpoint)
{
    /* Disable the stall and reset the data toggle */
    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    *(ep0BaseAddress + (endpoint * 0x10) + 0x2) &= 0xCF;
    *(ep0BaseAddress + (endpoint * 0x10) + 0x2) |= 0x40;
}

//******************************************************************************
/* Function :  USBHS_DeviceTxEndpointPacketReady_Default

  Summary:
    Implements Default variant of PLIB_USBHS_DeviceTxEndpointPacketReady 

  Description:
    This template implements the Default variant of the PLIB_USBHS_DeviceTxEndpointPacketReady function.
*/

PLIB_TEMPLATE void USBHS_DeviceTxEndpointPacketReady_Default(USBHS_MODULE_ID index, uint8_t endpoint)
{
    /* Disable the stall and reset the data toggle */
    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    *(ep0BaseAddress + (endpoint * 0x10) + 0x2) |= 0x1;
}


//******************************************************************************
/* Function :  USBHS_ExistsEndpointOperations_Default

  Summary:
    Implements Default variant of PLIB_USBHS_ExistsEndpointOperations

  Description:
    This template implements the Default variant of the PLIB_USBHS_ExistsEndpointOperations function.
*/

#define PLIB_USBHS_ExistsEndpointOperations PLIB_USBHS_ExistsEndpointOperations
PLIB_TEMPLATE bool USBHS_ExistsEndpointOperations_Default( USBHS_MODULE_ID index )
{
    return true;
}


#endif /*_USBHS_ENDPOINTOPERATIONS_DEFAULT_H*/

/******************************************************************************
 End of File
*/

