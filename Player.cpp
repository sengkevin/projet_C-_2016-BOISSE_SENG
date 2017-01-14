#include <cmath>

#include "Player.hpp"

/**
 *  Constructeur du joueur
 */
Player::Player(){
    /* Chargement texture et sprite du personnage */
    m_cstate = STANDING;
    m_speed = m_walkSpeed;
    m_canAttack = true;
    setAlive(true);
}

/**
 * Deplacement du joueur a partir des entrees clavier
 */
void Player::deplacement(){
    m_nstate = STANDING;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        goLeft();
        m_nstate = WALKING;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        goRight();
        m_nstate = WALKING;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        goUp();
        m_nstate = WALKING;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        goDown();
        m_nstate = WALKING;
    }
}

void Player::getInputs(){
    deplacement();

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        m_nstate = PUNCH;
    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
        m_nstate = KICK;
    }

}

/**
 *  Rotation du joueur vers la souris
 *
 *  @param window
 *          Fenetre de jeu
 */
void Player::rotation(sf::RenderWindow& window){
    setRotation(getAngleToMouse(window)*180/M_PI);
}

/**
 *  Attaque du joueur
 */
void Player::attaque(const std::string& index, sf::RenderWindow& window, sf::Clock& gameClock, std::vector<Character*> charList){
    int atq_dist;
    static int frames = -1;

    int startF, activeF, endF;
    startF = m_attaques[index]->getStartupFrame();
    activeF = m_attaques[index]->getActiveFrame();
    endF = m_attaques[index]->getEndFrame();

    if(frames < startF){
        frames++;
        m_canAttack = false;
    }
    else if(frames < (startF + activeF)){
        atq_dist = m_attaques[index]->getDistance();

        sf::Vector2f atq_pos = getCoordsToMouse(atq_dist, window);

        m_attaques[index]->setPosition(atq_pos);
        m_attaques[index]->setRotation(getRotation());

        for(unsigned int i=1; i<charList.size(); i++){
            if(m_attaques[index]->getHitbox().intersects(charList[i]->getHitbox())){
                charList[i]->damage(m_attaques[index]->getDegats());
            }
        }
        frames++;
    }
    else if(frames < startF + activeF + endF){
        frames ++;
    }
    else{
        frames = 0;
    }
}

void Player::stateHandler(sf::RenderWindow& window, sf::Clock& gameClock, std::vector<Character*> charList){
    switch(m_cstate){
        case STANDING:
            break;

        case WALKING:
            m_speed = m_walkSpeed;
            break;

        case PUNCH:
            m_speed = m_walkSpeed/2;
            attaque("Punch", window, gameClock, charList);
            break;

        case KICK:
            m_speed = m_walkSpeed/4;
            attaque("Kick", window, gameClock, charList);
            break;
    }
}
