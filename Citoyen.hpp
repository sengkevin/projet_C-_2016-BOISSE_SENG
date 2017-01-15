#ifndef _CITOYEN_H
#define _CITOYEN_H

#include "Character.hpp"

/**
 *  Classe Citoyen
 *  Ennemis du jeu
 *
 *  @author kseng, mboisse
 */
class Citoyen : public Character{
public:
    Citoyen(int hp, float speed);
    virtual void deplacement();
    virtual void animationDraw();

    /**
     *  Opérateur == pour tester si deux citoyens ont le même nombre de points de vie
     */
    friend bool operator==(Citoyen& c1, Citoyen& c2){
        return (c1.m_hp == c2.m_hp);
    }

private:
    int m_distance;
    int m_dirX;
    int m_dirY;
};

#endif
