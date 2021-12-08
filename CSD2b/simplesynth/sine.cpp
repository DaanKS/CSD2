#include "sine.h"

Sine::Sine(double samplerate, double phase) : Oscillator(Oscillator),
samplerate(samplerate), phase(phase){

}
Sine::~Sine(){}

double Sine::calculate(){
  return amplitude * sin(phase * M_PI * 2.0f );
}
