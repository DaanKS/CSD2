#include "oscillator.h"

Oscillator::Oscillator(double samplerate){
  std::cout << "Osc samplerate " << samplerate << " \n";
}
Oscillator::~Oscillator(){}

double Oscillator::tick(){
  phase += delta;
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
  std::cout << "Phase is reset \n";
}

void Oscillator::setDelta(double frequency, double samplerate){
  this->delta = frequency / samplerate;
  
}
