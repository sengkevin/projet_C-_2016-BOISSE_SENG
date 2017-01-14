
#include "Attaque.hpp"

Attaque::Attaque(int degats, sf::Time cooldown, int startup, int activeFrame, int endFrame, int l, int h, float distance):
                                                    m_degats(degats),
                                                    m_cooldown(cooldown),
                                                    m_startUpFrame(startup),
                                                    m_activeFrame(activeFrame),
                                                    m_endFrame(endFrame),
                                                    m_distance(distance){
    //m_texture.create(l, h);
    m_texture.loadFromFile("usflag.png");
    setTexture(m_texture);
    setTextureRect(sf::IntRect(0,0,l,h));
}

/*
void Attaque::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();
    states.texture = &m_texture;
    target.draw(m_sprite, states);
}
*/
