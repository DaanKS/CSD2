#include <iostream>

#pragma once

class Oscillator{
public:
  Oscillator(double samplerate);
  virtual ~Oscillator();

  double tick();
  virtual double calculate() = 0;

  void setFrequency(double frequency);
  double getFrequency();
  void setDelta(double frequency);

  void resetPhase();

protected:
  double samplerate;
  double phase;
  double frequency;
  double delta;
};
