#include "synth.h"
#include "saw.h"

#pragma once

#define NUMOSC 3

class Supersynth : public Synth{
public:
  Supersynth(double samplerate);
  ~Supersynth();

  double tick() override;
  void accumulateOutput();

  void setPitches();
  void updatePitchesFromMidi();

private:
  Oscillator* osc[NUMOSC];
  int pitchMod[NUMOSC] = {0, 12, -12};
  double sample;

  double oldPitch;
  double newPitch;
  

};
