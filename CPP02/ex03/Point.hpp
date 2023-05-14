#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
public:
	Point();
	explicit Point(float const &x, float const &y);
	explicit Point(int const &x, int const &y);
	Point(const Point &other);
	~Point();

	Point &operator=(const Point &other);

	Point operator+(const Point &other) const;
	Point operator-(const Point &other) const;

	Fixed dot(const Point &other) const;
	Fixed cross(const Point &other) const;
	Fixed getX() const;
	Fixed getY() const;

private:
	const Fixed x;
	const Fixed y;
};

std::ostream &operator<<(std::ostream &os, const Point &point);

#endif
