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

	Point &operator=(const Point &other);

	Fixed dot(const Point &other) const;
	Fixed cross(const Point &other) const;
	Fixed getX() const;
	Fixed getY() const;

private:
	Fixed _x;
	Fixed _y;
};

#endif