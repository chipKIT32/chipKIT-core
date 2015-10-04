/*******************************************************************************
  USB Peripheral Library Template Implementation

  File Name:
    usb_BDTFunctions_PIC18.h

  Summary:
    Peripheral library functions in support of USB Buffer Descriptor Table

  Description:
    This file contains implementations of:

      USB_BufferIndexGet - Gets index into Buffer Descriptor Table entries

      USB_BufferAddressGet - Gets the memory address of an endpoint buffer

      USB_BufferAddressSet - Sets endpoint buffer address

      USB_BufferByteCountGet - Returns endpoint buffer byte count

      USB_BufferByteCountSet - Sets the buffer byte count

      USB_BufferDataToggleGet -
         Returns data synchronization (DATA0 or DATA1) for the endpoint buffer

      USB_BufferDataToggleSelect - Sets endpoint buffer to DATA0 or DATA1

      USB_BufferDataToggleSyncDisable -
              Disables DATA0/DATA1 synchronization between the device and host

      USB_BufferDataToggleSyncEnable -
                Enables DATA0/DATA1 synchronization between the device and host

      USB_BufferPIDGet - Returns token PID from endpoint buffer status

      USB_BufferReleasedToSW -
                Returns "true" when buffer has been released by the USB module.

      USB_BufferReleaseToUSB -
                 Releases endpoint buffer, allowing USB module access to buffer

      USB_BufferCancelReleaseToUSB -
                 Cancels release of endpoint buffer, allowing SW to access buffer

      USB_BufferStallDisable -
                   Enables STALL handshaking for the associated endpoint buffer

      USB_BufferStallEnable -
                   Enables STALL handshaking for the associated endpoint buffer

      USB_BufferPIDBitsClear - Clears status field in BDT

*******************************************************************************/

// DOM-IGNORE-BEGIN

/*******************************************************************************
Copyright (c) <year> released Microchip Technology Inc.  All rights reserved.

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
// DOM-IGNORE-END


#ifndef _USB_BDTFUNCTIONS_PIC18F_H
#define _USB_BDTFUNCTIONS_PIC18F_H


#define ConvertToPhysicalAddress( a )   ( ( unsigned short int )( a ) )
#define ConvertToVirtualAddress( a )    ( ( void * )( a ) )


// *****************************************************************************
/* Buffer Status Layout for PIC18.

  Summary:
    Provides C structure equivalence to lower 8 bits of Buffer Descriptor.

  Description:
    This union provides C structure equivalence to lower 8 bits of Buffer
    Descriptor.

    Software To Hardware Fields: (Writable by software, not readable)
<pre><c>
        stallEnable
        dataToggleSyncEnable
</c></pre>
    On read these fields are replaced by:
<pre><c>
        packetID
</c></pre>

    With keepBDForever = 1, the USB module will keep the Buffer Descriptor and
    buffer defined by bufferAddress forever once usbOwnsBuffer = 1.  The USB
    status FIFO will not be updated nor will a Token Processing Complete
    interrupt fire.

    Writable and Readable (Software to Hardware and Hardware to Software):
<pre><c>
        dataToggle
        usbOwnsBuffer
</c></pre>

    When usbOwnsBuffer = 1 the USB module controls the Buffer Descriptor (BD)
    and the data buffer that bufferAddress points to.  The software cannot
    modify any of this.  When usbOwnsBuffer = 0 the software owns the BD and
    buffer.  The USB module ignores all fields except usbOwnsBuffer, waiting
    for software to set this bit again after setting up the descriptor and
    buffer again.

    The usbOwnsBuffer should be assigned the correct initial value prior to
    enabling the associated endpoint.

*/

typedef union
{
    struct
    {
        uint8_t byteCount_8          :1; //bit 8 of the byte count
        uint8_t byteCount_9          :1; //bit 9 of the byte count
        uint8_t stallEnable          :1; //Buffer Stall Enable
        uint8_t dataToggleSyncEnable :1; //Data Toggle Synch Enable
        uint8_t                      :1; //Reserved
        uint8_t                      :1; //Reserved
        uint8_t dataToggle           :1; //Data Toggle Synch Value
        uint8_t usbOwnsBuffer        :1; //USB Ownership
    };

    struct
    {
        uint8_t byteCount_89         :2;
        uint8_t packetID             :4; //Packet Identifier (PID)
        uint8_t                      :2;
    };

    uint8_t bValue; // Byte value

} USB_STATUS;


// *****************************************************************************
/* Buffer Descriptor Table Entry for PIC18

  Summary:
    Provides C structure equivalence to each entry in the Buffer Descriptor
    Table (BDT).

  Description:
    This union provides C structure equivalence to each entry in the Buffer
    Descriptor Table (BDT).

    Each Endpoint has four entries in the Buffer Descriptor Table (BDT), in the
    following order:
<pre><c>
        EndPoint Receive Even
        EndPoint Receive Odd
        EndPoint Transmit Even
        EndPoint Transmit Odd
</c></pre>

    The Buffer Descriptor Table (BDT) is build by
  <code>
    //                                           (Even,Odd) or (Ping,Pong)
    //                                               (Rx,Tx) |
    //                             (EP0     to      EPn)  |  |
    volatile USB_BDT_ENTRY USB_BDT[(USB_MAX_EP_USED + 1)][2][2] __attribute__ (( aligned (512) ));
  </code>
    for the case that all Endpoint buffers are ping-pong buffered:
  <code>
    USB_PingPongSelect(MY_USB_INSTANCE,USB_PING_PONG__FULL_PING_PONG);
  </code>
    Other cases require a more complicated indexing scheme.

    Note: <c>USB_MAX_EP_USED</c> is defined in a configuration header.
*/

union USB_BDT_ENTRY_TAG
{
    struct
    {
        USB_STATUS bufferStatus;  //Buffer Status
        uint8_t    byteCountLSB;  //Byte Count Least Significant Byte, Bits <7:0>
        uint16_t   bufferAddress; //Buffer Address
    };
    
    struct
    {
        uint8_t :8;
        uint8_t :8;
        uint8_t bufferAddressLo;          //Buffer Address Low
        uint8_t bufferAddressHi;          //Buffer Address High
    };
    
    uint32_t lValue;        //Long  integer values
    uint16_t sValue[2];     //Short integer values
    uint8_t  bValue[4];     //Byte values
};


// *****************************************************************************
/* Pointer to Buffer Descriptor Table Entry

  Summary:
    Pointer to BDT Entry.

  Description:
    Pointer to BDT Entry.

  Remarks:
    None.
*/

typedef union USB_BDT_ENTRY_TAG * pUSB_BDT_ENTRY;


static short USB_BDTIndexGet ( USB_PING_PONG_MODE   ppMode,
                               uint8_t              epValue,
                               USB_BUFFER_DIRECTION bufferDirection,
                               USB_BUFFER_PING_PONG bufferPingPong )
{
    short nBuffers;  // Total number of buffers for each endpoint
    short nPingPong; // Ping Pong offset, either 1 or 2
    short iBDTEntry; // Index of BDT entry

    switch ( ppMode )
    {
        case USB_PING_PONG_NO_PING_PONG:
            nBuffers  = 2;
            iBDTEntry = epValue * nBuffers + bufferDirection;
            break;

        case USB_PING_PONG_FULL_PING_PONG:
            nPingPong = 2;
            nBuffers  = 2*nPingPong;
            iBDTEntry = epValue * nBuffers + bufferDirection * nPingPong + bufferPingPong;
            break;

        case USB_PING_PONG_EP0_OUT_ONLY:
            if ( epValue == 0 )
            {
                if ( bufferDirection == USB_BUFFER_RX )
                {
                    iBDTEntry = bufferPingPong;
                }
                else
                {
                    iBDTEntry = 2;
                }
            }
            else
            {
                nBuffers  = 2;
                iBDTEntry = epValue * nBuffers + bufferDirection;
                iBDTEntry += 1; // For extra RX buffer for Endpoint Zero
            }
            break;

        case USB_PING_PONG_ALL_BUT_EP0:
            if ( epValue == 0 )
            {
                iBDTEntry = bufferDirection;
            }
            else
            {
                nPingPong = 2;
                nBuffers  = 2 * nPingPong;
                iBDTEntry = epValue * nBuffers + bufferDirection * nPingPong + bufferPingPong;
                iBDTEntry -= 2; // Remove ping-pong buffers for EP0
            }
            break;
    }

    return iBDTEntry;
}


PLIB_TEMPLATE unsigned int  USB_BufferIndexGet_PIC18F ( USB_MODULE_ID           index,
                                                        USB_PING_PONG_MODE      ppMode,
                                                        uint8_t                 epValue,
                                                        USB_BUFFER_DIRECTION    bufferDirection,
                                                        USB_BUFFER_PING_PONG    bufferPingPong )
{
    return USB_BDTIndexGet( ppMode, epValue, bufferDirection, bufferPingPong );
}


PLIB_TEMPLATE void * USB_BufferAddressGet_PIC18F ( USB_MODULE_ID        index,
                                                   void *               pBDT,
                                                   USB_PING_PONG_MODE   ppMode,
                                                   uint8_t              epValue,
                                                   USB_BUFFER_DIRECTION bufferDirection,
                                                   USB_BUFFER_PING_PONG bufferPingPong )
{
    short iBDTEntry; // Index of BDT entry
    pUSB_BDT_ENTRY pBDTEntry;

    iBDTEntry = USB_BDTIndexGet( ppMode, epValue, bufferDirection, bufferPingPong );
    pBDTEntry = (pUSB_BDT_ENTRY)pBDT + iBDTEntry;
    return ( void * )ConvertToVirtualAddress( pBDTEntry -> bufferAddress );
}


PLIB_TEMPLATE void USB_BufferAddressSet_PIC18F ( USB_MODULE_ID          index,
                                                 void *                 pBDT,
                                                 USB_PING_PONG_MODE     ppMode,
                                                 uint8_t                epValue,
                                                 USB_BUFFER_DIRECTION   bufferDirection,
                                                 USB_BUFFER_PING_PONG   bufferPingPong,
                                                 void *                 bufferAddress )
{
    short iBDTEntry; // Index of BDT entry
    pUSB_BDT_ENTRY pBDTEntry;

    iBDTEntry = USB_BDTIndexGet( ppMode, epValue, bufferDirection, bufferPingPong );
    pBDTEntry = (pUSB_BDT_ENTRY)pBDT + iBDTEntry;
    pBDTEntry -> bufferAddress = ConvertToPhysicalAddress( ( uint8_t * )bufferAddress );
}


PLIB_TEMPLATE uint16_t USB_BufferByteCountGet_PIC18F ( USB_MODULE_ID        index,
                                                       void *               pBDT,
                                                       USB_PING_PONG_MODE   ppMode,
                                                       uint8_t              epValue,
                                                       USB_BUFFER_DIRECTION bufferDirection,
                                                       USB_BUFFER_PING_PONG bufferPingPong )
{
    short iBDTEntry; // Index of BDT entry
    pUSB_BDT_ENTRY pBDTEntry;
    uint16_t byteCount = 0, temp;

    iBDTEntry = USB_BDTIndexGet( ppMode, epValue, bufferDirection, bufferPingPong );
    pBDTEntry = (pUSB_BDT_ENTRY)pBDT + iBDTEntry;
    byteCount = byteCount | pBDTEntry -> byteCountLSB;
    temp = pBDTEntry -> bufferStatus.byteCount_89;
    temp = temp << 8;
    byteCount = byteCount | temp;
    return ( byteCount );
}


PLIB_TEMPLATE void USB_BufferByteCountSet_PIC18F ( USB_MODULE_ID        index,
                                                   void *               pBDT,
                                                   USB_PING_PONG_MODE   ppMode,
                                                   uint8_t              epValue,
                                                   USB_BUFFER_DIRECTION bufferDirection,
                                                   USB_BUFFER_PING_PONG bufferPingPong,
                                                   uint16_t             bufferByteCount )
{
    short iBDTEntry; // Index of BDT entry
    pUSB_BDT_ENTRY pBDTEntry;

    iBDTEntry = USB_BDTIndexGet( ppMode, epValue, bufferDirection, bufferPingPong );
    pBDTEntry = (pUSB_BDT_ENTRY)pBDT + iBDTEntry;
    pBDTEntry -> byteCountLSB = bufferByteCount;
    pBDTEntry -> bufferStatus.byteCount_89 = bufferByteCount >> 8;
}


PLIB_TEMPLATE USB_BUFFER_DATA01 USB_BufferDataToggleGet_PIC18F ( USB_MODULE_ID          index,
                                                                 void *                 pBDT,
                                                                 USB_PING_PONG_MODE     ppMode,
                                                                 uint8_t                epValue,
                                                                 USB_BUFFER_DIRECTION   bufferDirection,
                                                                 USB_BUFFER_PING_PONG   bufferPingPong )
{
    short iBDTEntry; // Index of BDT entry
    pUSB_BDT_ENTRY pBDTEntry;

    iBDTEntry = USB_BDTIndexGet( ppMode, epValue, bufferDirection, bufferPingPong );
    pBDTEntry = (pUSB_BDT_ENTRY)pBDT + iBDTEntry;
    return ( pBDTEntry -> bufferStatus.dataToggle );
}


PLIB_TEMPLATE void USB_BufferDataToggleSelect_PIC18F ( USB_MODULE_ID        index,
                                                       void *               pBDT,
                                                       USB_PING_PONG_MODE   ppMode,
                                                       uint8_t              epValue,
                                                       USB_BUFFER_DIRECTION bufferDirection,
                                                       USB_BUFFER_PING_PONG bufferPingPong,
                                                       USB_BUFFER_DATA01    bufferData01 )
{
    short iBDTEntry; // Index of BDT entry
    pUSB_BDT_ENTRY pBDTEntry;

    iBDTEntry = USB_BDTIndexGet( ppMode, epValue, bufferDirection, bufferPingPong );
    pBDTEntry = (pUSB_BDT_ENTRY)pBDT + iBDTEntry;
    pBDTEntry -> bufferStatus.dataToggle = bufferData01;
}


PLIB_TEMPLATE void USB_BufferDataToggleSyncDisable_PIC18F ( USB_MODULE_ID          index,
                                                            void *                 pBDT,
                                                            USB_PING_PONG_MODE     ppMode,
                                                            uint8_t                epValue,
                                                            USB_BUFFER_DIRECTION   bufferDirection,
                                                            USB_BUFFER_PING_PONG   bufferPingPong )
{
    short iBDTEntry; // Index of BDT entry
    pUSB_BDT_ENTRY pBDTEntry;

    iBDTEntry = USB_BDTIndexGet( ppMode, epValue, bufferDirection, bufferPingPong );
    pBDTEntry = (pUSB_BDT_ENTRY)pBDT + iBDTEntry;
    pBDTEntry -> bufferStatus.dataToggleSyncEnable = 0;
}


PLIB_TEMPLATE void USB_BufferDataToggleSyncEnable_PIC18F ( USB_MODULE_ID        index,
                                                           void *               pBDT,
                                                           USB_PING_PONG_MODE   ppMode,
                                                           uint8_t              epValue,
                                                           USB_BUFFER_DIRECTION bufferDirection,
                                                           USB_BUFFER_PING_PONG bufferPingPong )
{
    short iBDTEntry; // Index of BDT entry
    pUSB_BDT_ENTRY pBDTEntry;

    iBDTEntry = USB_BDTIndexGet( ppMode, epValue, bufferDirection, bufferPingPong );
    pBDTEntry = (pUSB_BDT_ENTRY)pBDT + iBDTEntry;
    pBDTEntry -> bufferStatus.dataToggleSyncEnable = 1;
}


PLIB_TEMPLATE uint8_t USB_BufferPIDGet_PIC18F ( USB_MODULE_ID           index,
                                                void *                  pBDT,
                                                USB_PING_PONG_MODE      ppMode,
                                                uint8_t                 epValue,
                                                USB_BUFFER_DIRECTION    bufferDirection,
                                                USB_BUFFER_PING_PONG    bufferPingPong )
{
    short iBDTEntry; // Index of BDT entry
    pUSB_BDT_ENTRY pBDTEntry;

    iBDTEntry = USB_BDTIndexGet( ppMode, epValue, bufferDirection, bufferPingPong );
    pBDTEntry = (pUSB_BDT_ENTRY)pBDT + iBDTEntry;
    return ( pBDTEntry -> bufferStatus.packetID );
}


PLIB_TEMPLATE bool USB_BufferReleasedToSW_PIC18F ( USB_MODULE_ID        index,
                                                   void *               pBDT,
                                                   USB_PING_PONG_MODE   ppMode,
                                                   uint8_t              epValue,
                                                   USB_BUFFER_DIRECTION bufferDirection,
                                                   USB_BUFFER_PING_PONG bufferPingPong )
{
    short iBDTEntry; // Index of BDT entry
    pUSB_BDT_ENTRY pBDTEntry;

    iBDTEntry = USB_BDTIndexGet( ppMode, epValue, bufferDirection, bufferPingPong );
    pBDTEntry = (pUSB_BDT_ENTRY)pBDT + iBDTEntry;
    return ( ~( bool )( pBDTEntry -> bufferStatus.usbOwnsBuffer ) );
}


PLIB_TEMPLATE void USB_BufferReleaseToUSB_PIC18F ( USB_MODULE_ID        index,
                                                   void *               pBDT,
                                                   USB_PING_PONG_MODE   ppMode,
                                                   uint8_t              epValue,
                                                   USB_BUFFER_DIRECTION bufferDirection,
                                                   USB_BUFFER_PING_PONG bufferPingPong )
{
    short iBDTEntry; // Index of BDT entry
    pUSB_BDT_ENTRY pBDTEntry;

    iBDTEntry = USB_BDTIndexGet( ppMode, epValue, bufferDirection, bufferPingPong );
    pBDTEntry = (pUSB_BDT_ENTRY)pBDT + iBDTEntry;
    pBDTEntry -> bufferStatus.usbOwnsBuffer = 1;
}


PLIB_TEMPLATE void USB_BufferCancelReleaseToUSB_PIC18F ( USB_MODULE_ID          index,
                                                        void *                  pBDT,
                                                        USB_PING_PONG_MODE      ppMode,
                                                        uint8_t                 epValue,
                                                        USB_BUFFER_DIRECTION    bufferDirection,
                                                        USB_BUFFER_PING_PONG    bufferPingPong )
{
    short iBDTEntry; // Index of BDT entry
    pUSB_BDT_ENTRY pBDTEntry;

    iBDTEntry = USB_BDTIndexGet( ppMode, epValue, bufferDirection, bufferPingPong );
    pBDTEntry = (pUSB_BDT_ENTRY)pBDT + iBDTEntry;
    pBDTEntry -> bufferStatus.usbOwnsBuffer = 0;
}

//******************************************************************************
/* Function :  USB_BufferAllCancelReleaseToUSB_PIC32

  Summary:
    Implements PIC32 variant of PLIB_USB_BufferAllCancelReleaseToUSB

  Description:
    This template implements the PIC32 variant of the PLIB_USB_BufferAllCancelReleaseToUSB function.
*/

PLIB_TEMPLATE void USB_BufferAllCancelReleaseToUSB_PIC18F( USB_MODULE_ID         index ,
                                                           void *                pBDT ,
                                                           USB_PING_PONG_MODE    ppMode ,
                                                           int                   nEndpoint )
{
    int iBDTEntry; // Index of BDT entry
    pUSB_BDT_ENTRY pBDTEntry = (pUSB_BDT_ENTRY) pBDT ;

    for(iBDTEntry = 0; iBDTEntry < (nEndpoint * 4); iBDTEntry ++)
    {
        pBDTEntry -> bufferStatus.usbOwnsBuffer = 0;
        pBDTEntry += 1;
    }
}


PLIB_TEMPLATE void USB_BufferClearAll_PIC18F( USB_MODULE_ID         index,
                                              void *                pBDT,
                                              USB_PING_PONG_MODE    ppMode,
                                              uint8_t               epValue,
                                              USB_BUFFER_DIRECTION  bufferDirection,
                                              USB_BUFFER_PING_PONG  bufferPingPong )
{
    short iBDTEntry;
    pUSB_BDT_ENTRY pBDTEntry;

    iBDTEntry = USB_BDTIndexGet(ppMode, epValue, bufferDirection, bufferPingPong);
    pBDTEntry = (pUSB_BDT_ENTRY)pBDT + iBDTEntry;
    pBDTEntry->lValue = 0ul;
}


PLIB_TEMPLATE void USB_BufferStallDisable_PIC18F ( USB_MODULE_ID        index,
                                                   void *               pBDT,
                                                   USB_PING_PONG_MODE   ppMode,
                                                   uint8_t              epValue,
                                                   USB_BUFFER_DIRECTION bufferDirection,
                                                   USB_BUFFER_PING_PONG bufferPingPong )
{
    short iBDTEntry; // Index of BDT entry
    pUSB_BDT_ENTRY pBDTEntry;

    iBDTEntry = USB_BDTIndexGet( ppMode, epValue, bufferDirection, bufferPingPong );
    pBDTEntry = (pUSB_BDT_ENTRY)pBDT + iBDTEntry;
    pBDTEntry -> bufferStatus.stallEnable = 0;
}


PLIB_TEMPLATE void USB_BufferStallEnable_PIC18F ( USB_MODULE_ID         index,
                                                  void *                pBDT,
                                                  USB_PING_PONG_MODE    ppMode,
                                                  uint8_t               epValue,
                                                  USB_BUFFER_DIRECTION  bufferDirection,
                                                  USB_BUFFER_PING_PONG  bufferPingPong )
{
    short iBDTEntry; // Index of BDT entry
    pUSB_BDT_ENTRY pBDTEntry;

    iBDTEntry = USB_BDTIndexGet( ppMode, epValue, bufferDirection, bufferPingPong );
    pBDTEntry = (pUSB_BDT_ENTRY)pBDT + iBDTEntry;
    pBDTEntry -> bufferStatus.stallEnable = 1;
}


PLIB_TEMPLATE void USB_BufferPIDBitsClear_PIC18F ( USB_MODULE_ID        index,
                                                   void *               pBDT,
                                                   USB_PING_PONG_MODE   ppMode,
                                                   uint8_t              epValue,
                                                   USB_BUFFER_DIRECTION bufferDirection,
                                                   USB_BUFFER_PING_PONG bufferPingPong )
{
    short iBDTEntry; // Index of BDT entry
    pUSB_BDT_ENTRY pBDTEntry;

    iBDTEntry = USB_BDTIndexGet( ppMode, epValue, bufferDirection, bufferPingPong );
    pBDTEntry = (pUSB_BDT_ENTRY)pBDT + iBDTEntry;
    pBDTEntry -> bufferStatus.packetID = 0;
}


PLIB_TEMPLATE void USB_BufferSchedule_PIC18F( USB_MODULE_ID  index ,
                                              void*  pBDT ,
                                              USB_PING_PONG_MODE  ppMode ,
                                              uint8_t  epValue ,
                                              USB_BUFFER_DIRECTION  bufferDirection ,
                                              USB_BUFFER_PING_PONG  bufferPingPong ,
                                              void * bufferAddress ,
                                              int16_t bufferByteCount ,
                                              USB_BUFFER_SCHEDULE_DATA01 bufferData01 )
{
    short iBDTEntry; // Index of BDT entry
    pUSB_BDT_ENTRY pBDTEntry;

    iBDTEntry = USB_BDTIndexGet( ppMode, epValue, bufferDirection, bufferPingPong );
    pBDTEntry = (pUSB_BDT_ENTRY)pBDT + iBDTEntry;

    pBDTEntry -> bufferStatus.packetID = 0;             // Clear PID overlap bits
    pBDTEntry -> bufferStatus.dataToggleSyncEnable = 1; // Re-enable DTS

    if ( bufferData01 != USB_BUFFER_DONTCHANGE )
    {
        pBDTEntry -> bufferStatus.dataToggle = bufferData01;
    }

    pBDTEntry -> bufferAddress = ConvertToPhysicalAddress((uint8_t*)bufferAddress);
    pBDTEntry -> byteCountLSB = bufferByteCount;
    pBDTEntry -> bufferStatus.byteCount_89 = bufferByteCount >> 8;
    PLIB_ASSERT( pBDTEntry -> bufferStatus.usbOwnsBuffer == 0, "Buffer already in use" );
    pBDTEntry -> bufferStatus.usbOwnsBuffer = 1;

}

PLIB_TEMPLATE bool USB_BufferStallGet_PIC18F( USB_MODULE_ID index ,
                                              void* pBDT ,
                                              USB_PING_PONG_MODE ppMode ,
                                              uint8_t epValue ,
                                              USB_BUFFER_DIRECTION bufferDirection ,
                                              USB_BUFFER_PING_PONG  bufferPingPong )
{
    short iBDTEntry; // Index of BDT entry
    pUSB_BDT_ENTRY pBDTEntry;

    iBDTEntry = USB_BDTIndexGet( ppMode, epValue, bufferDirection, bufferPingPong );
    pBDTEntry = (pUSB_BDT_ENTRY)pBDT + iBDTEntry;
    return ( pBDTEntry -> bufferStatus.stallEnable );
}

PLIB_TEMPLATE void USB_BufferEP0RxStatusInitialize_PIC18F ( USB_MODULE_ID index,
                                                            void* pBDT,
                                                            USB_PING_PONG_MODE ppMode,
                                                            USB_BUFFER_PING_PONG pingpong,
                                                            uint16_t bufferByteCount )
{
    short iBDTEntry;
    pUSB_BDT_ENTRY pBDTEntry = (pUSB_BDT_ENTRY) pBDT;
    iBDTEntry = USB_BDTIndexGet( ppMode, 0, USB_BUFFER_RX, pingpong );
    pBDTEntry += iBDTEntry;

    pBDTEntry->lValue = 0;
    pBDTEntry -> byteCountLSB = bufferByteCount;
    pBDTEntry -> bufferStatus.byteCount_89 = bufferByteCount >> 8;
    pBDTEntry->bufferStatus.usbOwnsBuffer = 1;

}

PLIB_TEMPLATE void USB_BufferClearAllDTSEnable_PIC18F( USB_MODULE_ID index,
                                                       void * pBDT,
                                                       USB_PING_PONG_MODE ppMode,
                                                       uint8_t epValue,
                                                       USB_BUFFER_DIRECTION bufferDirection)
{
    short iBDTEntry, i; // Index of BDT entry
    pUSB_BDT_ENTRY pBDTEntry;

    iBDTEntry = USB_BDTIndexGet( ppMode, epValue, bufferDirection, USB_BUFFER_EVEN );
    /* This is the even BD for the specified direction */
    pBDTEntry = (pUSB_BDT_ENTRY)pBDT + iBDTEntry;

    for (i = 0; i < 2; i ++)
    {
        pBDTEntry -> lValue = 0;
        pBDTEntry -> bufferStatus.dataToggleSyncEnable = 1;

        /* Increment to point to odd BD for this endpoint */
        pBDTEntry ++;
    }
}

//******************************************************************************
/* Function :  USB_ExistsBDTFunctions_PIC18F

  Summary:
    Implements PIC18F variant of PLIB_USB_ExistsBDTFunctions

  Description:
    This template implements the PIC18F variant of the PLIB_USB_ExistsBDTFunctions function.
*/

#define PLIB_USB_ExistsBDTFunctions PLIB_USB_ExistsBDTFunctions
PLIB_TEMPLATE bool USB_ExistsBDTFunctions_PIC18F( USB_MODULE_ID index )
{
    return true;
}

#endif /*_USB_BDTFUNCTIONS_PIC18F_H*/
