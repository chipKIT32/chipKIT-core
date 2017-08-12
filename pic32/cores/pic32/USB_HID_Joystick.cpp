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


uint16_t HID_Joystick::getDescriptorLength() {
    return (9 + 9 + 7);
}

uint8_t HID_Joystick::getInterfaceCount() {
    return 1;
}

static const uint8_t joystickHidReport[] = {
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
    0x09, 0x04,                    // USAGE (Joystick)
    0xa1, 0x01,                    // COLLECTION (Application)
    0xa1, 0x02,                    //   COLLECTION (Logical)
    0x75, 0x08,                    //     REPORT_SIZE (8)
    0x95, 0x06,                    //     REPORT_COUNT (6)
    0x15, 0x00,                    //     LOGICAL_MINIMUM (0)
    0x26, 0xff, 0x00,              //     LOGICAL_MAXIMUM (255)
    0x35, 0x00,                    //     PHYSICAL_MINIMUM (0)
    0x46, 0xff, 0x00,              //     PHYSICAL_MAXIMUM (255)
    0x09, 0x30,                    //     USAGE (X)
    0x09, 0x31,                    //     USAGE (Y)
    0x09, 0x32,                    //     USAGE (Z)
    0x09, 0x33,                    //     USAGE (Rx)
    0x09, 0x34,                    //     USAGE (Ry)
    0x09, 0x35,                    //     USAGE (Rz)
    0x81, 0x02,                    //     INPUT (Data,Var,Abs)
    0x75, 0x08,                    //     REPORT_SIZE (8)
    0x95, 0x01,                    //     REPORT_COUNT (1)
    0x26, 0xFF, 0x00,              //     LOGICAL_MAXIMUM (255)
    0x46, 0x3b, 0x01,              //     PHYSICAL_MAXIMUM (359)
    0x65, 0x14,                    //     UNIT (Eng Rot:Angular Pos)
    0x09, 0x39,                    //     USAGE (Hat switch)
    0x81, 0x42,                    //     INPUT (Data,Var,Abs,Null)
    0x65, 0x00,                    //     UNIT (None)
    0x75, 0x01,                    //     REPORT_SIZE (1)
    0x95, 0x10,                    //     REPORT_COUNT (16)
    0x25, 0x01,                    //     LOGICAL_MAXIMUM (1)
    0x45, 0x01,                    //     PHYSICAL_MAXIMUM (1)
    0x05, 0x09,                    //     USAGE_PAGE (Button)
    0x19, 0x01,                    //     USAGE_MINIMUM (Button 1)
    0x29, 0x10,                    //     USAGE_MAXIMUM (Button 16)
    0x81, 0x02,                    //     INPUT (Data,Var,Abs)
    0xc0,                          //   END_COLLECTION
    0xc0,                          // END_COLLECTION
};

uint32_t HID_Joystick::populateConfigurationDescriptor(uint8_t *buf) {
    uint8_t i = 0;
    buf[i++] =                      0x09;
    buf[i++] =                      0x04;
    buf[i++] =                      _ifInt;
    buf[i++] =                      0;
    buf[i++] =                      1;
    buf[i++] =                      0x03;
    buf[i++] =                      0x00;
    buf[i++] =                      0;
    buf[i++] =                      0;

    /* HID Class-Specific Descriptor */

    buf[i++] =                      0x09;
    buf[i++] =                      0x21;
    buf[i++] =                      0x11;
    buf[i++] =                      0x01;
    buf[i++] =                      0x00;
    buf[i++] =                      1;
    buf[i++] =                      0x22;
    buf[i++] =                      sizeof(joystickHidReport) & 0xFF;
    buf[i++] =                      sizeof(joystickHidReport) >> 8;

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


void HID_Joystick::initDevice(USBManager *manager) {
    _manager = manager;
    _ifInt = _manager->allocateInterface();
    _epInt = _manager->allocateEndpoint();
}

bool HID_Joystick::getDescriptor(uint8_t ep, uint8_t target, uint8_t id, uint8_t maxlen) {
    return false;
}

bool HID_Joystick::getReportDescriptor(uint8_t ep, uint8_t target, uint8_t id, uint8_t maxlen) {
    if (target == _ifInt) {
        _manager->sendBuffer(0, joystickHidReport, min(sizeof(joystickHidReport), maxlen));
        return true;
    }
    return false;
}

void HID_Joystick::configureEndpoints() {
    _manager->addEndpoint(_epInt, EP_OUT, EP_INT, 16, _intA, _intB);
}


bool HID_Joystick::onSetupPacket(uint8_t ep, uint8_t target, uint8_t *data, uint32_t l) {
    if (data[4] != _ifInt) return false;

    uint16_t signature = (data[0] << 8) | data[1];
    switch (signature) {
        case 0xA101: {
                _manager->sendBuffer(0, (uint8_t *)&_rep, sizeof(_rep));
                return true;
            }
            break;
    }
    return false;

}

bool HID_Joystick::onInPacket(uint8_t ep, uint8_t target, uint8_t *data, uint32_t l) {
    if (ep == _epInt) {
//        sendReport((uint8_t *)&_rep, sizeof(_rep));
        return true;
    }
    return false;
}

bool HID_Joystick::onOutPacket(uint8_t ep, uint8_t target, uint8_t *data, uint32_t l) {
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

void HID_Joystick::sendReport(const uint8_t *buf, uint8_t l) {
    uint32_t ts = millis();
    while (!_manager->sendBuffer(_epInt, buf, l)) {
        if (millis() - ts > USB_TX_TIMEOUT) return;
    }
}

HID_Joystick::HID_Joystick() {
    _rep.position.x = 127;
    _rep.position.y = 127;
    _rep.position.z = 127;
    _rep.rotation.x = 127;
    _rep.rotation.y = 127;
    _rep.rotation.z = 127;
    _rep.buttons = 0;
    _rep.hat = 0x0f;
}

void HID_Joystick::setX(uint8_t x) {
    _rep.position.x = x;
    sendReport((uint8_t *)&_rep, sizeof(_rep));
}

void HID_Joystick::setY(uint8_t y) {
    _rep.position.y = y;
    sendReport((uint8_t *)&_rep, sizeof(_rep));
}

void HID_Joystick::setZ(uint8_t z) {
    _rep.position.z = z;
    sendReport((uint8_t *)&_rep, sizeof(_rep));
}

void HID_Joystick::rotateX(uint8_t x) {
    _rep.rotation.x = x;
    sendReport((uint8_t *)&_rep, sizeof(_rep));
}

void HID_Joystick::rotateY(uint8_t y) {
    _rep.rotation.y = y;
    sendReport((uint8_t *)&_rep, sizeof(_rep));
}

void HID_Joystick::rotateZ(uint8_t z) {
    _rep.rotation.z = z;
    sendReport((uint8_t *)&_rep, sizeof(_rep));
}

void HID_Joystick::setPosition(uint8_t x, uint8_t y, uint8_t z) {
    _rep.position.x = x;
    _rep.position.y = y;
    _rep.position.z = z;
    sendReport((uint8_t *)&_rep, sizeof(_rep));
}

void HID_Joystick::setRotation(uint8_t x, uint8_t y, uint8_t z) {
    _rep.rotation.x = x;
    _rep.rotation.y = y;
    _rep.rotation.z = z;
    sendReport((uint8_t *)&_rep, sizeof(_rep));
}

void HID_Joystick::press(uint8_t b) {
    b &= 0x0F;
    _rep.buttons |= (1 << b);
    sendReport((uint8_t *)&_rep, sizeof(_rep));
}

void HID_Joystick::release(uint8_t b) {
    b &= 0x0F;
    _rep.buttons &= ~(1 << b);
    sendReport((uint8_t *)&_rep, sizeof(_rep));
}

void HID_Joystick::setHat(uint8_t d) {
    _rep.hat = d & 0x0F;
    sendReport((uint8_t *)&_rep, sizeof(_rep));
}

void HID_Joystick::onEnumerated() {
    setPosition(127, 127, 127);
}

#endif // _USB
