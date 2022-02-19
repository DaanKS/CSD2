#include "circbuffer.h"
#include "audioeffect.h"
#include <cmath>

#pragma once

class Biquad : public AudioEffect{
public:
  Biquad(double samplerate);
  ~Biquad();

  float output(float inputSample) override;

  void setCutoffFreq(float cutoffFreq);
  void setQFactor(float qFactor);

  float calculatOmega(float cutoffFreq);
  float calculateAlpha(float omega);
  float calculateCoefficients();

private:
  inline void calculateBzero(){Bzero = ((1.0 - cos(omega)) / 2.0); }
  inline void calculateBone(){Bone = (1.0 - cos(omega));}
  inline void calculateBtwo(){Btwo = ((1.0 - cos(omega)) / 2.0);}
  inline void calculateAzero(){Azero = 1.0 + alpha;}
  inline void calculateAone(){Aone = -2.0 * cos(omega);}
  inline void calculateAtwo(){Atwo = 1.0 - alpha;}

  float cutoffFreq;
  float qFactor;
  float omega, alpha;

  float Bzero, Bone, Btwo;
  float Azero, Aone, Atwo;
};
