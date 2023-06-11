#pragma once
#include <Statki/Statek.hpp>

class Dwumasztowiec : public Statek {
public:
    Dwumasztowiec(sf::Vector2i position, int rotation = 0);
    virtual ~Dwumasztowiec() override {};

    static constexpr char defaultTexturePath[] = "images/dwumasztowiec.png";
    static constexpr char destroyedTexturePath[] = "images/destroyed-dwumasztowiec.png";

    static sf::Texture defaultTexture;
    static sf::Texture destroyedTexture;

    std::size_t getLength() const override {return 2;}
    const sf::Texture& getDefaultTexture() const override;
    const sf::Texture& getDestroyedTexture() const override;

};
