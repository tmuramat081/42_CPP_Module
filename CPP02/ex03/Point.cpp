#include "Point.hpp"

Point::Point(): x(0), y(0) {}

Point::Point(float const &x, float const &y): x(Fixed(x)), y(Fixed(y)) {}

Point::Point(int const &x, int const &y): x(Fixed(x)), y(Fixed(y)) {}

Point::Point(const Point &other): x(other.getX()), y(other.getY()) {}

Point::~Point(){}

Point &Point::operator=(const Point &other)
{
    return *this;
}

Point Point::operator+(const Point &other) const
{
	Fixed new_x = this->getX() + other.getX();
	Fixed new_y = this->getY() + other.getY();
    return Point(new_x.toFloat(), new_y.toFloat());
}

Point Point::operator-(const Point &other) const
{
	Fixed new_x = this->getX() - other.getX();
	Fixed new_y = this->getY() - other.getY();
    return Point(new_x.toFloat(), new_y.toFloat());
}

/* 内積 */
Fixed Point::dot(const Point &other) const
{
    return this->getX() * other.getX() + this->getY() * other.getY();
}

/** 外積 */
Fixed Point::cross(const Point &other) const
{
    return this->getX() * other.getY() - this->getY() * other.getX();
}

Fixed Point::getX() const
{
    return this->x;
}

Fixed Point::getY() const
{
    return this->y;
}

std::ostream &operator<<(std::ostream &os, const Point &point)
{
	os << "(" << point.getX() << ", " << point.getY() << ")";
	return os;
}
