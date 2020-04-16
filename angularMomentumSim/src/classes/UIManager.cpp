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

	controls.setFont(font);
	controls.setString("Press the left/right keys to change the speed\nPress the up/down keys to change the radius");
	controls.setCharacterSize(12);
	controls.setFillColor(sf::Color(0, 255, 65));
	controls.setOrigin(0, controls.getLocalBounds().height);
	controls.setPosition(20, 120);

	newSatellite.create("Add Satellite", 20, font);
}

void UIManager::update(SatelliteManager& satelliteMan) {
	satelliteMan.input(selectedSat);
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
	newSatellite.setPosition(100, 60);
	if (newSatellite.isClicked(window)) {
		satelliteMan.addSatellite(500, 200, 100);
		select.push_back(Button(("Satallite " + std::to_string(select.size() + 1)), 20, font));
		select.back().setPosition(120 + select.size() * 160, 60);
	}

	for (int i = 0; i < select.size(); i++) {
		if (select[i].isClicked(window)) {
			selectedSat = i;
		}
		if (i == selectedSat) {
			select[i].highlight(true);
			satelliteMan.highlight(true, i);
		} else {
			select[i].highlight(false);
			satelliteMan.highlight(false, i);
		}
	}
	
}

void UIManager::draw() {
	window.draw(title);
	window.draw(controls);
	newSatellite.draw(window);
	for (int i = 0; i < select.size(); i++) {
		select[i].draw(window);
	}
}

sf::RenderWindow& UIManager::getWindow() {
	return window;
}

bool UIManager::isUIOpen() {
	return window.isOpen();
}