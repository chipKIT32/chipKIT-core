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

// Default Combinations

#if defined(__USB_ENABLED__)

#if defined(__PIC32MZ__) 
USBHS usbDriver;
#elif defined(__PIC32MX__)
USBFS usbDriver;
#else // nothing defined
#error No USB driver defined for this chip type
#endif // chip type selection

#define VID_FUTURE          0x0403
#define VID_MCHP            0x04d8

#define PID_CDCACM          0xa662
#define PID_CDCACM_KM       0x0f50

#define PID_UNASSIGNED_1    0x0f51
#define PID_UNASSIGNED_2    0x0f52
#define PID_UNASSIGNED_3    0x0f53
#define PID_UNASSIGNED_4    0x0f54
#define PID_UNASSIGNED_5    0x0f55
#define PID_UNASSIGNED_6    0x0f56
#define PID_UNASSIGNED_7    0x0f57
#define PID_UNASSIGNED_8    0x0f58
#define PID_UNASSIGNED_9    0x0f59
#define PID_UNASSIGNED_10   0x0f5a
#define PID_UNASSIGNED_11   0x0f5b
#define PID_UNASSIGNED_12   0x0f5c
#define PID_UNASSIGNED_13   0x0f5d
#define PID_UNASSIGNED_14   0x0f5e

#define PID_BOOTLOADER      0x0f5f

#if defined(__USB_CDCACM__)
    #ifndef _USB_VID_
        #define _USB_VID_ VID_FUTURE
    #endif
    #ifndef _USB_PID_
        #define _USB_PID_ PID_CDCACM
    #endif
    USBManager USB(usbDriver, _USB_VID_, _USB_PID_);
    CDCACM Serial;
    extern "C" void usb_boot_system() {
        USB.addDevice(Serial);
        USB.begin();
    }
#endif // __USB_CDCACM__

#if defined(__USB_CDCACM_KM__)
    #ifndef _USB_VID_
        #define _USB_VID_ VID_MCHP
    #endif
    #ifndef _USB_PID_
        #define _USB_PID_ PID_CDCACM_KM
    #endif
    USBManager USB(usbDriver, _USB_VID_, _USB_PID_);
    CDCACM Serial;
    HID_Keyboard Keyboard;
    HID_Mouse Mouse;
    extern "C" {
        void usb_boot_system() {
            USB.addDevice(Serial);
            USB.addDevice(Keyboard);
            USB.addDevice(Mouse);
            USB.begin();
        }
    }
#endif // __USB_CDCACM_KM__




#endif // __USB_ENABLED__

USBManager::USBManager(USBDriver *driver, uint16_t vid, uint16_t pid, const char *mfg, const char *prod, const char *ser) {
    _enumerated = false;
    _driver = driver;
    _driver->setManager(this);
    _devices = NULL;
    _vid = vid;
    _pid = pid;
    _ifCount = 0;
    _epCount = 1;
    _stringCount = 4;
    _manufacturer = mfg;
    _product = prod;
    _deviceAttributes = 0x80; // Bus powered
    _devicePower = 250; // 500mA
    if (ser) {
        _serial = ser;
        _serialLen = strlen(ser);
    } else {
        _serial = _defSerial;
        _serialLen = _driver->populateDefaultSerial(_defSerial);
    }
}

USBManager::USBManager(USBDriver &driver, uint16_t vid, uint16_t pid, const char *mfg, const char *prod, const char *ser) {
    _enumerated = false;
    _driver = &driver;
    _driver->setManager(this);
    _devices = NULL;
    _vid = vid;
    _pid = pid;
    _ifCount = 0;
    _epCount = 1;
    _stringCount = 4;
    _manufacturer = mfg;
    _product = prod;
    if (ser) {
        _serial = ser;
        _serialLen = strlen(ser);
    } else {
        _serial = _defSerial;
        _serialLen = _driver->populateDefaultSerial(_defSerial);
    }
}

USBManager::USBManager(USBDriver *driver, uint16_t vid, uint16_t pid) {
    _enumerated = false;
    _driver = driver;
    _driver->setManager(this);
    _devices = NULL;
    _vid = vid;
    _pid = pid;
    _ifCount = 0;
    _epCount = 1;
    _stringCount = 4;
    _manufacturer = "chipKIT";
    _product = _BOARD_NAME_;
    _serial = _defSerial;
    _serialLen = _driver->populateDefaultSerial(_defSerial);
}

USBManager::USBManager(USBDriver &driver, uint16_t vid, uint16_t pid) {
    _enumerated = false;
    _driver = &driver;
    _driver->setManager(this);
    _devices = NULL;
    _vid = vid;
    _pid = pid;
    _ifCount = 0;
    _epCount = 1;
    _stringCount = 4;
    _manufacturer = "chipKIT";
    _product = _BOARD_NAME_;
    _serial = _defSerial;
    _serialLen = _driver->populateDefaultSerial(_defSerial);
}

uint8_t USBManager::allocateString() {
    uint8_t i = _stringCount;
    _stringCount++;
    return i;
}

uint8_t USBManager::allocateInterface() {
    uint8_t i = _ifCount;
    _ifCount++;
    return i;
}

uint8_t USBManager::allocateEndpoint() {
    uint8_t i = _epCount;
    _epCount++;
    return i;
}

void USBManager::begin() {
    _wantedAddress = 0;
    for (struct USBDeviceList *scan = _devices; scan; scan = scan->next) {
        scan->device->configureEndpoints();
    }
    _driver->enableUSB();
}

void USBManager::end() {
    _driver->disableUSB();
}

void USBManager::onSetupPacket(uint8_t ep, uint8_t *data, uint32_t l) {
    uint16_t signature = (data[0] << 8) | data[1];
    uint16_t outLength = (data[7] << 8) | data[6];

    _target = (data[5] << 8) | data[4];

    switch (signature) {
        case 0x8006: // Get Descriptor
            switch (data[3]) {
                case 1: { // Device Descriptor
                        struct DeviceDescriptor o;
                        o.bLength = sizeof(struct DeviceDescriptor);
                        o.bDescriptorType = 0x01;
                        o.bcdUSB = 0x0101;
                        o.bDeviceClass = 0xEF; //0x00;
                        o.bDeviceSubClass = 0x02; //0x00;
                        o.bDeviceProtocol = 0x01; //0x00;
                        o.bMaxPacketSize = 0x40;
                        o.idVendor = _vid;
                        o.idProduct = _pid;
                        o.bcdDevice = 0x0200;
                        o.iManufacturer = 0x01;
                        o.iProduct = 0x02;
                        o.iSerialNumber = 0x03;
                        o.bNumConfigurations = 0x01;
                        _driver->sendBuffer(0, (const uint8_t *)&o, min(outLength, sizeof(struct DeviceDescriptor)));
                    }
                    break;

                case 2: { // Configuration Descriptor
                        uint32_t len = sizeof(struct ConfigurationDescriptor);
                        uint8_t faces = 0;

                        for (struct USBDeviceList *scan = _devices; scan; scan = scan->next) {
                            len += scan->device->getDescriptorLength();
                            faces += scan->device->getInterfaceCount();
                        }

                        uint8_t *buf = (uint8_t *)alloca(len);
                        if (!buf) {
                            break;
                        }
                        uint8_t *ptr = buf;
                        struct ConfigurationDescriptor *desc = (struct ConfigurationDescriptor *)buf;

                        desc->bLength = sizeof(struct ConfigurationDescriptor);
                        desc->bDescriptorType = 0x02;
                        desc->wTotalLength = len;
                        desc->bNumInterfaces = faces;
                        desc->bConfigurationValue = 1;
                        desc->iConfiguration = 0;
                        desc->bmAttributes = _deviceAttributes; // 0x80;
                        desc->bMaxPower = _devicePower; // 250;

                        ptr += sizeof(struct ConfigurationDescriptor);

                        for (struct USBDeviceList *scan = _devices; scan; scan = scan->next) {
                            ptr += scan->device->populateConfigurationDescriptor(ptr);
                        }
                        _driver->sendBuffer(0, buf, min(outLength, len));
//                        free(buf);
                    }
                    break;

                case 3: { // String Descriptor
                        switch (data[2]) {
                            case 0x00: { // Header
                                    struct StringDescriptorHeader o;
                                    o.bLength = sizeof(struct StringDescriptorHeader);
                                    o.bDescriptorType = 0x03;
                                    o.wLANGID = 0x0409;
                                    _driver->sendBuffer(0, (const uint8_t *)&o, min(outLength, sizeof(struct StringDescriptorHeader)));
                                }
                                break;

                            case 0x01: { // Manufacturer
                                    uint8_t mlen = strlen(_manufacturer);
                                    uint8_t o[mlen * 2 + 2];
                                    o[0] = mlen * 2 + 2;
                                    o[1] = 0x03;
                                    for (int i = 0; i < mlen; i++) {
                                        o[2 + (i * 2)] = _manufacturer[i];
                                        o[3 + (i * 2)] = 0;
                                    }
                                    _driver->sendBuffer(0, (const uint8_t *)&o, min(outLength, mlen * 2 + 2));
                                }
                                break;

                            case 0x02: { // Product
                                    uint8_t mlen = strlen(_product);
                                    uint8_t o[mlen * 2 + 2];
                                    o[0] = mlen * 2 + 2;
                                    o[1] = 0x03;
                                    for (int i = 0; i < mlen; i++) {
                                        o[2 + (i * 2)] = _product[i];
                                        o[3 + (i * 2)] = 0;
                                    }
                                    _driver->sendBuffer(0, (const uint8_t *)&o, min(outLength, mlen * 2 + 2));
                                }
                                break;

                            case 0x03: { // Serial
                                    uint8_t mlen = _serialLen;
                                    uint8_t o[mlen * 2 + 2];
                                    o[0] = mlen * 2 + 2;
                                    o[1] = 0x03;
                                    for (int i = 0; i < mlen; i++) {
                                        o[2 + (i * 2)] = _serial[i];
                                        o[3 + (i * 2)] = 0;
                                    }
                                    _driver->sendBuffer(0, (const uint8_t *)&o, min(outLength, mlen * 2 + 2));
                                }
                                break;

                            default:
                                for (struct USBDeviceList *scan = _devices; scan; scan = scan->next) {
                                    if (scan->device->getStringDescriptor(data[2], outLength)) {
                                        return;
                                    }
                                }
                                
                                _driver->sendBuffer(0, NULL, 0);
                                break;
                        }

                        break;
                    }
                    break;

                default:
                    for (struct USBDeviceList *scan = _devices; scan; scan = scan->next) {
                        if (scan->device->getDescriptor(ep, 0, data[3], outLength)) {
                            return;
                        }
                    }
                    _driver->sendBuffer(0, NULL, 0);
                    break;
            }

            break;

        case 0x8106: // Get report descriptor
            for (struct USBDeviceList *scan = _devices; scan; scan = scan->next) {
                if (scan->device->getReportDescriptor(ep, _target, data[2], outLength)) {
                    return;
                }
            }
            _driver->sendBuffer(0, NULL, 0);
            break;

        case 0x0005: // Set Address
            _driver->sendBuffer(0, NULL, 0);
            _wantedAddress = data[2];
            break;

        case 0x0009: // Set Configuration
            _enumerated = true;
            for (struct USBDeviceList *scan = _devices; scan; scan = scan->next) {
                scan->device->onEnumerated();
            }
            _driver->sendBuffer(0, NULL, 0);
            break;

        default:
            for (struct USBDeviceList *scan = _devices; scan; scan = scan->next) {
                if (scan->device->onSetupPacket(ep, _target, data, l)) {
                    return;
                }
            }
            _driver->sendBuffer(0, NULL, 0);
            break;
    }
}

void USBManager::onInPacket(uint8_t ep, uint8_t *data, uint32_t l) {
    if (_wantedAddress != 0) {
        _driver->setAddress(_wantedAddress);
        _wantedAddress = 0;
    }
    for (struct USBDeviceList *scan = _devices; scan; scan = scan->next) {
        if (scan->device->onInPacket(ep, _target, data, l)) {
            return;
        }
    }
}

void USBManager::onOutPacket(uint8_t ep, uint8_t *data, uint32_t l) {
    for (struct USBDeviceList *scan = _devices; scan; scan = scan->next) {
        if (scan->device->onOutPacket(ep, _target, data, l)) {
            return;
        }
    }
}

void USBManager::addDevice(USBDevice *d) {
    struct USBDeviceList *newDevice = (struct USBDeviceList *)malloc(sizeof(struct USBDeviceList));
    if (!newDevice) {
        return;
    }
    struct USBDeviceList *scan;
    d->initDevice(this);
    newDevice->device = d;
    newDevice->next = NULL;
    if (_devices == NULL) {
        _devices = newDevice;
        return;
    }
    
    scan = _devices;
    while (scan->next != NULL) {
        scan = scan->next;
    }
    scan->next = newDevice;
}

bool USBManager::isEnumerated() { 
    return _enumerated;
}

#endif // _USB
