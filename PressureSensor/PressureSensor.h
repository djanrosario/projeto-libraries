
#ifndef PressureSensor_h
#define PressureSensor_h

class PressureSensor
{
    private:
            int   _address;
            int   _pin;
            float _value;
            float _zero;
            float _fullscale;
    public:
            PressureSensor();
            PressureSensor(int address, int pin, float zero, float fullscale);
            float getValue();

};
#endif