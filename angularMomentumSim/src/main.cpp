#include <iostream>
#include <SFML/Graphics.hpp>
#include "classes/SatelliteManager.h"
#include "classes/UIManager.h"

int main() {
	SatelliteManager satelliteMan;
	satelliteMan.addSatellite(500, 200, 100);
	UIManager ui;
	
	//sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Angular Momentum Visualizer");
	//window.setFramerateLimit(100);
	/*
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

		satelliteMan.update();

		window.clear();
		satelliteMan.draw(window);
		window.display();
	}
	*/

	while (ui.isUIOpen()) {
		ui.update();
		satelliteMan.update();
		ui.getWindow().clear();
		ui.draw();
		satelliteMan.draw(ui.getWindow());
		ui.getWindow().display();
	}

	return 0;
}