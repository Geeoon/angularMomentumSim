#include "Vector.h"

Vector::Vector(double d, double m) {
	direction = d;
	magnitude = m;
}

void Vector::setDirection(double d) {
	direction = d;
}

void Vector::setMagnitude(double m) {
	magnitude = m;
}

double Vector::getDirection() {
	return direction;
}

double Vector::getMagnitude() {
	return magnitude;
}