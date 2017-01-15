#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>
#include <X11/Xlib.h>
#include <ctime>

#include "GameInc.hpp"

int main(int argc, char* argv[]){
	XInitThreads();
	std::srand(std::time(0));

	sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), "Fight for the country");
	/* Desactivation contexte OpenGL */
	window.setActive(false);

	// Liste de tous les personnages
	std::vector<Character*> charList;
	charList.clear();

	sf::Clock gameClock;

	// Création du thread de l'application
	App application(std::ref(window), std::ref(gameClock), std::ref(charList));
	std::thread t_window(gameLoop, std::ref(application));

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
