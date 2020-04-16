#pragma once
#include "SFML/Graphics.hpp"

class Textbox
{
public:
	Textbox();
	void create();
	int getValue();
private:
	sf::RectangleShape box;
	sf::Text text;
};

