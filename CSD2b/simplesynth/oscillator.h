#pragma once

class Oscillator{
public:
  Oscillator(double samplerate, double phase);
  ~Oscillator();

  double tick();
  virtual double calculate() = 0;

  void setFrequency(double frequency);
  double getFrequency();

protected:
  double samplerate;
  double phase;
  double frequency;
}
