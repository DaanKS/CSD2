#include "biquad.h"

#pragma once

class Bibiquad{
public:
    Bibiquad(double samplerate);
    ~Bibiquad();

    float outputLP(float inputSample);
    float outputHP(float inputSample);

    void setCutoffFrequency(float cutoff);
    void setQFactor(float qFactor);
    void setDifference(float difference);
    void makeFilters();

private:
    Biquad* Lopass;
    Biquad* Hipass;

    double m_samplerate;
    float m_cutoff;
    float m_qFactor;
    float m_difference;

};