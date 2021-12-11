#include "synth.h"

Synth::Synth(double samplerate){}
Synth::~Synth();

void Synth::setAmplitude(double amplitude){
  this->amplitude = amplitude;
}
void Synth::getAmplitude(){
  return amplitude;
}

void Synth::setPitch(int pitch){
  this->pitch = pitch;
}
int Synth::getPitch(){
  return pitch;
}
