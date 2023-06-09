#include "Czteromasztowiec.hpp"

constexpr char Czteromasztowiec::defaultTexturePath[];
constexpr char Czteromasztowiec::destroyedTexturePath[];

sf::Texture Czteromasztowiec::defaultTexture = sf::Texture();
sf::Texture Czteromasztowiec::destroyedTexture = sf::Texture();

// Constructor
Czteromasztowiec::Czteromasztowiec(std::pair<int, int> position, int rotation) 
                                : Statek(position)
{
    this->rotation = rotation;
    this->defaultTexture.loadFromFile(this->defaultTexturePath);
    this->destroyedTexture.loadFromFile(this->destroyedTexturePath);
}

std::size_t Czteromasztowiec::getLength() const {return 4;}

const sf::Texture& Czteromasztowiec::getDefaultTexture() const {
    return this->defaultTexture;
}

const sf::Texture& Czteromasztowiec::getDestroyedTexture() const {
    return this->destroyedTexture;
}
