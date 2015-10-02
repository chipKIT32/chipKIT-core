/* Created by plibgen $Revision: 1.31 $ */

#ifndef _OSC_P32MZ1024ECH064_H
#define _OSC_P32MZ1024ECH064_H

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

    OSC_ID_0 = 0,
    OSC_NUMBER_OF_MODULES

} OSC_MODULE_ID;

typedef enum {

    OSC_ON_WAIT_IDLE = 0x00,
    OSC_ON_WAIT_SLEEP = 0x01

} OSC_OPERATION_ON_WAIT;

typedef enum {

    OSC_FRC_DIV_256 = 0x07,
    OSC_FRC_DIV_64 = 0x06,
    OSC_FRC_DIV_32 = 0x05,
    OSC_FRC_DIV_16 = 0x04,
    OSC_FRC_DIV_8 = 0x03,
    OSC_FRC_DIV_4 = 0x02,
    OSC_FRC_DIV_2 = 0x01,
    OSC_FRC_DIV_1 = 0x00

} OSC_FRC_DIV;

typedef enum {

    OSC_FRC_WITH_PLL = 0x01,
    OSC_PRIMARY = 0x02,
    OSC_PRIMARY_WITH_PLL = 0x03,
    OSC_SECONDARY = 0x04,
    OSC_LPRC = 0x05,
    OSC_BFRC = 0x06,
    OSC_FRC_BY_FRCDIV = 0x00

} OSC_SYS_TYPE;

typedef enum {

    OSC_REF_BASECLOCK_SYSCLK = 0x00,
    OSC_REF_BASECLOCK_PBCLK = 0x01,
    OSC_REF_BASECLOCK_PRIMARY = 0x02,
    OSC_REF_BASECLOCK_FRC = 0x03,
    OSC_REF_BASECLOCK_LPRC = 0x04,
    OSC_REF_BASECLOCK_SOSC = 0x05,
    OSC_REF_BASECLOCK_SYSPLLOUT = 0x07,
    OSC_REF_BASECLOCK_EXT = 0x08,
    OSC_REF_BASECLOCK_BFRC = 0x09

} OSC_REF_BASECLOCK;

typedef enum {

    OSC_USBCLOCK_SOURCE_NONE

} OSC_USBCLOCK_SOURCE;

typedef enum {

    OSC_SYSPLL_OUT_DIV_32 = 0x05,
    OSC_SYSPLL_OUT_DIV_16 = 0x04,
    OSC_SYSPLL_OUT_DIV_8 = 0x03,
    OSC_SYSPLL_OUT_DIV_4 = 0x02,
    OSC_SYSPLL_OUT_DIV_2 = 0x01

} OSC_SYSPLL_OUT_DIV;

typedef enum {

    OSC_PLL_SYSTEM = 0x00,
    OSC_PLL_USB = 0x01

} OSC_PLL_SELECT;

typedef enum {

    OSC_PERIPHERAL_BUS_1 = 0x00,
    OSC_PERIPHERAL_BUS_2 = 0x01,
    OSC_PERIPHERAL_BUS_3 = 0x02,
    OSC_PERIPHERAL_BUS_4 = 0x03,
    OSC_PERIPHERAL_BUS_5 = 0x04,
    OSC_PERIPHERAL_BUS_7 = 0x06,
    OSC_PERIPHERAL_BUS_8 = 0x07

} OSC_PERIPHERAL_BUS;

typedef enum {

    OSC_REFERENCE_1 = 0x00,
    OSC_REFERENCE_2 = 0x01,
    OSC_REFERENCE_3 = 0x02,
    OSC_REFERENCE_4 = 0x03

} OSC_REFERENCE;

typedef enum {

    OSC_SYSPLL_IN_DIV_8 = 0x07,
    OSC_SYSPLL_IN_DIV_7 = 0x06,
    OSC_SYSPLL_IN_DIV_6 = 0x05,
    OSC_SYSPLL_IN_DIV_5 = 0x04,
    OSC_SYSPLL_IN_DIV_4 = 0x03,
    OSC_SYSPLL_IN_DIV_3 = 0x02,
    OSC_SYSPLL_IN_DIV_2 = 0x01,
    OSC_SYSPLL_IN_DIV_1 = 0x00

} OSC_SYSPLL_IN_DIV;

typedef enum {

    OSC_SYSPLL_FREQ_RANGE_34M_TO_68M = 0x05,
    OSC_SYSPLL_FREQ_RANGE_21M_TO_42M = 0x04,
    OSC_SYSPLL_FREQ_RANGE_13M_TO_26M = 0x03,
    OSC_SYSPLL_FREQ_RANGE_8M_TO_16M = 0x02,
    OSC_SYSPLL_FREQ_RANGE_5M_TO_10M = 0x01,
    OSC_SYSPLL_FREQ_RANGE_BYPASS = 0x00

} OSC_SYSPLL_FREQ_RANGE;

typedef enum {

    OSC_SYSPLL_IN_CLK_SOURCE_FRC = 0x1,
    OSC_SYSPLL_IN_CLK_SOURCE_PRIMARY = 0x0

} OSC_SYSPLL_IN_CLK_SOURCE;

typedef enum {

    OSC_SLEEP_TO_STARTUP_CLK_TYPE_NONE

} OSC_SLEEP_TO_STARTUP_CLK_TYPE;

typedef enum {

    OSC_CLOCK_ID_NONE

} OSC_CLOCK_ID;

typedef enum {

    OSC_CLOCK_SLEW_TYPE_NONE

} OSC_CLOCK_SLEW_TYPE;

PLIB_INLINE SFR_TYPE* _OSC_OSC_SWITCH_INIT_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &OSCCON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_SECONDARY_ENABLE_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &OSCCON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_CLOCK_FAIL_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &OSCCON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_ON_WAIT_ACTION_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &OSCCON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_LOCK_STATUS_SYS_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &OSCCON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_LOCK_STATUS_USB_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &OSCCON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_CLOCK_LOCK_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &OSCCON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_SELECTMZ_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &OSCCON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_CURRENT_GET_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &OSCCON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_SECONDARY_READY_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &OSCCON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_DREAM_MODE_ENABLE_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &OSCCON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_FRC_DIVISOR_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &OSCCON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_FRC_TUNING_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &OSCTUN;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_REGISTER_LOCK_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &SYSKEY;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_BASECLK_SELECT_1_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO1CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_CHANGE_ACTIVE_1_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO1CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_BASECLK_CHANGE_1_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO1CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_STOPINSLEEP_1_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO1CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_OUTPUT_ENABLE_1_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO1CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_STOPINIDLE_1_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO1CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_CLK_ENABLE_1_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO1CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_CLK_OUTPUT_DIV_1_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO1CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_BASECLK_SELECT_2_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO2CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_CHANGE_ACTIVE_2_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO2CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_BASECLK_CHANGE_2_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO2CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_STOPINSLEEP_2_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO2CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_OUTPUT_ENABLE_2_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO2CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_STOPINIDLE_2_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO2CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_CLK_ENABLE_2_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO2CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_CLK_OUTPUT_DIV_2_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO2CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_BASECLK_SELECT_3_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO3CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_CHANGE_ACTIVE_3_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO3CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_BASECLK_CHANGE_3_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO3CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_STOPINSLEEP_3_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO3CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_OUTPUT_ENABLE_3_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO3CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_STOPINIDLE_3_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO3CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_CLK_ENABLE_3_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO3CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_CLK_OUTPUT_DIV_3_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO3CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_BASECLK_SELECT_4_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO4CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_CHANGE_ACTIVE_4_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO4CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_BASECLK_CHANGE_4_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO4CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_STOPINSLEEP_4_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO4CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_OUTPUT_ENABLE_4_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO4CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_STOPINIDLE_4_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO4CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_CLK_ENABLE_4_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO4CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_CLK_OUTPUT_DIV_4_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO4CON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_OUTPUT_TRIM_1_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO1TRIM;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_OUTPUT_TRIM_2_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO2TRIM;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_OUTPUT_TRIM_3_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO3TRIM;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_REF_OUTPUT_TRIM_4_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &REFO4TRIM;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_SYSPLL_FREQ_RANGE_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &SPLLCON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_SYSPLL_INPUT_SOURCE_CLOCK_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &SPLLCON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_INPUT_DIVISOR_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &SPLLCON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_SYSPLL_MULTIPLIER_1_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &SPLLCON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_OUTPUT_DIVISOR_2_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &SPLLCON;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_PB_DIVISOR_1_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &PB1DIV;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_PB_CLOCK_READY_1_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &PB1DIV;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_PB_DIVISOR_2_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &PB2DIV;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_PB_CLOCK_READY_2_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &PB2DIV;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_PB_CLOCK_ENABLE_2_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &PB2DIV;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_PB_DIVISOR_3_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &PB3DIV;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_PB_CLOCK_READY_3_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &PB3DIV;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_PB_CLOCK_ENABLE_3_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &PB3DIV;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_PB_DIVISOR_4_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &PB4DIV;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_PB_CLOCK_READY_4_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &PB4DIV;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_PB_CLOCK_ENABLE_4_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &PB4DIV;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_PB_DIVISOR_5_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &PB5DIV;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_PB_CLOCK_READY_5_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &PB5DIV;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_PB_CLOCK_ENABLE_5_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &PB5DIV;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_PB_DIVISOR_7_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &PB7DIV;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_PB_CLOCK_READY_7_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &PB7DIV;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_PB_CLOCK_ENABLE_7_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &PB7DIV;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_PB_DIVISOR_8_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &PB8DIV;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_PB_CLOCK_READY_8_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &PB8DIV;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_TYPE* _OSC_OSC_PB_CLOCK_ENABLE_8_VREG(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return &PB8DIV;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_TYPE*)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_SWITCH_INIT_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_OSWEN_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_SECONDARY_ENABLE_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_SOSCEN_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_CLOCK_FAIL_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_CF_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_ON_WAIT_ACTION_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_SLPEN_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_LOCK_STATUS_SYS_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_SLOCK_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_LOCK_STATUS_USB_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_ULOCK_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_CLOCK_LOCK_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_CLKLOCK_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_SELECTMZ_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_NOSC_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_CURRENT_GET_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_COSC_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_SECONDARY_READY_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_SOSCRDY_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_DREAM_MODE_ENABLE_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_DRMEN_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_FRC_DIVISOR_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_FRCDIV_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_FRC_TUNING_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCTUN_TUN_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_REGISTER_LOCK_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return (SFR_DATA)-1;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_SELECT_1_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_ROSEL_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CHANGE_ACTIVE_1_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_ACTIVE_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_CHANGE_1_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_DIVSWEN_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINSLEEP_1_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_RSLP_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_ENABLE_1_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_OE_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINIDLE_1_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_SIDL_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_ENABLE_1_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_ON_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_OUTPUT_DIV_1_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_RODIV_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_SELECT_2_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_ROSEL_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CHANGE_ACTIVE_2_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_ACTIVE_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_CHANGE_2_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_DIVSWEN_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINSLEEP_2_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_RSLP_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_ENABLE_2_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_OE_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINIDLE_2_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_SIDL_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_ENABLE_2_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_ON_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_OUTPUT_DIV_2_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_RODIV_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_SELECT_3_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_ROSEL_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CHANGE_ACTIVE_3_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_ACTIVE_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_CHANGE_3_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_DIVSWEN_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINSLEEP_3_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_RSLP_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_ENABLE_3_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_OE_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINIDLE_3_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_SIDL_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_ENABLE_3_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_ON_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_OUTPUT_DIV_3_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_RODIV_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_SELECT_4_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_ROSEL_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CHANGE_ACTIVE_4_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_ACTIVE_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_CHANGE_4_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_DIVSWEN_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINSLEEP_4_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_RSLP_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_ENABLE_4_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_OE_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINIDLE_4_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_SIDL_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_ENABLE_4_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_ON_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_OUTPUT_DIV_4_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_RODIV_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_TRIM_1_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1TRIM_ROTRIM_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_TRIM_2_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2TRIM_ROTRIM_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_TRIM_3_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3TRIM_ROTRIM_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_TRIM_4_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4TRIM_ROTRIM_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_SYSPLL_FREQ_RANGE_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _SPLLCON_PLLRANGE_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_SYSPLL_INPUT_SOURCE_CLOCK_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _SPLLCON_PLLICLK_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_INPUT_DIVISOR_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _SPLLCON_PLLIDIV_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_SYSPLL_MULTIPLIER_1_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _SPLLCON_PLLMULT_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_OUTPUT_DIVISOR_2_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _SPLLCON_PLLODIV_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_DIVISOR_1_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB1DIV_PBDIV_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_READY_1_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB1DIV_PBDIVRDY_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_DIVISOR_2_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB2DIV_PBDIV_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_READY_2_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB2DIV_PBDIVRDY_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_ENABLE_2_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB2DIV_ON_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_DIVISOR_3_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB3DIV_PBDIV_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_READY_3_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB3DIV_PBDIVRDY_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_ENABLE_3_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB3DIV_ON_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_DIVISOR_4_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB4DIV_PBDIV_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_READY_4_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB4DIV_PBDIVRDY_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_ENABLE_4_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB4DIV_ON_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_DIVISOR_5_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB5DIV_PBDIV_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_READY_5_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB5DIV_PBDIVRDY_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_ENABLE_5_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB5DIV_ON_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_DIVISOR_7_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB7DIV_PBDIV_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_READY_7_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB7DIV_PBDIVRDY_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_ENABLE_7_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB7DIV_ON_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_DIVISOR_8_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB8DIV_PBDIV_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_READY_8_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB8DIV_PBDIVRDY_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_ENABLE_8_MASK(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB8DIV_ON_MASK;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_SWITCH_INIT_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_OSWEN_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_SECONDARY_ENABLE_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_SOSCEN_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_CLOCK_FAIL_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_CF_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_ON_WAIT_ACTION_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_SLPEN_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_LOCK_STATUS_SYS_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_SLOCK_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_LOCK_STATUS_USB_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_ULOCK_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_CLOCK_LOCK_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_CLKLOCK_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_SELECTMZ_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_NOSC_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_CURRENT_GET_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_COSC_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_SECONDARY_READY_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_SOSCRDY_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_DREAM_MODE_ENABLE_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_DRMEN_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_FRC_DIVISOR_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_FRCDIV_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_FRC_TUNING_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCTUN_TUN_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_REGISTER_LOCK_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return (SFR_DATA)0;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_SELECT_1_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_ROSEL_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CHANGE_ACTIVE_1_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_ACTIVE_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_CHANGE_1_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_DIVSWEN_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINSLEEP_1_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_RSLP_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_ENABLE_1_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_OE_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINIDLE_1_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_SIDL_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_ENABLE_1_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_ON_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_OUTPUT_DIV_1_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_RODIV_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_SELECT_2_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_ROSEL_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CHANGE_ACTIVE_2_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_ACTIVE_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_CHANGE_2_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_DIVSWEN_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINSLEEP_2_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_RSLP_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_ENABLE_2_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_OE_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINIDLE_2_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_SIDL_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_ENABLE_2_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_ON_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_OUTPUT_DIV_2_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_RODIV_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_SELECT_3_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_ROSEL_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CHANGE_ACTIVE_3_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_ACTIVE_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_CHANGE_3_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_DIVSWEN_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINSLEEP_3_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_RSLP_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_ENABLE_3_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_OE_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINIDLE_3_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_SIDL_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_ENABLE_3_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_ON_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_OUTPUT_DIV_3_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_RODIV_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_SELECT_4_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_ROSEL_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CHANGE_ACTIVE_4_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_ACTIVE_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_CHANGE_4_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_DIVSWEN_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINSLEEP_4_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_RSLP_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_ENABLE_4_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_OE_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINIDLE_4_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_SIDL_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_ENABLE_4_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_ON_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_OUTPUT_DIV_4_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_RODIV_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_TRIM_1_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1TRIM_ROTRIM_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_TRIM_2_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2TRIM_ROTRIM_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_TRIM_3_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3TRIM_ROTRIM_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_TRIM_4_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4TRIM_ROTRIM_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_SYSPLL_FREQ_RANGE_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _SPLLCON_PLLRANGE_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_SYSPLL_INPUT_SOURCE_CLOCK_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _SPLLCON_PLLICLK_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_INPUT_DIVISOR_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _SPLLCON_PLLIDIV_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_SYSPLL_MULTIPLIER_1_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _SPLLCON_PLLMULT_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_OUTPUT_DIVISOR_2_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _SPLLCON_PLLODIV_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_DIVISOR_1_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB1DIV_PBDIV_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_READY_1_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB1DIV_PBDIVRDY_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_DIVISOR_2_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB2DIV_PBDIV_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_READY_2_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB2DIV_PBDIVRDY_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_ENABLE_2_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB2DIV_ON_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_DIVISOR_3_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB3DIV_PBDIV_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_READY_3_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB3DIV_PBDIVRDY_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_ENABLE_3_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB3DIV_ON_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_DIVISOR_4_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB4DIV_PBDIV_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_READY_4_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB4DIV_PBDIVRDY_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_ENABLE_4_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB4DIV_ON_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_DIVISOR_5_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB5DIV_PBDIV_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_READY_5_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB5DIV_PBDIVRDY_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_ENABLE_5_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB5DIV_ON_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_DIVISOR_7_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB7DIV_PBDIV_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_READY_7_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB7DIV_PBDIVRDY_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_ENABLE_7_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB7DIV_ON_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_DIVISOR_8_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB8DIV_PBDIV_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_READY_8_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB8DIV_PBDIVRDY_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_ENABLE_8_POS(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB8DIV_ON_POSITION;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_SWITCH_INIT_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_OSWEN_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_SECONDARY_ENABLE_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_SOSCEN_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_CLOCK_FAIL_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_CF_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_ON_WAIT_ACTION_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_SLPEN_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_LOCK_STATUS_SYS_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_SLOCK_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_LOCK_STATUS_USB_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_ULOCK_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_CLOCK_LOCK_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_CLKLOCK_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_SELECTMZ_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_NOSC_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_CURRENT_GET_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_COSC_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_SECONDARY_READY_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_SOSCRDY_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_DREAM_MODE_ENABLE_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_DRMEN_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_FRC_DIVISOR_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCCON_FRCDIV_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_FRC_TUNING_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _OSCTUN_TUN_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_REGISTER_LOCK_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return (SFR_DATA)sizeof(SFR_DATA);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_SELECT_1_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_ROSEL_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CHANGE_ACTIVE_1_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_ACTIVE_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_CHANGE_1_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_DIVSWEN_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINSLEEP_1_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_RSLP_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_ENABLE_1_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_OE_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINIDLE_1_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_SIDL_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_ENABLE_1_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_ON_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_OUTPUT_DIV_1_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1CON_RODIV_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_SELECT_2_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_ROSEL_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CHANGE_ACTIVE_2_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_ACTIVE_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_CHANGE_2_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_DIVSWEN_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINSLEEP_2_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_RSLP_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_ENABLE_2_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_OE_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINIDLE_2_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_SIDL_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_ENABLE_2_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_ON_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_OUTPUT_DIV_2_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2CON_RODIV_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_SELECT_3_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_ROSEL_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CHANGE_ACTIVE_3_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_ACTIVE_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_CHANGE_3_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_DIVSWEN_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINSLEEP_3_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_RSLP_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_ENABLE_3_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_OE_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINIDLE_3_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_SIDL_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_ENABLE_3_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_ON_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_OUTPUT_DIV_3_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3CON_RODIV_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_SELECT_4_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_ROSEL_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CHANGE_ACTIVE_4_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_ACTIVE_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_BASECLK_CHANGE_4_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_DIVSWEN_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINSLEEP_4_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_RSLP_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_ENABLE_4_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_OE_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_STOPINIDLE_4_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_SIDL_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_ENABLE_4_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_ON_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_CLK_OUTPUT_DIV_4_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4CON_RODIV_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_TRIM_1_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO1TRIM_ROTRIM_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_TRIM_2_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO2TRIM_ROTRIM_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_TRIM_3_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO3TRIM_ROTRIM_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_REF_OUTPUT_TRIM_4_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _REFO4TRIM_ROTRIM_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_SYSPLL_FREQ_RANGE_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _SPLLCON_PLLRANGE_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_SYSPLL_INPUT_SOURCE_CLOCK_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _SPLLCON_PLLICLK_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_INPUT_DIVISOR_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _SPLLCON_PLLIDIV_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_SYSPLL_MULTIPLIER_1_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _SPLLCON_PLLMULT_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_OUTPUT_DIVISOR_2_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _SPLLCON_PLLODIV_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_DIVISOR_1_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB1DIV_PBDIV_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_READY_1_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB1DIV_PBDIVRDY_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_DIVISOR_2_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB2DIV_PBDIV_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_READY_2_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB2DIV_PBDIVRDY_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_ENABLE_2_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB2DIV_ON_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_DIVISOR_3_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB3DIV_PBDIV_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_READY_3_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB3DIV_PBDIVRDY_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_ENABLE_3_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB3DIV_ON_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_DIVISOR_4_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB4DIV_PBDIV_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_READY_4_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB4DIV_PBDIVRDY_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_ENABLE_4_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB4DIV_ON_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_DIVISOR_5_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB5DIV_PBDIV_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_READY_5_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB5DIV_PBDIVRDY_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_ENABLE_5_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB5DIV_ON_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_DIVISOR_7_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB7DIV_PBDIV_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_READY_7_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB7DIV_PBDIVRDY_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_ENABLE_7_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB7DIV_ON_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_DIVISOR_8_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB8DIV_PBDIV_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_READY_8_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB8DIV_PBDIVRDY_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

PLIB_INLINE SFR_DATA _OSC_OSC_PB_CLOCK_ENABLE_8_LEN(OSC_MODULE_ID i)
{
    switch (i) {
        case OSC_ID_0 :
            return _PB8DIV_ON_LENGTH;
        case OSC_NUMBER_OF_MODULES :
        default :
            return (SFR_DATA)-1;
    }
}

/* Section 2 - Feature variant inclusion */

#define PLIB_TEMPLATE PLIB_INLINE
#include "../templates/osc_OnWaitAction_Default.h"
#include "../templates/osc_SecondaryEnable_Default.h"
#include "../templates/osc_SecondaryReady_Default.h"
#include "../templates/osc_FRCDivisor_Default.h"
#include "../templates/osc_OscSelect_Mz.h"
#include "../templates/osc_OscSwitchInit_Default.h"
#include "../templates/osc_OscCurrentGet_Mz.h"
#include "../templates/osc_PBClockDivisor_PIC32_2.h"
#include "../templates/osc_PBClockReady_PIC32_1.h"
#include "../templates/osc_UsbClockSource_Unsupported.h"
#include "../templates/osc_PLLLockStatus_Default.h"
#include "../templates/osc_PLLClockLock_Default.h"
#include "../templates/osc_PLLMultiplier_PIC32_2.h"
#include "../templates/osc_PLLOutputDivisor_PIC32_2.h"
#include "../templates/osc_ClockFail_Default.h"
#include "../templates/osc_FRCTuning_Default.h"
#include "../templates/osc_ReferenceOscBaseClock_PIC32_2.h"
#include "../templates/osc_ReferenceOscChange_PIC32_2.h"
#include "../templates/osc_ReferenceOscChangeActive_PIC32_2.h"
#include "../templates/osc_ReferenceOscStopInSleep_PIC32_2.h"
#include "../templates/osc_ReferenceOutputEnable_PIC32_2.h"
#include "../templates/osc_ReferenceOscStopInIdleEnable_PIC32_2.h"
#include "../templates/osc_ReferenceOscEnable_PIC32_2.h"
#include "../templates/osc_ReferenceOscDivisor_PIC32_2.h"
#include "../templates/osc_ReferenceOscTrim_PIC32_2.h"
#include "../templates/osc_PBClockOutputEnable_Default.h"
#include "../templates/osc_PLLInputDivisor_Default.h"
#include "../templates/osc_PLLInputClockSource_Default.h"
#include "../templates/osc_PLLFrequencyRange_Default.h"
#include "../templates/osc_SleepToStartupClock_Unsupported.h"
#include "../templates/osc_ClockReadyStatus_Unsupported.h"
#include "../templates/osc_ClockSlewingStatus_Unsupported.h"
#include "../templates/osc_SlewEnableControl_Unsupported.h"
#include "../templates/osc_SlewDivisorStepControl_Unsupported.h"
#include "../templates/osc_SystemClockDivisorControl_Unsupported.h"

/* Section 3 - PLIB dispatch function definitions */

PLIB_INLINE_API bool PLIB_OSC_ExistsOnWaitAction(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsOnWaitAction_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_OSC_OnWaitActionSet(OSC_MODULE_ID index, OSC_OPERATION_ON_WAIT onWait)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_OnWaitActionSet_Default(index, onWait);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API OSC_OPERATION_ON_WAIT PLIB_OSC_OnWaitActionGet(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_OnWaitActionGet_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (OSC_OPERATION_ON_WAIT)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsSecondaryEnable(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsSecondaryEnable_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_OSC_SecondaryEnable(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_SecondaryEnable_Default(index);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_OSC_SecondaryDisable(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_SecondaryDisable_Default(index);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_OSC_SecondaryIsEnabled(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_SecondaryIsEnabled_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsSecondaryReady(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsSecondaryReady_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_SecondaryIsReady(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_SecondaryIsReady_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsFRCDivisor(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsFRCDivisor_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_OSC_FRCDivisorSelect(OSC_MODULE_ID index, OSC_FRC_DIV divisorFRC)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_FRCDivisorSelect_Default(index, divisorFRC);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API uint16_t PLIB_OSC_FRCDivisorGet(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_FRCDivisorGet_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (uint16_t)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsOscSelect(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsOscSelect_Mz(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_OSC_SysClockSelect(OSC_MODULE_ID index, OSC_SYS_TYPE newOsc)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_SysClockSelect_Mz(index, newOsc);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsOscSwitchInit(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsOscSwitchInit_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_OSC_ClockSwitchingAbort(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_ClockSwitchingAbort_Default(index);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ClockSwitchingIsComplete(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ClockSwitchingIsComplete_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsOscCurrentGet(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsOscCurrentGet_Mz(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API OSC_SYS_TYPE PLIB_OSC_CurrentSysClockGet(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_CurrentSysClockGet_Mz(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (OSC_SYS_TYPE)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsPBClockDivisor(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsPBClockDivisor_PIC32_2(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API OSC_PB_CLOCK_DIV_TYPE PLIB_OSC_PBClockDivisorGet(OSC_MODULE_ID index, OSC_PERIPHERAL_BUS peripheralBusNumber)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_PBClockDivisorGet_PIC32_2(index, peripheralBusNumber);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (OSC_PB_CLOCK_DIV_TYPE)0;
    }
}

PLIB_INLINE_API void PLIB_OSC_PBClockDivisorSet(OSC_MODULE_ID index, OSC_PERIPHERAL_BUS peripheralBusNumber, OSC_PB_CLOCK_DIV_TYPE peripheralBusClkDiv)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_PBClockDivisorSet_PIC32_2(index, peripheralBusNumber, peripheralBusClkDiv);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsPBClockReady(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsPBClockReady_PIC32_1(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_PBClockDivisorIsReady(OSC_MODULE_ID index, OSC_PERIPHERAL_BUS peripheralBusNumber)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_PBClockDivisorIsReady_PIC32_1(index, peripheralBusNumber);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsUsbClockSource(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsUsbClockSource_Unsupported(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_OSC_UsbClockSourceSelect(OSC_MODULE_ID index, OSC_USBCLOCK_SOURCE usbClock)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_UsbClockSourceSelect_Unsupported(index, usbClock);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API OSC_USBCLOCK_SOURCE _PLIB_UNSUPPORTED PLIB_OSC_UsbClockSourceGet(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_UsbClockSourceGet_Unsupported(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (OSC_USBCLOCK_SOURCE)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsPLLLockStatus(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsPLLLockStatus_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_PLLIsLocked(OSC_MODULE_ID index, OSC_PLL_SELECT pllselect)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_PLLIsLocked_Default(index, pllselect);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsPLLClockLock(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsPLLClockLock_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_OSC_PLLClockLock(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_PLLClockLock_Default(index);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_OSC_PLLClockUnlock(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_PLLClockUnlock_Default(index);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_OSC_PLLClockIsLocked(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_PLLClockIsLocked_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsSysPLLMultiplier(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsSysPLLMultiplier_PIC32_2(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_OSC_SysPLLMultiplierSelect(OSC_MODULE_ID index, OSC_SYSPLL_MULTIPLIER_TYPE pll_multiplier)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_SysPLLMultiplierSelect_PIC32_2(index, pll_multiplier);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API OSC_SYSPLL_MULTIPLIER_TYPE PLIB_OSC_SysPLLMultiplierGet(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_SysPLLMultiplierGet_PIC32_2(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (OSC_SYSPLL_MULTIPLIER_TYPE)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsSysPLLOutputDivisor(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsSysPLLOutputDivisor_PIC32_2(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_OSC_SysPLLOutputDivisorSet(OSC_MODULE_ID index, OSC_SYSPLL_OUT_DIV PLLOutDiv)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_SysPLLOutputDivisorSet_PIC32_2(index, PLLOutDiv);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API uint16_t PLIB_OSC_SysPLLOutputDivisorGet(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_SysPLLOutputDivisorGet_PIC32_2(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (uint16_t)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsClockFail(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsClockFail_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ClockHasFailed(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ClockHasFailed_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsFRCTuning(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsFRCTuning_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_OSC_FRCTuningSelect(OSC_MODULE_ID index, OSC_FRC_TUNE_TYPE tuningValue)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_FRCTuningSelect_Default(index, tuningValue);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsReferenceOscBaseClock(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsReferenceOscBaseClock_PIC32_2(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_OSC_ReferenceOscBaseClockSelect(OSC_MODULE_ID index, OSC_REFERENCE referenceOsc, OSC_REF_BASECLOCK refOscBaseClock)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_ReferenceOscBaseClockSelect_PIC32_2(index, referenceOsc, refOscBaseClock);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsReferenceOscChange(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsReferenceOscChange_PIC32_2(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ReferenceOscSwitchIsComplete(OSC_MODULE_ID index, OSC_REFERENCE referenceOsc)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ReferenceOscSwitchIsComplete_PIC32_2(index, referenceOsc);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsReferenceOscChangeActive(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsReferenceOscChangeActive_PIC32_2(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ReferenceOscSourceChangeIsActive(OSC_MODULE_ID index, OSC_REFERENCE referenceOsc)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ReferenceOscSourceChangeIsActive_PIC32_2(index, referenceOsc);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsReferenceOscStopInSleep(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsReferenceOscStopInSleep_PIC32_2(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_OSC_ReferenceOscStopInSleepEnable(OSC_MODULE_ID index, OSC_REFERENCE referenceOsc)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_ReferenceOscStopInSleepEnable_PIC32_2(index, referenceOsc);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_OSC_ReferenceOscStopInSleepDisable(OSC_MODULE_ID index, OSC_REFERENCE referenceOsc)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_ReferenceOscStopInSleepDisable_PIC32_2(index, referenceOsc);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ReferenceOscStopInSleepIsEnabled(OSC_MODULE_ID index, OSC_REFERENCE referenceOsc)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ReferenceOscStopInSleepIsEnabled_PIC32_2(index, referenceOsc);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsReferenceOutputEnable(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsReferenceOutputEnable_PIC32_2(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_OSC_ReferenceOutputEnable(OSC_MODULE_ID index, OSC_REFERENCE referenceOsc)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_ReferenceOutputEnable_PIC32_2(index, referenceOsc);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_OSC_ReferenceOutputDisable(OSC_MODULE_ID index, OSC_REFERENCE referenceOsc)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_ReferenceOutputDisable_PIC32_2(index, referenceOsc);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ReferenceOutputIsEnabled(OSC_MODULE_ID index, OSC_REFERENCE referenceOsc)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ReferenceOutputIsEnabled_PIC32_2(index, referenceOsc);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsReferenceOscStopInIdleEnable(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsReferenceOscStopInIdleEnable_PIC32_2(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_OSC_ReferenceOscStopInIdleEnable(OSC_MODULE_ID index, OSC_REFERENCE referenceOsc)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_ReferenceOscStopInIdleEnable_PIC32_2(index, referenceOsc);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_OSC_ReferenceOscStopInIdleDisable(OSC_MODULE_ID index, OSC_REFERENCE referenceOsc)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_ReferenceOscStopInIdleDisable_PIC32_2(index, referenceOsc);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ReferenceOscStopInIdleIsEnabled(OSC_MODULE_ID index, OSC_REFERENCE referenceOsc)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ReferenceOscStopInIdleIsEnabled_PIC32_2(index, referenceOsc);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsReferenceOscEnable(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsReferenceOscEnable_PIC32_2(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_OSC_ReferenceOscEnable(OSC_MODULE_ID index, OSC_REFERENCE referenceOsc)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_ReferenceOscEnable_PIC32_2(index, referenceOsc);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_OSC_ReferenceOscDisable(OSC_MODULE_ID index, OSC_REFERENCE referenceOsc)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_ReferenceOscDisable_PIC32_2(index, referenceOsc);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ReferenceOscIsEnabled(OSC_MODULE_ID index, OSC_REFERENCE referenceOsc)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ReferenceOscIsEnabled_PIC32_2(index, referenceOsc);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsReferenceOscDivisor(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsReferenceOscDivisor_PIC32_2(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_OSC_ReferenceOscDivisorValueSet(OSC_MODULE_ID index, OSC_REFERENCE referenceOsc, OSC_REF_DIVISOR_TYPE refOscDivValue)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_ReferenceOscDivisorValueSet_PIC32_2(index, referenceOsc, refOscDivValue);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsReferenceOscTrim(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsReferenceOscTrim_PIC32_2(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_OSC_ReferenceOscTrimSet(OSC_MODULE_ID index, OSC_REFERENCE referenceOsc, OSC_REF_TRIM_TYPE trimValue)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_ReferenceOscTrimSet_PIC32_2(index, referenceOsc, trimValue);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsPBClockOutputEnable(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsPBClockOutputEnable_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_OSC_PBOutputClockEnable(OSC_MODULE_ID index, OSC_PERIPHERAL_BUS peripheralBusNumber)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_PBOutputClockEnable_Default(index, peripheralBusNumber);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void PLIB_OSC_PBOutputClockDisable(OSC_MODULE_ID index, OSC_PERIPHERAL_BUS peripheralBusNumber)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_PBOutputClockDisable_Default(index, peripheralBusNumber);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool PLIB_OSC_PBOutputClockIsEnabled(OSC_MODULE_ID index, OSC_PERIPHERAL_BUS peripheralBusNumber)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_PBOutputClockIsEnabled_Default(index, peripheralBusNumber);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsSysPLLInputDivisor(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsSysPLLInputDivisor_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_OSC_SysPLLInputDivisorSet(OSC_MODULE_ID index, uint16_t PLLInDiv)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_SysPLLInputDivisorSet_Default(index, PLLInDiv);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API uint16_t PLIB_OSC_SysPLLInputDivisorGet(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_SysPLLInputDivisorGet_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (uint16_t)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsSysPLLInputClockSource(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsSysPLLInputClockSource_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_OSC_SysPLLInputClockSourceSet(OSC_MODULE_ID index, OSC_SYSPLL_IN_CLK_SOURCE PLLInClockSource)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_SysPLLInputClockSourceSet_Default(index, PLLInClockSource);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API OSC_SYSPLL_IN_CLK_SOURCE PLIB_OSC_SysPLLInputClockSourceGet(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_SysPLLInputClockSourceGet_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (OSC_SYSPLL_IN_CLK_SOURCE)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsSysPLLFrequencyRange(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsSysPLLFrequencyRange_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void PLIB_OSC_SysPLLFrequencyRangeSet(OSC_MODULE_ID index, OSC_SYSPLL_FREQ_RANGE PLLFrequencyRange)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_SysPLLFrequencyRangeSet_Default(index, PLLFrequencyRange);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API OSC_SYSPLL_FREQ_RANGE PLIB_OSC_SysPLLFrequencyRangeGet(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_SysPLLFrequencyRangeGet_Default(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (OSC_SYSPLL_FREQ_RANGE)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsSleepToStartupClock(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsSleepToStartupClock_Unsupported(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_OSC_SleepToStartupClockSelect(OSC_MODULE_ID index, OSC_SLEEP_TO_STARTUP_CLK_TYPE startupOsc)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_SleepToStartupClockSelect_Unsupported(index, startupOsc);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API OSC_SLEEP_TO_STARTUP_CLK_TYPE _PLIB_UNSUPPORTED PLIB_OSC_SleepToStartupClockGet(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_SleepToStartupClockGet_Unsupported(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (OSC_SLEEP_TO_STARTUP_CLK_TYPE)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsClockReadyStatus(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsClockReadyStatus_Unsupported(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_OSC_ClockIsReady(OSC_MODULE_ID index, OSC_CLOCK_ID clk)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ClockIsReady_Unsupported(index, clk);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsClockSlewingStatus(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsClockSlewingStatus_Unsupported(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_OSC_ClockSlewingIsActive(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ClockSlewingIsActive_Unsupported(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsSlewEnableControl(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsSlewEnableControl_Unsupported(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_OSC_SlewEnable(OSC_MODULE_ID index, OSC_CLOCK_SLEW_TYPE slewType)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_SlewEnable_Unsupported(index, slewType);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_OSC_SlewDisable(OSC_MODULE_ID index, OSC_CLOCK_SLEW_TYPE slewType)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_SlewDisable_Unsupported(index, slewType);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API bool _PLIB_UNSUPPORTED PLIB_OSC_SlewIsEnabled(OSC_MODULE_ID index, OSC_CLOCK_SLEW_TYPE slewType)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_SlewIsEnabled_Unsupported(index, slewType);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsSlewDivisorStepControl(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsSlewDivisorStepControl_Unsupported(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_OSC_SlewDivisorStepSelect(OSC_MODULE_ID index, uint32_t slewSteps)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_SlewDivisorStepSelect_Unsupported(index, slewSteps);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_OSC_SlewDivisorStepGet(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_SlewDivisorStepGet_Unsupported(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (uint32_t)0;
    }
}

PLIB_INLINE_API bool PLIB_OSC_ExistsSystemClockDivisorControl(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_ExistsSystemClockDivisorControl_Unsupported(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (bool)0;
    }
}

PLIB_INLINE_API void _PLIB_UNSUPPORTED PLIB_OSC_SystemClockDivisorSelect(OSC_MODULE_ID index, uint32_t systemClkDivisor)
{
    switch (index) {
        case OSC_ID_0 :
            OSC_SystemClockDivisorSelect_Unsupported(index, systemClkDivisor);
            break;
        case OSC_NUMBER_OF_MODULES :
        default :
            break;
    }
}

PLIB_INLINE_API uint32_t _PLIB_UNSUPPORTED PLIB_OSC_SystemClockDivisorGet(OSC_MODULE_ID index)
{
    switch (index) {
        case OSC_ID_0 :
            return OSC_SystemClockDivisorGet_Unsupported(index);
        case OSC_NUMBER_OF_MODULES :
        default :
            return (uint32_t)0;
    }
}

#endif
