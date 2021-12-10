#include "synth.h"
#include "sine.h"

class Bisynth : public Synth{
public:
  Bisynth(double amplitude, double samplerate);
  ~Bisynth();

  double tick();

  void setFrequencies(double frequency)

  void setDetune(double amtDetune);
  double getDetune();

  double applyDetune(double amtDetune);

  void resetPhase();

private:
  double amtDetune;

  Sine* sine1;
  Sine* sine2;
}
