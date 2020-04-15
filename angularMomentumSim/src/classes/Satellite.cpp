#include "Satellite.h"

Satellite::Satellite(double ma, double aV, double r) {
	mass = ma;
	angularVelocity = aV;
	radius = r;
	circle.setRadius(sqrt(mass));
	
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
	window.draw(circle);
}