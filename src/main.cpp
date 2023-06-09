#include <iostream>
#include <array>
#include "Statki/Czteromasztowiec/Czteromasztowiec.hpp"
#include <SFML/Graphics.hpp>

#define FPS 60

int main(int argc, char * argv[]){
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::Clock deltaClock;

    // MAIN LOOP
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
       
        window.clear();
        //window.draw(shape);
        window.display();
    }

    return 0;
}