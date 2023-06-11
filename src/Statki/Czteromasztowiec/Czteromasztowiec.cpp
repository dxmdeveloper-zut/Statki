#include "Czteromasztowiec.hpp"

#define TMPL_CLASS_NAME Czteromasztowiec
#include <Statki/Derived_Statek_Static_Init_Template.hpp>

// Constructor
Czteromasztowiec::Czteromasztowiec(sf::Vector2i position, int rotation) : Statek(position, rotation) {
    Statek::loadTextures(defaultTexture, destroyedTexture,
                         defaultTexturePath, destroyedTexturePath);
}