//Made by Geeoon Chung
#include <iostream>
#include <SFML/Graphics.hpp>
#include "classes/SatelliteManager.h"
#include "classes/UIManager.h"

int main() {
	SatelliteManager satelliteMan;
	UIManager ui;
	while (ui.isUIOpen()) {
		//update stuff
		ui.update(satelliteMan);
		satelliteMan.update(ui.getWindow());

		//drawing stuff
		ui.getWindow().clear();

		ui.draw();
		satelliteMan.draw(ui.getWindow());

		ui.getWindow().display();
	}

	return 0;
}