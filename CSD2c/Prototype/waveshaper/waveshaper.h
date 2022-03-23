#include <cmath>
#include <iostream>
#include "squarelaw.h"

class Waveshaper{
public:
    Waveshaper(double samplerate);
    ~Waveshaper();

    void generateWaveTable();

    float output(float inputSample);

    float mapInRange(float input, float xLow, float xHigh, float yLow, float yHigh);
    float linearMap(float input, float low, float high);

    void setKvalue(float kValue);
    void setBufferSize(int bufferSize);
    void setDryWet(float drywet);
    
protected:
    std::unique_ptr<Mix> mix;
    float* buffer;

    int bufferSize;
    float kValue;
    float m_drywet;
};