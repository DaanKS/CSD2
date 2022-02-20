#include "history.h"

History::History() : inputSample(0), previousSample(0){}
History::~History(){}

double History::tick(double inputSample){
    double outputSample = previousSample;
    previousSample = inputSample;
    return outputSample;
}
