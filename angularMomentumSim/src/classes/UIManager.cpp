#include "UIManager.h"

UIManager::UIManager() {
	window.create(sf::VideoMode(800, 600, 32), "Angular Momentum Visualizer");
	window.setFramerateLimit(100);
	if (!font.loadFromFile("src/fonts/SourceCodePro.ttf")) {
		//unable to load font
	}
	title.setFont(font);
	title.setString("Visualization of Angular Momentum");
	title.setCharacterSize(24);
	title.setFillColor(sf::Color(0, 255, 65));
	title.setOrigin(title.getLocalBounds().width / 2, title.getLocalBounds().height / 2);
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
	title.setPosition(window.getSize().x / 2, 20);
}

void UIManager::draw() {
	window.draw(title);
}

sf::RenderWindow& UIManager::getWindow() {
	return window;
}

bool UIManager::isUIOpen() {
	return window.isOpen();
}