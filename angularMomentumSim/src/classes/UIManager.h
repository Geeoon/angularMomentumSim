#pragma once
#include <SFML/Graphics.hpp>

class UIManager
{
public:
	UIManager(sf::Font font1);
private:
	sf::Font font;
	sf::Text title;
};

