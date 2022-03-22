#include <iostream>
#ifndef EINDOPDRACHT_ENERGYDETECT_H
#define EINDOPDRACHT_ENERGYDETECT_H
//0 = nothing
//1 = constructors
//2 = functions
//3 = variables
#define DEBUG 3

class EnergyDetect{
public:
    EnergyDetect();
    EnergyDetect(float inputBuffer[], int inputBufSize, int numberFx,
                 unsigned int samplerate);
    ~EnergyDetect();

    float* envBuffer;
    int bufferSize;

    int envChunckForFx = 0;
    int envAmpBufferSize;
    //this is a double pointer cuz its a multidimentional array
    //depending on the number of fx, a number of
    //envelope buffers is created
    float** envAmpBuffer;

private:
    unsigned int m_samplerate;
    //fraction is blockszie of samplepoints (needs to be float because castig)
    float fraction = 10;
    void averageEnvAmp(float inputBuffer[], int inputBufSize);

};

#endif //EINDOPDRACHT_ENERGYDETECT_H