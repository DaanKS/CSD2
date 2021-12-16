#include "polysynth.h"

//==================================================================\\
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
//==================================================================\\

//==================================================================\\
double Polysynth::tick(){
  for(int i = 0; i < NUM_VOICES; i++){
    return osc[i]->tick();
  }
}

void Polysynth::resetPhase(){
  for(int i = 0; i <NUM_VOICES; i++){
    osc[i]->resetPhase();
  }
}
//==================================================================\\

//==================================================================\\
void Polysynth::setFrequency(int voiceNum, double frequency, double samplerate){
  //osc[voiceNum]->setFrequency(frequency);
  osc[voiceNum]->setDelta(frequency, samplerate);
}
