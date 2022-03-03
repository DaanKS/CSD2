#include "tremolo.h"

Tremolo::Tremolo() : AudioEffect(),
 rate(0.5), amplitude(1.0){
}

Tremolo::~Tremolo(){
  delete osc;
  osc = nullptr;
}

float Tremolo::output(float inputSample){
  modSignal = osc->output();
  modSignal *= amplitude;
  modSignal += 1.0 - amplitude;
  return inputSample * modSignal;
}

void Tremolo::assignWave(){
    osc = new Sine(samplerate);
}

void Tremolo::setRate(double rate){
  if(rate >= minRate && rate <= maxRate){
    this->rate = rate;
    osc->setDelta(rate);
  }else{
    std::cout << "rate exceeds acceptable range (0.01 - 20.0)";
  }
}
void Tremolo::setAmplitude(double amplitude){
  if(amplitude >= minAmp && amplitude <= maxAmp){
    this->amplitude = amplitude;
  }else{
    std::cout << "amplitude exceeds acceptable range (0.00 - 1.00)";
  }
}
