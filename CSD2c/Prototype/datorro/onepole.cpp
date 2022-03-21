#include "onepole.h"
#include <iostream>

Onepole::Onepole() : xHistory_1(0.0f),m_A(1.0f){}
Onepole::Onepole(float A) : xHistory_1(0.0f){
    this->m_A = A;
    std::cout << "I am a onepole: " <<std::endl;
}
Onepole::~Onepole() = default;

float Onepole::output(float inputSample) {
    xHistory_1 = (m_A * inputSample) + ((1 - m_A) * xHistory_1);
    return xHistory_1;
}

void Onepole::setCoefficinets(float A) {
    //The less A means the more cutoff
    //TODO -> Find formula for cutoff frequency in Hz
    this->m_A = A;
}
