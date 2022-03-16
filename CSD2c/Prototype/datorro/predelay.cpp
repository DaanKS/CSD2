#include "predelay.h"

PreDelay::PreDelay() {}
PreDelay::PreDelay(double samplerate) {
    circ = new CircBuffer(static_cast<uint>(samplerate));
}
PreDelay::~PreDelay() {
    delete circ;
    circ = nullptr;
}

float PreDelay::output(float inputSample) {
    circ->writeToBuffer(inputSample);
    const float outputSample = circ->readFromBuffer();
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

float PreDelay::msToSamples(float delayTime) {
    //cast float samples to uint
    return static_cast<uint((delayTime * (m_samplerate / 1000.0)));
}