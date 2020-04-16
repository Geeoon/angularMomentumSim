#pragma once
#include <SFML/Graphics.hpp>

class Button
{
public:
	Button();
	Button(std::string text1, int size, sf::Font& font);
	void create(std::string text1, int size, sf::Font& font);
	void setFont(sf::Font font1);
	void setFontSize(int size);
	void draw(sf::RenderWindow &window);
	void setPosition(double x, double y);
	bool isClicked(sf::RenderWindow &window);
private:
	void resize();
	bool firstClick = true;
	sf::RectangleShape button;
	sf::Text text;
};

