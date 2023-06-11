// Define TMPL_CLASS_NAME before include
// Include in every Statek derived class cpp
#ifndef TMPL_CLASS_NAME
    //#error "TMPL_CLASS_NAME NOT DEFINED"
#endif

#include <SFML/Graphics.hpp>

constexpr char TMPL_CLASS_NAME::defaultTexturePath[];
constexpr char TMPL_CLASS_NAME::destroyedTexturePath[];

sf::Texture TMPL_CLASS_NAME::defaultTexture = sf::Texture();
sf::Texture TMPL_CLASS_NAME::destroyedTexture = sf::Texture();

const sf::Texture& TMPL_CLASS_NAME::getDefaultTexture() const {return this->defaultTexture;}
const sf::Texture& TMPL_CLASS_NAME::getDestroyedTexture() const {return this->destroyedTexture;}

#undef  TMPL_CLASS_NAME