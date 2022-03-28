#include <iostream>
#include <vector>
#include "energyDetect.h"
#ifndef EINDOPDRACHT_GENERATOR_H
#define EINDOPDRACHT_GENERATOR_H

class Generator{
public:
    Generator(float inputBuffer[], int inputBufSize, int numberFx,
              int fxIndex, unsigned int samplerate);
    ~Generator();

    float envAtSamp(int fxIndex);

protected:
    int inputBufSize;

    unsigned int samplerate;
    void calcSampsBetweenAmps();
    void calcSlopeIncrement(int fxIndex);
private:
    EnergyDetect* energyDetect;
    //starting points from with to calculte amplitude
    int envPoint1 = 0;
    int envPoint2 = 1;
    float ampEnvPoint1;
    float ampEnvPoint2;
    float slopeIncrement;
    int sampsBetweenAmps;
    float slope = 0;
};

#endif //EINDOPDRACHT_GENERATOR_H
