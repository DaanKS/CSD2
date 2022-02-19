#include "biquad.h"

Biquad::Biquad(double samplerate): AudioEffect(samplerate){}
Biquad::~Biquad(){}


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
