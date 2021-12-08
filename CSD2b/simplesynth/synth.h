#pragma once

class Synth{
public:
  Synth(double amplitude);
  ~Synth();

  virtual double tick() = 0;

  void setAmplitude(double amplitude);
  double getAmplitude();

protected:
  double amplitude;
}
