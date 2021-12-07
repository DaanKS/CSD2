#include "History.h"

History::History(){}
History::~History(){}

double History::tick(double inputSample){
    double outputSample = previousSample;
    previousSample = inputSample;
    return outputSample;
}
