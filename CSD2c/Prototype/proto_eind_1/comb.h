#include <circbuffer.h>
#include "filter.h"

#pragma once

class Comb : public Filter{
public:
    Comb(float samplerate);
    Comb(float bufferSize, float delayTime, float feedforward, float feedback, float samplerate);
    ~Comb();

    float output(float inputSample) override;

private:
    float m_bufferSize;
    float m_delayTime;
    float m_feedforward;
    float m_feedback;

    float outputSample;

    CircBuffer* circFF;
    CircBuffer* circFB;
};
