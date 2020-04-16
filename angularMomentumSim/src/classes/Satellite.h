#pragma once
#include <SFML/Graphics.hpp>
#include "Point.h"
#include "Vector.h"
#include <cmath>
#include <iostream>

# define M_PI           3.14159265358979323846  /* pi */

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
	void setAngularVelocity(double v);
	void draw(sf::RenderWindow &window);
	void update();
	double getAngle();
private:
	double toRad(double deg);
	double toDeg(double rad);
	double radius; //meters
	double mass; //kg
	double velocity; //regular velocity
	double angularVelocity; //vector is always pointing down (away from user) (in degrees / second)
	double momentum;
	double inertia;
	double currentAngle;
	bool isTethered;
	sf::CircleShape circle;
	Point cOfRotation;
	Point currentPosition;
	Vector instantVel;
	Vector centripetal;
	Vector resultant;
	sf::Time elapsedTime;
	sf::Clock clock;
};

