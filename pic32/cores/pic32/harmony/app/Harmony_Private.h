#ifndef _HARMONY_PRIVATE_H
#define _HARMONY_PRIVATE_H


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdlib.h>
#include "system_config.h"
#include "system_definitions.h"
#include "utlist.h"
#include "osal/osal.h"
#include "Harmony_Sys.h"

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

#define COM1 USB_DEVICE_CDC_INDEX_0
#define COM2 USB_DEVICE_CDC_INDEX_1

#define HARMONY_CDC_WRITE_BUFFER_SIZE 512
#define HARMONY_CDC_READ_BUFFER_SIZE 512

#define HARMONY_CDC_WRITE_BUFFER_COUNT (2)
#define HARMONY_CDC_READ_BUFFER_COUNT (2)

#define HARMONY_HID_WRITE_BUFFER_SIZE 64
#define HARMONY_HID_READ_BUFFER_SIZE 64

#define APP_MAKE_BUFFER_DMA_READY
#define APP_USB_CONVERT_TO_MILLISECOND (1)
#define HARMONY_CDC_PORT_COUNT 2

#define ENTER_USB_CRITICAL(uint32Context) uint32Context = OSAL_CRIT_Enter(OSAL_CRIT_TYPE_HIGH)
#define LEAVE_USB_CRITICAL(uint32Context) OSAL_CRIT_Leave(OSAL_CRIT_TYPE_HIGH, uint32Context)

// *****************************************************************************
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/

typedef enum
{
    /* Application's state machine's initial state. */
    APP_STATE_INIT=0,

    /* Application waits for device configuration*/
    APP_STATE_READY,

    /* Application checks if the device is still configured*/
    APP_STATE_USB_READY,
            
} HARMONY_APP_STATES;

/******************************************************
 * Application COM Port Object
 ******************************************************/
typedef struct HARMONY_CDC_TRANSFER_CONTEXT
{
    /* transfer handle */
    USB_DEVICE_CDC_TRANSFER_HANDLE TransferHandle;

    uint8_t* DataBuffer;

    size_t TransferredLength;
    size_t TransferredPos;
    
    USB_DEVICE_CDC_RESULT ErrorCode;
    
    volatile struct HARMONY_CDC_TRANSFER_CONTEXT * next;
    volatile struct HARMONY_CDC_TRANSFER_CONTEXT * prev;
}HARMONY_CDC_TRANSFER_CONTEXT;

typedef struct
{
    USB_DEVICE_CDC_INDEX cdcInstance;

    /* Set Line Coding Data */
    USB_CDC_LINE_CODING setLineCodingData;

    /* Get Line Coding Data */
    USB_CDC_LINE_CODING getLineCodingData;

    /* Control Line State */
    USB_CDC_CONTROL_LINE_STATE controlLineStateData;

    /* Break data */
    uint16_t breakData;
    
    HARMONY_CDC_TRANSFER_CONTEXT readTransfers[HARMONY_CDC_WRITE_BUFFER_COUNT];
    HARMONY_CDC_TRANSFER_CONTEXT writeTransfers[HARMONY_CDC_READ_BUFFER_COUNT];

    volatile HARMONY_CDC_TRANSFER_CONTEXT* ReadPendingList;
    volatile HARMONY_CDC_TRANSFER_CONTEXT* ReadCompleteList;
    volatile HARMONY_CDC_TRANSFER_CONTEXT* ReadIdleList;
    
  
    volatile HARMONY_CDC_TRANSFER_CONTEXT* WriteIdleList;
    volatile HARMONY_CDC_TRANSFER_CONTEXT* WritePendingList;
    
    bool IsActive;
    

}HARMONY_APP_COM_PORT;

/******************************************************
 * Application Mouse Object
 ******************************************************/

typedef struct
{
    /* Transfer handle */
    USB_DEVICE_HID_TRANSFER_HANDLE writeTransferHandle;
    USB_DEVICE_HID_TRANSFER_HANDLE readTransferHandle;

    /* USB HID active Protocol */
    uint8_t activeProtocol;

    /* USB HID current Idle */
    uint8_t idleRate;

    /* Tracks the progress of the report send */
    bool isTxBusy;
    
    /* Tracks the progress of the report read */
    bool isRxReady;
    
    /* pointer to tx buffer initialized on startup */
    uint8_t* TxBuffer;
    
    /* pointer to rx buffer initialized on startup */
    uint8_t* RxBuffer;
    
     /* Byes recieved on successful read */
   uint32_t ReceivedLength;

    /* SET IDLE timer */
    uint16_t setIdleTimer;
    
    bool IsActive;

}HARMONY_APP_MOUSE;

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 */

typedef struct
{
    /* Device layer handle returned by device layer open function */
    USB_DEVICE_HANDLE deviceHandle;

    /* Application's current state*/
    HARMONY_APP_STATES state;

    /* Device configured state */
    bool isUsbConfigured;
   
    size_t UsbConfigureCookie;
    size_t UsbConfigureCookieIsr;
    
    HARMONY_APP_COM_PORT comPorts[HARMONY_CDC_PORT_COUNT];
    
    HARMONY_APP_MOUSE Hid;

} HARMONY_APP_DATA;

#endif /* _HARMONY_PRIVATE_H */
/*******************************************************************************
 End of File
 */

