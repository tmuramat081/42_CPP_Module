#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
	Point::Point();
	explicit Point::Point(Fixed x, Fixed y);
	Point(const Point &);
	Point::~Point();

	Point &operator=(const Point &p);

private:
	Fixed x;
	Fixed y;
};

#endif