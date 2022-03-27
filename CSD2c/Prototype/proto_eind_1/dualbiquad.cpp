#include "dualbiquad.h"

DualBiquad::DualBiquad(double samplerate): AudioEffect(samplerate), m_samplerate(samplerate),
m_cutoff(1000), m_qFactor(3.0), m_difference(300){
    Lopass = new Biquad(m_samplerate);
    Hipass = new Biquad(m_samplerate);
    Lopass->setCoefficients(Lopass->makeLowPass(m_cutoff, m_qFactor, m_samplerate));
    Hipass->setCoefficients(Hipass->makeHighPass(m_cutoff + m_difference, m_qFactor, m_samplerate));
}
DualBiquad::~DualBiquad() = default;

float DualBiquad::output(float inputSample) {
    return 0;
}

float DualBiquad::outputLP(float inputSample){
    return Lopass->output(inputSample);
}
float DualBiquad::outputHP(float inputSample) {
    return Hipass->output(inputSample);
}


void DualBiquad::setCutoffFrequency(float cutoff) {
    this->m_cutoff = cutoff;
}
void DualBiquad::setQFactor(float qFactor) {
    this->m_qFactor = qFactor;
}
void DualBiquad::setDifference(float difference) {
    this->m_difference = difference;
}
void DualBiquad::makeFilters(){
    Lopass->makeLowPass(m_cutoff, m_qFactor, m_samplerate);
    Hipass->makeHighPass(m_cutoff + m_difference, m_qFactor, m_samplerate);
}