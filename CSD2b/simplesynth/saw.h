#include "oscillator.h"

#pragma once

class Saw : public Oscillator{
public:
  Saw(double samplerate);
  ~Saw();

  double calculate();

};
