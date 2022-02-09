#include "oscillator.h"

Oscillator::Oscillator(double samplerate){
    resetPhase();
    this->samplerate = samplerate;
}
Oscillator::~Oscillator(){}

double Oscillator::output(){
    phase += delta;
    if(phase > 1.0) phase -= 1.0;
    return calculate();
}

void Oscillator::setDelta(double frequency){
    this->frequency = frequency;
    this->delta = frequency / samplerate;
}
double Oscillator::getFrequency(){
    return frequency;
}
void Oscillator::resetPhase(){
    this->phase = 0;
}
