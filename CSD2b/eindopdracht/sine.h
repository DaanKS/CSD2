#include "oscillator.h"

#pragma once

class Sine : public(Oscillator){
public:
  Sine(double samplerate);
  ~Sine();

  double calculate() override;

};
