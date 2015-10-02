#ifndef _HARMONY_PUBLIC_H
#define _HARMONY_PUBLIC_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "usb/usb_cdc.h"
#include "usb/usb_hid.h"

#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif

    //<editor-fold defaultstate="collapsed" desc="USB CDC Types and Functions">
    
    // Harmony error codes are negative.
    // See USB_DEVICE_CDC_RESULT to decipher negative codes.

    typedef enum {
        /* Operation completed successfully. */
        CDC_STATUS_SUCCESS = 0,

        /* Not connected or the host has not yet configured usb. */
        CDC_STATUS_USB_NOT_CONFIGURED = 1,

        /* All of the buffers are full. */
        CDC_STATUS_BUFFERS_FULL = 2,

        /* One of the paramters is invalid. */
        CDC_STATUS_INVALID_PARAM = 3,

        /* The port index supplied is not in range of available CDC ports. */
        CDC_STATUS_INVALID_PORT = 4,
 
        /* No data is available to read. */
        CDC_STATUS_NO_DATA = 5,
    } CDC_STATUS;
    
    /* Returns the number of available CDC serial ports. */
    size_t Harmony_Cdc_GetPortCount(void);
    
    /* Used to track if we think an application on the PC has our port open or not.
     * True if it's OK to write to host, false if we should just drop the data.
     * We start out false, but if the PC asks for any IN packets, sends us any OUT 
     * packets, or touches any hardware handshaking line, we set it to true.
     * The application should set it to false after xx ms goes by without the
     * host accepting a write request. THIS module will toggle the active state to
     * true when the host sets either the CARRIER or the DTR bit and back to false
     * if the host clears both CARRIER and DTR bits.*/
    bool Harmony_Cdc_IsPortActive(int32_t portIndex);
    
    /* Deactivates the port. See Harmony_Cdc_IsPortActive. */
    void Harmony_Cdc_SetPortActive(int32_t portIndex, bool isActive);
    
    /* Returns the line enocoding. */
    USB_CDC_LINE_CODING* Harmony_Cdc_GetLineEncoding(int32_t portIndex);
    
    /* True if USB is in a configured state and there is one or more buffers available for writing. */
    bool Harmony_Cdc_CanWrite(int32_t portIndex);
    
    /* Writes bytes to CDC seria.l */
    CDC_STATUS Harmony_Cdc_Write(int32_t portIndex, const uint8_t * data, size_t size, size_t* bytesWritten);
    
    /* True if there is one or more bytes available to read. */
    bool Harmony_Cdc_CanRead(int32_t portIndex);
    
    /* Reads bytes from CDC serial. */
    CDC_STATUS Harmony_Cdc_Read(int32_t portIndex, uint8_t * data, size_t size, size_t* bytesRead);
    
    /* Returns the first available char if there is one or more bytes available 
     * to read. Does NOT consume the char. Returns -1 in all other cases. */
    int Harmony_Cdc_PeekChar(int32_t portIndex);  
    
    /* Reads the first available char if there is one or more bytes available 
     * to read. Returns -1 in all other cases. */
    int Harmony_Cdc_ReadChar(int32_t portIndex);
    //</editor-fold>

    //<editor-fold defaultstate="collapsed" desc="HID Types and Functions">
    
    // Harmony error codes are negative.
    // See USB_DEVICE_HID_RESULT to decipher negative codes.

    typedef enum {
        /* Operation completed successfully. */
        HID_STATUS_SUCCESS = 0,

        /* Not connected or the host has not yet configured usb. */
        HID_STATUS_USB_NOT_CONFIGURED = 1,

        /* All of the buffers are full. */
        HID_STATUS_BUFFERS_FULL = 2,

        /* One of the paramters is invalid. */
        HID_STATUS_INVALID_PARAM = 3,
 
        /* No data is available to read. */
        HID_STATUS_NO_DATA = 5,
    } HID_STATUS;
    
    /* True if USB is in a configured state and we have received control requests
     * from the HID class driver. */
    bool Harmony_Hid_IsActive(void);
    
    /* True if USB is in a configured state and is not busy sending a previous packet. */
    bool Harmony_Hid_CanSendReport(void);
    
    /* Sends a collection specific HID report. The transfer packet is prefixed with
     * the 'id' byte. */
    HID_STATUS Harmony_Hid_SendCollectionReport(uint8_t id, const void* data, int len);
    //</editor-fold>

#ifdef __cplusplus
}
#endif

#endif
