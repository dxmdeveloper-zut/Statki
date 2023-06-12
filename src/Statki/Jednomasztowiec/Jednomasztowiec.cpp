#include "Jednomasztowiec.hpp"

#define TMPL_CLASS_NAME Jednomasztowiec
#include <Statki/Derived_Statek_Static_Init_Template.hpp>

// Constructor
Jednomasztowiec::Jednomasztowiec(sf::Vector2i position, int rotation) : Statek(position, rotation) {
    Statek::loadTextures(defaultTexture, destroyedTexture,
                         defaultTexturePath, destroyedTexturePath);
    this->sprite.setTexture(defaultTexture);
}