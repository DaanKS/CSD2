#include <iostream>
#include "circbuffer.h"

class Delay{
public:
  Delay(double samplerate);
  ~Delay();

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
