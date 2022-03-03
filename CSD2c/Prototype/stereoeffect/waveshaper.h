#include <cmath>
#include <iostream>
#include "audioeffect.h"

class Waveshaper : public AudioEffect{
public:
    Waveshaper(double samplerate);
    ~Waveshaper();

    void generateWaveTable();

    float output(float inputSample);

    float mapInRange(float input, float xLow, float xHigh, float yLow, float yHigh);
    float linearMap(float input, float low, float high);

    void setKvalue(float kValue);
    void setBufferSize(int bufferSize);
    
protected:

    float* buffer;

    int bufferSize;
    float kValue;
};