#include "circbuffer.h"
#include "audioeffect.h"
#include "history.h"
#include <cmath>

#pragma once

class Biquad : public AudioEffect{
public:
  Biquad(double samplerate);
  ~Biquad();

  float output(float inputSample) override;

  void setCutoffFreq(float cutoffFreq);
  void setQFactor(float qFactor);

  void calculateOmega(float cutoffFreq);
  void calculateAlpha(float omega);
  void calculateCoefficients();

private:
  inline void calculateBzero(){Bzero = ((1.0 - cos(omega)) / 2.0); }
  inline void calculateBone(){Bone = (1.0 - cos(omega));}
  inline void calculateBtwo(){Btwo = ((1.0 - cos(omega)) / 2.0);}
  inline void calculateAzero(){Azero = 1.0 + alpha;}
  inline void calculateAone(){Aone = -2.0 * cos(omega);}
  inline void calculateAtwo(){Atwo = 1.0 - alpha;}

  History* his1;
  History* his2;
  History* his3;
  History* his4;
  History* his5;
  History* his6;

  float cutoffFreq;
  float qFactor;
  float omega, alpha;
  float outputSample;

  float Bzero, Bone, Btwo;
  float Azero, Aone, Atwo;
};
