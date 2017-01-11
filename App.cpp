#include <SFML/Graphics.hpp>
#include "App.hpp"

void renderPlayer(sf::RenderWindow& window, Player& player){
    player.deplacement();
    player.direction(window);

    window.draw(player);
}

void gameLoop(sf::RenderWindow& window){
    Player player;

    while(window.isOpen()){
        window.clear(sf::Color::Black);

        renderPlayer(window, std::ref(player));

        window.display();
    }
}
