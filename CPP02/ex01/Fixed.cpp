#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Constructors
Fixed::Fixed()
{
	std::cout << "\033[0;33mDefault constructor called\033[0m" << std::endl;
	this->_fixedPointNum = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "\033[0;33mInt constructor called\033[0m" << std::endl;
	this->_fixedPointNum = num << this->FRACTIONAL_BITS;
}

Fixed::Fixed(const float num)
{
	std::cout << "\033[0;33mFloat constructor called\033[0m" << std::endl;
	this->_fixedPointNum = static_cast<int>(std::roundf(num * (1 << this->FRACTIONAL_BITS)));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "\033[0;33mCopy constructor called\033[0m" << std::endl;
	this->_fixedPointNum = other._fixedPointNum;
}

// Operator
Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "\033[0;33mCopy assignment operator called\033[0m" << std::endl;
	if (this != &rhs)
	{
		this->_fixedPointNum = rhs._fixedPointNum;
	}
	return *this;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "\033[0;33mDestructor called\033[0m" << std::endl;
}

// Member functions
float Fixed::toFloat() const
{
	int raw_bits = this->_fixedPointNum;
	return static_cast<float>(raw_bits) / (1 << FRACTIONAL_BITS);
}

int Fixed::toInt() const
{
	int raw_bits = this->_fixedPointNum;
	return raw_bits >> this->FRACTIONAL_BITS;
}

// Getters / Setters
int Fixed::getRawBits() const
{
	return this->_fixedPointNum;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointNum = raw;
}

// Shift oprator
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	float n = fixed.toFloat();
	os << n;
	return os;
}
