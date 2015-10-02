/*******************************************************************************
  System Initialization File

  File Name:
    system_init.c

  Summary:
    This file contains source code necessary to initialize the system.

  Description:
    This file contains source code necessary to initialize the system.  It
    implements the "SYS_Initialize" function, defines the configuration bits, 
    and allocates any necessary global system resources, such as the 
    HarmonySysObj structure that contains the object handles to all the MPLAB Harmony 
    module objects in the system.
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


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include <xc.h>
#include <sys/attribs.h>
#include "Harmony_Private.h"
#include "Harmony_Sys.h"

#if defined (_USB)

// *****************************************************************************
// *****************************************************************************
// Section: Library/Stack Initialization Data
// *****************************************************************************
// *****************************************************************************
//<editor-fold defaultstate="collapsed" desc="USB Stack Initialization Data">



/****************************************************
 * Class specific descriptor - HID Report descriptor
 ****************************************************/
const uint8_t _hidReportDescriptor[] = {

    //	Mouse
    0x05, 0x01, // USAGE_PAGE (Generic Desktop)	// 54
    0x09, 0x02, // USAGE (Mouse)
    0xa1, 0x01, // COLLECTION (Application)
    0x09, 0x01, //   USAGE (Pointer)
    0xa1, 0x00, //   COLLECTION (Physical)
    0x85, 0x01, //     REPORT_ID (1)
    0x05, 0x09, //     USAGE_PAGE (Button)
    0x19, 0x01, //     USAGE_MINIMUM (Button 1)
    0x29, 0x03, //     USAGE_MAXIMUM (Button 3)
    0x15, 0x00, //     LOGICAL_MINIMUM (0)
    0x25, 0x01, //     LOGICAL_MAXIMUM (1)
    0x95, 0x03, //     REPORT_COUNT (3)
    0x75, 0x01, //     REPORT_SIZE (1)
    0x81, 0x02, //     INPUT (Data,Var,Abs)
    0x95, 0x01, //     REPORT_COUNT (1)
    0x75, 0x05, //     REPORT_SIZE (5)
    0x81, 0x03, //     INPUT (Cnst,Var,Abs)
    0x05, 0x01, //     USAGE_PAGE (Generic Desktop)
    0x09, 0x30, //     USAGE (X)
    0x09, 0x31, //     USAGE (Y)
    0x09, 0x38, //     USAGE (Wheel)
    0x15, 0x81, //     LOGICAL_MINIMUM (-127)
    0x25, 0x7f, //     LOGICAL_MAXIMUM (127)
    0x75, 0x08, //     REPORT_SIZE (8)
    0x95, 0x03, //     REPORT_COUNT (3)
    0x81, 0x06, //     INPUT (Data,Var,Rel)
    0xc0, //   END_COLLECTION
    0xc0, // END_COLLECTION

    //	Keyboard
    0x05, 0x01, // USAGE_PAGE (Generic Desktop)	// 47
    0x09, 0x06, // USAGE (Keyboard)
    0xa1, 0x01, // COLLECTION (Application)
    0x85, 0x02, //   REPORT_ID (2)
    0x05, 0x07, //   USAGE_PAGE (Keyboard)

    0x19, 0xe0, //   USAGE_MINIMUM (Keyboard LeftControl)
    0x29, 0xe7, //   USAGE_MAXIMUM (Keyboard Right GUI)
    0x15, 0x00, //   LOGICAL_MINIMUM (0)
    0x25, 0x01, //   LOGICAL_MAXIMUM (1)
    0x75, 0x01, //   REPORT_SIZE (1)

    0x95, 0x08, //   REPORT_COUNT (8)
    0x81, 0x02, //   INPUT (Data,Var,Abs)
    0x95, 0x01, //   REPORT_COUNT (1)
    0x75, 0x08, //   REPORT_SIZE (8)
    0x81, 0x03, //   INPUT (Cnst,Var,Abs)

    0x95, 0x06, //   REPORT_COUNT (6)
    0x75, 0x08, //   REPORT_SIZE (8)
    0x15, 0x00, //   LOGICAL_MINIMUM (0)
    0x25, 0x65, //   LOGICAL_MAXIMUM (101)
    0x05, 0x07, //   USAGE_PAGE (Keyboard)

    0x19, 0x00, //   USAGE_MINIMUM (Reserved (no event indicated))
    0x29, 0x65, //   USAGE_MAXIMUM (Keyboard Application)
    0x81, 0x00, //   INPUT (Data,Ary,Abs)
    0xc0, // END_COLLECTION
};

/**************************************************
 * USB Device Function Driver Init Data
 **************************************************/
const USB_DEVICE_CDC_INIT cdcInit0 ={
    .queueSizeRead = 2,
    .queueSizeWrite = 2,
    .queueSizeSerialStateNotification = 1
};
const USB_DEVICE_CDC_INIT cdcInit1 ={
    .queueSizeRead = 2,
    .queueSizeWrite = 2,
    .queueSizeSerialStateNotification = 1
};
const USB_DEVICE_HID_INIT hidInit0 ={
    .hidReportDescriptorSize = sizeof (_hidReportDescriptor),
    .hidReportDescriptor = &_hidReportDescriptor,
    .queueSizeReportReceive = 1,
    .queueSizeReportSend = 1
};
/**************************************************
 * USB Device Layer Function Driver Registration 
 * Table
 **************************************************/
const USB_DEVICE_FUNCTION_REGISTRATION_TABLE funcRegistrationTable[3] ={
    /* Function 1 */
    {
        .configurationValue = 1, /* Configuration value */
        .interfaceNumber = 0, /* First interfaceNumber of this function */
        .speed = USB_SPEED_FULL, /* Function Speed */
        .numberOfInterfaces = 2, /* Number of interfaces */
        .funcDriverIndex = 0, /* Index of CDC Function Driver */
        .driver = (void*) USB_DEVICE_CDC_FUNCTION_DRIVER, /* USB CDC function data exposed to device layer */
        .funcDriverInit = (void*) &cdcInit0 /* Function driver init data */
    },
    /* Function 2 */
    {
        .configurationValue = 1, /* Configuration value */
        .interfaceNumber = 2, /* First interfaceNumber of this function */
        .speed = USB_SPEED_FULL, /* Function Speed */
        .numberOfInterfaces = 2, /* Number of interfaces */
        .funcDriverIndex = 1, /* Index of CDC Function Driver */
        .driver = (void*) USB_DEVICE_CDC_FUNCTION_DRIVER, /* USB CDC function data exposed to device layer */
        .funcDriverInit = (void*) &cdcInit1 /* Function driver init data */
    },
    /* Function 3 */
    {
        .configurationValue = 1, /* Configuration value */
        .interfaceNumber = 4, /* First interfaceNumber of this function */
        .speed = USB_SPEED_FULL, /* Function Speed */
        .numberOfInterfaces = 1, /* Number of interfaces */
        .funcDriverIndex = 0, /* Index of HID Function Driver */
        .driver = (void*) USB_DEVICE_HID_FUNCTION_DRIVER, /* USB HID function data exposed to device layer */
        .funcDriverInit = (void*) &hidInit0, /* Function driver init data */
    },
};

/*******************************************
 * USB Device Layer Descriptors
 *******************************************/
/*******************************************
 *  USB Device Descriptor 
 *******************************************/
const USB_DEVICE_DESCRIPTOR deviceDescriptor ={
    0x12, // Size of this descriptor in bytes
    USB_DESCRIPTOR_DEVICE, // DEVICE descriptor type
    0x0200, // USB Spec Release Number in BCD format
    0xEF, // Class Code
    0x02, // Subclass code
    0x01, // Protocol code
    USB_DEVICE_EP0_BUFFER_SIZE, // Max packet size for EP0, see system_config.h
    0x04D8, // Vendor ID
    0x0208, // Product ID
    0x0100, // Device release number in BCD format
    0x01, // Manufacturer string index
    0x02, // Product string index
    0x00, // Device serial number string index
    0x01 // Number of possible configurations
};


/*******************************************
 *  USB Full Speed Configuration Descriptor
 *******************************************/
const uint8_t fullSpeedConfigurationDescriptor[] ={
    /* Configuration Descriptor */

    0x09, // Size of this descriptor in bytes
    USB_DESCRIPTOR_CONFIGURATION, // Descriptor Type
    173, 0, //(173 Bytes)Size of the Config descriptor.e
    5, // Number of interfaces in this cfg
    0x01, // Index value of this configuration
    0x00, // Configuration string index
    USB_ATTRIBUTE_DEFAULT | USB_ATTRIBUTE_SELF_POWERED, // Attributes
    50, // Max power consumption (2X mA)
    /* Descriptor for Function 1 - CDC     */
    /* Interface Association Descriptor: CDC Function 1*/
    0x08, // Size of this descriptor in bytes
    0x0B, // Interface association descriptor type
    0, // The first associated interface
    0x02, // Number of contiguous associated interface
    0x02, // bInterfaceClass of the first interface
    0x02, // bInterfaceSubclass of the first interface
    0x01, // bInterfaceProtocol of the first interface
    0x00, // Interface string index

    /* Interface Descriptor */

    0x09, // Size of this descriptor in bytes
    USB_DESCRIPTOR_INTERFACE, // Descriptor Type
    0, // Interface Number
    0x00, // Alternate Setting Number
    0x01, // Number of endpoints in this interface
    USB_CDC_COMMUNICATIONS_INTERFACE_CLASS_CODE, // Class code
    USB_CDC_SUBCLASS_ABSTRACT_CONTROL_MODEL, // Subclass code
    USB_CDC_PROTOCOL_AT_V250, // Protocol code
    0x00, // Interface string index

    /* CDC Class-Specific Descriptors */

    sizeof (USB_CDC_HEADER_FUNCTIONAL_DESCRIPTOR), // Size of the descriptor
    USB_CDC_DESC_CS_INTERFACE, // CS_INTERFACE
    USB_CDC_FUNCTIONAL_HEADER, // Type of functional descriptor
    0x20, 0x01, // CDC spec version

    sizeof (USB_CDC_ACM_FUNCTIONAL_DESCRIPTOR), // Size of the descriptor
    USB_CDC_DESC_CS_INTERFACE, // CS_INTERFACE
    USB_CDC_FUNCTIONAL_ABSTRACT_CONTROL_MANAGEMENT, // Type of functional descriptor
    USB_CDC_ACM_SUPPORT_LINE_CODING_LINE_STATE_AND_NOTIFICATION, // bmCapabilities of ACM

    sizeof (USB_CDC_UNION_FUNCTIONAL_DESCRIPTOR_HEADER) + 1, // Size of the descriptor
    USB_CDC_DESC_CS_INTERFACE, // CS_INTERFACE
    USB_CDC_FUNCTIONAL_UNION, // Type of functional descriptor
    0, // com interface number
    1,

    sizeof (USB_CDC_CALL_MANAGEMENT_DESCRIPTOR), // Size of the descriptor
    USB_CDC_DESC_CS_INTERFACE, // CS_INTERFACE
    USB_CDC_FUNCTIONAL_CALL_MANAGEMENT, // Type of functional descriptor
    0x00, // bmCapabilities of CallManagement
    1, // Data interface number

    /* Interrupt Endpoint (IN)Descriptor */

    0x07, // Size of this descriptor
    USB_DESCRIPTOR_ENDPOINT, // Endpoint Descriptor
    1 | USB_EP_DIRECTION_IN, // EndpointAddress ( EP1 IN INTERRUPT)
    USB_TRANSFER_TYPE_INTERRUPT, // Attributes type of EP (INTERRUPT)
    0x10, 0x00, // Max packet size of this EP
    0x02, // Interval (in ms)

    /* Interface Descriptor */

    0x09, // Size of this descriptor in bytes
    USB_DESCRIPTOR_INTERFACE, // INTERFACE descriptor type
    1, // Interface Number
    0x00, // Alternate Setting Number
    0x02, // Number of endpoints in this interface
    USB_CDC_DATA_INTERFACE_CLASS_CODE, // Class code
    0x00, // Subclass code
    USB_CDC_PROTOCOL_NO_CLASS_SPECIFIC, // Protocol code
    0x00, // Interface string index

    /* Bulk Endpoint (OUT)Descriptor */

    0x07, // Size of this descriptor
    USB_DESCRIPTOR_ENDPOINT, // Endpoint Descriptor
    2 | USB_EP_DIRECTION_OUT, // EndpointAddress ( EP2 OUT)
    USB_TRANSFER_TYPE_BULK, // Attributes type of EP (BULK)
    0x40, 0x00, // Max packet size of this EP
    0x00, // Interval (in ms)

    /* Bulk Endpoint (IN)Descriptor */

    0x07, // Size of this descriptor
    USB_DESCRIPTOR_ENDPOINT, // Endpoint Descriptor
    2 | USB_EP_DIRECTION_IN, // EndpointAddress ( EP2 IN )
    0x02, // Attributes type of EP (BULK)
    0x40, 0x00, // Max packet size of this EP
    0x00, // Interval (in ms)

    /* Descriptor for Function 2 - CDC     */
    /* Interface Association Descriptor: CDC Function 2*/
    0x08, // Size of this descriptor in bytes
    0x0B, // Interface association descriptor type
    2, // The first associated interface
    0x02, // Number of contiguous associated interface
    0x02, // bInterfaceClass of the first interface
    0x02, // bInterfaceSubclass of the first interface
    0x01, // bInterfaceProtocol of the first interface
    0x00, // Interface string index

    /* Interface Descriptor */

    0x09, // Size of this descriptor in bytes
    USB_DESCRIPTOR_INTERFACE, // Descriptor Type
    2, // Interface Number
    0x00, // Alternate Setting Number
    0x01, // Number of endpoints in this interface
    USB_CDC_COMMUNICATIONS_INTERFACE_CLASS_CODE, // Class code
    USB_CDC_SUBCLASS_ABSTRACT_CONTROL_MODEL, // Subclass code
    USB_CDC_PROTOCOL_AT_V250, // Protocol code
    0x00, // Interface string index

    /* CDC Class-Specific Descriptors */

    sizeof (USB_CDC_HEADER_FUNCTIONAL_DESCRIPTOR), // Size of the descriptor
    USB_CDC_DESC_CS_INTERFACE, // CS_INTERFACE
    USB_CDC_FUNCTIONAL_HEADER, // Type of functional descriptor
    0x20, 0x01, // CDC spec version

    sizeof (USB_CDC_ACM_FUNCTIONAL_DESCRIPTOR), // Size of the descriptor
    USB_CDC_DESC_CS_INTERFACE, // CS_INTERFACE
    USB_CDC_FUNCTIONAL_ABSTRACT_CONTROL_MANAGEMENT, // Type of functional descriptor
    USB_CDC_ACM_SUPPORT_LINE_CODING_LINE_STATE_AND_NOTIFICATION, // bmCapabilities of ACM

    sizeof (USB_CDC_UNION_FUNCTIONAL_DESCRIPTOR_HEADER) + 1, // Size of the descriptor
    USB_CDC_DESC_CS_INTERFACE, // CS_INTERFACE
    USB_CDC_FUNCTIONAL_UNION, // Type of functional descriptor
    2, // com interface number
    3,

    sizeof (USB_CDC_CALL_MANAGEMENT_DESCRIPTOR), // Size of the descriptor
    USB_CDC_DESC_CS_INTERFACE, // CS_INTERFACE
    USB_CDC_FUNCTIONAL_CALL_MANAGEMENT, // Type of functional descriptor
    0x00, // bmCapabilities of CallManagement
    3, // Data interface number

    /* Interrupt Endpoint (IN)Descriptor */

    0x07, // Size of this descriptor
    USB_DESCRIPTOR_ENDPOINT, // Endpoint Descriptor
    3 | USB_EP_DIRECTION_IN, // EndpointAddress ( EP3 IN INTERRUPT)
    USB_TRANSFER_TYPE_INTERRUPT, // Attributes type of EP (INTERRUPT)
    0x10, 0x00, // Max packet size of this EP
    0x02, // Interval (in ms)

    /* Interface Descriptor */

    0x09, // Size of this descriptor in bytes
    USB_DESCRIPTOR_INTERFACE, // INTERFACE descriptor type
    3, // Interface Number
    0x00, // Alternate Setting Number
    0x02, // Number of endpoints in this interface
    USB_CDC_DATA_INTERFACE_CLASS_CODE, // Class code
    0x00, // Subclass code
    USB_CDC_PROTOCOL_NO_CLASS_SPECIFIC, // Protocol code
    0x00, // Interface string index

    /* Bulk Endpoint (OUT)Descriptor */

    0x07, // Size of this descriptor
    USB_DESCRIPTOR_ENDPOINT, // Endpoint Descriptor
    4 | USB_EP_DIRECTION_OUT, // EndpointAddress ( EP4 OUT)
    USB_TRANSFER_TYPE_BULK, // Attributes type of EP (BULK)
    0x40, 0x00, // Max packet size of this EP
    0x00, // Interval (in ms)

    /* Bulk Endpoint (IN)Descriptor */

    0x07, // Size of this descriptor
    USB_DESCRIPTOR_ENDPOINT, // Endpoint Descriptor
    4 | USB_EP_DIRECTION_IN, // EndpointAddress ( EP4 IN )
    0x02, // Attributes type of EP (BULK)
    0x40, 0x00, // Max packet size of this EP
    0x00, // Interval (in ms)


    /* Interface Descriptor */

    0x09, // Size of this descriptor in bytes
    USB_DESCRIPTOR_INTERFACE, // INTERFACE descriptor type
    4, // Interface Number
    0, // Alternate Setting Number
    2, // Number of endpoints in this interface
    USB_HID_CLASS_CODE, // Class code
    USB_HID_SUBCLASS_CODE_NO_SUBCLASS, // Subclass code
    USB_HID_PROTOCOL_CODE_NONE, // No Protocol
    0, // Interface string index

    /* HID Class-Specific Descriptor */

    0x09, // Size of this descriptor in bytes
    USB_HID_DESCRIPTOR_TYPES_HID, // HID descriptor type
    0x11, 0x01, // HID Spec Release Number in BCD format (1.11)
    0x00, // Country Code (0x00 for Not supported)
    1, // Number of class descriptors, see usbcfg.h
    USB_HID_DESCRIPTOR_TYPES_REPORT, // Report descriptor type
    USB_DEVICE_16bitTo8bitArrange(sizeof (_hidReportDescriptor)), // Size of the report descriptor

    /* Endpoint Descriptor */

    0x07, // Size of this descriptor in bytes
    USB_DESCRIPTOR_ENDPOINT, // Endpoint Descriptor
    5 | USB_EP_DIRECTION_IN, // EndpointAddress
    USB_TRANSFER_TYPE_INTERRUPT, // Attributes
    0x40, 0x00, // Size
    0x01, // Interval

    /* Endpoint Descriptor */

    0x07, // Size of this descriptor in bytes
    USB_DESCRIPTOR_ENDPOINT, // Endpoint Descriptor
    5 | USB_EP_DIRECTION_OUT, // EndpointAddress
    USB_TRANSFER_TYPE_INTERRUPT, // Attributes
    0x40, 0x00, // size
    0x01, // Interval




};

/*******************************************
 * Array of Full speed config descriptors
 *******************************************/
USB_DEVICE_CONFIGURATION_DESCRIPTORS_TABLE fullSpeedConfigDescSet[1] ={
    fullSpeedConfigurationDescriptor
};


/**************************************
 *  String descriptors.
 *************************************/

/*******************************************
 *  Language code string descriptor
 *******************************************/
const struct __attribute__((packed))
{
    uint8_t stringIndex; //Index of the string descriptor
    uint16_t languageID; // Language ID of this string.
    uint8_t bLength; // Size of this descriptor in bytes
    uint8_t bDscType; // STRING descriptor type 
    uint16_t string[1]; // String
}

sd000 ={
    0, // Index of this string is 0
    0, // This field is always blank for String Index 0
    sizeof (sd000) - sizeof (sd000.stringIndex) - sizeof (sd000.languageID),
    USB_DESCRIPTOR_STRING,
    {
        0x0409} // Language ID
};

/*******************************************
 *  Manufacturer string descriptor
 *******************************************/
const struct __attribute__((packed))
{
    uint8_t stringIndex; //Index of the string descriptor
    uint16_t languageID; // Language ID of this string.
    uint8_t bLength; // Size of this descriptor in bytes
    uint8_t bDscType; // STRING descriptor type
    uint16_t string[7]; // String
}

sd001 ={
    1, // Index of this string descriptor is 1. 
    0x0409, // Language ID of this string descriptor is 0x0409 (English)
    sizeof (sd001) - sizeof (sd001.stringIndex) - sizeof (sd001.languageID),
    USB_DESCRIPTOR_STRING,
    {
        'c', 'h', 'i', 'p', 'K', 'I', 'T'}
};

/*******************************************
 *  Product string descriptor
 *******************************************/
const struct __attribute__((packed))
{
    uint8_t stringIndex; //Index of the string descriptor
    uint16_t languageID; // Language ID of this string.
    uint8_t bLength; // Size of this descriptor in bytes
    uint8_t bDscType; // STRING descriptor type 
    uint16_t string[23]; // String
}

sd002 ={
    2, // Index of this string descriptor is 2. 
    0x0409, // Language ID of this string descriptor is 0x0409 (English)
    sizeof (sd002) - sizeof (sd002.stringIndex) - sizeof (sd002.languageID),
    USB_DESCRIPTOR_STRING,
    {
        'M', 'P', 'I', 'D', 'E', ' ', 'C', 'o', 'm', 'p', 'a', 't', 'i', 'b', 'l', 'e', ' ', 'D', 'e', 'v', 'i', 'c', 'e'}
};

/***************************************
 * Array of string descriptors
 ***************************************/
USB_DEVICE_STRING_DESCRIPTORS_TABLE stringDescriptors[3] ={
    (const uint8_t * const) &sd000,
    (const uint8_t * const) &sd001,
    (const uint8_t * const) &sd002
};


/*******************************************
 * USB Device Layer Master Descriptor Table 
 *******************************************/
const USB_DEVICE_MASTER_DESCRIPTOR usbMasterDescriptor ={
    &deviceDescriptor, /* Full speed descriptor */
    1, /* Total number of full speed configurations available */
    fullSpeedConfigDescSet, /* Pointer to array of full speed configurations descriptors*/
    NULL,
    0,
    NULL,
    3, // Total number of string descriptors available.
    stringDescriptors, // Pointer to array of string descriptors.
    NULL,
    NULL
};


/****************************************************
 * USB Device Layer Initialization Data
 ****************************************************/
const USB_DEVICE_INIT usbDevInitData ={
    /* System module initialization */
    .moduleInit =
    {SYS_MODULE_POWER_RUN_FULL},

    /* Number of function drivers registered to this instance of the
       USB device layer */
    .registeredFuncCount = 3,

    /* Function driver table registered to this instance of the USB device layer*/
    .registeredFunctions = (USB_DEVICE_FUNCTION_REGISTRATION_TABLE*) funcRegistrationTable,

    /* Pointer to USB Descriptor structure */
    .usbMasterDescriptor = (USB_DEVICE_MASTER_DESCRIPTOR*) & usbMasterDescriptor,

    /* USB Device Speed */
    .deviceSpeed = USB_SPEED_FULL,

    /* Index of the USB Driver to be used by this Device Layer Instance */
    .driverIndex = DRV_USBFS_INDEX_0,

    /* Pointer to the USB Driver Functions. */
    .usbDriverInterface = DRV_USBFS_DEVICE_INTERFACE,

};

// </editor-fold>

// *****************************************************************************
// *****************************************************************************
// Section: Driver Initialization Data
// *****************************************************************************
// *****************************************************************************

//<editor-fold defaultstate="collapsed" desc="DRV_USB Initialization Data">

/******************************************************
 * USB Driver Initialization
 ******************************************************/
/****************************************************
 * Endpoint Table needed by the Device Layer.
 ****************************************************/
uint8_t __attribute__((aligned(512))) endPointTable[DRV_USBFS_ENDPOINTS_NUMBER * 32];
const DRV_USBFS_INIT drvUSBInit ={
    /* Assign the endpoint table */
    .endpointTable = endPointTable,

    /* Interrupt Source for USB module */
    .interruptSource = INT_SOURCE_USB_1,

    /* System module initialization */
    .moduleInit =
    {SYS_MODULE_POWER_RUN_FULL},

    .operationMode = DRV_USBFS_OPMODE_DEVICE,

    .operationSpeed = USB_SPEED_FULL,

    /* Stop in idle */
    .stopInIdle = false,

    /* Suspend in sleep */
    .suspendInSleep = false,

    /* Identifies peripheral (PLIB-level) ID */
    .usbID = USB_ID_1
};

// </editor-fold>

#endif

// *****************************************************************************
// *****************************************************************************
// Section: System Data
// *****************************************************************************
// *****************************************************************************

/* Structure to hold the object handles for the modules in the system. */
HARMONY_SYSTEM_OBJECTS HarmonySysObj;


// *****************************************************************************
// *****************************************************************************
// Section: Module Initialization Data
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Device Control System Service Initialization Data
  
  <editor-fold defaultstate="collapsed" 
  desc="Device Control System Service Initialization Data">
 */

const SYS_DEVCON_INIT sysDevconInit ={
    .moduleInit =
    {0},
};

// </editor-fold>


// *****************************************************************************
// *****************************************************************************
// Section: Static Initialization Functions
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// *****************************************************************************
// Section: System Initialization
// *****************************************************************************
// *****************************************************************************

void Harmony_SYS_InitDrivers(void* data)
{

#if defined (_USB)
    /* Initialize Drivers */
    /* Initialize USB Driver */
    HarmonySysObj.drvUSBObject = DRV_USBFS_Initialize(DRV_USBFS_INDEX_0, (SYS_MODULE_INIT *) & drvUSBInit);
#endif
    
}

void Harmony_SYS_InitDevices(void* data)
{
    
#if defined (_USB)    
    /* Initialize the USB device layer */
    HarmonySysObj.usbDevObject0 = USB_DEVICE_Initialize(USB_DEVICE_INDEX_0, (SYS_MODULE_INIT*) & usbDevInitData);
#endif
    
}

void Harmony_SYS_InitApplication(void* data)
{
    Harmony_APP_Initialize();
}

// *****************************************************************************
// *****************************************************************************
// Section: System Interrupt Vector Functions
// *****************************************************************************
// *****************************************************************************

void __attribute__((vector(_USB_1_VECTOR), interrupt(ipl6SOFT), nomips16)) _IntHandlerUSBInstance0(void)
{
    DRV_USBFS_Tasks_ISR(HarmonySysObj.drvUSBObject);
}

void Harmony_SYS_Tasks(void)
{
    /* Maintain system services */
    //    SYS_DEVCON_Tasks(HarmonySysObj.sysDevcon);

    /* Maintain Device Drivers */

    /* Maintain Middleware & Other Libraries */

#if defined(_USB)
    /* USB FS Driver Task Routine */
    DRV_USBFS_Tasks(HarmonySysObj.drvUSBObject);

    /* USB Device layer tasks routine */
    USB_DEVICE_Tasks(HarmonySysObj.usbDevObject0);
#endif
    
    /* Maintain the application's state machine. */
    Harmony_APP_Tasks();
}

/*******************************************************************************
 End of File
 */

