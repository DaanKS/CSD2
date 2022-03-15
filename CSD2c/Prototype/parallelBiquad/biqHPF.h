//
// Created by Dean on 14/03/2022
//

#include "biquad.h"

#pragma once

class BiqHPF : public Biquad{
public:
    BiqHPF();
    ~BiqHPF();

protected:
     void calculateBzero() override;
     void calculateBone() override;
     void calculateBtwo() override;
     void calculateAzero() override;
     void calculateAone() override;
     void calculateAtwo() override;
};