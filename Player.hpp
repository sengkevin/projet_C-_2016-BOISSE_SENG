#ifndef _PLAYER_H
#define _PLAYER_H

#include "Character.hpp"
#include "Attaque.hpp"

/**
 *  Classe joueur
 *
 *  @author kseng, mboisse
 */
class Player : public Character{
public:
    Player();
	void attaque();
    void rotation(sf::RenderWindow& window);

    /**
    *	Test de l'etat du personnage (marche, arret)
    */
    void stateHandler(sf::Clock&);

    virtual void deplacement();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};


#endif
