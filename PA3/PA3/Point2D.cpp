#include <iostream>
#include "Point2D.h"
#include <cmath>
using namespace std;

Point2D::Point2D(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}

double GetDistanceBetween(Point2D p1, Point2D p2)
{
	double xd = p2.x - p1.x;
	double yd = p2.y - p1.y;
	double distance = (pow(xd, 2) + pow(yd, 2));
	return distance;
}