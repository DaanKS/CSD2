/*
  ==============================================================================

    square.cpp
    Created: 8 Feb 2022 11:13:43am
    Author:  Dean

  ==============================================================================
*/

#include "square.h"

Square::Square(double samplerate) : Oscillator(samplerate){}
Square::~Square(){}

double Square::calculate(){
    return phase >= 0.5 ? 1.0f : 0.0f;
}


