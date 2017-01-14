#ifndef _CITOYEN_H
#define _CITOYEN_H

#include "Character.hpp"

/**
 *  Classe Citoyen
 *  Ennemis basique du jeu
 *
 *  @author kseng, mboisse
 */
class Citoyen : public Character{
public:
    Citoyen(int hp);
    virtual void deplacement();
    virtual void animationDraw();

//    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    int m_distance;
    int m_dirX;
    int m_dirY;
};

#endif
