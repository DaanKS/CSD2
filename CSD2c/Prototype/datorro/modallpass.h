#include "circbuffer.h"
#include "sine.h"
#include "allpass.h"

#pragma once

class ModAllPass : public Allpass{
public:
    ModAllPass();
    ModAllPass(float coeff_G, float delayTime, double samplerate, float rate, float depth);
    ~ModAllPass();

    float output(float inputSample) override;

    void delayModulation();

    void setModulationRate(float rate);
    void setModulationDepth(float depth);
    void initializeOscillator();

private:
    float m_Rate;
    float m_Depth;
    foat tempSample = 0.0f;

    Sine* sin;

};