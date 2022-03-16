#include "onepole.h"

Onepole::Onepole() : xHistory_1(0.0f),m_A(1.0f), m_B(0.0f){}
Onepole::~Onepole() = default;

float Onepole::output(float inputSample) {
    xHistory_1 = (m_A * inputSample) + (m_B * xHistory_1);
    return xHistory_1;
}

void Onepole::setCoefficinets(float A, float B) {
    //The more B means the more cutoff
    //TODO -> Find formula for cutoff frequency in Hz
    this->m_A = A;
    this->m_B = B;
}
