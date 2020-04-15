#include "Satellite.h"

Satellite::Satellite(double ma, double aV, double r) {
	mass = ma;
	angularVelocity = aV;
	radius = r;
	circle.setRadius((float)sqrt(mass));
	currentAngle = 90;
	cOfRotation.set(0, 0);
	currentPosition = cOfRotation;
	
}

Satellite::~Satellite() {

}

double Satellite::getRadius() {
	return radius;
}

double Satellite::getMass() {
	return mass;
}

double Satellite::getVelocity() {
	return velocity;
}

double Satellite::getMomentum() {
	return momentum;
}

double Satellite::getAngularVelocity() {
	return angularVelocity;
}

double Satellite::getInertia() {
	return inertia;
}

void Satellite::setRadius(double r) {
	radius = r;
}

void Satellite::setVelocity(double v) {
	velocity = v;
}

void Satellite::setMomentum(double m) {
	momentum = m;
}

void Satellite::setAngularVelocity(double v) {
	angularVelocity = v;
}

void Satellite::draw(sf::RenderWindow &window) {
	cOfRotation.set(window.getSize().x / 2, window.getSize().y / 2);
	window.draw(circle);
}

void Satellite::update() {
	elapsedTime = clock.getElapsedTime();
	clock.restart();
	currentAngle += angularVelocity * elapsedTime.asSeconds();
	

	if (abs(currentAngle / 360) > 1) {
		currentAngle = std::fmod(currentAngle, 360);
	}
	std::cout << currentAngle << std::endl;
	currentPosition.set(radius * sin(toRad(currentAngle)) + cOfRotation.getX(), radius * cos(toRad(currentAngle)) + cOfRotation.getY());
	circle.setPosition((float) currentPosition.getX(), (float) currentPosition.getY());
}

double Satellite::toRad(double deg) {
	return (deg * M_PI / 180);
}