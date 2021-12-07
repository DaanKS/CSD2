#include "mix.h"
#include "history.h"
//onepole lowpass filter
// Y[n] = aX[n] + bY[n-1]

class Lowpass{
public:
  Lowpass();
  ~Lowpass();

  double tick(inputSample);

  //feedback is correlated with cutoff frequency
  void setFeedback(double feedback);
  double getFeedback();
protected:
  History* history;
  Mix* mix;

  double inputSample;
  double outputSample;
  double feedback;

}
