#pragma once

class Synth{
public:
  Synth(double amplitude, double samplerate);
  ~Synth();

  virtual double tick() = 0;

  void setAmplitude(double amplitude);
  double getAmplitude();

  void setPitch(double pitch);
  double getPitch();

  double MTOF(double pitch);

protected:
  double pitch;
  double amplitude;
  double samplerate;
};
