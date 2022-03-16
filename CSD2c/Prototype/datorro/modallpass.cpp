#include "modallpass.h"

ModAllPass::ModAllPass() {}
ModAllPass::ModAllPass(float coeff_G, float delayTime, double samplerate, float rate, float depth)
: Allpass(coeff_G, delayTime, samplerate),
m_Rate(rate), m_Depth(depth)
{}

ModAllPass::~ModAllPass() {
    delete sin;
    sin = nullptr;
    delete circ;
    circ = nullptr;
}

float ModAllPass::output(double inputSample) {

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