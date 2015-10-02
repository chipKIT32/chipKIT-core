/*******************************************************************************
  TMR Peripheral Library Template Implementation

  File Name:
    tmr_CounterAsyncWriteControl_Default.h

  Summary:
    TMR PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : CounterAsyncWriteControl
    and its Variant : Default
    For following APIs :
        PLIB_TMR_CounterAsyncWriteEnable
        PLIB_TMR_CounterAsyncWriteDisable
        PLIB_TMR_ExistsCounterAsyncWriteControl

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

#ifndef _TMR_COUNTERASYNCWRITECONTROL_DEFAULT_H
#define _TMR_COUNTERASYNCWRITECONTROL_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are

  VREGs:
    _TMR_ASYNC_TIMER_WRITE_VREG(index)

  MASKs:
    _TMR_ASYNC_TIMER_WRITE_MASK(index)

  POSs:
    _TMR_ASYNC_TIMER_WRITE_POS(index)

  LENs:
    _TMR_ASYNC_TIMER_WRITE_LEN(index)

*/


//******************************************************************************
/* Function :  TMR_CounterAsyncWriteEnable_Default

  Summary:
    Implements Default variant of PLIB_TMR_CounterAsyncWriteEnable

  Description:
    This template implements the Default variant of the PLIB_TMR_CounterAsyncWriteEnable function.
*/

PLIB_TEMPLATE void TMR_CounterAsyncWriteEnable_Default( TMR_MODULE_ID index )
{
    _SFR_BIT_CLEAR(_TMR_ASYNC_TIMER_WRITE_VREG(index),
                 _TMR_ASYNC_TIMER_WRITE_POS(index) );
}


//******************************************************************************
/* Function :  TMR_CounterAsyncWriteDisable_Default

  Summary:
    Implements Default variant of PLIB_TMR_CounterAsyncWriteDisable

  Description:
    This template implements the Default variant of the PLIB_TMR_CounterAsyncWriteDisable function.
*/

PLIB_TEMPLATE void TMR_CounterAsyncWriteDisable_Default( TMR_MODULE_ID index )
{
    _SFR_BIT_SET(_TMR_ASYNC_TIMER_WRITE_VREG(index),
                   _TMR_ASYNC_TIMER_WRITE_POS(index) );
}


//******************************************************************************
/* Function :  TMR_ExistsCounterAsyncWriteControl_Default

  Summary:
    Implements Default variant of PLIB_TMR_ExistsCounterAsyncWriteControl

  Description:
    This template implements the Default variant of the PLIB_TMR_ExistsCounterAsyncWriteControl function.
*/

#define PLIB_TMR_ExistsCounterAsyncWriteControl PLIB_TMR_ExistsCounterAsyncWriteControl
PLIB_TEMPLATE bool TMR_ExistsCounterAsyncWriteControl_Default( TMR_MODULE_ID index )
{
    return true;
}


#endif /*_TMR_COUNTERASYNCWRITECONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

