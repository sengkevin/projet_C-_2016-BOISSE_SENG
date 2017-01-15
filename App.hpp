#ifndef _APP_H
#define _APP_H

#include "Player.hpp"
#include "Trump.hpp"
#include "Obama.hpp"
#include "Citoyen.hpp"
#include "GameState.hpp"

#define N_CITOYENS         7
#define CITOYENS_BASE_HP   100

#define DRAIN_TIME         1
#define DRAIN_RATE         5

#define HP_REGEN_RATE      7

void gameLoop(sf::RenderWindow& window, std::vector<Character*>& charList);

#endif
