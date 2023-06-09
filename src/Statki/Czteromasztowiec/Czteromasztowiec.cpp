#include "Czteromasztowiec.hpp"

constexpr char Czteromasztowiec::defaultTexturePath[];
constexpr char Czteromasztowiec::destroyedTexturePath[];

sf::Texture Czteromasztowiec::defaultTexture = sf::Texture();
sf::Texture Czteromasztowiec::destroyedTexture = sf::Texture();

Czteromasztowiec::Czteromasztowiec(std::pair<int, int> position, int rotation) 
                 : Statek(position, sf::Sprite(),
                          this->defaultTexture, this->defaultTexturePath,
                          this->destroyedTexture, this->destroyedTexturePath){
    this->rotation = rotation;
}

std::size_t Czteromasztowiec::getLength() const {return 4;}


