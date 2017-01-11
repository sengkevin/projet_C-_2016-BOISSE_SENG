#ifndef _CHARAC_H
#define _CHARAC_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Character : public sf::Drawable , public sf::Transformable {
public:
		std::string toString() const;
        virtual void deplacement() = 0;

		double getSpeed(void){ return m_speed; }
		void setSpeed(double speed){ m_speed = speed; }

protected:
		std::string m_nom;
        int m_hp;
        double m_speed;

        sf::Texture m_texture;
        sf::Sprite m_sprite;
		sf::FloatRect m_hitbox;
};

#endif
