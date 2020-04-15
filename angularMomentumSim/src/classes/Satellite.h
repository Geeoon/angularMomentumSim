#pragma once
#include <SFML/Graphics.hpp>
#include "Point.h"

class Satellite
{
public:
	Satellite(double ma, double aV, double r);

	~Satellite();

	double getRadius();

	double getMass();

	double getVelocity();

	double getMomentum();

	double getAngularVelocity();

	double getInertia();

	void setRadius(double r);

	void setVelocity(double v);

	void setMomentum(double m);

	void setAngularVelocity(double v);

	void draw(sf::RenderWindow &window);

	void update();

private:
	double radius; //meters
	double mass; //kg
	double velocity; //regular velocity
	double angularVelocity; //vector is always pointing up (toward user) (in radians / second)
	double momentum;
	double inertia;
	sf::CircleShape circle;
	Point cOfRotation;
	Point currentPosition;
	sf::Time elapsedTime;
};

