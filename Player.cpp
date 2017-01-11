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
        move(-m_speed, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        move(m_speed, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        move(0, -m_speed);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        move(0, m_speed);
    }
}

void Player::direction(){

}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    states.texture = &m_texture;
    target.draw(m_sprite, states);
}
