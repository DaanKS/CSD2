#include "supersynth.h"

Supersynth::Supersynth(double samplerate) : Synth(samplerate){
  for(int i = 0; i < NUMOSC; i++){
    osc[i] = new Saw;
  }
}
Supersynth::~Supersynth(){
  for(int i = 0; i < NUMOSC; i++){
    delete osc[i];
    osc[i] = nullptr;
  }
}

double Supersynth::tick(){
  return sample * amplitude;
}
void Supersynth::accumulateOutput(){
  sample = (osc[0]->tick() + osc[1]->tick() + osc[2]->tick()) / 3.0;
}

void setPitches(){
  for(int i = 0; i < NUMOSC;){
    osc[i]->setDelta(MTOF(getPitch() + pitchMod[i]));
  }
}
