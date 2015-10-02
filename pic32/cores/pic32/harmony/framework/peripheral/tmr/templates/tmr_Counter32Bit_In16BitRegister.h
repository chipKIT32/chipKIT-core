/*******************************************************************************
  TMR Peripheral Library Template Implementation

  File Name:
    tmr_Counter32Bit_In16BitRegister.h

  Summary:
    TMR PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : Counter32Bit
    and its Variant : In16BitRegister
    For following APIs :
        PLIB_TMR_Counter32BitSet
        PLIB_TMR_Counter32BitGet
        PLIB_TMR_Counter32BitClear
        PLIB_TMR_ExistsCounter32Bit

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

#ifndef _TMR_COUNTER32BIT_IN16BITREGISTER_H
#define _TMR_COUNTER32BIT_IN16BITREGISTER_H


// *****************************************************************************
/* Maintains the foot print of timer registers.

  Summary:
	Structure which maintains the foot print of timer registers.

  Description:
    This structure maintains the foot print of timer registers. Used to access
	another insance of the timer from one.

  Remarks:
    None
*/

typedef struct _tmr_registers
{
    volatile uint32_t timerX1;
    volatile uint32_t offSet1[119];
    volatile uint32_t timerX1Reg1;
    volatile uint32_t offSet2[3];
    volatile uint32_t timerX2Reg2;
    volatile uint32_t offSet3[3];
    volatile uint32_t timerX2;
} TMR_REG;

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are

  VREGs:
    _TMR_VALUE_REGISTER_16BIT_LOW_VREG(index)

  MASKs:
    _TMR_VALUE_REGISTER_16BIT_LOW_MASK(index)

  POSs:
    _TMR_VALUE_REGISTER_16BIT_LOW_POS(index)

  LENs:
    _TMR_VALUE_REGISTER_16BIT_LOW_LEN(index)

*/


//******************************************************************************
/* Function :  TMR_Counter32BitSet_In16BitRegister

  Summary:
    Implements In16BitRegister variant of PLIB_TMR_Counter32BitSet

  Description:
    This template implements the In16BitRegister variant of the PLIB_TMR_Counter32BitSet function.
*/

PLIB_TEMPLATE void TMR_Counter32BitSet_In16BitRegister( TMR_MODULE_ID index , uint32_t value )
{
	TMR_REG *pTmrModule;
    pTmrModule =  (TMR_REG*)_TMR_VALUE_REGISTER_16BIT_LOW_VREG( index );

    if( _TMR_PERIOD_MATCH_MODE_VREG( index ) == (SFR_TYPE *)-1 )
    {
        uint32_t val1 = 0, val2 = 0, per;
        val1 = _SFR_READ( _TMR_VALUE_REGISTER_16BIT_LOW_VREG( index ) );
        val2 = ((uint32_t)_SFR_READ( &pTmrModule->timerX2) << 16);
        per = val1 | val2;

        /* Overflow TMR */
        _SFR_WRITE( &pTmrModule->timerX2, _PLIB_ACCESS_DOUBLE_BYTE( ( UINT32_MAX + 1 - per + (uint32_t)value ), 1 ) );
        _SFR_WRITE( _TMR_VALUE_REGISTER_16BIT_LOW_VREG( index ), ( UINT32_MAX + 1 - per + (uint32_t)value ) );
    }
    else
    {
        /* Period Match TMR */
        _SFR_WRITE( &pTmrModule->timerX2, _PLIB_ACCESS_DOUBLE_BYTE( value, 1 ) );
        _SFR_WRITE( _TMR_VALUE_REGISTER_16BIT_LOW_VREG( index ), value );
    }

}


//******************************************************************************
/* Function :  TMR_Counter32BitGet_In16BitRegister

  Summary:
    Implements In16BitRegister variant of PLIB_TMR_Counter32BitGet

  Description:
    This template implements the In16BitRegister variant of the PLIB_TMR_Counter32BitGet function.
*/

PLIB_TEMPLATE uint32_t TMR_Counter32BitGet_In16BitRegister( TMR_MODULE_ID index )
{
    TMR_REG *pTmrModule;
    uint32_t val1 = 0, val2 = 0, per;
    pTmrModule =  (TMR_REG*)_TMR_VALUE_REGISTER_16BIT_LOW_VREG( index );

    val1 = _SFR_READ( _TMR_VALUE_REGISTER_16BIT_LOW_VREG( index ) );
    val2 = ((uint32_t)_SFR_READ( &pTmrModule->timerX2 ) << 16);
    per = val1 | val2;
    return ( per );
}


//******************************************************************************
/* Function :  TMR_Counter32BitClear_In16BitRegister

  Summary:
    Implements In16BitRegister variant of PLIB_TMR_Counter32BitClear

  Description:
    This template implements the In16BitRegister variant of the PLIB_TMR_Counter32BitClear function.
*/

PLIB_TEMPLATE void TMR_Counter32BitClear_In16BitRegister( TMR_MODULE_ID index )
{
	TMR_REG *pTmrModule;
	pTmrModule =  (TMR_REG*)_TMR_VALUE_REGISTER_16BIT_LOW_VREG( index );

    _SFR_WRITE( &pTmrModule->timerX2, 0 );
    _SFR_WRITE( _TMR_VALUE_REGISTER_16BIT_LOW_VREG( index ), 0 );
}


//******************************************************************************
/* Function :  TMR_ExistsCounter32Bit_In16BitRegister

  Summary:
    Implements In16BitRegister variant of PLIB_TMR_ExistsCounter32Bit

  Description:
    This template implements the In16BitRegister variant of the PLIB_TMR_ExistsCounter32Bit function.
*/

#define PLIB_TMR_ExistsCounter32Bit PLIB_TMR_ExistsCounter32Bit
PLIB_TEMPLATE bool TMR_ExistsCounter32Bit_In16BitRegister( TMR_MODULE_ID index )
{
    return true;
}


#endif /*_TMR_COUNTER32BIT_IN16BITREGISTER_H*/

/******************************************************************************
 End of File
*/

