
#include "Obama.hpp"

Obama::Obama() : Player(){
    m_texture.loadFromFile("img/sprite_obama.png");
    setTexture(m_texture);
    setTextureRect(sf::IntRect(0,0,16,24));
    setScale(2,2);
    setOrigin(((getTextureRect().width)/2),((getTextureRect().height)/2));

    m_nom = "Obama";
    m_walkSpeed = 0.28f;
    m_healRate = 8;
    m_hp = 80;

    m_attaques["Punch"] = new Attaque(10,1,4,0,10*getScale().x,10*getScale().y,20*getScale().x);
    m_attaques["Kick"] = new Attaque(30,2,2,2,15*getScale().x,15*getScale().y,20*getScale().x);
}

void Obama::animationDraw(){
    static int i = 0;
    sf::Vector2f dimensions;

    if(m_nstate != m_cstate && !m_inAnimation){
        m_cstate = m_nstate;
        i=0;
    }

    switch(m_cstate){
        case STANDING:
            dimensions.x = 16;
            dimensions.y = 24;
            setTextureRect(sf::IntRect(0,0,dimensions.x,dimensions.y));
            break;

        case WALKING:
            dimensions.x = 16;
            dimensions.y = 24;
            setTextureRect(sf::IntRect(i*dimensions.x,0,dimensions.x,dimensions.y));
            i = (i+1) % 8;
            break;

        case PUNCH:
            m_inAnimation = true;
            dimensions.x = 31;
            dimensions.y = 24;
            setTextureRect(sf::IntRect(i*dimensions.x,dimensions.y,dimensions.x,dimensions.y));
            i = (i+1)%5;
            break;

        case KICK:
            m_inAnimation = true;
            dimensions.x = 34;
            dimensions.y = 24;
            setTextureRect(sf::IntRect(i*dimensions.x,2*dimensions.y,dimensions.x,dimensions.y));
            i = (i+1)%6;
            break;
    }

    if(i==0)
        m_inAnimation = false;
}
