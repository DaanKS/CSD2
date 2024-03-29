#include "predelay.h"

PreDelay::PreDelay() {}
PreDelay::PreDelay(double samplerate, float delayTime) {
    this->m_samplerate = samplerate;
    circ = new CircBuffer(static_cast<uint>(samplerate));
    circ->setDelayTimeSamps(delayTime);
}
PreDelay::~PreDelay() {
    delete circ;
    circ = nullptr;
}

float PreDelay::output(float inputSample) {
    circ->writeToBuffer(inputSample);
    outputSample = circ->readFromBuffer();
    circ->incrementIndeces();
    return outputSample;
}

void PreDelay::setDelayTime(float delayTime) {
    circ->setDelayTimeSamps(msToSamples(delayTime));
}

void PreDelay::setSamplerate(double samplerate){
    this->m_samplerate = samplerate;
}

void PreDelay::initializeBuffer() {
    //circbuffer is made here, because we don't know the samplerate yet at
    //the time of the constructor - if we use portaudio
    circ = new CircBuffer(m_samplerate);
}

uint PreDelay::msToSamples(float delayTime) {
    //cast float samples to uint
    return ((m_samplerate / 1000.0f) * delayTime);
}