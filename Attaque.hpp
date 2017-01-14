#ifndef _ATTAQUE_H
#define _ATTAQUE_H

#include <SFML/Graphics.hpp>

class Attaque : public sf::Sprite{
public:
    Attaque(int degats, int startup, int active, int end, int l, int h, float distance);

//    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    int getDegats(){ return m_degats;}
    float getDistance(){ return m_distance; }
    int getStartupFrame(){ return m_startUpFrame; }
    int getActiveFrame(){ return m_activeFrame; }
    int getEndFrame(){ return m_endFrame; }
    sf::FloatRect getHitbox(){ return getGlobalBounds(); }

protected:
    sf::Texture m_texture;
    sf::Sprite m_sprite;

    int m_degats;

    /**
    *   Durée de l'attaque
    */
    int m_startUpFrame;
    int m_activeFrame;
    int m_endFrame;

    float m_distance;
};

#endif
