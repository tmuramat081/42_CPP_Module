#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointNum = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointNum = num << this->FRACTIONAL_BITS;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointNum = static_cast<int>(num * (1 << this->FRACTIONAL_BITS));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(other.getRawBits());
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(rhs.getRawBits());
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

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

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	float n = fixed.toFloat();
	os << n;
	return os;
}
