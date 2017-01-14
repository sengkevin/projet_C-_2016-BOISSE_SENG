#ifndef _ATTAQUE_H
#define _ATTAQUE_H

#include <SFML/Graphics.hpp>

class Attaque : public sf::Sprite{
public:
    Attaque(int degats, sf::Time cooldown, int startup, int active, int end, int l, int h, float distance);

//    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    float getDistance(){ return m_distance; }
    int getStartupFrame(){ return m_startUpFrame; }
    int getActiveFrame(){ return m_activeFrame; }
    int getEndFrame(){ return m_endFrame; }
    sf::Time getCooldown() { return m_cooldown; }
    sf::FloatRect getHitbox(){ return getGlobalBounds(); }

protected:
    sf::Texture m_texture;
    sf::Sprite m_sprite;

    int m_degats;

    /**
    *   Délai entre les attaques
    */
    sf::Time m_cooldown;

    /**
    *   Durée de l'attaque
    */
    int m_startUpFrame;
    int m_activeFrame;
    int m_endFrame;

    float m_distance;
};

#endif
