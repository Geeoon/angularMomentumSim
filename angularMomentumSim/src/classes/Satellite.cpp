#include "Satellite.h"

Satellite::Satellite(double ma, double aV, double r) {
	create(ma, aV, r);
}

Satellite::~Satellite() {

}

void Satellite::create(double ma, double aV, double r) {
	mass = ma;
	angularVelocity = aV;
	radius = r;
	circle.setRadius((float)mass/20);
	circle.setFillColor(sf::Color::Black);
	circle.setOutlineColor(sf::Color(0, 255, 65));
	circle.setOutlineThickness(3);
	currentAngle = 90;
	cOfRotation.set(0, 0);
	currentPosition = cOfRotation;
	inertia = mass * (radius*radius) / 2; //kg * m^2
	momentum = inertia * angularVelocity;
	circle.setOrigin(circle.getLocalBounds().height / 2, circle.getLocalBounds().width / 2);
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
	window.draw(circle);
}

void Satellite::update(sf::RenderWindow &window) {
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
	cOfRotation.set(window.getSize().x / 2, window.getSize().y / 2);
	resultant.setDirection(toDeg(atanf(centripetal.getMagnitude() / instantVel.getMagnitude())));
	resultant.setMagnitude(sqrt((instantVel.getMagnitude() * instantVel.getMagnitude()) + (centripetal.getMagnitude() * centripetal.getMagnitude())));
	//currentPosition.set(resultant.getMagnitude() * sin(toRad(resultant.getDirection())) + cOfRotation.getX(), resultant.getMagnitude() * cos(toRad(resultant.getDirection())) + cOfRotation.getX());
	if (isTethered) {
		currentPosition.set(radius * sin(toRad(currentAngle)) + cOfRotation.getX(), radius * cos(toRad(currentAngle)) + cOfRotation.getY());
	} else {
		currentPosition.set(currentPosition.getX() + instantVel.deltaX(), currentPosition.getY() + instantVel.deltaY());
	}
	circle.setPosition((float) currentPosition.getX(), (float) currentPosition.getY());
}

void Satellite::highlight(bool h) {
	if (h == true) {
		circle.setOutlineColor(sf::Color::White);
	} else {
		circle.setOutlineColor(sf::Color(0, 255, 65));
	}
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

void Satellite::setMass(double m) {
	mass = m;
	circle.setRadius((float)mass / 20);
	circle.setOrigin(circle.getLocalBounds().width / 2, circle.getLocalBounds().height / 2);
}