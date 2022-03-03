#include "sine.h"
#include "square.h"
#include "saw.h"
#include "audioeffect.h"

#pragma once

class Tremolo : public AudioEffect{
public:
  Tremolo();
  ~Tremolo();

  float output(float inputSample) override;

  void assignWave();

  void setRate(double rate);
  void setAmplitude(double amplitude);

private:
  inline void clearOsc(){
    if(osc != nullptr){
    delete osc;
    osc = nullptr;
    }
  }

  double rate;
  double amplitude;
  double modSignal;

  double maxRate = 20.0;
  double minRate = 0.01;

  double maxAmp = 1.00;
  double minAmp = 0.00;

  Oscillator* osc;
};
