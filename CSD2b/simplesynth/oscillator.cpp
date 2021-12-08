#include "oscillator.h"

Oscillator::Oscillator(double samplerate, double phase){}
Oscillator::~Oscillator();

double Oscillator::tick(){
  phase += frequency / samplerate;
  return calculate();
}

void Oscillator::setFrequency(double frequency){
  this->frequency = frequency;
}
double Oscillator::getFrequency(){
  return frequency;
}
