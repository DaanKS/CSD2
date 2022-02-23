//
// Created by Dean on 21/02/2022.
//

#include "biquad.h"


Biquad::Biquad(float samplerate) : samplerate(samplerate),
m_cutoff(2000), m_qFactor(1.0), outputSample(0),
x_his1(0), x_his2(0), y_his1(0),
{}

Biquad::~Biquad() = default;


float Biquad::output(float inputSample)
noexcept {
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

void Biquad::setCutoffFreq(float cutoffFreq){
    this->m_cutoff = cutoffFreq;
}
void Biquad::setQFactor(float qFactor){
    this->m_qFactor = qFactor;
}

void Biquad::calculateOmega(){
    this->omega = 2 * M_PI * (m_cutoff / samplerate);
}
void Biquad::calculateAlpha(){
    this->alpha = (sin(omega) / (2 * m_qFactor));
}

void Biquad::calculateCoefficients(){
    calculateBzero();
    calculateBone();
    calculateBtwo();
    calculateAzero();
    calculateAone();
    calculateAtwo();
}
