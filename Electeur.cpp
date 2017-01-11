#include <ctime>

#include "Electeur.hpp"

/**
 *  Constructeur d'electeur
 */
Electeur::Electeur(){
    m_texture.loadFromFile("usflag.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(sf::IntRect(0,0,30,30));
    setOrigin(15,15);
    setPosition(std::rand()%800,std::rand()%600);
    m_hitbox = m_sprite.getGlobalBounds();
    m_speed = 0.2f;
}

/**
 *  Deplacement des electeurs
 */
void Electeur::deplacement(){

}

/**
 *  Affichage des electeurs
 */
void Electeur::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    states.texture = &m_texture;
    target.draw(m_sprite, states);
}
