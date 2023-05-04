#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	this->_fixedPointNum = 0;
	std::cout << "Default constructor called" << std::endl;
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

void setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
}
