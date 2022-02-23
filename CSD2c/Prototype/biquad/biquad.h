//
// Created by Dean on 21/02/2022.
//

#include "history.h"
#include <cmath>
#include <iostream>

#pragma once

class Biquad{
public:
    Biquad(float samplerate);
    ~Biquad();

    float output(float inputSample) noexcept;

    void setCutoffFreq(float cutoffFreq);
    void setQFactor(float qFactor);

    void calculateOmega();
    void calculateAlpha();
    void calculateCoefficients();

private:
    inline void calculateBzero(){this->Bzero = ((1.0 - cos(omega)) / 2.0);}
    inline void calculateBone(){this->Bone = (1.0 - cos(omega));}
    inline void calculateBtwo(){this->Btwo = ((1.0 - cos(omega)) / 2.0);}
    inline void calculateAzero(){this->Azero = 1.0 + alpha;}
    inline void calculateAone(){this->Aone = -2.0 * cos(omega);}
    inline void calculateAtwo(){this->Atwo = 1.0 - alpha;}

    float samplerate;

    float m_cutoff;
    float m_qFactor;
    float omega, alpha;
    float outputSample;

    float Bzero, Bone, Btwo;
    float Azero, Aone, Atwo;

    float x_his1;
    float x_his2;
    float y_his1;

};