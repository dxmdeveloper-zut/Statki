#pragma once
#include <Statki/Statek.hpp>
#include <memory>


class Jednomasztowiec : public Statek {
    public:
    Jednomasztowiec(sf::Vector2i position, int rotation = 0);
    virtual ~Jednomasztowiec() override {};

    static constexpr char defaultTexturePath[] = "images/jednomasztowiec.png";
    static constexpr char destroyedTexturePath[] = "images/jednomasztowiec-destroyed.png";

    static sf::Texture defaultTexture;
    static sf::Texture destroyedTexture;

    size_t getLength() const override {return 1;} ;
    const sf::Texture& getDefaultTexture() const override;
    const sf::Texture& getDestroyedTexture() const override;

    private:

};