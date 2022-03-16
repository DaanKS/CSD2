#include "allpass.h"

Allpass::Allpass() : m_coeffG(0.0f), m_delayTime(0.0f),m_samplerate(0.0),tempSample(0.0f)  {}

Allpass::Allpass(float coeff_G, float delayTime, double samplerate) :
m_coeffG(coeffG), m_delayTime(delayTime),
m_samplerate(samplerate), tempSample(0.0f)
{
    circ = new CircBuffer(m_samplerate);
}
Allpass::~Allpass() {
    delete circ;
    circ = nullptr;
}

float Allpass::output(float inputSample) {
    circ->writeToBuffer(inputSample + ((-1 * m_coeffG) * tempSample);
    tempSample = circ->readFromBuffer();
    circ->incrementIndeces();
    return (m_coeffG * inputSample) + tempSample;
}
void Allpass::setCoefficientG(float coeff_G){
    this->m_coeffG = coeff_G;
}


//TODO --> Fix Duplicate Code
void Allpass::setDelayTime(float delayTime){
    circ->setDelayTimeSamps(msToSamples(delayTime));
}
void Allpass::setSamplerate(double samplerate){
    this->m_samplerate = samplerate;
}
float Allpass::msToSamples(float delayTime) {
    //cast float samples to uint
    return static_cast<uint>((delayTime * (m_samplerate / 1000.0)));
}
void Allpass::initializeBuffer() {
    //circbuffer is made here, because we don't know the samplerate yet at
    //the time of the constructor - if we use portaudio
    circ = new CircBuffer(m_samplerate);
}