#include "sine.h"
#include <iostream>

Sine::Sine(double samplerate) : Oscillator(samplerate){
}
Sine::~Sine(){}

double Sine::calculate(){
  double sample = sin(phase * M_PI * 2.0f );
  //std::cout << "Sample: " << sample << " \n";
  return sample;
}
