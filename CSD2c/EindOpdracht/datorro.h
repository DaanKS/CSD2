/*
 * Created by Dean, refactored on 27/03/2022
 *
 *Original Datorro filter design and coefficients found in
 *Pirkle 2019, "Designing Audio Effect Plugins in C++" p. 477 - 478
 *
 *Parallel combfilfters on output inspired by:
 *Yafr2 - Randy Jones rej@2uptech.com, based on
 *Griesinger plate reverb
*/
#include "filter.h"
#include "modallpass.h"
#include "onepole.h"
#include "allpass.h"
#include "fixeddelay.h"
#include "comb.h"
#include <squarelaw.h>
#include <vector>

#pragma once

#define NUMFILTERS 27

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
    Filter* filters[NUMFILTERS];
    float m_dryWet;

    double m_samplerate;

    FixedDelay* fixed_1;
    FixedDelay* fixed_2;
    FixedDelay* fixed_3;
    FixedDelay* fixed_4;
    FixedDelay* predel;

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