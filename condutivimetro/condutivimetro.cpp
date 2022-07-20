#include "condutivimetro.h"

AllcaCondutivimetro::AllcaCondutivimetro(int address, int powerpin, int readpin,
                                         int ntcpin, float vin, float calibconst)
{
    _address    = address;
    _powerpin   = powerpin;
    _readpin    = readpin;
    _ntcpin     = ntcpin;
    _vin        = vin;
    _calibconst = calibconst;
}

void AllcaCondutivimetro::begin()
{
    pinMode(_powerpin, OUTPUT);
    pinMode(_readpin, INPUT);
    pinMode(_ntcpin, INPUT);
}

float AllcaCondutivimetro::getRawValue()
{
    digitalWrite(_powerpin, HIGH);
    float raw = analogRead(_readpin);
    raw = analogRead(_readpin);
    digitalWrite(_powerpin, LOW);
    return raw;
}

void AllcaCondutivimetro::setResist(float value)
{
    _resistvalue = value;
}

float AllcaCondutivimetro::getResist()
{
    return _resistvalue;
}

float AllcaCondutivimetro::getWaterResist()
{
    float Vdrop = (_vin * this->getRawValue()) / RESOL;
    this->setResist((Vdrop * RREF) / (_vin - Vdrop));
    return this->getResist();
}

void AllcaCondutivimetro::setUncompValue(float value)
{
    _uncompvalue = value;
}

float AllcaCondutivimetro::getUncompValue()
{
    return _uncompvalue;
}

float AllcaCondutivimetro::getUncompCondutiv()
{
    this->setUncompValue(US_CM_SCALE / (this->getWaterResist() * _calibconst));
    return this->getUncompValue();
}

void AllcaCondutivimetro::setTemp(float value)
{
    _tempF = value;
}

float AllcaCondutivimetro::getTemp()
{
    return _tempF;
}

float AllcaCondutivimetro::getWaterTemp()
{
    double rx = RREF * exp(-BETA / T0);
    int sampleNTC = analogRead(_ntcpin);
    float Vntc = (_vin * sampleNTC) / RESOL;
    float Rntc = (_vin * RREF) / Vntc - RREF;
    this->setTemp(BETA / log(Rntc / rx));
    return this->getTemp();
}

void AllcaCondutivimetro::setValue(float value)
{
    _value = value;
}

float AllcaCondutivimetro::getValue()
{
    return _value;
}

float AllcaCondutivimetro::getCompCondutiv()
{
    this->setValue(this->getUncompValue() * (1+0.02*(this->getWaterTemp()-T0)));
    return this->getValue();
}

void AllcaCondutivimetro::adjustCalibConst(float value)
{
    value /= (1+0.02*(this->getWaterTemp()-T0));
    _calibconst = US_CM_SCALE / (value * this->getWaterResist());
}