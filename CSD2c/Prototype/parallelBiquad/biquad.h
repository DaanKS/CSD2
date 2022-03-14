//
// Created by Dean on 21/02/2022.
//

#include "audioeffect.h"
#include <cmath>
#include <iostream>

#pragma once

class Biquad : public AudioEffect{
public:
    Biquad();
    ~Biquad();

    float output(float inputSample) noexcept;

    void setCutoffFreq(float cutoffFreq);
    void setQFactor(float qFactor);

    void calculateOmega();
    void calculateAlpha();
    void calculateCoefficients();



protected:
    virtual void calculateBzero();
    virtual void calculateBone();
    virtual void calculateBtwo();
    virtual void calculateAzero();
    virtual void calculateAone();
    virtual void calculateAtwo();

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
