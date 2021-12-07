#include "lowpass.h"
#include "sine.h"
#include <vector>

#pragma once

class Additive{
public:
  Additive();
  ~Additive();

  double tick();

  void setPitch(double pitch);
  double getPitch();

//For Singular Oscillator
  void setPitchRatio(double pitchRatio);
  double getPitchRatio();

//For all Oscillators
  void setPitchRatios();

protected:
  std::vector<Sine> sines;

  std::vector<double> pitchRatios;
  double pitchRatio;

};
