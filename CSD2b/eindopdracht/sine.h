#include "oscillator.h"
#include <cmath>

class Sine : public Oscillator{
public:
  Sine(double samplerate, double phase);
  ~Sine();

  double calculate();

};
