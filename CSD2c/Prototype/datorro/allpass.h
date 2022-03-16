#include "circbuffer.h"
#pragma once

class Allpass{
public:
    Allpass();
    Allpass(float coeff_G, float delayTime, double samplerate);
    ~Allpass();

    virtual float output(float inputSample);

    void setCoefficientG(float coeff_G);
    void setDelayTime(float delayTime);

    void setSamplerate(double samplerate);
    void msToSamples(float delayTime);
    void initializeBuffer();

private:
    float m_coeffG;
    float m_delayTime;
    double m_samplerate;

    float tempSample;

    CircBuffer* circ;
};