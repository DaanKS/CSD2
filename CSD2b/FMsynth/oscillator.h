#pragma once
#include <iostream>

class Oscillator{
public:
  Oscillator(double samplerate);
  virtual ~Oscillator();

  double tick();
  virtual double calculate() = 0;

  void setFrequency(double frequency);
  double getFrequency();

  void resetPhase();
  void setDelta(double frequency, double samplerate);

protected:
  double samplerate;
  double phase;
  double frequency;
  double delta;

};
