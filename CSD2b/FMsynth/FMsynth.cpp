#include "FMsynth.h"

Fmsynth::Fmsynth(double samplerate) : Synth(samplerate){
  car = new Saw(samplerate);
  mod = new Saw(samplerate);
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

double Fmsynth::resetPhase(){
  car->resetPhase();
  mod->resetPhase();
}

//Ratio to have modFreq dependant on carFreq
void Fmsynth::setRatio(double ratio){
  this->ration = ratio;
}
double Fmsynth::getRatio(){
  return ratio;
}


void Fmsynth::carFreq(double freq){
  car->setFrequency(freq);
}
void Fmsynth::modFreq(double freq){
  mod->setFrequency(freq)
}
//Apply Actual frequencies
void Fmsynth::setFrequencies(){
  double oscFreq = MTOF(getPitch());
  carFreq(oscFreq);
  modFreq(oscFreq * getRatio());
}
