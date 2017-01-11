#ifndef _PLAYER_H
#define _PLAYER_H

#include "Character.hpp"

class Player : public Character{
public:
    Player();
	void attack();
    void direction();

    virtual void deplacement();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif
