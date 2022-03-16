#pragma once

class Onepole{
public:
    Onepole();
    ~Onepole();

    float output(float inputSample);
    void setCoefficinets(float A, float B);

private:
    float xHistory_1;

    float m_A;
    float m_B;
};