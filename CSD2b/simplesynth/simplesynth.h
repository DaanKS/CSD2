#include "synth.h"
#include "sine.h"

#pragma once

class Simplesynth : public Synth{
public:
  Simplesynth(double amplitude);
  ~Simplesynth();

  double tick();
protected:
Sine* sine;

};
