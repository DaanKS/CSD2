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
  void updatePitches() override; 
  void setRatio(double ratio);
  double getRatio();
  void setModDepth(double modDepth);
  double getModDepth();
  void setModulationIndex(double oscFreq);
  double getModulationIndex();

  void setCarDelta(double frequency);
  void setModDelta(double frequency);

  void changeWaveCar();
  void changeWaveMod();

protected:
  Oscillator* car;
  Oscillator* mod;

  int carPos;
  int modPos;

  double ratio;
  double oscFreq;
  double modDepth;
  double modulationIndex;

  double frequency;




};
