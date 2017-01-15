#include <ctime>

#include "Citoyen.hpp"
#include "windowParam.hpp"

/**
 *  Constructeur d'Citoyen
 */
 Citoyen::Citoyen(int hp, float speed){
    m_texture.loadFromFile("img/sprite_electeur.png");
    setTexture(m_texture);
    setTextureRect(sf::IntRect(0,0,16,24));
    setOrigin(((getTextureRect().width)/2),((getTextureRect().height)/2));

    int posIni = rand()%4;

    switch(posIni){
        case 0:
            setPosition(0, rand()%W_HEIGHT);
            break;
        case 1:
            setPosition(W_WIDTH, rand()%W_HEIGHT);
            break;
        case 2:
            setPosition(rand()%W_WIDTH, 0);
            break;
        case 3:
            setPosition(rand()%W_WIDTH, 0);
            break;
    }

    m_hp = hp;
    setAlive(true);

    m_speed = speed;

    m_distance = 0;
    m_dirX = 0;
    m_dirY = 0;
}

/**
 *  Deplacement des Citoyens
 */
void Citoyen::deplacement(){
    /* Définition de la rotation du personnage selon la direction de son déplacement */
    int rotation[3][3] = {
        { -135, -90, -45 },
        { 180,  0, 0 },
        { 135,  90,  45}
    };

    if(m_distance <= 0)
    {
        m_distance = 500 + rand() % 300; // déplacement aléatoire durant 500 à 799 frames
        // Direction aléatoire
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
}

void Citoyen::animationDraw(){
    static int i = 0;
    // On déplace le sprite sur la texture pour obtenir la frame suivante de l'animation
    setTextureRect(sf::IntRect(i*16,0,16,24));
    i = (i+1) % 7;
}
