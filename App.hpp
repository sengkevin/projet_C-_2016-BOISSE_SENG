#ifndef _APP_H
#define _APP_H

#include "Player.hpp"
#include "Trump.hpp"
#include "Obama.hpp"
#include "Citoyen.hpp"
#include "GameState.hpp"

#define N_ELECTEURS         5
#define ELECTEURS_BASE_HP   10
void gameLoop(sf::RenderWindow& window, std::vector<Character*>& charList);

#endif
