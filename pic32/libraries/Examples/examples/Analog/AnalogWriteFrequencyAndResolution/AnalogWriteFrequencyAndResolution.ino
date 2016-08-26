/*  Analog Write frequency and resolution changing
 *  
 *  Changes the PWM frequency to 25KHz and the resolution to 10 bits.
 *  
 *  Duty cycle is then varied from 0 to 100%
 *  
 *  25KHz is preferred for motors as it is above the human audible range
 *  so you don't get the annoying whine.
 */

const int PWM_PIN = 10;

void setup() {
    // 25KHz frequency
    analogWriteFrequency(25000);

    // 10-bit resolution (0 to 1023)
    analogWriteResolution(10);
}

void loop() {
    for (int duty = 0; duty < 1023; duty++) {
        analogWrite(PWM_PIN, duty);
        delay(5);
    }
}
