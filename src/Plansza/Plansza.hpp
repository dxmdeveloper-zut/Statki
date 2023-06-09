#pragma once
#include <cstdint>
#include <vector>
#include <memory>
#include <Statki/Statek.hpp>

class Plansza {
    private:
    std::vector<Statek> statki;
    int8_t matrix[10][10];
};