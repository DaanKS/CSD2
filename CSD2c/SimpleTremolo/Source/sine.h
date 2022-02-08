/*
  ==============================================================================

    sine.h
    Created: 8 Feb 2022 11:13:36am
    Author:  Dean

  ==============================================================================
*/
#include "oscillator.h"
#include <cmath>

#pragma once

class Sine : public Oscillator{
public:
    Sine(double samplerate);
    ~Sine();
    
    double calculate() override;
};
