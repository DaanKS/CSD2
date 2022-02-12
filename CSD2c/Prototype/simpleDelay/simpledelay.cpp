#include "simpledelay.h"

Delay::Delay(double samplerate){
  CircBuffer circ(samplerate * maxBufferSize, 4000);
}
Delay::~Delay(){}

double Delay::output(double inputSample){
  circ.writeToBuffer(inputSample + (outputSample * feedback))
  outputSample = circ.readFromBuffer();
  return outputSample;
}
