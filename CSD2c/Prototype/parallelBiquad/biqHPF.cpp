//
// Created by Dean on 14/03/2022
//

#include "biqHPF.h"

BiqHPF::BiqHPF() : Biquad()
{}
BiqHPF::~BiqHPF() = default;

void BiqHPF::calculateBzero(){
    this->Bzero = (1.0 + cos(omega)) / 2.0;
}
void BiqHPF::calculateBone() {
    this->Bone = -1 * (1.0 + cos(omega));
}
void BiqHPF::calculateBtwo(){
    this->Btwo = (1.0 + cos(omega)) / 2.0;
}
void BiqHPF::calculateAzero(){
    this->Azero = 1.0 + alpha;
}
void BiqHPF::calculateAone(){
    this->Aone = (-2.0 * cos(omega));
}
void BiqHPF::calculateAtwo(){
    this->Atwo = 1.0 - alpha;
}