#pragma once
#include <SFML/Graphics.hpp>

class Satellite
{
public:
	Satellite(double ma, double mo, double v, double r);

	~Satellite();

	double getRadius();

	double getMass();

	double getVelocity();

	double getMomentum();

	void setRadius(double r);

	void setVelocity(double v);

	void setMomentum(double m);
	void draw(sf::RenderWindow &window);

private:
	double radius;
	double mass; //kg
	double velocity;
	double momentum;
	sf::CircleShape circle;
};

