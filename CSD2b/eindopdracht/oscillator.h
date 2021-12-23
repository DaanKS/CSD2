#pragma once;

class Oscillator{
public:
  Oscillator(double samplerate);
  virtual ~Oscillator();

  virtual double calculate() = 0;
  double tick();

  void resetPhase();
  void setDelta(double frequency);

private:
  double samplerate;
  double phase;
  double delta;
  double frequency;


}
