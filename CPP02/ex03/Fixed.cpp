#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	this->_fixedPointNum = 0;
}

Fixed::Fixed(const int num)
{
	this->_fixedPointNum = num << this->FRACTIONAL_BITS;
}

Fixed::Fixed(const float num)
{
	this->_fixedPointNum = static_cast<int>(num * (1 << this->FRACTIONAL_BITS));
}

Fixed::Fixed(const Fixed &other)
{
	setRawBits(other.getRawBits());
}

/** Asignement operator */
Fixed &Fixed::operator=(const Fixed &rhs)
{
	setRawBits(rhs.getRawBits());
	return *this;
}

Fixed::~Fixed(){}

int Fixed::getRawBits() const
{
	return this->_fixedPointNum;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointNum = raw;
}

float Fixed::toFloat() const
{
	int raw_bits = getRawBits();
	return static_cast<float>(raw_bits) / (1 << FRACTIONAL_BITS);
}

int Fixed::toInt() const
{
	int raw_bits = getRawBits();
	return static_cast<int>(std::roundf(raw_bits >> this->FRACTIONAL_BITS));
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	return a > b ? a : b;
}

/** Comparison operators */
bool Fixed::operator==(const Fixed &rhs) const
{
	return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return !(*this == rhs);
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>(const Fixed &rhs) const
{
	return rhs < *this;
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return !(rhs < *this);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return rhs <= *this;
}

/** Arithmatic operators */
Fixed Fixed::operator+(const Fixed &rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

/** Increment and decrement operators */
Fixed Fixed::operator++()
{
	*this = Fixed(this->toInt() + 1);
	return *this;
}

Fixed Fixed::operator--()
{
	*this = Fixed(this->toInt() - 1);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++*this;
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	--*this;
	return tmp;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	float n = fixed.toFloat();
	os << n;
	return os;
}
