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
void renderPlayer(sf::RenderWindow& window, Player& player){
    player.deplacement();
    player.rotation(window);

    window.draw(player);
}

/**
 *  Boucle de jeu
 *
 *  @param window
 *          Fenetre de jeu
 */
void gameLoop(sf::RenderWindow& window){
    Player player;
    Electeur electeur1, electeur2;

    while(window.isOpen()){
        window.clear(sf::Color::Black);

        renderPlayer(window, std::ref(player));
        window.draw(electeur1);
        window.draw(electeur2);

        window.display();
    }
}
