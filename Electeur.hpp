#ifndef _ELECTEUR_H
#define _ELECTEUR_H

#include "Character.hpp"

class Electeur : public Character{
public:
    Electeur();
    virtual void deplacement() const;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
