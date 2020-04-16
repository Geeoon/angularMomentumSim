#pragma once
class Vector
{
public:
	Vector();
	Vector(double d, double m);
	void setDirection(double d);
	void setMagnitude(double m);
	double getDirection();
	double getMagnitude();
	double deltaX();
	double deltaY();
private:
	double direction;
	double magnitude;
};

