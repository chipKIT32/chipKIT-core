// --------------------------------------
// DTWIscanner v2.0
// Author: Dr. Mathias Wilhelm
// Copyright 2016 - CC BY-NC-SA
// Creative Commons Attribution 4.0 International license. 
//
// 17.03.2016 v1.0 initial release
// 18.03.2016 v1.1 extending to scan multiple I2C buses is present
//
#include <DTWI.h>

DTWI0 dtwi0;
#ifdef _DTWI1_BASE
DTWI1 dtwi1;
#endif
#ifdef _DTWI2_BASE
DTWI2 dtwi2;
#endif
#ifdef _DTWI3_BASE
DTWI3 dtwi3;
#endif
#ifdef _DTWI4_BASE
DTWI4 dtwi4;
#endif
uint8_t numbus = 1; // assuming that this script is started on a system with at least one I2C bus

void setup()
{
#ifdef _DTWI1_BASE
	numbus++;
#endif
#ifdef _DTWI2_BASE
	numbus++;
#endif
#ifdef _DTWI3_BASE
	numbus++;
#endif
#ifdef _DTWI4_BASE
	numbus++;
#endif
	Serial.begin(9600);
  delay(5000); // allow the user to start serial monitor
	Serial.println("I2C Scanner v1.0");
	Serial.println("based on DTWI library");
	Serial.print("number of I2C buses found on this board: ");
	Serial.println(numbus);
	SerialDelay(5);
}

void loop()
{
	byte error, address;
	int nDevices;

	// ========================================================== I2C BUS 0
	Serial.println("starting master mode on I2C bus -= 0 =-");
	dtwi0.beginMaster();
	nDevices = 0;
	for(address = 8; address < 127; address++ ) 
	{
		// The DTWIscanner uses the return value of
		// the DTWI0.stopMaster() to see if
		// a device did acknowledge to the address.
		dtwi0.startMasterWrite(address);
		delay(10);
		if(!dtwi0.stopMaster())
		{
			Serial.print("I2C device found at address 0x");
			if (address<16) Serial.print("0");
			Serial.print(address,HEX);
			Serial.println("  !");
			nDevices++;
		}
	}
	if (nDevices == 0) Serial.println("No I2C devices found\n");
	dtwi0.endMaster();

	// ========================================================== I2C BUS 1
#ifdef _DTWI1_BASE
	Serial.println("starting master mode on I2C bus -= 1 =-");
	dtwi1.beginMaster();
	nDevices = 0;
	for(address = 8; address < 127; address++ ) 
	{
		dtwi1.startMasterWrite(address);
		delay(10);
		if(!dtwi1.stopMaster())
		{
			Serial.print("I2C device found at address 0x");
			if (address<16) Serial.print("0");
			Serial.print(address,HEX);
			Serial.println("  !");
			nDevices++;
		}
	}
	if (nDevices == 0) Serial.println("No I2C devices found\n");
	dtwi1.endMaster();
#endif

	// ========================================================== I2C BUS 2
#ifdef _DTWI2_BASE
	Serial.println("starting master mode on I2C bus -= 2 =-");
	dtwi2.beginMaster();
	nDevices = 0;
	for(address = 8; address < 127; address++ ) 
	{
		dtwi2.startMasterWrite(address);
		delay(10);
		if(!dtwi2.stopMaster())
		{
			Serial.print("I2C device found at address 0x");
			if (address<16) Serial.print("0");
			Serial.print(address,HEX);
			Serial.println("  !");
			nDevices++;
		}
	}
	if (nDevices == 0) Serial.println("No I2C devices found\n");
	dtwi2.endMaster();
#endif

	// ========================================================== I2C BUS 3
#ifdef _DTWI3_BASE
	Serial.println("starting master mode on I2C bus -= 3 =-");
	dtwi3.beginMaster();
	nDevices = 0;
	for(address = 8; address < 127; address++ ) 
	{
		dtwi3.startMasterWrite(address);
		delay(10);
		if(!dtwi3.stopMaster())
		{
			Serial.print("I2C device found at address 0x");
			if (address<16) Serial.print("0");
			Serial.print(address,HEX);
			Serial.println("  !");
			nDevices++;
		}
	}
	if (nDevices == 0) Serial.println("No I2C devices found\n");
	dtwi3.endMaster();
#endif

	// ========================================================== I2C BUS 4
#ifdef _DTWI4_BASE
	Serial.println("starting master mode on I2C bus -= 4 =-");
	dtwi4.beginMaster();
	nDevices = 0;
	for(address = 8; address < 127; address++ ) 
	{
		dtwi4.startMasterWrite(address);
		delay(10);
		if(!dtwi4.stopMaster())
		{
			Serial.print("I2C device found at address 0x");
			if (address<16) Serial.print("0");
			Serial.print(address,HEX);
			Serial.println("  !");
			nDevices++;
		}
	}
	if (nDevices == 0) Serial.println("No I2C devices found\n");
	dtwi4.endMaster();
#endif
	SerialDelay(5);           // wait 5 seconds for next scan
}

void SerialDelay(int s){
	Serial.print("Wait for ");
	Serial.print(s);
	Serial.print(" seconds  ");
	for (int i=s; i>0; i--){
		Serial.print("\b");
		Serial.print(i);
		delay(1000);
	}
	Serial.println("\bdone");
}
