/*******************************************************************************
  USBHS Peripheral Library Template Implementation

  File Name:
    usbhs_HighSpeedSupport_Default.h

  Summary:
    USBHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : HighSpeedSupport
    and its Variant : Default
    For following APIs :
        PLIB_USBHS_HighSpeedEnable
        PLIB_USBHS_HighSpeedDisable
        PLIB_USBHS_HighSpeedIsConnected
        PLIB_USBHS_FullOrHighSpeedIsConnected
        PLIB_USBHS_ExistsHighSpeedSupport
        PLIB_USBHS_DMAErrorGet
        PLIB_USBHS_DMAInterruptGet
        PLIB_USBHS_DMAOperationEnable
        PLIB_USBHS_LoadEPInIndex
        PLIB_USBHS_GetEP0FIFOAddress
        PLIB_USBHS_GetEP0CSRAddress
        PLIB_USBHS_GetReceiveDataCount
        PLIB_USBHS_TestModeEnter
        PLIB_USBHS_TestModeExit

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

#ifndef _USBHS_HIGHSPEEDSUPPORT_DEFAULT_H
#define _USBHS_HIGHSPEEDSUPPORT_DEFAULT_H

#include <sys/kmem.h>

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
/* Function :  USBHS_HighSpeedEnable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_HighSpeedEnable 

  Description:
    This template implements the Default variant of the PLIB_USBHS_HighSpeedEnable function.
*/

PLIB_TEMPLATE void USBHS_HighSpeedEnable_Default( USBHS_MODULE_ID index )
{
    /* This function enables high speed support */

    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);

    *(usbBaseAddress + 0x01) |= 0x20;
}


//******************************************************************************
/* Function :  USBHS_HighSpeedDisable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_HighSpeedDisable 

  Description:
    This template implements the Default variant of the PLIB_USBHS_HighSpeedDisable function.
*/

PLIB_TEMPLATE void USBHS_HighSpeedDisable_Default( USBHS_MODULE_ID index )
{
    /* This function disables high speed support */

    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);

    *(usbBaseAddress + 0x01) &= 0xDF;
}


//******************************************************************************
/* Function :  USBHS_HighSpeedIsConnected_Default

  Summary:
    Implements Default variant of PLIB_USBHS_HighSpeedIsConnected 

  Description:
    This template implements the Default variant of the PLIB_USBHS_HighSpeedIsConnected function.
*/

PLIB_TEMPLATE bool USBHS_HighSpeedIsConnected_Default( USBHS_MODULE_ID index )
{
    /* Returns true if the connected device is high speed
     * else returns false. */

    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);

    if((*(usbBaseAddress + 0x1)) & 0x10)
    {
        return true;
    }
    
    return false;
}

//******************************************************************************
/* Function :  USBHS_DMAErrorGet_Default

  Summary:
    Implements Default variant of PLIB_USBHS_DMAErrorGet 

  Description:
    This template implements the Default variant of the PLIB_USBHS_DMAErrorGet function.
*/

PLIB_TEMPLATE bool USBHS_DMAErrorGet_Default( USBHS_MODULE_ID index, uint8_t dmaChannel )
{
    /* Returns true if the connected device is high speed
     * else returns false. */

    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
    volatile uint8_t *dmaControlRegAddress = NULL;
    bool returnValue = false;
	
    dmaControlRegAddress = usbBaseAddress + (0x204) +
                            ((dmaChannel - 1) * 0x10);
    dmaControlRegAddress++;
    if((*dmaControlRegAddress) & 0x01)
    {
        /* DMA error set */
        returnValue = true;
        /* DMA error clear */
        *dmaControlRegAddress = *dmaControlRegAddress & 0xFE;
    }
    /* true returned when error set */
    return returnValue;
}



//******************************************************************************
/* Function :  USBHS_DMAInterruptGet_Default

  Summary:
    Implements Default variant of PLIB_USBHS_DMAInterruptGet 

  Description:
    This template implements the Default variant of the PLIB_USBHS_DMAInterruptGet function.
*/

PLIB_TEMPLATE uint8_t USBHS_DMAInterruptGet_Default( USBHS_MODULE_ID index)
{
    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
    volatile uint8_t * dmaInterruptRegAddress = NULL;
    dmaInterruptRegAddress = usbBaseAddress + (0x200);
    return (*dmaInterruptRegAddress);

}


//******************************************************************************
/* Function :  USBHS_DMAOperationEnable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_DMAOperationEnable

  Description:
    This template implements the Default variant of the PLIB_USBHS_DMAOperationEnable function.
*/

PLIB_TEMPLATE void USBHS_DMAOperationEnable_Default
(
    USBHS_MODULE_ID index,
    uint8_t endpoint,
    uint8_t dmaChannel,
    void * address,
    uint32_t count,
    bool direction
)
{
    /* Returns true if the connected device is high speed
     * else returns false. */

    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);

    volatile uint32_t * dmaAddrRegAddress = (volatile uint32_t *)(usbBaseAddress + (0x208) +
                        ((dmaChannel - 1) * 0x10));
    volatile uint32_t * dmaCountRegAddress = (volatile uint32_t *)(usbBaseAddress + (0x20C) +
                        ((dmaChannel - 1) * 0x10));
    volatile uint16_t * dmaControlRegAddress = (volatile uint16_t *)(usbBaseAddress + (0x204) +
                            ((dmaChannel - 1) * 0x10));

    /* DMA ADDR register program */
    *dmaAddrRegAddress = KVA_TO_PA(address);

    /* DMA COUNT register program */
    *dmaCountRegAddress = (uint32_t)count;

    /* Program DMA CTRL register */
    if(direction == 0)
    {
        /* For TX */
        *dmaControlRegAddress = (uint16_t)(0x0600 | (endpoint << 4)  | 0x0B);
    }
    else
    {
        /* For RX */
        *dmaControlRegAddress = (uint16_t)(0x0600 | (endpoint << 4)  | 0x09);
    }
}


//******************************************************************************
/* Function :  USBHS_LoadEPInIndex_Default

  Summary:
    Implements Default variant of PLIB_USBHS_LoadEPInIndex 

  Description:
    This template implements the Default variant of the PLIB_USBHS_LoadEPInIndex function.
*/

PLIB_TEMPLATE void USBHS_LoadEPInIndex_Default(USBHS_MODULE_ID index, uint8_t endpoint)
{
    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
	*(usbBaseAddress + 0xE) = endpoint;
}


//******************************************************************************
/* Function :  USBHS_GetEP0FIFOAddress_Default

  Summary:
    Implements Default variant of PLIB_USBHS_GetEP0FIFOAddress 

  Description:
    This template implements the Default variant of the PLIB_USBHS_GetEP0FIFOAddress function.
*/

PLIB_TEMPLATE uint8_t * USBHS_GetEP0FIFOAddress_Default(USBHS_MODULE_ID index)
{
    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
	return ((uint8_t *)(usbBaseAddress + 0x20));
}


//******************************************************************************
/* Function :  USBHS_GetEP0CSRAddress_Default

  Summary:
    Implements Default variant of PLIB_USBHS_GetEP0CSRAddress 

  Description:
    This template implements the Default variant of the PLIB_USBHS_GetEP0CSRAddress function.
*/

PLIB_TEMPLATE uint8_t * USBHS_GetEP0CSRAddress_Default(USBHS_MODULE_ID index)
{
    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
	return ((uint8_t *)(usbBaseAddress + 0x12));
}


//******************************************************************************
/* Function :  USBHS_GetReceiveDataCount_Default

  Summary:
    Implements Default variant of PLIB_USBHS_GetReceiveDataCount 

  Description:
    This template implements the Default variant of the PLIB_USBHS_GetReceiveDataCount function.
*/

PLIB_TEMPLATE uint32_t USBHS_GetReceiveDataCount_Default(USBHS_MODULE_ID index, uint8_t endpoint)
{
    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
	/* Load the endpoint in INDEX register */
	*(usbBaseAddress + 0xE) = endpoint;
	return ((uint32_t)*((uint16_t *)(usbBaseAddress + 0x18)));
}


//******************************************************************************
/* Function :  USBHS_FullOrHighSpeedIsConnected_Default

  Summary:
    Implements Default variant of PLIB_USBHS_FullOrHighSpeedIsConnected 

  Description:
    This template implements the Default variant of the PLIB_USBHS_FullOrHighSpeedIsConnected function.
*/

PLIB_TEMPLATE bool USBHS_FullOrHighSpeedIsConnected_Default( USBHS_MODULE_ID index )
{
    /* Function returns true is high or full speed device is connected.
     * Return false if low speed or no device is connected */

    volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);

    if((*(usbBaseAddress + 0x60)) & 0x40)
    {
        /* Connected device is either full or high speed */
        return true;
    }

    if((*(usbBaseAddress + 0x60)) & 0x20)
    {
        /* Connected device is low speed */
        return false;
    }

    /* Nothing is connected ? */

    return false;
}


//******************************************************************************
/* Function :  USBHS_ExistsHighSpeedSupport_Default

  Summary:
    Implements Default variant of PLIB_USBHS_ExistsHighSpeedSupport

  Description:
    This template implements the Default variant of the PLIB_USBHS_ExistsHighSpeedSupport function.
*/

#define PLIB_USBHS_ExistsHighSpeedSupport PLIB_USBHS_ExistsHighSpeedSupport
PLIB_TEMPLATE bool USBHS_ExistsHighSpeedSupport_Default( USBHS_MODULE_ID index )
{
    return true;
}

//******************************************************************************
/* Function :  USBHS_TestModeEnter_Default

  Summary:
    Implements Default variant of PLIB_USBHS_TestModeEnter 

  Description:
    This template implements the Default variant of the PLIB_USBHS_TestModeEnter function.
*/

PLIB_TEMPLATE bool USBHS_TestModeEnter_Default( USBHS_MODULE_ID index , uint8_t testMode )
{
	volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);
	
	/* Only 1 bit of D0-D6 should be set at any time */
	if( (*(usbBaseAddress + 0xF) == 0x00) || (*(usbBaseAddress + 0xF) == 0x80) )
	{
	    /* Proceed */
	}
	else
	{
	    return false;
	}
	if( (1 == testMode) || (2 == testMode) )
	{
	    *(usbBaseAddress + 0xF) = *(usbBaseAddress + 0xF) | (testMode << 1);
	}
	else if( 3 == testMode )
	{
	    *(usbBaseAddress + 0xF) = *(usbBaseAddress + 0xF) | 0x01;
	}
	else if( 4 == testMode )
	{
	    *(usbBaseAddress + 0xF) = *(usbBaseAddress + 0xF) | 0x08;
	}
	else
	{
	    return false;
	}
	return true;
}


//******************************************************************************
/* Function :  USBHS_TestModeExit_Default

  Summary:
    Implements Default variant of PLIB_USBHS_TestModeExit 

  Description:
    This template implements the Default variant of the PLIB_USBHS_TestModeExit function.
*/

PLIB_TEMPLATE bool USBHS_TestModeExit_Default( USBHS_MODULE_ID index , uint8_t testMode )
{
	volatile uint8_t * usbBaseAddress = (uint8_t *)_USBHS_BASE_ADDRESS_VREG(index);

	if( (1 == testMode) || (2 == testMode) )
	{
	    *(usbBaseAddress + 0xF) = *(usbBaseAddress + 0xF) & ~(testMode << 1);
	}
	else if( 3 == testMode )
	{
	    *(usbBaseAddress + 0xF) = *(usbBaseAddress + 0xF) & 0xFE;
	}
	else if( 4 == testMode )
	{
	    *(usbBaseAddress + 0xF) = *(usbBaseAddress + 0xF) & 0xF7;
	}
	else
	{
	    return false;
	}
	return true;
}


#endif /*_USBHS_HIGHSPEEDSUPPORT_DEFAULT_H*/

/******************************************************************************
 End of File
*/

