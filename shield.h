#pragma once
#include <iostream>
#include <stdio>
#include <stdlib>
#include <cmath>
#include <string>

class Shield:
    protected:
    double m_charge;
    public:
    Shield();
    void crank_charge();
    void take_shot(ShotBlaster& shotblaster);
