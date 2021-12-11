#include "bisynth.h"

BiSynth::BiSynth(double samplerate) : Synth(samplerate){
  sine1 = new Sine;
  sine2 = new Sine;
}
BiSynth::BiSynth(){}

double BiSynth::tick(){
  return (sine1->tick() + sine2->tick());
}

void BiSynth::initiateOscillators(double frequency){
  sine1->setFrequency(frequency);
  sine2->setFrequency(frequency + getDetune());
  sine1->setDelta(sine1->getFrequency(), samplerate);
  sine2->setDelta(sine2->getFrequency(), samplerate);
}

void BiSynth::resetPhase(){
  sine1->resetPhase();
  sine2->resetPhase();
}
