#include "fmsynth.h"

Fmsynth::Fmsynth(double samplerate) : Synth(samplerate),
 ratio(1.02), modDepth(2){
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
//function to calculate the frequency of the carrier oscillator
void Fmsynth::calculateCarrierFreq(){
  setCarDelta(oscFreq + (mod->tick() * getModulationIndex()));
}

//pitch only changes if a new pitch is found
void Fmsynth::updatePitches(){
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



//Duplicate Code! Simple instructions to loop through wave types
void Fmsynth::changeWaveCar(){
  if(carPos > 2) carPos = 0;
  if(carPos == 0){
    delete car;
    car = new Saw(samplerate);
    setCarDelta(frequency);
  }else if(carPos == 1){
    delete car;
    car = new Square(samplerate);
    setCarDelta(frequency);
  }else{
    delete car;
    car = new Sine(samplerate);
    setCarDelta(frequency);
  }
  carPos++;
}

void Fmsynth::changeWaveMod(){
  if(modPos > 2) modPos = 0;
  if(modPos == 0){
    delete mod;
    mod = new Saw(samplerate);
    setModDelta(frequency);
  }else if(modPos == 1){
    delete mod;
    mod = new Square(samplerate);
    setModDelta(frequency);
  }else{
    delete mod;
    mod = new Sine(samplerate);
    setModDelta(frequency);
  }
  modPos++;
}
