#include <iostream>
#include <SFML/Graphics.hpp>
#include "classes/Satellite.h"

int main() {
	Satellite object(500, 10, 200); //delete later
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Angular Momentum Visualizer");

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



		//For testing, delete later

		object.update();

		//For testing, delete later


		window.clear();
		object.draw(window);
		window.display();
	}
	return 0;
}