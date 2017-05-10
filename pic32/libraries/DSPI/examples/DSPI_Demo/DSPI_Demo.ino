/*
 * This is a very simple test of the DSPI library, using the three available SPI ports
 * on a Fubarino SD chipKIT board. To run this test, simply connect the MOSI and MISO
 * pins of each of the three SPI ports to each other. This test sends one set of 3
 * bytes out SPI0, back in SPI0, then out SPI1, back in SPI1, and out SPI2, back in SPI2.
 * It then prints out all of the received bytes to the USB serial port. If everything is
 * working you should get the following printed to the serial monitor:
 * 55:AA:A5  55:AA:A5  55:AA:A5
 * See https://github.com/chipKIT32/chipKIT-core/issues/349 for more information includeing
 * a logic analyzer trace of what this looks like as it runs.
 */

#include <DSPI.h>

/* Note these pin numbers are for Fubarino SD */
DSPI0    spi0;   /* SCK = 24, MISO = 25, MOSI = 26, CS = 27 */
DSPI1    spi1;   /* SCK = 7, MISO = 8, MOSI = 9, CS = 1 */
DSPI2    spi2;   /* SCK = 43, MISO = 28, MOSI = 29, CS = 37 */

uint8_t sendBuffer[3] = {0x55, 0xAA, 0xA5};
uint8_t receiveBuffer1[3];
uint8_t receiveBuffer2[3];
uint8_t receiveBuffer3[3];

void setup() {
  // Make all CS lines outputs
  pinMode(27, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(37, OUTPUT);
  // Use different speeds so we can tell which port is which on the logic analzyer
  // Simple begin, no arguments. Defaults to 1Mhz clock and DSPI_MODE0, and default SS pin for this port
  spi0.begin();
  spi0.setSpeed(5000000);

  // Single argument to begin() is the pin you want to use as slave select (if different from default)
  spi1.begin(1);
  spi1.setSpeed(10000000);
  // What if we don't want MODE0? We can set any of the four modes using setMode()
  spi1.setMode(DSPI_MODE1);
  
  spi2.begin();
  spi2.setSpeed(20000000);
  // We can also set the pin select pin using the setPinSelect() call
  spi2.setPinSelect(37);

  Serial.begin(9600);
  while(!Serial);     // Wait for PC to connect
}

void loop() {
  spi0.setSelect(LOW);
  // Let's do this one byte at a time for spi0
  receiveBuffer1[0] = spi0.transfer(sendBuffer[0]);
  receiveBuffer1[1] = spi0.transfer(sendBuffer[1]);
  receiveBuffer1[2] = spi0.transfer(sendBuffer[2]);
  spi0.setSelect(HIGH);
  
  spi1.setSelect(LOW);
  spi1.transfer(3, receiveBuffer1, receiveBuffer2);
  spi1.setSelect(HIGH);
  
  spi2.setSelect(LOW);
  spi2.transfer(3, receiveBuffer2, receiveBuffer3);
  spi2.setSelect(HIGH);

  Serial.print(receiveBuffer1[0], HEX);
  Serial.print(":");
  Serial.print(receiveBuffer1[1], HEX);
  Serial.print(":");
  Serial.print(receiveBuffer1[2], HEX);
  Serial.print("   ");

  Serial.print(receiveBuffer2[0], HEX);
  Serial.print(":");
  Serial.print(receiveBuffer2[1], HEX);
  Serial.print(":");
  Serial.print(receiveBuffer2[2], HEX);
  Serial.print("   ");

  Serial.print(receiveBuffer3[0], HEX);
  Serial.print(":");
  Serial.print(receiveBuffer3[1], HEX);
  Serial.print(":");
  Serial.print(receiveBuffer3[2], HEX);
  Serial.println("");
}


