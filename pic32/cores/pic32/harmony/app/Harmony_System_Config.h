/*******************************************************************************
  MPLAB Harmony System Configuration Header

  File Name:
    system_config.h

  Summary:
    Build-time configuration header for the system defined by this MPLAB Harmony
    project.

  Description:
    An MPLAB Project may have multiple configurations.  This file defines the
    build-time options for a single configuration.

  Remarks:
    This configuration header must not define any prototypes or data
    definitions (or include any files that do).  It only provides macro
    definitions for build-time configuration options that are not instantiated
    until used by another MPLAB Harmony module or application.
    
    Created with MPLAB Harmony Version 1.06
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2015 released Microchip Technology Inc.  All rights reserved.

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
// DOM-IGNORE-END

#ifndef _HARMONY_SYSTEM_CONFIG_H
#define _HARMONY_SYSTEM_CONFIG_H

/* This is a temporary workaround for an issue with the peripheral library "Exists"
   functions that causes superfluous warnings.  It "nulls" out the definition of
   The PLIB function attribute that causes the warning.  Once that issue has been
   resolved, this definition should be removed. */
#define _PLIB_UNSUPPORTED


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
/*  This section Includes other configuration headers necessary to completely
    define this configuration.
*/

// *****************************************************************************
// *****************************************************************************
// Section: System Service Configuration
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Common System Service Configuration Options
*/
#define SYS_VERSION_STR           "1.06"
#define SYS_VERSION               10600

// *****************************************************************************
 
/*** Interrupt System Service Configuration ***/
#define SYS_INT                     true


/*** USB Driver Configuration ***/

/* MZ processors need the high speed driver */
#if defined(__PIC32MZ)
	#define USB_DRV_HS 1
#else
	#define USB_DRV_FS 1
#endif

#if defined(USB_DRV_HS)

	/* Enables Device Support */
	#define DRV_USBHS_DEVICE_SUPPORT	true

	/* Disable Device Support */
	#define DRV_USBHS_HOST_SUPPORT		false

	#define DRV_USBHS_PERIPHERAL_ID		0
	#define DRV_USBHS_INTERRUPT_SOURCE	INT_SOURCE_USB_1
	#define DRV_USBHS_INDEX				0

	/* Interrupt mode enabled */
	#define DRV_USBHS_INTERRUPT_MODE	true

	/* Number of Endpoints used */
	#define DRV_USBHS_ENDPOINTS_NUMBER	9

	#define APP_MAKE_BUFFER_DMA_READY	__attribute__((coherent)) __attribute__((aligned(4)))

	/* Maximum USB driver instances */
	#define DRV_USBHS_INSTANCES_NUMBER	1

#else 

	/* Enables Device Support */
	#define DRV_USBFS_DEVICE_SUPPORT	true

	/* Disable Device Support */
	#define DRV_USBFS_HOST_SUPPORT		false

	#define DRV_USBFS_PERIPHERAL_ID		USB_ID_1
	#define DRV_USBFS_INTERRUPT_SOURCE	INT_SOURCE_USB_1
	#define DRV_USBFS_INDEX				0

	/* Interrupt mode enabled */
	#define DRV_USBFS_INTERRUPT_MODE	true

	/* Number of Endpoints used */
	#define DRV_USBFS_ENDPOINTS_NUMBER	9

	#define APP_MAKE_BUFFER_DMA_READY

	/* Maximum USB driver instances */
	#define DRV_USBFS_INSTANCES_NUMBER	1

#endif


/*** USB Device Stack Configuration ***/


/* The USB Device Layer will not initialize the USB Driver */
#define USB_DEVICE_DRIVER_INITIALIZE_EXPLICIT


/* EP0 size in bytes */
#define USB_DEVICE_EP0_BUFFER_SIZE      64

/* Enable SOF Events */ 
#define USB_DEVICE_SOF_EVENT_ENABLE     

/* Enable Advanced String Descriptor table. This feature lets the user specify 
   String Index along with the String descriptor Structure  */
#define USB_DEVICE_STRING_DESCRIPTOR_TABLE_ADVANCED_ENABLE

/* Maximum instances of CDC function driver */
#define USB_DEVICE_CDC_INSTANCES_NUMBER     2

/* CDC Transfer Queue Size for both read and
   write. Applicable to all instances of the
   function driver */
#define USB_DEVICE_CDC_QUEUE_DEPTH_COMBINED 10

/* Maximum instances of HID function driver */
#define USB_DEVICE_HID_INSTANCES_NUMBER     1

/* HID Transfer Queue Size for both read and
   write. Applicable to all instances of the
   function driver */
#define USB_DEVICE_HID_QUEUE_DEPTH_COMBINED 2

/* Maximum device layer instances */
#define USB_DEVICE_INSTANCES_NUMBER     1

// Number of milliseconds we will wait before giving up while trying to 
// send data up to the PC.
#define     USB_CDC_INACTIVE_TIMEOUT_MS     50

#endif // _HARMONY_SYSTEM_CONFIG_H
/*******************************************************************************
 End of File
*/

