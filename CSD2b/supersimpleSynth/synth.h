#include <iostream>

#pragma once

class Synth{
public:
  Synth(double samplerate);
  ~Synth();

  virtual double tick();
  double MTOF(int pitch);

  void setPitch(int pitch);
  int getPitch();

  void setAmplitude(double amplitude);
  double getAmplitude();

protected:
  int pitch;
  double amplitude;
};
