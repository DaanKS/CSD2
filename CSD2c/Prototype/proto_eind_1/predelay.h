#include <circbuffer.h>
#pragma once

//TODO --> Rename to FixedDelay
class PreDelay{
public:
    PreDelay();
    PreDelay(double samplerate, float delayTime);
    ~PreDelay();

    float output(float inputSample);

    void setDelayTime(float delayTime);
    void setSamplerate(double samplerate);
    void initializeBuffer();

private:
    uint msToSamples(float delayTime);

    CircBuffer* circ;
    //float delayTimeSamples;
    double m_samplerate;
    float outputSample;
};