#include <Clicker2.h>

Clicker2_ Clicker2;



double Clicker2_::getBatteryVoltage() {
    pinMode(PIN_SENSEL, OUTPUT);
    digitalWrite(PIN_SENSEL, LOW);
    delay(50);
    double vs = analogRead(PIN_VSENSE);
    double volts = (vs / 1023.0) * 3.24;
    digitalWrite(PIN_SENSEL, HIGH);
    pinMode(PIN_SENSEL, INPUT);
    return volts * 3.0;
}

bool Clicker2_::isCharging() {
    pinMode(PIN_STAT, INPUT);
    return (digitalRead(PIN_STAT) == LOW);
}

bool Clicker2_::isUSBConnected() {
    return U1OTGSTATbits.SESVD;
}
