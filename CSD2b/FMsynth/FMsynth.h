#include "synth.h"
#include "saw.h"
#include "square.h"
#include "sine.h"

#pragma once

class Fmsynth : public Synth{
public:
  Fmsynth(double samplerate);
  ~Fmsynth();

  double tick();

  void resetPhase();

  void setRatio(double ratio);
  double getRatio();
  void setModulationIndex(double ratio, double oscFreq);
  double getModulationIndex();

  void carFreq(double freq);
  void modFreq(double freq);
  void setFrequencies(); //modulator
  void calculateCarrierFreq();

protected:
  Oscillator* car;
  Oscillator* mod;

  double freq;
  double ratio;
  double modulationIndex;

  double oscFreq;
};
