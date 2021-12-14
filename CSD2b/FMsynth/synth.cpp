#include "synth.h"
#include <cmath>
#include <iostream>

Synth::Synth(double samplerate){

  this->samplerate = samplerate;
}
Synth::~Synth(){}

void Synth::setAmplitude(double amplitude){
  if(amplitude >= 0.0 && amplitude <= 1.0){
    this->amplitude = amplitude;
  }else{
    this->amplitude = 0.1;
  }
}
double Synth::getAmplitude(){
  return amplitude;
}

void Synth::setPitch(int pitch){
  if(pitch >= 0 && pitch <= 127){
    this->pitch = pitch;
  }else{
    this->pitch = 60;
  }
}
int Synth::getPitch(){
  return pitch;
}

double Synth::MTOF(int pitch){
//https://www.music.mcgill.ca/~gary/307/week1/node28.html
   return 440.0 * pow(2 , ((pitch-69.0)/12.0));
}
