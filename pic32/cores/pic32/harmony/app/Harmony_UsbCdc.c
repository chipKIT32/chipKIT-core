
#include <string.h> 
#include "System_Config.h"
#include "system_definitions.h"
#include "Harmony_Sys.h"
#include "Harmony_Private.h"
#include "Harmony_Public.h"
#include "utlist.h"
#include "osal/osal.h"

#if defined(_USB)

/* CDC Data Buffers */
uint8_t ComPortRxBuffers[HARMONY_CDC_READ_BUFFER_COUNT* HARMONY_CDC_PORT_COUNT][HARMONY_CDC_READ_BUFFER_SIZE] APP_MAKE_BUFFER_DMA_READY;
uint8_t ComPortTxBuffers[HARMONY_CDC_WRITE_BUFFER_COUNT * HARMONY_CDC_PORT_COUNT][HARMONY_CDC_WRITE_BUFFER_SIZE] APP_MAKE_BUFFER_DMA_READY;

extern HARMONY_APP_DATA Harmony_AppData;

#define IsPortValid(mPortIndex) ((mPortIndex) >= 0 && (mPortIndex) < HARMONY_CDC_PORT_COUNT)

static uint32_t usb_critical;

static USB_DEVICE_CDC_RESULT sumbitFromReadCompleteList(int32_t portIndex)
{
    USB_DEVICE_CDC_RESULT stat = CDC_STATUS_SUCCESS;
    HARMONY_CDC_TRANSFER_CONTEXT* pTransfer = (HARMONY_CDC_TRANSFER_CONTEXT*) Harmony_AppData.comPorts[portIndex].ReadCompleteList;

    if (pTransfer == NULL) return CDC_STATUS_BUFFERS_FULL;

    ENTER_USB_CRITICAL(usb_critical);

    DL_DELETE(Harmony_AppData.comPorts[portIndex].ReadCompleteList, pTransfer);
    DL_APPEND(Harmony_AppData.comPorts[portIndex].ReadPendingList, pTransfer);
    pTransfer->ErrorCode = USB_DEVICE_CDC_RESULT_ERROR;
    pTransfer->TransferredLength = 0;
    LEAVE_USB_CRITICAL(usb_critical);

    stat = USB_DEVICE_CDC_Read(
                               portIndex,
                               &pTransfer->TransferHandle,
                               pTransfer->DataBuffer,
                               HARMONY_CDC_READ_BUFFER_SIZE);

    if (stat != USB_DEVICE_CDC_RESULT_OK)
    {
        ENTER_USB_CRITICAL(usb_critical);

        DL_DELETE(Harmony_AppData.comPorts[portIndex].ReadPendingList, pTransfer);
        DL_APPEND(Harmony_AppData.comPorts[portIndex].ReadCompleteList, pTransfer);

        LEAVE_USB_CRITICAL(usb_critical);

        // Harmony error codes are negative.
        // See USB_DEVICE_CDC_RESULT to decipher negative codes.
        return (CDC_STATUS) stat;
    }

    return stat;
}

size_t Harmony_Cdc_GetPortCount(void)
{
    return HARMONY_CDC_PORT_COUNT;
}

bool Harmony_Cdc_CanWrite(int32_t portIndex)
{
    if (!IsPortValid(portIndex)) return false;

    Harmony_SYS_Tasks();
    return (Harmony_AppData.isUsbConfigured && Harmony_AppData.comPorts[portIndex].WriteIdleList != NULL);
}

CDC_STATUS Harmony_Cdc_Write(int32_t portIndex, const uint8_t * data, size_t size, size_t* bytesWritten)
{
    size_t batchIndex, batchSize;
    USB_DEVICE_CDC_RESULT stat;
    size_t _bytesWritten = 0;

    HARMONY_CDC_TRANSFER_CONTEXT* pTransfer;

    if (!IsPortValid(portIndex)) return CDC_STATUS_INVALID_PORT;
    Harmony_SYS_Tasks();

    if (bytesWritten != NULL)
        *bytesWritten = 0;

    if (size == 0)
        return CDC_STATUS_INVALID_PARAM;

    if (!Harmony_AppData.isUsbConfigured)
        return CDC_STATUS_USB_NOT_CONFIGURED;

    while (size > 0 && Harmony_AppData.comPorts[portIndex].WriteIdleList != NULL)
    {
        pTransfer = (HARMONY_CDC_TRANSFER_CONTEXT*) Harmony_AppData.comPorts[portIndex].WriteIdleList;
        batchSize = size > HARMONY_CDC_WRITE_BUFFER_SIZE ? HARMONY_CDC_WRITE_BUFFER_SIZE : size;
        size -= batchSize;
        memcpy(pTransfer->DataBuffer, &data[_bytesWritten], batchSize);
        pTransfer->ErrorCode = USB_DEVICE_CDC_RESULT_ERROR;

        ENTER_USB_CRITICAL(usb_critical);

        DL_DELETE(Harmony_AppData.comPorts[portIndex].WriteIdleList, pTransfer);
        DL_APPEND(Harmony_AppData.comPorts[portIndex].WritePendingList, pTransfer);

        LEAVE_USB_CRITICAL(usb_critical);
        stat = USB_DEVICE_CDC_Write(
                                    portIndex,
                                    &pTransfer->TransferHandle,
                                    pTransfer->DataBuffer,
                                    batchSize,
                                    USB_DEVICE_CDC_TRANSFER_FLAGS_DATA_COMPLETE);
        if (stat != USB_DEVICE_CDC_RESULT_OK)
        {
            ENTER_USB_CRITICAL(usb_critical);

            DL_DELETE(Harmony_AppData.comPorts[portIndex].WritePendingList, pTransfer);
            DL_APPEND(Harmony_AppData.comPorts[portIndex].WriteIdleList, pTransfer);

            LEAVE_USB_CRITICAL(usb_critical);

            // Harmony error codes are negative.
            // See USB_DEVICE_CDC_RESULT to decipher negative codes.
            return (CDC_STATUS) stat;
        }
        else
        {
            _bytesWritten += batchSize;
            if (bytesWritten != NULL)
                *bytesWritten = _bytesWritten;
        }
    }

    if (size > 0)
        return CDC_STATUS_BUFFERS_FULL;

    return CDC_STATUS_SUCCESS;
}

bool Harmony_Cdc_CanRead(int32_t portIndex)
{
    if (!IsPortValid(portIndex)) return false;

    Harmony_SYS_Tasks();
    return (Harmony_AppData.isUsbConfigured && Harmony_AppData.comPorts[portIndex].ReadCompleteList != NULL);
}

CDC_STATUS Harmony_Cdc_Read(int32_t portIndex, uint8_t * data, size_t size, size_t* bytesRead)
{
    size_t batchIndex, batchSize;
    size_t _bytesRead = 0;
    USB_DEVICE_CDC_RESULT stat;
    HARMONY_CDC_TRANSFER_CONTEXT* pTransfer;

    if (!IsPortValid(portIndex)) return CDC_STATUS_INVALID_PORT;

    Harmony_SYS_Tasks();

    if (bytesRead != NULL)
        *bytesRead = 0;

    if (size == 0)
        return CDC_STATUS_INVALID_PARAM;

    if (!Harmony_AppData.isUsbConfigured)
        return CDC_STATUS_USB_NOT_CONFIGURED;

    pTransfer = (HARMONY_CDC_TRANSFER_CONTEXT*) Harmony_AppData.comPorts[portIndex].ReadCompleteList;
    if (pTransfer == NULL)
        return CDC_STATUS_NO_DATA;


    while (size > 0 && Harmony_AppData.comPorts[portIndex].ReadCompleteList != NULL)
    {
        pTransfer = (HARMONY_CDC_TRANSFER_CONTEXT*) Harmony_AppData.comPorts[portIndex].ReadCompleteList;
        if (pTransfer->ErrorCode == USB_DEVICE_CDC_RESULT_OK && pTransfer->TransferredLength > 0)
        {
            batchSize = pTransfer->TransferredLength > size ? size : pTransfer->TransferredLength;
            size -= batchSize;
            pTransfer->TransferredLength -= batchSize;

            memcpy(&data[_bytesRead], &pTransfer->DataBuffer[pTransfer->TransferredPos], batchSize);
            pTransfer->TransferredPos += batchSize;

            _bytesRead += batchSize;
            if (bytesRead)
                *bytesRead = _bytesRead;

        }
        if (pTransfer->ErrorCode != USB_DEVICE_CDC_RESULT_OK || pTransfer->TransferredLength == 0)
        {
            ENTER_USB_CRITICAL(usb_critical);

            DL_DELETE(Harmony_AppData.comPorts[portIndex].ReadCompleteList, pTransfer);
            DL_APPEND(Harmony_AppData.comPorts[portIndex].ReadPendingList, pTransfer);
            pTransfer->ErrorCode = USB_DEVICE_CDC_RESULT_ERROR;
            LEAVE_USB_CRITICAL(usb_critical);

            stat = USB_DEVICE_CDC_Read(
                                       portIndex,
                                       &pTransfer->TransferHandle,
                                       pTransfer->DataBuffer,
                                       HARMONY_CDC_READ_BUFFER_SIZE);

            if (stat != USB_DEVICE_CDC_RESULT_OK)
            {
                ENTER_USB_CRITICAL(usb_critical);

                DL_DELETE(Harmony_AppData.comPorts[portIndex].ReadPendingList, pTransfer);
                DL_APPEND(Harmony_AppData.comPorts[portIndex].ReadCompleteList, pTransfer);

                LEAVE_USB_CRITICAL(usb_critical);

                // Harmony error codes are negative.
                // See USB_DEVICE_CDC_RESULT to decipher negative codes.
                return (CDC_STATUS) stat;
            }
        }
    }
    return CDC_STATUS_SUCCESS;
}

int Harmony_Cdc_PeekChar(int32_t portIndex)
{
    HARMONY_CDC_TRANSFER_CONTEXT* pTransfer;

    if (!IsPortValid(portIndex)) return -1;

    Harmony_SYS_Tasks();

    pTransfer = (HARMONY_CDC_TRANSFER_CONTEXT*) Harmony_AppData.comPorts[portIndex].ReadCompleteList;
    if (pTransfer == NULL)
        return -1;

    if (pTransfer->ErrorCode != USB_DEVICE_CDC_RESULT_OK || pTransfer->TransferredLength == 0)
    {
        if (!Harmony_AppData.isUsbConfigured)
            return -1;

        sumbitFromReadCompleteList(portIndex);

        return -1;
    }

    return pTransfer->DataBuffer[pTransfer->TransferredPos];

}

int Harmony_Cdc_ReadChar(int32_t portIndex)
{
    HARMONY_CDC_TRANSFER_CONTEXT* pTransfer;
    int theChar = -1;
    if (!IsPortValid(portIndex)) return -1;

    Harmony_SYS_Tasks();

    pTransfer = (HARMONY_CDC_TRANSFER_CONTEXT*) Harmony_AppData.comPorts[portIndex].ReadCompleteList;
    if (pTransfer == NULL)
        return -1;

    if (pTransfer->ErrorCode != USB_DEVICE_CDC_RESULT_OK || pTransfer->TransferredLength == 0)
    {
        if (!Harmony_AppData.isUsbConfigured)
            return -1;

        sumbitFromReadCompleteList(portIndex);

        return -1;
    }

    theChar = pTransfer->DataBuffer[pTransfer->TransferredPos];
    pTransfer->TransferredPos++;
    pTransfer->TransferredLength--;

    if (pTransfer->TransferredLength == 0)
    {
        sumbitFromReadCompleteList(portIndex);
    }
    return theChar;
}

bool Harmony_Cdc_IsPortActive(int32_t portIndex)
{
    return (IsPortValid(portIndex) && Harmony_AppData.isUsbConfigured && Harmony_AppData.comPorts[portIndex].IsActive);
}

void Harmony_Cdc_SetPortActive(int32_t portIndex, bool isActive)
{
    if (IsPortValid(portIndex))
    {
        Harmony_AppData.comPorts[portIndex].IsActive = isActive;
    }
}

USB_CDC_LINE_CODING* Harmony_Cdc_GetLineEncoding(int32_t portIndex)
{
    if (IsPortValid(portIndex))
    {
        return &Harmony_AppData.comPorts[portIndex].getLineCodingData;
    }
    return NULL;
}

void Harmony_Cdc_Flush(int32_t portIndex)
{
	USB_DEVICE_CDC_RESULT stat = CDC_STATUS_SUCCESS;
	HARMONY_CDC_TRANSFER_CONTEXT* pTransfer;
	int bufCounter = 0;

	if (!IsPortValid(portIndex)) return;

	Harmony_SYS_Tasks();

	while ((pTransfer = (HARMONY_CDC_TRANSFER_CONTEXT*)Harmony_AppData.comPorts[portIndex].ReadCompleteList) != NULL)
	{
		stat = sumbitFromReadCompleteList(portIndex);
		if (stat != CDC_STATUS_SUCCESS)
			break;

		Harmony_SYS_Tasks();

		if (++bufCounter == HARMONY_CDC_READ_BUFFER_COUNT)
			break;
	}
}

/************************************************
 * CDC Application Event Handler
 ************************************************/
USB_DEVICE_CDC_EVENT_RESPONSE APP_USBDeviceCDCEventHandler
(
 USB_DEVICE_CDC_INDEX index,
 USB_DEVICE_CDC_EVENT event,
 void* pData,
 uintptr_t userData
 )
{

    HARMONY_APP_DATA * pAppData = (HARMONY_APP_DATA *) userData;
    USB_DEVICE_CDC_EVENT_DATA_READ_COMPLETE * pDataComplete;
    HARMONY_CDC_TRANSFER_CONTEXT* pTransfer;

    USB_CDC_CONTROL_LINE_STATE * controlLineStateData;
    uint16_t * breakData;

    switch (event)
    {
    case USB_DEVICE_CDC_EVENT_GET_LINE_CODING:

        /* This means the host wants to know the current line
         * coding. This is a control transfer request. Use the
         * USB_DEVICE_ControlSend() function to send the data to
         * host.  */

        USB_DEVICE_ControlSend(pAppData->deviceHandle,
                               &pAppData->comPorts[index].getLineCodingData,
                               sizeof (USB_CDC_LINE_CODING));

        break;

    case USB_DEVICE_CDC_EVENT_SET_LINE_CODING:

        /* This means the host wants to set the line coding.
         * This is a control transfer request. Use the
         * USB_DEVICE_ControlReceive() function to receive the
         * data from the host */

        USB_DEVICE_ControlReceive(pAppData->deviceHandle,
                                  &pAppData->comPorts[index].setLineCodingData,
                                  sizeof (USB_CDC_LINE_CODING));

        break;

    case USB_DEVICE_CDC_EVENT_SET_CONTROL_LINE_STATE:

        /* This means the host is setting the control line state.
         * Read the control line state. We will accept this request
         * for now. */

        controlLineStateData = (USB_CDC_CONTROL_LINE_STATE *) pData;
        pAppData->comPorts[index].IsActive = (controlLineStateData->carrier || controlLineStateData->dtr);
        pAppData->comPorts[index].controlLineStateData.dtr = controlLineStateData->dtr;
        pAppData->comPorts[index].controlLineStateData.carrier = controlLineStateData->carrier;

        USB_DEVICE_ControlStatus(pAppData->deviceHandle, USB_DEVICE_CONTROL_STATUS_OK);

        break;

    case USB_DEVICE_CDC_EVENT_SEND_BREAK:

        /* This means that the host is requesting that a break of the
         * specified duration be sent. Read the break duration */

        breakData = (uint16_t *) pData;
        pAppData->comPorts[index].breakData = *breakData;
        break;

    case USB_DEVICE_CDC_EVENT_READ_COMPLETE:

        if (pAppData->comPorts[index].ReadPendingList == NULL) break;

        pTransfer = (HARMONY_CDC_TRANSFER_CONTEXT*) pAppData->comPorts[index].ReadPendingList;
        pDataComplete = (USB_DEVICE_CDC_EVENT_DATA_READ_COMPLETE *) pData;
        DL_DELETE(pAppData->comPorts[index].ReadPendingList, pTransfer);
        DL_APPEND(pAppData->comPorts[index].ReadCompleteList, pTransfer);

        pTransfer->ErrorCode = pDataComplete->status;
        pTransfer->TransferredLength = pDataComplete->length;
        pTransfer->TransferredPos = 0;
        if (pTransfer->ErrorCode == USB_DEVICE_CDC_RESULT_OK)
        {
            pAppData->comPorts[index].IsActive = true;
        }
        break;

    case USB_DEVICE_CDC_EVENT_CONTROL_TRANSFER_DATA_RECEIVED:

        /* The data stage of the last control transfer is
         * complete. For now we accept all the data */

        USB_DEVICE_ControlStatus(pAppData->deviceHandle, USB_DEVICE_CONTROL_STATUS_OK);
        break;

    case USB_DEVICE_CDC_EVENT_CONTROL_TRANSFER_DATA_SENT:

        /* This means the GET LINE CODING function data is valid. We dont
         * do much with this data in this demo. */

        break;

    case USB_DEVICE_CDC_EVENT_WRITE_COMPLETE:

        if (pAppData->comPorts[index].WritePendingList == NULL) break;
        pTransfer = (HARMONY_CDC_TRANSFER_CONTEXT*) pAppData->comPorts[index].WritePendingList;
        pDataComplete = (USB_DEVICE_CDC_EVENT_DATA_READ_COMPLETE *) pData;
        DL_DELETE(pAppData->comPorts[index].WritePendingList, pTransfer);
        DL_APPEND(pAppData->comPorts[index].WriteIdleList, pTransfer);

        pTransfer->ErrorCode = pDataComplete->status;
        pTransfer->TransferredLength = pDataComplete->length;
        pTransfer->TransferredPos = 0;
        if (pTransfer->ErrorCode == USB_DEVICE_CDC_RESULT_OK)
        {
            pAppData->comPorts[index].IsActive = true;
        }

        break;

    default:
        break;
    }

    return USB_DEVICE_CDC_EVENT_RESPONSE_NONE;
}

void Harmony_Cdc_ResetStates(void)
{
    size_t portIndex = 0;
    size_t bufferIndex = 0;
    size_t nextRxDataBufferIndex = 0;
    size_t nextTxDataBufferIndex = 0;

    for (portIndex = 0; portIndex < HARMONY_CDC_PORT_COUNT; portIndex++)
    {
        Harmony_AppData.comPorts[portIndex].ReadCompleteList = NULL;
        Harmony_AppData.comPorts[portIndex].ReadPendingList = NULL;
        Harmony_AppData.comPorts[portIndex].ReadIdleList = NULL;

        Harmony_AppData.comPorts[portIndex].WritePendingList = NULL;
        Harmony_AppData.comPorts[portIndex].WriteIdleList = NULL;

        Harmony_AppData.comPorts[portIndex].IsActive = false;
        for (bufferIndex = 0; bufferIndex < HARMONY_CDC_READ_BUFFER_COUNT; bufferIndex++)
        {
            Harmony_AppData.comPorts[portIndex].readTransfers[bufferIndex].TransferredLength = 0;
            Harmony_AppData.comPorts[portIndex].readTransfers[bufferIndex].ErrorCode = USB_DEVICE_CDC_RESULT_ERROR;
            Harmony_AppData.comPorts[portIndex].readTransfers[bufferIndex].TransferHandle = USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;
            Harmony_AppData.comPorts[portIndex].readTransfers[bufferIndex].DataBuffer = ComPortRxBuffers[nextRxDataBufferIndex++];
            DL_APPEND(Harmony_AppData.comPorts[portIndex].ReadIdleList, (&Harmony_AppData.comPorts[portIndex].readTransfers[bufferIndex]));
        }
        for (bufferIndex = 0; bufferIndex < HARMONY_CDC_WRITE_BUFFER_COUNT; bufferIndex++)
        {
            Harmony_AppData.comPorts[portIndex].writeTransfers[bufferIndex].TransferredLength = 0;
            Harmony_AppData.comPorts[portIndex].writeTransfers[bufferIndex].ErrorCode = USB_DEVICE_CDC_RESULT_ERROR;
            Harmony_AppData.comPorts[portIndex].writeTransfers[bufferIndex].TransferHandle = USB_DEVICE_CDC_TRANSFER_HANDLE_INVALID;
            Harmony_AppData.comPorts[portIndex].writeTransfers[bufferIndex].DataBuffer = ComPortTxBuffers[nextTxDataBufferIndex++];
            DL_APPEND(Harmony_AppData.comPorts[portIndex].WriteIdleList, (&Harmony_AppData.comPorts[portIndex].writeTransfers[bufferIndex]));
        }
    }
}

void Harmony_Cdc_Initialize()
{
    int portIndex = 0;

    for (portIndex = 0; portIndex < HARMONY_CDC_PORT_COUNT; portIndex++)
    {
        Harmony_AppData.comPorts[portIndex].getLineCodingData.dwDTERate = 9600;
        Harmony_AppData.comPorts[portIndex].getLineCodingData.bDataBits = 8;
        Harmony_AppData.comPorts[portIndex].getLineCodingData.bParityType = 0;
        Harmony_AppData.comPorts[portIndex].getLineCodingData.bCharFormat = 0;
        Harmony_AppData.comPorts[portIndex].IsActive = false;
    }
}

#endif
