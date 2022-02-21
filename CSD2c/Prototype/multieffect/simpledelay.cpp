#include "simpledelay.h"

Delay::Delay(double samplerate) : AudioEffect(samplerate), maxBufferMult(2)
{
  circ = new CircBuffer(samplerate * maxBufferMult);
  circ->setDelayTimeSamps(static_cast<uint>(samplerate / 2));
  mix = new Mix;
}
Delay::~Delay(){
  delete circ;
  circ = nullptr;
}

float Delay::output(float inputSample){
  circ->writeToBuffer(inputSample + (outputSample * feedback));
  outputSample = circ->readFromBuffer();
  circ->incrementIndeces();

  return (inputSample * mix->getA(drywet)) + (outputSample * mix->getB(drywet));
}

void Delay::setFeedback(float feedback){
  if(feedback >= 0.0f && feedback <= 0.9f){
    this->feedback = feedback;
  }else{
    std::cout << "OOPS feedback too high" << std::endl;
  }
}
void Delay::setDelayTime(float delayTime){
//TODO -- add input validation
  circ->setDelayTimeSamps(msToSamps(delayTime));
}

uint Delay::msToSamps(float ms){
  //ms = (samplerate / 1000.0) / timeInSamples
  // using + 0.5 and then casting to uint for rounding
  return uint((ms * (samplerate / 1000.0)) + 0.5);
}
