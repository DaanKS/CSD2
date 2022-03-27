#include "fixeddelay.h"

FixedDelay::FixedDelay() {}
FixedDelay::FixedDelay(double samplerate, float delayTime) {
    this->m_samplerate = samplerate;
    circ = new CircBuffer(static_cast<uint>(samplerate));
    circ->setDelayTimeSamps(delayTime);
}
FixedDelay::~FixedDelay() {
    delete circ;
    circ = nullptr;
}

float FixedDelay::output(float inputSample) {
    circ->writeToBuffer(inputSample);
    outputSample = circ->readFromBuffer();
    circ->incrementIndeces();
    return outputSample;
}

void FixedDelay::setDelayTime(float delayTime) {
    circ->setDelayTimeSamps(msToSamples(delayTime));
}

void FixedDelay::setSamplerate(double samplerate){
    this->m_samplerate = samplerate;
}

void FixedDelay::initializeBuffer() {
    //circbuffer is made here, because we don't know the samplerate yet at
    //the time of the constructor - if we use portaudio
    circ = new CircBuffer(m_samplerate);
}

uint FixedDelay::msToSamples(float delayTime) {
    //cast float samples to uint
    return ((m_samplerate / 1000.0f) * delayTime);
}