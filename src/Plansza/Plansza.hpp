#pragma once
#include <cstdint>
#include <iostream>
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
    CELL_STATE_MISSED           = 100,
    INVALID_CELL_POSITION       = 101,
};

class Plansza {
    public:
    Plansza();

    /// @return 0 on success, -1 if position is invalid, -2 if position is occupied
    template <class ShipT>
    int addStatek(ShipT&& statek);

    /// @return CELL_STATE_ENUM
    int checkState(sf::Vector2i position) const;

    #ifdef DEBUG
    void printMatrix(){
        for(int i = 0; i <PLANSZA_HEIGHT ; i++){
            for(int ii = 0; ii < PLANSZA_WIDTH ; ii++)
                printf("%04hhi ", matrix[i][ii]);
            printf("\n");
        }
    }
    //! TEMP
    void dbg_printStatek(sf::RenderTarget& rt){
        rt.draw(*statki.at(0), sf::RenderStates::Default);
    }
    #endif

    private:
    std::vector<std::unique_ptr<Statek>> statki;
    int8_t matrix[PLANSZA_HEIGHT][PLANSZA_WIDTH] = {0};
};