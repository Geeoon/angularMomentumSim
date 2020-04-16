#include "Vector.h"
#include <cmath>
# define M_PI           3.14159265358979323846  /* pi */

Vector::Vector() {

}

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

double Vector::deltaX() {
	return magnitude * cos(direction * M_PI / 180);
}

double Vector::deltaY() {
	return magnitude * sin(direction * M_PI / 180);
}