#include "sine.h"
#include <iostream>

Sine::Sine(double samplerate) : Oscillator(samplerate){
}
Sine::~Sine(){}

double Sine::calculate(){
  double sample = sin(phase * M_PI * 2.0f );
  std::cout << sample << " \n";
  return sample;
}
