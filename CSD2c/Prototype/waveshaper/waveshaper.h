#include <cmath>

class Waveshaper{
public:
    Waveshaper(double samplerate);
    ~Waveshaper();

    void generateWaveTable(float* buffer, int bufferSize, float kValue);

    float output(float inputSample);

    float mapInRange(float input, float xLow, float xHigh, float yLow, float yHigh);
    float linearMap(float input, float low, float high);

protected:
    int bufferSize;
    float kValue;
};