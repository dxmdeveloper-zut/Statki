#pragma once
#include <Statki/Statek.hpp>
#include <memory>


class Czteromasztowiec : public Statek {
    public:
    Czteromasztowiec(std::pair<int, int> position, int rotation = 0);
    ~Czteromasztowiec() override = 0;


    static constexpr char defaultTexturePath[] = "images/czteromasztowiec.png";
    static constexpr char destroyedTexturePath[] = "images/destroyed-czteromasztowiec.png";

    static sf::Texture defaultTexture;
    static sf::Texture destroyedTexture;

    size_t getLength() const;

    private:

};