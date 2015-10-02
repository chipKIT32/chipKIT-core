/*******************************************************************************
  System Services Common Library Header

  Company:
    Microchip Technology Inc.

  File Name:
    sys_common.h

  Summary:
    Common definitions and declarations required for the system.

  Description:
    This file defines the common definitions and declarations required for the
    system.

  Remarks:
    This file is included by "system.h".
 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2011-2013 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _SYS_COMMON_H_
#define _SYS_COMMON_H_


// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include "assert.h"

#ifdef __cplusplus
    extern "C" {
#endif


/**************************************************************************
  Function:
      void SYS_ASSERT ( bool test, char *message )

  Summary:
    Implements default system assert routine, asserts that "test" is true.
  Description:
    This macro implements the default system assert routine that asserts
    that a test is true.
  Conditions:
    None.
  Input:
    test -     This is an expression that resolves to a boolean value
               (zero=false, non-zero=true)
    message -  This is a NULL-terminated character string that can be
               displayed on a debug output terminal if "test" is false (if
               supported)
  Return:
    None - Normally hangs in a loop
  Example:
    <code>
    void MyFunc ( int *pointer )
    {
        SYS_ASSERT(NULL != pointer, "NULL Pointer passed to MyFunc");

        //...
    }
    </code>
  Remarks:
    Can be overridden as desired by defining your own SYS_ASSERT macro
    before including system.h.

    The default definition removes this macro from all code because it adds
    significant size to all projects. The most efficient use is to enabled
    it in individual libraries and build them separately for debugging.
  **************************************************************************/

#ifndef SYS_ASSERT

    #define SYS_ASSERT(test,message)

#endif


// *****************************************************************************
/* Main Routine Return Type

  Summary:
    Defines the correct return type for the "main" routine.

  Description:
    This macro defines the correct return type for the "main" routine for the
    selected Microchip microcontroller family.

  Example:
    <code>
    MAIN_RETURN main ( void )
    {
        // Initialize the system
        SYS_Initialize(...);

        // Main Loop
        while(true)
        {
            SYS_Tasks();
        }

        return MAIN_RETURN_CODE(MAIN_RETURN_SUCCESS);
    }
    </code>

  Remarks:
    This type changes depending upon which family of Microchip microcontrollers
    is chosen. Most Microchip microcontrollers do not return any value from
    "main".
*/

#if defined(__PIC32MX__) || defined(__C30__)||defined(__XC32)

    #define MAIN_RETURN int

#else

    #define MAIN_RETURN void

#endif


// *****************************************************************************
/* Main Routine Code Macro

  Summary:
    Provides the correct value for the return code from "main".

  Description:
    This macro provides the correct value for the return code from "main".

  Example:
    <code>
    MAIN_RETURN main ( void )
    {
        // Initialize the system
        SYS_Initialize(...);

        // Main Loop
        while(true)
        {
            SYS_Tasks();
        }

        return MAIN_RETURN_CODE(MAIN_RETURN_SUCCESS);
    }
    </code>

  Remarks:
    Most Microchip microcontrollers do not provide a return value from "main".
    Therefore, this macro discards the code it is given unless it is needed.
*/

#if defined(__PIC32MX__) || defined(__C30__)||defined(__XC32)

    #define MAIN_RETURN_CODE(c)     ((MAIN_RETURN)(c))

#else

    #define MAIN_RETURN_CODE(c)

#endif


// *****************************************************************************
/* Main Routine Codes

  Summary:
    Predefined list of return codes for "main".

  Description:
    This enumeration provides a predefined list of return codes for "main".

  Example:
    <code>
    MAIN_RETURN main ( void )
    {
        // Initialize the system
        SYS_Initialize(...);

        // Main Loop
        while(true)
        {
            SYS_Tasks();
        }

        return MAIN_RETURN_CODE(MAIN_RETURN_SUCCESS);
    }
    </code>

  Remarks:
    These codes can be passed into the MAIN_RETURN_CODE macro to convert them
    to the appropriate type (or discard them if not needed) for the
    Microchip microcontroller in use.
*/

typedef enum
{
    MAIN_RETURN_FAILURE     = -1,

    MAIN_RETURN_SUCCESS     = 0

} MAIN_RETURN_CODES;


// *****************************************************************************
/* System Tasks Priority

  Summary:
    Defines system tasks priorities.

  Description:
    This enumeration defines the available system tasks priorities.

  Remarks
    To use medium priority tasks, a medium priority interval must be defined
    by defining SYS_TASKS_CONFIG_MEDIUM_INTERVAL to the desired interval (in
    milliseconds).

    To use low priority tasks, a low priority interval must be defined
    by defining SYS_TASKS_CONFIG_LOW_INTERVAL to the desired interval (in
    milliseconds).
*/

typedef enum _SYS_TASKS_PRIORITIES
{
    // Invalid priority (can be used as a sentinel value)
    SYS_TASKS_PRIORITY_INVALID = 0,

    // High priority tasks are called every time through the loop
    SYS_TASKS_PRIORITY_HIGH,

    // Called at the medium priority interval.
    SYS_TASKS_PRIORITY_MEDIUM,

    // Called at the low priority interval.
    SYS_TASKS_PRIORITY_LOW

} SYS_TASKS_PRIORITY;

//******************************************************************************
/* Function:
    SYS_VersionGet( void )

  Summary:
    Gets SYS_COMMON version in numerical format.

  Description:
    This routine gets the SYS_COMMON version. The version is encoded as
    major * 10000 + minor * 100 + patch. The string version can be obtained
    using SYS_VersionStrGet()

  Parameters:
    None.

  Returns:
    Current driver version in numerical format.
*/

#define SYS_VersionGet( void ) SYS_VERSION


// *****************************************************************************
/* Macro:
    char * SYS_VersionStrGet ( void )

  Summary:
    Gets SYS_COMMON version in string format.

  Description:
    This routine gets the SYS_COMMON version in string format. The version is
    returned as major.minor.path[type], where type is optional. The numerical version can
    be obtained using SYS_VersionGet()

  Parameters:
    None.

  Returns:
    Current SYS_COMMON version in the string format.

  Remarks:
    None.
*/

#define SYS_VersionStrGet( void )   SYS_VERSION_STR


#ifdef __cplusplus
    }
#endif

#endif // _SYS_COMMON_H_

/*******************************************************************************
 End of File
*/

