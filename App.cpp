#include <SFML/Graphics.hpp>
#include "App.hpp"

/**
 *  Rendu graphique du joueur
 *
 *  @param window
 *          Fenetre de jeu
 *  @param player
 *          Personnage joueur
 */
void renderPlayer(sf::RenderWindow& window, Player& player, sf::Clock& gameClock){
    player.deplacement();
    player.rotation(window);
    player.stateHandler(gameClock);

    window.draw(player);
}

/**
 *  Boucle de jeu
 *
 *  @param window
 *          Fenetre de jeu
 */
void gameLoop(sf::RenderWindow& window){
    sf::Clock gameClock;

    gameClock.restart();

    Player player;
    Electeur electeur1, electeur2;
    
    while(window.isOpen()){
        window.clear(sf::Color::Black);

        renderPlayer(window, std::ref(player), std::ref(gameClock));

        window.display();
    }
}
