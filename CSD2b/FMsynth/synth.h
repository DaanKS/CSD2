#pragma once

class Synth{
public:
  Synth(double samplerate);
  ~Synth();

  virtual double tick() = 0;

  void setAmplitude(double amplitude);
  double getAmplitude();

  void setPitch(int pitch);
  int getPitch();

  double MTOF(int pitch);

protected:
  int pitch;
  double amplitude;
  double samplerate;
};
