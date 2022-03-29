#include <iostream>
#ifndef EINDOPDRACHT_ENERGYDETECT_H
#define EINDOPDRACHT_ENERGYDETECT_H
//0 = nothing
//1 = constructors
//2 = functions
//3 = variables
#define DEBUG 0

class EnergyDetect{
public:
    EnergyDetect(float inputBuffer[], int inputBufSize, int numberParams);
    ~EnergyDetect();

    //TODO:make nice with setters and getters and  stuff
    float* envBuffer;
    int bufferSize;
    int envChunckForFx = 0;
    int envAmpBufferSize;
    //this is a double pointer cuz it's a 2d array
    //depending on the number of fx params, and number of
    //envelope points (depending on the input buffer)
    float** envAmpBuffer;

private:
    //fraction is chunk of samplepoints (needs to be float because castig)
    float fraction = 1000;
    void averageEnvAmp(float inputBuffer[], int inputBufSize);
};

#endif //EINDOPDRACHT_ENERGYDETECT_H