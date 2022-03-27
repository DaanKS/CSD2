#include "comb.h"

Comb::Comb(float samplerate) : Filter(samplerate){}
Comb::Comb(float bufferSize, float delayTime, float feedforward, float feedback, float samplerate) : Filter(samplerate),
m_bufferSize(bufferSize), m_delayTime(delayTime), m_feedforward(feedforward), m_feedback(feedback)
{
    circFF = new CircBuffer(m_bufferSize);
    circFF->setDelayTimeSamps(msToSamples(m_delayTime));
    circFB = new CircBuffer(m_bufferSize);
    circFB->setDelayTimeSamps(msToSamples(m_delayTime));
}
Comb::~Comb(){
    delete circFB;
    circFB = nullptr;
    delete circFF;
    circFF = nullptr;
}

float Comb::output(float inputSample) {
    //Combfilter design taken from MaxMSP reference. MSP > Objects > Comb~
    //Y[n] = X[n] + AX[n - z] + BY[n - z]
    circFF->writeToBuffer(inputSample);
    outputSample = inputSample + (circFF->readFromBuffer() * m_feedforward) + (circFB->readFromBuffer() * m_feedback);
    circFB->writeToBuffer(outputSample);

    circFB->incrementIndeces();
    circFF->incrementIndeces();

    return outputSample;
}
