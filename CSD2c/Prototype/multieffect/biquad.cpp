#include "biquad.h"

Biquad::Biquad(double samplerate): AudioEffect(samplerate){
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
  outputSample =  1.0 / Azero * (Bzero * inputSample +
  Bone * his1->tick(inputSample) +
  Btwo * his2->tick(his3->tick(inputSample)) -
  Aone * his4->tick(outputSample) -
  Atwo * his5->tick(his6->tick(outputSample)));
  return outputSample;
}

void Biquad::setCutoffFreq(float cutoffFreq){
  this->cutoffFreq = cutoffFreq;
}
void Biquad::setQFactor(float qFactor){
  this->qFactor = qFactor;
}

void Biquad::calculateOmega(float cutoffFreq){
  this->omega = 2 * M_PI * (cutoffFreq / samplerate);
}
void Biquad::calculateAlpha(float omega){
  this->alpha = (sin(omega) / (2 * qFactor));
}

void Biquad::calculateCoefficients(){
  calculateBzero();
  calculateBone();
  calculateBtwo();
  calculateAzero();
  calculateAone();
  calculateAtwo();
}
