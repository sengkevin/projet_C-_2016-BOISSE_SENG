#ifndef _PLAYER_H
#define _PLAYER_H

#include <cmath>

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
    virtual void deplacement();
    void getInputs();
    void rotation(sf::RenderWindow& window);
    void attaque(const std::string& index, sf::RenderWindow& window, sf::Clock& gameClock, std::vector<Character*> charList);

    /**
    *	Test de l'etat du personnage (marche, arret)
    */
    void stateHandler(sf::RenderWindow& window, sf::Clock& gameClock, std::vector<Character*> charList);
    void animationDraw();

//    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    enum C_States{
        STANDING,
        WALKING,
        PUNCH,
        KICK
    };

private:
    const double m_walkSpeed;
    std::map<std::string, Attaque*> m_attaques;

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
