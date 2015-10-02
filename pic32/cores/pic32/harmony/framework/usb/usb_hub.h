/*******************************************************************************
  USB HOST HUB driver Interface Definition

  Company:
    Microchip Technology Inc.

  File Name:
    usb_host_hub.h

  Summary:
    USB HUB Layer Interface Header

  Description:
    This header file contains the function prototypes and definitions of the
    data types and constants that make up the interface to the USB HOST HUB driver
    * Connectivity behavior
    * Power management
    * Device connect/disconnect detection
    * Bus fault detection and recovery
    * High-Speed, Full-Speed, and Low-Speed device support
    
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


#ifndef _USB_HOST_HUB_H
#define _USB_HOST_HUB_H


// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include "system/common/sys_common.h"
#include "driver/driver_common.h"
#include "system/tmr/sys_tmr.h"
#include "usb/usb_host.h"
#include "usb/usb_host_client_driver.h"


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END  


// *****************************************************************************
// *****************************************************************************
// Section: USB HOST HUB CLASS DRIVER Constants
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* USB Hub Port Indicator Colors

  Summary:
    Enumerates the color of the Port Indicators.

  Description:
    This enumeration lists the possible Hub Port Indicator Colors.

  Remarks:
    None.
*/

typedef enum
{
    /* Port Indicator Color Green */ 
    USB_HUB_PORT_INDICATOR_COLOR_GREEN,

    /* Port Indicator Color Amber */
    USB_HUB_PORT_INDICATOR_COLOR_AMBER

} USB_HUB_PORT_INDICATOR_COLOR;

// *****************************************************************************
/* USB Hub Port Indicator State

  Summary:
    Enumerates the state of the Port Indicators.

  Description:
    This enumeration lists the possible Hub Port Indicator states.

  Remarks:
    None.
*/

typedef enum
{
    /* Port Indicator should be off */
    USB_HUB_PORT_INDICATOR_STATE_OFF,

    /* Port Indicator should be on */
    USB_HUB_PORT_INDICATOR_STATE_ON,

    /* Port Indicator should be blinking */
    USB_HUB_PORT_INDICATOR_STATE_BLINKING,

} USB_HUB_PORT_INDICATOR_STATE;




/* Hub  Status   Table  11-19 from spec */
#define HUB_LOW_POWER_SOURCE                     (0x01 << 0)
#define HUB_OVER_CURRENT                         (0x01 << 1)


#define      PORT_INDEX_MASK                         0xFFFF0000
#define      HUB_INDEX_MASK                          0x0000FFFF


/* HUB change Table 11-20 from spec */

#define C_HUB_LOCAL_POWER   (0x01 << 0)
#define C_HUB_OVER_CURRENT  (0x01 << 1)


/* HUB Class codes as defined by USB            */
#define USB_HUB_CLASS_CODE                          0x09

/* Port status Bit numbers  Table 11-21 from spec*/

#define HUB_PORT_CONNECTION_POS                 (0x01 << 0)
#define HUB_PORT_ENABLE_POS                     (0x01 << 1)
#define HUB_PORT_SUSPEND_POS                    (0x01 << 2)
#define HUB_PORT_OVER_CURRENT_POS               (0x01 << 3)
#define HUB_PORT_RESET_POS                     (0x01 << 4)
#define HUB_PORT_POWER_POS                      (0x01 << 8)
#define HUB_PORT_LOW_SPEED_POS                  (0x01 << 9)
#define HUB_PORT_HIGH_SPEED_POS                 (0x01 << 10)
#define HUB_PORT_TEST_POS                       (0x01 << 11)
#define HUB_PORT_INDICATOR_POS                  (0x01 << 12)

/* Port Change  Bit numbers Table 11-22 from spec */

// #define HUB_CHANGE_PORT_CONNECTION               (0x01 << 0)
// #define HUB_CHANGE_PORT_ENABLE                   (0x01 << 1)
// #define HUB_CHANGE_PORT_SUSPEND                  (0x01 << 2)
// #define HUB_CHANGE_PORT_OVER_CURRENT             (0x01 << 3)
// #define HUB_CHANGE_PORT_RESET                    (0x01 << 4)


/* HUB Commands  */

#define USB_HOST_HUB_COMMAND_GET_STATUS                      0x0
#define USB_HOST_HUB_COMMAND_CLEAR_FEATURE                   0x1
#define USB_HOST_HUB_COMMAND_SET_FEATURE                     0x3
#define USB_HOST_HUB_COMMAND_GET_DESCRIPTOR                  0x6
#define USB_HOST_HUB_COMMAND_SET_DESCRIPTOR                  0x7


#define  USB_HOST_HUB_GET_PORT_STATUS                 0x51
#define  USB_HOST_HUB_GET_STATUS                      0x50
/* Port commands */



#define HUB_NORMAL                              0x0
#define HUB_SHUTDOWN                            0x1
#define HUB_DIRTY                               0x2

#define HUB_CHANGE_PORT_CONNECTION           16
#define HUB_CHANGE_PORT_ENABLE               17
#define HUB_CHANGE_PORT_SUSPEND              18
#define HUB_CHANGE_PORT_OVER_CURRENT         19
#define HUB_CHANGE_PORT_RESET                20






/* wPortStatus  */

#define USB_HOST_HUB_BIT_PORT_CONNECTION                 (0x01 << 0)
#define USB_HOST_HUB_BIT_PORT_ENABLE                     (0x01 << 1)
#define USB_HOST_HUB_BIT_PORT_SUSPEND                    (0x01 << 2)
#define USB_HOST_HUB_BIT_PORT_OVER_CURRENT               (0x01 << 3)
#define USB_HOST_HUB_BIT_PORT_RESET                      (0x01 << 4)

#define USB_HOST_HUB_BIT_PORT_POWER                      (0x01 << 8)
#define USB_HOST_HUB_BIT_PORT_LOW_SPEED                  (0x01 << 9)
#define USB_HOST_HUB_BIT_PORT_HIGH_SPEED                 (0x01 << 10)

/* wPortChange  */

#define USB_HOST_HUB_BIT_C_PORT_CONNECTION               (0x01 << 0)
#define USB_HOST_HUB_BIT_C_PORT_ENABLE                   (0x01 << 1)
#define USB_HOST_HUB_BIT_C_PORT_SUSPEND                  (0x01 << 2)
#define USB_HOST_HUB_BIT_C_PORT_OVER_CURRENT             (0x01 << 3)
#define USB_HOST_HUB_BIT_C_PORT_RESET                    (0x01 << 4)


/* The following commands have a port as the recipient */

#define HUB_FEATURE_PORT_CONNECTION             0
#define USB_HOST_HUB_FEATURE_PORT_ENABLE                 1
#define HUB_FEATURE_PORT_SUSPEND                2
#define HUB_FEATURE_PORT_OVER_CURRENT           3
#define HUB_FEATURE_PORT_RESET                  4
#define HUB_FEATURE_PORT_POWER                  8
#define HUB_FEATURE_PORT_LOW_SPEED              9
#define HUB_FEATURE_PORT_HIGH_SPEED             10
#define USB_HOST_HUB_FEATURE_C_PORT_CONNECTION  16
#define HUB_FEATURE_C_PORT_ENABLE               17
#define HUB_FEATURE_C_PORT_SUSPEND              18
#define HUB_FEATURE_C_PORT_OVER_CURRENT         19
#define HUB_FEATURE_C_PORT_RESET                20


/*******************************************************************************/

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END
 
#endif

