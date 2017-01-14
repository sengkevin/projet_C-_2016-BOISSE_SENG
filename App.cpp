#include <SFML/Graphics.hpp>
#include <thread>
#include "App.hpp"
#include "windowParam.hpp"

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
    sf::Texture t_fond, iconTrump, iconObama;
    sf::RectangleShape s_fond(sf::Vector2f(W_WIDTH, W_HEIGHT));
    std::string perso;

    sf::Text text;
    sf::Font font;
    if(!font.loadFromFile("DejaVuSans.ttf"))
        return;

    if(!iconTrump.loadFromFile("img/trump_icon.png"))
        return;

    if(!iconObama.loadFromFile("img/obama_icon.png"))
        return;


    sf::RectangleShape rectTrump(sf::Vector2f(iconTrump.getSize()));
    rectTrump.setTexture(&iconTrump);
    rectTrump.setOutlineColor(sf::Color::Blue);
    rectTrump.setOutlineThickness(10);
    rectTrump.setOrigin(100,100);
    rectTrump.setPosition(250,300);

    sf::RectangleShape rectObama(sf::Vector2f(iconObama.getSize()));
    rectObama.setTexture(&iconObama);
    rectObama.setOutlineColor(sf::Color::Blue);
    rectObama.setOutlineThickness(10);
    rectObama.setOrigin(100,100);
    rectObama.setPosition(550,300);

    text.setFont(font);
    text.setString("Choisissez votre personnage");
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::Yellow);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2);
    text.setOrigin(text.getGlobalBounds().width/2, text.getGlobalBounds().height/2);
    text.setPosition(400, 50);

    while(window.isOpen()){
        switch(gameCurrState.getCurrentState()){
            case GameState::INIT:
                gameCurrState.setCurrentState(GameState::MENU);
                break;

            case GameState::MENU:
                window.clear(sf::Color::Red);
                window.draw(rectTrump);
                window.draw(rectObama);
                window.draw(text);
                window.display();

                if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    if(rectTrump.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window))){
                        perso = "Trump";
                        gameCurrState.setCurrentState(GameState::LOAD);
                        gameClock.restart();
                    }
                    else if(rectObama.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window))){
                        perso = "Obama";
                        gameCurrState.setCurrentState(GameState::LOAD);
                        gameClock.restart();
                    }
                }
                break;

            case GameState::LOAD:
                if(perso == "Trump")
                    charList.push_back(new Trump);
                else if(perso == "Obama")
                    charList.push_back(new Obama);

                for(int i=0; i<N_CITOYENS; i++){
                    charList.push_back(new Citoyen(CITOYENS_BASE_HP));
                    charList[i+1]->setPosition(rand()%W_WIDTH, rand()%W_HEIGHT);
                }

                if(!t_fond.loadFromFile("img/fond.png"))
                    return;
                s_fond.setTexture(&t_fond);

                gameCurrState.setCurrentState(GameState::GAME);
                break;


            case GameState::GAME:
                window.draw(s_fond);

                renderPlayer(window, (Player&)(*charList[0]), std::ref(gameClock), charList);

                for(unsigned int i=1; i<charList.size(); i++){
                    if(!charList[i]->isInBound(window) || !charList[i]->isAlive()){
                        charList.erase(charList.begin()+i);
                        charList.push_back(new Citoyen(CITOYENS_BASE_HP));
                        i = 1;
                    }
                    else
                        renderCitoyen(window, (Citoyen&)(*charList[i]), std::ref(gameClock));
                }
                if(!charList[0]->isAlive() || gameClock.getElapsedTime().asSeconds() >= 60){
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
