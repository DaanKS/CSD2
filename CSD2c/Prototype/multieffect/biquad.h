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

  void calculateOmega();
  void calculateAlpha();
  void calculateCoefficients();

private:
  inline void calculateBzero(){this->Bzero = ((1.0 - cos(omega)) / 2.0);
  std::cout << Bzero << " Bzero" << std::endl; }
  inline void calculateBone(){this->Bone = (1.0 - cos(omega));
  std::cout << Bone << " Bone" << std::endl; }
  inline void calculateBtwo(){this->Btwo = ((1.0 - cos(omega)) / 2.0);
  std::cout << Btwo << " Btwo" << std::endl; }
  inline void calculateAzero(){this->Azero = 1.0 + alpha;
  std::cout << Azero << " Azero" << std::endl; }
  inline void calculateAone(){this->Aone = -2.0 * cos(omega);
  std::cout << Aone << " Aone" << std::endl; }
  inline void calculateAtwo(){this->Atwo = 1.0 - alpha;
  std::cout << Atwo << " Atwo" << std::endl; }

  CircBuffer* his1;
  CircBuffer* his2;
  CircBuffer* his3;
  CircBuffer* his4;
  CircBuffer* his5;
  CircBuffer* his6;

  float cutoffFreq;
  float qFactor;
  float omega, alpha;
  float outputSample;

  float Bzero, Bone, Btwo;
  float Azero, Aone, Atwo;
};
