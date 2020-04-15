#include <iostream>
#include <SFML/Graphics.hpp>
#include "classes/SatelliteManager.h"

int main() {
	SatelliteManager satteliteMan;
	satteliteMan.addSatellite(500, 200, 100);

	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Angular Momentum Visualizer");
	window.setFramerateLimit(100);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Resized)
			{
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
			}
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		satteliteMan.update();

		window.clear();
		satteliteMan.draw(window);
		window.display();
	}
	return 0;
}