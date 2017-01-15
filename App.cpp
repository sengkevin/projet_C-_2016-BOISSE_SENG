#include <SFML/Graphics.hpp>
#include <thread>
#include "App.hpp"
#include "windowParam.hpp"

sf::Font font;

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

    if(gameClock.getElapsedTime().asMilliseconds() % 66 == 0)
    {
        citoyen.animationDraw();
    }

    window.draw(citoyen);
}

void endGame(sf::RenderWindow& window, Player& player){
    sf::Text resultPrint;
    sf::Text textExit;
    sf::Texture t_badEndImage;
    sf::RectangleShape r_badEndImage(sf::Vector2f(396,211));

    resultPrint.setFont(font);
    resultPrint.setFillColor(sf::Color::Red);
    resultPrint.setOutlineColor(sf::Color::Black);
    resultPrint.setOutlineThickness(2);

    textExit.setFont(font);
    textExit.setString("Appuyez sur (Alt + F4) pour quitter");
    textExit.setCharacterSize(15);
    textExit.setFillColor(sf::Color::White);
    textExit.setOutlineColor(sf::Color::Black);
    textExit.setOutlineThickness(1);
    textExit.setPosition(250, 500);

    if(player.getHp() < 50){
        if(!t_badEndImage.loadFromFile("img/notgoodending.png"))
            return;
        resultPrint.setCharacterSize(30);
        std::string str = "Vous avez perdu\nResultat des elections : ";
        str += std::to_string(player.getHp());
        str += "%";
        resultPrint.setString(str);
        resultPrint.setOrigin(resultPrint.getGlobalBounds().width/2, resultPrint.getGlobalBounds().height/2);
        resultPrint.setPosition(400, 100);
    }
    else{
        if(!t_badEndImage.loadFromFile("img/worstending.png"))
            return;
        resultPrint.setCharacterSize(20);
        resultPrint.setString("Le FBI a retrouve vos traces en examinant les cadavres de vos victimes\n Vous avez perdu");
        resultPrint.setOrigin(resultPrint.getGlobalBounds().width/2, resultPrint.getGlobalBounds().height/2);
        resultPrint.setPosition(400, 100);
    }

    r_badEndImage.setTexture(&t_badEndImage);
    r_badEndImage.setOrigin(0,0);
    r_badEndImage.setPosition(200,200);

    window.clear(sf::Color::Black);
    window.draw(resultPrint);
    window.draw(textExit);
    window.draw(r_badEndImage);
    window.display();
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
    sf::Clock drainLife;

    sf::Time gameTime = sf::seconds(60.0f);

    sf::Text text1, text2;
    std::string perso, textLife, timeRem;

    sf::Texture t_menuFond, t_fond, iconTrump, iconObama;

    if(!font.loadFromFile("DejaVuSans.ttf"))
        return;

    if(!iconTrump.loadFromFile("img/trump_icon.png"))
        return;

    if(!iconObama.loadFromFile("img/obama_icon.png"))
        return;

    if(!t_menuFond.loadFromFile("img/usflag.png"))
        return;

    sf::RectangleShape s_menuFond(sf::Vector2f(W_WIDTH, W_HEIGHT));
    sf::RectangleShape s_fond(sf::Vector2f(W_WIDTH, W_HEIGHT));
    sf::RectangleShape rectTrump(sf::Vector2f(iconTrump.getSize()));
    sf::RectangleShape rectObama(sf::Vector2f(iconObama.getSize()));

    while(window.isOpen()){
        switch(gameCurrState.getCurrentState()){
            case GameState::INIT:
                s_menuFond.setTexture(&t_menuFond);
                s_menuFond.setOrigin(0,0);
                s_menuFond.setPosition(0,0);

                rectTrump.setTexture(&iconTrump);
                rectTrump.setOutlineThickness(10);
                rectTrump.setOrigin(100,100);
                rectTrump.setPosition(250,350);

                rectObama.setTexture(&iconObama);
                rectObama.setOutlineThickness(10);
                rectObama.setOrigin(100,100);
                rectObama.setPosition(550,350);

                text1.setFont(font);
                text1.setString("Choisissez votre personnage");
                text1.setCharacterSize(35);
                text1.setFillColor(sf::Color::Yellow);
                text1.setOutlineColor(sf::Color::Black);
                text1.setOutlineThickness(3);
                text1.setOrigin(text1.getGlobalBounds().width/2, text1.getGlobalBounds().height/2);
                text1.setPosition(400, 110);

                text2.setFont(font);
                text2.setString("Z,Q,S,D : Directions\nClic gauche : Poing\nClic Droit : Pied ");
                text2.setCharacterSize(20);
                text2.setFillColor(sf::Color::White);
                text2.setOutlineColor(sf::Color::Black);
                text2.setOutlineThickness(1);
                text2.setPosition(300, 500);

                gameCurrState.setCurrentState(GameState::MENU);
                break;

            case GameState::MENU:
                rectTrump.setOutlineColor(sf::Color::Blue);
                rectTrump.setFillColor(sf::Color(50,50,50,255));
                rectObama.setOutlineColor(sf::Color::Blue);
                rectObama.setFillColor(sf::Color(50,50,50,255));

                if(rectTrump.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window))){
                    rectTrump.setFillColor(sf::Color(255,255,255,255));
                    rectTrump.setOutlineColor(sf::Color::Red);
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        perso = "Trump";
                        gameCurrState.setCurrentState(GameState::LOAD);
                    }
                }
                if(rectObama.getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window))){
                    rectObama.setOutlineColor(sf::Color::Red);
                    rectObama.setFillColor(sf::Color(255,255,255,255));

                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                        perso = "Obama";
                        gameCurrState.setCurrentState(GameState::LOAD);
                    }
                }

                window.clear(sf::Color::Red);
                window.draw(s_menuFond);
                window.draw(rectTrump);
                window.draw(rectObama);
                window.draw(text1);
                window.draw(text2);
                window.display();
                break;

            case GameState::LOAD:
                if(perso == "Trump")
                    charList.push_back(new Trump);
                else if(perso == "Obama")
                    charList.push_back(new Obama);

                for(int i=1; i<=N_CITOYENS; i++){
                    charList.push_back(new Citoyen(CITOYENS_BASE_HP));
                    charList[i]->setPosition(rand()%W_WIDTH, rand()%W_HEIGHT);
                }

                if(!t_fond.loadFromFile("img/fond.png"))
                    return;
                s_fond.setTexture(&t_fond);

                text1.setCharacterSize(20);
                text1.setFillColor(sf::Color::White);
                text1.setOutlineColor(sf::Color::Black);
                text1.setOutlineThickness(2);
                text1.setOrigin(0,0);
                text1.setPosition(20, 10);

                text2.setCharacterSize(20);
                text2.setFillColor(sf::Color::White);
                text2.setOutlineColor(sf::Color::Black);
                text2.setOutlineThickness(2);
                text2.setOrigin(0,0);
                text2.setPosition(300, 10);

                gameClock.restart();
                drainLife.restart();

                gameCurrState.setCurrentState(GameState::GAME);
                break;

            case GameState::PAUSE:
                break;

            case GameState::GAME:
                window.draw(s_fond);

                textLife = "Electeurs : ";
                textLife += std::to_string(charList[0]->getHp());
                textLife += "%";
                text1.setString(textLife);

                timeRem = "Temps restant : ";
                timeRem += std::to_string((int)(gameTime.asSeconds()-gameClock.getElapsedTime().asSeconds()));
                text2.setString(timeRem);

                renderPlayer(window, (Player&)(*charList[0]), std::ref(gameClock), charList);

                for(unsigned int i=1; i<charList.size(); i++){
                    if(!charList[i]->isInBound(window)){
                        charList.erase(charList.begin()+i);
                        charList.push_back(new Citoyen(CITOYENS_BASE_HP));
                        i = 1;
                    }
                    else if(!charList[i]->isAlive())
                    {
                        charList.erase(charList.begin()+i);
                        charList.push_back(new Citoyen(CITOYENS_BASE_HP));
                        charList[0]->addHp(((Player*)charList[0])->getHealRate());
                        i = 1;
                    }
                    else
                        renderCitoyen(window, (Citoyen&)(*charList[i]), std::ref(gameClock));
                }
                if(drainLife.getElapsedTime().asSeconds() > DRAIN_TIME)
                {
                    charList[0]->damage(DRAIN_RATE);
                    drainLife.restart();
                }

                if(!charList[0]->isAlive() || gameClock.getElapsedTime().asSeconds() >= gameTime.asSeconds()){
                    gameCurrState.setCurrentState(GameState::OVER);
                }

                if(charList[0]->getHp() < 10)
                    text1.setFillColor(sf::Color(200,0,0,255));
                else if(charList[0]->getHp() < 25)
                    text1.setFillColor(sf::Color(255,100,0,255));
                else if(charList[0]->getHp() < 50)
                    text1.setFillColor(sf::Color(100,255,0,255));
                else if(charList[0]->getHp() < 75)
                    text1.setFillColor(sf::Color(50,255,0,255));
                else
                    text1.setFillColor(sf::Color(0,255,0,255));


                window.draw(text1);
                window.draw(text2);
                window.display();
                break;

            case GameState::OVER:
                endGame(window, (Player&)*charList[0]);
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    gameCurrState.setCurrentState(GameState::EXIT);
                break;

            case GameState::EXIT:
//                window.close();
                break;

        }
    }
}
