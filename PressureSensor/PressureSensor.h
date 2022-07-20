
#ifndef PressureSensor_h
#define PressureSensor_h

#define STEP  50
#define RESOL 1024

class PressureSensor
{
    private:
            int   _address;
            int   _pin;
            float _value;
            float _zero;
            float _fullscale;
    public:
            PressureSensor(int address = 1, int pin = A0, float zero = 100, float fullscale = 100);
            void  begin();
            float getValue();
            float getAutoZero();
            void  setZero(float value);
            float getZero();
            float getFullScale();
            void  setFullScale(float value);
            float getFullScaleByMeasure(float value);
            float getRawValue();
};
#endif