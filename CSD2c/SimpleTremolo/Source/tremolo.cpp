/*
  ==============================================================================

    tremolo.cpp
    Created: 8 Feb 2022 11:13:29am
    Author:  Dean

  ==============================================================================
*/

#include "tremolo.h"

Tremolo::Tremolo(){}
Tremolo::~Tremolo(){}

double Tremolo::outputSample(double inputSample){
    modSignal = osc->output();
    modSignal *= amplitude;
    modSignal += 1.0 - amplitude;
    return inputSample * modSignal;
}
void Tremolo::assignWave(){
    if( osc != nullptr){
        delete osc;
        osc = nullptr;
    }
    osc = new Sine(samplerate);
}

void Tremolo::setRate(double rate){
    this->rate = rate;
}
void Tremolo::setAmplitude(double amplitude){
    this->amplitude = amplitude;
}
