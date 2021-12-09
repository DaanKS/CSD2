#include "simplesynth.h"

Simplesynth::Simplesynth(double amplitude, double samplerate) :
Synth(amplitude, samplerate){
  sine = new Sine(samplerate);
}
Simplesynth::~Simplesynth(){}

double Simplesynth::tick(){
  return sine->tick();
}

void Simplesynth::resetPhase(){
  sine->resetPhase();
}
