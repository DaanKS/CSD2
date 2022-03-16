#include "circbuffer.h"
#include "sine.h"

#pragma once

class ModAllPass{
public:
    ModAllPass();
    ModAllPass(double samplerate, float offset, float depth);
    ~ModAllPass();

    float output(double inputSample);

    
};