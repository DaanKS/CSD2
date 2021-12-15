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
  calculateCarrierFreq();
  return car->tick();
}

void Fmsynth::resetPhase(){
  car->resetPhase();
  mod->resetPhase();
}

//FM parameters
//Ratio to have modFreq dependant on carFreq
void Fmsynth::setRatio(double ratio){
  this->ratio = ratio;
}
double Fmsynth::getRatio(){
  return ratio;
}
//ModulationIndex
void Fmsynth::setModulationIndex(){
  this->modulationIndex = ratio * *oscFreq;
}
double Fmsynth::getModulationIndex(){
  return modulationIndex;
}

//Pitches
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
  *oscFreq = MTOF(getPitch());
  modFreq(*oscFreq * getRatio());
}
void Fmsynth::calculateCarrierFreq(){
  //modulation index = (ratio * oscFreq) * x   (1 <= x >= 0.0)
  //(mod * modulation index) + (carFreq)
  carFreq(*oscFreq + (mod->tick() * getModulationIndex()));
}
