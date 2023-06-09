#pragma once
#include <SFML/Graphics.hpp>

#include <cstddef>
#include <utility>

class Statek : public sf::Drawable {
    public:
    Statek(std::pair<int, int> position, sf::Sprite sprite,
           sf::Texture& defaultTexture, const char defaultTexturePath[],
           sf::Texture& destroyedTexture, const char destroyedTexturePath[]);
    virtual ~Statek() = 0;

    void destroy();

    // Inherited
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    // Virtual
    virtual std::size_t getLength() const = 0;
    
    protected:

    int rotation{};
    std::pair<int, int> position;

    sf::Texture& defaultTexture;
    sf::Texture& destroyedTexture;

    sf::Sprite sprite;
    bool isDestroyed;

    private:
    // Virtual
    ///@brief should be called in constructor of derived class
    void loadTextures(const char *defaultTexturePath, const char *destroyedTexturePath);

};