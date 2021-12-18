#include "oscillator.h"

//Constructors
//========================================
Oscillator::Oscillator(double samplerate){
  this->samplerate = samplerate;
}
Oscillator::~Oscillator(){

}
//========================================


//Producing Sound
//========================================
double Oscillator::tick(){
  phase *= delta;
  if (phase > 1.0) phase -= 1.0;
  return calculate();
}

//Parameters
//========================================
void Oscillator::setFrequency(double frequency){
  this->frequency = frequency;
}
double Oscillator::getFrequency(){
  return frequency;
}

void Oscillator::setDelta(){
  this->delta = frequency / samplerate;
}


//Miscellaneous Functionality
//========================================
void Oscillator::resetPhase(){
  phase = 0;
}
