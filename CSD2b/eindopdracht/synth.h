#include <cmath>
#include <vector>
#include "midicontrol.h"

#pragma once

class Synth{
public:
  Synth(double samplerate);
  ~Synth();

  virtual double output()=0;
  double mtof(double pitch);

  void setPitch(double pitch);
  double getPitch();
  virtual void setPitches() = 0; //change name to updatePitchesFromMidi();

  void setAmplitude(double amplitude);
  double getAmplitude();

  void initMidi();
  void startMidiListening();
  void passMessageFromMidiToSynth();
  void updatePitchesFromMidi();

protected:
  double pitch;
  double amplitude, samplerate;
  double newPitch, oldPitch;

  Midicontrol* midi;

};
