#include <sine.h>
#include <saw.h>
#include <square.h>
#include <cmath>
#include "onepole.h"
#include "oversampler.h"

#pragma once

class Subsynth {
public:
    Subsynth(double samplerate);
    ~Subsynth();

    double output();
    double calculate();

    void setCutoff(float cutoff);
    void setDetune(float detune);
    void setPitch(float pitch);
    inline float getPitch(){return m_pitch;}
    void updatePitches();


private:
    inline float mtof(float pitch){return 440.0 * pow(2.0 , ((pitch-57.0)/12.0));}

    double m_samplerate;
    float m_pitch;
    float m_detune;
    float oldPitch;

    Oscillator *osc_1;
    Oscillator *osc_2;

    Onepole lpf_1;
    Onepole lpf_2;

    Oversampler *over;

};
