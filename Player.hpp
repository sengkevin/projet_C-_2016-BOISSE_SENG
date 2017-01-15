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

    /**
     *  Gestion des entrées clavier / souris
     */
     void getInputs();

    /**
     *  Rotation du personnage vers le pointeur de la souris
     *
     *  @param window
     *          Fenêtre de jeu
     */
    void rotation(sf::RenderWindow& window);

    /**
     *  Gestion des attaques du joueur
     *
     *  @param index
     *          Nom de l'attaque déclenchée
     *  @param window
     *          Fenêtre de jeu
     *  @param gameClock
     *          Horloge du jeu
     *  @param charList
     *          Liste des personnages du jeu
     */
    void attaque(const std::string& index, sf::RenderWindow& window, sf::Clock& gameClock, std::vector<Character*> charList);

    /**
     *  Gestion de l'état du personnage (marche, arrêt, attaque)
     *
     *  @param window
     *          Fenetre du jeu
     *  @param gameClock
     *          Horloge du jeu
     *  @param charList
     *          Liste des personnages du jeu
     */
    void stateHandler(sf::RenderWindow& window, sf::Clock& gameClock, std::vector<Character*> charList);

    virtual void deplacement();
    virtual void animationDraw() = 0;

    enum C_States{
        STANDING,
        WALKING,
        PUNCH,
        KICK
    };

    void setNState(C_States state){ m_nstate = state; }

    int getHealRate(){ return m_healRate; }

    /**
     *  Test si un déplacement fait sortir de l'écran
     */
    bool canGoLeft(){ return(getPosition().x - m_speed > 0 ); }
    bool canGoRight(){ return(getPosition().x + m_speed < W_WIDTH); }
    bool canGoUp(){ return(getPosition().y - m_speed > 0); }
    bool canGoDown(){ return(getPosition().y + m_speed < W_HEIGHT); }

protected:
    std::map<std::string, Attaque*> m_attaques;
    double m_walkSpeed;
    int m_healRate;

    /**
     *  Calcul de l'angle de rotation nécessaire pour tourner le personnage vers le pointeur de la souris
     *
     *  @param window
     *          Fenêtre de jeu
     *
     *  @return float angle
     *          Angle de rotation
     */
    const float getAngleToMouse(sf::RenderWindow& window){
        sf::Vector2f c_m = (sf::Vector2f)sf::Mouse::getPosition(window);
        sf::Vector2f c_p = getPosition();
        return atan2((c_m.y - c_p.y),(c_m.x - c_p.x));
    }

    /**
     *  Calcul des coordonnées d'un point à une distance donnée du personnage vers la souris
     *
     *  @param distance
     *          Distance du point par rapport au personnage
     *  @param window
     *          Fenêtre de jeu
     *
     *  @return sf::Vector2f coords
     *          Coordonnées du point
     */
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
