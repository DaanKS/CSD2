#include "bisynth.h"

Bisynth::Bisynth(double amplitude, double samplerate) :
Synth(amplitude, samplerate) {
  sine1 = new Sine(samplerate);
  sine2 = new Sine(samplerate);
}
Bisynth::~Bisynth(){}

double Bisynth::tick(){
  return (sine1->tick() + sine2->tick()) / 2.0;
}
void Bisynth::setFrequencies(){
  double nuPitch = MTOF(getPitch());
  std::cout << "Nu Pitch " << nuPitch <<  "\n";
  sine1->setFrequency(nuPitch);
  sine2->setFrequency(nuPitch + getDetune());
}
void Bisynth::setDetune(double amtDetune){
  this->amtDetune = amtDetune;
}
double Bisynth::getDetune(){
  return amtDetune;
}
