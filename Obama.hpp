#ifndef _OBAMA_H
#define _OBAMA_H

#include <cmath>
#include "Player.hpp"

/**
 *  Classe Obama
 *  Personnage Obama
 *
 *  @author kseng, mboisse
 */
class Obama : public Player{
public:
    Obama();

    virtual void animationDraw();
};


#endif
