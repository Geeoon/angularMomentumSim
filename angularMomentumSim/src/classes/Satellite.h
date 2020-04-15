#pragma once
#include <SFML/Graphics.hpp>

class Satellite
{
public:
	Satellite(double ma, double mo, double aV, double r);

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

private:
	double radius;
	double mass; //kg
	double velocity; //regular velocity
	double angularVelocity; //vector is always pointing up (toward user) (in radians / second)
	double momentum;
	double inertia;
	sf::CircleShape circle;
};

