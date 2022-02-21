//
// Created by Dean on 21/02/2022.
//

#include "biquad.h"


Biquad::Biquad(double samplerate) : AudioEffect(samplerate){
    this->samplerate = samplerate;
    his1 = new History;
    his2 = new History;
    his3 = new History;
    his4 = new History;
    his5 = new History;
    his6 = new History;
}

Biquad::~Biquad(){
    delete his1;
    his1 = nullptr;
    delete his2;
    his2 = nullptr;
    delete his3;
    his3 = nullptr;
    delete his4;
    his4 = nullptr;
    delete his5;
    his5 = nullptr;
    delete his6;
    his6 = nullptr;
}


float Biquad::output(float inputSample){
/*
  outputSample =  ((1.0 / Azero) * ((Bzero * inputSample) +
                    (Bone * his1->tick(inputSample)) +
                    (Btwo * his2->tick(his3->tick(inputSample))) -
                    (Aone * his4->tick(outputSample)) -
                    (Atwo * his5->tick(his6->tick(outputSample)))));

  outputSample = (Bzero * inputSample) + (Bone * his1->tick(inputSample)) +
          Btwo * his2->tick(his3->tick(inputSample)) -
          Aone * his4->tick(outputSample)-
          Atwo * his5->tick(his6->tick(outputSample));

    outputSample = ((Bzero / Azero) * inputSample) +
                   ((Bone / Azero) * his1->tick(inputSample)) +
                   ((Btwo / Azero) * his2->tick(his3->tick(inputSample))) -
                   ((Aone / Azero) * his4->tick(outputSample)) -
                   ((Atwo / Azero) * his5->tick(his6->tick(outputSample))); */
    // std::cout << outputSample << std::endl;
    //y[n] = a0 * x[n] + a1 * x[n-1] + a2 * x[n-2] - b1 * y[n-1] - b2 * y[n-2];

    outputSample = (Azero * inputSample) +
                   (Aone * his1->tick(inputSample)) +
                   (Atwo * his2->tick(his3->tick(inputSample))) -
                   (Bone * his4->tick(outputSample)) -
                   (Btwo * his5->tick(his6->tick(outputSample)));
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