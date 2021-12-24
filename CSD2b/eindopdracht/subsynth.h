#include "sine.h"
#include "saw.h"
#include "square.h"
#include "onepole.h"
#include "synth.h"

#pragma once

class Subsynth : public Synth{
public:
  Subsynth(double samplerate);
  ~Subsynth();

  double output() override;

  void setFeedback(double feedback);
  double getFeedback();
  void setDetune(double detune);

  void setPitches() override;
  void updatePitchesFromMidi();


private:
  double feedback;
  double detune;

  Oscillator* osc_1;
  Oscillator* osc_2;

  Lowpass lpf_1;
  Lowpass lpf_2;


};
