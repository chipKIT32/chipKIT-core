/*******************************************************************************
  PORTS Peripheral Library Template Implementation

  File Name:
    ports_SlewRateControl_Default.h

  Summary:
    PORTS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : SlewRateControl
    and its Variant : Default
    For following APIs :
        PLIB_PORTS_ChannelSlewRateSelect
        PLIB_PORTS_PinSlewRateGet
        PLIB_PORTS_ExistsSlewRateControl

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

#ifndef _PORTS_SLEWRATECONTROL_DEFAULT_H
#define _PORTS_SLEWRATECONTROL_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _PORTS_SLEW_RATE_CONTROL_0B_VREG(index)
    _PORTS_SLEW_RATE_CONTROL_1B_VREG(index)

  MASKs: 
    _PORTS_SLEW_RATE_CONTROL_0B_MASK(index)
    _PORTS_SLEW_RATE_CONTROL_1B_MASK(index)

  POSs: 
    _PORTS_SLEW_RATE_CONTROL_0B_POS(index)
    _PORTS_SLEW_RATE_CONTROL_1B_POS(index)

  LENs: 
    _PORTS_SLEW_RATE_CONTROL_0B_LEN(index)
    _PORTS_SLEW_RATE_CONTROL_1B_LEN(index)

*/


//******************************************************************************
/* Function :  PORTS_ChannelSlewRateSelect_Default

  Summary:
    Implements Default variant of PLIB_PORTS_ChannelSlewRateSelect 

  Description:
    This template implements the Default variant of the PLIB_PORTS_ChannelSlewRateSelect function.
*/

PLIB_TEMPLATE void PORTS_ChannelSlewRateSelect_Default( PORTS_MODULE_ID  index , PORTS_CHANNEL channel , PORTS_DATA_MASK   channelMask , PORTS_PIN_SLEW_RATE slewRate )
{
    switch(slewRate)
    {
        case 0x03:  _SFR_SET(_PORTS_SLEW_RATE_CONTROL_0B_VREG(index) + ((channel-1) * 0x40), channelMask );
                    _SFR_SET(_PORTS_SLEW_RATE_CONTROL_1B_VREG(index) + ((channel-1) * 0x40), channelMask );
                    break;
                    
        case 0x02:  _SFR_CLEAR(_PORTS_SLEW_RATE_CONTROL_0B_VREG(index) + ((channel-1) * 0x40), channelMask );
                    _SFR_SET(_PORTS_SLEW_RATE_CONTROL_1B_VREG(index) + ((channel-1) * 0x40), channelMask );
                    break;
                    
        case 0x01:  _SFR_SET(_PORTS_SLEW_RATE_CONTROL_0B_VREG(index) + ((channel-1) * 0x40), channelMask );
                    _SFR_CLEAR(_PORTS_SLEW_RATE_CONTROL_1B_VREG(index) + ((channel-1) * 0x40), channelMask );
                    break;
                    
        case 0x00:  _SFR_CLEAR(_PORTS_SLEW_RATE_CONTROL_0B_VREG(index) + ((channel-1) * 0x40), channelMask );
                    _SFR_CLEAR(_PORTS_SLEW_RATE_CONTROL_1B_VREG(index) + ((channel-1) * 0x40), channelMask );
                    break;
                    
        default:    break;
    }
}


//******************************************************************************
/* Function :  PORTS_PinSlewRateGet_Default

  Summary:
    Implements Default variant of PLIB_PORTS_PinSlewRateGet 

  Description:
    This template implements the Default variant of the PLIB_PORTS_PinSlewRateGet function.
*/

PLIB_TEMPLATE PORTS_PIN_SLEW_RATE PORTS_PinSlewRateGet_Default( PORTS_MODULE_ID  index , PORTS_CHANNEL channel , PORTS_BIT_POS bitPos )
{
    unsigned int srcon0Bit, srcon1Bit;
    srcon0Bit = (unsigned int) _SFR_BIT_READ(_PORTS_SLEW_RATE_CONTROL_0B_VREG(index) + ((channel-1) * 0x40), bitPos);
    srcon1Bit = (unsigned int) _SFR_BIT_READ(_PORTS_SLEW_RATE_CONTROL_1B_VREG(index) + ((channel-1) * 0x40), bitPos);
    
    return (PORTS_PIN_SLEW_RATE)((srcon1Bit << 1)+(srcon0Bit));
}


//******************************************************************************
/* Function :  PORTS_ExistsSlewRateControl_Default

  Summary:
    Implements Default variant of PLIB_PORTS_ExistsSlewRateControl

  Description:
    This template implements the Default variant of the PLIB_PORTS_ExistsSlewRateControl function.
*/

#define PLIB_PORTS_ExistsSlewRateControl PLIB_PORTS_ExistsSlewRateControl
PLIB_TEMPLATE bool PORTS_ExistsSlewRateControl_Default( PORTS_MODULE_ID index )
{
    return true;
}


#endif /*_PORTS_SLEWRATECONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

