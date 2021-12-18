#include "saw.h"

//Constructors
//========================================
Saw::Saw(double samplerate) : Synth(samplerate){
  this->samplerate=samplerate;
}
Saw::~Saw(){}
//Calculating Samples
//========================================
double Saw::calculate(){
  return phase * 2.0 - 1.0;
}
