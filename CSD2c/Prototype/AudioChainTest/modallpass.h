#include <circbuffer.h>
#include <sine.h>
#include "filter.h"

#pragma once

class ModAllPass : public Filter{
public:
    ModAllPass(double samplerate);
    ModAllPass(float coeff_G, float delayTime, double samplerate, float rate, float depth);
    ~ModAllPass();

    float output(float inputSample) override;

    void delayModulation();

    void setModulationRate(float rate);
    void setModulationDepth(float depth);


private:
    void initializeOscillator();

    float m_coeffG;
    float m_Rate;
    float m_Depth;
    float m_delayTime;
    float tempSample = 0.0f;

    CircBuffer* circ;
    Sine* sin;

};