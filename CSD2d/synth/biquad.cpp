//
// Created by Dean on 21/02/2022.
//

#include "biquad.h"


Biquad::Biquad() :
                    outputSample(0),
                    x_his1(0), x_his2(0), y_his1(0)
{}
Biquad::~Biquad() = default;


float Biquad::output(float inputSample) noexcept {

const auto [Bzero, Bone, Btwo, Azero, Aone, Atwo] = currentCoefficients.load();
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
    currentCoefficients.store(coefficients);
}

BiquadCoefficients Biquad::makeLowPass(float cutoff, float qFactor, float samplerate) noexcept {
    const auto omega = 2 * M_PI * (cutoff / samplerate);
    const auto alpha = (sin(omega) / (2 * qFactor));
    return {
        .Bzero = (1.0 - cos(omega)) / 2.0,
        .Bone = (1.0 - cos(omega)),
        .Btwo = ((1.0 - cos(omega)) / 2.0),
        .Azero = 1.0 + alpha,
        .Aone = -2.0 * cos(omega),
        .Atwo = 1.0 - alpha
    };
}
/**
 * JS DOCS
 * @param cutoff
 * @param qFactor
 * @param samplerate
 * @return <BiquadCoefficients> 's filter coefficients
 */
BiquadCoefficients Biquad::makeHighPass(float cutoff, float qFactor, float samplerate) noexcept {
    const auto omega = 2 * M_PI * (cutoff / samplerate);
    const auto alpha = (sin(omega) / (2 * qFactor));
    return {
        .Bzero = (1.0 + cos(omega)) / 2.0,
        .Bone = -1 * (1.0 + cos(omega)),
        .Btwo = (1.0 + cos(omega)) / 2.0,
        .Azero = 1.0 + alpha,
        .Aone = -2.0 * cos(omega),
        .Atwo = 1.0 - alpha
    };
}

/**
 *
 * @param cutoff is de cutoff frequency.
 * @param qFactor
 * @param samplerate
 * @param bandwidth
 * @return
 */
BiquadCoefficients Biquad::makeBandPass(float cutoff, float qFactor, float samplerate, float bandwidth) noexcept{
    const auto omega = 2 * M_PI * (cutoff / samplerate);
    const auto alpha = sin(omega) * sinh((log(2)/ 2.0f) * bandwidth * (omega / sin(omega)));
    return {
        .Bzero = (qFactor * alpha),
        .Bone = 0,
        .Btwo = ((-1 * qFactor) * alpha),
        .Azero = 1 + alpha,
        .Aone = -2.0 * cos(omega),
        .Atwo = 1.0 - alpha
    };
}