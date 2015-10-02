
#include <string.h> 
#include "Harmony_Private.h"
#include "Harmony_Sys.h"
#include "Harmony_Public.h"

#if defined(_USB)

extern HARMONY_APP_DATA Harmony_AppData;

extern USB_DEVICE_CDC_EVENT_RESPONSE APP_USBDeviceCDCEventHandler(USB_DEVICE_CDC_INDEX index, USB_DEVICE_CDC_EVENT event, void* pData, uintptr_t userData);
extern void APP_USBDeviceHIDEventHandler(USB_DEVICE_HID_INDEX index, USB_DEVICE_HID_EVENT event, void * eventData, uintptr_t userData);

/*************************************************
 * Application Device Layer Event Handler
 *************************************************/
void APP_USBDeviceEventHandler(USB_DEVICE_EVENT event, void * pData, uintptr_t context)
{
    uint8_t configurationValue;

    switch (event)
    {
    case USB_DEVICE_EVENT_RESET:
    case USB_DEVICE_EVENT_DECONFIGURED:

        /* Device was either de-configured or reset */
        Harmony_AppData.isUsbConfigured = false;
        Harmony_AppData.UsbConfigureCookieIsr++;
        Harmony_AppData.comPorts[COM1].IsActive = false;
        Harmony_AppData.comPorts[COM2].IsActive = false;
        Harmony_AppData.Hid.IsActive = false;
        break;

    case USB_DEVICE_EVENT_CONFIGURED:

        /* pData will point to the configuration. Check the configuration */
        configurationValue = ((USB_DEVICE_EVENT_DATA_CONFIGURED *) pData)->configurationValue;
        if (configurationValue == 1)
        {
            /* Register the CDC Device application event handler here.
             * Note how the appData object pointer is passed as the
             * user data */

            USB_DEVICE_CDC_EventHandlerSet(COM1, APP_USBDeviceCDCEventHandler, (uintptr_t) & Harmony_AppData);
            USB_DEVICE_CDC_EventHandlerSet(COM2, APP_USBDeviceCDCEventHandler, (uintptr_t) & Harmony_AppData);
            USB_DEVICE_HID_EventHandlerSet(0, APP_USBDeviceHIDEventHandler, (uintptr_t) & Harmony_AppData);

            /* Mark that app is configured complete */
            Harmony_AppData.isUsbConfigured = true;
        }
        break;

    case USB_DEVICE_EVENT_SUSPENDED:
        Harmony_AppData.comPorts[COM1].IsActive = false;
        Harmony_AppData.comPorts[COM2].IsActive = false;
        Harmony_AppData.Hid.IsActive = false;
        break;

    case USB_DEVICE_EVENT_POWER_DETECTED:

        /* VBUS has been detected. We can attach the device */
        USB_DEVICE_Attach(Harmony_AppData.deviceHandle);
        break;

    case USB_DEVICE_EVENT_POWER_REMOVED:

        /* VBUS is not avialable. We can detach the device */
        USB_DEVICE_Detach(Harmony_AppData.deviceHandle);
        break;

    case USB_DEVICE_EVENT_RESUMED:
        if (Harmony_AppData.comPorts[COM1].controlLineStateData.carrier || Harmony_AppData.comPorts[COM1].controlLineStateData.dtr)
            Harmony_AppData.comPorts[COM1].IsActive = true;

        if (Harmony_AppData.comPorts[COM2].controlLineStateData.carrier || Harmony_AppData.comPorts[COM2].controlLineStateData.dtr)
            Harmony_AppData.comPorts[COM2].IsActive = true;

        Harmony_AppData.Hid.IsActive = true;
        break;

    case USB_DEVICE_EVENT_ERROR:
    default:
        break;
    }
}
#endif