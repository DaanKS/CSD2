/*
  ==============================================================================

    audioeffect.cpp
    Created: 8 Feb 2022 11:12:33am
    Author:  Dean

  ==============================================================================
*/

#include "audioeffect.h"

Audioeffect::Audioeffect(){}
Audioeffect::~Audioeffect(){}

void Audioeffect::setSamplerate(double samplerate){
    this->samplerate = samplerate;
}
