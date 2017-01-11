#ifndef _PLAYER_H
#define _PLAYER_H

#include "Character.hpp"

/**
 *  Classe joueur
 *
 *  @author kseng, mboisse
 */
class Player : public Character{
public:
    Player();
	void attack();
    void rotation(sf::RenderWindow& window);
    virtual void deplacement();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif
