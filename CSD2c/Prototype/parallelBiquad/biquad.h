//
// Created by Dean on 21/02/2022.
//
// Formula's taken from http://shepazu.github.io/Audio-EQ-Cookbook/audio-eq-cookbook.html
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
    Biquad(double samplerate);
    ~Biquad();

    float output(float inputSample) noexcept;
    void setCoefficients(const BiquadCoefficients& coefficients);

    BiquadCoefficients makeLowPass(float cutoff, float qFactor, float samplerate) noexcept;
    BiquadCoefficients makeHighPass(float cutoff, float qFactor, float samplerate) noexcept;
    BiquadCoefficients makeBandPass(float cutoff, float qFactor, float samplerate, float bandwidth) noexcept;

private:
    std::atomic<BiquadCoefficients> currentCoefficients;

    float outputSample;
    float x_his1;
    float x_his2;
    float y_his1;

};

// TODO -> add more filters!