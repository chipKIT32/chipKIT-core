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

static const uint8_t tabletHidReport[] = {
    //  Mouse
    0x05, 0x01, // USAGE_PAGE (Generic Desktop) // 54
    0x09, 0x02, // USAGE (Mouse)
    0xa1, 0x01, // COLLECTION (Application)
    0x09, 0x01, //   USAGE (Pointer)
    0xa1, 0x00, //   COLLECTION (Physical)
    0x05, 0x09, //     USAGE_PAGE (Button)
    0x19, 0x01, //     USAGE_MINIMUM (Button 1)
    0x29, 0x03, //     USAGE_MAXIMUM (Button 3)
    0x15, 0x00, //     LOGICAL_MINIMUM (0)
    0x25, 0x01, //     LOGICAL_MAXIMUM (1)
    0x95, 0x03, //     REPORT_COUNT (3)
    0x75, 0x01, //     REPORT_SIZE (1)
    0x81, 0x02, //     INPUT (Data,Var,Abs)
    0x95, 0x01, //     REPORT_COUNT (1)
    0x75, 13, //     REPORT_SIZE (13)
    0x81, 0x03, //     INPUT (Cnst,Var,Abs)
    0x05, 0x01, //     USAGE_PAGE (Generic Desktop)

    0x09, 0x30, //     USAGE (X)
    0x15, 0x00, //     LOGICAL_MINIMUM (0)
    0x26, 0xff, 0x7f,  //     LOGICAL_MAXIMUM (32767)
#define THR_W_L 39
#define THR_W_H 40
    0x75, 16, //     REPORT_SIZE (16)
    0x95, 1, //     REPORT_COUNT (1)
    0x81, 0x02, //     INPUT (Data,Var,Abs)

    0x09, 0x31, //     USAGE (Y)
    0x15, 0x00, //     LOGICAL_MINIMUM (0)
    0x26, 0xff, 0x7f,  //     LOGICAL_MAXIMUM (32767)
#define THR_H_L 52
#define THR_H_H 53
    0x75, 16, //     REPORT_SIZE (16)
    0x95, 1, //     REPORT_COUNT (1)
    0x81, 0x02, //     INPUT (Data,Var,Abs)

    0xc0, //   END_COLLECTION
    0xc0, // END_COLLECTION
};


uint32_t HID_Tablet::populateConfigurationDescriptor(uint8_t *buf) {
    uint8_t i = 0;
    buf[i++] =                      0x09;
    buf[i++] =                      0x04;
    buf[i++] =                      _ifInt;
    buf[i++] =                      0;
    buf[i++] =                      1;
    buf[i++] =                      0x03;
    buf[i++] =                      0x00;
    buf[i++] =                      2;
    buf[i++] =                      0;

    /* HID Class-Specific Descriptor */

    buf[i++] =                      0x09;
    buf[i++] =                      0x21;
    buf[i++] =                      0x11;
    buf[i++] =                      0x01;
    buf[i++] =                      0x00;
    buf[i++] =                      1;
    buf[i++] =                      0x22;
    buf[i++] =                      sizeof(tabletHidReport) & 0xFF;
    buf[i++] =                      sizeof(tabletHidReport) >> 8;

    /* Endpoint Descriptor */

    buf[i++] =                      0x07;
    buf[i++] =                      0x05;
    buf[i++] =                      0x80 | _epInt;
    buf[i++] =                      0x03;
    buf[i++] =                      0x10; // Size = 16
    buf[i++] =                      0x00;
    buf[i++] =                      1;

    return i;
}

bool HID_Tablet::getReportDescriptor(uint8_t __attribute__((unused)) ep, uint8_t target, uint8_t __attribute__((unused)) id, uint8_t maxlen) {
    if (target == _ifInt) {
        uint8_t temp[sizeof(tabletHidReport)];
        memcpy(temp, tabletHidReport, sizeof(tabletHidReport));
        temp[THR_W_L] = _w & 0xFF;
        temp[THR_W_H] = (_w >> 8) & 0xFF;
        temp[THR_H_L] = _h & 0xFF;
        temp[THR_H_H] = (_h >> 8) & 0xFF;
        _manager->sendBuffer(0, temp, min(sizeof(tabletHidReport), maxlen));
        return true;
    }
    return false;
}

uint16_t HID_Tablet::getDescriptorLength() {
    return (9 + 9 + 7);
}


uint8_t HID_Tablet::getInterfaceCount() {
    return 1;
}

void HID_Tablet::initDevice(USBManager *manager) {
    _manager = manager;
    _ifInt = _manager->allocateInterface();
    _epInt = _manager->allocateEndpoint();
}

bool HID_Tablet::getDescriptor(uint8_t __attribute__((unused)) ep, uint8_t __attribute__((unused)) target, uint8_t __attribute__((unused)) id, uint8_t __attribute__((unused)) maxlen) {
    return false;
}

void HID_Tablet::configureEndpoints() {
    _manager->addEndpoint(_epInt, EP_OUT, EP_INT, 16, _intA, _intB);
}


bool HID_Tablet::onSetupPacket(uint8_t __attribute__((unused)) ep, uint8_t __attribute__((unused)) target, uint8_t *data, uint32_t __attribute__((unused)) l) {

    if (data[4] != _ifInt) return false;

    uint16_t signature = (data[0] << 8) | data[1];
    switch (signature) {
        case 0xA101: {
                uint16_t m[3];
                m[0] = _buttons;
                m[1] = _x;
                m[2] = _y;
                _manager->sendBuffer(0, (uint8_t *)m, 6);
                return true;
            }
            break;
    }
    return false;
}

bool HID_Tablet::onInPacket(uint8_t __attribute__((unused)) ep, uint8_t __attribute__((unused)) target, uint8_t __attribute__((unused)) *data, uint32_t __attribute__((unused)) l) {
    return false;
}

bool HID_Tablet::onOutPacket(uint8_t ep, uint8_t target, uint8_t __attribute__((unused)) *data, uint32_t __attribute__((unused)) l) {
    if (ep == 0) {
        if (target == _ifInt) {
            return true;
        }
    }

    if (ep == _epInt) {
        return true;
    }
    return false;
}

void HID_Tablet::sendReport(const uint8_t *b, uint8_t l) {
    uint32_t ts = millis();
    while (!_manager->sendBuffer(_epInt, b, l)) {
        if (millis() - ts > USB_TX_TIMEOUT) {
            digitalWrite(3, HIGH);
            return;
        }
    }
}

void HID_Tablet::click(uint8_t b) {
    press(b);
    release(b);
}

void HID_Tablet::update() {
    uint16_t m[3];
    m[0] = _buttons;
    m[1] = _x;
    m[2] = _y;
    sendReport((uint8_t *)m, 6); 
}

void HID_Tablet::move(uint16_t x, uint16_t y) {
    _x = x;
    _y = y;
    update();
}

void HID_Tablet::buttons(uint8_t b) {
    if (b != _buttons) {
        _buttons = b;
        update();
    }
}

void HID_Tablet::press(uint8_t b) {
    buttons(_buttons | b);
}

void HID_Tablet::release(uint8_t b) {
    buttons(_buttons & ~b);
}

bool HID_Tablet::isPressed(uint8_t b) {
    if ((b & _buttons) > 0)
        return true;
    return false;
}

void HID_Tablet::onEnumerated() {
}

#endif
