#include "synth.h"

Synth::Synth(double amplitude){
  this->amplitude = amplitude;
}
Synth::~Synth(){}

void Synth::setAmplitude(double amplitude){
  if(amplitude >= 0.0 && amplitude <= 1.0){
    this->amplitude = amplitude;
  }else{
    this->amplitude = 0.1;
  }
}
double Synth::getAmplitude(){
  return amplitude;
}
