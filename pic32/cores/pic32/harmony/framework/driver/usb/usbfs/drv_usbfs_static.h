/*******************************************************************************
  USB Device Driver Static Interface

  Company:
    Microchip Technology Inc.

  File Name:
    drv_usbfs_static.h

  Summary:
    USB Device Driver Interface File

  Description:
    The USB device driver provides a simple interface to manage the "USB"
    peripheral.  This file defines the interface definitions for the static
    single client version of the driver. Static interfaces incorporate the 
    the instance index within the name of the routines thus eliminating the
    need for an object ID or an object handle.  
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2012 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
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

#ifndef _DRV_USBFS_STATIC_H
#define _DRV_USBFS_STATIC_H

// *****************************************************************************
// *****************************************************************************
// Section: Interface Headers for Instance 0 for the static single open driver
// *****************************************************************************
// *****************************************************************************

void DRV_USBFS0_Tasks(void);
void DRV_USBFS0_Tasks_ISR     (void);
void DRV_USBFS0_Tasks_ISR_USBDMA (void);
void DRV_USBFS0_Deinitialize  (void);
SYS_MODULE_OBJ DRV_USBFS0_Initialize    (const SYS_MODULE_INIT * const init);

void DRV_USBFS0_Close                     (void);
void DRV_USBFS0_DEVICE_Attach             (void);
void DRV_USBFS0_DEVICE_Detach             (void);
bool DRV_USBFS0_DEVICE_EndpointIsStalled  (USB_ENDPOINT endpoint);
bool DRV_USBFS0_DEVICE_EndpointIsEnabled  (USB_ENDPOINT endpoint);
void DRV_USBFS0_ClientEventCallBackSet    (uintptr_t hReferenceData, DRV_USB_EVENT_CALLBACK eventCallBack); 
void DRV_USBFS0_DEVICE_AddressSet         (uint8_t address);

USB_ERROR DRV_USBFS0_DEVICE_EndpointStall     (USB_ENDPOINT endpoint);
USB_ERROR DRV_USBFS0_DEVICE_EndpointStallClear(USB_ENDPOINT endpoint);
USB_ERROR DRV_USBFS0_DEVICE_IRPCancelAll      (USB_ENDPOINT endpoint);
USB_ERROR DRV_USBFS0_DEVICE_EndpointDisable   (USB_ENDPOINT endpoint);
USB_ERROR DRV_USBFS0_DEVICE_IRPSubmit         (USB_ENDPOINT endpointAndDirection, USB_DEVICE_IRP * inputIRP);
USB_ERROR DRV_USBFS0_DEVICE_EndpointEnable    (USB_ENDPOINT endpoint,  USB_TRANSFER_TYPE transferType, uint16_t endpointSize);
USB_ERROR DRV_USBFS0_DEVICE_EndpoinDisable    (USB_ENDPOINT endpoint);

USB_SPEED   DRV_USBFS0_DEVICE_CurrentSpeedGet(void);
SYS_STATUS  DRV_USBFS0_Status(void);
DRV_HANDLE  DRV_USBFS0_Open( const DRV_IO_INTENT intent );

char* DRV_USBFS0_VersionStrGet( void );
unsigned int DRV_USBFS0_VersionGet( void );


bool DRV_USBFS0_HOST_Suspend(void);
bool DRV_USBFS0_HOST_Resume(void);
uint16_t DRV_USBFS0_DEVICE_SOFNumberGet(void);

void DRV_USBFS0_DEVICE_RemoteWakeupStart(void);
void DRV_USBFS0_DEVICE_RemoteWakeupStop(void);

#define DRV_USBFS0_DEVICE_EndpointDisableAll(x)  DRV_USBFS0_DEVICE_EndpointDisable(x, _DRV_USBFS_DEVICE_ENDPOINT_ALL)
#endif

