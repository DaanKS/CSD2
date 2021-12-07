#pragma once

class Oscillator{
public:
  Oscillator(double samplerate, double phase);
  ~Oscillator();

  double tick();
  virtual double calculate() = 0;

  void setAmplitude(double amplitude);
  double getAmplitude();

  void setFrequency(double frequency);
  double getFrequency();


protected:
  double samplerate;
  double frequency;
  double phase;
  double amplitude;
};
