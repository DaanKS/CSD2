#include "audioeffect.h"

class Bypass : public AudioEffect{
public:
  Bypass(double samplerate);
  ~Bypass();

  float output(float inputSample) override;

};
