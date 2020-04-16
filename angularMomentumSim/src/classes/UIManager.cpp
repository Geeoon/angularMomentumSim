#include "UIManager.h"

UIManager::UIManager() {
	window.create(sf::VideoMode(800, 600, 32), "Angular Momentum Visualizer");
	window.setFramerateLimit(100);
	/*
	title.setFont(font);
	title.setString("Visualization of Angular Momentum by Geeoon Chung");
	title.setCharacterSize(24);
	title.setFillColor(sf::Color(0, 255, 65));
	*/
}

void UIManager::update() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Resized)
		{
			sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
			window.setView(sf::View(visibleArea));
		}
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}
}

void UIManager::draw() {

}

sf::RenderWindow& UIManager::getWindow() {
	return window;
}

bool UIManager::isUIOpen() {
	return window.isOpen();
}