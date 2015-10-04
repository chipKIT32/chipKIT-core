
#include <string.h> 
#include "System_Config.h"
#include "Harmony_System_Definitions.h"
#include "Harmony_Sys.h"
#include "Harmony_Private.h"
#include "Harmony_Public.h"
#include "utlist.h"
#include "osal/osal.h"

#if defined(_USB)

extern HARMONY_APP_DATA Harmony_AppData;

uint8_t HidTxBuffer[HARMONY_HID_WRITE_BUFFER_SIZE] APP_MAKE_BUFFER_DMA_READY;
uint8_t HidRxBuffer[HARMONY_HID_READ_BUFFER_SIZE] APP_MAKE_BUFFER_DMA_READY;

bool Harmony_Hid_CanSendReport(void)
{
    Harmony_SYS_Tasks();
    return (Harmony_AppData.isUsbConfigured && !Harmony_AppData.Hid.isTxBusy);
}

HID_STATUS Harmony_Hid_SendCollectionReport(uint8_t id, const void* data, int len)
{
    USB_DEVICE_HID_RESULT hidStat;

    if (!Harmony_Hid_CanSendReport())
        return HID_STATUS_BUFFERS_FULL;

    Harmony_AppData.Hid.isTxBusy = true;

    len = len > (HARMONY_HID_WRITE_BUFFER_SIZE - 1) ? (HARMONY_HID_WRITE_BUFFER_SIZE - 1) : len;

    Harmony_AppData.Hid.TxBuffer[0] = id;
    memcpy(&Harmony_AppData.Hid.TxBuffer[1], data, len);

    hidStat = USB_DEVICE_HID_ReportSend(0,
                                        &Harmony_AppData.Hid.writeTransferHandle,
                                        Harmony_AppData.Hid.TxBuffer, len + 1);

    if (hidStat != USB_DEVICE_HID_RESULT_OK)
    {
        Harmony_AppData.Hid.isTxBusy = false;
    }

    return (HID_STATUS) hidStat;
}

bool Harmony_Hid_IsActive(void)
{
    return Harmony_AppData.isUsbConfigured && Harmony_AppData.Hid.IsActive;
}

/************************************************
 * HID Application Event Handler
 ************************************************/
void APP_USBDeviceHIDEventHandler(USB_DEVICE_HID_INDEX index,
                                  USB_DEVICE_HID_EVENT event, void * eventData, uintptr_t userData)
{
    HARMONY_APP_DATA * pAppData = (HARMONY_APP_DATA *) userData;
    USB_DEVICE_HID_EVENT_DATA_REPORT_RECEIVED* reportReceivedData;

    if (index != 0) return;

    switch (event)
    {
    case USB_DEVICE_HID_EVENT_REPORT_SENT:
        pAppData->Hid.isTxBusy = false;
        break;

    case USB_DEVICE_HID_EVENT_REPORT_RECEIVED:
        reportReceivedData = (USB_DEVICE_HID_EVENT_DATA_REPORT_RECEIVED*) eventData;
        pAppData->Hid.isRxReady = true;
        if (reportReceivedData != NULL)
        {
            pAppData->Hid.ReceivedLength = reportReceivedData->length;
        }
        break;

    case USB_DEVICE_HID_EVENT_SET_IDLE:

        /* Acknowledge the Control Write Transfer */
        USB_DEVICE_ControlStatus(pAppData->deviceHandle, USB_DEVICE_CONTROL_STATUS_OK);

        /* save Idle rate received from Host */
        pAppData->Hid.idleRate = ((USB_DEVICE_HID_EVENT_DATA_SET_IDLE*) eventData)->duration;
        pAppData->Hid.IsActive = true;
        break;

    case USB_DEVICE_HID_EVENT_GET_IDLE:

        /* Host is requesting for Idle rate. Now send the Idle rate */
        USB_DEVICE_ControlSend(pAppData->deviceHandle, &(pAppData->Hid.idleRate), 1);

        /* On successfully receiving Idle rate, the Host would acknowledge back with a
           Zero Length packet. The HID function driver returns an event
           USB_DEVICE_HID_EVENT_CONTROL_TRANSFER_DATA_SENT to the application upon
           receiving this Zero Length packet from Host.
           USB_DEVICE_HID_EVENT_CONTROL_TRANSFER_DATA_SENT event indicates this control transfer
           event is complete */

        break;

    case USB_DEVICE_HID_EVENT_SET_PROTOCOL:
        /* Host is trying set protocol. Now receive the protocol and save */
        pAppData->Hid.activeProtocol = *(USB_HID_PROTOCOL_CODE *) eventData;

        /* Acknowledge the Control Write Transfer */
        USB_DEVICE_ControlStatus(pAppData->deviceHandle, USB_DEVICE_CONTROL_STATUS_OK);
        break;

    case USB_DEVICE_HID_EVENT_GET_PROTOCOL:

        /* Host is requesting for Current Protocol. Now send the Idle rate */
        USB_DEVICE_ControlSend(pAppData->deviceHandle, &(pAppData->Hid.activeProtocol), 1);

        /* On successfully receiving Idle rate, the Host would acknowledge
          back with a Zero Length packet. The HID function driver returns
          an event USB_DEVICE_HID_EVENT_CONTROL_TRANSFER_DATA_SENT to the
          application upon receiving this Zero Length packet from Host.
          USB_DEVICE_HID_EVENT_CONTROL_TRANSFER_DATA_SENT event indicates
          this control transfer event is complete */
        break;

    case USB_DEVICE_HID_EVENT_CONTROL_TRANSFER_DATA_SENT:
        pAppData->Hid.IsActive = true;
        break;

    default:
        break;
    }
}

void Harmony_Hid_ResetStates(void)
{
    Harmony_AppData.Hid.writeTransferHandle = USB_DEVICE_HANDLE_INVALID;
    Harmony_AppData.Hid.isTxBusy = false;

    Harmony_AppData.Hid.readTransferHandle = USB_DEVICE_HANDLE_INVALID;
    Harmony_AppData.Hid.isRxReady = true;
    Harmony_AppData.Hid.ReceivedLength = 0;
}

void Harmony_Hid_Initialize(void)
{
    Harmony_AppData.Hid.idleRate = 0;
    Harmony_AppData.Hid.setIdleTimer = 0;
    Harmony_AppData.Hid.TxBuffer = HidTxBuffer;
    Harmony_AppData.Hid.RxBuffer = HidRxBuffer;
}

#endif
