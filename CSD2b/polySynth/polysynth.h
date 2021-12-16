#include "synth.h"
#include "sine.h"
#include "saw.h"
#include "square.h"

#pragma once
#define NUM_VOICES 4

class Polysynth : public Synth{
public:
  Polysynth(double samplerate);
  ~Polysynth();

  double tick();
  void resetPhase();

  
  void setFrequency(int voiceNum, double frequency);

protected:
  Oscillator* osc[NUM_VOICES];

  int voiceNum;

};
