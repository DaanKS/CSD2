#include "synth.h"
#include "saw.h"
#include "square.h"

#pragma once

class Fmsynth : public Synth{
public:
  Fmsynth(double samplerate);
  ~Fmsynth();

  double tick();

  double resetPhase();

  void setRatio(double ratio);
  void getRatio();

  void carFreq(double freq);
  void modFreq(double freq);
  void setFrequencies();

protected:
  Saw* car;
  Saw* mod;

  double freq;
  double ration;

};
