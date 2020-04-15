#include "Satellite.h"

Satellite::Satellite(double ma, double mo, double v, double r) {
	mass = ma;
	momentum = mo;
	velocity = v;
	radius = r;
	circle.setRadius(mass * 0.5);
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

void Satellite::setRadius(double r) {
	radius = r;
}

void Satellite::setVelocity(double v) {
	velocity = v;
}

void Satellite::setMomentum(double m) {
	momentum = m;
}

void Satellite::draw(sf::RenderWindow &window) {
	window.draw(circle);
}