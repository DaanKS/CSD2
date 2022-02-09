/*
  ==============================================================================

    tremolo.cpp
    Created: 8 Feb 2022 11:13:29am
    Author:  Dean

  ==============================================================================
*/

#include "tremolo.h"

Tremolo::Tremolo()  : Audioeffect(){}
Tremolo::~Tremolo(){
    delete osc;
    osc = nullptr;
}

double Tremolo::outputSample(double inputSample){
    modSignal = osc->output();
    modSignal *= amplitude;
    modSignal += 1.0 - amplitude;
    return inputSample * modSignal;
}
void Tremolo::assignWave(){
    osc = new Sine(samplerate);
}

void Tremolo::setRate(double rate){
    this->rate = rate;
    osc->setDelta(rate);
}
void Tremolo::setAmplitude(double amplitude){
    this->amplitude = amplitude;
}
