//Base class for all filter objects (apart from biquad)
#pragma once
typedef unsigned int uint;

class Filter{
public:
    Filter(double samplerate);
    virtual ~Filter();

    virtual float output(float inputSample) = 0;

protected:
    uint msToSamples(float delayMS);
    float m_samplerate;
};