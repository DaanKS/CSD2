#include "oscillator.h"

Oscillator::Oscillator(double samplerate, double frequency, double phase){}
Oscillator::~Oscillator();

double Oscillator::tick(){
  return calculate();
}
