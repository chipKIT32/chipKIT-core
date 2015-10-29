/*******************************************************************************
  USBHS Peripheral Library Template Implementation

  File Name:
    usbhs_EndpointFIFO_Default.h

  Summary:
    USBHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : EndpointFIFO
    and its Variant : Default
    For following APIs :
        PLIB_USBHS_EndpointFIFOLoad
        PLIB_USBHS_EndpointFIFOUnload
        PLIB_USBHS_Endpoint0SetupPacketLoad
        PLIB_USBHS_ExistsEndpointFIFO

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _USBHS_ENDPOINTFIFO_DEFAULT_H
#define _USBHS_ENDPOINTFIFO_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _USBHS_FIFO_BASE_ADDRESS_VREG(index)
    _USBHS_ENDPOINT_BASE_ADDRESS_VREG(index)
    _USBHS_TARGET_CONTROL_BASE_ADDRESS_VREG(index)

  MASKs: 
    _USBHS_FIFO_BASE_ADDRESS_MASK(index)
    _USBHS_ENDPOINT_BASE_ADDRESS_MASK(index)
    _USBHS_TARGET_CONTROL_BASE_ADDRESS_MASK(index)

  POSs: 
    _USBHS_FIFO_BASE_ADDRESS_POS(index)
    _USBHS_ENDPOINT_BASE_ADDRESS_POS(index)
    _USBHS_TARGET_CONTROL_BASE_ADDRESS_POS(index)

  LENs: 
    _USBHS_FIFO_BASE_ADDRESS_LEN(index)
    _USBHS_ENDPOINT_BASE_ADDRESS_LEN(index)
    _USBHS_TARGET_CONTROL_BASE_ADDRESS_LEN(index)

*/

//******************************************************************************
/* Function :  USBHS_EndpointFIFOLoad_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EndpointFIFOLoad 

  Description:
    This template implements the Default variant of the PLIB_USBHS_EndpointFIFOLoad function.
*/

PLIB_TEMPLATE void USBHS_EndpointFIFOLoad_Default( USBHS_MODULE_ID index , 
        uint8_t endpoint , void * source , size_t nBytes )
{
    /* This function loads the FIFO and then
     * sends the packet */

    volatile uint8_t * fifo, * data, * ep0BaseAddress, txPacketReadyValue;
    size_t i;

    fifo = (uint8_t *)_USBHS_FIFO_BASE_ADDRESS_VREG(index);
    ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    fifo += (endpoint * 4);
    data = (uint8_t *) source;

    /* fifo now has the fifo address for this endpoint.
     * Now load the fifo with source data */

    for(i = 0; i < nBytes; i ++)
    {
        *fifo = *(data + i);
    }

    txPacketReadyValue = (endpoint == 0) ? 0x2 : 0x1;
    *(ep0BaseAddress + (endpoint * 0x10) + 2) |= txPacketReadyValue; 

}

//******************************************************************************
/* Function :  USBHS_DeviceEPFIFOLoad_Default

  Summary:
    Implements Default variant of PLIB_USBHS_DeviceEPFIFOLoad 

  Description:
    This template implements the Default variant of the PLIB_USBHS_DeviceEPFIFOLoad function.
*/

PLIB_TEMPLATE void USBHS_DeviceEPFIFOLoad_Default( USBHS_MODULE_ID index , 
        uint8_t endpoint , void * source , size_t nBytes )
{
    /* This function loads the FIFO */ 

    volatile uint8_t * fifo, * data;
    size_t i;

    fifo = (uint8_t *)_USBHS_FIFO_BASE_ADDRESS_VREG(index);
    fifo += (endpoint * 4);
    data = (uint8_t *) source;

    /* fifo now has the fifo address for this endpoint.
     * Now load the fifo with source data */

    for(i = 0; i < nBytes; i ++)
    {
        *fifo = *(data + i);
    }
}

//******************************************************************************
/* Function :  USBHS_EndpointFIFOUnload_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EndpointFIFOUnload 

  Description:
    This template implements the Default variant of the PLIB_USBHS_EndpointFIFOUnload function.
*/

PLIB_TEMPLATE int USBHS_EndpointFIFOUnload_Default( USBHS_MODULE_ID index , uint8_t endpoint , void * dest)
{
    /* This function unloads the FIFO and then
     * clears the rx packet ready bit */

    volatile uint8_t * fifo, * data, * ep0BaseAddress, offset;
    volatile unsigned int count;
    size_t i;

    fifo = (uint8_t *)_USBHS_FIFO_BASE_ADDRESS_VREG(index);
    ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    count = *((uint16_t*)(ep0BaseAddress + (endpoint * 0x10) + 0x8));
    fifo += (endpoint * 4);
    data = (uint8_t *) dest;

    /* fifo now has the fifo address for this endpoint.
     * Now unload the fifo into data */

    for(i = 0; i < count; i ++)
    {
        data[i] = *(fifo + (i & 3));
    }

    offset = (endpoint == 0) ? 0x2 : 0x6;
    *(ep0BaseAddress + (endpoint * 0x10) + offset) &= 0xFE;
    return(count);
}

//******************************************************************************
/* Function :  USBHS_DeviceEPFIFOUnload_Default

  Summary:
    Implements Default variant of PLIB_USBHS_DeviceEPFIFOUnload 

  Description:
    This template implements the Default variant of the PLIB_USBHS_DeviceEPFIFOUnload function.
*/

PLIB_TEMPLATE int USBHS_DeviceEPFIFOUnload_Default( USBHS_MODULE_ID index , uint8_t endpoint , void * dest)
{
    /* This function unloads the FIFO and then
     * clears the rx packet ready bit */

    volatile uint8_t * fifo, * data, * ep0BaseAddress;
    volatile unsigned int count;
    size_t i;

    fifo = (uint8_t *)_USBHS_FIFO_BASE_ADDRESS_VREG(index);
    ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    count = *((uint16_t*)(ep0BaseAddress + (endpoint * 0x10) + 0x8));
    fifo += (endpoint * 4);
    data = (uint8_t *) dest;

    /* fifo now has the fifo address for this endpoint.
     * Now unload the fifo into data */

    for(i = 0; i < count; i ++)
    {
        data[i] = *(fifo + (i & 3));
    }

    return(count);
}

//******************************************************************************
/* Function :  USBHS_Endpoint0SetupPacketLoad_Default

  Summary:
    Implements Default variant of PLIB_USBHS_Endpoint0SetupPacketLoad 

  Description:
    This template implements the Default variant of the PLIB_USBHS_Endpoint0SetupPacketLoad function.
*/

PLIB_TEMPLATE void USBHS_Endpoint0SetupPacketLoad_Default( USBHS_MODULE_ID index , void * setupPacket , 
        uint8_t deviceAddress , uint8_t hubAddress , uint8_t hubPortAddress , uint32_t speed )
{
    volatile uint8_t * fifo, * ep0BaseAddress;
    volatile uint8_t * data, speedConstant, *ep0TargetAddress;
    unsigned int i;

    data = (uint8_t *)setupPacket;
    ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    ep0TargetAddress = (uint8_t *)_USBHS_TARGET_CONTROL_BASE_ADDRESS_VREG(index);
    fifo = (uint8_t *)_USBHS_FIFO_BASE_ADDRESS_VREG(index);

    if(speed == 4)
    {
        speedConstant = 1;
    }
    else if(speed == 2)
    {
        speedConstant = 2;
    }
    else if (speed == 1)
    {
        speedConstant = 3;
    }

    for(i = 0; i < 8; i++)
    {
        *fifo = *(data + i);
    }

    *ep0TargetAddress = deviceAddress;
    *(ep0TargetAddress + 2) = hubAddress;
    *(ep0TargetAddress + 3) = hubPortAddress;
    *(ep0BaseAddress + 0xA) = (speedConstant << 6);
    *(ep0BaseAddress + 0x2) |= 0x0A; 

}
//******************************************************************************
/* Function :  USBHS_Endpoint0SetupPacketUnload_Default

  Summary:
    Implements Default variant of PLIB_USBHS_Endpoint0SetupPacketUnload 

  Description:
    This template implements the Default variant of the PLIB_USBHS_Endpoint0SetupPacketUnload function.
*/

PLIB_TEMPLATE void USBHS_Endpoint0SetupPacketUnload_Default( USBHS_MODULE_ID index, void * dest )
{
    /* Unloads a setup packet from endpoint 0 fifo */
    volatile uint8_t * fifo = (uint8_t *)_USBHS_FIFO_BASE_ADDRESS_VREG(index);
    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    uint8_t * data = (uint8_t *)dest;
    *((uint32_t *)(data)) = *((uint32_t *)(fifo));
    *((uint32_t *)(data + 4)) = *((uint32_t *)(fifo));
    *(ep0BaseAddress + 0x2) = 0x40;
}

//******************************************************************************
/* Function :  USBHS_Endpoint0FIFOFlush_Default

  Summary:
    Implements Default variant of PLIB_USBHS_Endpoint0FIFOFlush 

  Description:
    This template implements the Default variant of the PLIB_USBHS_Endpoint0FIFOFlush function.
*/

PLIB_TEMPLATE void USBHS_Endpoint0FIFOFlush_Default( USBHS_MODULE_ID index )
{
    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    uint8_t status;

    status = *(ep0BaseAddress + 0x2); 

    /* Check if transmit packet ready or if the
     * receive packet ready is set. If so then
     * clear the flush */

    if((status & 0x1) || (status & 0x2))
    {
        *(ep0BaseAddress + 0x3) |= 0x1;
    }
}

//******************************************************************************
/* Function :  USBHS_EndpointTxFIFOFlush_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EndpointTxFIFOFlush 

  Description:
    This template implements the Default variant of the PLIB_USBHS_EndpointTxFIFOFlush function.
*/

PLIB_TEMPLATE void USBHS_EndpointTxFIFOFlush_Default( USBHS_MODULE_ID index, uint8_t endpoint )
{
    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    uint8_t status;

    status = *(ep0BaseAddress + (endpoint * 0x10) + 2);
    if(status & 0x1)
    {
        /* This means that the TX Packet Request is set. We can
         * flush the FIFO */

        *(ep0BaseAddress + (endpoint * 0x10) + 2) |= 0x8;
    }
}

//******************************************************************************
/* Function :  USBHS_EndpointRxFIFOFlush_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EndpointRxFIFOFlush 

  Description:
    This template implements the Default variant of the PLIB_USBHS_EndpointRxFIFOFlush function.
*/

PLIB_TEMPLATE void USBHS_EndpointRxFIFOFlush_Default( USBHS_MODULE_ID index, uint8_t endpoint )
{
    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    uint8_t status;

    status = *(ep0BaseAddress + (endpoint * 0x10) + 6);
    if(status & 0x1)
    {
        /* This means that the RX Packet Request is set. We can
         * flush the FIFO */

        *(ep0BaseAddress + (endpoint * 0x10) + 2) |= 0x10;
    }
}

//******************************************************************************
/* Function :  USBHS_ExistsEndpointFIFO_Default

  Summary:
    Implements Default variant of PLIB_USBHS_ExistsEndpointFIFO

  Description:
    This template implements the Default variant of the PLIB_USBHS_ExistsEndpointFIFO function.
*/

#define PLIB_USBHS_ExistsEndpointFIFO PLIB_USBHS_ExistsEndpointFIFO
PLIB_TEMPLATE bool USBHS_ExistsEndpointFIFO_Default( USBHS_MODULE_ID index )
{
    return true;
}


#endif /*_USBHS_ENDPOINTFIFO_DEFAULT_H*/

/******************************************************************************
 End of File
*/

