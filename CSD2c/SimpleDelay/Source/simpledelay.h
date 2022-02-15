/*
  =============================================================================

    simpledelay.
    Created: 15 Feb 2022 1:10:33p
    Author:  Dea

  =============================================================================
*/
#include "circbuffer.h"

#pragma once

class Delay{
public:
  Delay();
  ~Delay();
    void instantiate();
    void setSampleRate(float samplerate);

  double output(double inputSample);

  void setFeedback(float feedback);
  void setDelayTime(float delayTime);

  uint msToSamps(float ms);

protected:
  CircBuffer* circ;

  float samplerate;
  int maxBufferSize;
  float outputSample = 0;
  float feedback;
  float delayTime;

};
