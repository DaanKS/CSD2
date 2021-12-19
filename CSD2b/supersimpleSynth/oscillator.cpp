#include "oscillator.h"

//Constructors
//========================================
Oscillator::Oscillator(double samplerate){
  this->samplerate = samplerate;
  resetPhase();
  std::cout << "OSC samplerate = " << samplerate << std::endl;
}
Oscillator::~Oscillator(){

}
//========================================


//Producing Sound
//========================================
double Oscillator::tick(){
  phase += delta;
  if (phase > 1.0) phase -= 1.0;
  return calculate();
}

//Parameters
//========================================
void Oscillator::setFrequency(double frequency){
  this->frequency = frequency;
  std::cout << "OSC Frequency = " << frequency;
}
double Oscillator::getFrequency(){
  return frequency;
}

void Oscillator::setDelta(double frequency){
  this->delta = frequency / samplerate;
  std::cout << "OSC delta = " << delta << std::endl;
}


//Miscellaneous Functionality
//========================================
void Oscillator::resetPhase(){
  phase = 0;
}
