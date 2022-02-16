#include <iostream>
#include "circbuffer.h"
#include "audioeffect.h"

class Delay : public AudioEffect{
public:
  Delay(double samplerate);
  ~Delay();

  double output(double inputSample);

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
