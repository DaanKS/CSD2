#include "sine.h"


Sine::Sine(double samplerate) : Oscillator(samplerate){
}
Sine::~Sine(){}

double Sine::calculate(){
  return sin(phase * M_PI * 2.0f );
}
