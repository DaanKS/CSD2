#include <iostream>
#include "circbuffer.h"
#include "audioeffect.h"


#pragma once

class Delay : public AudioEffect{
public:
  Delay(double samplerate);
  ~Delay();

  float output(float inputSample) override;

  void setFeedback(float feedback);
  void setDelayTime(float delayTime);

  uint msToSamps(float ms);

protected:
  CircBuffer* circ;

  int maxBufferMult;
  float outputSample = 0;
  float feedback;
  float delayTime;

};
