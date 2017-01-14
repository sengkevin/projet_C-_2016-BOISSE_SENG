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
void renderPlayer(sf::RenderWindow& window, Player& player, sf::Clock& gameClock, std::vector<Character*> charList){
    player.getInputs();
    player.rotation(window);

    if(gameClock.getElapsedTime().asMilliseconds() % 66 == 0){
        player.animationDraw();
        player.stateHandler(window, gameClock, charList);
    }

    window.draw(player);
}

void renderCitoyen(sf::RenderWindow& window, Citoyen& citoyen, sf::Clock& gameClock){
    citoyen.deplacement();
    window.draw(citoyen);
}

/**
 *  Boucle de jeu
 *
 *  @param window
 *          Fenetre de jeu
 */
void gameLoop(sf::RenderWindow& window, std::vector<Character*>& charList){
    sf::Clock gameClock;
    gameClock.restart();

    while(window.isOpen()){
        window.clear(sf::Color::Black);

        renderPlayer(window, (Player&)(*charList[0]), std::ref(gameClock), charList);

        for(unsigned int i=1; i<charList.size(); i++)
            renderCitoyen(window, (Citoyen&)(*charList[i]), std::ref(gameClock));

        window.display();
    }
}
