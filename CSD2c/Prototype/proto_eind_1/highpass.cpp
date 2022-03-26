#include "highpass.h"

Highpass::Highpass() : xHistory_1(0.0f), m_A(1.0f){}
Highpass::Highpass(float A) : xHistory_1(0.0f),m_A(A) {}
Highpass::~Highpass() = default;

float Highpass::output(float inputSample) {
    xHistory_1 = (m_A * inputSample) - ((1.0 - m_A) * xHistory_1);
    return xHistory_1;
}

void Highpass::setCoefficients(float A) {
    this-> m_A = A;
}