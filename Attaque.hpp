#ifndef _ATTAQUE_H
#define _ATTAQUE_H

#include <SFML/Graphics.hpp>

class Attaque : public sf::Drawable , public sf::Transformable{
public:
    Attaque(int degats, sf::Time lifetime, const std::string& textureFile, int l, int h);
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::FloatRect m_hitbox;

    int m_degats;
    sf::Time m_lifetime;
};

#endif
