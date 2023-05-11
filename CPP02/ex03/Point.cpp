#include "Point.hpp"

Point::Point(){}

Point::Point(Fixed x, Fixed y): _x(x), _y(y){}

Point::~Point(){}

Point &Point::operator=(const Point &other)
{
    this->_x = other.getX();
    this->_y = other.getY();
    return *this;
}

/* 内積 */
Fixed Point::dot(const Point &other) const
{
    return this->getX() * other.getX() + this->getY() * other.getY();
}

/** 外積 */
Fixed Point::cross(const Point &other) const
{
    return this->getX() * other.getY() - this->getY() * other.getY();
}


Fixed Point::getX() const
{
    return this->_x;
}

Fixed Point::getY() const
{
    return this->_y;
}
