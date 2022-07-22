/* AllcaFluxometro.cpp
* Arquivo fonte da classe AllcaFluxometro
* Autor: Djan Rosario
* Data: 22/07/2022
* Versão: 1.0
* 
*/
#include <Arduino.h>
#include "AllcaFluxometro.h"

AllcaFluxometro::AllcaFluxometro(int address, int pin, float rateFactor)
{
    _address    = address;
    _pin        = pin;
    _rateFactor = rateFactor;
}
void AllcaFluxometro::begin(void (*userfunc)())
{
    pinMode(_pin, INPUT);
    attachInterrupt(digitalPinToInterrupt(_pin), userfunc, RISING);
}

float AllcaFluxometro::getValue(int countPulses)
{
    _value = countPulses / _rateFactor;
    return _value;
}

float AllcaFluxometro::calcRateFactor(float value, int countPulses)
{
    _rateFactor = countPulses / value;
    return _rateFactor;
}
