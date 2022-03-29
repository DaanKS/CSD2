#include <iostream>
#include <vector>
#include "energyDetect.h"
#ifndef EINDOPDRACHT_GENERATOR_H
#define EINDOPDRACHT_GENERATOR_H

class Generator{
public:
    Generator(float inputBuffer[], int inputBufSize, int numberParams);
    ~Generator();

    float envAtSamp(int paramNumber);

protected:
    int inputBufSize;
    void calcSampsBetweenAmps();
    void calcSlopeIncrement(int paramNumber);
private:
    EnergyDetect* energyDetect;
    //starting points from which to calculate amplitude
    int envPoint1 = 0;
    int envPoint2 = 1;
    float ampEnvPoint1;
    float ampEnvPoint2;
    float slopeIncrement;
    int sampsBetweenAmps;
    float slope = 0;
    int timesExecuted = 0;
};

#endif //EINDOPDRACHT_GENERATOR_H
