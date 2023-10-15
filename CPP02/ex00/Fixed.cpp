#include "Fixed.hpp"
#include <iostream>

// Constructors
Fixed::Fixed()
{
	std::cout << "\033[0;33mDefault constructor called\033[0m" << std::endl;
	this->_fixedPointNum = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "\033[0;33mCopy constructor called\033[0m" << std::endl;
	*this = other;
}

// Destructors
Fixed::~Fixed()
{
	std::cout << "\033[0;33mDestructor called\033[0m" << std::endl;
}

// Operators
Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "\033[0;33mCopy assignment operator called\033[0m" << std::endl;
	if (this != &rhs)
	{
		this->_fixedPointNum = rhs.getRawBits();
	}
	return *this;
}

// Getters / Setters
int Fixed::getRawBits() const
{
	std::cout << "\033[0;32mgetRawBits member function called\033[0m" << std::endl;
	return this->_fixedPointNum;
}

void Fixed::setRawBits(int const raw)
{
	(void)raw;
	std::cout << "\033[0;32msetRawBits member function called\033[0m" << std::endl;
}
