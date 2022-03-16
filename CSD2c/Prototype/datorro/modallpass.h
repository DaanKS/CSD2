#include "circbuffer.h"
#include "sine.h"
#include "allpass.h"

#pragma once

class ModAllPass : public Allpass{
public:
    ModAllPass();
    ModAllPass(float coeff_G, float delayTime, double samplerate, float rate, float depth);
    ~ModAllPass();

    float output(double inputSample) override;

    void setModulationRate(float rate);
    void setModulationDepth(float depth);
    void initializeOscillator();

private:
    float m_Depth;
    float m_Rate;

    Sine* sin;

};