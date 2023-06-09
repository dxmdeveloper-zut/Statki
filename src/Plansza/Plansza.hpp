#pragma once
#include <cstdint>
#include <vector>
#include <memory>
#include <Statki/Statek.hpp>

#define PLANSZA_WIDTH 10
#define PLANSZA_HEIGHT 10


/*
 range [1 : 11] statek index+1
 range [-11 : -1] statek abs(index+1)
*/
enum CELL_STATE_ENUM {
    CELL_STATE_EMPTY            =  0,
    CELL_STATE_MISSED           = 256,
    INVALID_CELL_POSITION       = 257,
};



class Plansza {
    public:
    Plansza();
    /// @return 0 on success, -1 if position is invalid, -2 if position is occupied
    int addStatek(Statek statek);

    /// @return CELL_STATE_ENUM
    int checkState(std::pair<int, int> position) const;

    private:
    std::vector<Statek> statki;
    int8_t matrix[PLANSZA_HEIGHT][PLANSZA_WIDTH];
};