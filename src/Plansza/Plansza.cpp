#include "Plansza.hpp"
#include <algorithm>

Plansza::Plansza(){
    this->statki = std::vector<Statek>(10);
}

int Plansza::checkState(std::pair<int, int> position) const {
    if(position.first < 0 || position.second < 0 
    || position.first >= PLANSZA_WIDTH || position. second >= PLANSZA_HEIGHT)
        return INVALID_CELL_POSITION;

    return this->matrix[position.second][position.first];
}

int Plansza::addStatek(Statek statek){
    auto posVec = statek.getOccupiedPosVec();
    for(auto pos : posVec)
        if(this->checkState(pos) != CELL_STATE_EMPTY) return -1;
    
    for(auto pos : posVec){
        this->matrix[pos.second][pos.first] = statki.size();
    }

    this->statki.push_back(statek);
}