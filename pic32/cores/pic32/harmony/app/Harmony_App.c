#include "Harmony_Private.h"
HARMONY_APP_DATA Harmony_AppData;

extern void Harmony_Cdc_Initialize(void);
extern void Harmony_Hid_Initialize(void);

extern void Harmony_Cdc_ResetStates(void);
extern void Harmony_Hid_ResetStates(void);

extern void APP_USBDeviceEventHandler(USB_DEVICE_EVENT event, void * pData, uintptr_t context);


void (*pCbReportReceived)(uint8_t *data, uint32_t len) = NULL;

void Harmony_Hid_onReportReceived(void (*cbFunc)(uint8_t *, uint32_t)) {
    pCbReportReceived = cbFunc;
}


/************************************************
 * Application State Reset Function
 ************************************************/

void APP_StateReset(void)
{
    uint32_t usb_critical;
#if defined(_USB)
    ENTER_USB_CRITICAL(usb_critical);

    Harmony_Cdc_ResetStates();
    Harmony_Hid_ResetStates();

    LEAVE_USB_CRITICAL(usb_critical);
#endif
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void Harmony_APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void Harmony_APP_Initialize(void)
{
    /* Initialize the application object */

    Harmony_AppData.deviceHandle = USB_DEVICE_HANDLE_INVALID;
    Harmony_AppData.isUsbConfigured = false;
    Harmony_AppData.UsbConfigureCookie = 0;
    Harmony_AppData.UsbConfigureCookieIsr = 0;

    Harmony_AppData.state = APP_STATE_INIT;

#if defined (_USB)
    Harmony_Cdc_Initialize();
    Harmony_Hid_Initialize();
#endif
    
    APP_StateReset();
}

/******************************************************************************
  Function:
    void Harmony_APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

HARMONY_APP_STATES Harmony_APP_Tasks(void)
{
    /* Update the application state machine based
     * on the current state */
    size_t portIndex;
    size_t bufIndex;
    uint32_t usb_critical;

    switch (Harmony_AppData.state)
    {
    case APP_STATE_INIT:
#if defined(_USB)
        /* Open the device layer */
        Harmony_AppData.deviceHandle = USB_DEVICE_Open(USB_DEVICE_INDEX_0, DRV_IO_INTENT_READWRITE);

        if (Harmony_AppData.deviceHandle != USB_DEVICE_HANDLE_INVALID)
        {
            /* Register a callback with device layer to get event notification (for end point 0) */
            USB_DEVICE_EventHandlerSet(Harmony_AppData.deviceHandle, APP_USBDeviceEventHandler, 0);

            Harmony_AppData.state = APP_STATE_READY;
        }
        else
        {
            /* The Device Layer is not ready to be opened. We should try
             * again later. */
        }
#else
       Harmony_AppData.state = APP_STATE_READY; 
#endif
        break;

    case APP_STATE_READY:

        /* Check if the device was configured */
#if defined(_USB)
        if (Harmony_AppData.isUsbConfigured)
        {
            USB_DEVICE_CDC_RESULT stat;
            USB_DEVICE_HID_RESULT hidStat;
            /* If the device is configured then lets start
             * the application */

            ENTER_USB_CRITICAL(usb_critical);
            if (!Harmony_AppData.isUsbConfigured)
            {
                LEAVE_USB_CRITICAL(usb_critical);
                break;
            }
            Harmony_AppData.UsbConfigureCookie = Harmony_AppData.UsbConfigureCookieIsr;
            LEAVE_USB_CRITICAL(usb_critical);

            for (portIndex = 0; portIndex < HARMONY_CDC_PORT_COUNT; portIndex++)
            {
                while (Harmony_AppData.comPorts[portIndex].ReadIdleList != NULL)
                {

                    HARMONY_CDC_TRANSFER_CONTEXT* pTransfer = (HARMONY_CDC_TRANSFER_CONTEXT*) Harmony_AppData.comPorts[portIndex].ReadIdleList;

                    ENTER_USB_CRITICAL(usb_critical);

                    DL_DELETE(Harmony_AppData.comPorts[portIndex].ReadIdleList, pTransfer);
                    DL_APPEND(Harmony_AppData.comPorts[portIndex].ReadPendingList, pTransfer);

                    LEAVE_USB_CRITICAL(usb_critical);

                    stat = USB_DEVICE_CDC_Read(
                                               portIndex,
                                               &pTransfer->TransferHandle,
                                               pTransfer->DataBuffer,
                                               HARMONY_CDC_READ_BUFFER_SIZE);

                    if (stat != USB_ERROR_NONE)
                    {
                        ENTER_USB_CRITICAL(usb_critical);

                        DL_DELETE(Harmony_AppData.comPorts[portIndex].ReadPendingList, pTransfer);
                        DL_PREPEND(Harmony_AppData.comPorts[portIndex].ReadIdleList, pTransfer);

                        LEAVE_USB_CRITICAL(usb_critical);
                        break;
                    }

                }
            }
            Harmony_AppData.Hid.isRxReady = false;
            hidStat = USB_DEVICE_HID_ReportReceive(0,
                                                   &Harmony_AppData.Hid.readTransferHandle,
                                                   Harmony_AppData.Hid.RxBuffer, HARMONY_HID_READ_BUFFER_SIZE);

            if (hidStat != USB_DEVICE_HID_RESULT_OK)
                Harmony_AppData.Hid.isRxReady = true;
            Harmony_AppData.state = APP_STATE_USB_READY;

        }
#endif
        break;

    case APP_STATE_USB_READY:
#if defined (_USB)
        if (Harmony_AppData.UsbConfigureCookie != Harmony_AppData.UsbConfigureCookieIsr)
        {
            APP_StateReset();
            Harmony_AppData.state = APP_STATE_READY;
        }
#endif

        if (Harmony_AppData.Hid.isRxReady == true) {
            if (pCbReportReceived != NULL) {
                pCbReportReceived((uint8_t *)Harmony_AppData.Hid.RxBuffer, Harmony_AppData.Hid.ReceivedLength);
            }
            Harmony_AppData.Hid.isRxReady = false;
        }

        break;
    default:
        break;
    }

    return Harmony_AppData.state;
}



/*******************************************************************************
 End of File
 */

