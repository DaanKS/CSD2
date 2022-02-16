#include "sine.h"
#include "square.h"
#include "saw.h"
#include <iostream>

class Tremolo{
public:
  Tremolo(double samplerate);
  ~Tremolo();

  double output(double inputSample) override;

  void assignWave(int waveformtype);

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
