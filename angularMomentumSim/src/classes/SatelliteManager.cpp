#include "SatelliteManager.h"

SatelliteManager::SatelliteManager() {

}

void SatelliteManager::addSatellite(double ma, double aV, double r) {
	satellites.push_back(Satellite(ma, aV, r));
}

void SatelliteManager::update() {
	for (size_t i = 0; i < satellites.size(); i++) {
		satellites[i].update();
	}
}