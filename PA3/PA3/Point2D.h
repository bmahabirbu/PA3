#pragma once
#include <iostream>
using namespace std;

class Point2D
{
public:
	double x;
	double y;
	Point2D(double in_x, double in_y);
};

double GetDistanceBetween(Point2D p1, Point2D p2);