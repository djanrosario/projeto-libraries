#include <Arduino.h>
#include "PressureSensor.h"

PressureSensor::PressureSensor(int address, int pin, float zero, float fullscale)
{
    _address   = address;
    _pin       = pin;
    _zero      = zero;
    _fullscale = fullscale;
}

void PressureSensor::begin()
{
    pinMode(_pin, INPUT);
}

float PressureSensor::getValue()
{
    float raw = this->getRawValue();
    raw-=_zero;
    _value = raw * (_fullscale / 1023.0);
    return _value;
}

void PressureSensor::setZero(float value)
{
    _zero = value;
}

float PressureSensor::getAutoZero()
{
    int count;
    float raw, tempzero;
    for (count = 0; count < 50; count++) {
        raw = this->getRawValue();
        tempzero += raw / 50;
        delay(250);
    }
    raw = this->getRawValue();
    if (abs(tempzero - raw) > 1) {
        _zero = -1;
        
    } else {
        _zero = tempzero;
    }
    return _zero;
}

float PressureSensor::getZero()
{
    return _zero;
}

float PressureSensor::getFullScaleByMeasure(float value)
{
    float raw = this->getRawValue();
    raw-=_zero;
    this->setFullScale((value * 1024) / raw);
    return this->getFullScale();
}
void PressureSensor::setFullScale(float value)
{
    _fullscale = value;
}
float PressureSensor::getFullScale()
{
    return _fullscale;
}

float PressureSensor::getRawValue()
{
    float raw = analogRead(_pin);
    return raw;
}