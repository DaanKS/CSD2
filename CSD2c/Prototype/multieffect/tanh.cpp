//
// Created by Dean on 21/02/2022.
//

#include "tanh.h"

Tanh::Tanh(double samplerate) : AudioEffect(samplerate){
    mix = std::make_unique<Mix>();
}
Tanh::~Tanh(){}

float Tanh::output(float inputSample) {
    return (tanh(inputSample * drive) * mix->getB(drywet)) + (inputSample * mix->getA(drywet));
}
void Tanh::setDrive(float drive) {
    this->drive = drive;
}
