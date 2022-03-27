#include <circbuffer.h>
#include "filter.h"
#pragma once

class Allpass : public Filter{
public:
    Allpass(double samplerate);
    Allpass(float coeff_G, float delayTime, double samplerate);
    virtual ~Allpass();

    virtual float output(float inputSample);

    void setCoefficientG(float coeff_G);
    void setDelayTime(float delayTime);

    void setSamplerate(double samplerate);
    void initializeBuffer();

protected:
    float m_coeffG;
    float m_delayTime;
    double m_samplerate;

    float tempSample;

    CircBuffer* circ;
};