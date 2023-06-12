#include "Plansza.hpp"
#include "Statki/Czteromasztowiec/Czteromasztowiec.hpp"
#include "Statki/Dwumasztowiec/Dwumasztowiec.hpp"
#include <algorithm>
#include <functional>

Plansza::Plansza(){
    this->statki = std::vector<std::unique_ptr<Statek>>();
}

int Plansza::checkState(sf::Vector2i position) const {
    if(position.x < 0 || position.y < 0 
    || position.x >= PLANSZA_WIDTH || position.y >= PLANSZA_HEIGHT)
        return INVALID_CELL_POSITION;

    return this->matrix[position.y][position.x];
}

int Plansza::shoot(sf::Vector2i position) {
    int cell_state = this->checkState(position);
    switch(cell_state){
        case INVALID_CELL_POSITION: break;
        case CELL_STATE_MISSED: return INVALID_CELL_POSITION;
        case CELL_STATE_EMPTY: this->matrix[position.y][position.x] = CELL_STATE_MISSED; break;
        default: {
            int8_t *cellp = &this->matrix[position.y][position.x];
            if(*cellp < 0) return INVALID_CELL_POSITION;
            *cellp = -(cellp[0]);
        } break;
    }
}

template<class ShipT>
int Plansza::addStatek(ShipT&& statek){
    auto posVec = statek.getOccupiedPosVec();
    for(auto pos : posVec)
        if(this->checkState(pos) != CELL_STATE_EMPTY) return -1;
    
    for(auto pos : posVec){
        this->matrix[pos.y][pos.x] = statki.size() + 1;
    }

    this->statki.push_back(std::make_unique<ShipT>(std::move(statek)));
    return 0;
}
template int Plansza::addStatek<Czteromasztowiec>(Czteromasztowiec&& statek);
template int Plansza::addStatek<Dwumasztowiec>(Dwumasztowiec&& statek);
//template int Plansza::addStatek(ShipT&& statek)
//template int Plansza::addStatek(ShipT&& statek)