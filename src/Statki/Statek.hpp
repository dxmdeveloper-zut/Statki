#pragma once
#include <SFML/Graphics.hpp>

#include <cstddef>
#include <utility>
#include <vector>

enum STATEK_ROTATION_ENUM {
    STATEK_ROT_HEAD_TO_RIGHT = 0,
    STATEK_ROT_HEAD_TO_DOWN = 1,
    STATEK_ROT_HEAD_TO_LEFT = 2,
    STATEK_ROT_HEAD_TO_UP = 3,
};

class Statek : public sf::Drawable {
    public:
    Statek(std::pair<int, int> position);
    virtual ~Statek();

    // Own Methods
    void destroy();
    void setPosition(std::pair<int, int> position);
    void setPosition(int x, int y);
    
    std::vector<std::pair<int, int>> getOccupiedPosVec() const;

    // Inherited
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    // Virtual
    virtual std::size_t getLength() const = 0;
    virtual const sf::Texture& getDefaultTexture() const = 0;
    virtual const sf::Texture& getDestroyedTexture() const = 0;

    protected:

    int rotation;
    std::pair<int, int> position;

    sf::Sprite sprite;
    bool isDestroyed;

    private:
};