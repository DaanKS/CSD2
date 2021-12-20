#include <iostream>
#include <cmath>
#include <vector>

#include "midi_io.h"


#pragma once

class Synth{
public:
  Synth(double samplerate);
  ~Synth();

  virtual double tick()=0;
  double MTOF(int pitch);

  void setPitch(int pitch);
  int getPitch();

  void setAmplitude(double amplitude);
  double getAmplitude();

  void initMidi(int something, char somethingelse);
protected:
  int pitch;
  double amplitude;
  double samplerate;

  int something;
  char somethingelse;
};
