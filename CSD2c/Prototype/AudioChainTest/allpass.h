#include <circbuffer.h>
#include "filter.h"
#pragma once

class Allpass : public Filter{
public:
    Allpass(double samplerate);
    Allpass(float coeff_G, float delayTime, double samplerate);
    virtual ~Allpass();

   float output(float inputSample) override;

    void setCoefficientG(float coeff_G);
    void setDelayTime(float delayTime);

    void setSamplerate(double samplerate);
    void initializeBuffer();

protected:
    float m_coeffG;
    float tempSample;
    float m_delayTime;

    CircBuffer* circ;
};