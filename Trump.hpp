#ifndef _TRUMP_H
#define _TRUMP_H

#include <cmath>
#include "Player.hpp"

/**
 *  Classe Trump
 *
 *  @author kseng, mboisse
 */
class Trump : public Player{
public:
    Trump();

    virtual void animationDraw();
};


#endif
