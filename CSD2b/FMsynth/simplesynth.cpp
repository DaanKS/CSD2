#include "simplesynth.h"

Simplesynth::Simplesynth(double amplitude, double samplerate) :
Synth(amplitude, samplerate){
  sine = new Square(samplerate);
}
Simplesynth::~Simplesynth(){}

double Simplesynth::tick(){
  return amplitude * sine->tick();
}

void Simplesynth::resetPhase(){
  sine->resetPhase();
}
void Simplesynth::setFrequency(double frequency){
  sine->setFrequency(frequency);
  sine->setDelta(sine->getFrequency(), samplerate);
}
