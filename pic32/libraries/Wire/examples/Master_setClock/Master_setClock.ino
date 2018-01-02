// Wire Master_setClock example

// Demonstrates use of the Wire library
// setClock() & getClock() methods.
//
// uint32_t Wire.setClock(clockFrequencyHZ);
//	returns - actual Master mode clock frequency in Hz
//
// uint32_t Wire.getClock();
//	returns - actual Master mode clock frequency in Hz
// 	Note: if 0, Master mode is non operational
// 
// Displays all supported i2c clock rates by
// attempting to set every clock rate from 0 to 1.5M in 10k increments.
// For each attempted clock rate it prints out the actual clock rate 
// being used.
//

// Created 13 Nov 2017

// This example code is in the public domain

#include <Wire.h>

void setup()
{
	Serial.begin(9600);
	Wire.begin();

// Wire.h will set these defines when setClock() & getClock() exist
#if defined(WIRE_HAS_SETCLOCK) && defined(WIRE_HAS_GETCLOCK)
	for(uint32_t f = 0; f < 3500000; f += 10000)
	{
	uint32_t rf;

		rf = Wire.setClock(f); // set i2c clock bit rate
		Serial.print("setClock(");
		Serial.print(f);
		Serial.print(") returned: ");
		Serial.print(rf);
		Serial.print(" Actual clock: ");
		Serial.print(Wire.getClock());
		Serial.println();
	}
#else
	Serial.println("Core does not support Wire.setClock()/Wire.getClock()");
#endif
}

void loop()
{
}
