#pragma once
#include <iostream>
#include <stack>
#include <cstdlib>
#include <string>

class ShotBlaster{
    protected:
    std::stack<std::string> m_mag;
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
};