#include "Point.h"


Point::Point() {
	xPosition = 0;
	yPosition = 0;
}

Point::Point(double x, double y) {
	xPosition = x;
	yPosition = y;
}

void Point::setX(double x) {
	xPosition = x;
}

void Point::setY(double y) {
	yPosition = y;
}

void Point::set(double x, double y) {
	xPosition = x;
	yPosition = y;
}

double Point::getX() {
	return yPosition;
}

double Point::getY() {
	return xPosition;
}