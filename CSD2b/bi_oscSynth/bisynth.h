#include "synth.h"
#include "sine.h"

#pragma once

class BiSynth : public Synth{
public:
  BiSynth(double samplerate);
  ~BiSynth();

  double tick();

  void initiateOscillators(double frequency);
  void resetPhase();

protected:
  Sine* sine1;
  Sine* sine2;

  double frequency;
};
