#include "oscillator.h"
#include <cmath>

#pragma once

class Sine : public Oscillator {
public:
  Sine(double samplerate, double phase);
  ~Sine();

  double calculate();

}
