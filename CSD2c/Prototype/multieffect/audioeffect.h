#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

#pragma once

class AudioEffect{
public:
  AudioEffect(double samplerate);
  virtual ~AudioEffect() = 0;

  virtual float output(float inputSample) = 0;

  float setDrywet(float drywet);

protected:
  double samplerate;

  float drywet;

};
