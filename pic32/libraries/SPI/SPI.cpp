/*
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@bug.st>
 * Copyright (c) 2014 by Paul Stoffregen <paul@pjrc.com> (Transaction API)
 * Copyright (c) 2014 by Matthijs Kooijman <matthijs@stdin.nl> (SPISettings AVR)
 * Copyright (c) 2014 by Andrew J. Kroll <xxxajk@gmail.com> (atomicity fixes)
 * SPI Master library for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

#include "SPI.h"

#ifndef _SPI_PORT
    #define _SPI_PORT 0
#endif

#if (_SPI_PORT == 0)
    #if defined(__PIC32_PPS__)
        SPIClass SPI(_DSPI0_BASE, _DSPI0_MISO_PIN, _DSPI0_MOSI_PIN, _DSPI0_MISO_IN, _DSPI0_MOSI_OUT);
    #else
        SPIClass SPI(_DSPI0_BASE);
    #endif
#elif (_SPI_PORT == 1)
    #if defined(__PIC32_PPS__)
        SPIClass SPI(_DSPI1_BASE, _DSPI1_MISO_PIN, _DSPI1_MOSI_PIN, _DSPI1_MISO_IN, _DSPI1_MOSI_OUT);
    #else
        SPIClass SPI(_DSPI1_BASE);
    #endif
#elif (_SPI_PORT == 2)
    #if defined(__PIC32_PPS__)
        SPIClass SPI(_DSPI2_BASE, _DSPI2_MISO_PIN, _DSPI2_MOSI_PIN, _DSPI2_MISO_IN, _DSPI2_MOSI_OUT);
    #else
        SPIClass SPI(_DSPI2_BASE);
    #endif
#elif (_SPI_PORT == 3)
    #if defined(__PIC32_PPS__)
        SPIClass SPI(_DSPI3_BASE, _DSPI3_MISO_PIN, _DSPI3_MOSI_PIN, _DSPI3_MISO_IN, _DSPI3_MOSI_OUT);
    #else
        SPIClass SPI(_DSPI3_BASE);
    #endif
#elif (_SPI_PORT == 4)
    #if defined(__PIC32_PPS__)
        SPIClass SPI(_DSPI4_BASE, _DSPI4_MISO_PIN, _DSPI4_MOSI_PIN, _DSPI4_MISO_IN, _DSPI4_MOSI_OUT);
    #else
        SPIClass SPI(_DSPI4_BASE);
    #endif
#elif (_SPI_PORT == 5)
    #if defined(__PIC32_PPS__)
        SPIClass SPI(_DSPI5_BASE, _DSPI5_MISO_PIN, _DSPI5_MOSI_PIN, _DSPI5_MISO_IN, _DSPI5_MOSI_OUT);
    #else
        SPIClass SPI(_DSPI5_BASE);
    #endif
#else
    #if defined(__PIC32_PPS__)
        SPIClass SPI(_DSPI0_BASE, _DSPI0_MISO_PIN, _DSPI0_MOSI_PIN, _DSPI0_MISO_IN, _DSPI0_MOSI_OUT);
    #else
        SPIClass SPI(_DSPI0_BASE);
    #endif
#endif

#if defined(__PIC32_PPS__)
SPIClass::SPIClass(uint32_t base, int pinMI, int pinMO, ppsFunctionType ppsMI, ppsFunctionType ppsMO) {
    pspi = (p32_spi *)base;
    pinMISO = pinMI;
    pinMOSI = pinMO;
    ppsMISO = ppsMI;
    ppsMOSI = ppsMO;
    softBitOrder = MSBFIRST;
}
#else
SPIClass::SPIClass(uint32_t base) {
    pspi = (p32_spi *)base;
    softBitOrder = MSBFIRST;
}
#endif


void SPIClass::begin() {
    uint32_t sreg = disableInterrupts();

    if (!initialized) {
#if defined(__PIC32_PPS__)
        pinMode(pinMISO, INPUT);
        mapPps(pinMISO, ppsMISO);
        pinMode(pinMOSI, OUTPUT);
        mapPps(pinMOSI, ppsMOSI);
#endif       
        pspi->sxCon.set = (1<<_SPICON_MSTEN) | (1<<_SPICON_ON);
        setClockDivider(SPI_CLOCK_DIV128);
        setDataMode(SPI_MODE0);
    }

    initialized++; // reference count
    restoreInterrupts(sreg);
}

void SPIClass::end() {
    uint32_t sreg = disableInterrupts();

    // Decrease the reference counter
    if (initialized) {
        initialized--;
//        mapPps(pinMISO, 0);
//        mapPps(pinMOSI, 0);
    }

    // If there are no more references disable SPI
    if (!initialized) {
        pspi->sxCon.clr = 1<<_SPICON_ON;
        interruptMode = 0;
        
#ifdef SPI_TRANSACTION_MISMATCH_LED
        inTransactionFlag = 0;
#endif
    }

    restoreInterrupts(sreg);
}

void SPIClass::usingInterrupt(uint8_t __attribute__((unused)) interruptNumber) {
    uint32_t sreg = disableInterrupts();
    uint8_t mask = 0x00U;
    switch (interruptNumber) {
      case EXT_INT0:
        mask = 0x01U;
        break;
      case EXT_INT1:
        mask = 0x02U;
        break;
        case EXT_INT2:
        mask = 0x04U;
        break;
      case EXT_INT3:
        mask = 0x08U;
        break;
      case EXT_INT4:
        mask = 0x10U;
        break;
      default:
        interruptMode = 2;
        break;
    }
    interruptMask |= mask;
    if (!interruptMode) interruptMode = 1;
    restoreInterrupts(sreg);   
}

void SPIClass::notUsingInterrupt(uint8_t __attribute__((unused)) interruptNumber) {
    if (interruptMode == 2) return;
    uint32_t sreg = disableInterrupts();
    uint8_t mask = 0xFFU;
    switch (interruptNumber) {
      case EXT_INT0:
        mask = 0xFEU;
        break;
      case EXT_INT1:
        mask = 0xFDU;
        break;
        case EXT_INT2:
        mask = 0xFBU;
        break;
      case EXT_INT3:
        mask = 0xF7U;
        break;
      case EXT_INT4:
        mask = 0xEFU;
        break;
    }
    interruptMask &= mask;
    restoreInterrupts(sreg);
}
