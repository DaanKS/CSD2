//
// Created by Dean on 21/02/2022.
//

#include "biquad.h"


Biquad::Biquad(float samplerate) : AudioEffect(samplerate),
                                   m_cutoff(800), m_qFactor(1.0), outputSample(0),
                                   x_his1(0), x_his2(0), y_his1(0),
                                   filterType(1)
{}
Biquad::~Biquad() = default;


float Biquad::output(float inputSample) noexcept {
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

void Biquad::calculateBzero(){
   this->Bzero = (1.0 - cos(omega)) / 2.0;
}
void Biquad::calculateBone() {
    this->Bone = (1.0 - cos(omega));
}
void Biquad::calculateBtwo(){
    this->Btwo = ((1.0 - cos(omega)) / 2.0);
}
void Biquad::calculateAzero(){
   this->Azero = 1.0 + alpha;
}
void Biquad::calculateAone(){
    this->Aone = -2.0 * cos(omega);
}
void Biquad::calculateAtwo(){
   this->Atwo = 1.0 - alpha;
}