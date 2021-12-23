#include "oscillator.h"

#pragma once

class Square : public Oscillator{
public:
  Square(double samplerate);
  ~Square();

  double calculate() override;
}
