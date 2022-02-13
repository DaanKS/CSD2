#include <iostream>
#include "circbuffer.h"

class Delay{
public:
  Delay(double samplerate);
  ~Delay();

  double output(double inputSample);

  void setFeedback(float feedback);
  void setDelayTime(float delayTime);

  float msToSamps(float ms);

  

protected:
  int maxBufferSize = 5; //5 times samplerate = 5 seconds of delay
  float outputSample = 0;
  float feedback;
  float delayTime;
  float samplerate;

  CircBuffer circ;
};
