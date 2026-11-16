#pragma once
#include <iostream>
#include <stdio>
#include <stack>
#include <stdlib>
#include <string>

class ShotBlaster:
    protected:
    std::stack<char> m_mag;
    int m_capacity;
    public:
    int m_count;
    int m_range;
    int m_heat;
    ShotBlaster();
    void load_shells();
    std::string fire();
    void change_range();
    void cool();