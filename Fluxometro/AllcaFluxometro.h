/* AllcaFluxometro.h
* Arquivo de cabeçalho da classe AllcaFluxometro
* Autor: Djan Rosario
* Data: 22/07/2022
* Versão: 1.0
* 
*/

#ifndef ALLCAFLUXOMETRO_H
#define ALLCAFLUXOMETRO_H

class AllcaFluxometro {
    private:
            int _address;
            int _pin;
            float _value;
            float _rateFactor;

    public:
            AllcaFluxometro(int address = 1, int pin = 2, float rateFactor = 10.5);
            void begin(void (*userfunc)());
            float getValue(int countPulses);
            float calcRateFactor(float value, int countPulses);
};

#endif
