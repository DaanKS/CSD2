#include "biquad.h"

Biquad::Biquad(double samplerate): AudioEffect(samplerate){
  his1 = new CircBuffer(3);
  his1->setDelayTimeSamps(1);
  his2 = new CircBuffer(3);
  his2->setDelayTimeSamps(1);
  his3 = new CircBuffer(3);
  his3->setDelayTimeSamps(1);
  his4 = new CircBuffer(3);
  his4->setDelayTimeSamps(1);
  his5 = new CircBuffer(3);
  his5->setDelayTimeSamps(1);
  his6 = new CircBuffer(3);
  his6->setDelayTimeSamps(1);
}

Biquad::~Biquad(){
  delete his1;
  his1 = nullptr;
  delete his2;
  his2 = nullptr;
  delete his3;
  his3 = nullptr;
  delete his4;
  his4 = nullptr;
  delete his5;
  his5 = nullptr;
  delete his6;
  his6 = nullptr;
}


float Biquad::output(float inputSample){
/*
  outputSample =  ((1.0 / Azero) * ((Bzero * inputSample) +
  (Bone * his1->tick(inputSample)) +
  (Btwo * his2->tick(his3->tick(inputSample))) -
  (Aone * his4->tick(outputSample)) -
  (Atwo * his5->tick(his6->tick(outputSample))))); */
/*
  outputSample = (Bzero * inputSample) + (Bone * his1->tick(inputSample)) +
  Btwo * his2->tick(his3->tick(inputSample)) -
  Aone * his4->tick(outputSample)-
  Atwo * his5->tick(his6->tick(outputSample)); */

  outputSample = ((Bzero / Azero) * inputSample) +
  ((Bone / Azero) * his1->tick(inputSample)) +
  ((Btwo / Azero) * his2->tick(his3->tick(inputSample))) -
  ((Aone / Azero) * his4->tick(outputSample)) -
  ((Atwo / Azero) * his5->tick(his6->tick(outputSample)));
  std::cout << outputSample << std::endl;
  his1->incrementIndeces();
  his2->incrementIndeces();
  his3->incrementIndeces();
  his4->incrementIndeces();
  his5->incrementIndeces();
  his6->incrementIndeces();

  return 0;
}

void Biquad::setCutoffFreq(float cutoffFreq){
  this->cutoffFreq = cutoffFreq;
  std::cout << cutoffFreq << " CutOff" << std::endl;
}
void Biquad::setQFactor(float qFactor){
  this->qFactor = qFactor;
  std::cout << qFactor << " qFactor" << std::endl;
}

void Biquad::calculateOmega(){
  this->omega = 2 * M_PI * (cutoffFreq / samplerate);
  std::cout << omega << " Omega" << std::endl;
  std::cout << samplerate << " Calculate Omega" << std::endl;
}
void Biquad::calculateAlpha(){
  this->alpha = (sin(omega) / (2 * qFactor));
  std::cout << alpha << " alpha" <<std::endl;
}

void Biquad::calculateCoefficients(){
  calculateBzero();
  calculateBone();
  calculateBtwo();
  calculateAzero();
  calculateAone();
  calculateAtwo();
}
