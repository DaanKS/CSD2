#include "biquad.h"

Biquad::Biquad(double samplerate): AudioEffect(samplerate){}
Biquad::~Biquad(){}


float Biquad::output(float inputSample){
  outputSample =  1.0 / Azero * (Bzero * inputSample +
  Bone * his1.tick(inputSample) +
  Btwo * his2.tick(his3.tick(inputSample)) -
  Aone * his4.tick(outputSample) -
  Atwo * his5.tick(his6.tick(outputSample)));
  return outputSample;
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
