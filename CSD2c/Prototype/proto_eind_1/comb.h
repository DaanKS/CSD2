#include "circbuffer.h"

#pragma once

class Comb{
public:
    Comb();
    Comb(float bufferSize, float delayTime, float feedforward, float feedback);
    ~Comb();

    float output(float inputSample);

    float msToSamples(float delayTime);

private:
    float m_bufferSize;
    float m_delayTime;
    float m_feedforward;
    float m_feedback;

    float outputSample;

    CircBuffer* circFF;
    CircBuffer* circFB;
};
