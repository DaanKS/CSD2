#include "allpass.h"

Allpass::Allpass(double samplerate) : Filter(samplerate) ,m_coeffG(0.0f), m_delayTime(0.0f), tempSample(0.0f)  {}

Allpass::Allpass(float coeff_G, float delayTime, double samplerate) : Filter(samplerate),
m_coeffG(coeff_G), m_delayTime(delayTime),
tempSample(0.0f)
{
    circ = new CircBuffer(static_cast<uint>(m_samplerate));
    circ->setDelayTimeSamps((m_delayTime));

}
Allpass::~Allpass() {
    delete circ;
    circ = nullptr;
}

float Allpass::output(float inputSample) {
    circ->writeToBuffer(inputSample + ((-1 * m_coeffG) * tempSample));
    tempSample = circ->readFromBuffer();
    circ->incrementIndeces();
    return (m_coeffG * inputSample) + tempSample;
}
void Allpass::setCoefficientG(float coeff_G){
    this->m_coeffG = coeff_G;
}


//TODO --> Fix Duplicate Code
void Allpass::setDelayTime(float delayTime){
    circ->setDelayTimeSamps(delayTime);
}
void Allpass::setSamplerate(double samplerate){
    this->m_samplerate = samplerate;
}
void Allpass::initializeBuffer() {
    circ = new CircBuffer(m_samplerate);
}
