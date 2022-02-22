//
// Created by Dean on 21/02/2022.
//

#include "biquad.h"


Biquad::Biquad(double samplerate){
    this->samplerate = samplerate;

}

Biquad::~Biquad(){

}


float Biquad::output(float inputSample){
    outputSample = ((Bzero / Azero) * inputSample) +
                   ((Bone / Azero) * x_his1) +
                   ((Btwo / Azero) * x_his2) -
                   ((Aone / Azero) * outputSample) -
                   ((Atwo / Azero) * y_his1);

// recache values
    x_his2 = x_his1;
    x_his1 = inputSample;
    y_his1 = outputSample;

    return outputSample;
    return outputSample;

}

void Biquad::setCutoffFreq(float cutoffFreq){
    this->cutoffFreq = cutoffFreq;
    std::cout << cutoffFreq << " CutOff" << std::endl;
}
void Biquad::setQFactor(float qFactor){
    this->qFactor = qFactor;
    std::cout << qFactor << " qFactor" << std::endl;
}

void Biquad::calculateOmega(){
    this->omega = 2 * M_PI * (cutoffFreq / samplerate);
    std::cout << omega << " Omega" << std::endl;
    std::cout << samplerate << " Calculate Omega" << std::endl;
}
void Biquad::calculateAlpha(){
    this->alpha = (sin(omega) / (2 * qFactor));
    std::cout << alpha << " alpha" <<std::endl;
}

void Biquad::calculateCoefficients(){
    calculateBzero();
    calculateBone();
    calculateBtwo();
    calculateAzero();
    calculateAone();
    calculateAtwo();
}
