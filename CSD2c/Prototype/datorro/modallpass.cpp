#include "modallpass.h"

ModAllPass::ModAllPass() {}
ModAllPass::ModAllPass(float coeff_G, float delayTime, double samplerate, float rate, float depth)
: Allpass(coeff_G, delayTime, samplerate),
m_Rate(rate), m_Depth(depth)
{
    this->m_samplerate = samplerate;
    this->m_coeffG = coeff_G;
    this->m_delayTime = delayTime;

    sin = new Sine(m_samplerate);
    sin->setDelta(m_Rate);
}

ModAllPass::~ModAllPass() {
    delete sin;
    sin = nullptr;
    delete circ;
    circ = nullptr;
}

float ModAllPass::output(float inputSample) {
    circ->writeToBuffer(inputSample + (tempSample * m_coeffG));
    tempSample = circ->readFromBuffer();
    circ->incrementIndeces();
    delayModulation();
    return tempSample + (inputSample * (-1 * m_coeffG));
}

void ModAllPass::delayModulation() {
    circ->setDelayTimeSamps((sin->output() * m_Depth) + m_delayTime);
}

void ModAllPass::setModulationRate(float rate){
    this->m_Rate = rate;
    sin->setDelta(m_Rate);
}
void ModAllPass::setModulationDepth(float depth) {
    this->m_Depth = depth;
}
void ModAllPass::initializeOscillator() {
    sin = new Sine(m_samplerate);
    sin->setDelta(m_Rate);
}