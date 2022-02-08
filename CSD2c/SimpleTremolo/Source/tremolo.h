/*
  ==============================================================================

    tremolo.h
    Created: 8 Feb 2022 11:13:29am
    Author:  Dean

  ==============================================================================
*/
#include "audioeffect.h"
#include "sine.h"
#include "square.h"

#pragma once

class Tremolo : public Audioeffect{
public:
    Tremolo();
    ~Tremolo();
    

    double outputSample(double inputSample) override;
    
    void assignWave();
    
    void setRate(double rate);
    void setAmplitude(double amplitude);
    
private:
    double rate;
    double amplitude;
    double modSignal;

    Oscillator* osc;
    
};

