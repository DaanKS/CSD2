//
// Created by Dean on 21/02/2022.
//

#include "history.h"

History::History() : inputSample(0), previousSample(0){}
History::~History(){}

double History::tick(double inputSample){
    double outputSample = previousSample;
    previousSample = inputSample;
    return outputSample;
}
