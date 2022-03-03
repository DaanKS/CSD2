//
// Created by Dean on 21/02/2022.
//

#include "audioeffect.h"
#include <cmath>
#include <iostream>

#pragma once

class Biquad : public AudioEffect{
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
    void calculateBzero();
    void calculateBone();
    void calculateBtwo();
    void calculateAzero();
    void calculateAone();
    void calculateAtwo();

    float m_cutoff;
    float m_qFactor;
    float omega, alpha;
    float outputSample;

    float Bzero, Bone, Btwo;
    float Azero, Aone, Atwo;

    float x_his1;
    float x_his2;
    float y_his1;

    int filterType;

};
};