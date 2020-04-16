#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "SatelliteManager.h"
class UIManager
{
public:
	UIManager();
	void update(SatelliteManager& satelliteMan);
	void draw();
	sf::RenderWindow& getWindow();
	bool isUIOpen();
private:
	sf::RenderWindow window;
	sf::Font font;
	sf::Text title;
	Button newSatellite;
};

