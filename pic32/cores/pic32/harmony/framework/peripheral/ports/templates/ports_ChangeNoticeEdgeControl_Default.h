/*******************************************************************************
  PORTS Peripheral Library Template Implementation

  File Name:
    ports_ChangeNoticeEdgeControl_Default.h

  Summary:
    PORTS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ChangeNoticeEdgeControl
    and its Variant : Default
    For following APIs :
        PLIB_PORTS_ChannelChangeNoticeEdgeEnable
        PLIB_PORTS_ChannelChangeNoticeEdgeDisable
        PLIB_PORTS_PinChangeNoticeEdgeIsEnabled
        PLIB_PORTS_ExistsChangeNoticeEdgeControl

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _PORTS_CHANGENOTICEEDGECONTROL_DEFAULT_H
#define _PORTS_CHANGENOTICEEDGECONTROL_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _PORTS_CN_NEGATIVE_EDGE_CONTROL_B_VREG(index)
    _PORTS_PIN_CHANGE_NOTICE_B_VREG(index)

  MASKs: 
    _PORTS_CN_NEGATIVE_EDGE_CONTROL_B_MASK(index)
    _PORTS_PIN_CHANGE_NOTICE_B_MASK(index)

  POSs: 
    _PORTS_CN_NEGATIVE_EDGE_CONTROL_B_POS(index)
    _PORTS_PIN_CHANGE_NOTICE_B_POS(index)

  LENs: 
    _PORTS_CN_NEGATIVE_EDGE_CONTROL_B_LEN(index)
    _PORTS_PIN_CHANGE_NOTICE_B_LEN(index)

*/


//******************************************************************************
/* Function :  PORTS_ChannelChangeNoticeEdgeEnable_Default

  Summary:
    Implements Default variant of PLIB_PORTS_ChannelChangeNoticeEdgeEnable 

  Description:
    This template implements the Default variant of the PLIB_PORTS_ChannelChangeNoticeEdgeEnable function.
*/

PLIB_TEMPLATE void PORTS_ChannelChangeNoticeEdgeEnable_Default( PORTS_MODULE_ID  index , PORTS_CHANNEL channel , PORTS_DATA_MASK   edgeRisingMask , PORTS_DATA_MASK   edgeFallingMask )
{
    _SFR_SET(_PORTS_PIN_CHANGE_NOTICE_B_VREG(index) + ((channel-1) * 0x40), edgeRisingMask );
    _SFR_SET(_PORTS_CN_NEGATIVE_EDGE_CONTROL_B_VREG(index) + ((channel-1) * 0x40), edgeFallingMask );
}


//******************************************************************************
/* Function :  PORTS_ChannelChangeNoticeEdgeDisable_Default

  Summary:
    Implements Default variant of PLIB_PORTS_ChannelChangeNoticeEdgeDisable 

  Description:
    This template implements the Default variant of the PLIB_PORTS_ChannelChangeNoticeEdgeDisable function.
*/

PLIB_TEMPLATE void PORTS_ChannelChangeNoticeEdgeDisable_Default( PORTS_MODULE_ID  index , PORTS_CHANNEL channel , PORTS_DATA_MASK   edgeRisingMask , PORTS_DATA_MASK   edgeFallingMask )
{
    _SFR_CLEAR(_PORTS_PIN_CHANGE_NOTICE_B_VREG(index) + ((channel-1) * 0x40), edgeRisingMask );
    _SFR_CLEAR(_PORTS_CN_NEGATIVE_EDGE_CONTROL_B_VREG(index) + ((channel-1) * 0x40), edgeFallingMask );
}


//******************************************************************************
/* Function :  PORTS_PinChangeNoticeEdgeIsEnabled_Default

  Summary:
    Implements Default variant of PLIB_PORTS_PinChangeNoticeEdgeIsEnabled 

  Description:
    This template implements the Default variant of the PLIB_PORTS_PinChangeNoticeEdgeIsEnabled function.
*/

PLIB_TEMPLATE bool PORTS_PinChangeNoticeEdgeIsEnabled_Default( PORTS_MODULE_ID  index , PORTS_CHANNEL channel , PORTS_BIT_POS bitPos , PORTS_CHANGE_NOTICE_EDGE  cnEdgeType )
{
    return _SFR_BIT_READ(_PORTS_PIN_CHANGE_NOTICE_B_VREG(index) + ((channel-1) * 0x40) + (8 * cnEdgeType), bitPos);
}


//******************************************************************************
/* Function :  PORTS_ExistsChangeNoticeEdgeControl_Default

  Summary:
    Implements Default variant of PLIB_PORTS_ExistsChangeNoticeEdgeControl

  Description:
    This template implements the Default variant of the PLIB_PORTS_ExistsChangeNoticeEdgeControl function.
*/

#define PLIB_PORTS_ExistsChangeNoticeEdgeControl PLIB_PORTS_ExistsChangeNoticeEdgeControl
PLIB_TEMPLATE bool PORTS_ExistsChangeNoticeEdgeControl_Default( PORTS_MODULE_ID index )
{
    return true;
}


#endif /*_PORTS_CHANGENOTICEEDGECONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

