/*
  ==============================================================================

    audioeffect.h
    Created: 8 Feb 2022 11:12:33am
    Author:  Dean

  ==============================================================================
*/

#pragma once

class Audioeffect{
public:
    Audioeffect();
    virtual ~Audioeffect();
    
    virtual double outputSample(double inputSample) = 0;
    void setSamplerate(double samplerate);

protected:
    double samplerate;
};
