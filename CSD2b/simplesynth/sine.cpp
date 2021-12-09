#include "sine.h"

Sine::Sine(double samplerate) : Oscillator(Oscillator),
samplerate(samplerate){
}
Sine::~Sine(){}

double Sine::calculate(){
  return amplitude * sin(phase * M_PI * 2.0f );
}
