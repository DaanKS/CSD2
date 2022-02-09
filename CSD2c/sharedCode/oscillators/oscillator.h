#pragma once

class Oscillator{
public:
    Oscillator(double samplerate);
    virtual ~Oscillator();

    double output();
    virtual double calculate() = 0;

    void setDelta(double frequency);
    double getFrequency();
    void resetPhase();

protected:
    double samplerate;
    double phase;
    double frequency;
    double delta;
};
