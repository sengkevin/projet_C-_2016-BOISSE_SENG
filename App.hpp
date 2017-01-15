#ifndef _APP_H
#define _APP_H

#include "Player.hpp"
#include "Trump.hpp"
#include "Obama.hpp"
#include "CitoyenBase.hpp"
#include "CitoyenGros.hpp"
#include "GameState.hpp"

#define N_CITOYENS         7
#define CITOYENS_BASE_HP   100

#define DRAIN_TIME         1
#define DRAIN_RATE         5

#define HP_REGEN_RATE      7


class App {
public:
    App(sf::RenderWindow& window, sf::Clock& gameClock, std::vector<Character*> charList) : m_window(window), m_gameClock(gameClock), m_charList(charList){};
    void renderPlayer(Player& player);
    void renderCitoyen(Citoyen& citoyen);
    void endGame(Player& player);
    friend void gameLoop(App& application);

private:
    sf::RenderWindow& m_window;
    sf::Clock& m_gameClock;
    std::vector<Character*> m_charList;
};

void gameLoop(App& application);

#endif
