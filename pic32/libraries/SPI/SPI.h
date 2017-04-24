/*
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@bug.st>
 * Copyright (c) 2014 by Paul Stoffregen <paul@pjrc.com> (Transaction API)
 * Copyright (c) 2014 by Matthijs Kooijman <matthijs@stdin.nl> (SPISettings AVR)
 * Copyright (c) 2014 by Andrew J. Kroll <xxxajk@gmail.com> (atomicity fixes)
 * Copyright (c) 2015 by Majenko Technologies <matt@majenko.co.uk> (port to chipKIT)
 * SPI Master library for Arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

#ifndef _SPI_H_INCLUDED
#define _SPI_H_INCLUDED

#define OPT_BOARD_INTERNAL

#include <Arduino.h>

// SPI_HAS_TRANSACTION means SPI has beginTransaction(), endTransaction(),
// usingInterrupt(), and SPISetting(clock, bitOrder, dataMode)
#define SPI_HAS_TRANSACTION 1

// SPI_HAS_NOTUSINGINTERRUPT means that SPI has notUsingInterrupt() method
#define SPI_HAS_NOTUSINGINTERRUPT 1

// SPI_ATOMIC_VERSION means that SPI has atomicity fixes and what version.
// This way when there is a bug fix you can check this define to alert users
// of your code if it uses better version of this library.
// This also implies everything that SPI_HAS_TRANSACTION as documented above is
// available too.
#define SPI_ATOMIC_VERSION 1

// Uncomment this line to add detection of mismatched begin/end transactions.
// A mismatch occurs if other libraries fail to use SPI.endTransaction() for
// each SPI.beginTransaction().  Connect an LED to this pin.  The LED will turn
// on if any mismatch is ever detected.
//#define SPI_TRANSACTION_MISMATCH_LED 5

#ifndef LSBFIRST
#define LSBFIRST 0
#endif
#ifndef MSBFIRST
#define MSBFIRST 1
#endif

#define SPI_CLOCK_DIV4 0x00
#define SPI_CLOCK_DIV16 0x01
#define SPI_CLOCK_DIV64 0x02
#define SPI_CLOCK_DIV128 0x03
#define SPI_CLOCK_DIV2 0x04
#define SPI_CLOCK_DIV8 0x05
#define SPI_CLOCK_DIV32 0x06

#define SPI_MODE0 0x00
#define SPI_MODE1 0x04
#define SPI_MODE2 0x08
#define SPI_MODE3 0x0C

#define SPI_MODE_MASK 0x0C  // CPOL = bit 3, CPHA = bit 2 on SPCR
#define SPI_CLOCK_MASK 0x03  // SPR1 = bit 1, SPR0 = bit 0 on SPCR
#define SPI_2XCLOCK_MASK 0x01  // SPI2X = bit 0 on SPSR

// define SPI_AVR_EIMSK for AVR boards with external interrupt pins
#if defined(EIMSK)
#define SPI_AVR_EIMSK  EIMSK
#elif defined(GICR)
#define SPI_AVR_EIMSK  GICR
#elif defined(GIMSK)
#define SPI_AVR_EIMSK  GIMSK
#endif

class SPISettings {
public:
    SPISettings(uint32_t clock, uint8_t bitOrder, uint8_t dataMode) {
        if (__builtin_constant_p(clock)) {
            init_AlwaysInline(clock, bitOrder, dataMode);
        } else {
            init_MightInline(clock, bitOrder, dataMode);
        }
    }
    SPISettings() {
        init_AlwaysInline(4000000, MSBFIRST, SPI_MODE0);
    }
private:
    uint32_t softBitOrder;
    /* Note that on PIC32, SPI always shifts out Most Significant Bit first, so the bitOrder parameter
     * is not used, but needs to be retained for compatibility with existing sketches/libraries */
    void init_MightInline(uint32_t clock, uint8_t __attribute__((unused)) bitOrder, uint8_t dataMode) {
        init_AlwaysInline(clock, bitOrder, dataMode);
    }
    void init_AlwaysInline(uint32_t clock, uint8_t __attribute__((unused)) bitOrder, uint8_t dataMode)
    __attribute__((__always_inline__)) {

        softBitOrder = bitOrder;
        
        DesiredSPIClockFrequency = clock;
        
        // By including the needed flag here, we have a speed optimization.
        // We will always set the Master Enable bit, because we are always the SPI master
        // We will always set the ON bit because we always want the SPI peripheral turned on
        //
        // The _SPICON_SMP bit makes the SPI peripheral actually follow the 
        // general SPI rules that everyone else uses. Normally an SPI master 
        // samples just before the next cycle starts.  
        // At high data rates it becomes very important to sample later 
        // than center, due to timing constraints in the silicon.
        con = (1 << _SPICON_MSTEN) | (1 << _SPICON_ON) | (1 << _SPICON_SMP);

        switch (dataMode) {
            case SPI_MODE0:     // CKE = 1, CKP = 0
                con |= (1 << _SPICON_CKE);
                break;

            case SPI_MODE1:     // CKE = 0, CKP = 0
                break;

            case SPI_MODE2:     // CKE = 1, CKP = 1
                con |= ((1 << _SPICON_CKP) | (1 << _SPICON_CKE));
                break;

            case SPI_MODE3:     // CKE = 0, CKP = 1
                con |= (1 << _SPICON_CKP);
                break;
        }
    }
    /* This function computes the proper value for the BRG register 
     * (baud rate generator divisor). This computation can't be done
     * in this object's initializer, because the value __PIC32_pbClk 
     * isn't guaranteed to be correct until after all objects have
     * been initialized and the init() call in wiring.c has had a
     * chance to run. Also, this value can (theoretically) be changed
     * at runtime (dynamically) and so we need to re-compute the proper
     * BRG value each time we start a transaction to be safe. */
    uint16_t GenerateBRG(void) {
        /* Compute the baud rate divider for this frequency. If the 
         * desired clock rate is too slow for our slowest possible
         * on this system, use the slowest possible.
        */
      if ((__PIC32_pbClk / (2 * DesiredSPIClockFrequency)) > 512)
      {
        return(511);
      }
      else
      {
        return (uint16_t)((__PIC32_pbClk / (2 * DesiredSPIClockFrequency)) - 1);
      }
    }
    uint32_t con;
    uint16_t brg;
    /* A cached copy of the desired SPI clock frequency set at object creation */
    uint32_t DesiredSPIClockFrequency;
    friend class SPIClass;
};


class SPIClass {
public:

#if defined(__PIC32_PPS__)
    SPIClass(uint32_t base, int pinMI, int pinMO, ppsFunctionType ppsMI, ppsFunctionType ppsMO);
#else
    SPIClass(uint32_t base);
#endif

    // Initialize the SPI library
    void begin();

    // If SPI is used from within an interrupt, this function registers
    // that interrupt with the SPI library, so beginTransaction() can
    // prevent conflicts.  The input interruptNumber is the number used
    // with attachInterrupt.  If SPI is used from a different interrupt
    // (eg, a timer), interruptNumber should be 255.
    void usingInterrupt(uint8_t interruptNumber);
    // And this does the opposite.
    void notUsingInterrupt(uint8_t interruptNumber);
    // Note: the usingInterrupt and notUsingInterrupt functions should
    // not to be called from ISR context or inside a transaction.
    // For details see:
    // https://github.com/arduino/Arduino/pull/2381
    // https://github.com/arduino/Arduino/pull/2449

    // Before using SPI.transfer() or asserting chip select pins,
    // this function is used to gain exclusive access to the SPI bus
    // and configure the correct settings.
    inline void beginTransaction(SPISettings settings) {
        if (interruptMode > 0) {
            int32_t sreg = disableInterrupts();
            if (interruptMode == 1) {
                if(interruptMask & 0x01) {
                    IEC0bits.INT0IE = 0;
                }
                if(interruptMask & 0x02) {
                    IEC0bits.INT1IE = 0;
                }
                if(interruptMask & 0x04) {
                    IEC0bits.INT2IE = 0;
                }
                if(interruptMask & 0x08) {
                    IEC0bits.INT3IE = 0;
                }
                if(interruptMask & 0x10) {
                    IEC0bits.INT4IE = 0;
                }
                restoreInterrupts(sreg);
            } else interruptSave = sreg;
            
        }

#ifdef SPI_TRANSACTION_MISMATCH_LED

        if (inTransactionFlag) {
            pinMode(SPI_TRANSACTION_MISMATCH_LED, OUTPUT);
            digitalWrite(SPI_TRANSACTION_MISMATCH_LED, HIGH);
        }

        inTransactionFlag = 1;
#endif
        /* Shut off the SPI peripheral to prepare for possibly changing things */
        // pspi->sxCon.clr = (1 << _SPICON_ON);         // This line can cause glitches on the CLOCK output
        /* Compute and set the proper BRG register value based on our desired SPI clock rate */
        pspi->sxBrg.reg = settings.GenerateBRG();
        /* Copy over the proper value of the CON register for this set of settings, turning SPI peripheral back on */
        pspi->sxCon.reg = settings.con;
        softBitOrder = settings.softBitOrder;
    }

    // Write to the SPI bus (MOSI pin) and also receive (MISO pin)
    inline uint8_t transfer(uint8_t data) {
        if (softBitOrder == LSBFIRST) {
            uint8_t sdata = 
                ((data & 0x80) >> 7) |
                ((data & 0x40) >> 5) |
                ((data & 0x20) >> 3) |
                ((data & 0x10) >> 1) |
                ((data & 0x08) << 1) |
                ((data & 0x04) << 3) |
                ((data & 0x02) << 5) |
                ((data & 0x01) << 7);
            data = sdata;
        }

        while ((pspi->sxStat.reg & (1 << _SPISTAT_SPITBE)) == 0) {
        }

        pspi->sxBuf.reg = data;

        while ((pspi->sxStat.reg & (1 << _SPISTAT_SPIRBF)) == 0) {
        }

        data = pspi->sxBuf.reg;
        if (softBitOrder == LSBFIRST) {
            uint8_t sdata = 
                ((data & 0x80) >> 7) |
                ((data & 0x40) >> 5) |
                ((data & 0x20) >> 3) |
                ((data & 0x10) >> 1) |
                ((data & 0x08) << 1) |
                ((data & 0x04) << 3) |
                ((data & 0x02) << 5) |
                ((data & 0x01) << 7);
            data = sdata;
        }

        return data;
    }
    inline uint16_t transfer16(uint16_t data) {
        pspi->sxCon.set = 1 << _SPICON_MODE16;

        while ((pspi->sxStat.reg & (1 << _SPISTAT_SPITBE)) == 0) {
        }

        pspi->sxBuf.reg = data;

        while ((pspi->sxStat.reg & (1 << _SPISTAT_SPIRBF)) == 0) {
        }

        pspi->sxCon.clr = 1 << _SPICON_MODE16;
        return pspi->sxBuf.reg;
    }
    inline void transfer(void *buf, size_t count) {
        uint8_t *p = (uint8_t *)buf;
        for (size_t i = 0; i < count; i++) {
            p[i] = transfer(p[i]);
        }
    }
    // After performing a group of transfers and releasing the chip select
    // signal, this function allows others to access the SPI bus
    inline void endTransaction(void) {
#ifdef SPI_TRANSACTION_MISMATCH_LED

        if (!inTransactionFlag) {
            pinMode(SPI_TRANSACTION_MISMATCH_LED, OUTPUT);
            digitalWrite(SPI_TRANSACTION_MISMATCH_LED, HIGH);
        }

        inTransactionFlag = 0;
#endif

        if (interruptMode > 0) {
            uint32_t sreg = disableInterrupts();
            if (interruptMode == 1) {
                if(interruptMask & 0x01) {
                    IEC0bits.INT0IE = 1;
                }
                if(interruptMask & 0x02) {
                    IEC0bits.INT1IE = 1;
                }
                if(interruptMask & 0x04) {
                    IEC0bits.INT2IE = 1;
                }
                if(interruptMask & 0x08) {
                    IEC0bits.INT3IE = 1;
                }
                if(interruptMask & 0x10) {
                    IEC0bits.INT4IE = 1;
                }
                restoreInterrupts(sreg);
            } else restoreInterrupts(interruptSave);
        }
    }

    // Disable the SPI bus
    void end();

    // This function is deprecated.  New applications should use
    // beginTransaction() to configure SPI settings.
    inline void setBitOrder(uint8_t __attribute__((unused)) bitOrder) {
        softBitOrder = bitOrder;
    }
    // This function is deprecated.  New applications should use
    // beginTransaction() to configure SPI settings.
    inline void setDataMode(uint8_t dataMode) {
        switch (dataMode) {
            case SPI_MODE0:
                pspi->sxCon.clr = 1 << _SPICON_CKP;
                pspi->sxCon.set = 1 << _SPICON_CKE;
                break;

            case SPI_MODE1:
                pspi->sxCon.clr = 1 << _SPICON_CKP;
                pspi->sxCon.clr = 1 << _SPICON_CKE;
                break;

            case SPI_MODE2:
                pspi->sxCon.set = 1 << _SPICON_CKP;
                pspi->sxCon.set = 1 << _SPICON_CKE;
                break;

            case SPI_MODE3:
                pspi->sxCon.set = 1 << _SPICON_CKP;
                pspi->sxCon.clr = 1 << _SPICON_CKE;
                break;
        }
    }
    // This function is deprecated.  New applications should use
    // beginTransaction() to configure SPI settings.
    inline void setClockDivider(uint8_t clockDiv) {
        switch (clockDiv) {
            case SPI_CLOCK_DIV2:
                pspi->sxBrg.reg = 1;
                break;

            case SPI_CLOCK_DIV4:
                pspi->sxBrg.reg = 3;
                break;

            case SPI_CLOCK_DIV8:
                pspi->sxBrg.reg = 7;
                break;

            case SPI_CLOCK_DIV16:
                pspi->sxBrg.reg = 15;
                break;

            case SPI_CLOCK_DIV32:
                pspi->sxBrg.reg = 31;
                break;

            case SPI_CLOCK_DIV64:
                pspi->sxBrg.reg = 63;
                break;

            case SPI_CLOCK_DIV128:
                pspi->sxBrg.reg = 127;
                break;
        }
    }
    // These undocumented functions should not be used.  SPI.transfer()
    // polls the hardware flag which is automatically cleared as the
    // AVR responds to SPI's interrupt
    inline void attachInterrupt() { }
    inline void detachInterrupt() { }

private:
    uint32_t softBitOrder;
    uint32_t initialized;
    uint32_t interruptMode; // 0=none, 1=mask, 2=global
    uint32_t interruptMask; // which interrupts to mask
    uint32_t interruptSave; // temp storage, to restore state
#ifdef SPI_TRANSACTION_MISMATCH_LED
    uint32_t inTransactionFlag;
#endif
    p32_spi *pspi;
#if defined(__PIC32_PPS__)
    uint8_t             pinMISO;        //digital pin number for MISO
    uint8_t             pinMOSI;        //digital pin number for MOSI
    ppsFunctionType     ppsMISO;        //PPS select for SPI MISO
    ppsFunctionType     ppsMOSI;        //PPS select for SPI MOSI
#endif

};

extern SPIClass SPI;

#endif
