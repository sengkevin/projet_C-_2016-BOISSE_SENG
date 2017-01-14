#include <SFML/Graphics.hpp>
#include <thread>
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

    if(gameClock.getElapsedTime().asMilliseconds() % 66 == 0)
    {
        player.stateHandler(window, gameClock, charList);
        player.animationDraw();
    }

    window.draw(player);
}

void renderCitoyen(sf::RenderWindow& window, Citoyen& citoyen, sf::Clock& gameClock){
    citoyen.deplacement();
    window.draw(citoyen);
}

void endGame(){

}
/**
 *  Boucle de jeu
 *
 *  @param window
 *          Fenetre de jeu
 */
void gameLoop(sf::RenderWindow& window, std::vector<Character*>& charList){
    GameState gameCurrState;
    sf::Clock gameClock;

    gameClock.restart();

    while(window.isOpen()){
        switch(gameCurrState.getCurrentState()){
            case GameState::INIT:
                gameCurrState.setCurrentState(GameState::LOAD);
                break;

                case GameState::MENU:

                gameCurrState.setCurrentState(GameState::GAME);
                break;

            case GameState::LOAD:
                charList.push_back(new Trump);
                for(int i=0; i<5; i++)
                    charList.push_back(new Citoyen(5));

                gameCurrState.setCurrentState(GameState::MENU);
                break;


            case GameState::GAME:
                window.clear(sf::Color::Black);

                renderPlayer(window, (Player&)(*charList[0]), std::ref(gameClock), charList);

                for(unsigned int i=1; i<charList.size(); i++){
                    if(charList[i]->isAlive())
                        renderCitoyen(window, (Citoyen&)(*charList[i]), std::ref(gameClock));
                    else{
                        charList.erase(charList.begin() + i);
                        i = 1;
                    }
                }
                if(charList.size() <= 1){
                    endGame();
                    gameCurrState.setCurrentState(GameState::EXIT);
                }

                window.display();
                break;

            case GameState::EXIT:
                break;

        }
    }
}
