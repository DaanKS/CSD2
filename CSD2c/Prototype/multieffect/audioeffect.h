#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <memory>
#include "squarelaw.h"

#pragma once

class AudioEffect{
public:
  AudioEffect(double samplerate);
  virtual ~AudioEffect();

  virtual float output(float inputSample) = 0;

  void setDrywet(float drywet);

protected:
  double samplerate;
  float drywet;
  //To replace Mix* and allow automatic ptr deletion
  std::unique_ptr<Mix> mix;


};
