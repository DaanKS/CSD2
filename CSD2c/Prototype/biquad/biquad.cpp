//
// Created by Dean on 21/02/2022.
//

#include "biquad.h"


Biquad::Biquad(float samplerate) : samplerate(samplerate),
m_cutoff(2000), m_qFactor(1.0), outputSample(0),
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
    if (filterType == 0){this->Bzero = (1.0 - cos(omega)) / 2.0;}
    else{this->Bzero = (1.0 + cos(omega)) / 2.0;}
}
void Biquad::calculateBone() {
    if (filterType == 0) { this->Bone = (1.0 - cos(omega)); }
    else { this->Bone = -1 * (1.0 + cos(omega)); }
}
void Biquad::calculateBtwo(){
    if(filterType == 0){this->Btwo = ((1.0 - cos(omega)) / 2.0);}
    else{this->Btwo = (1.0 + cos(omega)) / 2.0;}
}
void Biquad::calculateAzero(){
    if(filterType == 0){this->Azero = 1.0 + alpha;}
    else{this->Azero = 1.0 + alpha;}
}
void Biquad::calculateAone(){
    if(filterType == 0){this->Aone = -2.0 * cos(omega);}
    else{this->Aone = (-2.0 * cos(omega));}
}
void Biquad::calculateAtwo(){
    if(filterType == 0){this->Atwo = 1.0 - alpha;}
    else{this->Atwo = 1.0 - alpha;}
}