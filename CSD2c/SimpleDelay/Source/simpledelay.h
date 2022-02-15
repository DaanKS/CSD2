/*
  =============================================================================

    simpledelay.
    Created: 15 Feb 2022 1:10:33p
    Author:  Dea

  =============================================================================
*/
#include "circbuffer.h"
#include "mix.h"

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
    void setDryWet(float dryWet);

  uint msToSamps(float ms);

protected:
  CircBuffer* circ;
    Mix mix_1;
    int maxBufferSize;
    
    float samplerate;
  
  float outputSample = 0;
    
    float dryWet;
  float feedback;
  float delayTime;

};
