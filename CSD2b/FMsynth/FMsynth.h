#include "synth.h"
#include "saw.h"
#include "square.h"

#pragma once

class Fmsynth : public Synth{
public:
  Fmsynth(double samplerate);
  ~Fmsynth();

  double tick();

  void resetPhase();

  void setRatio(double ratio);
  double getRatio();

  void carFreq(double freq);
  void modFreq(double freq);
  void setFrequencies();

protected:
  Oscillator* car;
  Oscillator* mod;

  double freq;
  double ratio;

};
