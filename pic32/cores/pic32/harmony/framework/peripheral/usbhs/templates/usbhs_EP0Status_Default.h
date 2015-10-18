/*******************************************************************************
  USBHS Peripheral Library Template Implementation

  File Name:
    usbhs_EP0Status_Default.h

  Summary:
    USBHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : EP0Status
    and its Variant : Default
    For following APIs :
        PLIB_USBHS_EP0StatusGet
        PLIB_USBHS_EP0StatusClear
        PLIB_USBHS_EP0INHandshakeSend
        PLIB_USBHS_EP0INTokenSend
        PLIB_USBHS_EP0OUTHandshakeSend
        PLIB_USBHS_EP0INHandshakeClear
        PLIB_USBHS_ExistsEP0Status

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

#ifndef _USBHS_EP0STATUS_DEFAULT_H
#define _USBHS_EP0STATUS_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _USBHS_BASE_ADDRESS_VREG(index)
    _USBHS_ENDPOINT_BASE_ADDRESS_VREG(index)

  MASKs: 
    _USBHS_BASE_ADDRESS_MASK(index)
    _USBHS_ENDPOINT_BASE_ADDRESS_MASK(index)

  POSs: 
    _USBHS_BASE_ADDRESS_POS(index)
    _USBHS_ENDPOINT_BASE_ADDRESS_POS(index)

  LENs: 
    _USBHS_BASE_ADDRESS_LEN(index)
    _USBHS_ENDPOINT_BASE_ADDRESS_LEN(index)

*/


//******************************************************************************
/* Function :  USBHS_EP0StatusGet_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0StatusGet 

  Description:
    This template implements the Default variant of the PLIB_USBHS_EP0StatusGet function.
*/

PLIB_TEMPLATE uint8_t USBHS_EP0StatusGet_Default( USBHS_MODULE_ID index )
{
    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    return(*(ep0BaseAddress + 0x2));
}


//******************************************************************************
/* Function :  USBHS_EP0StatusClear_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0StatusClear 

  Description:
    This template implements the Default variant of the PLIB_USBHS_EP0StatusClear function.
*/

PLIB_TEMPLATE void USBHS_EP0StatusClear_Default( USBHS_MODULE_ID index , USBHS_EP0_ERROR error)
{
    /* This function clear the specified error */

    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);

    *(ep0BaseAddress + 0x2) &= (~(error));
}

//******************************************************************************
/* Function :  USBHS_EP0SentStallClear_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0SentStallClear 

  Description:
    This template implements the Default variant of the PLIB_USBHS_EP0SentStallClear function.
*/

PLIB_TEMPLATE void USBHS_EP0SentStallClear_Default( USBHS_MODULE_ID index)
{
    /* This function clears sent stall bit */

    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    *(ep0BaseAddress + 0x2) &= 0xFB;
}

//******************************************************************************
/* Function :  USBHS_EP0SetupEndServiced_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0SetupEndServiced 

  Description:
    This template implements the Default variant of the PLIB_USBHS_EP0SetupEndServiced function.
*/

PLIB_TEMPLATE void USBHS_EP0SetupEndServiced_Default( USBHS_MODULE_ID index)
{
    /* This function sets the serviced setup end bit
     * which then clears the setup end bit */

    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    *(ep0BaseAddress + 0x2) |= 0x80;
}

//******************************************************************************
/* Function :  USBHS_EP0RxPktRdyServiced_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0RxPktRdyServiced 

  Description:
    This template implements the Default variant of the PLIB_USBHS_EP0RxPktRdyServiced function.
*/

PLIB_TEMPLATE void USBHS_EP0RxPktRdyServiced_Default( USBHS_MODULE_ID index)
{
    /* This function sets the serviced setup end bit
     * which then clears the setup end bit */

    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    *(ep0BaseAddress + 0x2) = 0x40;
}

//******************************************************************************
/* Function :  USBHS_EP0RxPktRdyServicedDataEnd_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0RxPktRdyServicedDataEnd 

  Description:
    This template implements the Default variant of the PLIB_USBHS_EP0RxPktRdyServicedDataEnd function.
*/

PLIB_TEMPLATE void USBHS_EP0RxPktRdyServicedDataEnd_Default( USBHS_MODULE_ID index)
{
    /* This function sets the serviced setup end bit
     * which then clears the setup end bit */

    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    *(ep0BaseAddress + 0x2) = 0x48;
}

//******************************************************************************
/* Function :  USBHS_EP0TxPktRdyDataEnd_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0TxPktRdyDataEnd 

  Description:
    This template implements the Default variant of the PLIB_USBHS_EP0TxPktRdyDataEnd function.
*/

PLIB_TEMPLATE void USBHS_EP0TxPktRdyDataEnd_Default( USBHS_MODULE_ID index)
{
    /* This function sets the serviced setup end bit
     * which then clears the setup end bit */

    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    *(ep0BaseAddress + 0x2) = 0x0A;
}

//******************************************************************************
/* Function :  USBHS_EP0TxPktRdy_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0TxPktRdy 

  Description:
    This template implements the Default variant of the PLIB_USBHS_EP0TxPktRdy function.
*/

PLIB_TEMPLATE void USBHS_EP0TxPktRdy_Default( USBHS_MODULE_ID index)
{
    /* This function sets the serviced setup end bit
     * which then clears the setup end bit */

    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    *(ep0BaseAddress + 0x2) = 0x02;
}

//******************************************************************************
/* Function :  USBHS_EP0DataEndSet_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0DataEndSet 

  Description:
    This template implements the Default variant of the PLIB_USBHS_EP0DataEndSet function.
*/

PLIB_TEMPLATE void USBHS_EP0DataEndSet_Default( USBHS_MODULE_ID index)
{
    /* This function sets the data end bit */

    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    *(ep0BaseAddress + 0x2) = 0x08;
}

//******************************************************************************
/* Function :  USBHS_EP0INHandshakeSend_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0INHandshakeSend 

  Description:
    This template implements the Default variant of the PLIB_USBHS_EP0INHandshakeSend function.
*/

PLIB_TEMPLATE void USBHS_EP0INHandshakeSend_Default( USBHS_MODULE_ID index )
{
    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    *(ep0BaseAddress + 0x2) = 0x60;
}


//******************************************************************************
/* Function :  USBHS_EP0INTokenSend_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0INTokenSend 

  Description:
    This template implements the Default variant of the PLIB_USBHS_EP0INTokenSend function.
*/

PLIB_TEMPLATE void USBHS_EP0INTokenSend_Default( USBHS_MODULE_ID index )
{
    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    *(ep0BaseAddress + 0x2) = 0x20;

}

//******************************************************************************
/* Function :  USBHS_EP0StallEnable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0StallEnable 

  Description:
    This template implements the Default variant of the PLIB_USBHS_EP0StallEnable function.
*/

PLIB_TEMPLATE void USBHS_EP0StallEnable_Default( USBHS_MODULE_ID index )
{
    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    *(ep0BaseAddress + 0x2) = 0x20;

}

//******************************************************************************
/* Function :  USBHS_EP0StallDisable_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0StallDisable 

  Description:
    This template implements the Default variant of the PLIB_USBHS_EP0StallDisable function.
*/

PLIB_TEMPLATE void USBHS_EP0StallDisable_Default( USBHS_MODULE_ID index )
{
    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    *(ep0BaseAddress + 0x2) &= 0xDF;

}

//******************************************************************************
/* Function :  USBHS_EP0OUTHandshakeSend_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0OUTHandshakeSend 

  Description:
    This template implements the Default variant of the PLIB_USBHS_EP0OUTHandshakeSend function.
*/

PLIB_TEMPLATE void USBHS_EP0OUTHandshakeSend_Default( USBHS_MODULE_ID index )
{
    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    *(ep0BaseAddress + 0x2) = 0x42;

}


//******************************************************************************
/* Function :  USBHS_EP0INHandshakeClear_Default

  Summary:
    Implements Default variant of PLIB_USBHS_EP0INHandshakeClear 

  Description:
    This template implements the Default variant of the PLIB_USBHS_EP0INHandshakeClear function.
*/

PLIB_TEMPLATE void USBHS_EP0INHandshakeClear_Default( USBHS_MODULE_ID index )
{
    volatile uint8_t * ep0BaseAddress = (uint8_t *)_USBHS_ENDPOINT_BASE_ADDRESS_VREG(index);
    *(ep0BaseAddress + 0x2) &= 0xBE;
}


//******************************************************************************
/* Function :  USBHS_ExistsEP0Status_Default

  Summary:
    Implements Default variant of PLIB_USBHS_ExistsEP0Status

  Description:
    This template implements the Default variant of the PLIB_USBHS_ExistsEP0Status function.
*/

#define PLIB_USBHS_ExistsEP0Status PLIB_USBHS_ExistsEP0Status
PLIB_TEMPLATE bool USBHS_ExistsEP0Status_Default( USBHS_MODULE_ID index )
{
    return true;
}


#endif /*_USBHS_EP0STATUS_DEFAULT_H*/

/******************************************************************************
 End of File
*/

