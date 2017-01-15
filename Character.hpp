#ifndef _CHARAC_H
#define _CHARAC_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

/**
 *  Classe personnages
 *  Toutes les entités personnages
 *
 *  @author kseng, mboisse
 */
class Character : public sf::Sprite {
public:

	    /**
	     *  Gestion du déplacement du personnage
	     */
        virtual void deplacement() = 0;

		/**
	     *  Gestion de l'animation du personnage
	     */
		virtual void animationDraw() = 0;

		/**
		*	Teste si ce personnage est en vie
		*/
		void testAlive(){
			if (m_hp>0){
				m_alive = true;
			}
			else{
				m_hp = 0;
				m_alive = false;
			}
		}

		std::string getNom(void){ return m_nom; }
		double getSpeed(void){ return m_speed; }
		void setSpeed(double speed){ m_speed = speed; }
		void setAlive(bool state){ m_alive = state; }
		bool isAlive(){ return m_alive; }
		/**
		 *	Teste si le personnage est dans l'écran
		 */
		bool isInBound(sf::RenderWindow& window){
			return (getPosition().x >= 0 && getPosition().x <= window.getSize().x && getPosition().y >= 0 && getPosition().y < window.getSize().y);
		}

		void damage(int degats){
			m_hp -= degats;
			testAlive();
		}

		void addHp(int pts){
			if((m_hp+pts) <= 100)
				m_hp += pts;
			else
			 	m_hp = 100;
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
		bool m_inAnimation; // Le personnage est en cours d'animation

        sf::Texture m_texture;
        sf::Sprite m_sprite;
};

#endif
