#include "FMsynth.h"

Fmsynth::Fmsynth(double samplerate) : Synth(samplerate){
  car = new Sine(samplerate);
  mod = new Sine(samplerate);
}
Fmsynth::~Fmsynth(){
  delete car;
  car = nullptr;
  delete mod;
  mod = nullptr;
}

double Fmsynth::tick(){
  //Ring Modulation (LOL)
  return car->tick() * mod->tick();
}

void Fmsynth::resetPhase(){
  car->resetPhase();
  mod->resetPhase();
}

//Ratio to have modFreq dependant on carFreq
void Fmsynth::setRatio(double ratio){
  this->ratio = ratio;
}
double Fmsynth::getRatio(){
  return ratio;
}


void Fmsynth::carFreq(double freq){
  car->setFrequency(freq);
  car->setDelta(car->getFrequency(), samplerate);

}
void Fmsynth::modFreq(double freq){
  mod->setFrequency(freq);
  mod->setDelta(mod->getFrequency(), samplerate);
}
//Apply Actual frequencies
void Fmsynth::setFrequencies(){
  double oscFreq = MTOF(getPitch());
  carFreq(oscFreq);
  modFreq(oscFreq * getRatio());
}
