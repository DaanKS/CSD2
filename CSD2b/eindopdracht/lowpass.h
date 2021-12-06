#include "mix.h"
#include "history.h"
//onepole lowpass filter
// Y[n] = aX[n] + bY[n-1]

class Lowpass{
public:
  Lowpass();
  ~Lowpass();

  float tick(inputSample);

  //feedback is correlated with cutoff frequency
  void setFeedback(float feedback);
  float getFeedback();
protected:
  History* history;
  Mix* mix;

  float inputSample;
  float outputSample;
  float feedback;

}
