//
// Created by Dean on 21/02/2022.
//
// Formula's taken from http://shepazu.github.io/Audio-EQ-Cookbook/audio-eq-cookbook.html
//

#include <cmath>
#include <atomic>
#include <iostream>

#pragma once

struct BiquadCoefficients {
    double Bzero, Bone, Btwo, Azero, Aone, Atwo;
};

class Biquad{
public:
    Biquad();
    ~Biquad();

    Biquad(const Biquad& other){
        currentCoefficients.store(other.currentCoefficients.load());
        outputSample = other.outputSample;
        x_his1 = other.x_his1;
        x_his2 = other.x_his2;
        y_his1 = other.y_his1;
    }

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