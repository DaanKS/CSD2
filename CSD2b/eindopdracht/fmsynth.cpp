#include "fmsynth.h"

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


double Fmsynth::output(){
  calculateCarrierFreq();
  return car->tick();
}

void Fmsynth::calculateCarrierFreq(){
  setCarDelta(oscFreq + (mod->tick() * getModulationIndex()));
}

void Fmsynth::setPitches(){
  newPitch = getPitch();
  if(newPitch != oldPitch){
    double tempFreq = mtof(newPitch);
    setModulationIndex(tempFreq);
    setModDelta(tempFreq * getRatio());
    oldPitch = newPitch;
  }
}


void Fmsynth::setRatio(double ratio){
  this->ratio = ratio;
}
double Fmsynth::getRatio(){
  return ratio;
}
void Fmsynth::setModDepth(double modDepth){
  this->modDepth = modDepth;
}
double Fmsynth::getModDepth(){
  return modDepth;
}
void Fmsynth::setModulationIndex(double oscFreq){
  this->modulationIndex = ((getRatio() * oscFreq) * getModDepth());
}
double Fmsynth::getModulationIndex(){
  return modulationIndex;
}


void Fmsynth::setCarDelta(double frequency){
  car->setDelta(frequency);
}
void Fmsynth::setModDelta(double frequency){
  mod->setDelta(frequency);
}
