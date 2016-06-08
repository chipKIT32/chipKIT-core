#include <DSPI.h>
#include <DFATFS.h>
#include <SPIRAMVOL.h>

DSPI0 spi;

// A bug in FatFS means we can't use the full 2MB of the Rambo. Instead
// we will have to leave off the last chip and manually set its chip select
// pin to permanantly high.
//
// Each chip on my Rambo is 128KB in size (131072 bytes) and there are 16 installed.
SPIRAMVOL ram(spi, 131072, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40); //, 41);

void setup() {
    pinMode(41, OUTPUT); digitalWrite(41, HIGH); // Disable the last chip
    Serial.begin(115200);
    spi.setSpeed(10000000);
    
    FRESULT r;
    if ((r = DFATFS::fsmkfs(ram)) != FR_OK) {
        Serial.println("Error formatting RAM disk");
        Serial.println(r);
    }
    if (DFATFS::fsmount(ram, DFATFS::szFatFsVols[0], 0) != FR_OK) {
        Serial.println("Error mounting RAM disk");
    }

    DFILE testFile;
    

    if((r = testFile.fsopen("test.txt", FA_CREATE_ALWAYS | FA_WRITE | FA_READ)) != FR_OK) {
        Serial.println("Unable to open test file for writing");
    }

    testFile.println("This is a test");
    testFile.fsclose();    

    Serial.println("All setup done.");
}

void loop() {
    DFILE testFile;
    FRESULT r;
    if((r = testFile.fsopen("test.txt", FA_READ)) != FR_OK) {
        Serial.println("Unable to open test file for reading");
    }

    while (testFile.available()) {
        Serial.write(testFile.read());
    }
    testFile.fsclose();
    delay(100);
}
