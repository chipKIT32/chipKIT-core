/*******************************************************************************
  PORTS Peripheral Library Template Implementation

  File Name:
    ports_ChannelChangeNoticeMethod_Default.h

  Summary:
    PORTS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ChannelChangeNoticeMethod
    and its Variant : Default
    For following APIs :
        PLIB_PORTS_ChannelChangeNoticeMethodSelect
        PLIB_PORTS_ChannelChangeNoticeMethodGet
        PLIB_PORTS_ExistsChannelChangeNoticeMethod

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

#ifndef _PORTS_CHANNELCHANGENOTICEMETHOD_DEFAULT_H
#define _PORTS_CHANNELCHANGENOTICEMETHOD_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _PORTS_PIN_CHANGE_NOTICE_STYLE_B_VREG(index)

  MASKs: 
    _PORTS_PIN_CHANGE_NOTICE_STYLE_B_MASK(index)

  POSs: 
    _PORTS_PIN_CHANGE_NOTICE_STYLE_B_POS(index)

  LENs: 
    _PORTS_PIN_CHANGE_NOTICE_STYLE_B_LEN(index)

*/


//******************************************************************************
/* Function :  PORTS_ChannelChangeNoticeMethodSelect_Default

  Summary:
    Implements Default variant of PLIB_PORTS_ChannelChangeNoticeMethodSelect 

  Description:
    This template implements the Default variant of the PLIB_PORTS_ChannelChangeNoticeMethodSelect function.
*/

PLIB_TEMPLATE void PORTS_ChannelChangeNoticeMethodSelect_Default( PORTS_MODULE_ID  index , PORTS_CHANNEL channel , PORTS_CHANGE_NOTICE_METHOD changeNoticeMethod )
{
                         
    _SFR_BIT_WRITE(_PORTS_PIN_CHANGE_NOTICE_STYLE_B_VREG(index),
                       _PORTS_PIN_CHANGE_NOTICE_STYLE_B_POS(index),
                       changeNoticeMethod);
}


//******************************************************************************
/* Function :  PORTS_ChannelChangeNoticeMethodGet_Default

  Summary:
    Implements Default variant of PLIB_PORTS_ChannelChangeNoticeMethodGet 

  Description:
    This template implements the Default variant of the PLIB_PORTS_ChannelChangeNoticeMethodGet function.
*/

PLIB_TEMPLATE PORTS_CHANGE_NOTICE_METHOD PORTS_ChannelChangeNoticeMethodGet_Default( PORTS_MODULE_ID  index , PORTS_CHANNEL channel )
{
    return (PORTS_CHANGE_NOTICE_METHOD)_SFR_BIT_READ(_PORTS_PIN_CHANGE_NOTICE_STYLE_B_VREG(index),
                             _PORTS_PIN_CHANGE_NOTICE_STYLE_B_POS(index) );
}


//******************************************************************************
/* Function :  PORTS_ExistsChannelChangeNoticeMethod_Default

  Summary:
    Implements Default variant of PLIB_PORTS_ExistsChannelChangeNoticeMethod

  Description:
    This template implements the Default variant of the PLIB_PORTS_ExistsChannelChangeNoticeMethod function.
*/

#define PLIB_PORTS_ExistsChannelChangeNoticeMethod PLIB_PORTS_ExistsChannelChangeNoticeMethod
PLIB_TEMPLATE bool PORTS_ExistsChannelChangeNoticeMethod_Default( PORTS_MODULE_ID index )
{
    return true;
}


#endif /*_PORTS_CHANNELCHANGENOTICEMETHOD_DEFAULT_H*/

/******************************************************************************
 End of File
*/

