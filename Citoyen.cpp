#include <ctime>

#include "Citoyen.hpp"

/**
 *  Constructeur d'Citoyen
 */
 Citoyen::Citoyen(int hp){
    m_texture.loadFromFile("sprite_electeur.png");
    setTexture(m_texture);
    setTextureRect(sf::IntRect(0,0,16,24));
    setScale(2,2);
    setOrigin(((getTextureRect().width)/2),((getTextureRect().height)/2));
    setPosition(std::rand()%800,std::rand()%600);

    m_hp = hp;
    setAlive(true);

    m_distance = 0;
    m_dirX = 0;
    m_dirY = 0;

    m_speed = 0.15f;
}

/**
 *  Deplacement des Citoyens
 */
void Citoyen::deplacement(){
    int rotation[3][3] = {
        { -135, -90, -45 },
        { 180,  0, 0 },
        { 135,  90,  45}
    };

    if(m_distance <= 0)
    {
        m_distance = 300 + rand() % 50; // distance aléatoire entre 3 et 10 frames
        m_dirX = rand()%3;
        m_dirY = rand()%3;
    }
    else
    {
        setRotation(0);

        m_distance --;
        switch(m_dirY){
            case 0:
                goUp();
                break;
            case 1:
                break;
            case 2:
                goDown();
                break;
        }
        switch(m_dirX){
            case 0:
                goLeft();
                break;
            case 1:
                break;
            case 2:
                goRight();
                break;
        }
    }

    setRotation(rotation[m_dirY][m_dirX]);

    if(getPosition().x <0 || getPosition().x > 800 || getPosition().y<0 || getPosition().y>600){
        setPosition(std::rand()%800,std::rand()%600);
        m_distance = 0;
    }
}

void Citoyen::animationDraw(){

}
