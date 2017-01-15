#ifndef _ATTAQUE_H
#define _ATTAQUE_H

#include <SFML/Graphics.hpp>

/**
 *  Classe Attaque
 *  Attaques des joueurs
 *
 *  @author kseng, mboisse
 */
class Attaque : public sf::Sprite{
public:
    Attaque(int degats, int startup, int active, int end, int l, int h, float distance);

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

    // Frames de l'attaque
    /**
    *   Nombre de frames de début de l'attaque
    */
    int m_startUpFrame;

    /**
    *   Nombre de frames actives de l'attaque (faisant des dégats)
    */
    int m_activeFrame;

    /**
    *   Nombre de frames de fin de l'attaque
    */
    int m_endFrame;

    float m_distance;
};

#endif
