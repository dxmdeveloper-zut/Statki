#pragma once
#include <Statki/Statek.hpp>
#include <memory>


class Trzymasztowiec : public Statek {
    public:
    Trzymasztowiec(sf::Vector2i position, int rotation = 0);
    virtual ~Trzymasztowiec() override {};

    static constexpr char defaultTexturePath[] = "images/trzymasztowiec.png";
    static constexpr char destroyedTexturePath[] = "images/trzymasztowiec-destroyed.png";

    static sf::Texture defaultTexture;
    static sf::Texture destroyedTexture;

    size_t getLength() const override {return 3;}
    const sf::Texture& getDefaultTexture() const override;
    const sf::Texture& getDestroyedTexture() const override;

    private:

};