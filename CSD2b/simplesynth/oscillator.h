#pragma once

class Oscillator{
public:
  Oscillator(double samplerate);
  ~Oscillator();

  double tick();
  virtual double calculate() = 0;

  void setFrequency(double frequency);
  double getFrequency();

  void resetPhase();

protected:
  double samplerate;
  double phase;
  double frequency;

};
