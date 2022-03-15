#include "bandpass.h"

Bandpass::Bandpass() : Biquad() {}
Bandpass::~Bandpass() = default;


void Bandpass::setBandWidth(float bandwidth) {
    this->m_bandwidth = bandwidth;
}

void Bandpass::calculateAlpha() {
    this->alpha = sin(omega) * sinh((log(2)/ 2.0) * m_bandwidth * (omega / sin(omega)));
}