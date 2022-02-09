#include "saw.h"

Saw::Saw(double samplerate) : Oscillator(samplerate){
}
Saw::~Saw(){}

double Saw::calculate(){
  return phase * 2.0f - 1.0f;
}
