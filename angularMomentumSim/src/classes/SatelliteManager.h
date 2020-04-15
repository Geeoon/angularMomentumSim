#pragma once
#include <vector> 
#include "Satellite.h"

class SatelliteManager
{
public:
	SatelliteManager();

	void addSatellite(double ma, double aV, double r);

	void update();
private:
	std::vector<Satellite> satellites;
};

