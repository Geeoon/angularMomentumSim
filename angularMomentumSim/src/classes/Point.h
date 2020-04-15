#pragma once
class Point
{
public:
	Point();
	Point(double x, double y);
	void setX(double x);
	void setY(double y);
	void set(double x, double y);
	double getX();
	double getY();
private:
	double xPosition;
	double yPosition;
};

