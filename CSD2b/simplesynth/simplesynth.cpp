#include "simplesynth.h"

Simplesynth::Simplesynth(double amplitude, double samplerate) :
Synth(Synth), amplitude(amplitude), samplerate(samplerate){
  sine = new Sine(samplerate);
}
Simplesynth::~Simplesynth();

double Simplesynth::tick(){
  return sine->tick();
}
