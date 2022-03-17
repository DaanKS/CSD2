//
// Created by Dean on 21/02/2022.
//

#include "biquad.h"


Biquad::Biquad() :  AudioEffect(),
                    outputSample(0),
                    x_his1(0), x_his2(0), y_his1(0)
{}
Biquad::~Biquad() = default;


float Biquad::output(float inputSample) noexcept {

const auto [Bzero, Bone, Btwo, Azero, Aone, Atwo] = currentCoefficients;
outputSample = ((Bzero / Azero) * inputSample) +
               ((Bone / Azero) * x_his1) +
               ((Btwo / Azero) * x_his2) -
               ((Aone / Azero) * outputSample) -
               ((Atwo / Azero) * y_his1);
//recache values
    x_his2 = x_his1;
    x_his1 = inputSample;
    y_his1 = outputSample;

return outputSample;
}

void Biquad::setCoefficients(const BiquadCoefficients &coefficients) {
    currentCoefficients = coefficients;
}

BiquadCoefficients Biquad::makeLowPass(float cutoff, float qFactor, float samplerate) noexcept {
    const auto omega = 2 * M_PI * (cutoff / samplerate);
    const auto alpha = (sin(omega) / (2 * qFactor));
    return {
        .Bzero = (1.0 - cos(omega)) / 2.0;
        .Bone = (1.0 - cos(omega));
        .Btwo = ((1.0 - cos(omega)) / 2.0);
        .Azero = 1.0 + alpha;
        .Aone = -2.0 * cos(omega);
        .Atwo = 1.0 - alpha;
    }
}

