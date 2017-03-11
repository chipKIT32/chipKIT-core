---
layout: default
title: Non-Blocking Analog Read Functions
---

Introduction
------------


In an effort to increase the number of times per second the loop function is called when using analogRead functions non-blocking equivalent functions have been implemented into the chipKIT-core.


The existing analogRead function does three things:
    <ol>
        <li>Select ADC channel and start conversion.</li>
        <li>Do nothing while waiting for conversion to complete.</li>
        <li>Read converted value and return it to user.</li>
    </ol>
		
The "do nothing" part is what we aim to eliminate this non-blocking implementation and is indeed what we have done.  Three newly exposed functions [analogReadConversionStart(pin), analogReadConversionComplete(), analogReadConversion()] implement and the analogRead() in wiring_analog.c simply becomes this:

```cpp
int analogRead(uint8_t pin)
{
    analogReadConversionStart(pin);
    while( ! analogReadConversionComplete() );
    return analogReadConversion();
}
```
	
##Results 

The result of using the non-blocking analogRead functions result in a simple loop speed up of nearly 2x. On a MZ EFG chip this speed up is about 4.9x as fast as the blocking functions and allows for a loop frequency greater than 1MHz!

    <!-- This would be better shown in a table -->
	
| chipKIT Board (Rev)| PIC32 | Clock Freq  | loop() Frequency Blocking Analog Read  | loop() Frequency Non-Blocking Analog Read  | Improvement  | Notes                      |
| ------------------ |:-----:| -----------:| -------------------------------------- | ------------------------------------------ | ------------ | -------------------------- |
| Lenny              | MX    | 40 Mhz      | 49.14 kHz (20.35uS)					| 127.39 kHz (7.84uS)		            	 | 2.59	  	    |							 |
| Fubarino SD (1.5)  | MX    | 80 Mhz      | 90.91 kHz (10.99uS)					| 217.39 kHz	(4.60uS)	          		 | 2.39	  	    |							 |
| Wi-Fire (C)        | MZEFG | 200 Mhz     | 233.10 kHz (4.29uS)					| 1162.79 kHz (0.86us)		                 | 4.98	  	    |							 |
| Wi-Fire (B)        | MZECG | 200 Mhz     | 405.63 Hz (2465.3uS)   				| N/A               		                 | N/A	  	    | Non-Blocking Not Supported |
	

## Example

The following code example shows how to use the <a href="https://en.wikipedia.org/wiki/Non-blocking_algorithm">non-blocking</a> analogRead functions.  In the current implementation it is important that you do not mix blocking and non-blocking analogRead functions due to an internal state maching that keeps track of which ADC channel is currently selected.

```cpp
// This is in wiring.c, we shouldn't have to redefine it here (issue #288)
#define CORETIMER_TICKS_PER_MICROSECOND    (F_CPU / 2 / 1000000UL)

//#define ADC_TEST_PIN A12
#define ADC_TEST_PIN 16

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);           // start serial for output
    delay(3000);
    Serial.println("chipKIT-core ADC speed test");
#define FAST_ADC
#ifdef FAST_ADC
    analogReadConversionStart(ADC_TEST_PIN);
#endif
}

void loop() {
    // put your main code here, to run repeatedly:
    static uint32_t start_us = readCoreTimer();
    static uint32_t stop_us = readCoreTimer();

    uint32_t value;

#ifdef FAST_ADC
    if ( analogReadConversionComplete() ) {
    value = analogReadConversion();
    analogReadConversionStart(ADC_TEST_PIN);
    }
#else
    value = analogRead(ADC_TEST_PIN);
#endif

    stop_us = readCoreTimer(); //micros();

    // Display Loop Time
    Serial.print("ADC_TEST_PIN: ");
    Serial.print(value, DEC);
    Serial.println("");
    Serial.print("F_CPU: ");
    Serial.print(F_CPU, DEC);
    Serial.print(" ");
    float us = (float)(stop_us - start_us) / (float)CORETIMER_TICKS_PER_MICROSECOND;
    Serial.print(us, 3);
    Serial.print(" us, ");
    Serial.print(1.0 / us * 1000000.0, 3);
    Serial.print(" Hz");
    Serial.println("");
    delay(1000);

    start_us = readCoreTimer(); //micros();

}
```