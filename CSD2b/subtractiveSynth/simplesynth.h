#include "synth.h"
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "lowpass.h"
#include "oscillator.h"

#pragma once

class Simplesynth : public Synth{
public:
  Simplesynth(double amplitude, double samplerate);
  ~Simplesynth();

  double tick();
  void resetPhase();
  void setFrequency(double frequency);
  void setCutoff(double cutoff);

protected:
//Sine* sine;
  Saw* sine;
  Lowpass* lpf;
  Lowpass* lpf_2;

  double cutoff;
};
