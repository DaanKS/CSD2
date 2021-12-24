#include <cmath>

#pragma once

class Oscillator{
public:
  Oscillator(double samplerate);
  virtual ~Oscillator();

  virtual double calculate() = 0;
  double tick();

  void resetPhase();
  void setDelta(double frequency);

protected:
  double samplerate;
  double phase;
  double delta;
  double frequency;


};
