#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	this->_fixedPointNum = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	this->_fixedPointNum = num;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num)
{
	this->_fixedPointNum = num;
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	this->_fixedPointNum = other.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPointNum = this->getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointNum;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
}

float Fixed::toFloat(void) const
{
	int num = getRawBits();
	return (float)num;
}

int Fixed::toInt(void) const
{
	int num = getRawBits();
	return num;
}

std::ostream &operator<<(std::ostream & os, const Fixed &fixed)
{
	int n = fixed.getRawBits();
	os << n;
	return os;
}