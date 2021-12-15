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


void Fmsynth::setRatio(double ratio){
  this->ration = ratio;
}
double Fmsynth::getRatio(){
  return ratio;
}
