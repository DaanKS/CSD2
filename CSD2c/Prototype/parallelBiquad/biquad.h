//
// Created by Dean on 21/02/2022.
//

#include "audioeffect.h"
#include <cmath>
#include <atomic>
#include <iostream>

#pragma once

struct BiquadCoefficients {
    double Bzero, Bone, Btwo, Azero, Aone, Atwo;
};

class Biquad : public AudioEffect{
public:
    Biquad();
    ~Biquad();

    float output(float inputSample) noexcept;
    void setCoefficients(const BiquadCoefficients& coefficients);

    BiquadCoefficients makeLowPass(float cutoff, float qFactor, float samplerate) noexcept;
    BiquadCoefficients makeHighPass(float cutoff, float qFactor, float samplerate) noexcept;

private:
    std::atomic<BiquadCoefficients> currentCoefficients;

    float outputSample;
    float x_his1;
    float x_his2;
    float y_his1;

};
