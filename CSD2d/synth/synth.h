#include <cmath>
#include <vector>
#include "midicontrol.h"

#pragma once

class Synth{
public:
  Synth(double samplerate);
  virtual ~Synth();

  virtual double output()=0;
  double mtof(double pitch);

  void setPitch(double pitch);
  double getPitch();
  virtual void updatePitches() = 0;

  void setAmplitude(double amplitude);
  double getAmplitude();

  void initMidi();
  void startMidiListening();
  void stopMidiListening();
  void passMessageFromMidiToSynth();
  void updatePitchesFromMidi();

protected:
  double pitch;
  double amplitude, samplerate;
  double newPitch, oldPitch;

  bool updatingPitches;

  Midicontrol* midi;

};
