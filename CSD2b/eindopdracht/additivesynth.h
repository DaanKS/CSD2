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

  void setNumOsc(int numOsc);
  int getNumOsc();

protected:
  std::vector<Sine> sines;
};
