#include "synth.h"
#include "sine.h"

class Bisynth : public Synth{
public:
  Bisynth(double amplitude, double samplerate);
  ~Bisynth();

  double tick();

  void setFrequencies();

  void setDetune(double amtDetune);
  double getDetune();

  void resetPhase();

private:
  double amtDetune;

  Sine* sine1;
  Sine* sine2;
};
