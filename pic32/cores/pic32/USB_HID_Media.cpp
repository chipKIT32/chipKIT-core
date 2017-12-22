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

uint16_t HID_Media::getDescriptorLength() {
    return (9 + 9 + 7);
}

uint8_t HID_Media::getInterfaceCount() {
    return 1;
}

static const uint8_t mediaHidReport[] = {
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
    0x09, 0x80,                    // USAGE (System Control)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x85, 0x01,                    //   REPORT_ID (1)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)
    0x75, 0x01,                    //   REPORT_SIZE (1)
    0x09, 0x81,                    //   USAGE (System Power Down)
    0x09, 0x82,                    //   USAGE (System Sleep)
    0x09, 0x83,                    //   USAGE (System Wake Up)
    0x09, 0x84,                    //   USAGE (System Context Menu)
    0x09, 0x85,                    //   USAGE (System Main Menu)
    0x09, 0x86,                    //   USAGE (System App Menu)
    0x09, 0x87,                    //   USAGE (System Help Menu)
    0x09, 0x88,                    //   USAGE (System Menu Exit)
    0x09, 0x89,                    //   USAGE (System Menu Select)
    0x09, 0x8a,                    //   USAGE (System Menu Right)
    0x09, 0x8b,                    //   USAGE (System Menu Left)
    0x09, 0x8c,                    //   USAGE (System Menu Up)
    0x09, 0x8d,                    //   USAGE (System Menu Down)
    0x95, 0x0d,                    //   REPORT_COUNT (13)
    0x81, 0x06,                    //   INPUT (Data,Var,Rel)
    0x95, 0x03,                    //   REPORT_COUNT (3)
    0x81, 0x01,                    //   INPUT (Cnst,Ary,Abs)
    0xc0,                          // END_COLLECTION
    0x05, 0x0c,                    // USAGE_PAGE (Consumer Devices)
    0x09, 0x01,                    // USAGE (Consumer Control)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x85, 0x02,                    //   REPORT_ID (2)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)
    0x75, 0x01,                    //   REPORT_SIZE (1)
    0x09, 0xb0,                    //   USAGE (Play)
    0x09, 0xb1,                    //   USAGE (Pause)
    0x09, 0xb2,                    //   USAGE (Record)
    0x09, 0xb3,                    //   USAGE (Fast Forward)
    0x09, 0xb4,                    //   USAGE (Rewind)
    0x09, 0xb5,                    //   USAGE (Scan Next Track)
    0x09, 0xb6,                    //   USAGE (Scan Previous Track)
    0x09, 0xb7,                    //   USAGE (Stop)
    0x09, 0xb8,                    //   USAGE (Eject)
    0x09, 0xe2,                    //   USAGE (Mute)
    0x09, 0xe9,                    //   USAGE (Volume Up)
    0x09, 0xea,                    //   USAGE (Volume Down)
    0x09, 0x46,                    //   USAGE (Menu Escape)
    0x09, 0x45,                    //   USAGE (Menu Right)
    0x09, 0x44,                    //   USAGE (Menu Left)
    0x09, 0x43,                    //   USAGE (Menu Down)
    0x09, 0x42,                    //   USAGE (Menu Up)
    0x09, 0x41,                    //   USAGE (Menu  Pick)
    0x09, 0x40,                    //   USAGE (Menu)
    0x95, 0x13,                    //   REPORT_COUNT (19)
    0x81, 0x02,                    //   INPUT (Data,Var,Abs)
    0x95, 0x0d,                    //   REPORT_COUNT (13)
    0x81, 0x01,                    //   INPUT (Cnst,Ary,Abs)
    0xc0                           // END_COLLECTION
};

uint32_t HID_Media::populateConfigurationDescriptor(uint8_t *buf) {
    uint8_t i = 0;
    buf[i++] =                      0x09;
    buf[i++] =                      0x04;
    buf[i++] =                      _ifInt;
    buf[i++] =                      0;
    buf[i++] =                      1;
    buf[i++] =                      0x03;
    buf[i++] =                      0x00;
    buf[i++] =                      1;
    buf[i++] =                      0;

    /* HID Class-Specific Descriptor */

    buf[i++] =                      0x09;
    buf[i++] =                      0x21;
    buf[i++] =                      0x11;
    buf[i++] =                      0x01;
    buf[i++] =                      0x00;
    buf[i++] =                      1;
    buf[i++] =                      0x22;
    buf[i++] =                      sizeof(mediaHidReport) & 0xFF;
    buf[i++] =                      sizeof(mediaHidReport) >> 8;

    /* Endpoint Descriptor */

    buf[i++] =                      0x07;
    buf[i++] =                      0x05;
    buf[i++] =                      0x80 | _epInt;
    buf[i++] =                      0x03;
    buf[i++] =                      0x08; // Size = 8
    buf[i++] =                      0x00;
    buf[i++] =                      1;

    return i;
}


void HID_Media::initDevice(USBManager *manager) {
    _manager = manager;
    _ifInt = _manager->allocateInterface();
    _epInt = _manager->allocateEndpoint();
}

bool HID_Media::getDescriptor(uint8_t __attribute__((unused)) ep, uint8_t __attribute__((unused)) target, uint8_t __attribute__((unused)) id, uint8_t __attribute__((unused)) maxlen) {
    return false;
}

bool HID_Media::getReportDescriptor(uint8_t __attribute__((unused)) ep, uint8_t target, uint8_t __attribute__((unused)) id, uint8_t maxlen) {
    if (target == _ifInt) {
        uint32_t ts = millis();
        while (!_manager->sendBuffer(0, mediaHidReport, min(sizeof(mediaHidReport), maxlen))) {
            if (millis() - ts > USB_TX_TIMEOUT) {
                return false;
            }
        }
        return true;
    }
    return false;
}

void HID_Media::configureEndpoints() {
    _manager->addEndpoint(_epInt, EP_OUT, EP_INT, 8, _intA, _intB);
}


bool HID_Media::onSetupPacket(uint8_t __attribute__((unused)) ep, uint8_t __attribute__((unused)) target, uint8_t *data, uint32_t __attribute__((unused)) l) {
    if (data[4] != _ifInt) return false;

    uint16_t signature = (data[0] << 8) | data[1];
    switch (signature) {
        case 0xA101: {
                if (data[2] == 1) {
                    uint8_t buf[3] = {1, 0, 0};
                    _manager->sendBuffer(0, buf, 3);
                } else if (data[2] == 2) {
                    uint8_t buf[5] = {2, 0, 0, 0, 0};
                    _manager->sendBuffer(0, buf, 5);
                }
                return true;
            }
            break;
    }
    return false;

}

bool HID_Media::onInPacket(uint8_t __attribute__((unused)) ep, uint8_t __attribute__((unused)) target, uint8_t __attribute__((unused)) *data, uint32_t __attribute__((unused)) l) {
    return false;
}

bool HID_Media::onOutPacket(uint8_t ep, uint8_t target, uint8_t __attribute__((unused)) *data, uint32_t __attribute__((unused)) l) {
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

void HID_Media::sendReport(uint8_t id, uint16_t data) {
    uint8_t buf[3];
    buf[0] = id;
    buf[1] = data & 0xFF;
    buf[2] = data >> 8;
    uint32_t ts = millis();
    while(!_manager->sendBuffer(_epInt, buf, 3)) {
        if (millis() - ts > USB_TX_TIMEOUT) return;
    }
}

void HID_Media::sendReport(uint8_t id, uint32_t data) {
    uint8_t buf[5];
    buf[0] = id;
    buf[1] = data & 0xFF;
    buf[2] = data >> 8;
    buf[3] = data >> 16;
    buf[4] = data >> 24;
    uint32_t ts = millis();
    while(!_manager->sendBuffer(_epInt, buf, 5)) {
        if (millis() - ts > USB_TX_TIMEOUT) return;
    }
}

size_t HID_Media::pressSystem(uint16_t k) {
    _systemKeys |= k;
    sendReport(1, _systemKeys);
    return 1;
}

size_t HID_Media::releaseSystem(uint16_t k) {
    _systemKeys &= ~k;
    sendReport(1, _systemKeys);
    return 1;
}

size_t HID_Media::pressConsumer(uint32_t k) {
    _consumerKeys |= k;
    sendReport(2, _consumerKeys);
    return 1;
}

size_t HID_Media::releaseConsumer(uint32_t k) {
    _consumerKeys &= ~k;
    sendReport(2, _consumerKeys);
    return 1;
}

void HID_Media::releaseAll(void)
{
    _consumerKeys = 0;
    _systemKeys = 0;
    sendReport(1, _systemKeys);
    sendReport(2, _consumerKeys);
}

void HID_Media::releaseAllSystem(void)
{
    _systemKeys = 0;
    sendReport(1, _systemKeys);
}

void HID_Media::releaseAllConsumer(void)
{
    _consumerKeys = 0;
    sendReport(2, _consumerKeys);
}

void HID_Media::onEnumerated() {
    releaseAll();
}

#endif // _USB
