#include "Satellite.h"

Satellite::Satellite(double ma, double aV, double r) {
	mass = ma;
	angularVelocity = aV;
	radius = r;
	circle.setRadius((float)sqrt(mass));
	currentAngle = 90;
	cOfRotation.set(0, 0);
	currentPosition = cOfRotation;
	inertia = mass * (radius*radius) / 2; //kg * m^2
	momentum = inertia * angularVelocity;
	circle.setOrigin(circle.getLocalBounds().height / 2, circle.getLocalBounds().width / 2);
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
	inertia = mass * (radius*radius) / 2; //kg * m^2
	angularVelocity = momentum / inertia;
	currentAngle += angularVelocity * elapsedTime.asSeconds(); //added because of the right hand rule
	

	if (abs(currentAngle / 360) > 1) {
		currentAngle = std::fmod(currentAngle, 360);
	}

	instantVel.setDirection(currentAngle + 90);
	instantVel.setMagnitude(angularVelocity * radius);
	centripetal.setDirection(currentAngle + 180);
	centripetal.setMagnitude(mass * instantVel.getMagnitude() * instantVel.getMagnitude() / radius);

	resultant.setDirection(toDeg(atanf(centripetal.getMagnitude() / instantVel.getMagnitude())));
	resultant.setMagnitude(sqrt((instantVel.getMagnitude() * instantVel.getMagnitude()) + (centripetal.getMagnitude() * centripetal.getMagnitude())));
	//currentPosition.set(resultant.getMagnitude() * sin(toRad(resultant.getDirection())) + cOfRotation.getX(), resultant.getMagnitude() * cos(toRad(resultant.getDirection())) + cOfRotation.getX());
	currentPosition.set(radius * sin(toRad(currentAngle)) + cOfRotation.getX(), radius * cos(toRad(currentAngle)) + cOfRotation.getY());
	circle.setPosition((float) currentPosition.getX(), (float) currentPosition.getY());
}

double Satellite::toRad(double deg) {
	return (deg * M_PI / 180);
}

double Satellite::toDeg(double rad) {
	return (rad * 180 / M_PI);
}

double Satellite::getAngle() {
	return currentAngle;
}