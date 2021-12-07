#include "additivesynth.h"

Additive::Additive(double samplerate){
  //assign vector of Sine waves
  for (int i = 0; i < 8; ++i)
     sines.emplace_back (Sine(samplerate, phase));
}
Additive::~Additive(){}


double Additive::tick(){
  //TODO accumulate and return output of sines
  for(auto& sin : sines)
      sin.tick();
}


double Additive::setPitch(double pitch){
  //TODO convert pitch to frequency
  //TODO apply pitch calculations to additivesynth
}
double Additive::getPitch(){
  return pitch;
}

void Additive::setPitchRatios(double pitchRatio){
  this->pitchRatio = pitchRatio;
}
double Additive::getPitchRatio(){
  return pitchRatio;
}

void Additive::setPitchRatios(){
  //TODO for loop setting pitch for all oscillators
}
