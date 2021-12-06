#include "lowpass.h"

Lowpass::Lowpass(){
  mix = new Mix;
  history = new History;
}
Lowpass::~Lowpass(){}

float Lowpass::tick(inputSample){
  outputSample = (inputSample * mix->getA()) + (outputSample * mix->getB());
  return outputSample;
}

void Lowpass::setFeedback(float feedback){
  this->feedback = feedback;
  mix->setX(feedback);
}
float Lowpas::getFeedback(){
  return feedback;
}
