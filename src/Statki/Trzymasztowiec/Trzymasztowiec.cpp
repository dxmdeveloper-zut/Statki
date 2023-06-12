#include "Trzymasztowiec.hpp"

#define TMPL_CLASS_NAME Trzymasztowiec
#include <Statki/Derived_Statek_Static_Init_Template.hpp>

// Constructor
Trzymasztowiec::Trzymasztowiec(sf::Vector2i position, int rotation) : Statek(position, rotation) {
    Statek::loadTextures(defaultTexture, destroyedTexture,
                         defaultTexturePath, destroyedTexturePath);
    this->sprite.setTexture(defaultTexture);
}