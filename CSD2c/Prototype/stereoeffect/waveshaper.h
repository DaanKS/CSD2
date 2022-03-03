#include <cmath>
#include <iostream>
#include "audioeffect.h"

#pragma once

class Waveshaper : public AudioEffect{
public:
    Waveshaper();
    ~Waveshaper();

    void generateWaveTable();
    float output(float inputSample) override;
    float mapInRange(float input, float xLow, float xHigh, float yLow, float yHigh);
    float linearMap(float input, float low, float high);
    void setKvalue(float kValue); //Steepness of S-Curve

    void setBufferSize(int bufferSize);
    
protected:
    float* buffer;
    int bufferSize;
    float kValue;
};