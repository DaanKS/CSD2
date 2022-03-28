//
// Created by Dean on 27/03/2022.
//
// Formula's taken from https://dsp.stackexchange.com/questions/54086/single-pole-iir-low-pass-filter-which-is-the-correct-formula-for-the-decay-coe
//

#include <atomic>
#include <cmath>
#include "filter.h"

#pragma once

struct OnepoleCoefficients{
    double Aone, Atwo;
};

class Onepole : public Filter{
public:
    Onepole(double samperate);
    Onepole(float cutoff, double samplerate);
    ~Onepole();

    float output(float inputSample) override;
    void setCoefficinets(const OnepoleCoefficients& coefficients);

    OnepoleCoefficients makeLowPass(float cutoff, double samplerate) noexcept;
    OnepoleCoefficients makeHighPass(float cutoff, double samplerate) noexcept;


private:
    std::atomic<OnepoleCoefficients> currentCoefficients;
    float xHistory_1;

};