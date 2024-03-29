#include "modallpass.h"
#include "onepole.h"
#include "highpass.h"
#include "allpass.h"
#include "predelay.h"
#include "comb.h"
#include "squarelaw.h"

#pragma once

class Datorro{
public:
    Datorro(float samplerate);
    ~Datorro();

    float output(float inputSample);
    float outputL(float inputSample);
    float outputR(float inputSample);

    void setPreDelay(float preDelay);
    void setBandWidth(float bandwidth);

    void setDryWet(float drywet);


private:
    std::unique_ptr<Mix> mix;
    float m_dryWet;

    double m_samplerate;

    PreDelay* fixed_1;
    PreDelay* fixed_2;
    PreDelay* fixed_3;
    PreDelay* fixed_4;
    PreDelay* predel;

    Onepole* bandWidth;
    Onepole* damping_1;
    Onepole* damping_2;

    Highpass* hiDamping_1;
    Highpass* hiDamping_2;

    Allpass* ap_1;
    Allpass* ap_2;
    Allpass* ap_3;
    Allpass* ap_4;
    Allpass* ap_5;
    Allpass* ap_6;

    ModAllPass* map_1;
    ModAllPass* map_2;
    //ModAllPass* map_3;
    //ModAllPass* map_4;

    Comb* combL_1;
    Comb* combL_2;
    Comb* combL_3;
    Comb* combL_4;
    Comb* combL_5;
    Comb* combL_6;
    Comb* combL_7;

    Comb* combR_1;
    Comb* combR_2;
    Comb* combR_3;
    Comb* combR_4;
    Comb* combR_5;
    Comb* combR_6;
    Comb* combR_7;


    float feedSampleL1 = 0.0f;
    float feedSampleL2 = 0.0f;
    float feedSampleL3 = 0.0f;
    float feedSampleL4 = 0.0f;
    float feedSampleL5 = 0.0f;
    float feedSampleL6 = 0.0f;
    float feedSampleL7 = 0.0f;

    float feedSampleR1 = 0.0f;
    float feedSampleR2 = 0.0f;
    float feedSampleR3 = 0.0f;
    float feedSampleR4 = 0.0f;
    float feedSampleR5 = 0.0f;
    float feedSampleR6 = 0.0f;
    float feedSampleR7 = 0.0f;

    float coefficientG5 = 0.1f;
    float earlyTempSample = 0.0f;
    float tempSample_1 = 0.0f;
    float tempSample_2 = 0.0f;


};