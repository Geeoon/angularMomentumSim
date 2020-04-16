#pragma once
#include <SFML/Graphics.hpp>

class Button
{
public:
	Button();
	Button(std::string text, int size, sf::Font font1);
	void setFont(sf::Font font1);
	void setFontSize(int size);
	void draw(sf::RenderWindow &window);
private:
	void resize();
	sf::RectangleShape button;
	sf::Text text;
};

