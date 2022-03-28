#include <circbuffer.h>
#include "filter.h"

#pragma once

class Comb : public Filter{
public:
    Comb(double samplerate);
    Comb(float bufferSize, float delayTime, float feedforward, float feedback, double samplerate);
    ~Comb();

    float output(float inputSample) override;
    //TODO add setter for delaytime

private:
    float m_bufferSize;
    float m_delayTime;
    float m_feedforward;
    float m_feedback;

    float outputSample;

    CircBuffer* circFF;
    CircBuffer* circFB;
};
