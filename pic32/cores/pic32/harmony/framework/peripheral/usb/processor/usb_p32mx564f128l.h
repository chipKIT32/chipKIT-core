/* Created by plibgen $Revision: 1.31 $ */

#ifndef _USB_P32MX564F128L_H
#define _USB_P32MX564F128L_H

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

    USB_ID_1 = 0,
    USB_NUMBER_OF_MODULES

} USB_MODULE_ID;

typedef enum {

    USB_INT_DEVICE_RESET = 0x01,
    USB_INT_ERROR = 0x02,
    USB_INT_TOKEN_DONE = 0x08,
    USB_INT_IDLE_DETECT = 0x10,
    USB_INT_STALL = 0x80,
    USB_INT_SOF = 0x04,
    USB_INT_HOST_DETACH = 0x01,
    USB_INT_RESUME = 0x20,
    USB_INT_ATTACH = 0x40,
    USB_INT_ANY = 0xFF,
    USB_INT_ALL = 0xFF

} USB_INTERRUPTS;

typedef enum {

    USB_ERR_INT_PID_CHECK_FAILURE = 0x01,
    USB_ERR_INT_BAD_CRC5 = 0x02,
    USB_ERR_INT_BAD_CRC16 = 0x04,
    USB_ERR_INT_BAD_DATA_FIELD_SIZE = 0x08,
    USB_ERR_INT_BUS_TURNAROUND_TIMEOUT = 0x10,
    USB_ERR_INT_BIT_STUFF_ERROR = 0x80,
    USB_ERR_INT_HOST_EOF_ERROR = 0x02,
    USB_ERR_INT_DMA_ERROR = 0x20,
    USB_ERR_INT_BUS_MATRIX_ERROR = 0x40,
    USB_ERR_INT_ANY = 0xFF,
    USB_ERR_INT_ALL = 0xFF

} USB_ERROR_INTERRUPTS;

PLIB_INLINE SFR_TYPE* _USB_UnOTGIR_VAL_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1OTGIR;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_UnOTGIE_VAL_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1OTGIE;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_ID_STATE_CHANGE_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1OTGSTAT;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_LINE_STATE_STABLE_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1OTGSTAT;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_SESSION_VALID_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1OTGSTAT;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_B_SESSION_END_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1OTGSTAT;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_A_SESSION_VALID_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1OTGSTAT;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_DPLUS_PULLUP_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1OTGCON;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_DMINUS_PULLUP_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1OTGCON;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_DPLUS_PULLDN_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1OTGCON;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_DMINUS_PULLDN_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1OTGCON;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_VBUS_LINE_PWRD_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1OTGCON;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_OTG_ENABLE_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1OTGCON;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_VBUS_CHARGE_PULLUP_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1OTGCON;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_VBUS_DISCHARGE_PULLDN_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1OTGCON;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_ACTIVITY_PENDING_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1PWRC;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_SLEEP_GUARD_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1PWRC;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_MODULE_BUSY_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1PWRC;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_IN_SUSPEND_MODE_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1PWRC;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_POWERED_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1PWRC;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_UnIR_VAL_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1IR;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_UnIE_VAL_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1IE;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_UnEIR_VAL_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EIR;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_UnEIE_VAL_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EIE;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_LAST_ENDPOINT_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1STAT;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_LAST_DIRECTION_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1STAT;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_LAST_PING_PONG_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1STAT;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_LIVE_JSTATE_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1CON;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_LIVE_SE0_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1CON;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_PACKET_XFER_DISABLED_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1CON;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_BUSY_WITH_TOKEN_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1CON;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_GENERATE_RESET_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1CON;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_HOST_ENABLE_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1CON;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_RESUME_SIGNALING_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1CON;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_FREEZE_BUFFERS_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1CON;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_DEVICE_ENABLE_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1CON;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_START_OF_FRAMES_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1CON;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_NEXT_TOKEN_LOWSPEED_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1ADDR;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_DEVICE_ADDRESS_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1ADDR;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_FRAME_NUMBER_7to0_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1FRML;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_FRAME_NUMBER_10to8_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1FRMH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_TOKEN_PID_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1TOK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_TOKEN_ENDPOINT_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1TOK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_SOF_COUNT_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1SOF;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_BDT_BASE_ADDR_15to09_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1BDTP1;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_BDT_BASE_ADDR_23to16_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1BDTP2;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_BDT_BASE_ADDR_31to24_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1BDTP3;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EYE_PATTERN_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1CNFG1;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_STOP_IN_IDLE_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1CNFG1;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_AUTO_SUSPEND_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1CNFG1;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP0_LOW_SPEED_CONNECT_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP0;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP0_NO_RETRY_NAKS_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP0;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP0_CONTROL_OFF_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP0;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP0_RCV_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP0;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP0_XMIT_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP0;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP0_XMIT_ON_EN_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP0;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP0_STALL_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP0;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP0_HANDSHAKE_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP0;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP1_CONTROL_OFF_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP1;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP1_RCV_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP1;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP1_XMIT_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP1;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP1_STALL_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP1;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP1_HANDSHAKE_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP1;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP2_CONTROL_OFF_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP2;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP2_RCV_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP2;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP2_XMIT_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP2;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP2_STALL_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP2;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP2_HANDSHAKE_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP2;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP3_CONTROL_OFF_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP3;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP3_RCV_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP3;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP3_XMIT_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP3;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP3_STALL_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP3;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP3_HANDSHAKE_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP3;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP4_CONTROL_OFF_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP4;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP4_RCV_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP4;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP4_XMIT_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP4;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP4_STALL_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP4;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP4_HANDSHAKE_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP4;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP5_CONTROL_OFF_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP5;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP5_RCV_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP5;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP5_XMIT_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP5;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP5_STALL_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP5;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP5_HANDSHAKE_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP5;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP6_CONTROL_OFF_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP6;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP6_RCV_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP6;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP6_XMIT_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP6;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP6_STALL_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP6;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP6_HANDSHAKE_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP6;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP7_CONTROL_OFF_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP7;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP7_RCV_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP7;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP7_XMIT_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP7;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP7_STALL_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP7;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP7_HANDSHAKE_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP7;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP8_CONTROL_OFF_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP8;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP8_RCV_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP8;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP8_XMIT_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP8;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP8_STALL_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP8;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP8_HANDSHAKE_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP8;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP9_CONTROL_OFF_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP9;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP9_RCV_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP9;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP9_XMIT_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP9;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP9_STALL_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP9;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP9_HANDSHAKE_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP9;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP10_CONTROL_OFF_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP10;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP10_RCV_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP10;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP10_XMIT_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP10;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP10_STALL_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP10;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP10_HANDSHAKE_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP10;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP11_CONTROL_OFF_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP11;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP11_RCV_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP11;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP11_XMIT_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP11;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP11_STALL_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP11;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP11_HANDSHAKE_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP11;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP12_CONTROL_OFF_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP12;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP12_RCV_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP12;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP12_XMIT_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP12;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP12_STALL_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP12;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP12_HANDSHAKE_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP12;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP13_CONTROL_OFF_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP13;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP13_RCV_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP13;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP13_XMIT_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP13;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP13_STALL_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP13;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP13_HANDSHAKE_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP13;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP14_CONTROL_OFF_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP14;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP14_RCV_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP14;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP14_XMIT_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP14;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP14_STALL_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP14;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP14_HANDSHAKE_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP14;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP15_CONTROL_OFF_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP15;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP15_RCV_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP15;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP15_XMIT_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP15;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP15_STALL_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP15;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _USB_EP15_HANDSHAKE_ON_VREG(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return &U1EP15;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_UnOTGIR_VAL_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGIR_IDIF_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_UnOTGIE_VAL_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGIE_IDIE_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_ID_STATE_CHANGE_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGSTAT_ID_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_LINE_STATE_STABLE_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGSTAT_LSTATE_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_SESSION_VALID_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGSTAT_SESVD_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_B_SESSION_END_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGSTAT_SESEND_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_A_SESSION_VALID_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGSTAT_VBUSVD_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_DPLUS_PULLUP_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_DPPULUP_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_DMINUS_PULLUP_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_DMPULUP_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_DPLUS_PULLDN_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_DPPULDWN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_DMINUS_PULLDN_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_DMPULDWN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_VBUS_LINE_PWRD_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_VBUSON_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_OTG_ENABLE_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_OTGEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_VBUS_CHARGE_PULLUP_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_VBUSCHG_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_VBUS_DISCHARGE_PULLDN_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_VBUSDIS_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_ACTIVITY_PENDING_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1PWRC_UACTPND_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_SLEEP_GUARD_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1PWRC_USLPGRD_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_MODULE_BUSY_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1PWRC_USBBUSY_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_IN_SUSPEND_MODE_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1PWRC_USUSPEND_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_POWERED_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1PWRC_USBPWR_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_UnIR_VAL_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1IR_STALLIF_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_UnIE_VAL_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1IE_STALLIE_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_UnEIR_VAL_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EIR_BTSEF_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_UnEIE_VAL_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EIE_BTSEE_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_LAST_ENDPOINT_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1STAT_ENDPT_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_LAST_DIRECTION_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1STAT_DIR_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_LAST_PING_PONG_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1STAT_PPBI_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_LIVE_JSTATE_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_JSTATE_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_LIVE_SE0_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_SE0_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_PACKET_XFER_DISABLED_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_PKTDIS_TOKBUSY_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_BUSY_WITH_TOKEN_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_PKTDIS_TOKBUSY_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_GENERATE_RESET_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_USBRST_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_HOST_ENABLE_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_HOSTEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_RESUME_SIGNALING_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_RESUME_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_FREEZE_BUFFERS_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_PPBRST_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_DEVICE_ENABLE_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_USBEN_SOFEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_START_OF_FRAMES_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_USBEN_SOFEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_NEXT_TOKEN_LOWSPEED_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1ADDR_LSPDEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_DEVICE_ADDRESS_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1ADDR_DEVADDR_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_FRAME_NUMBER_7to0_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1FRML_FRML_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_FRAME_NUMBER_10to8_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1FRMH_FRMH_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_TOKEN_PID_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1TOK_PID_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_TOKEN_ENDPOINT_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1TOK_EP_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_SOF_COUNT_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1SOF_CNT_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_BDT_BASE_ADDR_15to09_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1BDTP1_BDTPTRL_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_BDT_BASE_ADDR_23to16_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1BDTP2_BDTPTRH_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_BDT_BASE_ADDR_31to24_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1BDTP3_BDTPTRU_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EYE_PATTERN_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CNFG1_UTEYE_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_STOP_IN_IDLE_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CNFG1_USBSIDL_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_AUTO_SUSPEND_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CNFG1_UASUSPND_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_LOW_SPEED_CONNECT_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_LSPD_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_NO_RETRY_NAKS_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_RETRYDIS_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_CONTROL_OFF_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_EPCONDIS_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_RCV_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_EPRXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_XMIT_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_EPTXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_XMIT_ON_EN_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_EPTXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_STALL_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_EPSTALL_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_HANDSHAKE_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_EPHSHK_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP1_CONTROL_OFF_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP1_EPCONDIS_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP1_RCV_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP1_EPRXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP1_XMIT_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP1_EPTXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP1_STALL_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP1_EPSTALL_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP1_HANDSHAKE_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP1_EPHSHK_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP2_CONTROL_OFF_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP2_EPCONDIS_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP2_RCV_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP2_EPRXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP2_XMIT_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP2_EPTXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP2_STALL_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP2_EPSTALL_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP2_HANDSHAKE_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP2_EPHSHK_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP3_CONTROL_OFF_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP3_EPCONDIS_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP3_RCV_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP3_EPRXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP3_XMIT_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP3_EPTXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP3_STALL_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP3_EPSTALL_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP3_HANDSHAKE_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP3_EPHSHK_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP4_CONTROL_OFF_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP4_EPCONDIS_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP4_RCV_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP4_EPRXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP4_XMIT_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP4_EPTXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP4_STALL_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP4_EPSTALL_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP4_HANDSHAKE_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP4_EPHSHK_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP5_CONTROL_OFF_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP5_EPCONDIS_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP5_RCV_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP5_EPRXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP5_XMIT_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP5_EPTXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP5_STALL_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP5_EPSTALL_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP5_HANDSHAKE_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP5_EPHSHK_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP6_CONTROL_OFF_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP6_EPCONDIS_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP6_RCV_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP6_EPRXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP6_XMIT_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP6_EPTXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP6_STALL_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP6_EPSTALL_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP6_HANDSHAKE_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP6_EPHSHK_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP7_CONTROL_OFF_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP7_EPCONDIS_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP7_RCV_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP7_EPRXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP7_XMIT_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP7_EPTXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP7_STALL_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP7_EPSTALL_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP7_HANDSHAKE_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP7_EPHSHK_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP8_CONTROL_OFF_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP8_EPCONDIS_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP8_RCV_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP8_EPRXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP8_XMIT_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP8_EPTXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP8_STALL_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP8_EPSTALL_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP8_HANDSHAKE_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP8_EPHSHK_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP9_CONTROL_OFF_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP9_EPCONDIS_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP9_RCV_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP9_EPRXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP9_XMIT_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP9_EPTXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP9_STALL_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP9_EPSTALL_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP9_HANDSHAKE_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP9_EPHSHK_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP10_CONTROL_OFF_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP10_EPCONDIS_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP10_RCV_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP10_EPRXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP10_XMIT_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP10_EPTXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP10_STALL_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP10_EPSTALL_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP10_HANDSHAKE_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP10_EPHSHK_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP11_CONTROL_OFF_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP11_EPCONDIS_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP11_RCV_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP11_EPRXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP11_XMIT_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP11_EPTXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP11_STALL_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP11_EPSTALL_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP11_HANDSHAKE_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP11_EPHSHK_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP12_CONTROL_OFF_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP12_EPCONDIS_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP12_RCV_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP12_EPRXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP12_XMIT_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP12_EPTXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP12_STALL_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP12_EPSTALL_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP12_HANDSHAKE_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP12_EPHSHK_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP13_CONTROL_OFF_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP13_EPCONDIS_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP13_RCV_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP13_EPRXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP13_XMIT_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP13_EPTXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP13_STALL_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP13_EPSTALL_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP13_HANDSHAKE_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP13_EPHSHK_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP14_CONTROL_OFF_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP14_EPCONDIS_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP14_RCV_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP14_EPRXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP14_XMIT_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP14_EPTXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP14_STALL_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP14_EPSTALL_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP14_HANDSHAKE_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP14_EPHSHK_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP15_CONTROL_OFF_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP15_EPCONDIS_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP15_RCV_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP15_EPRXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP15_XMIT_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP15_EPTXEN_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP15_STALL_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP15_EPSTALL_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP15_HANDSHAKE_ON_MASK(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP15_EPHSHK_MASK;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_UnOTGIR_VAL_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGIR_IDIF_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_UnOTGIE_VAL_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGIE_IDIE_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_ID_STATE_CHANGE_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGSTAT_ID_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_LINE_STATE_STABLE_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGSTAT_LSTATE_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_SESSION_VALID_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGSTAT_SESVD_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_B_SESSION_END_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGSTAT_SESEND_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_A_SESSION_VALID_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGSTAT_VBUSVD_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_DPLUS_PULLUP_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_DPPULUP_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_DMINUS_PULLUP_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_DMPULUP_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_DPLUS_PULLDN_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_DPPULDWN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_DMINUS_PULLDN_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_DMPULDWN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_VBUS_LINE_PWRD_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_VBUSON_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_OTG_ENABLE_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_OTGEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_VBUS_CHARGE_PULLUP_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_VBUSCHG_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_VBUS_DISCHARGE_PULLDN_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_VBUSDIS_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_ACTIVITY_PENDING_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1PWRC_UACTPND_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_SLEEP_GUARD_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1PWRC_USLPGRD_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_MODULE_BUSY_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1PWRC_USBBUSY_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_IN_SUSPEND_MODE_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1PWRC_USUSPEND_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_POWERED_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1PWRC_USBPWR_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_UnIR_VAL_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1IR_STALLIF_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_UnIE_VAL_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1IE_STALLIE_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_UnEIR_VAL_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EIR_BTSEF_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_UnEIE_VAL_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EIE_BTSEE_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_LAST_ENDPOINT_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1STAT_ENDPT_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_LAST_DIRECTION_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1STAT_DIR_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_LAST_PING_PONG_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1STAT_PPBI_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_LIVE_JSTATE_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_JSTATE_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_LIVE_SE0_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_SE0_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_PACKET_XFER_DISABLED_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_PKTDIS_TOKBUSY_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_BUSY_WITH_TOKEN_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_PKTDIS_TOKBUSY_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_GENERATE_RESET_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_USBRST_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_HOST_ENABLE_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_HOSTEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_RESUME_SIGNALING_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_RESUME_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_FREEZE_BUFFERS_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_PPBRST_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_DEVICE_ENABLE_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_USBEN_SOFEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_START_OF_FRAMES_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_USBEN_SOFEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_NEXT_TOKEN_LOWSPEED_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1ADDR_LSPDEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_DEVICE_ADDRESS_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1ADDR_DEVADDR_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_FRAME_NUMBER_7to0_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1FRML_FRML_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_FRAME_NUMBER_10to8_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1FRMH_FRMH_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_TOKEN_PID_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1TOK_PID_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_TOKEN_ENDPOINT_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1TOK_EP_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_SOF_COUNT_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1SOF_CNT_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_BDT_BASE_ADDR_15to09_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1BDTP1_BDTPTRL_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_BDT_BASE_ADDR_23to16_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1BDTP2_BDTPTRH_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_BDT_BASE_ADDR_31to24_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1BDTP3_BDTPTRU_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EYE_PATTERN_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CNFG1_UTEYE_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_STOP_IN_IDLE_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CNFG1_USBSIDL_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_AUTO_SUSPEND_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CNFG1_UASUSPND_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_LOW_SPEED_CONNECT_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_LSPD_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_NO_RETRY_NAKS_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_RETRYDIS_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_CONTROL_OFF_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_EPCONDIS_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_RCV_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_EPRXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_XMIT_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_EPTXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_XMIT_ON_EN_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_EPTXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_STALL_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_EPSTALL_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_HANDSHAKE_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_EPHSHK_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP1_CONTROL_OFF_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP1_EPCONDIS_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP1_RCV_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP1_EPRXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP1_XMIT_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP1_EPTXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP1_STALL_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP1_EPSTALL_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP1_HANDSHAKE_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP1_EPHSHK_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP2_CONTROL_OFF_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP2_EPCONDIS_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP2_RCV_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP2_EPRXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP2_XMIT_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP2_EPTXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP2_STALL_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP2_EPSTALL_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP2_HANDSHAKE_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP2_EPHSHK_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP3_CONTROL_OFF_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP3_EPCONDIS_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP3_RCV_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP3_EPRXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP3_XMIT_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP3_EPTXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP3_STALL_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP3_EPSTALL_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP3_HANDSHAKE_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP3_EPHSHK_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP4_CONTROL_OFF_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP4_EPCONDIS_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP4_RCV_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP4_EPRXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP4_XMIT_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP4_EPTXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP4_STALL_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP4_EPSTALL_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP4_HANDSHAKE_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP4_EPHSHK_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP5_CONTROL_OFF_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP5_EPCONDIS_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP5_RCV_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP5_EPRXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP5_XMIT_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP5_EPTXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP5_STALL_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP5_EPSTALL_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP5_HANDSHAKE_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP5_EPHSHK_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP6_CONTROL_OFF_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP6_EPCONDIS_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP6_RCV_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP6_EPRXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP6_XMIT_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP6_EPTXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP6_STALL_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP6_EPSTALL_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP6_HANDSHAKE_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP6_EPHSHK_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP7_CONTROL_OFF_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP7_EPCONDIS_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP7_RCV_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP7_EPRXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP7_XMIT_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP7_EPTXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP7_STALL_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP7_EPSTALL_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP7_HANDSHAKE_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP7_EPHSHK_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP8_CONTROL_OFF_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP8_EPCONDIS_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP8_RCV_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP8_EPRXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP8_XMIT_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP8_EPTXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP8_STALL_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP8_EPSTALL_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP8_HANDSHAKE_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP8_EPHSHK_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP9_CONTROL_OFF_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP9_EPCONDIS_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP9_RCV_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP9_EPRXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP9_XMIT_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP9_EPTXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP9_STALL_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP9_EPSTALL_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP9_HANDSHAKE_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP9_EPHSHK_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP10_CONTROL_OFF_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP10_EPCONDIS_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP10_RCV_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP10_EPRXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP10_XMIT_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP10_EPTXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP10_STALL_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP10_EPSTALL_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP10_HANDSHAKE_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP10_EPHSHK_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP11_CONTROL_OFF_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP11_EPCONDIS_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP11_RCV_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP11_EPRXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP11_XMIT_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP11_EPTXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP11_STALL_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP11_EPSTALL_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP11_HANDSHAKE_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP11_EPHSHK_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP12_CONTROL_OFF_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP12_EPCONDIS_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP12_RCV_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP12_EPRXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP12_XMIT_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP12_EPTXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP12_STALL_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP12_EPSTALL_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP12_HANDSHAKE_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP12_EPHSHK_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP13_CONTROL_OFF_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP13_EPCONDIS_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP13_RCV_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP13_EPRXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP13_XMIT_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP13_EPTXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP13_STALL_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP13_EPSTALL_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP13_HANDSHAKE_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP13_EPHSHK_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP14_CONTROL_OFF_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP14_EPCONDIS_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP14_RCV_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP14_EPRXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP14_XMIT_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP14_EPTXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP14_STALL_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP14_EPSTALL_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP14_HANDSHAKE_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP14_EPHSHK_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP15_CONTROL_OFF_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP15_EPCONDIS_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP15_RCV_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP15_EPRXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP15_XMIT_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP15_EPTXEN_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP15_STALL_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP15_EPSTALL_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP15_HANDSHAKE_ON_POS(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP15_EPHSHK_POSITION;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_UnOTGIR_VAL_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGIR_IDIF_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_UnOTGIE_VAL_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGIE_IDIE_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_ID_STATE_CHANGE_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGSTAT_ID_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_LINE_STATE_STABLE_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGSTAT_LSTATE_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_SESSION_VALID_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGSTAT_SESVD_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_B_SESSION_END_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGSTAT_SESEND_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_A_SESSION_VALID_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGSTAT_VBUSVD_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_DPLUS_PULLUP_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_DPPULUP_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_DMINUS_PULLUP_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_DMPULUP_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_DPLUS_PULLDN_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_DPPULDWN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_DMINUS_PULLDN_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_DMPULDWN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_VBUS_LINE_PWRD_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_VBUSON_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_OTG_ENABLE_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_OTGEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_VBUS_CHARGE_PULLUP_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_VBUSCHG_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_VBUS_DISCHARGE_PULLDN_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1OTGCON_VBUSDIS_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_ACTIVITY_PENDING_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1PWRC_UACTPND_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_SLEEP_GUARD_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1PWRC_USLPGRD_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_MODULE_BUSY_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1PWRC_USBBUSY_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_IN_SUSPEND_MODE_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1PWRC_USUSPEND_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_POWERED_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1PWRC_USBPWR_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_UnIR_VAL_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1IR_STALLIF_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_UnIE_VAL_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1IE_STALLIE_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_UnEIR_VAL_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EIR_BTSEF_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_UnEIE_VAL_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EIE_BTSEE_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_LAST_ENDPOINT_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1STAT_ENDPT_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_LAST_DIRECTION_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1STAT_DIR_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_LAST_PING_PONG_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1STAT_PPBI_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_LIVE_JSTATE_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_JSTATE_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_LIVE_SE0_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_SE0_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_PACKET_XFER_DISABLED_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_PKTDIS_TOKBUSY_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_BUSY_WITH_TOKEN_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_PKTDIS_TOKBUSY_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_GENERATE_RESET_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_USBRST_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_HOST_ENABLE_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_HOSTEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_RESUME_SIGNALING_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_RESUME_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_FREEZE_BUFFERS_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_PPBRST_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_DEVICE_ENABLE_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_USBEN_SOFEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_START_OF_FRAMES_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CON_USBEN_SOFEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_NEXT_TOKEN_LOWSPEED_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1ADDR_LSPDEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_DEVICE_ADDRESS_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1ADDR_DEVADDR_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_FRAME_NUMBER_7to0_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1FRML_FRML_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_FRAME_NUMBER_10to8_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1FRMH_FRMH_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_TOKEN_PID_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1TOK_PID_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_TOKEN_ENDPOINT_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1TOK_EP_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_SOF_COUNT_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1SOF_CNT_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_BDT_BASE_ADDR_15to09_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1BDTP1_BDTPTRL_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_BDT_BASE_ADDR_23to16_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1BDTP2_BDTPTRH_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_BDT_BASE_ADDR_31to24_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1BDTP3_BDTPTRU_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EYE_PATTERN_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CNFG1_UTEYE_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_STOP_IN_IDLE_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CNFG1_USBSIDL_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_AUTO_SUSPEND_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1CNFG1_UASUSPND_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_LOW_SPEED_CONNECT_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_LSPD_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_NO_RETRY_NAKS_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_RETRYDIS_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_CONTROL_OFF_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_EPCONDIS_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_RCV_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_EPRXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_XMIT_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_EPTXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_XMIT_ON_EN_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_EPTXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_STALL_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_EPSTALL_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP0_HANDSHAKE_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP0_EPHSHK_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP1_CONTROL_OFF_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP1_EPCONDIS_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP1_RCV_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP1_EPRXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP1_XMIT_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP1_EPTXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP1_STALL_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP1_EPSTALL_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP1_HANDSHAKE_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP1_EPHSHK_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP2_CONTROL_OFF_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP2_EPCONDIS_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP2_RCV_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP2_EPRXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP2_XMIT_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP2_EPTXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP2_STALL_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP2_EPSTALL_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP2_HANDSHAKE_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP2_EPHSHK_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP3_CONTROL_OFF_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP3_EPCONDIS_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP3_RCV_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP3_EPRXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP3_XMIT_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP3_EPTXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP3_STALL_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP3_EPSTALL_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP3_HANDSHAKE_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP3_EPHSHK_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP4_CONTROL_OFF_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP4_EPCONDIS_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP4_RCV_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP4_EPRXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP4_XMIT_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP4_EPTXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP4_STALL_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP4_EPSTALL_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP4_HANDSHAKE_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP4_EPHSHK_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP5_CONTROL_OFF_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP5_EPCONDIS_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP5_RCV_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP5_EPRXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP5_XMIT_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP5_EPTXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP5_STALL_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP5_EPSTALL_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP5_HANDSHAKE_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP5_EPHSHK_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP6_CONTROL_OFF_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP6_EPCONDIS_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP6_RCV_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP6_EPRXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP6_XMIT_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP6_EPTXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP6_STALL_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP6_EPSTALL_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP6_HANDSHAKE_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP6_EPHSHK_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP7_CONTROL_OFF_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP7_EPCONDIS_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP7_RCV_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP7_EPRXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP7_XMIT_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP7_EPTXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP7_STALL_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP7_EPSTALL_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP7_HANDSHAKE_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP7_EPHSHK_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP8_CONTROL_OFF_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP8_EPCONDIS_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP8_RCV_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP8_EPRXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP8_XMIT_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP8_EPTXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP8_STALL_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP8_EPSTALL_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP8_HANDSHAKE_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP8_EPHSHK_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP9_CONTROL_OFF_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP9_EPCONDIS_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP9_RCV_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP9_EPRXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP9_XMIT_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP9_EPTXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP9_STALL_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP9_EPSTALL_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP9_HANDSHAKE_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP9_EPHSHK_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP10_CONTROL_OFF_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP10_EPCONDIS_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP10_RCV_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP10_EPRXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP10_XMIT_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP10_EPTXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP10_STALL_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP10_EPSTALL_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP10_HANDSHAKE_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP10_EPHSHK_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP11_CONTROL_OFF_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP11_EPCONDIS_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP11_RCV_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP11_EPRXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP11_XMIT_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP11_EPTXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP11_STALL_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP11_EPSTALL_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP11_HANDSHAKE_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP11_EPHSHK_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP12_CONTROL_OFF_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP12_EPCONDIS_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP12_RCV_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP12_EPRXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP12_XMIT_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP12_EPTXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP12_STALL_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP12_EPSTALL_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP12_HANDSHAKE_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP12_EPHSHK_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP13_CONTROL_OFF_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP13_EPCONDIS_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP13_RCV_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP13_EPRXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP13_XMIT_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP13_EPTXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP13_STALL_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP13_EPSTALL_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP13_HANDSHAKE_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP13_EPHSHK_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP14_CONTROL_OFF_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP14_EPCONDIS_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP14_RCV_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP14_EPRXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP14_XMIT_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP14_EPTXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP14_STALL_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP14_EPSTALL_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP14_HANDSHAKE_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP14_EPHSHK_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP15_CONTROL_OFF_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP15_EPCONDIS_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP15_RCV_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP15_EPRXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP15_XMIT_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP15_EPTXEN_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP15_STALL_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP15_EPSTALL_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _USB_EP15_HANDSHAKE_ON_LEN(USB_MODULE_ID i)
{
    switch (i) {
        case USB_ID_1 :
            return _U1EP15_EPHSHK_LENGTH;
        case USB_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE
#include "../templates/usb_OTG_InterruptStatus_Default.h"
#include "../templates/usb_OTG_Interrupt_Default.h"
#include "../templates/usb_OTG_IDPinState_Default.h"
#include "../templates/usb_OTG_LineState_Default.h"
#include "../templates/usb_OTG_SessionValid_Default.h"
#include "../templates/usb_OTG_BSessionEnd_Default.h"
#include "../templates/usb_OTG_ASessionValid_Default.h"
#include "../templates/usb_OTG_PullUpPullDown_Default.h"
#include "../templates/usb_OTG_VbusPowerOnOff_Default.h"
#include "../templates/usb_OTG_VbusCharge_Default.h"
#include "../templates/usb_OTG_VbusDischarge_Default.h"
#include "../templates/usb_ActivityPending_Default.h"
#include "../templates/usb_SleepEntryGuard_Default.h"
#include "../templates/usb_ModuleBusy_Default.h"
#include "../templates/usb_Suspend_Default.h"
#include "../templates/usb_ModulePower_32Bit16Bit.h"
#include "../templates/usb_GEN_InterruptStatus_Default.h"
#include "../templates/usb_GEN_Interrupt_Default.h"
#include "../templates/usb_ALL_Interrupt_Default.h"
#include "../templates/usb_ERR_InterruptStatus_Default.h"
#include "../templates/usb_ERR_Interrupt_Default.h"
#include "../templates/usb_LastEndpoint_Default.h"
#include "../templates/usb_LastDirection_Default.h"
#include "../templates/usb_LastPingPong_Default.h"
#include "../templates/usb_LastTransactionDetails_Default.h"
#include "../templates/usb_LiveJState_Default.h"
#include "../templates/usb_LiveSingleEndedZero_Default.h"
#include "../templates/usb_PacketTransfer_Default.h"
#include "../templates/usb_HostBusyWithToken_Default.h"
#include "../templates/usb_HostGeneratesReset_Default.h"
#include "../templates/usb_OpModeSelect_Default.h"
#include "../templates/usb_ResumeSignaling_Default.h"
#include "../templates/usb_BufferFreeze_Default.h"
#include "../templates/usb_StartOfFrames_Default.h"
#include "../templates/usb_NextTokenSpeed_Default.h"
#include "../templates/usb_DeviceAddress_Default.h"
#include "../templates/usb_FrameNumber_Default.h"
#include "../templates/usb_TokenPID_Default.h"
#include "../templates/usb_TokenEP_Default.h"
#include "../templates/usb_SOFThreshold_Default.h"
#include "../templates/usb_BDTBaseAddress_Default.h"
#include "../templates/usb_EyePattern_Default.h"
#include "../templates/usb_StopInIdle_Default.h"
#include "../templates/usb_AutomaticSuspend_Default.h"
#include "../templates/usb_PingPongMode_Unsupported.h"
#include "../templates/usb_UOEMonitor_Unsupported.h"
#include "../templates/usb_OnChipPullup_Unsupported.h"
#include "../templates/usb_OnChipTransceiver_Unsupported.h"
#include "../templates/usb_SpeedControl_Unsupported.h"
#include "../templates/usb_EP0LowSpeedConnect_Default.h"
#include "../templates/usb_EP0NAKRetry_Default.h"
#include "../templates/usb_EPnTxRx_Default.h"
#include "../templates/usb_EPnRxEnableEnhanced_PIC32.h"
#include "../templates/usb_BDTFunctions_PIC32.h"

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API void PLIB_USB_OTG_InterruptFlagSet(USB_MODULE_ID index, USB_OTG_INTERRUPTS interruptFlag)
{
    switch (index) {
        case USB_ID_1 :
            USB_OTG_InterruptFlagSet_Default(index, interruptFlag);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_OTG_InterruptFlagClear(USB_MODULE_ID index, USB_OTG_INTERRUPTS interruptFlag)
{
    switch (index) {
        case USB_ID_1 :
            USB_OTG_InterruptFlagClear_Default(index, interruptFlag);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_OTG_InterruptFlagGet(USB_MODULE_ID index, USB_OTG_INTERRUPTS interruptFlag)
{
    switch (index) {
        case USB_ID_1 :
            return USB_OTG_InterruptFlagGet_Default(index, interruptFlag);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsOTG_InterruptStatus(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsOTG_InterruptStatus_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_OTG_InterruptEnable(USB_MODULE_ID index, USB_OTG_INTERRUPTS interruptFlag)
{
    switch (index) {
        case USB_ID_1 :
            USB_OTG_InterruptEnable_Default(index, interruptFlag);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_OTG_InterruptDisable(USB_MODULE_ID index, USB_OTG_INTERRUPTS interruptFlag)
{
    switch (index) {
        case USB_ID_1 :
            USB_OTG_InterruptDisable_Default(index, interruptFlag);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_OTG_InterruptIsEnabled(USB_MODULE_ID index, USB_INTERRUPTS interruptFlag)
{
    switch (index) {
        case USB_ID_1 :
            return USB_OTG_InterruptIsEnabled_Default(index, interruptFlag);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsOTG_Interrupt(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsOTG_Interrupt_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_OTG_IDPinStateIsTypeA(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_OTG_IDPinStateIsTypeA_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsOTG_IDPinState(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsOTG_IDPinState_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_OTG_LineStateIsStable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_OTG_LineStateIsStable_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsOTG_LineState(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsOTG_LineState_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_OTG_SessionValid(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_OTG_SessionValid_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsOTG_SessionValid(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsOTG_SessionValid_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_OTG_BSessionHasEnded(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_OTG_BSessionHasEnded_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsOTG_BSessionEnd(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsOTG_BSessionEnd_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_OTG_VBusValid(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_OTG_VBusValid_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsOTG_ASessionValid(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsOTG_ASessionValid_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_OTG_PullUpPullDownSetup(USB_MODULE_ID index, USB_OTG_PULL_UP_PULL_DOWN resistor, bool enableResistor)
{
    switch (index) {
        case USB_ID_1 :
            USB_OTG_PullUpPullDownSetup_Default(index, resistor, enableResistor);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsOTG_PullUpPullDown(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsOTG_PullUpPullDown_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_OTG_VBusPowerOff(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_OTG_VBusPowerOff_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_OTG_VBusPowerOn(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_OTG_VBusPowerOn_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsOTG_VbusPowerOnOff(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsOTG_VbusPowerOnOff_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_OTG_VBusChargeEnable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_OTG_VBusChargeEnable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_OTG_VBusChargeDisable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_OTG_VBusChargeDisable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsOTG_VbusCharge(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsOTG_VbusCharge_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_OTG_VBusDischargeEnable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_OTG_VBusDischargeEnable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_OTG_VBusDischargeDisable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_OTG_VBusDischargeDisable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsOTG_VbusDischarge(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsOTG_VbusDischarge_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ActivityPending(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ActivityPending_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsActivityPending(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsActivityPending_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_SleepGuardEnable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_SleepGuardEnable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_SleepGuardDisable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_SleepGuardDisable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsSleepEntryGuard(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsSleepEntryGuard_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ModuleIsBusy(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ModuleIsBusy_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsModuleBusy(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsModuleBusy_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_SuspendEnable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_SuspendEnable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_SuspendDisable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_SuspendDisable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsSuspend(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsSuspend_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_Enable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_Enable_32Bit16Bit(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_Disable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_Disable_32Bit16Bit(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsModulePower(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsModulePower_32Bit16Bit(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_InterruptFlagSet(USB_MODULE_ID index, USB_INTERRUPTS interruptFlag)
{
    switch (index) {
        case USB_ID_1 :
            USB_InterruptFlagSet_Default(index, interruptFlag);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_InterruptFlagClear(USB_MODULE_ID index, USB_INTERRUPTS interruptFlag)
{
    switch (index) {
        case USB_ID_1 :
            USB_InterruptFlagClear_Default(index, interruptFlag);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_InterruptFlagGet(USB_MODULE_ID index, USB_INTERRUPTS interruptFlag)
{
    switch (index) {
        case USB_ID_1 :
            return USB_InterruptFlagGet_Default(index, interruptFlag);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API USB_INTERRUPTS PLIB_USB_InterruptFlagAllGet(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_InterruptFlagAllGet_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (USB_INTERRUPTS)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsGEN_InterruptStatus(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsGEN_InterruptStatus_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_InterruptEnable(USB_MODULE_ID index, USB_INTERRUPTS interruptFlag)
{
    switch (index) {
        case USB_ID_1 :
            USB_InterruptEnable_Default(index, interruptFlag);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_InterruptDisable(USB_MODULE_ID index, USB_INTERRUPTS interruptFlag)
{
    switch (index) {
        case USB_ID_1 :
            USB_InterruptDisable_Default(index, interruptFlag);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_InterruptIsEnabled(USB_MODULE_ID index, USB_INTERRUPTS interruptFlag)
{
    switch (index) {
        case USB_ID_1 :
            return USB_InterruptIsEnabled_Default(index, interruptFlag);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsGEN_Interrupt(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsGEN_Interrupt_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_AllInterruptEnable(USB_MODULE_ID index, USB_INTERRUPTS usbInterruptsFlag, USB_ERROR_INTERRUPTS usbErrorInterruptsFlag, USB_OTG_INTERRUPTS otgInterruptFlag)
{
    switch (index) {
        case USB_ID_1 :
            USB_AllInterruptEnable_Default(index, usbInterruptsFlag, usbErrorInterruptsFlag, otgInterruptFlag);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API USB_INTERRUPTS PLIB_USB_InterruptEnableGet(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_InterruptEnableGet_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (USB_INTERRUPTS)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsALL_Interrupt(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsALL_Interrupt_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_ErrorInterruptFlagSet(USB_MODULE_ID index, USB_ERROR_INTERRUPTS interruptFlag)
{
    switch (index) {
        case USB_ID_1 :
            USB_ErrorInterruptFlagSet_Default(index, interruptFlag);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_ErrorInterruptFlagClear(USB_MODULE_ID index, USB_ERROR_INTERRUPTS interruptFlag)
{
    switch (index) {
        case USB_ID_1 :
            USB_ErrorInterruptFlagClear_Default(index, interruptFlag);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ErrorInterruptFlagGet(USB_MODULE_ID index, USB_ERROR_INTERRUPTS interruptFlag)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ErrorInterruptFlagGet_Default(index, interruptFlag);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API USB_ERROR_INTERRUPTS PLIB_USB_ErrorInterruptFlagAllGet(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ErrorInterruptFlagAllGet_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (USB_ERROR_INTERRUPTS)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsERR_InterruptStatus(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsERR_InterruptStatus_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_ErrorInterruptEnable(USB_MODULE_ID index, USB_ERROR_INTERRUPTS interruptFlag)
{
    switch (index) {
        case USB_ID_1 :
            USB_ErrorInterruptEnable_Default(index, interruptFlag);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_ErrorInterruptDisable(USB_MODULE_ID index, USB_ERROR_INTERRUPTS interruptFlag)
{
    switch (index) {
        case USB_ID_1 :
            USB_ErrorInterruptDisable_Default(index, interruptFlag);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ErrorInterruptIsEnabled(USB_MODULE_ID index, USB_INTERRUPTS interruptFlag)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ErrorInterruptIsEnabled_Default(index, interruptFlag);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsERR_Interrupt(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsERR_Interrupt_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API uint8_t PLIB_USB_LastTransactionEndPtGet(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_LastTransactionEndPtGet_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (uint8_t)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsLastEndpoint(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsLastEndpoint_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API USB_BUFFER_DIRECTION PLIB_USB_LastTransactionDirectionGet(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_LastTransactionDirectionGet_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (USB_BUFFER_DIRECTION)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsLastDirection(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsLastDirection_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API USB_PING_PONG_STATE PLIB_USB_LastTransactionPingPongStateGet(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_LastTransactionPingPongStateGet_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (USB_PING_PONG_STATE)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsLastPingPong(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsLastPingPong_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_LastTransactionDetailsGet(USB_MODULE_ID index, USB_BUFFER_DIRECTION* direction, USB_PING_PONG_STATE* pingpong, uint8_t* endpoint)
{
    switch (index) {
        case USB_ID_1 :
            USB_LastTransactionDetailsGet_Default(index, direction, pingpong, endpoint);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsLastTransactionDetails(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsLastTransactionDetails_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_JStateIsActive(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_JStateIsActive_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsLiveJState(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsLiveJState_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_SE0InProgress(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_SE0InProgress_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsLiveSingleEndedZero(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsLiveSingleEndedZero_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_PacketTransferIsDisabled(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_PacketTransferIsDisabled_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_PacketTransferEnable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_PacketTransferEnable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_PacketTransferDisable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_PacketTransferDisable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsPacketTransfer(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsPacketTransfer_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_IsBusyWithToken(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_IsBusyWithToken_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsHostBusyWithToken(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsHostBusyWithToken_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_ResetSignalEnable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_ResetSignalEnable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_ResetSignalDisable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_ResetSignalDisable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsHostGeneratesReset(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsHostGeneratesReset_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_OperatingModeSelect(USB_MODULE_ID index, USB_OPMODES opMode)
{
    switch (index) {
        case USB_ID_1 :
            USB_OperatingModeSelect_Default(index, opMode);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsOpModeSelect(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsOpModeSelect_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_ResumeSignalingEnable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_ResumeSignalingEnable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_ResumeSignalingDisable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_ResumeSignalingDisable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsResumeSignaling(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsResumeSignaling_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_PingPongFreeze(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_PingPongFreeze_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_PingPongUnfreeze(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_PingPongUnfreeze_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_PingPongReset(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_PingPongReset_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsBufferFreeze(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsBufferFreeze_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_SOFEnable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_SOFEnable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_SOFDisable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_SOFDisable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsStartOfFrames(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsStartOfFrames_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_TokenSpeedSelect(USB_MODULE_ID index, USB_TOKEN_SPEED tokenSpeed)
{
    switch (index) {
        case USB_ID_1 :
            USB_TokenSpeedSelect_Default(index, tokenSpeed);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsNextTokenSpeed(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsNextTokenSpeed_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_DeviceAddressSet(USB_MODULE_ID index, uint8_t address)
{
    switch (index) {
        case USB_ID_1 :
            USB_DeviceAddressSet_Default(index, address);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API uint8_t PLIB_USB_DeviceAddressGet(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_DeviceAddressGet_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (uint8_t)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsDeviceAddress(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsDeviceAddress_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API uint16_t PLIB_USB_FrameNumberGet(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_FrameNumberGet_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (uint16_t)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsFrameNumber(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsFrameNumber_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API USB_PID PLIB_USB_TokenPIDGet(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_TokenPIDGet_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (USB_PID)0;
    }
}

PLIB_INLINE_API void PLIB_USB_TokenPIDSet(USB_MODULE_ID index, USB_PID pidValue)
{
    switch (index) {
        case USB_ID_1 :
            USB_TokenPIDSet_Default(index, pidValue);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_TokenSend(USB_MODULE_ID index, USB_PID pidValue, uint8_t endpoint, uint8_t deviceAddress, bool isLowSpeed)
{
    switch (index) {
        case USB_ID_1 :
            USB_TokenSend_Default(index, pidValue, endpoint, deviceAddress, isLowSpeed);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsTokenPID(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsTokenPID_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API uint8_t PLIB_USB_TokenEPGet(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_TokenEPGet_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (uint8_t)0;
    }
}

PLIB_INLINE_API void PLIB_USB_TokenEPSet(USB_MODULE_ID index, uint8_t epValue)
{
    switch (index) {
        case USB_ID_1 :
            USB_TokenEPSet_Default(index, epValue);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsTokenEP(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsTokenEP_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API uint8_t PLIB_USB_SOFThresholdGet(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_SOFThresholdGet_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (uint8_t)0;
    }
}

PLIB_INLINE_API void PLIB_USB_SOFThresholdSet(USB_MODULE_ID index, uint8_t threshold)
{
    switch (index) {
        case USB_ID_1 :
            USB_SOFThresholdSet_Default(index, threshold);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsSOFThreshold(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsSOFThreshold_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void* PLIB_USB_BDTBaseAddressGet(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_BDTBaseAddressGet_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (void*)0;
    }
}

PLIB_INLINE_API void PLIB_USB_BDTBaseAddressSet(USB_MODULE_ID index, void* address)
{
    switch (index) {
        case USB_ID_1 :
            USB_BDTBaseAddressSet_Default(index, address);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsBDTBaseAddress(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsBDTBaseAddress_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_EyePatternDisable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_EyePatternDisable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_EyePatternEnable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_EyePatternEnable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsEyePattern(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsEyePattern_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_StopInIdleEnable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_StopInIdleEnable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_StopInIdleDisable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_StopInIdleDisable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsStopInIdle(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsStopInIdle_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_AutoSuspendDisable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_AutoSuspendDisable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_AutoSuspendEnable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_AutoSuspendEnable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsAutomaticSuspend(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsAutomaticSuspend_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_USB_PingPongModeSelect(USB_MODULE_ID index, USB_PING_PONG_MODE ppConfig)
{
    switch (index) {
        case USB_ID_1 :
            USB_PingPongModeSelect_Unsupported(index, ppConfig);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API USB_PING_PONG_MODE _PLIB_UNSUPPORTED PLIB_USB_PingPongModeGet(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_PingPongModeGet_Unsupported(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (USB_PING_PONG_MODE)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsPingPongMode(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsPingPongMode_Unsupported(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_USB_UOEMonitorEnable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_UOEMonitorEnable_Unsupported(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_USB_UOEMonitorDisable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_UOEMonitorDisable_Unsupported(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsUOEMonitor(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsUOEMonitor_Unsupported(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_USB_OnChipPullUpEnable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_OnChipPullUpEnable_Unsupported(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_USB_OnChipPullUpDisable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_OnChipPullUpDisable_Unsupported(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsOnChipPullup(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsOnChipPullup_Unsupported(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_USB_TransceiverEnable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_TransceiverEnable_Unsupported(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_USB_TransceiverDisable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_TransceiverDisable_Unsupported(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsOnChipTransceiver(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsOnChipTransceiver_Unsupported(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_USB_FullSpeedEnable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_FullSpeedEnable_Unsupported(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_USB_FullSpeedDisable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_FullSpeedDisable_Unsupported(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsSpeedControl(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsSpeedControl_Unsupported(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_EP0LSDirectConnectEnable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_EP0LSDirectConnectEnable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_EP0LSDirectConnectDisable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_EP0LSDirectConnectDisable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsEP0LowSpeedConnect(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsEP0LowSpeedConnect_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_EP0NakRetryEnable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_EP0NakRetryEnable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_EP0NakRetryDisable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_EP0NakRetryDisable_Default(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsEP0NAKRetry(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsEP0NAKRetry_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_EPnTxSelect(USB_MODULE_ID index, uint8_t epValue, USB_EP_TXRX epTxRx)
{
    switch (index) {
        case USB_ID_1 :
            USB_EPnTxSelect_Default(index, epValue, epTxRx);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_EPnRxSelect(USB_MODULE_ID index, uint8_t epValue, USB_EP_TXRX epTxRx)
{
    switch (index) {
        case USB_ID_1 :
            USB_EPnRxSelect_Default(index, epValue, epTxRx);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_EPnTxRxSelect(USB_MODULE_ID index, uint8_t epValue, USB_EP_TXRX epTxRx)
{
    switch (index) {
        case USB_ID_1 :
            USB_EPnTxRxSelect_Default(index, epValue, epTxRx);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsEPnTxRx(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsEPnTxRx_Default(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_EPnRxEnable(USB_MODULE_ID index, uint8_t endpoint)
{
    switch (index) {
        case USB_ID_1 :
            USB_EPnRxEnable_PIC32(index, endpoint);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_EPnRxDisable(USB_MODULE_ID index, uint8_t endpoint)
{
    switch (index) {
        case USB_ID_1 :
            USB_EPnRxDisable_PIC32(index, endpoint);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_EPnTxEnable(USB_MODULE_ID index, uint8_t endpoint)
{
    switch (index) {
        case USB_ID_1 :
            USB_EPnTxEnable_PIC32(index, endpoint);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_EPnTxDisable(USB_MODULE_ID index, uint8_t endpoint)
{
    switch (index) {
        case USB_ID_1 :
            USB_EPnTxDisable_PIC32(index, endpoint);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_EPnHandshakeEnable(USB_MODULE_ID index, uint8_t epValue)
{
    switch (index) {
        case USB_ID_1 :
            USB_EPnHandshakeEnable_PIC32(index, epValue);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_EPnHandshakeDisable(USB_MODULE_ID index, uint8_t epValue)
{
    switch (index) {
        case USB_ID_1 :
            USB_EPnHandshakeDisable_PIC32(index, epValue);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_EPnControlTransferEnable(USB_MODULE_ID index, uint8_t epValue)
{
    switch (index) {
        case USB_ID_1 :
            USB_EPnControlTransferEnable_PIC32(index, epValue);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_EPnControlTransferDisable(USB_MODULE_ID index, uint8_t epValue)
{
    switch (index) {
        case USB_ID_1 :
            USB_EPnControlTransferDisable_PIC32(index, epValue);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_EPnAttributesSet(USB_MODULE_ID index, uint8_t epValue, int direction, bool isControl, bool handshake)
{
    switch (index) {
        case USB_ID_1 :
            USB_EPnAttributesSet_PIC32(index, epValue, direction, isControl, handshake);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_EPnDirectionDisable(USB_MODULE_ID index, uint8_t epValue, int direction)
{
    switch (index) {
        case USB_ID_1 :
            USB_EPnDirectionDisable_PIC32(index, epValue, direction);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_EPnAttributesClear(USB_MODULE_ID index, uint8_t epValue)
{
    switch (index) {
        case USB_ID_1 :
            USB_EPnAttributesClear_PIC32(index, epValue);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_EPnIsStalled(USB_MODULE_ID index, uint8_t epValue)
{
    switch (index) {
        case USB_ID_1 :
            return USB_EPnIsStalled_PIC32(index, epValue);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_EPnStallClear(USB_MODULE_ID index, uint8_t epValue)
{
    switch (index) {
        case USB_ID_1 :
            USB_EPnStallClear_PIC32(index, epValue);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_EP0HostSetup(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            USB_EP0HostSetup_PIC32(index);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsEPnRxEnable(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsEPnRxEnable_PIC32(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void* PLIB_USB_BufferAddressGet(USB_MODULE_ID index, void* pBDT, USB_PING_PONG_MODE ppMode, uint8_t epValue, USB_BUFFER_DIRECTION bufferDirection, USB_BUFFER_PING_PONG bufferPingPong)
{
    switch (index) {
        case USB_ID_1 :
            return USB_BufferAddressGet_PIC32(index, pBDT, ppMode, epValue, bufferDirection, bufferPingPong);
        case USB_NUMBER_OF_MODULES :
        default :
            return (void*)0;
    }
}

PLIB_INLINE_API void PLIB_USB_BufferAddressSet(USB_MODULE_ID index, void* pBDT, USB_PING_PONG_MODE ppMode, uint8_t epValue, USB_BUFFER_DIRECTION bufferDirection, USB_BUFFER_PING_PONG bufferPingPong, void* bufferAddress)
{
    switch (index) {
        case USB_ID_1 :
            USB_BufferAddressSet_PIC32(index, pBDT, ppMode, epValue, bufferDirection, bufferPingPong, bufferAddress);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API uint16_t PLIB_USB_BufferByteCountGet(USB_MODULE_ID index, void* pBDT, USB_PING_PONG_MODE ppMode, uint8_t epValue, USB_BUFFER_DIRECTION bufferDirection, USB_BUFFER_PING_PONG bufferPingPong)
{
    switch (index) {
        case USB_ID_1 :
            return USB_BufferByteCountGet_PIC32(index, pBDT, ppMode, epValue, bufferDirection, bufferPingPong);
        case USB_NUMBER_OF_MODULES :
        default :
            return (uint16_t)0;
    }
}

PLIB_INLINE_API void PLIB_USB_BufferByteCountSet(USB_MODULE_ID index, void* pBDT, USB_PING_PONG_MODE ppMode, uint8_t epValue, USB_BUFFER_DIRECTION bufferDirection, USB_BUFFER_PING_PONG bufferPingPong, uint16_t bufferByteCount)
{
    switch (index) {
        case USB_ID_1 :
            USB_BufferByteCountSet_PIC32(index, pBDT, ppMode, epValue, bufferDirection, bufferPingPong, bufferByteCount);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_BufferCancelReleaseToUSB(USB_MODULE_ID index, void* pBDT, USB_PING_PONG_MODE ppMode, uint8_t epValue, USB_BUFFER_DIRECTION bufferDirection, USB_BUFFER_PING_PONG bufferPingPong)
{
    switch (index) {
        case USB_ID_1 :
            USB_BufferCancelReleaseToUSB_PIC32(index, pBDT, ppMode, epValue, bufferDirection, bufferPingPong);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_BufferAllCancelReleaseToUSB(USB_MODULE_ID index, void* pBDT, USB_PING_PONG_MODE ppMode, int nEndpoints)
{
    switch (index) {
        case USB_ID_1 :
            USB_BufferAllCancelReleaseToUSB_PIC32(index, pBDT, ppMode, nEndpoints);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_BufferClearAll(USB_MODULE_ID index, void* pBDT, USB_PING_PONG_MODE ppMode, uint8_t epValue, USB_BUFFER_DIRECTION bufferDirection, USB_BUFFER_PING_PONG bufferPingPong)
{
    switch (index) {
        case USB_ID_1 :
            USB_BufferClearAll_PIC32(index, pBDT, ppMode, epValue, bufferDirection, bufferPingPong);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API USB_BUFFER_DATA01 PLIB_USB_BufferDataToggleGet(USB_MODULE_ID index, void* pBDT, USB_PING_PONG_MODE ppMode, uint8_t epValue, USB_BUFFER_DIRECTION bufferDirection, USB_BUFFER_PING_PONG bufferPingPong)
{
    switch (index) {
        case USB_ID_1 :
            return USB_BufferDataToggleGet_PIC32(index, pBDT, ppMode, epValue, bufferDirection, bufferPingPong);
        case USB_NUMBER_OF_MODULES :
        default :
            return (USB_BUFFER_DATA01)0;
    }
}

PLIB_INLINE_API void PLIB_USB_BufferDataToggleSelect(USB_MODULE_ID index, void* pBDT, USB_PING_PONG_MODE ppMode, uint8_t epValue, USB_BUFFER_DIRECTION bufferDirection, USB_BUFFER_PING_PONG bufferPingPong, USB_BUFFER_DATA01 bufferData01)
{
    switch (index) {
        case USB_ID_1 :
            USB_BufferDataToggleSelect_PIC32(index, pBDT, ppMode, epValue, bufferDirection, bufferPingPong, bufferData01);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_BufferDataToggleSyncEnable(USB_MODULE_ID index, void* pBDT, USB_PING_PONG_MODE ppMode, uint8_t epValue, USB_BUFFER_DIRECTION bufferDirection, USB_BUFFER_PING_PONG bufferPingPong)
{
    switch (index) {
        case USB_ID_1 :
            USB_BufferDataToggleSyncEnable_PIC32(index, pBDT, ppMode, epValue, bufferDirection, bufferPingPong);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_BufferDataToggleSyncDisable(USB_MODULE_ID index, void* pBDT, USB_PING_PONG_MODE ppMode, uint8_t epValue, USB_BUFFER_DIRECTION bufferDirection, USB_BUFFER_PING_PONG bufferPingPong)
{
    switch (index) {
        case USB_ID_1 :
            USB_BufferDataToggleSyncDisable_PIC32(index, pBDT, ppMode, epValue, bufferDirection, bufferPingPong);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API uint8_t PLIB_USB_BufferIndexGet(USB_MODULE_ID index, USB_PING_PONG_MODE ppMode, uint8_t epValue, USB_BUFFER_DIRECTION bufferDirection, USB_BUFFER_PING_PONG bufferPingPong)
{
    switch (index) {
        case USB_ID_1 :
            return USB_BufferIndexGet_PIC32(index, ppMode, epValue, bufferDirection, bufferPingPong);
        case USB_NUMBER_OF_MODULES :
        default :
            return (uint8_t)0;
    }
}

PLIB_INLINE_API void PLIB_USB_BufferPIDBitsClear(USB_MODULE_ID index, void* pBDT, USB_PING_PONG_MODE ppMode, uint8_t epValue, USB_BUFFER_DIRECTION bufferDirection, USB_BUFFER_PING_PONG bufferPingPong)
{
    switch (index) {
        case USB_ID_1 :
            USB_BufferPIDBitsClear_PIC32(index, pBDT, ppMode, epValue, bufferDirection, bufferPingPong);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API uint8_t PLIB_USB_BufferPIDGet(USB_MODULE_ID index, void* pBDT, USB_PING_PONG_MODE ppMode, uint8_t epValue, USB_BUFFER_DIRECTION bufferDirection, USB_BUFFER_PING_PONG bufferPingPong)
{
    switch (index) {
        case USB_ID_1 :
            return USB_BufferPIDGet_PIC32(index, pBDT, ppMode, epValue, bufferDirection, bufferPingPong);
        case USB_NUMBER_OF_MODULES :
        default :
            return (uint8_t)0;
    }
}

PLIB_INLINE_API bool PLIB_USB_BufferReleasedToSW(USB_MODULE_ID index, void* pBDT, USB_PING_PONG_MODE ppMode, uint8_t epValue, USB_BUFFER_DIRECTION bufferDirection, USB_BUFFER_PING_PONG bufferPingPong)
{
    switch (index) {
        case USB_ID_1 :
            return USB_BufferReleasedToSW_PIC32(index, pBDT, ppMode, epValue, bufferDirection, bufferPingPong);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_BufferReleaseToUSB(USB_MODULE_ID index, void* pBDT, USB_PING_PONG_MODE ppMode, uint8_t epValue, USB_BUFFER_DIRECTION bufferDirection, USB_BUFFER_PING_PONG bufferPingPong)
{
    switch (index) {
        case USB_ID_1 :
            USB_BufferReleaseToUSB_PIC32(index, pBDT, ppMode, epValue, bufferDirection, bufferPingPong);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_BufferSchedule(USB_MODULE_ID index, void* pBDT, USB_PING_PONG_MODE ppMode, uint8_t epValue, USB_BUFFER_DIRECTION bufferDirection, USB_BUFFER_PING_PONG bufferPingPong, void* bufferAddress, int16_t bufferByteCount, USB_BUFFER_SCHEDULE_DATA01 bufferData01)
{
    switch (index) {
        case USB_ID_1 :
            USB_BufferSchedule_PIC32(index, pBDT, ppMode, epValue, bufferDirection, bufferPingPong, bufferAddress, bufferByteCount, bufferData01);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_BufferStallDisable(USB_MODULE_ID index, void* pBDT, USB_PING_PONG_MODE ppMode, uint8_t epValue, USB_BUFFER_DIRECTION bufferDirection, USB_BUFFER_PING_PONG bufferPingPong)
{
    switch (index) {
        case USB_ID_1 :
            USB_BufferStallDisable_PIC32(index, pBDT, ppMode, epValue, bufferDirection, bufferPingPong);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_BufferStallEnable(USB_MODULE_ID index, void* pBDT, USB_PING_PONG_MODE ppMode, uint8_t epValue, USB_BUFFER_DIRECTION bufferDirection, USB_BUFFER_PING_PONG bufferPingPong)
{
    switch (index) {
        case USB_ID_1 :
            USB_BufferStallEnable_PIC32(index, pBDT, ppMode, epValue, bufferDirection, bufferPingPong);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_BufferStallGet(USB_MODULE_ID index, void* pBDT, USB_PING_PONG_MODE ppMode, uint8_t epValue, USB_BUFFER_DIRECTION bufferDirection, USB_BUFFER_PING_PONG bufferPingPong)
{
    switch (index) {
        case USB_ID_1 :
            return USB_BufferStallGet_PIC32(index, pBDT, ppMode, epValue, bufferDirection, bufferPingPong);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_USB_BufferEP0RxStatusInitialize(USB_MODULE_ID index, void* pBDT, USB_PING_PONG_MODE ppMode, USB_BUFFER_PING_PONG pingpong, uint16_t bufferByteCount)
{
    switch (index) {
        case USB_ID_1 :
            USB_BufferEP0RxStatusInitialize_PIC32(index, pBDT, ppMode, pingpong, bufferByteCount);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_USB_BufferClearAllDTSEnable(USB_MODULE_ID index, void* pBDT, USB_PING_PONG_MODE ppMode, uint8_t epValue, USB_BUFFER_DIRECTION bufferDirection)
{
    switch (index) {
        case USB_ID_1 :
            USB_BufferClearAllDTSEnable_PIC32(index, pBDT, ppMode, epValue, bufferDirection);
            break;
        case USB_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_USB_ExistsBDTFunctions(USB_MODULE_ID index)
{
    switch (index) {
        case USB_ID_1 :
            return USB_ExistsBDTFunctions_PIC32(index);
        case USB_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

#endif
