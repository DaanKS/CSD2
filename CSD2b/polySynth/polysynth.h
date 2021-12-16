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

  void tick();
  double output(int voiceNum);
  void resetPhase();


  void setFrequencies(int voiceNum, double samplerate);
  void setPitchPerVoice(int voiceNum, int pitch);

protected:
  Oscillator* osc[NUM_VOICES];

  int voiceNum;

};
