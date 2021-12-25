#include "subsynth.h"

Subsynth::Subsynth(double samplerate) : Synth(samplerate){
  osc_1 = new Saw(samplerate);
  osc_2 = new Square(samplerate);
}
Subsynth::~Subsynth(){
  delete osc_1;
  delete osc_2;
  osc_1 = nullptr;
  osc_2 = nullptr;
}

//Oscillators are accumulated and go through 2 Onepole filters (serially)
double Subsynth::output(){
    return (lpf_2.tick(lpf_1.tick((osc_1->tick() + osc_2->tick() / 2.0)))/ 2.0);
}


void Subsynth::setFeedback(double feedback){
  this->feedback = feedback;
  lpf_1.setFeedback(feedback);
  lpf_2.setFeedback(feedback);
}
double Subsynth::getFeedback(){
  return feedback;
}
void Subsynth::setDetune(double detune){
  this->detune = detune;
}


void Subsynth::updatePitches(){
  newPitch = getPitch();
  if(newPitch != oldPitch){
    osc_1->setDelta(mtof(getPitch()));
    osc_2->setDelta(mtof(getPitch() + detune));
    oldPitch = newPitch;
  }
}
