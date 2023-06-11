#pragma once
#include <Statki/Statek.hpp>
#include <memory>


class Czteromasztowiec : public Statek {
    public:
    Czteromasztowiec(sf::Vector2i position, int rotation = 0);
    virtual ~Czteromasztowiec() override {};

    static constexpr char defaultTexturePath[] = "images/czteromasztowiec.png";
    static constexpr char destroyedTexturePath[] = "images/destroyed-czteromasztowiec.png";

    static sf::Texture defaultTexture;
    static sf::Texture destroyedTexture;

    size_t getLength() const override {return 4;} ;
    const sf::Texture& getDefaultTexture() const override;
    const sf::Texture& getDestroyedTexture() const override;

    private:

};