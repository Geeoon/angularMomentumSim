#include "Vector.h"

Vector::Vector(double d, double m) {
	direction = d;
	magnitude = m;
}

void Vector::setDirection(double d) {
	direction = d;
}

void Vector::setMagnitude() {
	magnitude = m;
}

void Vector::getDirection() {
	return direction;
}

void Vector::getMagnitude() {
	return magnitude;
}