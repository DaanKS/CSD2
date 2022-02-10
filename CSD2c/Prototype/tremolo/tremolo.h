#include "sine.h"
#include "square.h"
#include "saw.h"

class Tremolo{
public:
  enum WaveformType {
    SINE = 0, //ensure enum starts at 0
    SAW,
    SQUARE,
    SIZE // 3
  };
  Tremolo(double samplerate);
  ~Tremolo();

  double outputSample(double inputSample);

  void assignWave(WaveformType waveformtype);

  void setRate(double rate);
  void setAmplitude(double amplitude);

private:
  inline void clearOsc(){
    if(osc != nullptr){
    delete osc;
    osc = nullptr;
    }
  }

  double rate;
  double amplitude;
  double modSignal;

  Oscillator* osc;
};
