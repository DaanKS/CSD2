#include "simplesynth.h"

Simplesynth::Simplesynth(double amplitude, double samplerate) :
Synth(amplitude, samplerate){
  sine = new Saw(samplerate);
  lpf = new Lowpass();
  lpf_2 = new Lowpass();

}
Simplesynth::~Simplesynth(){}

double Simplesynth::tick(){
  return lpf_2->tick(lpf->tick(amplitude * sine->tick()));
}

void Simplesynth::resetPhase(){
  sine->resetPhase();
}
void Simplesynth::setFrequency(double frequency){
  sine->setFrequency(frequency);
  sine->setDelta(sine->getFrequency(), samplerate);
}

void Simplesynth::setCutoff(double cutoff){
  lpf->setFeedback(cutoff);
  lpf_2->setFeedback(cutoff);
}
