/*  SPI Transaction Test Code
 *  This sketch shows how different clock rates, differet chip selects, and
 *  different SPI modes can be used on chipKIT boards. It was tested with a
 *  FubarinoSD board, and the output checked with a Saleae Logic Pro 16. 
 *  
 *  The SPI bus is not connected to anything, so no data ever gets recevied,
 *  only transmitted. But that is enough to show that the different clock rates,
 *  different chip selects, and different SPI modes all work properly.
 *  
 *  The first part of the test shows four different clock rates. For 80MHz chipKIT
 *  boards (including FubarinoSD), the slowest clock rate possible of 78125 Hz is 
 *  tested, as is the highest clock rate of 40 Mhz, and two clock rates in between.
 *  
 *  Each of these different clock rates is tested with a different chip select
 *  signal, as if there were four separate SPI slaves connected on the same SPI
 *  bus, and each one needed to be communicated with at a different speed.
 *  
 *  The second part of the test re-uses chip select line C, but tests sending
 *  the same data using all four SPI modes. (These are combinations of clock
 *  polarity and sampling times.) 
 *  
 *  Note that the PIC32 can only send SPI data MSB First. That paramter to the
 *  Settings object initalizer is ignored by the SPI library.
 */
#include <SPI.h>

const int slaveAPin = 20;
const int slaveBPin = 21;
const int slaveCPin = 22;
const int slaveDPin = 23;

// set up the speed, data order and data mode
SPISettings settingsA(   78125, MSBFIRST, SPI_MODE0); // Slowest SPI clk rate supported for 80MHz parts
SPISettings settingsB(  156250, MSBFIRST, SPI_MODE0); 
SPISettings settingsC(20000000, MSBFIRST, SPI_MODE0); 
SPISettings settingsD(40000000, MSBFIRST, SPI_MODE0); // Fastest SPI clk rate supported for 80MHz parts
SPISettings settingsE( 1000000, MSBFIRST, SPI_MODE0); 
SPISettings settingsF( 1000000, MSBFIRST, SPI_MODE1); 
SPISettings settingsG( 1000000, MSBFIRST, SPI_MODE2); 
SPISettings settingsH( 1000000, MSBFIRST, SPI_MODE3); 

void setup() {
  // set the Slave Select Pins as outputs and set them high
  pinMode (slaveAPin, OUTPUT);
  digitalWrite (slaveAPin, HIGH);
  pinMode (slaveBPin, OUTPUT);
  digitalWrite (slaveBPin, HIGH);
  pinMode (slaveCPin, OUTPUT);
  digitalWrite (slaveCPin, HIGH);
  pinMode (slaveDPin, OUTPUT);
  digitalWrite (slaveDPin, HIGH);
  // initialize SPI:
  SPI.begin(); 
}

/* Use varying data for interest */
uint8_t data1 = 0;

void loop() {  
  uint8_t i;

  /*  Send three data bytes in a transaction, 10 transactions
   *  on SettingA and chip select A.
   */
  for (i = 0; i < 10; i++)
  {
    SPI.beginTransaction(settingsA);
    digitalWrite (slaveAPin, LOW);
    SPI.transfer(0x55);
    SPI.transfer(0xAA);
    SPI.transfer(0xF0);
    digitalWrite (slaveAPin, HIGH);
    SPI.endTransaction();
  }
  
  /*  Send one data bytes in a transaction, 10 transactions
   *  on SettingB and chip select B.
   */
  for (i = 0; i < 10; i++)
  {
    SPI.beginTransaction(settingsB);
    digitalWrite (slaveBPin, LOW);
    SPI.transfer(data1);
    digitalWrite (slaveBPin, HIGH);
    SPI.endTransaction();
    data1++;
  }
  
  /*  Send three data bytes in a transaction, 10 transactions
   *  on SettingC and chip select C.
   */
  for (i = 0; i < 10; i++)
  {
    SPI.beginTransaction(settingsC);
    digitalWrite (slaveCPin, LOW);
    SPI.transfer(0x55);
    SPI.transfer(0xAA);
    SPI.transfer(0xF0);
    digitalWrite (slaveCPin, HIGH);
    SPI.endTransaction();
    data1++;
  }
  
  /*  Send one data byte in a transaction, 10 transactions
   *  on SettingD and chip select D.
   */
  for (i = 0; i < 10; i++)
  {
    SPI.beginTransaction(settingsD);
    digitalWrite (slaveDPin, LOW);
    SPI.transfer(data1);
    digitalWrite (slaveDPin, HIGH);
    SPI.endTransaction();
    data1++;
  }

  /*  Send three data bytes in a transaction,
   *  on SettingE and chip select D.
   */
  SPI.beginTransaction(settingsE);
  digitalWrite (slaveDPin, LOW);
  SPI.transfer(0x55);
  SPI.transfer(0xAA);
  SPI.transfer(0xF0);
  digitalWrite (slaveDPin, HIGH);
  SPI.endTransaction();
  data1++;

  /*  Send three data bytes in a transaction,
   *  on SettingE and chip select D.
   */
  SPI.beginTransaction(settingsF);
  digitalWrite (slaveDPin, LOW);
  SPI.transfer(0x55);
  SPI.transfer(0xAA);
  SPI.transfer(0xF0);
  digitalWrite (slaveDPin, HIGH);
  SPI.endTransaction();
  data1++;

  /*  Send three data bytes in a transaction,
   *  on SettingF and chip select D.
   */
  SPI.beginTransaction(settingsG);
  digitalWrite (slaveDPin, LOW);
  SPI.transfer(0x55);
  SPI.transfer(0xAA);
  SPI.transfer(0xF0);
  digitalWrite (slaveDPin, HIGH);
  SPI.endTransaction();
  data1++;

  /*  Send three data bytes in a transaction,
   *  on SettingG and chip select D.
   */
  SPI.beginTransaction(settingsH);
  digitalWrite (slaveDPin, LOW);
  SPI.transfer(0x55);
  SPI.transfer(0xAA);
  SPI.transfer(0xF0);
  digitalWrite (slaveDPin, HIGH);
  SPI.endTransaction();
  data1++;
  
  delay(20);
}
