#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
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
	sf::Text controls;
	sf::Text stats;
	Button newSatellite;
	std::vector<Button> select;
	int selectedSat = 0;
};

