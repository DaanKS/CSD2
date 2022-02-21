//
// Created by Dean on 21/02/2022.
//

#include "tanh.h"

Tanh::Tanh(double samplerate) : AudioEffect(samplerate){

}
Tanh::~Tanh(){}

float Tanh::output(float inputSample) {
    return tanh(inputSample * drive);
}
void Tanh::setDrive(float drive) {
    this->drive = drive;
}
