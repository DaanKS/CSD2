#include "synth.h"

Synth::Synth(double samplerate){}
Synth::~Synth();

void Synth::setAmplitude(double amplitude){
  this->amplitude = amplitude;
}
void Synth::getAmplitude(){
  return amplitude;
}

void Synth::setPitch(int pitch){
  this->pitch = pitch;
}
int Synth::getPitch(){
  return pitch;
}

double MTOF(int pitch){
  //https://www.music.mcgill.ca/~gary/307/week1/node28.html
  return 440.0 * pow(2 , ((pitch-69.0)/12.0));
}
