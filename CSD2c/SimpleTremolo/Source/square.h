/*
  ==============================================================================

    square.h
    Created: 8 Feb 2022 11:13:43am
    Author:  Dean

  ==============================================================================
*/
#include "oscillator.h"

#pragma once

class Square : public Oscillator{
    public:
    
    Square(double samplerate);
    ~Square();
    
    double calculate() override;
};
