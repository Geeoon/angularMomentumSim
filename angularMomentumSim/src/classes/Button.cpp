#include "Button.h"
#include <iostream>
Button::Button() {

}

Button::Button(std::string text1, int size, sf::Font& font) {
	create(text1, size, font);
}

void Button::create(std::string text1, int size, sf::Font& font) {
	text.setFont(font);
	text.setString(text1);
	text.setCharacterSize(size);
	text.setFillColor(sf::Color(0, 255, 65));
	button.setFillColor(sf::Color::Black);
	button.setOutlineColor(sf::Color(0, 255, 65));
	button.setOutlineThickness(2);
	resize();
}
void Button::setFont(sf::Font font) {
	text.setFont(font);
	resize();
}

void Button::setFontSize(int size) {
	text.setCharacterSize(size);
	resize();
}

void Button::draw(sf::RenderWindow &window) {
	window.draw(button);
	window.draw(text);
}

void Button::resize() {
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
	button.setSize(sf::Vector2f(text.getLocalBounds().width + 13, text.getLocalBounds().height + 13));
	button.setOrigin(text.getLocalBounds().width / 2 + 5, text.getLocalBounds().height / 2);
}

void Button::setPosition(double x, double y) {
	button.setPosition(x, y);
	text.setPosition(x, y);
}

bool Button::isClicked(sf::RenderWindow &window) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && button.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
		if (firstClick == true) {
			firstClick = false;
			return true;			
		} else {
			return false;
		}
		
	} else {
		firstClick = true;
	}
	return false;
}