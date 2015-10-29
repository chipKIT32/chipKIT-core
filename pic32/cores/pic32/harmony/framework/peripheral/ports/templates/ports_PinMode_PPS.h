/*******************************************************************************
  PORTS Peripheral Library Template Implementation

  File Name:
    ports_PinMode_PPS.h

  Summary:
    PORTS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : PinMode
    and its Variant : PPS
    For following APIs :
        PLIB_PORTS_PinModeSelect
        PLIB_PORTS_ExistsPinMode

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

#ifndef _PORTS_PINMODE_PPS_H
#define _PORTS_PINMODE_PPS_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _PORTS_PIN_MODE_B_VREG(index)

  MASKs: 
    _PORTS_PIN_MODE_B_MASK(index)

  POSs: 
    _PORTS_PIN_MODE_B_POS(index)

  LENs: 
    _PORTS_PIN_MODE_B_LEN(index)

*/


//******************************************************************************
/* Function :  PORTS_PinModeSelect_PPS

  Summary:
    Implements PPS variant of PLIB_PORTS_PinModeSelect 

  Description:
    This template implements the PPS variant of the PLIB_PORTS_PinModeSelect function.
*/

PLIB_TEMPLATE void PORTS_PinModeSelect_PPS( PORTS_MODULE_ID  index , PORTS_ANALOG_PIN pin , PORTS_PIN_MODE   mode )
{

uint8_t channel, bitPos;

    channel = pin/16;
    bitPos = pin % 16;

    if ( mode == PORTS_PIN_MODE_ANALOG )
	{
		_SFR_BIT_SET(_PORTS_PIN_MODE_B_VREG(index) + ((channel-1) * 0x40),
						   bitPos );	
	}
	else
	{
		_SFR_BIT_CLEAR(_PORTS_PIN_MODE_B_VREG(index) + ((channel-1) * 0x40),
						   bitPos );
	}
}

//******************************************************************************
/* Function :  PORTS_ExistsPinMode_PPS

  Summary:
    Implements PPS variant of PLIB_PORTS_ExistsPinMode

  Description:
    This template implements the PPS variant of the PLIB_PORTS_ExistsPinMode function.
*/

#define PLIB_PORTS_ExistsPinMode PLIB_PORTS_ExistsPinMode
PLIB_TEMPLATE bool PORTS_ExistsPinMode_PPS( PORTS_MODULE_ID index )
{
    return true;
}


#endif /*_PORTS_PINMODE_PPS_H*/

/******************************************************************************
 End of File
*/

