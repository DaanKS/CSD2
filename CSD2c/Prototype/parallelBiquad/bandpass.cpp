#include "bandpass.h"

Bandpass::Bandpass() : Biquad() {}
Bandpass::~Bandpass() = default;


void Bandpass::setBandWidth(float bandwidth) {
    this->m_bandwidth = bandwidth;
}

void Bandpass::calculateAlpha() {
    this->alpha = sin(omega) * sinh((log(2)/ 2.0) * m_bandwidth * (omega / sin(omega)));
}

void Bandpass::calculateBzero() {
     this->Bzero = (sin(omega) / 2);
}
void Bandpass::calculateBone() {
    this->Bone = 0;
}
void Bandpass::calculateBtwo() {
    this->Btwo = -1 * (sin(omega) / 2);
}
void Bandpass::calculateAzero() {
    this->Azero = 1 + alpha;
}
void Bandpass::calculateAone() {
    this->Aone = -2 * cos(omega);
}
void Bandpass::calculateAtwo() {
    this->Atwo = 1 - alpha;
}
