#include "comb.h"

Comb::Comb();
Comb::Comb(float bufferSize, float delayTime, float feedforward, float feedback) :
m_bufferSize(bufferSize), m_delayTime(delayTime), m_feedforward(feedforward), m_feedback(feedback)
{
    circFF = new CircBuffer(m_bufferSize);
    circFF->setDelayTimeSamps(m_delayTime);
    circFB = new CircBuffer(m_bufferSize);
    circFB->setDelayTimeSamps(m_delayTime);
}
Comb::~Comb(){
    delete circFB;
    circFB = nullptr;
    delete circFF;
    circFF = nullptr;
}

float Comb::output(float inputSample) {
    circFF->writeToBuffer(inputSample);
    outputSample = inputSample + (circFF->readFromBuffer() * m_feedforward) + (circFB->readFromBuffer() * m_feedback);
    circFB->writeToBuffer(outputSample);

    circFB->incrementIndeces();
    circFF->incrementIndeces();

    return outputSample;
}