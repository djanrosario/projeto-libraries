#ifndef condutivimetro_h
#define condutivimetro_h

#include <Arduino.h>

#define RESOL       1023.0
#define RREF        10000.0
#define US_CM_SCALE 100000
#define T0          298.0
#define BETA        3600.0


class AllcaCondutivimetro
{
    private:
            int _address;
            int _powerpin;
            int _readpin;
            int _ntcpin;
            float _vin;
            float _uncompvalue;
            float _value;
            float _resistvalue;
            float _calibconst;
            float _tempF;
    public:
            AllcaCondutivimetro(int address = 1, int powerpin = A0, 
                                int readpin = A1, int ntcpin = A2, 
                                float vin = 5.0, float calibconst = 0.11);
            void begin();
            float getRawValue();
            void  setResist(float value);
            float getResist();
            float getWaterResist();
            float getUncompValue();
            void  setUncompValue(float value);
            float getUncompCondutiv();
            void  setTemp(float value);
            float getTemp();
            float getWaterTemp();
            void  setValue(float value);
            float getValue();
            float getCompCondutiv();
            void  adjustCalibConst(float value);
};
#endif