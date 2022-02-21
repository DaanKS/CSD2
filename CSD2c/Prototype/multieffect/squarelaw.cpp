//
// Created by Dean on 21/02/2022.
//

#include "squarelaw.h"
Mix::Mix(){}
Mix::~Mix(){}

float Mix::getA(float drywet) {
    return 1 - 0.25 * pow((drywet + 1), 2);
}
float Mix::getB(float drywet) {
    return 1 - pow(((0.5 * drywet) - 0.5), 2);
}
