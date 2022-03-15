#include "bandpass.h"

Bandpass::Bandpass() : Biquad() {}
Bandpass::~Bandpass() = default;


void Bandpass::setBandWidth(float bandwidth) {
    this->m_bandwidth = bandwidth;
}

void Bandpass::calculateAlpha() {

}