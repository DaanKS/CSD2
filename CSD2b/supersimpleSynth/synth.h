#include <iostream>
#include <cmath>
#include <vector>

#include "midicontrol.h"


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

  void initMidi();
  void startMidiListening();
  void passMessageFromMidiToSynth();


protected:
  int pitch;
  double amplitude;
  double samplerate;

  double oldPitch;

  int something;
  char somethingelse;

  Midicontrol* midi;
};
