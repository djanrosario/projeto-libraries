#include <Arduino.h>
#include "PressureSensor.h"

PressureSensor::PressureSensor(int address, int pin, float zero, float fullscale)
{
    _address   = address;
    _pin       = pin;
    _zero      = zero;
    _fullscale = fullscale;
}

PressureSensor::PressureSensor()
{
    _address   = 0x01;
    _pin       = A0;
    _zero      = 0;
    _fullscale = 100.0;
}

float PressureSensor::getValue()
{
    float raw = analogRead(_pin);
    raw-=_zero;
    return raw * (_fullscale / 1023.0);
}