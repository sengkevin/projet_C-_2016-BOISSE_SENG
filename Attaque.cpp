
#include "Attaque.hpp"

Attaque::Attaque(int degats, sf::Time lifetime, const std::string& textureFile, int l, int h): m_degats(degats), m_lifetime(lifetime){
    m_texture.loadFromFile(textureFile);
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(sf::IntRect(0,0,l,h));

    m_hitbox = m_sprite.getGlobalBounds(); 
}

void Attaque::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    states.texture = &m_texture;
    target.draw(m_sprite, states);
}
