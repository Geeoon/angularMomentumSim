#include "SatelliteManager.h"

SatelliteManager::SatelliteManager() {
	center.setRadius(5);
	center.setFillColor(sf::Color::Black);
	center.setOutlineThickness(3);
	center.setOutlineColor(sf::Color::White);
	center.setOrigin(center.getLocalBounds().height / 2, center.getLocalBounds().width / 2);
}

void SatelliteManager::addSatellite(double ma, double aV, double r) {
	satellites.push_back(Satellite(ma, aV, r));
	tether.push_back(sf::RectangleShape(sf::Vector2f(1, r)));
	tether.back().setOrigin(0, 0);
}

void SatelliteManager::update() {
	for (size_t i = 0; i < satellites.size(); i++) {
		satellites[i].update();
		tether[i].setRotation(satellites[i].getAngle() - 90);
	}
}

void SatelliteManager::draw(sf::RenderWindow &window) {
	for (size_t i = 0; i < satellites.size(); i++) {
		satellites[i].draw(window);
		window.draw(tether[i]);
		tether[i].setPosition(window.getSize().x / 2 - 2, window.getSize().y / 2 - 3);
	}
	drawCenter(window);
}

void SatelliteManager::drawCenter(sf::RenderWindow &window) {
	center.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	window.draw(center);
}