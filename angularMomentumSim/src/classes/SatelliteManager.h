#pragma once
#include <vector> 
#include "Satellite.h"

class SatelliteManager
{
public:
	SatelliteManager();
	void addSatellite(double ma, double aV, double r);
	void update(sf::RenderWindow &window);
	void changeRadius(int index, double radius);
	void draw(sf::RenderWindow &window);
	void drawCenter(sf::RenderWindow &window);
	void highlight(bool h, int index);
	void input(int index);
	Satellite getSatellite(int index);
	int size();
private:
	std::vector<Satellite> satellites;
	std::vector<sf::RectangleShape> tether;
	sf::CircleShape center;
	sf::Time elapsedTime;
	sf::Clock clock;
};

