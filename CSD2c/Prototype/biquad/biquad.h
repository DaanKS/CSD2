//
// Created by Dean on 21/02/2022.
//

#include "history.h"
#include <cmath>
#include <iostream>

#pragma once

class Biquad{
public:
    Biquad(double samplerate);
    ~Biquad();

    float output(float inputSample);

    void setCutoffFreq(float cutoffFreq);
    void setQFactor(float qFactor);

    void calculateOmega();
    void calculateAlpha();
    void calculateCoefficients();

private:
    inline void calculateBzero(){this->Bzero = ((1.0 - cos(omega)) / 2.0);
        std::cout << Bzero << " Bzero" << std::endl; }
    inline void calculateBone(){this->Bone = (1.0 - cos(omega));
        std::cout << Bone << " Bone" << std::endl; }
    inline void calculateBtwo(){this->Btwo = ((1.0 - cos(omega)) / 2.0);
        std::cout << Btwo << " Btwo" << std::endl; }
    inline void calculateAzero(){this->Azero = 1.0 + alpha;
        std::cout << Azero << " Azero" << std::endl; }
    inline void calculateAone(){this->Aone = -2.0 * cos(omega);
        std::cout << Aone << " Aone" << std::endl; }
    inline void calculateAtwo(){this->Atwo = 1.0 - alpha;
        std::cout << Atwo << " Atwo" << std::endl; }

    double samplerate;

    float cutoffFreq;
    float qFactor;
    float omega, alpha;
    float outputSample;

    float Bzero, Bone, Btwo;
    float Azero, Aone, Atwo;

    float x_his1 = 0;
    float x_his2 = 0;
    float y_his1 = 0;

};