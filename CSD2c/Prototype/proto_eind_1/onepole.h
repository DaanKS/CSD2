//
// Created by Dean on 27/03/2022.
//
// Formula's taken from https://dsp.stackexchange.com/questions/54086/single-pole-iir-low-pass-filter-which-is-the-correct-formula-for-the-decay-coe
//

#include <atomic>
#include <cmath>

#pragma once

struct OnepoleCoefficients{
    double Aone, Atwo;
};

class Onepole{
public:
    Onepole();
    Onepole(float cutoff);
    ~Onepole();

    float output(float inputSample);
    void setCoefficinets(const OnepoleCoefficients coefficients);

    OnepoleCoefficients makeLowPass(float cutoff) noexcept;
    OnepoleCoefficients makeHighPass(float cutoff) noexcept;


private:
    std::atomic<OnepoleCoefficients> currentCoefficients;

    float xHistory_1;

};