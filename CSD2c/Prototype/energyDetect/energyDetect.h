#include <iostream>

class EnergyDetect{
public:
    EnergyDetect(float inputBuffer[], int inputBufSize,
                 unsigned int samplerate);
    ~EnergyDetect();

private:
    unsigned int m_samplerate;
    int bufferSize;
    float* envBuffer;
    //fraction is blockszie of samplepoints (needs to be float because castig)
    float fraction = 10;
    void averageEnvAmp(float inputBuffer[], int inputBufSize);
};