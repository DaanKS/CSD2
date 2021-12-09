#include "synth.h"
#include "sine.h"
#include "saw.h"
#include "square.h"

#pragma once

class Simplesynth : public Synth{
public:
  Simplesynth(double amplitude, double samplerate);
  ~Simplesynth();

  double tick();
  void resetPhase();
  void setFrequency(double frequency);

protected:
//Sine* sine;
  Square* sine;

};
