#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
    Point v0 = a - c;
	Point v1 = a - b;
	Point v2 = a - p;

	Fixed dot00 = v0.dot(v0);
	Fixed dot01 = v0.dot(v1);
	Fixed dot02 = v0.dot(v2);
	Fixed dot11 = v1.dot(v1);
	Fixed dot12 = v1.dot(v2);

	Fixed innerDeno = Fixed(1) / (dot00 * dot11 - dot01 * dot01);

	Fixed u = (dot11 * dot02 - dot01 * dot12) * innerDeno;
	if (u < Fixed(0) || u > Fixed(1))
	{
		return false;
	}

	Fixed v = (dot00 * dot12 - dot01 * dot02) * innerDeno;
	if (v < Fixed(0) || v > Fixed(1))
	{
		return false;
	}
	return u + v <= Fixed(1);
}
