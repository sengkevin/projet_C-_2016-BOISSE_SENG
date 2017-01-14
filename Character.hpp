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
class Character : public sf::Sprite {
public:
		std::string toString() const;
        virtual void deplacement() = 0;
		virtual void animationDraw() = 0;

		/**
		*	Teste si ce personnage est en vie
		*/
		void testAlive(){ setAlive((m_hp>0)? true : false); }

//		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

		double getSpeed(void){ return m_speed; }
		void setSpeed(double speed){ m_speed = speed; }
		void setAlive(bool state){ m_alive = state; }
		bool isAlive(){ return m_alive; }
		bool isInBound(sf::RenderWindow& window){
			return (getPosition().x >= 0 && getPosition().x <= window.getSize().x && getPosition().y >= 0 && getPosition().y < window.getSize().y);
		}
		void damage(int degats){
			m_hp -= degats;
			testAlive();
		}
		int getHp(){ return m_hp; }

		sf::FloatRect getHitbox(){ return getGlobalBounds(); }

protected:
		void goLeft(){ move(-m_speed, 0); }
		void goRight(){ move(m_speed, 0); }
		void goUp(){ move(0, -m_speed); }
		void goDown(){ move(0, m_speed); }

		std::string m_nom;
        int m_hp;
        double m_speed;

		bool m_alive;
		bool m_inAnimation;

        sf::Texture m_texture;
        sf::Sprite m_sprite;
};

#endif
