#include "supersynth.h"

Supersynth::Supersynth(double samplerate) : Synth(samplerate){
  for(int i = 0; i < NUMOSC; i++){
    osc[i] = new Saw(samplerate);
  }
}
Supersynth::~Supersynth(){
  for(int i = 0; i < NUMOSC; i++){
    delete osc[i];
    osc[i] = nullptr;
  }
}

double Supersynth::tick(){
  return sample * getAmplitude();
}
void Supersynth::accumulateOutput(){
  sample = (osc[0]->tick() + osc[1]->tick() + osc[2]->tick()) / 3.0;


}

void Supersynth::setPitches(){
  for(int i = 0; i < NUMOSC; i++){
    osc[i]->setFrequency(MTOF(getPitch() + pitchMod[i]));
    osc[i]->setDelta(osc[i]->getFrequency());
  }
}
