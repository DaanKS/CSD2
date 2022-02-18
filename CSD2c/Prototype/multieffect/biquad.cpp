#include "biquad.h"

Biquad::Biquad(double samplerate): AudioEffect(samplerate){}
Biquad::~Biquad(){}


void Biquad::calculateTheta(float cutoffFreq){
  this->theta = 2 * M_PI * (cutoffFreq / samplerate);
}
void Biquad::calculateAlpha(float theta){
  this->alpha = (sin(theta) / (2 * qFactor));
}

void Biquad::calculateCoefficients(){
  calculateBzero();
  calculateBone();
  calculateBtwo();
  calculateAzero();
  calculateAone();
  calculateAtwo();
}
