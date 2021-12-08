#include "oscillator.h"

Oscillator::Oscillator(double samplerate){}
Oscillator::~Oscillator();

double Oscillator::tick(){
  phase += frequency / samplerate;
  if(phase > 1.0) phase -= 1.0;
  return calculate();
}

void Oscillator::setFrequency(double frequency){
  this->frequency = frequency;
}
double Oscillator::getFrequency(){
  return frequency;
}

void Oscillator::resetPhase(){
  phase = 0;
}
