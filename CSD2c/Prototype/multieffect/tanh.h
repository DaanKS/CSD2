//
// Created by Dean on 21/02/2022.
//
#include "audioeffect.h"


#pragma once

class Tanh : public AudioEffect{
public:
    Tanh(double samplerate);
    ~Tanh();

    float output(float inputSample) override;
    void setDrive(float drive);

private:
    float drive;

};