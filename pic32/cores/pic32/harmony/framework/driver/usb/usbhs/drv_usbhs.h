/******************************************************************************
  PIC32MX USB Module Driver Interface Header File

  Company:
    Microchip Technology Inc.
    
  File Name:
    drv_usbhs.h
	
  Summary:
    PIC32MX USB Module Driver Interface File
	
  Description:
    The PIC32MX Full speed USB Module driver provides a simple interface to
    manage the "USB" peripheral. This file defines the interface definitions and
    prototypes for the USB driver. The driver interface meets the requirements
    of the USB Host and Device Layer.                                                  
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2012 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to  you  the  right  to  use,  modify,  copy  and  distribute
Software only when embedded on a Microchip  microcontroller  or  digital  signal
controller  that  is  integrated  into  your  product  or  third  party  product
(pursuant to the  sublicense  terms  in  the  accompanying  license  agreement).

You should refer  to  the  license  agreement  accompanying  this  Software  for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS  WITHOUT  WARRANTY  OF  ANY  KIND,
EITHER EXPRESS  OR  IMPLIED,  INCLUDING  WITHOUT  LIMITATION,  ANY  WARRANTY  OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A  PARTICULAR  PURPOSE.
IN NO EVENT SHALL MICROCHIP OR  ITS  LICENSORS  BE  LIABLE  OR  OBLIGATED  UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,  BREACH  OF  WARRANTY,  OR
OTHER LEGAL  EQUITABLE  THEORY  ANY  DIRECT  OR  INDIRECT  DAMAGES  OR  EXPENSES
INCLUDING BUT NOT LIMITED TO ANY  INCIDENTAL,  SPECIAL,  INDIRECT,  PUNITIVE  OR
CONSEQUENTIAL DAMAGES, LOST  PROFITS  OR  LOST  DATA,  COST  OF  PROCUREMENT  OF
SUBSTITUTE  GOODS,  TECHNOLOGY,  SERVICES,  OR  ANY  CLAIMS  BY  THIRD   PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE  THEREOF),  OR  OTHER  SIMILAR  COSTS.
*******************************************************************************/
//DOM-IGNORE-END

#ifndef _DRV_USBHS_H
#define _DRV_USBHS_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files (continued at end of file)
// *****************************************************************************
// *****************************************************************************
/*  This section lists the other files that are included in this file.  Also,
    see the bottom of the file for additional implementation header files that
    are also included
*/

#include <stdint.h>
#include <stdbool.h>
#include "usb/usb_common.h"
#include "usb/usb_chapter_9.h"
#include "driver/driver_common.h"
#include "system/int/sys_int.h"
#include "driver/usb/drv_usb.h"
#include "system/common/sys_module.h"
#include "peripheral/usbhs/plib_usbhs.h"
#include "usb/usb_hub.h"

// *****************************************************************************
// *****************************************************************************
// Section: USB Device Driver Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* USB Driver Endpoint Table Entry Size in bytes

  Summary:
    USB Driver Endpoint Table Entry Size in bytes

  Description:
    Defines the size of an entry in the endpoint table.

  Remarks:
    The endpoint table is only required for PIC32MX devices.
*/

#define DRV_USBHS_ENDPOINT_TABLE_ENTRY_SIZE  0 

#define DRV_USBHS_ENDPOINT_ALL 16

/*DOM-IGNORE-BEGIN*/extern DRV_USB_DEVICE_INTERFACE gDrvUSBHSDeviceInterface;/*DOM-IGNORE-END */
#define DRV_USBHS_DEVICE_INTERFACE /*DOM-IGNORE-BEGIN*/&gDrvUSBHSDeviceInterface/*DOM-IGNORE-END */

// *****************************************************************************
/* USB Driver Host Mode Interface Functions.

  Summary:
    USB Driver Host Mode Interface Functions.

  Description:
    The Host Controller Driver interface in the Host Layer Initialization data
    structure should be set to this value so that Host Layer can access the USB
    Driver Host Mode functions.

  Remarks:
    None.
*/

/*DOM-IGNORE-BEGIN*/extern DRV_USB_HOST_INTERFACE gDrvUSBHSHostInterface;/*DOM-IGNORE-END */
#define DRV_USBHS_HOST_INTERFACE /*DOM-IGNORE-BEGIN*/&gDrvUSBHSHostInterface/*DOM-IGNORE-END */

// *****************************************************************************
/* USB Driver Module Index Numbers

  Summary:
    USB driver index definitions

  Description:
    These constants provide USB driver index definitions.

  Remarks:
    These constants should be used in place of hard-coded numeric literals
    and should be passed into the DRV_USBHS_Initialize and DRV_USBHS_Open
    routines to identify the driver instance in use. These are not
    indicative of the number of modules that are actually supported by the
    microcontroller.
*/

#define DRV_USBHS_INDEX_0         0
#define DRV_USBHS_INDEX_1         1

// *****************************************************************************
// *****************************************************************************
// Section: USB Device Driver Data Types
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* USB Driver Host Pipe Handle

  Summary:
    Defines the USB Driver Host Pipe handle type

  Description:
    Defines the USB Driver Host Pipe handle type

  Remarks:
    None.
*/

typedef uintptr_t DRV_USBHS_HOST_PIPE_HANDLE;

// *****************************************************************************
/* USB Driver Host Pipe Handle Invalid

  Summary:
    Defines the USB Driver Host Pipe Invalid handle 

  Description:
    Defines the USB Driver Host Pipe Invalid handle 

  Remarks:
    None.
*/

#define DRV_USBHS_HOST_PIPE_HANDLE_INVALID ((DRV_USBHS_HOST_PIPE_HANDLE)(-1))

#define DRV_USBHS_DEVICE_ENDPOINT_ALL 16

// *****************************************************************************
/* USB Driver Events Enumeration

  Summary:
    Identifies the different events that the USB Driver provides.

  Description:
    Identifies the different events that the USB Driver provides.

  Remarks:
    None.
*/

typedef enum
{
    /* Bus error occurred and was reported */
    DRV_USBHS_EVENT_ERROR = DRV_USB_EVENT_ERROR,

    /* Host has issued a device reset */
    DRV_USBHS_EVENT_RESET_DETECT = DRV_USB_EVENT_RESET_DETECT,

    /* Resume detected while USB in suspend mode */
    DRV_USBHS_EVENT_RESUME_DETECT = DRV_USB_EVENT_RESUME_DETECT,

    /* Idle detected */
    DRV_USBHS_EVENT_IDLE_DETECT = DRV_USB_EVENT_IDLE_DETECT,

    /* Stall handshake has occurred */
    DRV_USBHS_EVENT_STALL = DRV_USB_EVENT_STALL,

    /* Either Device received SOF or SOF threshold was reached in the Host mode
       operation */
    DRV_USBHS_EVENT_SOF_DETECT = DRV_USB_EVENT_SOF_DETECT,

    /* Session valid */
    DRV_USBHS_EVENT_DEVICE_SESSION_VALID = DRV_USB_EVENT_DEVICE_SESSION_VALID,

    /* Session Invalid */
    DRV_USBHS_EVENT_DEVICE_SESSION_INVALID = DRV_USB_EVENT_DEVICE_SESSION_INVALID,

} DRV_USBHS_EVENT;

// *****************************************************************************
/* USB Operating Modes Enumeration

  Summary:
    Provides enumeration of operating modes supported by USB.

  Description:
    This data type provides enumeration of the operating modes supported by the
    USB module.

  Remarks:
    None.
*/

typedef enum
{
    /* The driver should be able to switch between host and device mode */
    DRV_USBHS_OPMODE_DUAL_ROLE  = DRV_USB_OPMODE_DUAL_ROLE,

    /* The driver should support device mode operation only */
    DRV_USBHS_OPMODE_DEVICE  = DRV_USB_OPMODE_DEVICE,

    /* The driver should support host mode operation only */
    DRV_USBHS_OPMODE_HOST  = DRV_USB_OPMODE_HOST,

    /* The driver should support the OTG protocol */
    DRV_USBHS_OPMODE_OTG = DRV_USB_OPMODE_OTG

} DRV_USBHS_OPMODES;

// *****************************************************************************
/* Type of the USB Event Callback Function

  Summary:
    Type of the USB event callback function

  Description:
    Type of the USB event callback function. The client should register an event
    callback function of this type when it intends to receive events from the USB
    driver. The event callback function is registered using the
    DRV_USBHS_ClientEventCallBackSet() function. 

  Parameters:
    hClient    - handle to driver client that registered this callback function
    eventType  - Event type
    eventData  - Event relevant data

  Returns:
    None.

  Remarks:
    None.

*/

typedef void (*DRV_USBHS_EVENT_CALLBACK) 
(
    uintptr_t hClient, 
    DRV_USBHS_EVENT  eventType,
    void * eventData   
);

// *****************************************************************************
/* USB Root Hub Application Hooks (Port over current detection).

  Summary:
     USB Root Hub Application Hooks (Port over current detection).

  Description:
    A function of the type defined here should be provided to the driver root
    hub to check for port over current condition.  This function will be called
    periodically by the root hub driver to check the over current status of the
    port. It should continue to return true while the over current condition
    exists on the port. It should return false when the over current condition
    does not exist. 

  Remarks:
    None.
*/

typedef bool (* DRV_USBHS_ROOT_HUB_PORT_OVER_CURRENT_DETECT)(uint8_t port);

// *****************************************************************************
/* USB Root Hub Application Hooks (Port Power Enable/ Disable).

  Summary:
     USB Root Hub Application Hooks (Port Power Enable/ Disable).

  Description:
    A function of the type defined here should be provided to the driver root to
    control port power.  The root hub driver will call this function when it
    needs to enable port power. If the application circuit contains a VBUS
    switch, the switch should be accessed and controlled by this function. If
    the enable parameter is true, the switch should be enabled and VBUS should
    be available on the port. If the enable parameter is false, the
    switch should be disabled and VBUS should not be available on the port.  

  Remarks:
    None.
*/

typedef void (* DRV_USBHS_ROOT_HUB_PORT_POWER_ENABLE)
(
    uint8_t port, 
    bool control
);

// *****************************************************************************
/* USB Root Hub Application Hooks (Port Indication)

  Summary:
     USB Root Hub Application Hooks (Port Indication)

  Description:
    A function of the type defined here should be provided to the driver root to
    implement Port Indication.  The root hub driver calls this function when it
    needs to update the state of the port indication LEDs. The application can
    choose to implement the Amber and Green colors as one LED or 2 different
    LEDs.  The root hub driver specifies the color and the indicator attribute
    (on, off or blinking) when it calls this function 

  Remarks:
    None.
*/

typedef void(* DRV_USBHS_ROOT_HUB_PORT_INDICATION)
(
    uint8_t port, 
    USB_HUB_PORT_INDICATOR_COLOR color, 
    USB_HUB_PORT_INDICATOR_STATE state
);


// *****************************************************************************
/* USB Device Driver Initialization Data

  Summary:
    Contains all the data necessary to initialize the USB device

  Description:
    This structure contains all the data necessary to initialize the USB driver.
    A pointer to a structure of this format containing the desired
    initialization data must be passed into the DRV_USBHS_Initialize routine.

  Remarks:
    None.
*/

typedef struct
{
    /* System Module Initialization */
    SYS_MODULE_INIT moduleInit;     
    
    /* Identifies the USB peripheral to be used. This should be the USB PLIB
       module instance identifier. */
    uint8_t usbID; 
    
    /* This should be set to true if the USB module must stop operation in IDLE
       mode */
    bool stopInIdle;     

    /* This should be set to true if the USB module must suspend when the CPU
       enters sleep mode. */
    bool suspendInSleep; 

    /* Specify the interrupt source for the USB module. This should be Interrupt
       PLIB Interrupt source identifier for the USB module instance specified in
       usbID. */
    INT_SOURCE interruptSource;

    /* Specify the interrupt source for the USB module specific DMA contoller.
     * This hsould be INterrupt PLIB Interrupt source identified for the USB
     * module isntnce specified in usbID. */
    INT_SOURCE interruptSourceUSBDma;

    /* Specify the operational speed of the USB module. This should always be
       set to USB_SPEED_FULL. */
    USB_SPEED operationSpeed; 

    /* Specify the operation mode of the USB module. This defines if the USB
     * module will support Device, Host or Dual Role operation */
    DRV_USBHS_OPMODES operationMode;  

    /* A pointer to the endpoint descriptor table. This should be aligned at 512
       byte address boundary. The size of the table is equal to the
       DRV_USBHS_ENDPOINT_TABLE_ENTRY_SIZE times the number of endpoints needed
       in the application. */
    void * endpointTable; 

    /* Root hub available current in mA. This specifies the amount of current
       that root hub can provide to the attached device. This should be
       specified in mA. This is required when the driver is required to operate
       in host mode. */
    uint32_t rootHubAvailableCurrent;

    /* When operating in Host mode, the application can specify a Root Hub port
       enable function. This parameter should point to Root Hub port enable
       function. If this parameter is NULL, it implies that the Port is always
       enabled. */
    DRV_USBHS_ROOT_HUB_PORT_POWER_ENABLE portPowerEnable;

    /* When operating in Host mode, the application can specify a Root Port
       Indication. This parameter should point to the Root Port Indication
       function. If this parameter is NULL, it implies that Root Port Indication
       is not supported. */
    DRV_USBHS_ROOT_HUB_PORT_INDICATION portIndication;

    /* When operating is Host mode, the application can specify a Root Port
       Overcurrent detection. This parameter should point to the Root Port
       Indication function. If this parameter is NULL, it implies that
       Overcurrent detection is not supported. */
    DRV_USBHS_ROOT_HUB_PORT_OVER_CURRENT_DETECT portOverCurrentDetect;

} DRV_USBHS_INIT;

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines - System Level
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    SYS_MODULE_OBJ DRV_USBHS_Initialize
    ( 
        const SYS_MODULE_INDEX drvIndex,
        const SYS_MODULE_INIT * const init    
    )
    
  Summary:
    Initializes the USB driver.
	
  Description:
    This routine initializes the USB driver, making it ready for clients to
    open and use it.
	
  Precondition:
    None.
	
  Parameters:
    drvIndex -  Ordinal number of driver instance to be initialized

    init - Pointer to a data structure containing any data necessary to
    initialize the driver. This should be a DRV_USBHS_INIT structure reference
    typecast to SYS_MODULE_INIT reference.
				
  Returns:
    If successful, returns a valid handle to a driver object. Otherwise, it
    returns SYS_MODULE_OBJ_INVALID. The returned object must be passed as
    argument to DRV_USBHS_Status routines.
	
  Example:
    <code>
     // The following code snippet shows an example initialization of the
     // driver. The USB module to be used is USB1.  The module should not
     // automatically suspend when the  microcontroller enters Sleep mode.  The
     // module should continue  operation when the module enters Idle mode.  The
     // power state is set to run at full clock speeds. Device Mode operation
     // should be at FULL speed. The size of the endpoint table is set for 2
     // endpoints.
    
    DRV_USBHS_INIT moduleInit;

    uint8_t __attribute__((aligned(512))) endpointTable[DRV_USBHS_ENDPOINT_TABLE_ENTRY_SIZE * 2];
    
    usbInitData.usbID               = USB_ID_1;
    usbInitData.opMode              = DRV_USBHS_OPMODE_DEVICE;
    usbInitData.stopInIdle          = false;
    usbInitData.suspendInSleep      = false;
    usbInitData.operationSpeed      = USB_SPEED_FULL;
    usbInitData.interruptSource     = INT_SOURCE_USB;
    
    usbInitData.sysModuleInit.powerState = SYS_MODULE_POWER_RUN_FULL ;
    
    // This is how this data structure is passed to the initialize
    // function.
    
    DRV_USBHS_Initialize(DRV_USBHS_INDEX_0, (SYS_MODULE_INIT *) &usbInitData);
    
    </code>
	
  Remarks:
    This routine must be called before any other USB driver routine is called.
    This routine should only be called once during system initialization unless
    DRV_USBHS_Deinitialize is called to deinitialize the driver instance. If the
    driver is built for static mode, then the initialization data structure is
    ignored. The static overrides provided in system_config.h are considered
    instead.                                   
*/

SYS_MODULE_OBJ DRV_USBHS_Initialize 
(
    const SYS_MODULE_INDEX drvIndex,
    const SYS_MODULE_INIT * const init
);

// *****************************************************************************
/* Function:
    SYS_STATUS DRV_USBHS_Status ( SYS_MODULE_OBJ object )

  Summary:
    Provides the current status of the USB driver module.

  Description:
    This routine provides the current status of the USB driver module.

  Precondition:
    Function DRV_USBHS_Initialize must have been called before calling this
    function

  Parameters:
    object  - Driver object handle, returned from the DRV_USBHS_Initialize routine

  Returns:
    SYS_STATUS_READY - Indicates that the driver is ready
    SYS_STATUS_UNINITIALIZED - Indicates that the driver has never been
    initialized

  Example:
    <code>
    SYS_MODULE_OBJ      object;     // Returned from DRV_USBHS_Initialize
    SYS_STATUS          status;
    DRV_USBHS_INIT moduleInit;

    uint8_t __attribute__((aligned(512))) endpointTable[DRV_USBHS_ENDPOINT_TABLE_ENTRY_SIZE * 2];
    
    usbInitData.usbID               = USB_ID_1;
    usbInitData.opMode              = DRV_USBHS_OPMODE_DEVICE;
    usbInitData.stopInIdle          = false;
    usbInitData.suspendInSleep      = false;
    usbInitData.operationSpeed      = USB_SPEED_FULL;
    usbInitData.interruptSource     = INT_SOURCE_USB;
    
    usbInitData.sysModuleInit.powerState = SYS_MODULE_POWER_RUN_FULL ;
    
    // This is how this data structure is passed to the initialize
    // function.
    
    DRV_USBHS_Initialize(DRV_USBHS_INDEX_0, (SYS_MODULE_INIT *) &usbInitData);
    
    // The status of the driver can be checked.
    status = DRV_USBHS_Status(object);
    if(SYS_STATUS_READY == status)
    {
        // Driver is ready to be opened.
    }

    </code>

  Remarks:
    None.
*/

SYS_STATUS DRV_USBHS_Status ( SYS_MODULE_OBJ object );

// *****************************************************************************
/* Function:
    void DRV_USBHS_Tasks( SYS_MODULE_OBJ object )

  Summary:
    Maintains the driver's state machine when the driver is configured for 
    polled mode.

  Description:
    Maintains the driver's state machine when the driver is configured for 
    polled mode. This function should be called from the system tasks routine.

  Precondition:
    The DRV_USBHS_Initialize routine must have been called for the specified
    USB driver instance.

  Parameters:
    object - Object handle for the specified driver instance (returned from
    DRV_USBHS_Initialize)

  Returns:
    None

  Example:
    <code>
    SYS_MODULE_OBJ      object;     // Returned from DRV_USBHS_Initialize

    while (true)
    {
        DRV_USBHS_Tasks(object);

        // Do other tasks
    }
    </code>

  Remarks:
    This routine is normally not called  directly  by  an  application.   It  is
    called by the system's Tasks routine (SYS_Tasks). This function will never
    block.  
*/

void DRV_USBHS_Tasks(SYS_MODULE_OBJ object);

// *****************************************************************************
/* Function:
    void DRV_USBHS_Tasks_ISR( SYS_MODULE_OBJ object )

  Summary:
    Maintains the driver's state machine and implements its ISR.

  Description:
    This routine is used to maintain the driver's internal state machine and
    implement its ISR for interrupt-driven implementations.

  Precondition:
    The DRV_USBHS_Initialize routine must have been called for the specified
    USB driver instance.

  Parameters:
    object - Object handle for the specified driver instance (returned from
    DRV_USBHS_Initialize)

  Returns:
    None

  Example:
    <code>
    SYS_MODULE_OBJ object;     // Returned from DRV_USBHS_Initialize

    while (true)
    {
        DRV_USBHS_Tasks_ISR (object);

        // Do other tasks
    }
    </code>

  Remarks:
    This routine should be called from the USB interrupt service routine. In
    case of multiple USB modules, it should be ensured that the correct USB
    driver system module object is passed to this routine.
*/

void DRV_USBHS_Tasks_ISR( SYS_MODULE_OBJ object );

// *****************************************************************************
/* Function:
    void DRV_USBHS_Tasks_ISR_USBDMA( SYS_MODULE_OBJ object )

  Summary:
    Maintains the driver's DMA Transfer state machine and implements its ISR.

  Description:
    This routine is used to maintain the driver's internal DMA Transfer state
    machine and implement its ISR for interrupt-driven implementations.

  Precondition:
    The DRV_USBHS_Initialize routine must have been called for the specified
    USB driver instance.

  Parameters:
    object - Object handle for the specified driver instance (returned from
    DRV_USBHS_Initialize)

  Returns:
    None

  Example:
    <code>
    SYS_MODULE_OBJ object;     // Returned from DRV_USBHS_Initialize

    while (true)
    {
        DRV_USBHS_Tasks_ISR_USBDMA (object);

        // Do other tasks
    }
    </code>

  Remarks:
    This routine should be called from the USB DMA interrupt service routine. In
    case of multiple USB modules, it should be ensured that the correct USB
    driver system module object is passed to this routine.
*/

void DRV_USBHS_Tasks_ISR_USBDMA( SYS_MODULE_OBJ object );

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines - Client Level
// *****************************************************************************
// *****************************************************************************

// ****************************************************************************
/* Function:
    DRV_HANDLE DRV_USBHS_Open
    ( 
        const SYS_MODULE_INDEX drvIndex,
        const DRV_IO_INTENT intent
    )
    
  Summary:
    Opens the specified USB driver instance and returns a handle to it.
	
  Description:
    This routine opens the specified USB driver instance and provides a
    handle that must be provided to all other client-level operations to
    identify the caller and the instance of the driver. The intent flag
    should always be
    DRV_IO_INTENT_EXCLUSIVE|DRV_IO_INTENT_READWRITE|DRV_IO_INTENT_NON_BLOCKING.
    Any other setting of the intent flag will return a invalid driver
    handle. A driver instance can only support one client. Trying to open a
    driver that has an existing client will result in an unsuccessful
    function call.
	
  Precondition:
    Function DRV_USBHS_Initialize must have been called before calling this
    function.
	
  Parameters:
    drvIndex -  Driver instance that client will use
    intent -    Should always be
                DRV_IO_INTENT_EXCLUSIVE|DRV_IO_INTENT_READWRITE|
                DRV_IO_INTENT_NON_BLOCKING.
				
  Returns:
    If successful, valid driver handle for the client to use when interfacing
    with the driver. The function will return DRV_HANDL_INVALID if the driver
    could not be opened. This can happen if the driver initialization was not
    complete or if an internal error has occurred.
	
  Example:
    <code>

    DRV_HANDLE handle;

    // This code snippet assumes that the driver has been initialized.
    handle = DRV_USBHS_Open(DRV_USBHS_INDEX_0, DRV_IO_INTENT_EXCLUSIVE| DRV_IO_INTENT_READWRITE| DRV_IO_INTENT_NON_BLOCKING);

    if(DRV_HANDLE_INVALID == handle)
    {
        // The application should try opening the driver again.
    }
    
    </code>
	
  Remarks:
    The handle returned is valid until the DRV_USBHS_Close routine is called.
    The functioin will typically return DRV_HANDLE_INVALID if the driver was not
    initialized. In such a case the client should try to open the driver again.
*/

DRV_HANDLE DRV_USBHS_Open
(
    const SYS_MODULE_INDEX drvIndex,
    const DRV_IO_INTENT intent  
);

// *****************************************************************************
/* Function:
    void DRV_USBHS_Close( DRV_HANDLE handle )

  Summary:
    Closes an opened-instance of the USB driver.

  Description:
    This routine closes an opened-instance of the USB driver, invalidating the
    handle.

  Precondition:
    The DRV_USBHS_Initialize routine must  have  been  called  for  the  specified
    USB driver instance.  DRV_USBHS_Open must have been called to obtain  a  valid
    opened device handle.

  Parameters:
    handle  - Client's driver handle (returned from DRV_USBHS_Open)

  Returns:
    None

  Example:
    <code>
    DRV_HANDLE handle;  // Returned from DRV_USBHS_Open

    DRV_USBHS_Close(handle);
    </code>

  Remarks:
    After calling this routine, the handle passed in "handle" must not  be  used
    with any of the other driver routines.  A new handle must be obtained by
    calling  DRV_USBHS_Open  before  the  caller  may  use   the   driver
    again.
*/

void DRV_USBHS_Close( DRV_HANDLE handle );

// *****************************************************************************
/* Function:
    void DRV_USBHS_ClientEventCallBackSet
    ( 
        DRV_HANDLE handle,
        uintptr_t hReferenceData,
        DRV_USBHS_EVENT_CALLBACK myEventCallBack 
    );

  Summary:
    This function sets up the event callback function that is invoked by the USB
    controller driver to notify the a client of USB bus events.
	
  Description:
    This function sets up the event callback function that is invoked by the USB
    controller driver to notify the client of USB bus events. The call back is
    disabled by not calling this function after a USB_DRV_Open or by passing
    NULL for the myEventCallBack argument. When the callback function is called,
    the hReferenceData argument is returned.
	
  Precondition:
    None.
	
  Parameters:
    handle - Client's driver handle (returned from DRV_USBHS_Open)

    hReferenceData - object (could be a pointer) that is returned with the
    callback.  
    
    myEventCallBack -  Call back function for all USB events.
	
  Returns:
    None.
	
  Example:
    <code>

     // Set the client event callback for the Device Layer.  The
     // USBDeviceLayerEventHandler() function is the event handler. When this
     // event handler is invoked by the driver, the driver returns back the
     // second argument specified in the below function (which in this case is
     // the device layer data structure). This allows the application firmware
     // to identify, as an example, the device layer object associated with this
     // callback
     //
    
    DRV_USBHS_ClientEventCallBackSet(myUSBDevice.usbDriverHandle, (uintptr_t)&myUSBDevice, USBDeviceLayerEventHandler);
    
    </code>
	
  Remarks:
    Typical usage of the USB Driver requires a client to register a callback.                                                                         
*/

void DRV_USBHS_ClientEventCallBackSet
( 
    DRV_HANDLE handle,
    uintptr_t  hReferenceData ,
    DRV_USB_EVENT_CALLBACK myEventCallBack
);

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines - Device Mode Operation
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void DRV_USBHS_DEVICE_AddressSet(DRV_HANDLE handle, uint8_t address);

  Summary:
    This function will set the USB module address that is obtained from the host.

  Description:
    This function will set the USB module address  that  is  obtained  from  the
    host in a setup transaction.  The address is obtained from  the  SET_ADDRESS
    command issued by the host.   The  primary  (first)  client  of  the  driver
    uses this function to set the module's USB address after decoding the  setup
    transaction from the host.

  Precondition:
    None.

  Parameters:
    handle       - Client's driver handle (returned from DRV_USBHS_Open)
    address      - The address of this module on the USB bus

  Returns:
    None.

  Example:
    <code>
    // This function should be called by the first client of the driver,
    // which is typically the device layer. The address to set is obtained
    // from the host during enumeration.

    DRV_USBHS_DEVICE_AddressSet(deviceLayer, 4);
    </code>

  Remarks:
    None.
*/

void DRV_USBHS_DEVICE_AddressSet(DRV_HANDLE handle, uint8_t address);

// *****************************************************************************
/* Function:
    USB_SPEED DRV_USBHS_DEVICE_CurrentSpeedGet(DRV_HANDLE handle);

  Summary:
    This function will return the USB speed at which device is operating.

  Description:
    This function will return the USB speed at which device is operating. 

  Precondition:
    Only valid after device is attached to host.

  Parameters:
    handle - Client's driver handle (returned from DRV_USBHS_Open)

  Returns:
    Returns a member of the USB_SPEED type.  

  Example:
    <code>
    // Get the current speed.
    
    USB_SPEED deviceSpeed;
    
    deviceSpeed = DRV_USBHS_DEVICE_CurrentSpeedGet(deviceLayer);
    
    if(deviceLayer == USB_SPEED_HIGH)
    {
        // Possibly adjust buffers for higher throughput.
    } 
    
    </code>

  Remarks:
    None.
*/

USB_SPEED DRV_USBHS_DEVICE_CurrentSpeedGet(DRV_HANDLE handle);

// *****************************************************************************
/* Function:
    uint16_t DRV_USBHS_DEVICE_SOFNumberGet(DRV_HANDLE handle);

  Summary:
    This function will return the USB SOF packet number.

  Description:
    This function will return the USB SOF packet number..

  Precondition:
    This function will return a valid value only when the device is attached to
    the bus. The SOF packet count will not increment if the bus is suspended.

  Parameters:
    handle       - Client's driver handle (returned from DRV_USBHS_Open)

  Returns:
    Returns SOF packet number.

  Example:
    <code>
    // Get the current speed.

    uint16_t sofNumber;

    sofNumber = DRV_USBHS_DEVICE_SOFNumberGet(DRV_HANDLE handle);

    if(sofNumber > 0)
    {
        // use the packet number.
    }
    else
    {
        // error
    }

    </code>

  Remarks:
    None.
*/

uint16_t DRV_USBHS_DEVICE_SOFNumberGet(DRV_HANDLE handle);

// *****************************************************************************
/* Function:
    void DRV_USBHS_DEVICE_Attach(DRV_HANDLE handle);

  Summary:
    This function will attach the device to the USB.

  Description:
    This function will attach the device to the USB.  It does this  by  enabling
    the pull up resistors on the D+ or D- lines. This function should be called
    when the driver client is ready  to  receive  communication  from  the  host
    (typically after all initialization is complete). The USB 2.0 specification
    requires VBUS to be detected before the data line pull-ups are enabled. The
    application must ensure the same.

  Precondition:
    Client handle should be valid.

  Parameters:
    handle - Client's driver handle (returned from DRV_USBHS_Open)

  Returns:
    None.

  Example:
    <code>

    // Open the device driver and attach the device to the USB.
    handle = DRV_USBHS_Open(DRV_USBHS_INDEX_0, DRV_IO_INTENT_EXCLUSIVE| DRV_IO_INTENT_READWRITE| DRV_IO_INTENT_NON_BLOCKING);

    // Register a callback
    DRV_USBHS_ClientEventCallBackSet(handle, (uintptr_t)&myDeviceLayer, MyDeviceLayerEventCallback); 

    // The device can be attached when VBUS Session Valid event occurs
    void MyDeviceLayerEventCallback(uintptr_t handle, DRV_USBHS_EVENT event, void * hReferenceData)
    {
        switch(event)
        {
            case DRV_USBHS_EVENT_DEVICE_SESSION_VALID:
                // A valid VBUS was detected.    
                DRV_USBHS_DEVICE_Attach(handle);
                break;

            case DRV_USBHS_EVENT_DEVICE_SESSION_INVALID:
                // VBUS is not valid anymore. The device can be disconnected.
                DRV_USBHS_DEVICE_Detach(handle);
                break;

            default:
                break;
            }
        }
    }

    </code>

  Remarks:
    None.
*/

void DRV_USBHS_DEVICE_Attach(DRV_HANDLE handle);

// *****************************************************************************
/* Function:
    void DRV_USBHS_DEVICE_Detach(DRV_HANDLE handle);

  Summary:
    This function will detach the device from the USB. 

  Description:
    This function will detach  the  device  from  the  USB.   It  does  this  by
    disabling the pull up resistors on the D+ or D- lines. This function should
    be called when the application wants to disconnect the device  from  the
    bus (typically to implement a soft detach or switch  to  host  mode
    operation).  A self powered device should detached from the bus when the
    VBUS is not valid.

  Precondition:
    Client handle should be valid.

  Parameters:
    handle - Client's driver handle (returned from DRV_USBHS_Open)

  Returns:
    None.

  Example:
    <code>

    // Open the device driver and attach the device to the USB.
    handle = DRV_USBHS_Open(DRV_USBHS_INDEX_0, DRV_IO_INTENT_EXCLUSIVE| DRV_IO_INTENT_READWRITE| DRV_IO_INTENT_NON_BLOCKING);

    // Register a callback
    DRV_USBHS_ClientEventCallBackSet(handle, (uintptr_t)&myDeviceLayer, MyDeviceLayerEventCallback); 

    // The device can be detached when VBUS Session Invalid event occurs
    void MyDeviceLayerEventCallback(uintptr_t handle, DRV_USBHS_EVENT event, void * hReferenceData)
    {
        switch(event)
        {
            case DRV_USBHS_EVENT_DEVICE_SESSION_VALID:
                // A valid VBUS was detected.    
                DRV_USBHS_DEVICE_Attach(handle);
                break;

            case DRV_USBHS_EVENT_DEVICE_SESSION_INVALID:
                // VBUS is not valid anymore. The device can be disconnected.
                DRV_USBHS_DEVICE_Detach(handle);
                break;

            default:
                break;
            }
        }
    }

    </code>

  Remarks:
    None.
*/

void DRV_USBHS_DEVICE_Detach(DRV_HANDLE handle);

// ****************************************************************************
/* Function:
    USB_ERROR DRV_USBHS_DEVICE_EndpointEnable
    (
        DRV_HANDLE handle,
        USB_ENDPOINT endpointAndDirection,
        USB_TRANSFER_TYPE transferType,
        uint16_t endpointSize
    );
    
  Summary:
    This function enables a endpoint for the specified direction and endpoint
    size.
	
  Description:
    This function enables a endpoint for the specified direction and endpoint
    size. The function will enable the endpoint for communication in one
    direction at a time. It must be called twice if the endpoint is required to
    communicate in both the directions, except for control endpoints. If the
    endpoint type is a control endpoint, the endpoint is always bi-directional
    and the function needs to be called only once.  
    
    The size of the endpoint must match the wMaxPacketSize reported in the
    endpoint descriptor for this endpoint. A transfer that is scheduled over
    this endpoint will be scheduled in wMaxPacketSize transactions. The function
    does not check if the endpoint is already in use. It is the client's
    responsibility to make sure that a endpoint is not accidentally re-used.
	
  Precondition:
    Client handle should be valid.
	
  Parameters:
    handle -                Client's driver handle (returned from
                            DRV_USBHS_Open)
    endpointAndDirection -  Specifies the endpoint and direction.
    transferType -          Should be USB_TRANSFER_TYPE_CONTROL for control
                            endpoint, USB_TRANSFER_TYPE_BULK for bulk
                            endpoint, USB_TRANSFER_TYPE_INTERRUPT for
                            interrupt endpoint and
                            USB_TRANSFER_TYPE_ISOCHRONOUS for isochronous
                            endpoint.
    endpointSize -          Maximum size (in bytes) of the endpoint as
                            reported in the endpoint descriptor.
							
  Returns:
    USB_ERROR_NONE - The endpoint was successfully enabled.
    USB_ERROR_DEVICE_ENDPOINT_INVALID - If the endpoint that is being accessed
    is out of the valid endpoint defined for this driver instance.  The value of
    DRV_USBHS_ENDPOINTS_NUMBER should be adjusted.
    USB_ERROR_PARAMETER_INVALID - The driver handle is invalid.
	
  Example:
    <code>
    // This code snippet shows an example of how to enable endpoint
    // 0 for control transfers. Note that for a control endpoint, the
    // direction parameter is ignored. A control endpoint is always
    // bi-directional. Endpoint size is 64 bytes.
    
    uint8_t ep;
    
    ep = USB_ENDPOINT_AND_DIRECTION(USB_DATA_DIRECTION_DEVICE_TO_HOST, 0);
    
    DRV_USBHS_DEVICE_EndpointEnable(handle, ep, USB_TRANSFER_TYPE_CONTROL, 64);
    
    // This code snippet shows an example of how to set up a endpoint
    // for BULK IN transfer. For an IN transfer, data moves from device
    // to host. In this example, endpoint 1 is enabled. The maximum
    // packet size is 64.
    
    uint8_t ep;
    
    ep = USB_ENDPOINT_AND_DIRECTION(USB_DATA_DIRECTION_DEVICE_TO_HOST, 1);
    
    DRV_USBHS_DEVICE_EndpointEnable(handle, ep, USB_TRANSFER_TYPE_BULK, 64);
    
    // If endpoint 1 must also be set up for BULK OUT, then the enable
    // function must be called again, as shown here.
    
    ep = USB_ENDPOINT_AND_DIRECTION(USB_DATA_DIRECTION_HOST_TO_DEVICE, 1);
    
    DRV_USBHS_DEVICE_EndpointEnable(handle, ep, USB_TRANSFER_TYPE_BULK, 64);
    </code>
	
  Remarks:
    None.                                                                    
*/

USB_ERROR DRV_USBHS_DEVICE_EndpointEnable
(
    DRV_HANDLE handle, 
    USB_ENDPOINT endpointAndDirection, 
    USB_TRANSFER_TYPE transferType,
    uint16_t endpointSize
);

// ***************************************************************************
/* Function:
    USB_ERROR DRV_USBHS_DEVICE_EndpointDisable
    (
        DRV_HANDLE handle,
        USB_ENDPOINT endpointAndDirection
    )
    
  Summary:
    This function disables an endpoint.
	
  Description:
    This function disables an endpoint. If the endpoint type is control type
    then both directions are disabled. For non-control endpoints, the function
    disables one direction at a time.
	
  Precondition:
    Client handle should be valid.

  Parameters:
    handle -                Client's driver handle (returned from
                            DRV_USBHS_Open)
    endpointAndDirection -  Specifies the endpoint and direction.
	
  Returns:
    USB_ERROR_NONE - The endpoint was successfully enabled.
    USB_ERROR_DEVICE_ENDPOINT_INVALID - If the endpoint that is being
    accessed is out of the valid endpoint defined for this driver instance.
	
  Example:
    <code>
    // This code snippet shows an example of how to disable
    // a control endpoint. Note that the direction parameter is ignored.
    // For a control endpoint, both the directions are disabled.
    
    USB_ENDPOINT ep;
    
    ep = USB_ENDPOINT_AND_DIRECTION(USB_DATA_DIRECTION_DEVICE_TO_HOST, 0);
    
    DRV_USBHS_DEVICE_EndpointDisable(handle, ep );
    
    // This code snippet shows an example of how to disable a BULK IN
    // endpoint
    
    USB_ENDPOINT ep;
    
    ep = USB_ENDPOINT_AND_DIRECTION(USB_DATA_DIRECTION_DEVICE_TO_HOST, 1);
    
    DRV_USBHS_DEVICE_EndpointDisable(handle, ep );
    
    </code>
	
  Remarks:
    None.                                                                    
*/

USB_ERROR DRV_USBHS_DEVICE_EndpointDisable
(
    DRV_HANDLE handle, 
    USB_ENDPOINT endpointAndDirection
);

// *****************************************************************************
/* Function:
    USB_ERROR DRV_USBHS_DEVICE_EndpointDisableAll(DRV_HANDLE handle) 
  
  Summary:
    This function disables all provisioned endpoints.

  Description:
    This function disables all provisioned endpoints in both directions. 
  
  Precondition:
    Client handle should be valid.

  Parameters:
    handle - Client's driver handle (returned from DRV_USBHS_Open)

  Returns:
    USB_ERROR_NONE - The function exited successfully.
    USB_ERROR_PARAMETER_INVALID - The driver handle is invalid.

  Example:
    <code>
    // This code snippet shows an example of how to disable all endpoints. 

    DRV_USBHS_DEVICE_EndpointDisableAll(handle);
    
    </code>

  Remarks:
    This function is typically called by the USB Device Layer to disable
    all endpoints on detecting bus reset.
*/

USB_ERROR DRV_USBHS_DEVICE_EndpointDisableAll(DRV_HANDLE handle); 

// ****************************************************************************
/* Function:
    USB_ERROR DRV_USBHS_DEVICE_EndpointStall
    (
        DRV_HANDLE handle,
        USB_ENDPOINT endpointAndDirection
    )
    
  Summary:
    This function stalls an endpoint in the specified direction.
	
  Description:
    This function stalls an endpoint in the specified direction.
	
  Precondition:
    Client handle should be valid.
	
  Parameters:
    handle - Client's driver handle (returned from DRV_USBHS_Open)

    endpointAndDirection -  Specifies the endpoint and direction.
	
  Returns:
    USB_ERROR_NONE - The endpoint was successfully enabled.
    USB_ERROR_PARAMETER_INVALID - The driver handle is not valid.
    USB_ERROR_DEVICE_ENDPOINT_INVALID - If the endpoint that is being
    accessed is out of the valid endpoint defined for this driver instance.
    USB_ERROR_OSAL_FUNCTION - An error with an OSAL function called in this
    function.
	
  Example:
    <code>
    // This code snippet shows an example of how to stall an endpoint. In
    // this case , endpoint 1 IN direction is stalled.
    
    USB_ENDPOINT ep;
    
    ep = USB_ENDPOINT_AND_DIRECTION(USB_DATA_DIRECTION_DEVICE_TO_HOST, 1);
    
    DRV_USBHS_DEVICE_EndpointStall(handle, ep);
    
    </code>
	
  Remarks:
    None.                                                                    
*/

USB_ERROR DRV_USBHS_DEVICE_EndpointStall
(
    DRV_HANDLE handle, 
    USB_ENDPOINT endpointAndDirection
);

// ****************************************************************************
/* Function:
    USB_ERROR DRV_USBHS_DEVICE_EndpointStallClear
    (
        DRV_HANDLE handle,
        USB_ENDPOINT endpointAndDirection
    )
    
  Summary:
    This function clears the stall on an endpoint in the specified direction.
	
  Description:
    This function clears the stall on an endpoint in the specified direction.
	
  Precondition:
    Client handle should be valid.
	
  Parameters:
    handle -                Client's driver handle (returned from
                            DRV_USBHS_Open)
    endpointAndDirection -  Specifies the endpoint and direction.
	
  Returns:
    USB_ERROR_NONE - The endpoint was successfully enabled.
    USB_ERROR_PARAMETER_INVALID - The driver handle is not valid.
    USB_ERROR_DEVICE_ENDPOINT_INVALID - If the endpoint that is being
    accessed is out of the valid endpoint defined for this driver instance.
	
  Example:
    <code>
    // This code snippet shows an example of how to clear a stall. In this
    // example. the stall on endpoint 1 IN direction is cleared.
    
    USB_ENDPOINT ep;
    
    ep = USB_ENDPOINT_AND_DIRECTION(USB_DATA_DIRECTION_DEVICE_TO_HOST, 1);
    
    DRV_USBHS_DEVICE_EndpointStallClear(handle, ep);
    
    </code>
	
  Remarks:
    None.                                                                    
*/

USB_ERROR DRV_USBHS_DEVICE_EndpointStallClear
(
    DRV_HANDLE handle, 
    USB_ENDPOINT endpointAndDirection
);

// *****************************************************************************
/* Function:
    bool DRV_USBHS_DEVICE_EndpointIsEnabled
    (
        DRV_HANDLE handle,
        USB_ENDPOINT endpointAndDirection
    )
    
  Summary:
    This function returns the enable/disable status of the specified endpoint
    and direction.
	
  Description:
    This function returns the enable/disable status of the specified endpoint
    and direction.
	
  Precondition:
    Client handle should be valid.
	
  Parameters:
    handle -                Client's driver handle (returned from
                            DRV_USBHS_Open)
    endpointAndDirection -  Specifies the endpoint and direction.
	
  Returns:
    Returns true if the endpoint is enabled, false otherwise.
	
  Example:
    <code>
    // This code snippet shows an example of how the
    // DRV_USBHS_DEVICE_EndpointIsEnabled() function can be used to obtain the
    // status of the endpoint 1 and IN direction.
    
    USB_ENDPOINT ep;
    
    ep = USB_ENDPOINT_AND_DIRECTION(USB_DATA_DIRECTION_DEVICE_TO_HOST, 1);
    
    if(DRV_USBHS_ENDPOINT_STATE_DISABLED ==
                DRV_USBHS_DEVICE_EndpointIsEnabled(handle, ep))
    {
        // Endpoint is disabled. Enable endpoint.
    
        DRV_USBHS_DEVICE_EndpointEnable(handle, ep, USB_ENDPOINT_TYPE_BULK, 64);
    
    }
    
    </code>
	
  Remarks:
    None.                                                                     
*/

bool DRV_USBHS_DEVICE_EndpointIsEnabled
(
    DRV_HANDLE client, 
    USB_ENDPOINT endpointAndDirection
);

// *****************************************************************************
/* Function:
    bool DRV_USBHS_DEVICE_EndpointIsStalled
    (
        DRV_HANDLE handle, 
        USB_ENDPOINT endpointAndDirection
    ) 
  
  Summary:
    This function returns the stall status of the specified endpoint and
    direction.

  Description:
    This function returns the stall status of the specified endpoint and
    direction.
  
  Precondition:
    Client handle should be valid.

  Parameters:
    handle - Client's driver handle (returned from DRV_USBHS_Open)
    endpointAndDirection    - Specifies the endpoint and direction.

  Returns:
    Returns true if endpoint is stalled, false otherwise.

  Example:
    <code>
    // This code snippet shows an example of how the
    // DRV_USBHS_DEVICE_EndpointIsStalled() function can be used to obtain the
    // stall status of the endpoint 1 and IN direction.

    USB_ENDPOINT ep;

    ep = USB_ENDPOINT_AND_DIRECTION(USB_DATA_DIRECTION_DEVICE_TO_HOST, 1);

    if(true == DRV_USBHS_DEVICE_EndpointIsStalled (handle, ep))
    {
        // Endpoint stall is enabled. Clear the stall.

        DRV_USBHS_DEVICE_EndpointStallClear(handle, ep);
        
    }

    </code>

  Remarks:
    None.
*/

bool DRV_USBHS_DEVICE_EndpointIsStalled
(
    DRV_HANDLE client, 
    USB_ENDPOINT endpoint
); 

// ***********************************************************************************
/* Function:
    USB_ERROR DRV_USBHS_DEVICE_IRPSubmit
    (
        DRV_HANDLE client,
        USB_ENDPOINT endpointAndDirection,
        USB_DEVICE_IRP * irp
    );
    
  Summary:
    This function submits a I/O Request Packet (IRP) for processing to the
    USB Driver.
	
  Description:
    This function submits a I/O Request Packet (IRP) for processing to the USB
    Driver. The IRP allows a client to send and receive data from the USB Host.
    The data will sent or received through the specified endpoint. The direction
    of the data transfer is indicated by the direction flag in the
    endpointAndDirection structure. Submitting an IRP arms the endpoint to
    either send data to or receive data from the host.  If an IRP is already
    being processed on the endpoint, then the subsequent IRP submit operation
    will be queued. The contents of the IRP (including the application buffers)
    should not be changed until the IRP has been processed.
    
    Particular attention should be paid to the size parameter of IRP. The
    following should be noted:
    
      * The size parameter while sending data to the host can be less than,
        greater than, equal to or be an exact multiple of maximum packet size
        for the endpoint. The maximum packet size for the endpoint determines
        the number of transactions required to process the IRP.
      * If the size parameter while sending data to the host is less than
        maximum packet size, the transfer will complete in one transaction.
      * If the size parameter while sending data to the host is greater
        than maximum packet size, the IRP will be processed in multiple
        transactions.
      * If the size parameter while sending data to the host is equal to or
        an exact multiple of the maximum packet size, the client can optionally
        ask the driver to send a Zero Length packet by specifying the
        USB_DEVICE_IRP_FLAG_DATA_COMPLETE flag as the flag parameter.
      * The size parameter while receiving data from the host must be an
        exact multiple of the maximum packet size of the endpoint. If this is
        not the case, the driver will return a USB_ERROR_IRP_SIZE_INVALID
        result. If while processing the IRP, the driver receives less than
        maximum packet size or a ZLP from the host, the driver considers the
        IRP as processed. The size parameter at this point contains the actual
        amount of data received from the host. The IRP status is returned as
        USB_DEVICE_IRP_STATUS_COMPLETED_SHORT.
      * If a ZLP needs to be sent to host, the IRP size should be specified
        as 0 and flag should be set as USB_DEVICE_IRP_FLAG_DATA_COMPLETE.
      * If the IRP size is an exact multiple of endpoint size, the client
        can request the driver to not send a ZLP, by specifying the
        USB_DEVICE_IRP_FLAG_DATA_PENDING. This flag indicates that there is
        more data pending in this transfer.
      * Specifying a size less than endpoint size along with the
        USB_DEVICE_IRP_FLAG_DATA_PENDING flag will cause the driver to return a
        USB_ERROR_IRP_SIZE_INVALID.
      * If the size is greater than endpoint size, and the flag is
        specified as USB_DEVICE_IRP_FLAG_DATA_PENDING, the driver will send
        multiple of endpoint size data.
		
  Precondition:
    Client handle should be valid.
	
  Parameters:
    handle -                Client's driver handle (returned from
                            DRV_USBHS_Open)
    endpointAndDirection -  Specifies the endpoint and direction.
    irp -                   Pointer to the USB_DEVICE_IRP structure.
	
  Returns:
    USB_ERROR_NONE - if the IRP was submitted successful.
    USB_ERROR_IRP_SIZE_INVALID - if the size parameter of the IRP is not
    correct. 
    USB_ERROR_PARAMETER_INVALID - If the client handle is not valid.
    USB_ERROR_ENDPOINT_NOT_CONFIGURED - If the endpoint is not enabled.
    USB_ERROR_DEVICE_ENDPOINT_INVALID - The specified endpoint is not valid.
    USB_ERROR_OSAL_FUNCTION - An OSAL call in the function did not complete
    successfully.
	
  Example:
    <code>
    // The following code snippet shows an example of how to schedule a
    // IRP to send data from device to host. Assume that max packet size
    // is 64 and endpoint is 1. In this example, the transfer is
    // processed as 3 transactions of 64, 64 and 2 bytes.
    
    USB_ENDPOINT ep;
    USB_DEVICE_IRP irp;
    
    ep.direction = USB_ENDPOINT_AND_DIRECTION(USB_DATA_DIRECTION_DEVICE_TO_HOST, 1);
    
    irp.data = myDataBufferToSend;
    irp.size = 130;
    irp.flags = USB_DEVICE_IRP_FLAG_DATA_COMPLETE;
    irp.callback = MyIRPCompletionCallback;
    irp.referenceData = (uintptr_t)&myDeviceLayerObj;
    
    if (DRV_USBHS_DEVICE_IRPSubmit(handle, ep, &irp) != USB_ERROR_NONE)
    {
        // This means there was an error.
    }
    else
    {
        // The status of the IRP can be checked.
        while(irp.status != USB_DEVICE_IRP_STATUS_COMPLETED)
        {
            // Wait or run a task routine.
        }
    }
    
    // The following code snippet shows how the client can request
    // the driver to send a ZLP when the size is an exact multiple of
    // end point size.
    
    irp.data = myDataBufferToSend;
    irp.size = 128;
    irp.flags = USB_DEVICE_IRP_FLAG_DATA_COMPLETE;
    irp.callback = MyIRPCompletionCallback;
    irp.referenceData = (uintptr_t)&myDeviceLayerObj;
    
    // Note that while  receiving data from the host, the size should
    // be an exact multiple maximum packet size of the endpoint. In the
    // example below, the DRV_USBHS_DEVICE_IRPSubmit() function will
    // return a USB_DEVICE_IRP_SIZE_INVALID value.
    
    ep = USB_ENDPOINT_AND_DIRECTION(USB_DATA_DIRECTION_HOST_TO_DEVICE, 1);
    
    irp.data = myDataBufferToSend;
    irp.size = 60; // THIS SIZE IS NOT CORRECT
    irp.flags = USB_DEVICE_IRP_FLAG_DATA_COMPLETE;
    irp.callback = MyIRPCompletionCallback;
    irp.referenceData = (uintptr_t)&myDeviceLayerObj;
    
    </code>
	
  Remarks:
    This function can be called from the ISR of the USB module to associated
    with the client.                                                                           
*/

USB_ERROR DRV_USBHS_DEVICE_IRPSubmit
(
    DRV_HANDLE client, 
    USB_ENDPOINT endpointAndDirection, 
    USB_DEVICE_IRP * irp
);

// **************************************************************************
/* Function:
    USB_ERROR DRV_USBHS_DEVICE_IRPCancelAll 
    (
        DRV_HANDLE client,
        USB_ENDPOINT endpointAndDirection
    );
    
  Summary:
    This function cancels all IRPs that are queued and in progress at the
    specified endpoint.
	
  Description:
    This function cancels all IRPs that are queued and in progress at the
    specified endpoint.
	
  Precondition:
    Client handle should be valid.
	
  Parameters:
    handle -                Client's driver handle (returned from
                            DRV_USBHS_Open)
    endpointAndDirection -  Specifies the endpoint and direction.
	
  Returns:
    USB_ERROR_NONE - The endpoint was successfully enabled.
    USB_ERROR_DEVICE_ENDPOINT_INVALID - If the endpoint that is being
    accessed is out of the valid endpoint defined for this driver instance.
    USB_ERROR_PARAMETER_INVALID - The driver handle is not valid.
    USB_ERROR_OSAL_FUNCTION - An OSAL function called in this function did not
    execute successfully.
	
  Example:
    <code>
    // This code snippet shows an example of how to cancel all IRPs.
    
    void MyIRPCallback(USB_DEVICE_IRP * irp)
    {
        // Check if this is setup command
    
        if(irp->status == USB_DEVICE_IRP_STATUS_SETUP)
        {
            if(IsSetupCommandSupported(irp->data) == false)
            {
                // This means that this setup command is not
                // supported. Stall the endpoint.
    
                DRV_USBHS_DEVICE_EndpointStall(handle, ep);
            }
         }
     }
    </code>
	
  Remarks:
    None.                                                                  
*/

USB_ERROR DRV_USBHS_DEVICE_IRPCancelAll 
(
    DRV_HANDLE client, 
    USB_ENDPOINT endpointAndDirection
);

// ****************************************************************************
/* Function:
    bool DRV_USBHS_HOST_EventsDisable
    (
        DRV_HANDLE handle
    );
    
  Summary:
    Disables host mode events.
	
  Description:
    This function disables the host mode events. This function is called by the
    Host Layer when it wants to execute code atomically. 
	
  Precondition:
    handle should be valid.
	
  Parameters:
    handle - handle to the driver
	
  Returns:
    The state of the event when this function was called.
	
  Example:
    <code>
    TBD.
    </code>
	
  Remarks:
    None.
*/

bool DRV_USBHS_HOST_EventsDisable
(
    DRV_HANDLE handle
);

// ****************************************************************************
/* Function:
    void DRV_USBHS_HOST_EventsEnable
    (
        DRV_HANDLE handle
        bool eventRestoreContext
    );
    
  Summary:
    Restores the events to the specified the original value.
	
  Description:
    This function will restore the enable disable state of the events.
    eventRestoreContext should be equal to the value returned by the
    DRV_USBHS_HOST_EventsDisable() function.
	
  Precondition:
    handle should be valid.
	
  Parameters:
    handle - handle to the driver

    eventRestoreContext - value returned by the DRV_USBHS_HOST_EventsDisable()
    function.
	
  Returns:
    None.
	
  Example:
    <code>
    TBD.
    </code>
	
  Remarks:
    None.
*/

void DRV_USBHS_HOST_EventsEnable
(
    DRV_HANDLE handle, 
    bool eventContext
);

void DRV_USBHS_DEVICE_RemoteWakeupStart(DRV_HANDLE handle);
void DRV_USBHS_DEVICE_RemoteWakeupStop(DRV_HANDLE handle);
USB_ERROR DRV_USBHS_DEVICE_TestModeExit(DRV_HANDLE handle, USB_TEST_MODE_SELECTORS testMode);
USB_ERROR DRV_USBHS_DEVICE_TestModeEnter(DRV_HANDLE handle, USB_TEST_MODE_SELECTORS testMode);

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines - Host Mode Operation
// *****************************************************************************
// *****************************************************************************

// ****************************************************************************
/* Function:
    void DRV_USBHS_HOST_IRPCancel(USB_HOST_IRP * inputIRP);
    
  Summary:
    Cancels the specified IRP.
	
  Description:
    This function attempts to cancel the specified IRP. If the IRP is queued and
    its processing has not started, it will be cancelled successfully. If the
    IRP in progress, the ongoing transaction will be allowed to complete. 
	
  Precondition:
    None.
	
  Parameters:
    inputIRP - IRP to cancel
	
  Returns:
    None.
	
  Example:
    <code>
    TBD.
    </code>
	
  Remarks:
    None.                                                                  
*/

void DRV_USBHS_HOST_IRPCancel(USB_HOST_IRP * inputIRP);

// ****************************************************************************
/* Function:
    void DRV_USBHS_HOST_PipeClose
    (
        DRV_USBHS_HOST_PIPE_HANDLE pipeHandle
    );
    
  Summary:
    Closes an open pipe.
	
  Description:
    This function closes an open pipe. Any IRPs scheduled on the pipe will be
    aborted and IRP callback functions will be called with the status as
    DRV_USB_HOST_IRP_STATE_ABORTED. The pipe handle will be become and will not
    accept IRPs.
	
  Precondition:
    The pipe handle should be valid and should.
	
  Parameters:
    pipeHandle - Handle to the pipe to close.
	
  Returns:
    None.
	
  Example:
    <code>
    TBD.
    </code>
	
  Remarks:
    None.                                                                  
*/

void DRV_USBHS_HOST_PipeClose
(
    DRV_USBHS_HOST_PIPE_HANDLE pipeHandle
);

// ****************************************************************************
/* Function:
    USB_ERROR DRV_USBHS_HOST_IRPSubmit
    (
        DRV_USBHS_HOST_PIPE_HANDLE  hPipe,
        USB_HOST_IRP * pInputIRP
    );
    
  Summary:
    Submits an IRP on a pipe.
	
  Description:
    This function submits an IRP on the specified Pipe. The IRP will be added to
    the queue and will be processed in turn. The data will be transferred on the
    bus based on the USB bus scheduling rules. When the IRP has been processed,
    the callback function specified in the IRP will be called. The IRP status
    will be updated to reflect the completion status of the IRP. 
	
  Precondition:
    The pipe handle should be valid.
	
  Parameters:
    hPipe - handle to the pipe to which the IRP has to be submitted.

    pInputIRP - pointer to the IRP
	
  Returns:
    USB_ERROR_NONE - the IRP was submitted successfully.
    USB_ERROR_OSAL_FUNCTION - An error occurred in an OSAL function called in
    this function.
	
  Example:
    <code>
    TBD.
    </code>
	
  Remarks:
    An IRP can also be submitted in an IRP callback function.                                                                  
*/

USB_ERROR DRV_USBHS_HOST_IRPSubmit
(
    DRV_USBHS_HOST_PIPE_HANDLE  hPipe,
    USB_HOST_IRP * pinputIRP
);

// ****************************************************************************
/* Function:
    DRV_USBHS_HOST_PIPE_HANDLE DRV_USBHS_HOST_PipeSetup 
    (
        DRV_HANDLE client,
        uint8_t deviceAddress, 
        USB_ENDPOINT endpointAndDirection,
        uint8_t hubAddress,
        uint8_t hubPort,
        USB_TRANSFER_TYPE pipeType, 
        uint8_t bInterval, 
        uint16_t wMaxPacketSize,
        USB_SPEED speed
    );
    
  Summary:
    Open a pipe with specified attributes.
	
  Description:
    This function opens a communication pipe between the host and device
    endpoint. The transfer type and other attributes are specified through the
    function parameters. The driver does not check for available bus bandwidth.
    This should be done by the application (the USB host layer in this case)
	
  Precondition:
    The driver handle should be valid.
	
  Parameters:
    client - handle to the driver.
    
    deviceAddress - USB Address of the device to connect to.
    
    endpoint - endpoint on the device to connect to.
    
    hubAddress - Address of the hub to which this device is connected. If not
    connected to hub, this should be set to 0. 

    hubPort - Port number of the hub to which this device is connected.

    pipeType - Transfer type of the pipe to open.
    
    bInterval - Polling interval in case of periodic transfers. This should be
    specified as defined by the USB 2.0 specification.

    wMaxPacketSize - This should be set to the endpoint size reported by the
    device in its configuration descriptors. This defines the maximum size of
    the transaction in a transfer on this pipe.

    speed - the speed of the pipe. This should match the speed at which the
    device connected to the host.

  Returns:
    Returns a valid pipe handle. Return DRV_USB_HOST_PIPE_HANDLE_INVALID if the
    pipe could not be created.
	
  Example:
    <code>
    TBD.
    </code>
	
  Remarks:
    None.                                                                  
*/

DRV_USBHS_HOST_PIPE_HANDLE DRV_USBHS_HOST_PipeSetup 
(
    DRV_HANDLE client,
    uint8_t deviceAddress, 
    USB_ENDPOINT endpointAndDirection,
    uint8_t hubAddress,
    uint8_t hubPort,
    USB_TRANSFER_TYPE pipeType, 
    uint8_t bInterval, 
    uint16_t wMaxPacketSize,
    USB_SPEED speed
);

// *****************************************************************************
// *****************************************************************************
// Section: Interface Routines - Root Hub
// *****************************************************************************
// *****************************************************************************

// ****************************************************************************
/* Function:
    void DRV_USBHS_ROOT_HUB_PortReset(DRV_HANDLE handle, uint8_t port );
    
  Summary:
    Resets the specified root hub port.
	
  Description:
    This function resets the root hub port. The reset duration is defined by
    DRV_USBHS_ROOT_HUB_RESET_DURATION. The status of the reset signalling can be
    checked using the DRV_USBHS_ROOT_HUB_PortResetIsComplete() function.
	
  Precondition:
    None.
	
  Parameters:
    handle - handle to the driver.

    port - port to reset.
	
  Returns:
    None.
	
  Example:
    <code>
    TBD.
    </code>
	
  Remarks:
    The root hub on this particular hardware only contains one port - port 0.                                                                  
*/

USB_ERROR DRV_USBHS_HOST_ROOT_HUB_PortReset(DRV_HANDLE handle, uint8_t port );

// ****************************************************************************
/* Function:
    bool DRV_USBHS_ROOT_HUB_PortResetIsComplete
    (
        DRV_HANDLE handle,
        uint8_t port
    );

  Summary:
    Returns true if the root hub has completed the port reset operation.

  Description:
    This function returns true if the port reset operation has completed. It
    should be called after the DRV_USB_HOST_ROOT_HUB_PortReset() function to
    check if the reset operation has completed.

  Precondition:
    None.

  Parameters:
    handle - handle to the driver.

    port - port to check

  Returns:
    true - if the reset signalling has completed.

    false - if the reset is in progress.

  Example:
    <code>
    TBD.
    </code>

  Remarks:
    The root hub on this particular hardware only contains one port - port 0.
*/

bool DRV_USBHS_HOST_ROOT_HUB_PortResetIsComplete(DRV_HANDLE handle, uint8_t port );

// ****************************************************************************
/* Function:
    void DRV_USBHS_ROOT_HUB_PortResume(DRV_HANDLE handle, uint8_t port );
    
  Summary:
    Resumes the specified root hub port.
	
  Description:
    This function resumes the root hub. The resume duration is defined by
    DRV_USBHS_ROOT_HUB_RESUME_DURATION. The status of the resume signalling can
    be checked using the DRV_USBHS_ROOT_HUB_PortResumeIsComplete() function.
	
  Precondition:
    None.
	
  Parameters:
    handle - handle to the driver.

    port - port to resume.
	
  Returns:
    None.
	
  Example:
    <code>
    TBD.
    </code>
	
  Remarks:
    The root hub on this particular hardware only contains one port - port 0.                                                                  
*/

USB_ERROR DRV_USBHS_HOST_ROOT_HUB_PortResume(DRV_HANDLE handle, uint8_t port);

// ****************************************************************************
/* Function:
    void DRV_USBHS_ROOT_HUB_PortSuspend(DRV_HANDLE handle, uint8_t port );
    
  Summary:
    Suspends the specified root hub port.
	
  Description:
    This function suspends the root hub port. 
	
  Precondition:
    None.
	
  Parameters:
    handle - handle to the driver.

    port - port to suspend.
	
  Returns:
    None.
	
  Example:
    <code>
    TBD.
    </code>
	
  Remarks:
    The root hub on this particular hardware only contains one port - port 0.                                                                  
*/

USB_ERROR DRV_USBHS_HOST_ROOT_HUB_PortSuspend(DRV_HANDLE handle, uint8_t port);

// ****************************************************************************
/* Function:
    USB_SPEED DRV_USBHS_HOST_ROOT_HUB_PortSpeedGet
    (
        DRV_HANDLE handle, 
        uint8_t port
    );
    
  Summary:
    Returns the speed of at which the port is operating.
	
  Description:
    This function returns the speed at which the port is operating.
	
  Precondition:
    None.
	
  Parameters:
    handle - handle to the driver.

    port - port to suspend.
	
  Returns:
    The speed at which the port is operating.
	
  Example:
    <code>
    TBD.
    </code>
	
  Remarks:
    The root hub on this particular hardware only contains one port - port 0.                                                                  
*/

USB_SPEED DRV_USBHS_HOST_ROOT_HUB_PortSpeedGet(DRV_HANDLE handle, uint8_t port);

// ****************************************************************************
/* Function:
    USB_SPEED DRV_USBHS_HOST_ROOT_HUB_BusSpeedGet(DRV_HANDLE handle);
    
  Summary:
    Returns the speed at which the bus to which this root hub is connected is
    operating.
	
  Description:
    This function returns the speed at which the bus to which this root hub is
    connected is operating.
	
  Precondition:
    None.
	
  Parameters:
    handle - handle to the driver.

  Returns:
    Function will always return USB_SPEED_FULL.
	
  Example:
    <code>
    TBD.
    </code>
	
  Remarks:
    None.
*/

USB_SPEED DRV_USBHS_HOST_ROOT_HUB_BusSpeedGet(DRV_HANDLE handle);

// ****************************************************************************
/* Function:
    uint32_t DRV_USBHS_HOST_ROOT_HUB_MaximumCurrentGet(DRV_HANDLE);
    
  Summary:
    Returns the maximum amount of current that this root hub can provide on the
    bus.
	
  Description:
    This function returns the maximum amount of current that this root hubn can
    provide on the bus.
	
  Precondition:
    None.
	
  Parameters:
    handle - handle to the driver.

  Returns:
    Function will always return USB_SPEED_FULL.
	
  Example:
    <code>
    TBD.
    </code>
	
  Remarks:
    None.
*/

uint32_t DRV_USBHS_HOST_ROOT_HUB_MaximumCurrentGet(DRV_HANDLE handle);

// ****************************************************************************
/* Function:
    uint8_t DRV_USBHS_HOST_ROOT_HUB_PortNumbersGet(DRV_HANDLE handle);

  Summary:
    Returns the number of ports this root hub contains.

  Description:
    This function returns the number of ports that this root hub contains.

  Precondition:
    None.

  Parameters:
    handle - handle to the driver.

  Returns:
    Function will always return 1.

  Example:
    <code>
    TBD.
    </code>

  Remarks:
    None.
*/

uint8_t DRV_USBHS_HOST_ROOT_HUB_PortNumbersGet(DRV_HANDLE handle);

// ****************************************************************************
/* Function:
    void DRV_USBHS_HOST_ROOT_HUB_OperationEnable
    (
        DRV_HANDLE handle, 
        bool enable
    );

  Summary:
    Enables or disabled root hub operation.

  Description:
    This function enables or disables root hub operation. When enabled, the root
    hub will detect devices attached to the port and will request the Host layer
    to enumerate the device. This function is called by the Host Layer when it
    is ready to receive enumeration requests from the host. If the operation is
    disabled, the root hub will not detect attached devices.

  Precondition:
    None.

  Parameters:
    handle - handle to the driver.

    enable - if true, operation is enabled. If false, operation is disabled.

  Returns:
    None.

  Example:
    <code>
    TBD.
    </code>

  Remarks:
    None.
*/

void DRV_USBHS_HOST_ROOT_HUB_OperationEnable(DRV_HANDLE handle, bool enable);

// ****************************************************************************
/* Function:
    bool DRV_USBHS_HOST_ROOT_HUB_OperationIsEnabled(DRV_HANDLE handle);

  Summary:
    Returns the operation enabled status of the root hub.

  Description:
    This function returns true if the DRV_USBHS_HOST_ROOT_HUB_OperationEnable()
    function has completed enabling the host.

  Precondition:
    None.

  Parameters:
    handle - handle to the driver.

  Returns:
    true - Root Hub Operation is enabled.

    false - Root Hub Operation is not enanbled yet.

  Example:
    <code>
    TBD.
    </code>

  Remarks:
    None.
*/

bool DRV_USBHS_HOST_ROOT_HUB_OperationIsEnabled(DRV_HANDLE handle);

// ****************************************************************************
/* Function:
    void DRV_USBHS_HOST_ROOT_HUB_Initialize
    (
        DRV_HANDLE handle,
        USB_HOST_DEVICE_OBJ_HANDLE usbHostDeviceInfo,
    )

  Summary:
    This function instantiates the root hub driver.

  Description:
    This function initializes the root hub driver. It is called by the host
    layer at the time of processing root hub devices. The host layer assigns a
    USB_HOST_DEVICE_INFO reference to this root hub driver. This identifies the
    relationship between the root hub and the host layer.

  Precondition:
    None.

  Parameters:
    handle - handle to the driver.

    usbHostDeviceInfo - reference provided by the host.

  Returns:
    None.

  Example:
    <code>
    TBD.
    </code>

  Remarks:
    None.
*/

void DRV_USBHS_HOST_ROOT_HUB_Initialize
(
    DRV_HANDLE handle,
    USB_HOST_DEVICE_OBJ_HANDLE usbHostDeviceInfo
);


// *****************************************************************************
// *****************************************************************************
// Section: Included Files (continued)
// *****************************************************************************
// *****************************************************************************
/*  The file included below maps the interface definitions above to appropriate
    static implementations, depending on build mode.
*/


#endif
