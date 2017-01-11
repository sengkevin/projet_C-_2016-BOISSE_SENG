#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>
#include <X11/Xlib.h>
#include <ctime>

#include "GameInc.hpp"

#define WIDTH 	800
#define HEIGHT	600

int main(int argc, char* argv[]){
	XInitThreads();

	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Title");
	/* Desactivation contexte OpenGL */
	window.setActive(false);
	std::thread t_window(gameLoop, std::ref(window));

	std::srand(std::time(0));

	while(window.isOpen()){
		/* EVENT POLLING */
		sf::Event event;
		while(window.pollEvent(event)){
			switch(event.type){
				case sf::Event::Closed :
					window.close();
					break;

				default :
					break;
			}
		}
	}

	t_window.join();

	return 0;
}
