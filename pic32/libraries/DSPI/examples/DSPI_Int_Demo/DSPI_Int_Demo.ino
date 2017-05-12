/*
 * This is a very simple test of the DSPI library with interrupts, using the three available SPI ports
 * on a Fubarino SD chipKIT board. To run this test, simply connect the MOSI and MISO
 * pins of each of the three SPI ports to each other. This example code is based around the ability
 * of the DSPI library to use interrupts to peform the SPI transfers in the backgrounds. Because of
 * this, and because we want to show overlapping SPI transactions, we have to use six separate buffers,
 * three transmit and three receive. These buffers must be statically allocated (or through malloc())
 * so that the interrupts can have access to them during the entire transaction.
 * It then prints out all of the received bytes to the USB serial port. If everything is
 * working you should get the following printed to the serial monitor:
 * 11:22:33  44:55:66  77:88:99
 * See https://github.com/chipKIT32/chipKIT-core/issues/349 for more information includeing
 * a logic analyzer trace of what this looks like as it runs.
 * 
 * The whole point of using interrupt based SPI transfers is so that you can do other things
 * with your code while the SPI transaction happens in the background.
 */

#include <DSPI.h>

/* Note these pin numbers are for Fubarino SD */
DSPI0    spi0;   /* SCK = 24, MISO = 25, MOSI = 26, CS = 27 */
DSPI1    spi1;   /* SCK = 7, MISO = 8, MOSI = 9, CS = 1 */
DSPI2    spi2;   /* SCK = 43, MISO = 28, MOSI = 29, CS = 37 */

uint8_t sendBuffer1[3] = {0x11, 0x22, 0x33};
uint8_t sendBuffer2[3] = {0x44, 0x55, 0x66};
uint8_t sendBuffer3[3] = {0x77, 0x88, 0x99};
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
  spi0.enableInterruptTransfer();

  // Single argument to begin() is the pin you want to use as slave select (if different from default)
  spi1.begin(1);
  spi1.setSpeed(10000000);
  // What if we don't want MODE0? We can set any of the four modes using setMode()
  spi1.setMode(DSPI_MODE1);
  spi1.enableInterruptTransfer();
  
  spi2.begin();
  spi2.setSpeed(20000000);
  // We can also set the pin select pin using the setPinSelect() call
  spi2.setPinSelect(37);
  spi2.enableInterruptTransfer();

  Serial.begin(9600);
  while(!Serial);     // Wait for PC to connect
}

void loop() {
  spi0.setSelect(LOW);
  spi0.intTransfer(3, sendBuffer1, receiveBuffer1);
  // The intTransaction call will start our tx/rx over SPI in the background. The call
  // returns immediately.
  // Note that we can set the spi0 select pin high here, because the transaction isn't complete yet.

  // Next we send spi1 and spi2's data out. All three transactions will end up happening at the same time.
  spi1.setSelect(LOW);
  spi1.intTransfer(3, sendBuffer2, receiveBuffer2);
  
  spi2.setSelect(LOW);
  spi2.intTransfer(3, sendBuffer3, receiveBuffer3);

  // Now, before we can deassert the slave select lines and trust that our receive buffers
  // are full, we have to wait until all DSPI objects have no more bytes waiting to go out.
  while(spi0.transCount() != 0 || spi1.transCount() != 0 || spi2.transCount() != 0)
  {
    ;
  }
  spi0.setSelect(HIGH);
  spi1.setSelect(HIGH);
  spi2.setSelect(HIGH);

  // Now we can print out all of the values we received
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


