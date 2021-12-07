#include "oscillator.h"

Oscillator::Oscillator(double samplerate, double phase){}
Oscillator::~Oscillator();

double Oscillator::tick(){
  phase += freq / samplerate;
  return calculate();
}
