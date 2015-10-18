/*******************************************************************************
  USBHS Peripheral Library Template Implementation

  File Name:
    usbhs_ModuleControl_Default.h

  Summary:
    USBHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ModuleControl
    and its Variant : Default
    For following APIs :
        PLIB_USBHS_ResumeEnable
        PLIB_USBHS_ResumeDisable
        PLIB_USBHS_SuspendEnable
        PLIB_USBHS_SuspendDisable
        PLIB_USBHS_VBUSLevelGet
        PLIB_USBHS_HostModeIsEnabled
        PLIB_USBHS_SessionEnable
        PLIB_USBHS_SessionDisable
        PLIB_USBHS_ExistsModuleControl

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

#ifndef _USBHS_MODULECONTROL_DEFAULT_H
#define _USBHS_MODULECONTROL_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _USBHS_BASE_ADDRESS_VREG(index)

  MASKs: 
    _USBHS_BASE_ADDRESS_MASK(index)

  POSs: 
    _USBHS_BASE_ADDRESS_POS(index)

  LENs: 
    _USBHS_BASE_ADDRESS_LEN(index)

*/


//******************************************************************************
/* Function :  USBHS_ResumeEnable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_ResumeEnable 

  Description:
    This template implements the Default variant of the PLIB_USBHS_ResumeEnable function.
*/

PLIB_TEMPLATE void USBHS_ResumeEnable_Default( USBHS_MODULE_ID index )
{
    /* Function enables resume signalling */
    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
    *(usbBaseAddress + 0x1) |= 0x4;
}


//******************************************************************************
/* Function :  USBHS_ResumeDisable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_ResumeDisable 

  Description:
    This template implements the Default variant of the PLIB_USBHS_ResumeDisable function.
*/

PLIB_TEMPLATE void USBHS_ResumeDisable_Default( USBHS_MODULE_ID index )
{
    /* Function disables resume signalling */
    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
    *(usbBaseAddress + 0x1) &= 0xFB;
}


//******************************************************************************
/* Function :  USBHS_SuspendEnable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_SuspendEnable 

  Description:
    This template implements the Default variant of the PLIB_USBHS_SuspendEnable function.
*/

PLIB_TEMPLATE void USBHS_SuspendEnable_Default( USBHS_MODULE_ID index )
{
    /* Function enables suspend mode */
    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
    *(usbBaseAddress + 0x1) |= 0x2;
}


//******************************************************************************
/* Function :  USBHS_SuspendDisable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_SuspendDisable 

  Description:
    This template implements the Default variant of the PLIB_USBHS_SuspendDisable function.
*/

PLIB_TEMPLATE void USBHS_SuspendDisable_Default( USBHS_MODULE_ID index )
{
    /* Function disables suspend mode */
    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
    *(usbBaseAddress + 0x1) &= 0xFD;
}


//******************************************************************************
/* Function :  USBHS_VBUSLevelGet_Default

  Summary:
    Implements Default variant of PLIB_USBHS_VBUSLevelGet 

  Description:
    This template implements the Default variant of the PLIB_USBHS_VBUSLevelGet function.
*/

PLIB_TEMPLATE USBHS_VBUS_LEVEL USBHS_VBUSLevelGet_Default( USBHS_MODULE_ID index )
{
    /* Function returns the current VBUS level */
    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
    return((USBHS_VBUS_LEVEL)(*(usbBaseAddress + 0x60) & 0x18));
}


//******************************************************************************
/* Function :  USBHS_HostModeIsEnabled_Default

  Summary:
    Implements Default variant of PLIB_USBHS_HostModeIsEnabled 

  Description:
    This template implements the Default variant of the PLIB_USBHS_HostModeIsEnabled function.
*/

PLIB_TEMPLATE bool USBHS_HostModeIsEnabled_Default( USBHS_MODULE_ID index )
{
    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
    if((*(usbBaseAddress + 0x60)) & 0x4)
    {
        /* This means the host mode is set */
        return true;
    }
    else
    {
        return false;
    }
}


//******************************************************************************
/* Function :  USBHS_SessionEnable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_SessionEnable 

  Description:
    This template implements the Default variant of the PLIB_USBHS_SessionEnable function.
*/

PLIB_TEMPLATE void USBHS_SessionEnable_Default( USBHS_MODULE_ID index )
{
    /* Sets the session bit */
    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
    *(usbBaseAddress + 0x60) |= 0x1;
}


//******************************************************************************
/* Function :  USBHS_SessionDisable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_SessionDisable 

  Description:
    This template implements the Default variant of the PLIB_USBHS_SessionDisable function.
*/

PLIB_TEMPLATE void USBHS_SessionDisable_Default( USBHS_MODULE_ID index )
{
    /* Clears the session bit */
    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
    *(usbBaseAddress + 0x60) &= 0xFE;
}

//******************************************************************************
/* Function :  USBHS_ResetEnable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_ResetEnable 

  Description:
    This template implements the Default variant of the PLIB_USBHS_ResetEnable function.
*/

PLIB_TEMPLATE void USBHS_ResetEnable_Default( USBHS_MODULE_ID index )
{
    /* Sets the reset bit */
    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
    *(usbBaseAddress + 0x1) |= 0x8;
}


//******************************************************************************
/* Function :  USBHS_ResetDisable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_ResetDisable 

  Description:
    This template implements the Default variant of the PLIB_USBHS_ResetDisable function.
*/

PLIB_TEMPLATE void USBHS_ResetDisable_Default( USBHS_MODULE_ID index )
{
    /* Clears the reset bit */
    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
    *(usbBaseAddress + 0x1) &= 0xF7;
}

//******************************************************************************
/* Function :  USBHS_DeviceAddressSet_Default

  Summary:
    Implements Default variant of PLIB_USBHS_DeviceAddressSet 

  Description:
    This template implements the Default variant of the PLIB_USBHS_DeviceAddressSet function.
*/

PLIB_TEMPLATE void USBHS_DeviceAddressSet_Default( USBHS_MODULE_ID index, uint8_t address )
{
    /* Clears the reset bit */
    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
    *(usbBaseAddress + 0x0) = address;
}

//******************************************************************************
/* Function :  USBHS_DeviceAttach_Default

  Summary:
    Implements Default variant of PLIB_USBHS_DeviceAttach 

  Description:
    This template implements the Default variant of the PLIB_USBHS_DeviceAttach function.
*/

PLIB_TEMPLATE void USBHS_DeviceAttach_Default( USBHS_MODULE_ID index, uint32_t speed )
{
    /* Attach the device at the specified speed */
    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
    
    if(speed == 2)
    {
        *(usbBaseAddress + 0x1) = 0x40;
    }
    else if(speed == 4)
    {
        *(usbBaseAddress + 0x1) = 0x60;
    }
}

//******************************************************************************
/* Function :  USBHS_DeviceDetach_Default

  Summary:
    Implements Default variant of PLIB_USBHS_DeviceDetach 

  Description:
    This template implements the Default variant of the PLIB_USBHS_DeviceDetach function.
*/

PLIB_TEMPLATE void USBHS_DeviceDetach_Default( USBHS_MODULE_ID index)
{
    /* Detach the device */
    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
    *(usbBaseAddress + 0x1) &= 0xBF;
}

//******************************************************************************
/* Function :  USBHS_ExistsModuleControl_Default

  Summary:
    Implements Default variant of PLIB_USBHS_ExistsModuleControl

  Description:
    This template implements the Default variant of the PLIB_USBHS_ExistsModuleControl function.
*/

#define PLIB_USBHS_ExistsModuleControl PLIB_USBHS_ExistsModuleControl
PLIB_TEMPLATE bool USBHS_ExistsModuleControl_Default( USBHS_MODULE_ID index )
{
    return true;
}


#endif /*_USBHS_MODULECONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

