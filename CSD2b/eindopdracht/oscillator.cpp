#include "oscillator.h"

Oscillator::Oscillator(double samplerate){
  this->samplerate=samplerate;
  resetPhase();
}
Oscillator::~Oscillator(){}



double Oscillator::tick(){
  phase += delta;
  if(phase > 1.0) phase -= 1.0;
  return calculate();
}

void Oscillator::setDelta(double frequency){
  this->delta = frequency / samplerate;
}

void Oscillator::resetPhase(){
  phase = 0;
}
