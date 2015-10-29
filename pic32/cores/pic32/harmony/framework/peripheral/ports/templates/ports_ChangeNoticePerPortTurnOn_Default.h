/*******************************************************************************
  PORTS Peripheral Library Template Implementation

  File Name:
    ports_ChangeNoticePerPortTurnOn_Default.h

  Summary:
    PORTS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ChangeNoticePerPortTurnOn
    and its Variant : Default
    For following APIs :
        PLIB_PORTS_ChangeNoticePerPortTurnOn
        PLIB_PORTS_ChangeNoticePerPortTurnOff
        PLIB_PORTS_ExistsChangeNoticePerPortTurnOn

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

#ifndef _PORTS_CHANGENOTICEPERPORTTURNON_DEFAULT_H
#define _PORTS_CHANGENOTICEPERPORTTURNON_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _PORTS_PIN_CHANGE_NOTICE_TURN_ON_B_VREG(index)

  MASKs: 
    _PORTS_PIN_CHANGE_NOTICE_TURN_ON_B_MASK(index)

  POSs: 
    _PORTS_PIN_CHANGE_NOTICE_TURN_ON_B_POS(index)

  LENs: 
    _PORTS_PIN_CHANGE_NOTICE_TURN_ON_B_LEN(index)

*/


//******************************************************************************
/* Function :  PORTS_ChangeNoticePerPortTurnOn_Default

  Summary:
    Implements Default variant of PLIB_PORTS_ChangeNoticePerPortTurnOn 

  Description:
    This template implements the Default variant of the PLIB_PORTS_ChangeNoticePerPortTurnOn function.
*/

PLIB_TEMPLATE void PORTS_ChangeNoticePerPortTurnOn_Default( PORTS_MODULE_ID  index , PORTS_CHANNEL channel )
{
    _SFR_BIT_SET(_PORTS_PIN_CHANGE_NOTICE_TURN_ON_B_VREG(index) + ((channel-1) * 0x40),
						   _PORTS_PIN_CHANGE_NOTICE_TURN_ON_B_POS(index) );
}


//******************************************************************************
/* Function :  PORTS_ChangeNoticePerPortTurnOff_Default

  Summary:
    Implements Default variant of PLIB_PORTS_ChangeNoticePerPortTurnOff 

  Description:
    This template implements the Default variant of the PLIB_PORTS_ChangeNoticePerPortTurnOff function.
*/

PLIB_TEMPLATE void PORTS_ChangeNoticePerPortTurnOff_Default( PORTS_MODULE_ID  index , PORTS_CHANNEL channel )
{
    _SFR_BIT_CLEAR(_PORTS_PIN_CHANGE_NOTICE_TURN_ON_B_VREG(index) + ((channel-1) * 0x40),
						   _PORTS_PIN_CHANGE_NOTICE_TURN_ON_B_POS(index) );
}


//******************************************************************************
/* Function :  PORTS_ExistsChangeNoticePerPortTurnOn_Default

  Summary:
    Implements Default variant of PLIB_PORTS_ExistsChangeNoticePerPortTurnOn

  Description:
    This template implements the Default variant of the PLIB_PORTS_ExistsChangeNoticePerPortTurnOn function.
*/

#define PLIB_PORTS_ExistsChangeNoticePerPortTurnOn PLIB_PORTS_ExistsChangeNoticePerPortTurnOn
PLIB_TEMPLATE bool PORTS_ExistsChangeNoticePerPortTurnOn_Default( PORTS_MODULE_ID index )
{
    return true;
}


#endif /*_PORTS_CHANGENOTICEPERPORTTURNON_DEFAULT_H*/

/******************************************************************************
 End of File
*/

