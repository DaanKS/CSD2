#pragma once

class Highpass{
public:
    Highpass();
    Highpass(float A);
    ~Highpass();

    float output(float inputSample);
    void setCoefficients(float A);

private:
    float xHistory_1;
    float m_A;
};