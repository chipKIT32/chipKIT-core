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

#include <USB.h>

#define CDC_ACT_SET_LINE_CODING 1

struct CDCLineCoding {
    uint32_t dwDTERate;
    uint8_t bCharFormat;
    uint8_t bParityType;
    uint8_t bDataBits;
} __attribute__((packed));


uint16_t CDCACM::getDescriptorLength() {
    return 58 + 8;
}

uint8_t CDCACM::getInterfaceCount() {
    return 2;
}

uint32_t CDCACM::populateConfigurationDescriptor(uint8_t *buf) {
    uint8_t i = 0;

    buf[i++] =     8;                                      // bLength
    buf[i++] =     11;                                     // bDescriptorType
    buf[i++] =     _ifControl;                             // bFirstInterface
    buf[i++] =     2;                                      // bInterfaceCount
    buf[i++] =     0x02;                                   // bFunctionClass
    buf[i++] =     0x02;                                   // bFunctionSubClass
    buf[i++] =     0x01;                                   // bFunctionProtocol
    buf[i++] =     0; // iFunction


    buf[i++] = 9;          // length
    buf[i++] = 0x04;       // interface descriptor
    buf[i++] = _ifControl; // interface number
    buf[i++] = 0x00;       // alternate
    buf[i++] = 0x01;       // num endpoints
    buf[i++] = 0x02;       // interface class (comm)
    buf[i++] = 0x02;       // subclass (acm)
    buf[i++] = 0x01;       // protocol (at)
    buf[i++] = 0;           // iInterface

    buf[i++] = 5;          // length
    buf[i++] = 0x24;       // header functional descriptor
    buf[i++] = 0x00;
    buf[i++] = 0x10; 
    buf[i++] = 0x01;

    buf[i++] = 4;          // length
    buf[i++] = 0x24;       // abstract control model descriptor
    buf[i++] = 0x02;
    buf[i++] = 0x06;

    buf[i++] = 5;          // length
    buf[i++] = 0x24;       // union functional descriptor
    buf[i++] = 0x06;
    buf[i++] = _ifControl;
    buf[i++] = _ifBulk;

    buf[i++] = 5;          // length
    buf[i++] = 0x24;       // call management functional descriptor
    buf[i++] = 0x01;
    buf[i++] = 0x00;
    buf[i++] = _ifBulk;

    buf[i++] = 7;          // length
    buf[i++] = 0x05;       // endpoint descriptor
    buf[i++] = 0x80 | _epControl;       // endpoint IN address
    buf[i++] = 0x03;       // attributes: interrupt
    buf[i++] = 0x08; 
    buf[i++] = 0x00; // packet size
    buf[i++] = 0x10;       // interval (ms)

    buf[i++] = 9;          // length
    buf[i++] = 0x04;       // interface descriptor
    buf[i++] = _ifBulk;       // interface number
    buf[i++] = 0x00;       // alternate
    buf[i++] = 0x02;       // num endpoints
    buf[i++] = 0x0a;       // interface class (data)
    buf[i++] = 0x00;       // subclass
    buf[i++] = 0x00;       // protocol
    buf[i++] = 0;           // iInterface

    buf[i++] = 7;          // length
    buf[i++] = 0x05;       // endpoint descriptor
    buf[i++] = 0x80 | _epBulk;       // endpoint IN address
    buf[i++] = 0x02;       // attributes: bulk
    if (_manager->isHighSpeed()) {
        buf[i++] = 0x00; 
        buf[i++] = 0x02;     // packet size
    } else {
        buf[i++] = 0x40; 
        buf[i++] = 0x00;     // packet size
    }
    buf[i++] = 0x00;       // interval (ms)

    buf[i++] = 7;          // length
    buf[i++] = 0x05;       // endpoint descriptor
    buf[i++] = _epBulk;       // endpoint OUT address
    buf[i++] = 0x02;       // attributes: bulk
    if (_manager->isHighSpeed()) {
        buf[i++] = 0x00; 
        buf[i++] = 0x02;     // packet size
    } else {
        buf[i++] = 0x40; 
        buf[i++] = 0x00;     // packet size
    }
    buf[i++] = 0x00;       // interval (ms)
    return i;
}


void CDCACM::initDevice(USBManager *manager) {
    _manager = manager;
    _ifControl = _manager->allocateInterface();
    _ifBulk = _manager->allocateInterface();
    _epControl = _manager->allocateEndpoint();
    _epBulk = _manager->allocateEndpoint();
}

bool CDCACM::getDescriptor(uint8_t __attribute__((unused)) ep, uint8_t __attribute__((unused)) target, uint8_t __attribute__((unused)) id, uint8_t __attribute__((unused)) maxlen) {
    return false;
}

void CDCACM::configureEndpoints() {
    _manager->addEndpoint(_epControl, EP_OUT, EP_CTL, 8, _ctlA, _ctlB);
    if (_manager->isHighSpeed()) {
        _manager->addEndpoint(_epBulk, EP_IN, EP_BLK, 512, _bulkRxA, _bulkRxB);
        _manager->addEndpoint(_epBulk, EP_OUT, EP_BLK, 512, _bulkTxA, _bulkTxB);
    } else {
        _manager->addEndpoint(_epBulk, EP_IN, EP_BLK, 64, _bulkRxA, _bulkRxB);
        _manager->addEndpoint(_epBulk, EP_OUT, EP_BLK, 64, _bulkTxA, _bulkTxB);
    }
}


bool CDCACM::onSetupPacket(uint8_t __attribute__((unused)) ep, uint8_t __attribute__((unused)) target, uint8_t *data, uint32_t __attribute__((unused)) l) {
    if (data[4] == _ifControl) {
        uint16_t signature = (data[0] << 8) | data[1];
        switch (signature) {
            case 0x2120:
                _outAction = CDC_ACT_SET_LINE_CODING;
                return true;
            case 0x2122:
                _lineState = data[2];
                if ((_lineState == 0) && (_baud == 1200)) {
                    executeSoftReset(ENTER_BOOTLOADER_ON_BOOT);
                }
                _manager->sendBuffer(0, NULL, 0);
                return true;
            case 0xA121: {
                    struct CDCLineCoding lc;
                    lc.dwDTERate = _baud;
                    lc.bCharFormat = _stopBits;
                    lc.bParityType = _parity;
                    lc.bDataBits = _dataBits;
                    _manager->sendBuffer(0, (const uint8_t *)&lc, 7);
                    return true;
                }
                break;
        }
    }
    return false;
}

bool CDCACM::onInPacket(uint8_t ep, uint8_t target, uint8_t __attribute__((unused)) *data, uint32_t __attribute__((unused)) l) {
    if ((ep == 0) && (target == _ifControl)) {
        return true;
    }
    return false;
}

bool CDCACM::onOutPacket(uint8_t ep, uint8_t target, uint8_t *data, uint32_t l) {
    if (ep == 0) {
        if (target == _ifControl) {
            switch(_outAction) {
                case CDC_ACT_SET_LINE_CODING:
                    struct CDCLineCoding *coding = (struct CDCLineCoding *)data;
                    if ((coding->dwDTERate == 0) && (_baud == 1200)) {
                        executeSoftReset(ENTER_BOOTLOADER_ON_BOOT);
                    }
                    _baud = coding->dwDTERate;
                    _stopBits = coding->bCharFormat;
                    _parity = coding->bParityType;
                    _dataBits = coding->bDataBits;
                    _manager->sendBuffer(0, NULL, 0);
                    return true;
            }
        }
    }

    if (ep == _epBulk) {


        for (uint32_t i = 0; i < l; i++) {
            uint32_t bufIndex = (_rxHead + 1) % CDCACM_BUFFER_SIZE;
            if (bufIndex != _rxTail) {
                _rxBuffer[_rxHead] = data[i];
                _rxHead = bufIndex;
            }
        }

        int remaining = (_rxTail - _rxHead + CDCACM_BUFFER_SIZE) % CDCACM_BUFFER_SIZE;

        if ((remaining < CDCACM_BUFFER_HIGH) && (_rxHead != _rxTail)) {
            _manager->haltEndpoint(_epBulk);
        }

        return true;
    }
    return false;
}

size_t CDCACM::write(uint8_t b) {

    if (_lineState == 0) return 0;

    _manager->sendBuffer(_epBulk, &b, 1);
    return 1;
}

size_t CDCACM::write(const uint8_t *b, size_t len) {

    if (_lineState == 0) return 0;

    size_t pos = 0;
    int32_t slen = len;
    uint32_t packetSize = _manager->isHighSpeed() ? 512 : 64;
    while (pos < len) {
        int32_t toSend = min((int32_t)packetSize, slen);
        while (!_manager->canEnqueuePacket(_epBulk)) {
        }
        _manager->enqueuePacket(_epBulk, &b[pos], toSend);
        pos += toSend;
        slen -= toSend;
    }
    return 1;
}

int CDCACM::available() {
    return (CDCACM_BUFFER_SIZE + _rxHead - _rxTail) % CDCACM_BUFFER_SIZE;
}

int CDCACM::read() {
    if (_rxHead == _rxTail) return -1;
    uint8_t ch = _rxBuffer[_rxTail];
    _rxTail = (_rxTail + 1) % CDCACM_BUFFER_SIZE;

    int remaining = (_rxTail - _rxHead + CDCACM_BUFFER_SIZE) % CDCACM_BUFFER_SIZE;

    if ((remaining >= CDCACM_BUFFER_HIGH) || (_rxHead == _rxTail)) {
        _manager->resumeEndpoint(_epBulk);
    }

    return ch;
}

void CDCACM::flush() {
}

CDCACM::operator int() {
    return _lineState > 0;
}

int CDCACM::peek() {
    if (_rxHead == _rxTail) return -1;
    return _rxBuffer[_rxTail];
}

void CDCACM::onEnumerated() {
    _manager->sendBuffer(_epBulk, (uint8_t *)"\0", 1);
}

#endif // _USB

