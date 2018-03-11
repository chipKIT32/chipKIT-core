#include <DFATFS.h>
#include <RAMVOL.h>
#include <USB_MSD.h>


const uint32_t diskSectors = RAMVOL::CMINSECTORS;
const uint32_t sectorSize = RAMVOL::CBSECTOR;

uint8_t ramVolBuff[diskSectors * sectorSize];
RAMVOL ramVol(ramVolBuff, diskSectors);
DFILE dataFile;

USBFS usbDevice;
USBManager USB(usbDevice, 0x04d8, 0x0f5d);
USB_MSD ramdisk(ramVol);

void setup() {
   
    ramVol.disk_initialize();
    DFATFS::fsmkfs(ramVol);
    USB.addDevice(ramdisk);
    USB.begin();
    DFATFS::fsmount(ramVol, DFATFS::szFatFsVols[0], 0);
}

void loop() {
    delay(100);
    dataFile.fsopen("data.txt", FA_CREATE_ALWAYS | FA_WRITE | FA_READ);
    for (int i = 0; i < 12; i++) {
        dataFile.printf("%2d: %4d\r\n", i, analogRead(i));
    } 
    dataFile.fssync();
    dataFile.fsclose();
}
