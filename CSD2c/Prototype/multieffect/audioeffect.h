#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

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

};
