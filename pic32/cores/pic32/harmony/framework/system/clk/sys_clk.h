/*******************************************************************************
  Clock System Service Interface Definition

  Company:
    Microchip Technology Inc.

  File Name:
    sys_clk.h

  Summary:
    Clock system service interface header.

  Description:
    This file contains the interface definition for the Clock System
    Service.  It provides a way to interact with the Clock subsystem to
    manage the timing requests supported by the system.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _SYS_CLK_H
#define _SYS_CLK_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************
#include "system_config.h"
#include "system/common/sys_module.h"
#include "peripheral/osc/plib_osc.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END  


// *****************************************************************************
// *****************************************************************************
// Section: SYS Clock Data Types - Clock Buses
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/*  Peripherals Clock Buses enumeration

  Summary:
	Lists the available peripheral clock buses.

  Description:
	This enumeration lists all of the available peripheral clock buses. This is
	used by the SYS_CLK_PeripheralFrequencyGet and
	SYS_CLK_PeripheralFrequencySet functions.

  Remarks:
    The system service covers a wide range of devices. Not all the elements
	listed in here will be relevant for the your device.
*/

typedef enum
{
    /* Select peripheral bus 1. This should be the selection for the
	devices which doesn't have multiple peripheral buses */
	CLK_BUS_PERIPHERAL_1 ,

	/* Select peripheral bus 2 */
	CLK_BUS_PERIPHERAL_2,

	/* Select peripheral bus 3 */
	CLK_BUS_PERIPHERAL_3,

	/* Select peripheral bus 4 */
	CLK_BUS_PERIPHERAL_4,

	/* Select peripheral bus 5 */
        CLK_BUS_PERIPHERAL_5,

	/* Select peripheral bus 7 */
	CLK_BUS_PERIPHERAL_7,

	/* Select peripheral bus 8 */
	CLK_BUS_PERIPHERAL_8,

}CLK_BUSES_PERIPHERAL;


// *****************************************************************************
/*  Reference Clock Buses enumeration

  Summary:
	Lists the available reference clock buses.

  Description:
	This enumeration lists all of the available Reference clock buses. This is
	used by the SYS_CLK_ReferenceClockFrequencyGet and
	SYS_CLK_ReferenceFrequencySet functions.

  Remarks:
    The system service covers a wide range of devices. Not all the elements
	listed in here will be relevant for the your device.
*/

typedef enum
{
    /* Select Reference bus 1. This should be the selection for the
	devices which doesn't have multiple Reference buses */
	CLK_BUS_REFERENCE_1 ,

	/* Select Reference bus 2 */
	CLK_BUS_REFERENCE_2,

	/* Select Reference bus 3 */
	CLK_BUS_REFERENCE_3,

	/* Select Reference bus 4 */
	CLK_BUS_REFERENCE_4,

}CLK_BUSES_REFERENCE;


// *****************************************************************************
// *****************************************************************************
// Section: SYS Clock Data Types - Clock sources
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/*  System Clock sources enumeration

  Summary:
    Lists the available clock sources for the system clock.

  Description:
    This enumeration lists all the available clock sources for the system clock.
	This is used by the SYS_CLK_INIT structure.

  Remarks:
*/

typedef enum
{
    /* Source of clock is internal fast RC */
    SYS_CLK_SOURCE_FRC,

    /* Source of clock is internal fast RC multiplied by system PLL */
    SYS_CLK_SOURCE_FRC_SYSPLL,

    /* Source of clock is primary oscillator */
    SYS_CLK_SOURCE_PRIMARY,

    /* Source of clock is primary oscillator multiplied by
    the System PLL value and divided by the divisor configured by software */
    SYS_CLK_SOURCE_PRIMARY_SYSPLL,

    /* Source of clock is secondary oscillator */
    SYS_CLK_SOURCE_SECONDARY,

    /* Source of clock is internal low power RC */
    SYS_CLK_SOURCE_LPRC,

    /* Source of clock is internal fast RC divided by the divisor
    configured in software */
    SYS_CLK_SOURCE_FRC_BY_16,

    /* Source of clock is internal fast RC divided by the divisor
    configured in software */
    SYS_CLK_SOURCE_FRC_BY_DIV,

}CLK_SOURCES_SYSTEM;


// *****************************************************************************
/*  Peripheral clock sources enumeration

  Summary:
    Lists the available clock sources for the peripheral clock.

  Description:
    This enumeration lists all the available peripheral clock sources. This is
    used by the SYS_CLK_PeripheralFrequencySet function.

  Remarks:
   	None.
*/

typedef enum
{
    /* Source of clock is system clock */
    CLK_SOURCE_PERIPHERAL_SYSTEMCLK

}CLK_SOURCES_PERIPHERAL;


// *****************************************************************************
/*  Reference clock sources enumeration

  Summary:
    Lists the available clock sources for the Reference clock.

  Description:
    This enumeration lists all the available peripheral clock sources. This is
    used by the SYS_CLK_ReferenceFrequencySet function.

  Remarks:
   	None.
*/

typedef enum
{
    /* Source of Reference clock is System clock */
    CLK_SOURCE_REF_SYSTEMCLK,

    /* Source of Reference clock is Peripheral clock */
    CLK_SOURCE_REF_PBCLK_BUS1,

    /* Source of Reference clock is Primary oscillator */
    CLK_SOURCE_REF_PRIMARY,

    /* Source of Reference clock is Fast RC oscillator */
    CLK_SOURCE_REF_FRC,

    /* Source of Reference clock is Low power RC oscillator */
    CLK_SOURCE_REF_LPRC,

    /* Source of Reference clock is Secondary oscillator */
    CLK_SOURCE_REF_SECONDARY,

    /* Source of clock is output of USB PLL
    This is used only for the Reference clock. */
    CLK_SOURCE_REF_USBPLL_OUT ,

    /* Source of clock is the output of System PLL. Input to the
    system PLL may be Primary or FRC */
    CLK_SOURCE_REF_SYSPLL_OUT ,

    /* Source of clock is external(from the pin) */
    CLK_SOURCE_REF_EXTERNAL,

    /* Source of Reference clock is backup Fast RC oscillator */
    CLK_SOURCE_REF_BFRC,    

}CLK_SOURCES_REFERENCE;


// *****************************************************************************
/*  System clock operation status

  Summary:
    Lists all the possible status of a system clock operation.

  Description:
    This enumeration lists all the possible status of a system clock operation.
	
  Remarks:
   	None.
*/

typedef enum
{
    /* The last operation was successful */
    SYS_CLK_OPERATION_COMPLETE /*DOM-IGNORE-BEGIN*/ = 0 /*DOM-IGNORE-END*/,

    /* Operation started, may be PLL is not yet locked */
    SYS_CLK_OPERATION_IN_PROGRESS /*DOM-IGNORE-BEGIN*/ = 1 /*DOM-IGNORE-END*/,

    /* The last operation was not successful, Clock switching is not enabled
    through configuration bits */
    SYS_CLK_OPERATION_FAIL_SWITCHING_DISABLED /*DOM-IGNORE-BEGIN*/ = -1 /*DOM-IGNORE-END*/,

    /* The last operation was not successful, requested frequency
    is not achievable */
    SYS_CLK_OPERATION_FAIL_NOT_ACHIEVABLE /*DOM-IGNORE-BEGIN*/ = -2 /*DOM-IGNORE-END*/,

     /* The last operation was not successful, register is not ready to
     take the new value  */
     SYS_CLK_OPERATION_FAIL_REGISTER_NOT_READY /*DOM-IGNORE-BEGIN*/ = -3 /*DOM-IGNORE-END*/,

     /* The last operation was not successful, USB PLL is not enabled in
     through the 'configuration bits'. The same must be update in system_config.h  */
     SYS_CLK_OPERATION_FAIL_USBPLL_NOT_ENABLED /*DOM-IGNORE-BEGIN*/ = -4 /*DOM-IGNORE-END*/,

     /* PLL Lock time out. A restart is the only option  */
     SYS_CLK_OPERATION_FAIL_PLL_LOCK_TIMEOUT /*DOM-IGNORE-BEGIN*/ = -5 /*DOM-IGNORE-END*/,

     /* PLL cannot work with the current input clock frequency, adjust the
     clock input or the input divisor. Check the device data sheet to know the PLL input
     requirement */
     SYS_CLK_PLL_INVALID_INP_FREQUENCY /*DOM-IGNORE-BEGIN*/ = -6 /*DOM-IGNORE-END*/,
}SYS_CLK_STATUS;


// *****************************************************************************
// *****************************************************************************
// Section: SYS Clock Data Types - Structures
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* CLK System Service Error Handler Function Pointer

   Summary
    Pointer to a CLK System service SYS_CLK_ClockFailureCallbackRegister 
	function.

   Description
    This data type defines the type of the CLK System Service Error Handler
    callback function. The parameters are described here and a partial example 
	implementation is provided. On a clock failure, the device will switch its
	clock source to the FRC clock. By registering the callback function user 
	will get the current System clock source and the clock frequency. User can 
	use this information to try switching back.

  Parameters:
    systemSource    - System clock source. 

    systemFrequencyHz - System clock frequency in hertz.

  Returns:
    None.

  Example:
    <code>
    void SYS_CLK_ClockFailureCallbackRegister(  errorHandler );
    
	errorHandler ( CLK_SOURCES_SYSTEM systemSource, uint32_t systemFrequencyHz )
	{
		//Log a warning
		//Try switching back to the old source
	}
    </code>

  Remarks:
   
*/

typedef void ( *SYS_CLK_ERROR_HANDLER )  ( CLK_SOURCES_SYSTEM systemSource, uint32_t systemFrequencyHz );


// *****************************************************************************
/* Clock System Service Reference Oscillator initialization data

  Summary:
    Defines the data required to initialize the Oscillator for the Clock System
    Service.

  Description:
    This structure defines the data required to initialize the Oscillator
    for the Clock System Service.

  Remarks:
    This structure only includes the necessary settings for the clock module.
    Other features like USB clock and reference clock are considered to be
    optional and not every system will use it. There are dedicated APIs for
    configuring those.
*/

typedef	struct
{
	/* System module initialization */
    SYS_MODULE_INIT                 moduleInit;
    
	/* Initializations for System clock  */
    CLK_SOURCES_SYSTEM systemClockSource;

	/* Set the System clock frequency */
    uint32_t systemClockFrequencyHz;

    /* Wait until the clock switch operation is completed */
    bool waitTillComplete;

    /* Even though the secondary oscillator is not used, keeping the
    oscillator running, allows a fast switch to the lower system
    clock for low-power operation */
    bool secondaryOscKeepEnabled;

    /* System action on a 'Wait' instruction */
    OSC_OPERATION_ON_WAIT onWaitInstruction;

}SYS_CLK_INIT;


// *****************************************************************************
/* Clock System Service Reference Oscillator initialization data

  Summary:
    Defines the data required to initialize the Oscillator for the Clock System
    Service.

  Description:
    This structure defines the data required to initialize the Oscillator
    for the Clock System Service.

  Remarks:
    This structure only includes the necessary settings for the clock module.
    Other features like USB clock and reference clock are considered to be
    optional and not every system will use it. There are dedicated APIs for
    configuring those.
*/

typedef	struct
{
	/* Reference clock module should be stop its operation in 'Sleep' mode */
	bool suspendInSleep;
	
	/* Reference clock module should be stop its operation in 'Idle' mode */
	bool stopInIdle;
	
}SYS_CLK_REFERENCE_SETUP;


// *****************************************************************************
/* Clock module FRC tuning type

  Summary:
    Defines the data type for tuning the FRC Oscillator.

  Description:
    This structure defines the data type to tune the FRC Oscillator.

  Remarks:
   None.
*/

typedef	unsigned int SYS_CLK_FRC_TUNING_TYPE;


// *****************************************************************************
// *****************************************************************************
// Section: SYS CLK Module Initialization Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void SYS_CLK_Initialize ( const SYS_CLK_INIT * clkInit )

  Summary:
    Initializes hardware and internal data structure of the System Clock.
	<p><b>Implementation:</b> Static/Dynamic</p>

  Description:
    This function initializes the hardware and internal data structure of System
    Clock Service.

  Precondition:
    None.

  Parameters:
    clkInit      - Pointer to a data structure containing any data necessary
                   to initialize the System Clock. This pointer can be
                   NULL if no data is required as static overrides have
                   been provided.

  Returns:
    None.

  Example:
    <code>
	//Example 1: Do not alter the configuration bit settings
	SYS_CLK_Initialize ( NULL );
	
	//Example 2: Want to change the configuration bit settings
    SYS_CLK_INIT generalInit;

    // Populate the oscillator initialization structure
    generalInit.systemClockSource = SYS_CLK_SOURCE_FRC_SYSPLL;
    generalInit.systemClockFrequencyHz = 30000000;
    generalInit.onWaitInstruction = OSC_ON_WAIT_SLEEP;
	generalInit.secondaryOscKeepEnabled = true;
    SYS_CLK_Initialize (&generalInit);

	//Wait until complete
	while ( SYS_CLK_SystemOperationStatus ( ) !=  SYS_CLK_OPERATION_COMPLETE );
	
	//Configuration success
    </code>

  Remarks:
    This is API must be be called at the time of system initialization to
	initialize the oscillator. Call this again to change any of the
	initialization settings.

	If the frequency settings are already done through the 'configuration bits',
	call this API by passing 'NULL' to it. In any case calling this API is
	necessary get the internal data structures updated.
	
	To change the clock source clock switching must be enabled through 
	'configuration bits'. 
*/

void SYS_CLK_Initialize ( const SYS_CLK_INIT * clkInit );


// *****************************************************************************
// *****************************************************************************
// Section: System clock APIs
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
	uint32_t SYS_CLK_SystemFrequencySet ( CLK_SOURCES_SYSTEM systemSource,
								uint32_t systemClockHz, bool waitUntilComplete )

  Summary:
    Configures the System clock of the device to the value specified.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
	This function configures the clock multipliers and divisors to achieve requested
	System clock frequency. Initially it checks the difference between the requested
	value and possible value. If it is not within 'SYS_CLK_CONFIG_FREQ_ERROR_LIMIT',
	the registers values will not be changed and a value '0' will be returned to let
	user know that the operation was unsuccessful. If the value requested is acceptable,
	then it writes to the oscillator registers and return with the newly set frequency.

  Precondition:
    The SYS_CLK_Initialize function should be called before calling this API. To 
	change the clock source, clock switching must be enabled through 'configuration bits'.
	

  Parameters:
    systemSource 	- Clock source means the path of the clock signal. One of the 
						possible value from CLK_SOURCES_SYSTEM enum. See the block 
						diagram in the data sheet to get an idea.

    systemClockHz	- Required System Clock frequency in Hertz.

	waitUntilComplete - Passing this parameter as 'true' will make until the actual
						hardware operation is complete.

  Returns:
    'Zero' on an unsuccessful operation. Configured system clock frequency on successful
	operation.

  Example:
    <code>
	uint32_t achievedFrequencyHz;

	// ******** Blocking call******
	achievedFrequencyHz = SYS_CLK_SystemClockFrequencySet (
		SYS_CLK_SOURCE_PRIMARY, 8000000, true );

	if ( achievedFrequencyHz != 0 )
	{
		//Clock setting complete
	}

	</code>

  Remarks:
	Getting the new frequency doesn't mean that the operation is complete if the 
	API is not called to 'wait until' the operation is complete. The API will 
	return with the possible value immediately. The actual hardware switching
	may take longer. Use SYS_CLK_SystemClockStatus function to get the status
	of completion.

	Calling this API is only necessary to change the system clock. Use
	SYS_CLK_Initialize function to set up the system clock initially.
*/

uint32_t SYS_CLK_SystemFrequencySet ( CLK_SOURCES_SYSTEM systemSource,
								uint32_t systemClockHz, bool waitUntilComplete );


//******************************************************************************
/* Function:
    uint32_t SYS_CLK_SystemFrequencyGet ( void )

  Summary:
    Gets the system clock frequency in Hertz.
	<p><b>Implementation:</b> Static/Dynamic</p>

  Description:
    This function gets the System clock frequency in Hertz.

  Precondition:
    The SYS_CLK_Initialize function should be called before calling this API.

  Parameters:
    None.

  Returns:
    System clock frequency in Hertz.

  Example:
    <code>
    uint32_t sysClockHz;

    sysClockHz = SYS_CLK_SystemFrequencyGet ( );
    </code>

  Remarks:
 */

uint32_t SYS_CLK_SystemFrequencyGet ( void );


// *****************************************************************************
// *****************************************************************************
// Section: Peripheral clock APIs
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
	uint32_t SYS_CLK_PeripheralFrequencySet ( CLK_BUSES_PERIPHERAL peripheralBus,
				CLK_SOURCES_PERIPHERAL peripheralSource, uint32_t peripheralClockHz, 
				bool waitUntilComplete )

  Summary:
    Configures the peripheral clock of the device to the value specified.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function configures the clock multipliers and divisors to achieve requested
	Peripheral clock frequency. Initially it checks the difference between the requested
	value and possible value. If it is not within 'SYS_CLK_CONFIG_FREQ_ERROR_LIMIT',
	the registers values will not be changed and a value '0' will be returned to let
	user know that the operation was unsuccessful. If the value requested is acceptable,
	then it writes to the oscillator registers and return with the newly set frequency. 
	If the operation is a failure, SYS_CLK_PeripheralClosestFrequencyGet function will 
	give the closest possible frequency. If the closest possible value is acceptable, 
	user can reconfigure with that value.

  Precondition:
    The SYS_CLK_Initialize function should be called before calling this API.

  Parameters:
	peripheralBus - Peripheral bus selection. One of the possible value from
					CLK_BUSES_PERIPHERAL enum. For devices that do not have multiple
					clock channels for Peripheral clock, CLK_BUS_PERIPHERAL_1 should
					be the selection.

	peripheralSource  - Clock source means the path of the clock signal. One of the 
					    possible value from CLK_SOURCES_PERIPHERAL enum. See the block 
						diagram in the data sheet to get an idea.

    peripheralClockHz - Clock frequency in Hertz.

	waitUntilComplete - Passing this parameter as 'true' will make until the actual
						hardware operation is complete.
						
  Returns:
    None.

  Example:
    <code>
	uint32_t achievedFrequencyHz;

	//Example for MX, single peripheral bus
	achievedFrequencyHz = SYS_CLK_PeripheralFrequencySet ( CLK_BUS_PERIPHERAL_1,
		CLK_SOURCE_PERIPHERAL_SYSTEMCLK, 8000000, true );

	if ( achievedFrequencyHz !=  0 )
	{
		//Frequency successfully set 
	}

	//Example for MZ, multiple peripheral buses
	achievedFrequencyHz = SYS_CLK_PeripheralFrequencySet ( CLK_BUS_PERIPHERAL_4,
		CLK_SOURCE_PERIPHERAL_SYSTEMCLK, 8000000, true );

	if ( achievedFrequencyHz !=  0 )
	{
		//Frequency successfully set 
	}
	</code>

  Remarks:
	Most of the devices doesn't have multiple Peripheral clock buses. In that
	case, pass CLK_BUS_PERIPHERAL_1 as the bus number.
*/

uint32_t SYS_CLK_PeripheralFrequencySet ( CLK_BUSES_PERIPHERAL peripheralBus,
				CLK_SOURCES_PERIPHERAL peripheralSource, uint32_t peripheralClockHz, 
				bool waitUntilComplete );


//******************************************************************************
/* Function:
    uint32_t SYS_CLK_PeripheralFrequencyGet ( CLK_BUSES_PERIPHERAL peripheralBus )

  Summary:
    Gets the selected clock peripheral bus frequency in Hertz.
	<p><b>Implementation:</b> Static/Dynamic</p>

  Description:
    This function gets the selected peripheral bus clock frequency in Hertz.

  Precondition:
	The SYS_CLK_Initialize function should be called before calling this API.

  Parameters:
	peripheralBus - Reference clock bus selection. One of the possible value from
				CLK_BUSES_PERIPHERAL enum. For devices that do not have multiple
				clock channels for Reference clock, CLK_BUS_PERIPHERAL_1 should be
				the selection.

  Returns:
    Clock frequency in Hertz.

  Example:
    <code>
    unsigned long peripheralClockHz;

    peripheralClockHz = SYS_CLK_PeripheralFrequencyGet ( CLK_BUS_PERIPHERAL_5 );
    </code>

  Remarks:
	Most of the devices doesn't have multiple Peripheral clock buses. In that case, 
	pass CLK_USB_PERIPHERAL_1 as the bus number.
 */

uint32_t SYS_CLK_PeripheralFrequencyGet ( CLK_BUSES_PERIPHERAL peripheralBus );


// *****************************************************************************
// *****************************************************************************
// Section: Reference clock APIs
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
	void SYS_CLK_ReferenceClockSetup ( CLK_BUSES_REFERENCE referenceBus,
											SYS_CLK_REFERENCE_SETUP refSetup )

  Summary:
    Configures the reference clock of the device to the value specified.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function configures the clock multipliers and divisors to achieve requested
	Reference clock frequency. Initially it checks the difference between the requested
	value and possible value. If it is not within 'SYS_CLK_CONFIG_FREQ_ERROR_LIMIT',
	the registers values will not be changed and a value '0' will be returned to let
	user know that the operation was unsuccessful. If the value requested is acceptable,
	then it writes to the oscillator registers and return with the newly set frequency. 
	If the operation is a failure, SYS_CLK_ReferenceClosestFrequencyGet function will 
	give the closest possible frequency. If the closest possible value is acceptable, 
	user can reconfigure with that value.

  Precondition:
    The SYS_CLK_Initialize function should be called before calling this API.

  Parameters:
    referenceBus  - Reference clock bus selection. One of the possible value from
					CLK_BUSES_REFERENCE enum. For devices that do not have multiple
					clock channels for Reference clock, CLK_BUS_REFERENCE_1 should be
					the selection.

    refSetup	  - A structure which holds the reference oscillator configuration.						

  Returns:
    None.

  Example:
    <code>
	SYS_CLK_REFERENCE_SETUP refSetup;
	
	refSetup.suspendInSleep = true;
	refSetup.stopInIdle = true;
	
	SYS_CLK_ReferenceClockSetup ( ( CLK_BUS_REFERENCE_3, &refSetup );
    </code>

  Remarks:
    Most of the devices doesn't have multiple reference clock buses. In that case, pass
	CLK_BUS_REFERENCE_1 as the bus number.
*/

void SYS_CLK_ReferenceClockSetup ( CLK_BUSES_REFERENCE referenceBus,
											SYS_CLK_REFERENCE_SETUP *refSetup );
				
				
// *****************************************************************************
/* Function:
	uint32_t SYS_CLK_ReferenceFrequencySet ( CLK_BUSES_REFERENCE referenceBus,
				CLK_SOURCES_REFERENCE referenceSource, uint32_t referenceClockHz, 
				bool waitUntilComplete )

  Summary:
    Configures the reference clock of the device to the value specified.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function configures the clock multipliers and divisors to achieve requested
	Reference clock frequency. Initially it checks the difference between the requested
	value and possible value. If it is not within 'SYS_CLK_CONFIG_FREQ_ERROR_LIMIT',
	the registers values will not be changed and a value '0' will be returned to let
	user know that the operation was unsuccessful. If the value requested is acceptable,
	then it writes to the oscillator registers and return with the newly set frequency. 
	If the operation is a failure, SYS_CLK_ReferenceClosestFrequencyGet function will 
	give the closest possible frequency. If the closest possible value is acceptable, 
	user can reconfigure with that value.

  Precondition:
    The SYS_CLK_Initialize function should be called before calling this API. To 
	change the clock source clock switching must be enabled through 'configuration 
	bits'.

  Parameters:
    referenceBus  - Reference clock bus selection. One of the possible value from
					CLK_BUSES_REFERENCE enum. For devices that do not have multiple
					clock channels for Reference clock, CLK_BUS_REFERENCE_1 should be
					the selection.

    referenceSource	  - Clock source means the path of the clock signal. One of the 
					possible value from CLK_SOURCES_REFERENCE enum. See the block 
					diagram in the data sheet to get an idea.

    referenceClockHz	- Clock frequency in Hertz.
	
	waitUntilComplete - Passing this parameter as 'true' will make until the actual
						hardware operation is complete.
						

  Returns:
    None.

  Example:
    <code>
	uint32_t achievedFrequencyHz;
	
	//I want 200 KHz as output
	achievedFrequencyHz = SYS_CLK_ReferenceFrequencySet ( CLK_BUS_REFERENCE_3,
		CLK_SOURCE_REF_FRC, 200000, true );

	if ( achievedFrequencyHz != 0 )
	{
		//Frequency successfully set
	}
    </code>

  Remarks:
    Most of the devices doesn't have multiple reference clock buses. In that case, pass
	CLK_BUS_REFERENCE_1 as the bus number.
*/

uint32_t SYS_CLK_ReferenceFrequencySet ( CLK_BUSES_REFERENCE referenceBus,
				CLK_SOURCES_REFERENCE referenceSource, uint32_t referenceClockHz, 
				bool waitUntilComplete );


//******************************************************************************
/* Function:
    uint32_t SYS_CLK_ReferenceClockFrequencyGet ( CLK_BUSES_REFERENCE referenceBus )

  Summary:
    Gets the selected Reference clock bus frequency in Hertz.
	<p><b>Implementation:</b> Static/Dynamic</p>

  Description:
    This function gets frequency of the selected Reference clock bus in Hertz.

  Precondition:
	The SYS_CLK_Initialize function should be called before calling this API.

  Parameters:
	peripheralBus - Reference clock bus selection. One of the possible value from
				CLK_BUSES_REFERENCE enum. For devices that do not have multiple
				clock channels for Reference clock, CLK_BUS_REFERENCE_1 should be
				the selection.

  Returns:
    Clock frequency in Hz.

  Example:
    <code>
    unsigned long sysClockOutputHz;

    sysClockOutputHz = SYS_CLK_ReferenceClockFrequencyGet ( CLK_BUS_REFERENCE_3 );
    </code>

  Remarks:
 */

uint32_t SYS_CLK_ReferenceClockFrequencyGet ( CLK_BUSES_REFERENCE referenceBus );


// *****************************************************************************
// *****************************************************************************
// Section: Error checking Routines
// *****************************************************************************
// *****************************************************************************
		
//******************************************************************************
/* Function:
    void SYS_CLK_ClockFailureCallbackRegister ( SYS_CLK_ERROR_HANDLER callback )

  Summary:
    Allows registration of a call back function that will be triggered on a 
	clock failure.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function allows registration of a callback function that will be
    triggered on a clock failure. 

  Precondition:
    None.

  Parameters:
    callback 	- Address of a callback function of type 'SYS_CLK_ERROR_HANDLER'.

  Returns:
    None.

  Example:
    <code>
    SYS_CLK_ClockFailureCallbackRegister ( &ErrorHandle );

    void ErrorHandle (void)
    {
		//Handle the error.
	}
    </code>

  Remarks:
    This function is not available on all devices. Please refer to the specific
    device data sheet for availability.
*/

void SYS_CLK_ClockFailureCallbackRegister ( SYS_CLK_ERROR_HANDLER callback );


//******************************************************************************
/* Function:
    void SYS_CLK_TaskError ( void )

  Summary:
    Informs the user on a clock failure by invoking the registered call back 
	function.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function informs the user on a clock failure by invoking the registered 
	call back function. This must be called from the Fail Safe Clock Monitor (FSCM)
	interrupt service routine.

  Precondition:
    None.

  Parameters:
    index      - Identifies the desired System Clock

  Returns:
    None.

  Example:
    <code>
    void clockMonitorISR ( void )
	{
		SYS_CLK_TaskError ( void );
	}
    </code>

  Remarks:
    None.
*/

void SYS_CLK_TaskError ( void );


// *****************************************************************************
// *****************************************************************************
// Section: SYS Clock Optional features
// *****************************************************************************
// *****************************************************************************
/* These APIs may not be applicable for all the devices */

//******************************************************************************
/* Function:
    void SYS_CLK_FRCTune ( SYS_CLK_FRC_TUNING_TYPE tuningData )

  Summary:
    This function is used for direct value based FRC oscillator tuning.
	<p><b>Implementation:</b> Dynamic</p>

  Description:
    This function tunes the FRC as per the given value. FRC tuning functionality
    has been provided to help customers compensate for temperature effects on
    the FRC frequency over a wide range of temperatures.

  Precondition:
    The device selected must support the oscillator tuning feature.

  Parameters:
    tuningData - One of the possible value of Tuning. Refer to the device
                 datasheet for possible values.

  Returns:
    None.

  Example:
    <code>
    SYS_CLK_FRCTune	( ox30 );
    </code>

  Remarks:
    The tuning step size is an approximation, and is neither characterized, nor
    tested.

    This API may can be only used with devices that support direct value
    based FRC tuning. Refer to the specific device data sheet to determine
    whether this feature exists for your device.
 */

void SYS_CLK_FRCTune ( SYS_CLK_FRC_TUNING_TYPE tuningData );

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif //SYS_CLK_H

/*******************************************************************************
 End of File
*/

