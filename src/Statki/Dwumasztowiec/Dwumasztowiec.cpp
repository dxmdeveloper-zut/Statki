#include "Dwumasztowiec.hpp"

#define TMPL_CLASS_NAME Dwumasztowiec
#include <Statki/Derived_Statek_Static_Init_Template.hpp>

// Constructor
Dwumasztowiec::Dwumasztowiec(sf::Vector2i position, int rotation) : Statek(position, rotation){
    Statek::loadTextures(defaultTexture, destroyedTexture,
                         defaultTexturePath, destroyedTexturePath);
}