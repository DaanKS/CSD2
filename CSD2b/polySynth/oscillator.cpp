#include "oscillator.h"

Oscillator::Oscillator(double samplerate){
  
}
Oscillator::~Oscillator(){}

void Oscillator::tick(){
  phase += delta;
  if(phase > 1.0) phase -= 1.0;
  sample = calculate();
}
double Oscillator::getSample(){
  return sample;
}

void Oscillator::setFrequency(double frequency){
  this->frequency = frequency;
  std::cout << "Osc Freq: " << frequency << " \n";
}
double Oscillator::getFrequency(){
  return frequency;
}

void Oscillator::resetPhase(){
  phase = 0;
  std::cout << "Phase is reset \n";
}

void Oscillator::setDelta(double frequency, double samplerate){
  this->delta = frequency / samplerate;
  std::cout << "delta is: " << delta << "\n";
}
