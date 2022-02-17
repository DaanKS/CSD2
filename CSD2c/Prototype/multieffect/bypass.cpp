#include "bypass.h"

Bypass::Bypass(double samplerate) : AudioEffect(samplerate){
  std::cout << "Bypass Constructor" << std::endl;
}
Bypass::~Bypass(){}

float Bypass::output(float inputSample){
  return inputSample;
}
