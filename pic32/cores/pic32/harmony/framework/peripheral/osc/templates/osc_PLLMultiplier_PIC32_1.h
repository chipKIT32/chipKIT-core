/*******************************************************************************
  OSC Peripheral Library Template Implementation

  File Name:
    osc_PLLMultiplier_PIC32_1.h

  Summary:
    OSC PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : PLLMultiplier
    and its Variant : PIC32_1
    For following APIs :
        PLIB_OSC_ExistsSysPLLMultiplier
        PLIB_OSC_SysPLLMultiplierSelect
        PLIB_OSC_SysPLLMultiplierGet

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

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
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

#ifndef _OSC_PLLMULTIPLIER_PIC32_1_H
#define _OSC_PLLMULTIPLIER_PIC32_1_H


// *****************************************************************************
/* Oscillator System PLL Multiplier Value Type

  Summary:
    Type of the oscillator system PLL multiplier value.

  Description:
    This macro defines the type of the oscillator system PLL multiplier value.

  Remarks:
    None
*/

#define OSC_SYSPLL_MULTIPLIER_TYPE					SFR_TYPE

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _OSC_OSC_SYSPLL_MULTIPLIER_VREG(index)
    _OSC_OSC_REGISTER_LOCK_VREG(index)

  MASKs: 
    _OSC_OSC_SYSPLL_MULTIPLIER_MASK(index)
    _OSC_OSC_REGISTER_LOCK_MASK(index)

  POSs: 
    _OSC_OSC_SYSPLL_MULTIPLIER_POS(index)
    _OSC_OSC_REGISTER_LOCK_POS(index)

  LENs: 
    _OSC_OSC_SYSPLL_MULTIPLIER_LEN(index)
    _OSC_OSC_REGISTER_LOCK_LEN(index)

*/


//******************************************************************************
/* Function :  OSC_ExistsSysPLLMultiplier_PIC32_1

  Summary:
    Implements PIC32_1 variant of PLIB_OSC_ExistsSysPLLMultiplier

  Description:
    This template implements the PIC32_1 variant of the PLIB_OSC_ExistsSysPLLMultiplier function.
*/

#define PLIB_OSC_ExistsSysPLLMultiplier PLIB_OSC_ExistsSysPLLMultiplier
PLIB_TEMPLATE bool OSC_ExistsSysPLLMultiplier_PIC32_1( OSC_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  OSC_SysPLLMultiplierSelect_PIC32_1

  Summary:
    Implements PIC32_1 variant of PLIB_OSC_SysPLLMultiplierSelect 

  Description:
    This template implements the PIC32_1 variant of the PLIB_OSC_SysPLLMultiplierSelect function.
*/

PLIB_TEMPLATE void OSC_SysPLLMultiplierSelect_PIC32_1( OSC_MODULE_ID index , OSC_SYSPLL_MULTIPLIER_TYPE pll_multiplier )
{
	if(( pll_multiplier < 22) && ( pll_multiplier > 14 ))
	{
		_SFR_FIELD_WRITE(_OSC_OSC_SYSPLL_MULTIPLIER_VREG(index),
						 _OSC_OSC_SYSPLL_MULTIPLIER_MASK(index),
						 _OSC_OSC_SYSPLL_MULTIPLIER_POS(index) ,
						 ( pll_multiplier - 15) );
	}
	else if( pll_multiplier == 24 )
	{
		_SFR_FIELD_WRITE(_OSC_OSC_SYSPLL_MULTIPLIER_VREG(index),
						 _OSC_OSC_SYSPLL_MULTIPLIER_MASK(index),
						 _OSC_OSC_SYSPLL_MULTIPLIER_POS(index) ,
						 ( pll_multiplier - 17) );
	}
	else
	{
	    PLIB_ASSERT(false, "Given PLL Multiplier value is not supported for the selected device");
	}
}


//******************************************************************************
/* Function :  OSC_SysPLLMultiplierGet_PIC32_1

  Summary:
    Implements PIC32_1 variant of PLIB_OSC_SysPLLMultiplierGet 

  Description:
    This template implements the PIC32_1 variant of the PLIB_OSC_SysPLLMultiplierGet function.
*/

PLIB_TEMPLATE OSC_SYSPLL_MULTIPLIER_TYPE OSC_SysPLLMultiplierGet_PIC32_1( OSC_MODULE_ID index )
{
    uint8_t multiplier;

    multiplier = _SFR_FIELD_READ(_OSC_OSC_SYSPLL_MULTIPLIER_VREG(index),
                                                             _OSC_OSC_SYSPLL_MULTIPLIER_MASK(index),
                                                             _OSC_OSC_SYSPLL_MULTIPLIER_POS(index) );

    /* Factor to actual value conversion */
    if ( ( multiplier >= 0 ) && ( multiplier < 7 ) )
    {
        return multiplier +15;
    }
    else if ( multiplier == 7 )
    {
        return multiplier +17;
    }

    /* Control should not come here */
    return 0;
}


#endif /*_OSC_PLLMULTIPLIER_PIC32_1_H*/

/******************************************************************************
 End of File
*/

