/*
  ==============================================================================

    simpledelay.cpp
    Created: 15 Feb 2022 1:10:33pm
    Author:  Dean

  ==============================================================================
*/

#include "simpledelay.h"

Delay::Delay() :  maxBufferSize(5)
{}
Delay::~Delay(){
  delete circ;
  circ = nullptr;
}
void Delay::instantiate(){
    circ = new CircBuffer(samplerate * maxBufferSize);
    circ->setDelayTimeSamps(static_cast<uint>(samplerate / 2));
}
double Delay::output(double inputSample){
  circ->writeToBuffer(inputSample + (outputSample * feedback));
  outputSample = circ->readFromBuffer();
  circ->incrementIndeces();

  return inputSample + outputSample;
}
void Delay::setSampleRate(float samplerate){
    this->samplerate = samplerate;
}
void Delay::setFeedback(float feedback){
  if(feedback >= 0.0f && feedback <= 0.9f){
    this->feedback = feedback;
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
