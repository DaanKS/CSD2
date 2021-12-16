#include "polysynth.h"

//==================================================================
Polysynth::Polysynth(double samplerate) : Synth(samplerate){
  for(int i = 0; i < NUM_VOICES; i++){
    osc[i] = new Sine(samplerate);
  }
}
Polysynth::~Polysynth(){
  for(int i = 0; i < NUM_VOICES; i++){
    delete osc[i];
    osc[i] = nullptr;
  }
}
//==================================================================

//==================================================================
void Polysynth::tick(){
  for(int i = 0; i < NUM_VOICES; i++){
    osc[i]->tick();
  }
}
double Polysynth::output(int voiceNum){
  return osc[voiceNum]->getSample();
}

void Polysynth::resetPhase(){
  for(int i = 0; i <NUM_VOICES; i++){
    osc[i]->resetPhase();
  }
}
//==================================================================

//==================================================================
void Polysynth::setFrequencies(int voiceNum, double samplerate){
  //osc[voiceNum]->setFrequency(frequency);
  osc[voiceNum]->setDelta(osc[voiceNum]->getFrequency(), samplerate);
}
void Polysynth::setPitchPerVoice(int voiceNum, int pitch){
  osc[voiceNum]->setFrequency(MTOF(pitch));
}
