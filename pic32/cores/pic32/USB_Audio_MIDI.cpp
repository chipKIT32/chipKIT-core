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

uint16_t Audio_MIDI::getDescriptorLength() {
    return (8+9+9 + 9+7+6+6+9+9+9+5+9+5);
}

uint8_t Audio_MIDI::getInterfaceCount() {
    return 2;
}

uint32_t Audio_MIDI::populateConfigurationDescriptor(uint8_t *buf) {
    uint8_t i = 0;

    buf[i++] =     8;                                      // bLength
    buf[i++] =     11;                                     // bDescriptorType
    buf[i++] =     _ifCtl;                                 // bFirstInterface
    buf[i++] =     2;                                      // bInterfaceCount
    buf[i++] =     0x01;                                   // bFunctionClass
    buf[i++] =     0x01;                                   // bFunctionSubClass
    buf[i++] =     0x00;                                   // bFunctionProtocol
    buf[i++] =     0; // iFunction

    buf[i++] = 9;
    buf[i++] = 4;
    buf[i++] = _ifCtl;
    buf[i++] = 0;
    buf[i++] = 0;
    buf[i++] = 1;
    buf[i++] = 1;
    buf[i++] = 0;
    buf[i++] = 0;

    buf[i++] = 9;
    buf[i++] = 36;
    buf[i++] = 1;
    buf[i++] = 0;
    buf[i++] = 1;
    buf[i++] = 9;
    buf[i++] = 0;
    buf[i++] = 1;
    buf[i++] = _ifBulk;

    buf[i++] = 9;                                // bLength
    buf[i++] = 4;                                // bDescriptorType
    buf[i++] = _ifBulk;                          // bInterfaceNumber
    buf[i++] = 0;                                // bAlternateSetting
    buf[i++] = 2;                                // bNumEndpoints
    buf[i++] = 0x01;                             // bInterfaceClass (0x01 = Audio)
    buf[i++] = 0x03;                             // bInterfaceSubClass (0x03 = MIDI)
    buf[i++] = 0x00;                             // bInterfaceProtocol (unused for MIDI)
    buf[i++] = 0;                                // iInterface

    buf[i++] = 7;                                // bLength
    buf[i++] = 0x24;                             // bDescriptorType = CS_INTERFACE
    buf[i++] = 0x01;                             // bDescriptorSubtype = MS_HEADER
    buf[i++] = 0x00; 
    buf[i++] = 0x01;                             // bcdMSC = revision 01.00
    buf[i++] = 0x41; 
    buf[i++] = 0x00;                             // wTotalLength

    buf[i++] = 6;                                // bLength
    buf[i++] = 0x24;                             // bDescriptorType = CS_INTERFACE
    buf[i++] = 0x02;                             // bDescriptorSubtype = MIDI_IN_JACK
    buf[i++] = 0x01;                             // bJackType = EMBEDDED
    buf[i++] = 1;                                // bJackID; ID = 1
    buf[i++] = 0;                                // iJack

    buf[i++] = 6;                                // bLength
    buf[i++] = 0x24;                             // bDescriptorType = CS_INTERFACE
    buf[i++] = 0x02;                             // bDescriptorSubtype = MIDI_IN_JACK
    buf[i++] = 0x02;                             // bJackType = EXTERNAL
    buf[i++] = 2;                                // bJackID; ID = 2
    buf[i++] = 0;                                // iJack

    buf[i++] = 9;
    buf[i++] = 0x24;                             // bDescriptorType = CS_INTERFACE
    buf[i++] = 0x03;                             // bDescriptorSubtype = MIDI_OUT_JACK
    buf[i++] = 0x01;                             // bJackType = EMBEDDED
    buf[i++] = 3;                                // bJackID; ID = 3
    buf[i++] = 1;                                // bNrInputPins = 1 pin
    buf[i++] = 2;                                // BaSourceID(1) = 2
    buf[i++] = 1;                                // BaSourcePin(1) = first pin
    buf[i++] = 0;                                // iJack

    buf[i++] = 9;
    buf[i++] = 0x24;                             // bDescriptorType = CS_INTERFACE
    buf[i++] = 0x03;                             // bDescriptorSubtype = MIDI_OUT_JACK
    buf[i++] = 0x02;                             // bJackType = EXTERNAL
    buf[i++] = 4;                                // bJackID; ID = 4
    buf[i++] = 1;                                // bNrInputPins = 1 pin
    buf[i++] = 1;                                // BaSourceID(1) = 1
    buf[i++] = 1;                                // BaSourcePin(1) = first pin
    buf[i++] = 0;                                // iJack

    buf[i++] = 9;                                // bLength
    buf[i++] = 5;                                // bDescriptorType = ENDPOINT
    buf[i++] = 0x80 | _epBulk;                   // bEndpointAddress
    buf[i++] = 0x02;                             // bmAttributes (0x02=bulk)
    if (_manager->isHighSpeed()) {
        buf[i++] = 0x00;                     // |
        buf[i++] = 0x02;                        // wMaxPacketSize
    } else {
        buf[i++] = 0x08;                     // |   0x40
        buf[i++] = 0x00;                        // wMaxPacketSize
    }
    buf[i++] = 0;                                // bInterval
    buf[i++] = 0;                                // bRefresh
    buf[i++] = 0;                                // bSynchAddress

    buf[i++] = 5;                                // bLength
    buf[i++] = 0x25;                             // bDescriptorSubtype = CS_ENDPOINT
    buf[i++] = 0x01;                             // bJackType = MS_GENERAL
    buf[i++] = 1;                                // bNumEmbMIDIJack = 1 jack
    buf[i++] = 3;                                // BaAssocJackID(1) = jack ID #3

    buf[i++] = 9;                                // bLength
    buf[i++] = 5;                                // bDescriptorType = ENDPOINT
    buf[i++] = _epBulk;                          // bEndpointAddress
    buf[i++] = 0x02;                             // bmAttributes (0x02=bulk)
    if (_manager->isHighSpeed()) {
        buf[i++] = 0x00;                     // |
        buf[i++] = 0x02;                        // wMaxPacketSize
    } else {
        buf[i++] = 0x08;                     // |   0x40
        buf[i++] = 0x00;                        // wMaxPacketSize
    }
    buf[i++] = 0;                                // bInterval
    buf[i++] = 0;                                // bRefresh
    buf[i++] = 0;                                // bSynchAddress

    buf[i++] = 5;                                // bLength
    buf[i++] = 0x25;                             // bDescriptorSubtype = CS_ENDPOINT
    buf[i++] = 0x01;                             // bJackType = MS_GENERAL
    buf[i++] = 1;                                // bNumEmbMIDIJack = 1 jack
    buf[i++] = 1;                                // BaAssocJackID(1) = jack ID #1

    return i;
}


void Audio_MIDI::initDevice(USBManager *manager) {
    _manager = manager;
    _ifCtl = _manager->allocateInterface();
    _ifBulk = _manager->allocateInterface();
    _epBulk = _manager->allocateEndpoint();
}

bool Audio_MIDI::getDescriptor(uint8_t __attribute__((unused)) ep, uint8_t __attribute__((unused)) target, uint8_t __attribute__((unused)) id, uint8_t __attribute__((unused)) maxlen) {
    return false;
}

bool Audio_MIDI::getReportDescriptor(uint8_t __attribute__((unused)) ep, uint8_t __attribute__((unused)) target, uint8_t __attribute__((unused)) id, uint8_t __attribute__((unused)) maxlen) {
    return false;
}

void Audio_MIDI::configureEndpoints() {
    if (_manager->isHighSpeed()) {
        _manager->addEndpoint(_epBulk, EP_IN, EP_BLK, 512, _bulkRxA, _bulkRxB);
        _manager->addEndpoint(_epBulk, EP_OUT, EP_BLK, 512, _bulkTxA, _bulkTxB);
    } else {
        _manager->addEndpoint(_epBulk, EP_IN, EP_BLK, 8, _bulkRxA, _bulkRxB);
        _manager->addEndpoint(_epBulk, EP_OUT, EP_BLK, 8, _bulkTxA, _bulkTxB);
    }
}


bool Audio_MIDI::onSetupPacket(uint8_t __attribute__((unused)) ep, uint8_t __attribute__((unused)) target, uint8_t __attribute__((unused)) *data, uint32_t __attribute__((unused)) l) {
    return false;
}

bool Audio_MIDI::onInPacket(uint8_t __attribute__((unused)) ep, uint8_t __attribute__((unused)) target, uint8_t __attribute__((unused)) *data, uint32_t __attribute__((unused)) l) {
    return false;
}

bool Audio_MIDI::onOutPacket(uint8_t ep, uint8_t __attribute__((unused)) target, uint8_t *data, uint32_t l) {
    if (ep == _epBulk) {
        if (_onMidiMessage != NULL) {
            for (uint32_t i = 0; i < l; i += 4) {
                _onMidiMessage(data[i+1], data[i+2], data[i+3]);
            }
        }
        _manager->sendBuffer(_epBulk, NULL, 0);
    }
    return false;
}

bool Audio_MIDI::sendMessage(uint8_t cable, uint8_t code, uint8_t b0, uint8_t b1, uint8_t b2) {
//    uint32_t msg = ((cable & 0xF) << 28) | ((code & 0xF) << 24) | (b0 << 16) | (b1 << 8) | b2;
    uint32_t msg = ((cable & 0xF) << 4) | ((code & 0xF) << 0) | (b0 << 8) | (b1 << 16) | (b2 << 24);
    uint32_t ts = millis();
    while (!_manager->sendBuffer(_epBulk, (uint8_t *)&msg, 4)) {
        if (millis() - ts > USB_TX_TIMEOUT) return false;
    }
    return true;
}

bool Audio_MIDI::noteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
    return sendMessage(0, 0x09, 0x90 | (channel & 0xF), note & 0x7F, velocity);
}

bool Audio_MIDI::noteOff(uint8_t channel, uint8_t note) {
    return sendMessage(0, 0x08, 0x80 | (channel & 0xF), note & 0x7F, 0);
}

void Audio_MIDI::onMidiMessage(void (*func)(uint8_t status, uint8_t d0, uint8_t d1)) {
    _onMidiMessage = func;
}

void Audio_MIDI::onEnumerated() {
}


#endif // _USB
