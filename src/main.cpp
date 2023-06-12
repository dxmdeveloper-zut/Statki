#include <iostream>
#include <array>
#include "Statki/Czteromasztowiec/Czteromasztowiec.hpp"
#include <SFML/Graphics.hpp>

#define DEBUG 1
#include "Plansza/Plansza.hpp"

#define FPS 60

int main(int argc, char * argv[]){
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::Clock deltaClock;

    Plansza plansza = Plansza();
    plansza.addStatek(Czteromasztowiec({5, 5}, 0));

    plansza.printMatrix();

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
        plansza.dbg_printStatek(window);
        window.display();
    }

    return 0;
}