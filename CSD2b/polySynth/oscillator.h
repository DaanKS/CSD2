#pragma once
#include <iostream>

class Oscillator{
public:
  Oscillator(double samplerate);
  virtual ~Oscillator();

  void tick();
  virtual double calculate() = 0;
  double getSample();

  void setFrequency(double frequency);
  double getFrequency();

  void resetPhase();
  void setDelta(double frequency, double samplerate);

protected:
  double samplerate;
  double phase;
  double frequency;
  double delta;

  double sample;
};
