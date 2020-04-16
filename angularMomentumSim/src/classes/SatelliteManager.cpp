#include "SatelliteManager.h"

SatelliteManager::SatelliteManager() {
	center.setRadius(5);
	center.setFillColor(sf::Color::Black);
	center.setOutlineThickness(3);
	center.setOutlineColor(sf::Color(0, 255, 65));
	center.setOrigin(center.getLocalBounds().height / 2, center.getLocalBounds().width / 2);
}

void SatelliteManager::addSatellite(double ma, double aV, double r) {
	satellites.push_back(Satellite(ma, aV, r));
	tether.push_back(sf::RectangleShape(sf::Vector2f(1, r)));
	tether.back().setOrigin(0, 0);
	tether.back().setFillColor(sf::Color(0, 255, 65));
}

void SatelliteManager::update(sf::RenderWindow &window) {
	elapsedTime = clock.getElapsedTime();
	clock.restart();
	for (size_t i = 0; i < satellites.size(); i++) {
		satellites[i].update(window);
		tether[i].setRotation(satellites[i].getAngle() - 90);
		tether[i].setSize(sf::Vector2f(1, satellites[i].getRadius()));
	}
}

void SatelliteManager::changeRadius(int index, double radius) {
	tether[index].setSize(sf::Vector2f(1, radius));
	satellites[index].setRadius(radius);
}

void SatelliteManager::draw(sf::RenderWindow &window) {
	for (size_t i = 0; i < satellites.size(); i++) {
		tether[i].setPosition(window.getSize().x / 2 - 2, window.getSize().y / 2 - 3);
		satellites[i].draw(window);
		window.draw(tether[i]);
	}
	drawCenter(window);
}

void SatelliteManager::drawCenter(sf::RenderWindow &window) {
	center.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	window.draw(center);
}

void SatelliteManager::highlight(bool h, int index) {
	satellites[index].highlight(h);
	if (h == true) {
		tether[index].setFillColor(sf::Color::White);
	} else {
		tether[index].setFillColor(sf::Color(0, 255, 65));
	}
}

void SatelliteManager::input(int index) {
	if (satellites.size() > 0) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			satellites[index].setRadius(satellites[index].getRadius() + 50 * elapsedTime.asSeconds());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			satellites[index].setRadius(satellites[index].getRadius() - 50 * elapsedTime.asSeconds());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			satellites[index].setAngularVelocity(satellites[index].getAngularVelocity() + 50 * elapsedTime.asSeconds());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			satellites[index].setAngularVelocity(satellites[index].getAngularVelocity() - 50000000 * elapsedTime.asSeconds());
		}
	}
}