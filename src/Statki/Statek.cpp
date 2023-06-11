#include "Statek.hpp"

#include <utility>

void Statek::destroy(){
    this->sprite.setTexture(this->getDestroyedTexture());
    this->isDestroyed = true;
}

void Statek::setPosition(sf::Vector2i position){this->position = position;}
void Statek::setPosition(int x, int y){this->position = {x, y};}

void Statek::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite);
}

Statek::Statek(sf::Vector2i position, int rotation){
}

std::vector<sf::Vector2i> Statek::getOccupiedPosVec() const {
    std::vector<sf::Vector2i> vec(this->getLength());
    size_t len = this->getLength();
    int rot = this->rotation;
    int originX = this->position.x;
    int originY = this->position.y;
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

Statek::~Statek() {}

void Statek::loadTextures(sf::Texture &defaultTex,sf::Texture &destroyedTex,
                          const char *defTexPath, const char *desTexPath) {
    if(defaultTex.getSize().x == 0) {
        defaultTex.loadFromFile(defTexPath);
        destroyedTex.loadFromFile(desTexPath);
    }
};