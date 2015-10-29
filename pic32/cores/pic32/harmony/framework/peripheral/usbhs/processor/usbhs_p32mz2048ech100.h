/* Created by plibgen $Revision: 1.31 $ */

#ifndef _USBHS_P32MZ2048ECH100_H
#define _USBHS_P32MZ2048ECH100_H

/* Section 1 - Enumerate instances, define constants, VREGs */

#include <xc.h>
#include <stdbool.h>

#include "peripheral/peripheral_common_32bit.h"

/* Default definition used for all API dispatch functions */
#ifndef PLIB_INLINE_API
    #define PLIB_INLINE_API extern inline
#endif

/* Default definition used for all other functions */
#ifndef PLIB_INLINE
    #define PLIB_INLINE extern inline
#endif

typedef enum {

    USBHS_ID_0 = 0,
    USBHS_NUMBER_OF_MODULES

} USBHS_MODULE_ID;

typedef enum {

    USBHS_TXRXINT_EP0 = 0x01,
    USBHS_TXRXINT_EP1 = 0x02,
    USBHS_TXRXINT_EP2 = 0x04,
    USBHS_TXRXINT_EP3 = 0x08,
    USBHS_TXRXINT_EP4 = 0x10,
    USBHS_TXRXINT_EP5 = 0x20,
    USBHS_TXRXINT_EP6 = 0x40,
    USBHS_TXRXINT_EP7 = 0x80,
    USBHS_TXRXINT_ANY = 0xFF,
    USBHS_TXRXINT_ALL = 0xFF

} USBHS_EPTXRX_INTERRUPT;

typedef enum {

    USBHS_GENINT_SUSPEND = 0x01,
    USBHS_GENINT_RESUME = 0x02,
    USBHS_GENINT_RESET = 0x04,
    USBHS_GENINT_BABBLE = 0x04,
    USBHS_GENINT_SOF = 0x08,
    USBHS_GENINT_DEVCONN = 0x10,
    USBHS_GENINT_DEVDISCONN = 0x20,
    USBHS_GENINT_DEVSESSEND = 0x20,
    USBHS_GENINT_SESSIONREQ = 0x40,
    USBHS_GENINT_VBUSERR = 0x80,
    USBHS_GENINT_ANY = 0xFF,
    USBHS_GENINT_ALL = 0xFF

} USBHS_GEN_INTERRUPT;

typedef enum {

    USBHS_EP0_ERROR_NAK_TIMEOUT = 0x80,
    USBHS_EP0_ERROR_BUS = 0x10,
    USBHS_EP0_ERROR_RXSTALL = 0x04,
    USBHS_EP0_ERROR_ANY = 0x94,
    USBHS_EP0_ERROR_ALL = 0x94

} USBHS_EP0_ERROR;

typedef enum {

    USBHS_TXEP_ERROR_NAK_TIMEOUT = 0x80,
    USBHS_TXEP_ERROR_INCOMP_TX = 0x80,
    USBHS_TXEP_ERROR_BUS = 0x04,
    USBHS_TXEP_ERROR_RXSTALL = 0x20,
    USBHS_TXEP_ERROR_ANY = 0xA4,
    USBHS_TXEP_ERROR_ALL = 0xA4

} USBHS_TXEP_ERROR;

typedef enum {

    USBHS_RXEP_ERROR_NAK_TIMEOUT = 0x08,
    USBHS_RXEP_ERROR_ISO_DATA = 0x08,
    USBHS_RXEP_ERROR_BUS = 0x04,
    USBHS_RXEP_ERROR_RXSTALL = 0x40,
    USBHS_RXEP_ERROR_ANY = 0x4C,
    USBHS_RXEP_ERROR_ALL = 0x4C

} USBHS_RXEP_ERROR;

typedef enum {

    USBHS_VBUS_SESSION_END = 0x00,
    USBHS_VBUS_BELOW_AVALID = 0x08,
    USBHS_VBUS_BELOW_VBUSVALID = 0x10,
    USBHS_VBUS_VALID = 0x18

} USBHS_VBUS_LEVEL;

typedef enum {

    USBHS_EP0_RXPKTRDY = 0x01,
    USBHS_EP0_TXPKTRDY = 0x02,
    USBHS_EP0_SENTSTALL = 0x04,
    USBHS_EP0_SETUPEND = 0x10

} USBHS_DEVICE_EP0_STATUS;

typedef enum {

    USBHS_TXEP_FIFONOTEMPTY = 0x02,
    USBHS_TXEP_UNDERRUN = 0x04,
    USBHS_TXEP_SENTSTALL = 0x20,
    USBHS_TXEP_INCOMPTX = 0x80

} USBHS_DEVICE_TXEP_STATUS;

typedef enum {

    USBHS_RXEP_PKTRDY = 0x01,
    USBHS_RXEP_FIFOFULL = 0x02,
    USBHS_RXEP_OVERRUN = 0x04,
    USBHS_RXEP_DATAERROR = 0x08,
    USBHS_RXEP_SENTSTALL = 0x40

} USBHS_DEVICE_RXEP_STATUS;

PLIB_INLINE SFR_TYPE* _USBHS_BASE_ADDRESS_VREG(USBHS_MODULE_ID i)
{
    switch (i) {
        case USBHS_ID_0 :
            return &USBCSR0;
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USBHS_FIFO_BASE_ADDRESS_VREG(USBHS_MODULE_ID i)
{
    switch (i) {
        case USBHS_ID_0 :
            return &USBFIFO0;
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USBHS_TARGET_CONTROL_BASE_ADDRESS_VREG(USBHS_MODULE_ID i)
{
    switch (i) {
        case USBHS_ID_0 :
            return &USBE0TXA;
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USBHS_ENDPOINT_BASE_ADDRESS_VREG(USBHS_MODULE_ID i)
{
    switch (i) {
        case USBHS_ID_0 :
            return &USBE0CSR0;
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_DATA _USBHS_BASE_ADDRESS_MASK(USBHS_MODULE_ID i)
{
    switch (i) {
        case USBHS_ID_0 :
            return _USBCSR0_EP0IF_MASK;
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USBHS_FIFO_BASE_ADDRESS_MASK(USBHS_MODULE_ID i)
{
    switch (i) {
        case USBHS_ID_0 :
            return _USBFIFO0_DATA_MASK;
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USBHS_TARGET_CONTROL_BASE_ADDRESS_MASK(USBHS_MODULE_ID i)
{
    switch (i) {
        case USBHS_ID_0 :
            return _USBE0TXA_TXHUBPRT_MASK;
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USBHS_ENDPOINT_BASE_ADDRESS_MASK(USBHS_MODULE_ID i)
{
    switch (i) {
        case USBHS_ID_0 :
            return _USBE0CSR0_DTWE_MASK;
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USBHS_BASE_ADDRESS_POS(USBHS_MODULE_ID i)
{
    switch (i) {
        case USBHS_ID_0 :
            return _USBCSR0_EP0IF_POSITION;
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USBHS_FIFO_BASE_ADDRESS_POS(USBHS_MODULE_ID i)
{
    switch (i) {
        case USBHS_ID_0 :
            return _USBFIFO0_DATA_POSITION;
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USBHS_TARGET_CONTROL_BASE_ADDRESS_POS(USBHS_MODULE_ID i)
{
    switch (i) {
        case USBHS_ID_0 :
            return _USBE0TXA_TXHUBPRT_POSITION;
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USBHS_ENDPOINT_BASE_ADDRESS_POS(USBHS_MODULE_ID i)
{
    switch (i) {
        case USBHS_ID_0 :
            return _USBE0CSR0_DTWE_POSITION;
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USBHS_BASE_ADDRESS_LEN(USBHS_MODULE_ID i)
{
    switch (i) {
        case USBHS_ID_0 :
            return _USBCSR0_EP0IF_LENGTH;
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USBHS_FIFO_BASE_ADDRESS_LEN(USBHS_MODULE_ID i)
{
    switch (i) {
        case USBHS_ID_0 :
            return _USBFIFO0_DATA_LENGTH;
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USBHS_TARGET_CONTROL_BASE_ADDRESS_LEN(USBHS_MODULE_ID i)
{
    switch (i) {
        case USBHS_ID_0 :
            return _USBE0TXA_TXHUBPRT_LENGTH;
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USBHS_ENDPOINT_BASE_ADDRESS_LEN(USBHS_MODULE_ID i)
{
    switch (i) {
        case USBHS_ID_0 :
            return _USBE0CSR0_DTWE_LENGTH;
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE
#include "../templates/usbhs_EndpointFIFO_Default.h"
#include "../templates/usbhs_SoftReset_Default.h"
#include "../templates/usbhs_Interrupts_Default.h"
#include "../templates/usbhs_HighSpeedSupport_Default.h"
#include "../templates/usbhs_ClockResetControl_Unsupported.h"
#include "../templates/usbhs_ModuleControl_Default.h"
#include "../templates/usbhs_EP0Status_Default.h"
#include "../templates/usbhs_TxEPStatus_Default.h"
#include "../templates/usbhs_RxEPStatus_Default.h"
#include "../templates/usbhs_EndpointOperations_Default.h"

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API void PLIB_USBHS_EndpointFIFOLoad(USBHS_MODULE_ID index, uint8_t endpoint, void* source, size_t nBytes)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_EndpointFIFOLoad_Default(index, endpoint, source, nBytes);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API int PLIB_USBHS_EndpointFIFOUnload(USBHS_MODULE_ID index, uint8_t endpoint, void* dest)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_EndpointFIFOUnload_Default(index, endpoint, dest);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (int)0;
    }
}

PLIB_INLINE_API void PLIB_USBHS_Endpoint0FIFOFlush(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_Endpoint0FIFOFlush_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_EndpointTxFIFOFlush(USBHS_MODULE_ID index, uint8_t endpoint)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_EndpointTxFIFOFlush_Default(index, endpoint);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_EndpointRxFIFOFlush(USBHS_MODULE_ID index, uint8_t endpoint)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_EndpointRxFIFOFlush_Default(index, endpoint);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_Endpoint0SetupPacketLoad(USBHS_MODULE_ID index, void* setupPacket, uint8_t deviceAddress, uint8_t hubAddress, uint8_t hubPortAddress, uint32_t speed)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_Endpoint0SetupPacketLoad_Default(index, setupPacket, deviceAddress, hubAddress, hubPortAddress, speed);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_Endpoint0SetupPacketUnload(USBHS_MODULE_ID index, void* dest)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_Endpoint0SetupPacketUnload_Default(index, dest);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_DeviceEPFIFOLoad(USBHS_MODULE_ID index, uint8_t endpoint, void* source, size_t nBytes)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_DeviceEPFIFOLoad_Default(index, endpoint, source, nBytes);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API int PLIB_USBHS_DeviceEPFIFOUnload(USBHS_MODULE_ID index, uint8_t endpoint, void* dest)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_DeviceEPFIFOUnload_Default(index, endpoint, dest);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (int)0;
    }
}

PLIB_INLINE_API bool PLIB_USBHS_ExistsEndpointFIFO(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_ExistsEndpointFIFO_Default(index);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USBHS_SoftResetEnable(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_SoftResetEnable_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_SoftResetDisable(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_SoftResetDisable_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USBHS_ExistsSoftReset(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_ExistsSoftReset_Default(index);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USBHS_InterruptEnableSet(USBHS_MODULE_ID index, USBHS_GEN_INTERRUPT generalInterrupts, USBHS_EPTXRX_INTERRUPT transmitInterrupts, USBHS_EPTXRX_INTERRUPT receiveInterrupts)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_InterruptEnableSet_Default(index, generalInterrupts, transmitInterrupts, receiveInterrupts);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API USBHS_EPTXRX_INTERRUPT PLIB_USBHS_TxInterruptFlagsGet(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_TxInterruptFlagsGet_Default(index);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (USBHS_EPTXRX_INTERRUPT)0;
    }
}

PLIB_INLINE_API USBHS_EPTXRX_INTERRUPT PLIB_USBHS_RxInterruptFlagsGet(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_RxInterruptFlagsGet_Default(index);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (USBHS_EPTXRX_INTERRUPT)0;
    }
}

PLIB_INLINE_API USBHS_GEN_INTERRUPT PLIB_USBHS_GenInterruptFlagsGet(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_GenInterruptFlagsGet_Default(index);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (USBHS_GEN_INTERRUPT)0;
    }
}

PLIB_INLINE_API void PLIB_USBHS_TxInterruptEnable(USBHS_MODULE_ID index, USBHS_EPTXRX_INTERRUPT interruptFlag)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_TxInterruptEnable_Default(index, interruptFlag);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_RxInterruptEnable(USBHS_MODULE_ID index, USBHS_EPTXRX_INTERRUPT interruptFlag)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_RxInterruptEnable_Default(index, interruptFlag);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_TxInterruptDisable(USBHS_MODULE_ID index, USBHS_EPTXRX_INTERRUPT interruptFlag)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_TxInterruptDisable_Default(index, interruptFlag);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_RxInterruptDisable(USBHS_MODULE_ID index, USBHS_EPTXRX_INTERRUPT interruptFlag)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_RxInterruptDisable_Default(index, interruptFlag);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USBHS_ExistsInterrupts(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_ExistsInterrupts_Default(index);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USBHS_HighSpeedEnable(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_HighSpeedEnable_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_HighSpeedDisable(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_HighSpeedDisable_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USBHS_HighSpeedIsConnected(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_HighSpeedIsConnected_Default(index);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USBHS_FullOrHighSpeedIsConnected(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_FullOrHighSpeedIsConnected_Default(index);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USBHS_ExistsHighSpeedSupport(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_ExistsHighSpeedSupport_Default(index);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USBHS_DMAErrorGet(USBHS_MODULE_ID index, uint8_t dmaChannel)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_DMAErrorGet_Default(index, dmaChannel);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API uint8_t PLIB_USBHS_DMAInterruptGet(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_DMAInterruptGet_Default(index);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (uint8_t)0;
    }
}

PLIB_INLINE_API void PLIB_USBHS_DMAOperationEnable(USBHS_MODULE_ID index, uint8_t endpoint, uint8_t dmaChannel, void* address, uint32_t count, bool direction)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_DMAOperationEnable_Default(index, endpoint, dmaChannel, address, count, direction);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_LoadEPInIndex(USBHS_MODULE_ID index, uint8_t endpoint)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_LoadEPInIndex_Default(index, endpoint);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API uint8_t* PLIB_USBHS_GetEP0FIFOAddress(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_GetEP0FIFOAddress_Default(index);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (uint8_t*)0;
    }
}

PLIB_INLINE_API uint8_t* PLIB_USBHS_GetEP0CSRAddress(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_GetEP0CSRAddress_Default(index);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (uint8_t*)0;
    }
}

PLIB_INLINE_API uint32_t PLIB_USBHS_GetReceiveDataCount(USBHS_MODULE_ID index, uint8_t endpoint)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_GetReceiveDataCount_Default(index, endpoint);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (uint32_t)0;
    }
}

PLIB_INLINE_API bool PLIB_USBHS_TestModeEnter(USBHS_MODULE_ID index, uint8_t testMode)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_TestModeEnter_Default(index, testMode);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USBHS_TestModeExit(USBHS_MODULE_ID index, uint8_t testMode)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_TestModeExit_Default(index, testMode);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USBHS_ExistsClockResetControl(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_ExistsClockResetControl_Unsupported(index);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_USBHS_GlobalInterruptEnable(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_GlobalInterruptEnable_Unsupported(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_USBHS_GlobalInterruptDisable(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_GlobalInterruptDisable_Unsupported(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_ResumeEnable(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_ResumeEnable_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_ResumeDisable(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_ResumeDisable_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_SuspendEnable(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_SuspendEnable_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_SuspendDisable(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_SuspendDisable_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_ResetEnable(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_ResetEnable_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_ResetDisable(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_ResetDisable_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API USBHS_VBUS_LEVEL PLIB_USBHS_VBUSLevelGet(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_VBUSLevelGet_Default(index);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (USBHS_VBUS_LEVEL)0;
    }
}

PLIB_INLINE_API bool PLIB_USBHS_HostModeIsEnabled(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_HostModeIsEnabled_Default(index);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USBHS_SessionEnable(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_SessionEnable_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_SessionDisable(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_SessionDisable_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_DeviceAddressSet(USBHS_MODULE_ID index, uint8_t address)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_DeviceAddressSet_Default(index, address);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_DeviceAttach(USBHS_MODULE_ID index, uint32_t speed)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_DeviceAttach_Default(index, speed);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_DeviceDetach(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_DeviceDetach_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USBHS_ExistsModuleControl(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_ExistsModuleControl_Default(index);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API uint8_t PLIB_USBHS_EP0StatusGet(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_EP0StatusGet_Default(index);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (uint8_t)0;
    }
}

PLIB_INLINE_API void PLIB_USBHS_EP0StatusClear(USBHS_MODULE_ID index, USBHS_EP0_ERROR error)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_EP0StatusClear_Default(index, error);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_EP0SentStallClear(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_EP0SentStallClear_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_EP0INHandshakeSend(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_EP0INHandshakeSend_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_EP0INTokenSend(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_EP0INTokenSend_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_EP0OUTHandshakeSend(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_EP0OUTHandshakeSend_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_EP0INHandshakeClear(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_EP0INHandshakeClear_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_EP0StallEnable(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_EP0StallEnable_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_EP0StallDisable(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_EP0StallDisable_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_EP0SetupEndServiced(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_EP0SetupEndServiced_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_EP0RxPktRdyServiced(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_EP0RxPktRdyServiced_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_EP0RxPktRdyServicedDataEnd(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_EP0RxPktRdyServicedDataEnd_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_EP0TxPktRdyDataEnd(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_EP0TxPktRdyDataEnd_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_EP0TxPktRdy(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_EP0TxPktRdy_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_EP0DataEndSet(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_EP0DataEndSet_Default(index);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USBHS_ExistsEP0Status(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_ExistsEP0Status_Default(index);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API uint8_t PLIB_USBHS_TxEPStatusGet(USBHS_MODULE_ID index, uint8_t endpoint)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_TxEPStatusGet_Default(index, endpoint);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (uint8_t)0;
    }
}

PLIB_INLINE_API void PLIB_USBHS_TxEPStatusClear(USBHS_MODULE_ID index, uint8_t endpoint, USBHS_TXEP_ERROR error)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_TxEPStatusClear_Default(index, endpoint, error);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USBHS_ExistsTxEPStatus(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_ExistsTxEPStatus_Default(index);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API uint8_t PLIB_USBHS_RxEPStatusGet(USBHS_MODULE_ID index, uint8_t endpoint)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_RxEPStatusGet_Default(index, endpoint);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (uint8_t)0;
    }
}

PLIB_INLINE_API void PLIB_USBHS_RxEPStatusClear(USBHS_MODULE_ID index, uint8_t endpoint, USBHS_RXEP_ERROR error)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_RxEPStatusClear_Default(index, endpoint, error);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_RxEPINTokenSend(USBHS_MODULE_ID index, uint8_t endpoint)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_RxEPINTokenSend_Default(index, endpoint);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USBHS_ExistsRxEPStatus(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_ExistsRxEPStatus_Default(index);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USBHS_EndpointRxRequestEnable(USBHS_MODULE_ID index, uint8_t endpoint)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_EndpointRxRequestEnable_Default(index, endpoint);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_EndpointRxRequestClear(USBHS_MODULE_ID index, uint8_t endpoint)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_EndpointRxRequestClear_Default(index, endpoint);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_HostRxEndpointConfigure(USBHS_MODULE_ID index, uint8_t hostEndpoint, uint32_t speed, uint32_t pipeType, uint16_t endpointSize, uint16_t receiveFIFOAddress, uint16_t fifoSize, uint8_t targetEndpoint, uint8_t targetDevice, uint8_t targetHub, uint8_t targetHubPort, uint8_t nakInterval)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_HostRxEndpointConfigure_Default(index, hostEndpoint, speed, pipeType, endpointSize, receiveFIFOAddress, fifoSize, targetEndpoint, targetDevice, targetHub, targetHubPort, nakInterval);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_HostTxEndpointConfigure(USBHS_MODULE_ID index, uint8_t hostEndpoint, uint32_t speed, uint32_t pipeType, uint16_t endpointSize, uint16_t receiveFIFOAddress, uint16_t fifoSize, uint8_t targetEndpoint, uint8_t targetDevice, uint8_t targetHub, uint8_t targetHubPort, uint8_t nakInterval)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_HostTxEndpointConfigure_Default(index, hostEndpoint, speed, pipeType, endpointSize, receiveFIFOAddress, fifoSize, targetEndpoint, targetDevice, targetHub, targetHubPort, nakInterval);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_HostTxEndpointDataToggleClear(USBHS_MODULE_ID index, uint8_t hostEndpoint)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_HostTxEndpointDataToggleClear_Default(index, hostEndpoint);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_HostRxEndpointDataToggleClear(USBHS_MODULE_ID index, uint8_t hostEndpoint)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_HostRxEndpointDataToggleClear_Default(index, hostEndpoint);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_DeviceRxEndpointConfigure(USBHS_MODULE_ID index, uint8_t endpoint, uint16_t endpointSize, uint16_t fifoAddress, uint8_t fifoSize, uint32_t transferType)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_DeviceRxEndpointConfigure_Default(index, endpoint, endpointSize, fifoAddress, fifoSize, transferType);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_DeviceTxEndpointConfigure(USBHS_MODULE_ID index, uint8_t endpoint, uint16_t endpointSize, uint16_t fifoAddress, uint8_t fifoSize, uint32_t transferType)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_DeviceTxEndpointConfigure_Default(index, endpoint, endpointSize, fifoAddress, fifoSize, transferType);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_DeviceRxEndpointStallEnable(USBHS_MODULE_ID index, uint8_t endpoint)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_DeviceRxEndpointStallEnable_Default(index, endpoint);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_DeviceTxEndpointStallEnable(USBHS_MODULE_ID index, uint8_t endpoint)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_DeviceTxEndpointStallEnable_Default(index, endpoint);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_DeviceRxEndpointStallDisable(USBHS_MODULE_ID index, uint8_t endpoint)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_DeviceRxEndpointStallDisable_Default(index, endpoint);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_DeviceTxEndpointStallDisable(USBHS_MODULE_ID index, uint8_t endpoint)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_DeviceTxEndpointStallDisable_Default(index, endpoint);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USBHS_DeviceTxEndpointPacketReady(USBHS_MODULE_ID index, uint8_t endpoint)
{
    switch (index) {
        case USBHS_ID_0 :
            USBHS_DeviceTxEndpointPacketReady_Default(index, endpoint);
            break;
        case USBHS_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USBHS_ExistsEndpointOperations(USBHS_MODULE_ID index)
{
    switch (index) {
        case USBHS_ID_0 :
            return USBHS_ExistsEndpointOperations_Default(index);
        case USBHS_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

#endif
