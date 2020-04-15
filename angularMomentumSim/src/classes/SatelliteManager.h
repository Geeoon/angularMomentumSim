#pragma once
#include <vector> 
#include "Satellite.h"

class SatelliteManager
{
public:
	SatelliteManager();
	void addSatellite(double ma, double aV, double r);
	void update();
	void draw(sf::RenderWindow &window);
	void drawCenter(sf::RenderWindow &window);
private:
	std::vector<Satellite> satellites;
	std::vector<sf::RectangleShape> tether;
	sf::CircleShape center;
};

