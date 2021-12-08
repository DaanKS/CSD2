#include "simplesynth.h"

Simplesynth::Simplesynth(double amplitude) : Synth(Synth),
amplitude(amplitude){
  sine = new Sine;
}
Simplesynth::~Simplesynth();

double Simplesynth::tick(){
  return sine->tick();
}
