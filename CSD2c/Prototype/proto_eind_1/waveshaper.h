#include <cmath>
#include <iostream>
#include "audioeffect.h"

class Waveshaper : public AudioEffect{
public:
    Waveshaper(double samplerate);
    Waveshaper(double samplerate, float frequency);
    ~Waveshaper();

    void generateWaveTable();
    void generateSawTable(float frequency);

    float output(float inputSample);

    float mapInRange(float input, float xLow, float xHigh, float yLow, float yHigh);
    float linearMap(float input, float low, float high);

    void setKvalue(float kValue);
    void setBufferSize(int bufferSize);
    void setDryWet(float drywet);

    float clipping(float inputSample, float c_threshold);
    
protected:
    float* buffer;
    int bufferSize;
    float kValue;
    float m_drywet;

    float phase;

};