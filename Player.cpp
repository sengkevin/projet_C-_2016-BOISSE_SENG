#include <cmath>

#include "Player.hpp"

/**
 *  Constructeur du joueur
 */
Player::Player(){
    /* Chargement texture et sprite du personnage */
    m_texture.loadFromFile("player_sprite.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(sf::IntRect(0,0,64,64));
    setOrigin(32,32);

    m_cstate = STANDING;
    m_hitbox = m_sprite.getGlobalBounds();
    m_speed = 0.2f;
}

/**
 * Deplacement du joueur a partir des entrees clavier
 */
void Player::deplacement(){
    m_cstate = STANDING;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        goLeft();
        m_cstate = WALKING;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        goRight();
        m_cstate = WALKING;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        goUp();
        m_cstate = WALKING;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        goDown();
        m_cstate = WALKING;
    }
}

/**
 *  Rotation du joueur vers la souris
 *
 *  @param window
 *          Fenetre de jeu
 */
void Player::rotation(sf::RenderWindow& window){
    float rot;
    sf::Vector2f c_m, c_p;

    c_m = (sf::Vector2f)sf::Mouse::getPosition(window);
    c_p = getPosition();

    rot = (atan2((c_m.y - c_p.y),(c_m.x - c_p.x))*180/M_PI) + 90;
    /* Le sprite est tourné vers le haut de base
        On ajoute une rotation de 90 degres pour l'aligner
    */

    setRotation(rot);
}

/**
 *  Attaque du joueur
 */
void Player::attaque(){

}

void Player::stateHandler(sf::Clock& gameClock){
    static int i = 0;

    if(gameClock.getElapsedTime().asMilliseconds() % 66 == 0){
        switch(m_cstate){
            case STANDING:
                i = 0;
                m_sprite.setTextureRect(sf::IntRect(0,0,64,64));
                break;

            case WALKING:
                m_sprite.setTextureRect(sf::IntRect(i*64,0,64,64));
                i = (i+1)%8;
                break;
        }
    }
}

/**
 *  Affichage du personnage joueur
 */
void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    states.texture = &m_texture;
    target.draw(m_sprite, states);
}
