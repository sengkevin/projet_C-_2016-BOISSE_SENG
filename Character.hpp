#ifndef _CHARAC_H
#define _CHARAC_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

/**
 *  Classe personnages
 *  Joueur + ennemis
 *
 *  @author kseng, mboisse
 */
class Character : public sf::Drawable , public sf::Transformable {
public:
		std::string toString() const;
        virtual void deplacement() = 0;

		/**
		*	Teste si ce personnage est en vie
		*/
		void isAlive(){ setAlive((m_hp>0)? true : false); }

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

		double getSpeed(void){ return m_speed; }
		void setSpeed(double speed){ m_speed = speed; }
		void setAlive(bool state){ m_alive = state; }
protected:
		void goLeft(){ move(-m_speed, 0); }
		void goRight(){ move(m_speed, 0); }
		void goUp(){ move(0, -m_speed); }
		void goDown(){ move(0, m_speed); }

		enum C_States{
			STANDING,
			WALKING
		};

		std::string m_nom;
        int m_hp;
        double m_speed;
		bool m_alive;

        sf::Texture m_texture;
        sf::Sprite m_sprite;
		sf::FloatRect m_hitbox;
		C_States m_cstate;
};

#endif
