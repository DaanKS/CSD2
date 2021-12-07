#include "oscillator.h"
#include <cmath>

class Sine : public Oscillator{
public:
  Sine(double samplerate, double frequency, double phase);
  ~Sine();

  void calculate();

};
