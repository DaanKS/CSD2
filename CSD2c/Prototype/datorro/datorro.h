#include "modallpass.h"
#include "onepole.h"
#include "allpass.h"
#include "predelay.h"

#pragma once

class Datorro{
public:
    Datorro(float samplerate);
    ~Datorro();

    float output(float inputSample);

    void setPreDelay(float preDelay);
    void setBandWidth(float bandwidth);

private:
    double m_samplerate;

    PreDelay* fixed_1, fixed_2, fixed_3, fixed_4, predel;
    Onepole* bandWidth, damping_1, damping_2;
    Allpass* ap_1, ap_2, ap_3, ap_4, ap_5, ap_6;
    ModAllPass* map_1, map_2;
};