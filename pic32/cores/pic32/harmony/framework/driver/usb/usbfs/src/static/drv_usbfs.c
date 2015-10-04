/*******************************************************************************
  USB Controller Driver Core Routines.

  Company:
    Microchip Technology Inc.

  File Name:
    drv_usb.c

  Summary:
    USB Controller Driver Core Routines intended for static implementation.

  Description:
    The USB Controller driver provides a simple interface to manage the USB
    modules on Microchip microcontrollers.  This file Implements the core
    interface routines to be used both by the client(USB Host or Device layer)
    and the system for communicating with USB Contoller driver.  While building
    the driver from source, ALWAYS use this file in the build.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute Software
only when embedded on a Microchip microcontroller or digital  signal  controller
that is integrated into your product or third party  product  (pursuant  to  the
sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
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

// *****************************************************************************
// *****************************************************************************
// Section: Include Files
// *****************************************************************************
// *****************************************************************************

#include "system_config.h"

#if defined(_USB)

#include "driver/usb/usbfs/src/drv_usbfs_local.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************

/******************************************************
 * Hardware instance, endpoint table and client object
 * lumped together as group to save memory.
 ******************************************************/
DRV_USBFS_GROUP gDrvUSBGroup;

// *****************************************************************************
// *****************************************************************************
// Section: USB Controller Driver Interface Implementations
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    SYS_MODULE_OBJ _DRV_USBFS_MAKE_NAME(Initialize)
    ( 
        const SYS_MODULE_INIT * const init
    )

  Summary:
    static impementation of _DRV_USBFS_MAKE_NAME(Initialize) system interface function.

  Description:
    This is the static impementation of _DRV_USBFS_MAKE_NAME(Initialize) system interface
    function. Function performs the following task:
    - Initializes the neccessary USB module as per the instance init data
    - Updates internal data structure for the particular USB instance
    - Returns the USB instance value as a handle to the system
  
  Remarks:
    See drv_usb.h for usage information.
*/

SYS_MODULE_OBJ _DRV_USBFS_MAKE_NAME(Initialize)
(
    const SYS_MODULE_INIT * const init
)
{
    /* Start of local variable */
    DRV_USBFS_OBJ * pUSBDrvObj    = (DRV_USBFS_OBJ *)NULL;
    DRV_USBFS_INIT * pusbInit     = (DRV_USBFS_INIT *)NULL;
    SYS_MODULE_OBJ returnValue  = SYS_MODULE_OBJ_INVALID;
    /* End of local variable */

    /* Check if the specified driver index is in valid range */

    /* Check if this hardware instance was already initialized */
    if(gDrvUSBGroup.gDrvUSBObj.inUse == true)
    {
        /* Cannot initialize an object that is
         * already in use. */
        SYS_DEBUG(SYS_ERROR_INFO, "USB Driver: Hardware Instance already in use");
        returnValue = SYS_MODULE_OBJ_INVALID;
    }
    else
    {
        /* Grab the particular USB instance object*/
        gDrvUSBGroup.gDrvUSBObj.inUse = true;

        /* Assign to the local pointer the init data passed */
        pusbInit   = (DRV_USBFS_INIT *) init;
        pUSBDrvObj = &(gDrvUSBGroup.gDrvUSBObj);

        /* If this being built in an OS application, then create a mutex */
        OSAL_ASSERT(if(OSAL_MUTEX_Create(&pUSBDrvObj->mutexID) == OSAL_RESULT_TRUE), "Mutex create failed");

        /* Populate the driver instance object with required data */
        pUSBDrvObj->status  = SYS_STATUS_BUSY;
        pUSBDrvObj->operationMode  = pusbInit->operationMode;
        pUSBDrvObj->pBDT    = (DRV_USBFS_BDT_ENTRY *)(pusbInit->endpointTable);
        pUSBDrvObj->isOpened = false;
        pUSBDrvObj->pEventCallBack = NULL;

        /* Assign the endpoint table */
        pUSBDrvObj->endpointTable = &(gDrvUSBGroup.gDrvUSBEndpoints[0]);

        /* Enable USB module(U1PWRC<0>). This internally does the following:
         * - Start the USB clock
         * - Allow the USB interrupt to be activated
         * - Select USB as the owner of the necessary I/O pins
         * - Enable the USB transceiver
         * - Enable the USB comparators */

        PLIB_USB_Enable(DRV_USBFS_PERIPHERAL_ID);

        /* Setup the Hardware */
        if(pusbInit->stopInIdle)
        {
            PLIB_USB_StopInIdleEnable( DRV_USBFS_PERIPHERAL_ID );
        }
        else
        {
            PLIB_USB_StopInIdleDisable( DRV_USBFS_PERIPHERAL_ID );
        }
#ifdef PLIB_USB_ExistsAutomaticSuspend
        if(PLIB_USB_ExistsAutomaticSuspend(DRV_USBFS_PERIPHERAL_ID))
        {
            if(pusbInit->suspendInSleep)
            {
                PLIB_USB_AutoSuspendEnable( DRV_USBFS_PERIPHERAL_ID );
            }
            else
            {
                PLIB_USB_AutoSuspendDisable( DRV_USBFS_PERIPHERAL_ID );
            }
        }
#endif
        /* Setup the USB Module as per selected mode */
        switch(pusbInit->operationMode)
        {
            case DRV_USBFS_OPMODE_DEVICE:
                
                /* Initialize USB Controller for Device mode */
                _DRV_USBFS_DEVICE_INIT(pUSBDrvObj, 0);
                break;

            case DRV_USBFS_OPMODE_HOST:
                
                /* Initialize USB Controller for Host mode */
                _DRV_USBFS_HOST_INIT(pUSBDrvObj, 0, init);
                break;

            case DRV_USBFS_OPMODE_OTG:
                /* Not implemented at this point of time*/
                break;
            default:
                SYS_DEBUG(SYS_ERROR_INFO, "What mode are you trying?");
                break;
        }

        /* Assign the BDT table base address */
        PLIB_USB_BDTBaseAddressSet(DRV_USBFS_PERIPHERAL_ID ,
                (void *)((uint32_t)KVA_TO_PA(pUSBDrvObj->pBDT)));

        /* Indicate that the object is ready and in use
         * and return the driver handle */

        pUSBDrvObj->status = SYS_STATUS_READY;
        returnValue = (SYS_MODULE_OBJ) 0;
    }

    return (returnValue);

}/* end of _DRV_USBFS_MAKE_NAME(Initialize)() */

// *****************************************************************************
/* Function:
    void _DRV_USBFS_MAKE_NAME(Deinitialize)()

  Summary:
    static impementation of _DRV_USBFS_MAKE_NAME(Deinitialize) system interface function.

  Description:
    This is the static impementation of _DRV_USBFS_MAKE_NAME(Deinitialize) system interface
    function.

  Remarks:
    See drv_usb.h for usage information.
*/

void _DRV_USBFS_MAKE_NAME(Deinitialize)()
{
    DRV_USBFS_OBJ * pUSBDrvObj = NULL;

    if(gDrvUSBGroup.gDrvUSBObj.inUse == false)
    {
        /* Cannot deinitialize an object that is 
         * not in use. */
        SYS_DEBUG(SYS_ERROR_INFO, "USB Driver: Instance not in use");
    }
    else
    {
        pUSBDrvObj = &(gDrvUSBGroup.gDrvUSBObj);

        /* Release the USB instance object */
        pUSBDrvObj->inUse = false;

        /* Reset the open flag */
        pUSBDrvObj->isOpened = false;

        /* Delete the mutex */
        OSAL_ASSERT(if(OSAL_MUTEX_Delete(&pUSBDrvObj->mutexID) == OSAL_RESULT_TRUE), "Mutex delete failed");
        
        /* Uninitialize the status*/
        pUSBDrvObj->status = SYS_STATUS_UNINITIALIZED;

        pUSBDrvObj->pEventCallBack = NULL;

        /* Clear and disable the interrupts */
        _DRV_USBFS_InterruptSourceDisable(DRV_USBFS_INTERRUPT_SOURCE);
        _DRV_USBFS_InterruptSourceClear(DRV_USBFS_INTERRUPT_SOURCE);

        /* Turn off USB module */
        PLIB_USB_Disable(DRV_USBFS_PERIPHERAL_ID);

    }

    return;

} /* end of _DRV_USBFS_MAKE_NAME(Deinitialize)() */

// *****************************************************************************
/* Function:
    SYS_STATUS _DRV_USBFS_MAKE_NAME(Status)()

  Summary:
    static impementation of _DRV_USBFS_MAKE_NAME(Status) system interface function.

  Description:
    This is the static impementation of _DRV_USBFS_MAKE_NAME(Status) system interface
    function.

  Remarks:
    See drv_usb.h for usage information.
*/

SYS_STATUS _DRV_USBFS_MAKE_NAME(Status)()
{
    /* Return the status of the driver object */
    return(gDrvUSBGroup.gDrvUSBObj.status);
    
}/* end of _DRV_USBFS_MAKE_NAME(Status) */

// *****************************************************************************
/* Function:
    DRV_HANDLE _DRV_USBFS_MAKE_NAME(Open)
    (
        const DRV_IO_INTENT    ioIntent 
    )

  Summary:
    static impementation of _DRV_USBFS_MAKE_NAME(Open) client interface function.

  Description:
    This is the static impementation of _DRV_USBFS_MAKE_NAME(Open) client interface function.

  Remarks:
    See drv_usb.h for usage information.
*/

DRV_HANDLE _DRV_USBFS_MAKE_NAME(Open)
(
    const DRV_IO_INTENT    ioIntent 
)
{
    /* Check if USB instance object is ready*/
    if(gDrvUSBGroup.gDrvUSBObj.status != SYS_STATUS_READY)
    {
        /* The USB module should be ready */
        SYS_DEBUG(SYS_ERROR_INFO, "USB Driver: Was the driver initialized?");
    }
    else if(ioIntent != (DRV_IO_INTENT_EXCLUSIVE|DRV_IO_INTENT_NONBLOCKING |DRV_IO_INTENT_READWRITE))
    {
        /* The driver only supports this mode */
        SYS_DEBUG(SYS_ERROR_INFO, "USB Driver: IO intent mode not supported");
    }
    else if(gDrvUSBGroup.gDrvUSBObj.isOpened)
    {
        /* Driver supports exclusive open only */
        SYS_DEBUG(SYS_ERROR_INFO, "Driver already opened once. Cannot open again");
    }
    else
    {
        gDrvUSBGroup.gDrvUSBObj.isOpened = true;
        
        /* Return the client object address */
        return ((DRV_HANDLE)&(gDrvUSBGroup.gDrvUSBObj));
    }

    /* Return invalid handle */
    return DRV_HANDLE_INVALID;

}/* end of _DRV_USBFS_MAKE_NAME(Open)()*/

// *****************************************************************************
/* Function:
    bool _DRV_USBFS_MAKE_NAME(HOST_Resume)

  Summary:
    static implementation of _DRV_USBFS_MAKE_NAME(HOST_Resume)
    client interface function.

  Description:
    This is the static implementation of _DRV_USBFS_MAKE_NAME(HOST_Resume) client interface
    function. Function resumes a suspended BUS.

  Remarks:
    See drv_usb.h for usage information.
*/

bool _DRV_USBFS_MAKE_NAME(HOST_Resume)()
{
    /* Start of local variable */
    DRV_USBFS_OBJ * pUSBDrvObj = (DRV_USBFS_OBJ *)&(gDrvUSBGroup.gDrvUSBObj);
    bool returnValue = false;
    /* End of local variable */
    
    /* Check if the handle is valid */
    if(!(pUSBDrvObj->isOpened))
    {
        SYS_DEBUG(SYS_ERROR_INFO, "Driver not opened");
    }
    else
    {
        /* Enable the SOF */
        PLIB_USB_SOFEnable(DRV_USBFS_PERIPHERAL_ID);
        PLIB_USB_InterruptEnable(DRV_USBFS_PERIPHERAL_ID, USB_INT_SOF);
        returnValue = true;
    }
    return returnValue;

}/* end of _DRV_USBFS_MAKE_NAME(HOST_Resume)() */

// *****************************************************************************
/* Function:
    bool _DRV_USBFS_MAKE_NAME(HOST_Suspend)()

  Summary:
    static implementation of _DRV_USBFS_MAKE_NAME(HOST_Suspend)
    client interface function.

  Description:
    This is the static implementation of _DRV_USBFS_MAKE_NAME(HOST_Suspend) client
    interface function. Function suspends USB BUS.

  Remarks:
    See drv_usb.h for usage information.
*/

bool _DRV_USBFS_MAKE_NAME(HOST_Suspend)()
{
    /* Start of local variable */
    DRV_USBFS_OBJ * pUSBDrvObj = (DRV_USBFS_OBJ *)&(gDrvUSBGroup.gDrvUSBObj);
    bool returnValue = false;
    /* End of local variable */

    /* Check if the handle is valid */
    if(!(pUSBDrvObj->isOpened))
    {
        SYS_DEBUG(SYS_ERROR_INFO, "Driver not opened");
    }
    else
    {
        /* Disable the SOF */
        PLIB_USB_SOFDisable(DRV_USBFS_PERIPHERAL_ID);
        PLIB_USB_InterruptDisable(DRV_USBFS_PERIPHERAL_ID, USB_INT_SOF);
        returnValue = true;
    }

    return returnValue;

}/* end of _DRV_USBFS_MAKE_NAME(HOST_Suspend)() */

// *****************************************************************************
/* Function:
    void _DRV_USBFS_MAKE_NAME(Close)()

  Summary:
    static impementation of _DRV_USBFS_MAKE_NAME(Close) client interface function.

  Description:
    This is the static impementation of _DRV_USBFS_MAKE_NAME(Close) client interface
    function.

  Remarks:
    See drv_usb.h for usage information.
*/

void _DRV_USBFS_MAKE_NAME(Close)()
{
    /* Start of local variable */
    DRV_USBFS_OBJ * pUSBDrvObj = (DRV_USBFS_OBJ *)&(gDrvUSBGroup.gDrvUSBObj);
    /* End of local variable */

    /* Reset the relevant parameters */
    if(pUSBDrvObj->isOpened)
    {
        pUSBDrvObj->isOpened = false;
        pUSBDrvObj->pEventCallBack = NULL;
    }
    else
    {
        SYS_DEBUG(SYS_ERROR_INFO, "Driver not opened");
    }
    
    return;
    
}/* end of _DRV_USBFS_MAKE_NAME(Close)() */

// *****************************************************************************
/* Function:
    void _DRV_USBFS_MAKE_NAME(Tasks_ISR)()

  Summary:
    static impementation of _DRV_USBFS_MAKE_NAME(Tasks_ISR) system interface function.

  Description:
    This is the static impementation of _DRV_USBFS_MAKE_NAME(Tasks_ISR) system interface
    function.

  Remarks:
    See drv_usb.h for usage information.
*/

void _DRV_USBFS_MAKE_NAME(Tasks_ISR)()
{
    /* Start of local variable */
    DRV_USBFS_OBJ * pUSBDriver = &(gDrvUSBGroup.gDrvUSBObj);
    /* End of local variable */

    /* We are entering an interrupt context */
    pUSBDriver->inInterruptContext = true;

	switch(pUSBDriver->operationMode)
    {
        case DRV_USBFS_OPMODE_DEVICE:
            
            /* Driver is running in Device Mode */
            _DRV_USBFS_DEVICE_TASKS_ISR(pUSBDriver);
            break;
        
        case DRV_USBFS_OPMODE_HOST:

            /* Driver is running in Host Mode */
            _DRV_USBFS_HOST_TASKS_ISR(pUSBDriver);
            break;

        case DRV_USBFS_OPMODE_OTG:
            /* OTG mode is not supported yet */
            break;

        default:
            SYS_DEBUG_MESSAGE(SYS_ERROR_INFO, "What mode are you trying?");
            break;
    }
  
    /* Clear the interrupt */
    _DRV_USBFS_InterruptSourceClear(DRV_USBFS_INTERRUPT_SOURCE);
    pUSBDriver->inInterruptContext = false;
    
}/* end of _DRV_USBFS_MAKE_NAME(Tasks_ISR)()*/

// *****************************************************************************
/* Function:
    void _DRV_USBFS_MAKE_NAME(ClientEventCallBackSet)
    (
        uintptr_t    hReferenceData,
        DRV_USBFS_EVENT_CALLBACK eventCallBack
    )

  Summary:
    static impementation of _DRV_USBFS_MAKE_NAME(ClientEventCallBackSet) client interface
    function.

  Description:
    This is the static impementation of _DRV_USBFS_MAKE_NAME(ClientEventCallBackSet) client
    interface function.

  Remarks:
    See drv_usb.h for usage information.
*/

void _DRV_USBFS_MAKE_NAME(ClientEventCallBackSet)
(
    uintptr_t    hReferenceData,
    DRV_USB_EVENT_CALLBACK eventCallBack 
)
{
    /* Start of local variables */
    DRV_USBFS_OBJ * pUSBDrvObj = (DRV_USBFS_OBJ *)&(gDrvUSBGroup.gDrvUSBObj);
    /* End of local variables */
    
    /* Check if the handle is valid or opened */
    if(!(pUSBDrvObj->isOpened))
    {
        SYS_DEBUG(SYS_ERROR_INFO, "Driver not opened");
    }
    else
    {
        /* Assign event call back and reference data */
        pUSBDrvObj->hClientArg = hReferenceData;
        pUSBDrvObj->pEventCallBack = eventCallBack;

        /* If the driver is operating in device mode, this is the time
         * we enable the USB interrupt */

        if(pUSBDrvObj->operationMode == USB_OPMODE_DEVICE)
        {
            /* Enable the session valid interrupt */
            PLIB_USB_OTG_InterruptEnable(DRV_USBFS_PERIPHERAL_ID, USB_OTG_INT_SESSION_VALID);
            
            /* Enable the interrupt */
            _DRV_USBFS_InterruptSourceEnable(DRV_USBFS_INTERRUPT_SOURCE);

        }
    }
   
    return;
    
} /* end of _DRV_USBFS_MAKE_NAME(ClientEventCallBackSet)() */

// *****************************************************************************
/* Function:
    void _DRV_USBFS_MAKE_NAME(Tasks)()

  Summary:
    Maintains the driver's state machine when the driver is configured for 
    polled mode.

  Description:
    Maintains the driver's state machine when the driver is configured for 
    polled mode. This function should be called from the system tasks routine.

  Remarks:
    Refer to drv_usb.h for usage information.
*/

void _DRV_USBFS_MAKE_NAME(Tasks)()
{
    /* This driver does not have any non interrupt tasks. When the driver
     * is configured for polled mode operation, the _DRV_USBFS_Tasks_ISR function
     * will map to DRV_USBFS_Tasks_ISR function. In interrupt mode, this function
     * will be mapped to nothing and hence this function will not have any
     * effect. */

    _DRV_USBFS_Tasks_ISR();
}

void _DRV_USBFS_MAKE_NAME(Tasks_ISR_USBDMA)()
{
    /* This function is implemented to only maintain compatibility with the
     * PIC32MZ High Speed USB Driver. This function does not do anything on the
     * PIC32MX USB driver and is not required to be called in a PIC32MX USB
     * applicaiton */
}

#endif
