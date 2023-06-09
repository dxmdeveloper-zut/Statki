#include "Statek.hpp"

#include <utility>

void Statek::destroy(){
    this->sprite.setTexture(this->getDestroyedTexture());
    this->isDestroyed = true;
}

void Statek::setPosition(std::pair<int, int> position){this->position = position;}
void Statek::setPosition(int x, int y){this->position = {x, y};}

void Statek::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite);
}

Statek::Statek(std::pair<int, int> position){
}

std::vector<std::pair<int, int>> Statek::getOccupiedPosVec() const {
    std::vector<std::pair<int, int>> vec(this->getLength());
    size_t len = this->getLength();
    int rot = this->rotation;
    int originX = this->position.first;
    int originY = this->position.second;
    if(rot | 1){
        for(int y = originY; (rot == 1 ? y < originY + len : y > originY - len); y += (rot == 1 ? 1 : -1)){
            vec.push_back({originX, y});
        }
    } else {
        for(int x = originX; (rot == 0 ? x < originX + len : x > originX - len); x += (rot == 0 ? 1 : -1)){
            vec.push_back({x, originY});
        }
    }
    return vec;
}

Statek::~Statek() {};