#include "bibiquad.h"

Bibiquad::Bibiquad(double samplerate):m_samplerate(samplerate),
m_cutoff(1000), m_qFactor(3.0), m_difference(300){
    Lopass = new Biquad();
    Hipass = new Biquad();
    Lopass->makeLowPass(m_cutoff, m_qFactor, m_samplerate);
    Hipass->makeHighPass(m_cutoff + m_difference, m_qFactor, m_samplerate);
}
Bibiquad::~Bibiquad() = default;

float Bibiquad::outputLP(float inputSample){
    return Lopass->output(inputSample);
}
float Bibiquad::outputHP(float inputSample) {
    return Hipass->output(inputSample);
}


float Bibiquad::setCutoffFrequency(float cutoff) {
    this->m_cutoff = cutoff;
}
float Bibiquad::setQFactor(float qFactor) {
    this->m_qFactor = qFactor;
}
float Bibiquad::setDifference(float difference) {
    this->m_difference = difference;
}
void Bibiquad::makeFilters(){
    Lopass->makeLowPass(m_cutoff, m_qFactor, m_samplerate);
    Hipass->makeHighPass(m_cutoff + m_difference, m_qFactor, m_samplerate);
}