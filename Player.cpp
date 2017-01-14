#include <cmath>

#include "Player.hpp"

/**
 *  Constructeur du joueur
 */
Player::Player() : m_walkSpeed(0.2f){
    /* Chargement texture et sprite du personnage */
    m_texture.loadFromFile("player_sprite.png");
    setTexture(m_texture);
    setTextureRect(sf::IntRect(0,0,20,25));
    setScale(3,3);
    setOrigin(((getTextureRect().width)/2),((getTextureRect().height)/2));

    m_cstate = STANDING;
    m_speed = m_walkSpeed;
    m_canAttack = true;

    m_attaques["Punch"] = new Attaque(1,sf::seconds(3.0f),1,4,0,40,30,30);
    m_attaques["Kick"] = new Attaque(2,sf::seconds(2.0f),2,2,2,40,30,30);
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
    static sf::Time lastAttack = sf::seconds(0);
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
                std::cout << "Touche" << std::endl;
            }
        }

        frames++;
    }
    else if(frames < startF + activeF + endF){
        frames ++;
    }
    else{
        lastAttack = gameClock.getElapsedTime();
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
                m_speed = m_walkSpeed/2;
                attaque("Kick", window, gameClock, charList);
                break;
        }

//        std::cout << getHitbox().top << std::endl;
}

void Player::animationDraw(){
    static int i = 0;
    static bool animationEnd = true;

    sf::Vector2f dimensions;

    if(m_nstate != m_cstate && animationEnd){
        i = 0;
        m_cstate = m_nstate;
    }

    switch(m_cstate){
        case STANDING:
            dimensions.x = 20;
            dimensions.y = 25;
            setTextureRect(sf::IntRect(0,0,dimensions.x,dimensions.y));
            break;

        case WALKING:
            dimensions.x = 20;
            dimensions.y = 25;
            setTextureRect(sf::IntRect(i*dimensions.x,0,dimensions.x,dimensions.y));
            i = (i+1) % 8;
            break;

        case PUNCH:
            animationEnd = false;
            dimensions.x = 38;
            dimensions.y = 25;
            setTextureRect(sf::IntRect(i*dimensions.x,dimensions.y,dimensions.x,dimensions.y));
            i = (i+1)%5;
            break;

        case KICK:
            animationEnd = false;
            dimensions.x = 38;
            dimensions.y = 25;
            setTextureRect(sf::IntRect(i*dimensions.x,2*dimensions.y,dimensions.x,dimensions.y));
            i = (i+1)%6;
            break;
    }

    if(i==0)
        animationEnd = true;
}

/**
 *  Affichage du personnage joueur
 */
 /*
void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    states.texture = &m_texture;
    target.draw(m_sprite, states);
}
*/
