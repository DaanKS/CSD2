#include "History.h"

History::History(){}
History::~History(){}

float History::tick(double inputSample){
    float outputSample = previousSample;
    previousSample = inputSample;
    return outputSample;
}
