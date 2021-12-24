#include "synth.h"
#include "saw.h"
#include "square.h"
#include "sine.h"

#pragma once

class Fmsynth : public Synth{
public:
  Fmsynth(double samplerate);
  ~Fmsynth();

  double output() override;
  void calculateCarrierFreq();
  void setPitches() override; //Change name to updatePitchesFromMidi();

  void setRatio(double ratio);
  double getRatio();
  void setModDepth(double modDepth);
  double getModDepth();
  void setModulationIndex(double oscFreq);
  double getModulationIndex();

  void setCarDelta(double frequency);
  void setModDelta(double frequency);



protected:
  Oscillator* car;
  Oscillator* mod;

  double ratio;
  double oscFreq;
  double modDepth;
  double modulationIndex;

  double frequency;




};
