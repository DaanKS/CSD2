/*
  ==============================================================================

    sine.cpp
    Created: 8 Feb 2022 11:13:36am
    Author:  Dean

  ==============================================================================
*/

#include "sine.h"

Sine::Sine(double samplerate): Oscillator(samplerate){
}
Sine::~Sine(){}

double Sine::calculate(){
    return (0.5 + (0.5 * sin(phase * M_PI * 2.0f)));
}
