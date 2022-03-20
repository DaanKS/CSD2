#pragma once

class Onepole{
public:
    Onepole();
    Onepole(float A);
    ~Onepole();

    float output(float inputSample);
    void setCoefficinets(float A);

private:
    float xHistory_1;

    float m_A;
};