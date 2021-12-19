#include "saw.h"

//Constructors
//========================================
Saw::Saw(double samplerate) : Oscillator(samplerate){
  this->samplerate=samplerate;
}
Saw::~Saw(){}
//Calculating Samples
//========================================
double Saw::calculate(){

  //std::cout << "trick = " << trick << std::endl;
  return ((phase * 2.0) - 1.0);
}
