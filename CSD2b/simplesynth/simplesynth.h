#include "synth.h"
#include "sine.h"

#pragma once

class Simplesynth : public Synth{
public:
  Simplesynth(double amplitude, double samplerate);
  ~Simplesynth();

  double tick();
  void resetPhase();
protected:
Sine* sine;

};
