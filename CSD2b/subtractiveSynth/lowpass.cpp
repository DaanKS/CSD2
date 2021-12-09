#include "lowpass.h"

Lowpass::Lowpass(){
  mix = new Mix;
  history = new History;
}
Lowpass::~Lowpass(){}

double Lowpass::tick(inputSample){
  outputSample = (inputSample * mix->getA()) + (outputSample * mix->getB());
  return outputSample;
}

void Lowpass::setFeedback(double feedback){
  this->feedback = feedback;
  mix->setX(feedback);
}
double Lowpas::getFeedback(){
  return feedback;
}
