#include "lowpass.h"

Lowpass::Lowpass(){
  mix = new Mix;
  history = new History;
}
Lowpass::~Lowpass(){}

double Lowpass::tick(double inputSample){
  //outputSample = (inputSample) + (outputSample * feedback);
  outputSample = (inputSample * mix->getA(mix->getX())) + (history->tick(outputSample) * mix->getB(mix->getX()));
  return outputSample;
}

void Lowpass::setFeedback(double feedback){
  this->feedback = feedback;
  mix->setX(feedback);
}
double Lowpass::getFeedback(){
  return feedback;
}
