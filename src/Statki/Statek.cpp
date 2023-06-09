#include "Statek.hpp"

#include <utility>

void Statek::destroy(){
    this->sprite.setTexture(destroyedTexture);
    this->isDestroyed = true;
}

void Statek::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite);
}

void Statek::loadTextures(const char *defaultTexturePath, const char *destroyedTexturePath) {
    if(defaultTexture.getSize().x == 0){
        defaultTexture = sf::Texture();
        defaultTexture.loadFromFile(std::string(defaultTexturePath));
        destroyedTexture = sf::Texture();
        destroyedTexture.loadFromFile(std::string(destroyedTexturePath));
    }
}

Statek::Statek(std::pair<int, int> position, sf::Sprite sprite, sf::Texture &defaultTexture,
               const char *defaultTexturePath, sf::Texture &destroyedTexture, const char *destroyedTexturePath)
        : position {std::move(position)}, sprite {std::move(sprite)}, defaultTexture {defaultTexture}, destroyedTexture {destroyedTexture}{
    this->loadTextures(defaultTexturePath, destroyedTexturePath);
    this->sprite.setTexture(destroyedTexture);
}
