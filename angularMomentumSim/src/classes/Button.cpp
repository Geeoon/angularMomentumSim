#include "Button.h"

Button::Button() {

}

Button::Button(std::string text1, int size, sf::Font font) {
	text.setFont(font);
	text.setString(text1);
	text.setCharacterSize(size);
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

}