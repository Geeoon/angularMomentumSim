#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

class UIManager
{
public:
	UIManager();
	void update();
	void draw();
	sf::RenderWindow& getWindow();
	bool isUIOpen();
private:
	sf::RenderWindow window;
	sf::Font font;
	sf::Text title;
	Button newSatellite;
};

