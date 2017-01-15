#ifndef _PLAYER_H
#define _PLAYER_H

#include <cmath>

#include "Character.hpp"
#include "Attaque.hpp"
#include "windowParam.hpp"

/**
 *  Classe joueur
 *
 *  @author kseng, mboisse
 */
class Player : public Character{
public:
    Player();
    virtual void deplacement();
    void getInputs();
    void rotation(sf::RenderWindow& window);
    void attaque(const std::string& index, sf::RenderWindow& window, sf::Clock& gameClock, std::vector<Character*> charList);

    /**
    *	Test de l'etat du personnage (marche, arret)
    */
    void stateHandler(sf::RenderWindow& window, sf::Clock& gameClock, std::vector<Character*> charList);
    virtual void animationDraw() = 0;

    enum C_States{
        STANDING,
        WALKING,
        PUNCH,
        KICK
    };

    void setNState(C_States state){ m_nstate = state; }

    int getHealRate(){ return m_healRate; }

    bool canGoLeft(){ return(getPosition().x - m_speed > 0 ); }
    bool canGoRight(){ return(getPosition().x + m_speed < W_WIDTH); }
    bool canGoUp(){ return(getPosition().y - m_speed > 0); }
    bool canGoDown(){ return(getPosition().y + m_speed < W_HEIGHT); }

protected:
    std::map<std::string, Attaque*> m_attaques;
    double m_walkSpeed;
    int m_healRate;

    const float getAngleToMouse(sf::RenderWindow& window){
        sf::Vector2f c_m = (sf::Vector2f)sf::Mouse::getPosition(window);
        sf::Vector2f c_p = getPosition();
        return atan2((c_m.y - c_p.y),(c_m.x - c_p.x));
    }

    const sf::Vector2f getCoordsToMouse(int distance, sf::RenderWindow& window){
        sf::Vector2f coords;
        float angle = getAngleToMouse(window);
        coords.x = cos(angle) * distance + getPosition().x;
        coords.y = sin(angle) * distance + getPosition().y;
        return coords;
    }

	C_States m_cstate;
	C_States m_nstate;

    bool m_canAttack;
};


#endif
