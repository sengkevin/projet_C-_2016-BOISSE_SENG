#include <cmath>

#include "Player.hpp"

Player::Player(){
    m_texture.loadFromFile("usflag.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(sf::IntRect(0,0,30,30));
    setOrigin(15,15);

    m_hitbox = m_sprite.getGlobalBounds();
    m_speed = 0.2f;
}

void Player::deplacement(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        goLeft();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        goRight();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        goUp();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        goDown();
    }
}

void Player::direction(sf::RenderWindow& window){
    float rot;
    sf::Vector2f c_m, c_p;

    c_m = (sf::Vector2f)sf::Mouse::getPosition(window);
    c_p = getPosition();

    rot = atan2((c_m.y - c_p.y),(c_m.x - c_p.x))*180/M_PI;

    setRotation(rot);
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    states.texture = &m_texture;
    target.draw(m_sprite, states);
}
