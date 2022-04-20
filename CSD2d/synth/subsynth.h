#include <sine.h>
#include <saw.h>
#include <square.h>
#include "onepole.h"
#include "oversampler.h"
#include "synth.h"

#pragma once

class Subsynth : public Synth{
public:
  Subsynth(double samplerate);
  ~Subsynth();

  double output() override;
  double calculate();

  void setCutoff(double feedback);
  void setDetune(double detune);

  void updatePitches() override;



private:

  double m_detune;

  Oscillator* osc_1;
  Oscillator* osc_2;

  Onepole lpf_1;
  Onepole lpf_2;

  Oversampler* over;

};
