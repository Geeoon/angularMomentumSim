#include <iostream>
#include <SFML/Graphics.hpp>
#include "classes/Satellite.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Angular Momentum Visualizer");
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();

		window.display();
	}
	return 0;
}