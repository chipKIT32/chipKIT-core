/*
 * Copyright (c) 2017, Majenko Technologies
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of Majenko Technologies nor the names of its contributors
 * may be used to endorse or promote products derived from this software without
 * specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <pins_arduino.h>
#if defined(_USB)

#ifdef __PIC32MX__

#include <p32xxxx.h>
#include <wiring.h>
#include <USB.h>

#define KVA_TO_PA(v)  ((v) & 0x1fffffff)
#define PA_TO_KVA0(pa)  ((pa) | 0x80000000)  // cachable
#define PA_TO_KVA1(pa)  ((pa) | 0xa000000

/*-------------- USB FS ---------------*/

USBFS *USBFS::_this;

#ifdef PIN_LED_TX
volatile static uint32_t TXLedTimeout = 0;

static uint32_t TXLedSwitchOff(uint32_t t) {
    TXLedTimeout++;
    if (TXLedTimeout > 1) {
        digitalWrite(PIN_LED_TX, LOW);
        detachCoreTimerService(TXLedSwitchOff);
        TXLedTimeout = 0;
    }
    return t + 50000;
}

static void TXOn() {
    digitalWrite(PIN_LED_TX, HIGH);
    TXLedTimeout = 0;
    attachCoreTimerService(TXLedSwitchOff);
}

#else
# define TXOn()
#endif

#ifdef PIN_LED_RX
volatile static uint32_t RXLedTimeout = 0;

static uint32_t RXLedSwitchOff(uint32_t t) {
    RXLedTimeout++;
    if (RXLedTimeout > 1) {
        digitalWrite(PIN_LED_RX, LOW);
        detachCoreTimerService(RXLedSwitchOff);
        RXLedTimeout = 0;
    }
    return t + 50000;
}

static void RXOn() {
    digitalWrite(PIN_LED_RX, HIGH);
    RXLedTimeout = 0;
    attachCoreTimerService(RXLedSwitchOff);
}
#else
# define RXOn()
#endif


bool USBFS::enableUSB() {
#ifdef PIN_LED_TX
    pinMode(PIN_LED_TX, OUTPUT);
    digitalWrite(PIN_LED_TX, LOW);
#endif

#ifdef PIN_LED_RX
    pinMode(PIN_LED_RX, OUTPUT);
    digitalWrite(PIN_LED_RX, LOW);
#endif

    U1BDTP1 = (uint8_t)(KVA_TO_PA((uint32_t)&_bufferDescriptorTable[0][0]) >> 8);
    U1BDTP2 = (uint8_t)(KVA_TO_PA((uint32_t)&_bufferDescriptorTable[0][0]) >> 16);
    U1BDTP3 = (uint8_t)(KVA_TO_PA((uint32_t)&_bufferDescriptorTable[0][0]) >> 24);


    // enable usb device mode
    U1CONbits.SOFEN = 1;
    U1OTGCONbits.DPPULUP = 1;
	U1OTGCONbits.OTGEN = 1;
	U1IR = 0xFF;
	U1IEbits.URSTIE = 1;
	U1EIE = 0xFF;

	setIntVector(_USB_1_VECTOR, _usbInterrupt);
	setIntPriority(_USB_1_VECTOR, 6, 0);
	clearIntFlag(_USB_IRQ);
	setIntEnable(_USB_IRQ);

	U1SOFbits.CNT = 74;

	U1PWRCbits.USBPWR = 1;

    addEndpoint(0, EP_IN, EP_CTL, 64, _ctlRxA, _ctlRxB);
    addEndpoint(0, EP_OUT, EP_CTL, 64, _ctlTxA, _ctlTxB);
	return true;
}

bool USBFS::disableUSB() {
	U1PWRCbits.USBPWR = 0;
	return true;
}
	

bool USBFS::addEndpoint(uint8_t id, uint8_t direction, uint8_t __attribute__((unused)) type, uint32_t size, uint8_t *a, uint8_t *b) {
	if (id > 15) return false;
    _endpointBuffers[id].data = 0x40;
    _endpointBuffers[id].size = size;
    _endpointBuffers[id].buffer = NULL;
    _endpointBuffers[id].bufferPtr = NULL;
	if (direction == EP_IN) {
        _endpointBuffers[id].rx[0] = a;
        _endpointBuffers[id].rx[1] = b;
		_bufferDescriptorTable[id][0].buffer = (uint8_t *)KVA_TO_PA((uint32_t)_endpointBuffers[id].rx[0]);
		_bufferDescriptorTable[id][0].flags = (_endpointBuffers[id].size << 16) | 0x80;
		_bufferDescriptorTable[id][1].buffer = (uint8_t *)KVA_TO_PA((uint32_t)_endpointBuffers[id].rx[1]);
		_bufferDescriptorTable[id][1].flags = (_endpointBuffers[id].size << 16) | 0x80;
		switch (id) {
			case 0: U1EP0bits.EPRXEN = 1; break;
			case 1: U1EP1bits.EPRXEN = 1; break;
			case 2: U1EP2bits.EPRXEN = 1; break;
			case 3: U1EP3bits.EPRXEN = 1; break;
			case 4: U1EP4bits.EPRXEN = 1; break;
			case 5: U1EP5bits.EPRXEN = 1; break;
			case 6: U1EP6bits.EPRXEN = 1; break;
			case 7: U1EP7bits.EPRXEN = 1; break;
			case 8: U1EP8bits.EPRXEN = 1; break;
			case 9: U1EP9bits.EPRXEN = 1; break;
			case 10: U1EP10bits.EPRXEN = 1; break;
			case 11: U1EP11bits.EPRXEN = 1; break;
			case 12: U1EP12bits.EPRXEN = 1; break;
			case 13: U1EP13bits.EPRXEN = 1; break;
			case 14: U1EP14bits.EPRXEN = 1; break;
			case 15: U1EP15bits.EPRXEN = 1; break;
		}
	} else {
        _endpointBuffers[id].tx[0] = a;
        _endpointBuffers[id].tx[1] = b;
		_bufferDescriptorTable[id][2].buffer = (uint8_t *)KVA_TO_PA((uint32_t)_endpointBuffers[id].tx[0]);
		_bufferDescriptorTable[id][2].flags = 0;
		_bufferDescriptorTable[id][3].buffer = (uint8_t *)KVA_TO_PA((uint32_t)_endpointBuffers[id].tx[1]);
		_bufferDescriptorTable[id][3].flags = 0;
		switch (id) {
			case 0: U1EP0bits.EPTXEN = 1; break;
			case 1: U1EP1bits.EPTXEN = 1; break;
			case 2: U1EP2bits.EPTXEN = 1; break;
			case 3: U1EP3bits.EPTXEN = 1; break;
			case 4: U1EP4bits.EPTXEN = 1; break;
			case 5: U1EP5bits.EPTXEN = 1; break;
			case 6: U1EP6bits.EPTXEN = 1; break;
			case 7: U1EP7bits.EPTXEN = 1; break;
			case 8: U1EP8bits.EPTXEN = 1; break;
			case 9: U1EP9bits.EPTXEN = 1; break;
			case 10: U1EP10bits.EPTXEN = 1; break;
			case 11: U1EP11bits.EPTXEN = 1; break;
			case 12: U1EP12bits.EPTXEN = 1; break;
			case 13: U1EP13bits.EPTXEN = 1; break;
			case 14: U1EP14bits.EPTXEN = 1; break;
			case 15: U1EP15bits.EPTXEN = 1; break;
		}
		_enabledEndpoints |= (1 << (id + 16));
	}

	
	switch (id) {
		case 0: U1EP0bits.EPHSHK = 1; break;
		case 1: U1EP1bits.EPHSHK = 1; break;
		case 2: U1EP2bits.EPHSHK = 1; break;
		case 3: U1EP3bits.EPHSHK = 1; break;
		case 4: U1EP4bits.EPHSHK = 1; break;
		case 5: U1EP5bits.EPHSHK = 1; break;
		case 6: U1EP6bits.EPHSHK = 1; break;
		case 7: U1EP7bits.EPHSHK = 1; break;
		case 8: U1EP8bits.EPHSHK = 1; break;
		case 9: U1EP9bits.EPHSHK = 1; break;
		case 10: U1EP10bits.EPHSHK = 1; break;
		case 11: U1EP11bits.EPHSHK = 1; break;
		case 12: U1EP12bits.EPHSHK = 1; break;
		case 13: U1EP13bits.EPHSHK = 1; break;
		case 14: U1EP14bits.EPHSHK = 1; break;
		case 15: U1EP15bits.EPHSHK = 1; break;
	}
	
	return true;
}

bool USBFS::canEnqueuePacket(uint8_t ep) {
    uint8_t buffer = _endpointBuffers[ep].txAB;
    uint8_t bdt_entry = buffer ? 3 : 2;
    if ((_bufferDescriptorTable[ep][bdt_entry].flags & 0x80) == 0) return true;
    return false;
}

bool USBFS::enqueuePacket(uint8_t ep, const uint8_t *data, uint32_t len) {
	bool sent = false;

    uint8_t buffer = _endpointBuffers[ep].txAB;
    uint8_t bdt_entry = buffer ? 3 : 2;

    while (!sent) {
        if ((_bufferDescriptorTable[ep][bdt_entry].flags & 0x80) == 0) {
            if (len > 0) memcpy(_endpointBuffers[ep].tx[buffer], data, min(len, _endpointBuffers[ep].size));
            _bufferDescriptorTable[ep][bdt_entry].flags = (len << 16) | 0x00 | _endpointBuffers[ep].data; 
            sent = true;
            _bufferDescriptorTable[ep][bdt_entry].flags |= 0x80;
        }
	}

    _endpointBuffers[ep].txAB = 1 - _endpointBuffers[ep].txAB;
	_endpointBuffers[ep].data = _endpointBuffers[ep].data ? 0 : 0x40;

	return true;
}

bool USBFS::sendBuffer(uint8_t ep, const uint8_t *data, uint32_t len) {

    uint32_t ts = millis();

    if (_inIsr) {
        while (_endpointBuffers[ep].buffer != NULL) {
            if (millis() - ts > USB_TX_TIMEOUT) return false;
            if (canEnqueuePacket(ep)) {
                if (_endpointBuffers[ep].length > 0) {
                    uint32_t toSend = min(_endpointBuffers[ep].size, _endpointBuffers[ep].length);
                    enqueuePacket(ep, _endpointBuffers[ep].bufferPtr, toSend);
                    _endpointBuffers[ep].length -= toSend;
                    _endpointBuffers[ep].bufferPtr += toSend;
                } else {
                    if (_endpointBuffers[ep].buffer != NULL) {
                        free(_endpointBuffers[ep].buffer);
                        _endpointBuffers[ep].buffer = NULL;
                    }
                }

            }
        }
    } else {
        while (_endpointBuffers[ep].buffer != NULL) {
            if (millis() - ts > USB_TX_TIMEOUT) {
                return false;
            }
        }
    }

    _endpointBuffers[ep].length = len;
    _endpointBuffers[ep].buffer = (uint8_t *)malloc(len);
    if (!_endpointBuffers[ep].buffer) {
        return false;
    }
    memcpy(_endpointBuffers[ep].buffer, data, len);
    _endpointBuffers[ep].bufferPtr = _endpointBuffers[ep].buffer;

    ts = millis();
    while (!canEnqueuePacket(ep)) {
        if (millis() - ts > USB_TX_TIMEOUT) return false;
    }

    uint32_t toSend = min(_endpointBuffers[ep].size, _endpointBuffers[ep].length);
    enqueuePacket(ep, _endpointBuffers[ep].bufferPtr, toSend);
    _endpointBuffers[ep].length -= toSend;
    _endpointBuffers[ep].bufferPtr += toSend;

    return true;
}

void USBFS::handleInterrupt() {
    uint32_t toSend;
    _inIsr = true;

	if (U1IRbits.TRNIF) {

		uint8_t ep = U1STATbits.ENDPT;
		uint8_t bdt_slot = U1STATbits.PPBI | (U1STATbits.DIR << 1);

		uint8_t pid = (_bufferDescriptorTable[ep][bdt_slot].flags >> 2) & 0x0F;

		switch (pid) {
			case 0x01: // OUT
                RXOn();
                if (_manager) _manager->onOutPacket(ep, _endpointBuffers[ep].rx[U1STATbits.PPBI], _bufferDescriptorTable[ep][bdt_slot].flags >> 16);
     //           _endpointBuffers[ep].data = _endpointBuffers[ep].data ? 0 : 0x40;
				_bufferDescriptorTable[ep][bdt_slot].flags = (_endpointBuffers[ep].size << 16) | 0x80 | _endpointBuffers[ep].data; 
				break;
			case 0x09: // IN
                TXOn();
                if (_endpointBuffers[ep].length > 0) {
                    toSend = min(_endpointBuffers[ep].size, _endpointBuffers[ep].length);
                    enqueuePacket(ep, _endpointBuffers[ep].bufferPtr, toSend);
                    _endpointBuffers[ep].length -= toSend;
                    _endpointBuffers[ep].bufferPtr += toSend;
                } else {
                    if (_endpointBuffers[ep].buffer != NULL) {
                        free(_endpointBuffers[ep].buffer);
                        _endpointBuffers[ep].buffer = NULL;
                    }
                }

                if (_manager) _manager->onInPacket(ep, _endpointBuffers[ep].rx[U1STATbits.PPBI], _bufferDescriptorTable[ep][bdt_slot].flags >> 16);
				break;
			case 0x0d: // SETUP
				_endpointBuffers[ep].data = 0x40;
                if (_manager) _manager->onSetupPacket(ep, _endpointBuffers[ep].rx[U1STATbits.PPBI], _bufferDescriptorTable[ep][bdt_slot].flags >> 16);
				_bufferDescriptorTable[ep][bdt_slot].flags = (_endpointBuffers[ep].size << 16) | 0x80;
				break;
			default:
				break;
		}

		U1CONbits.TOKBUSY=0;
	}
	if (U1IRbits.URSTIF) {
        _manager->setEnumerated(false);
		U1IEbits.IDLEIE = 1;
		U1IEbits.TRNIE = 1;
		U1ADDR = 0;
		U1CONbits.PPBRST = 1;
		U1CONbits.PPBRST = 0;
		for (int i  = 0; i < 16; i++) {
			_endpointBuffers[i].txAB = 0;
            _endpointBuffers[i].data = 0x40;

            _bufferDescriptorTable[i][0].flags |= 0x80;
            _bufferDescriptorTable[i][1].flags |= 0x80;

            _bufferDescriptorTable[i][2].flags &= 0x7F;
            _bufferDescriptorTable[i][3].flags &= 0x7F;

		}
	}
	if (U1IRbits.IDLEIF) {
		U1IEbits.IDLEIE = 0;
		U1IEbits.RESUMEIE = 1;
	}
	if (U1IRbits.RESUMEIF) {
		U1IEbits.IDLEIE = 1;
		U1IEbits.RESUMEIE = 0;
	}
	if (U1EIR) {
    
	}
	U1EIR = 0xFF;
	U1IR = 0xFF;
	clearIntFlag(_USB_IRQ);
    _inIsr = false;
}

bool USBFS::setAddress(uint8_t address) {
	U1ADDR = address;
	return true;
}

bool USBFS::isIdle(uint8_t ep) {
    return (_endpointBuffers[ep].buffer == NULL);
}

#endif // __PIC32MX__
#endif // _USB
