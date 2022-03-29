#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <memory>
#include <squarelaw.h>

#pragma once

//TODO - Make appropriate methods "noexcept"

class AudioEffect{
public:
  AudioEffect(double samplerate);
  virtual ~AudioEffect();

  virtual float output(float inputSample) = 0;

  void setDrywet(float drywet);
  void setSamplerate(float samplerate);

protected:
  double m_samplerate;
  float drywet;
  //To replace Mix* and allow automatic ptr deletion
  std::unique_ptr<Mix> mix;


};
