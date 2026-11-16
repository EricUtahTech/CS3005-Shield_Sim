#pragma once
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "shot-blaster.h"

class Shield{
    protected:
    double m_charge;
    public:
    Shield();
    void crank_charge();
    void take_shot(ShotBlaster& shotblaster);
};