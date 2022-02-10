#include "tremolo.h"

Tremolo::Tremolo(double samplerate) : samplerate(samplerate),
rate(0.5), amplitude(1.0){
  osc = new Sine(samplerate);

}
Tremolo::~Tremolo(){
  delete osc;
  osc = nullptr;
}
double Tremolo::outputSample(double inputSample){
  modSignal = osc->output();
  modSignal *= amplitude;
  modSignal += 1.0 - amplitude;
  return inputSample * modSignal;
}

void Tremolo::assignWave(WaveformType waveformtype){
  clearOsc();
  switch (waveformtype){
    case WaveformType::SINE:{
      osc = new Sine(samplerate);

    }
    case WaveformType::SQUARE:{
      osc = new Square(samplerate);
    }
    case WaveformType::SAW:{
      osc = new Saw(samplerate);
    }
  }
  setRate(rate);
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
