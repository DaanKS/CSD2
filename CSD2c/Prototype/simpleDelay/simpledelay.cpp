#include "simpledelay.h"

Delay::Delay(double samplerate) : samplerate(samplerate){
  CircBuffer circ(samplerate * maxBufferSize);
  circ.setDelayTimeSamps(samplerate);
}
Delay::~Delay(){}

double Delay::output(double inputSample){
  circ.writeToBuffer(inputSample + (outputSample * feedback));
  outputSample = circ.readFromBuffer();
  return outputSample;
}

void Delay::setFeedback(float feedback){
  if(feedback >= 0.0f && feedback <= 1.0f){
    this->feedback = feedback;
  }else{
    std::cout << "OOPS feedback too high" << std::endl;
  }
}
void Delay::setDelayTime(float delayTime){
//TODO -- add input validation
  circ.setDelayTimeSamps(msToSamps(delayTime));
}

float Delay::msToSamps(float ms){
  //ms = (samplerate / 1000.0) / timeInSamples
  return ms * (samplerate / 1000.0);
}
