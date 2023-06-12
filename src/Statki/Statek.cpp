#include "Statek.hpp"

void Statek::destroy(){
    this->sprite.setTexture(this->getDestroyedTexture());
    this->isDestroyed = true;
}

void Statek::setPosition(sf::Vector2i position){
    this->position = position;
    this->sprite.setPosition({(float)position.x * 16, (float)position.y * 16});
}
void Statek::setPosition(int x, int y){
    this->position = {x, y};
    this->sprite.setPosition({(float) x * 16, (float) y * 16});
}

void Statek::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

Statek::Statek(sf::Vector2i position, int rotation) :rotation{rotation}{
    this->setPosition(position);
}

std::vector<sf::Vector2i> Statek::getOccupiedPosVec() const {
    auto vec = std::vector<sf::Vector2i>();
    size_t len = this->getLength();
    int rot = this->rotation;
    int originX = this->position.x;
    int originY = this->position.y;
    if(rot & 1){
        for(int y = originY; (rot == 1 ? y < originY + len : y > originY - len); y += (rot == 1 ? 1 : -1)){
            vec.emplace_back(originX, y);
        }
    } else {
        for(int x = originX; (rot == 0 ? x < originX + len : x > originX - len); x += (rot == 0 ? 1 : -1)){
            vec.emplace_back(x, originY);
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