/*
  SoftwareSerial Simplex Test Code (For chipKIT)

 The purpose of this sketch is to show functional equivalence between 
 the old full duplex SoftwareSerial class and the two new Simplex
 SoftwareSerialRx and SoftwareSerialTx classes.

 Tested with the Fubarino Mini only
 Receives USB Serial, transmits HardwareSerial (from PC)
 Receives SoftwareSerial, transmits SoftwareSerial (loopback)
 Receives HardwareSerial, transmits USB Serial (back to PC)
 
 Fubarino Mini
 * Software TX (11) connect to Serial1 RX (25)
 * Software RX (10) connect to Serial1 TX (26)
 * 

 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example
 Modified on Aug 31,2015 by Brian Schmalz for chipKIT
 Modified on Jul 06,2016 by Jacob Christ for chipKIT (adding Simplex funtionality)
 This example code is in the public domain.

 */
#include <SoftwareSerial.h>

#define Simplex
#ifdef Simplex
SoftwareSerialRx mySerialRx(10); // RX
SoftwareSerialTx mySerialTx(11); // TX
#else
SoftwareSerial mySerial(10, 11); // RX, TX
#endif

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial) {
    ;
  }
  
  Serial1.begin(115200);

  // set the data rate for the SoftwareSerial port
#ifdef Simplex
  mySerialRx.begin(115200);
  mySerialTx.begin(115200);
#else
  mySerial.begin(115200);
#endif
}

void loop() // run over and over
{
  // Get from USB write out to hardware
  if (Serial.available())
    Serial1.write(Serial.read());
  // Get software and write out to software
#ifdef Simplex
  if (mySerialRx.available())
    mySerialTx.write(mySerialRx.read());
#else
  if (mySerial.available())
    mySerial.write(mySerial.read());
#endif
  // Get hardware and write out to USB
  if (Serial1.available())
    Serial.write(Serial1.read());
}

