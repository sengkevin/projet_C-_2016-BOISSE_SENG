#include <SFML/Graphics.hpp>
#include "App.hpp"

void gameLoop(sf::RenderWindow& window){
    Player player;

    while(window.isOpen()){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            player.move(-player.getSpeed(),0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            player.move(player.getSpeed(),0);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            player.move(0, -player.getSpeed());
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            player.move(0, player.getSpeed());
        }

        window.clear(sf::Color::Black);
        window.draw(player);
        window.display();
    }
}
