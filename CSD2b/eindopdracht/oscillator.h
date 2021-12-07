#pragma once

class Oscillator{
public:
  Oscillator(double samplerate, double frequency, double phase);
  ~Oscillator();

  double tick();
  virtual void calculate() = 0;

protected:
  double samplerate;
  double frequency;
}