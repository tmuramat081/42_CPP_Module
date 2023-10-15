#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Constructors
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
	this->_fixedPointNum = static_cast<int>(std::roundf(num * (1 << this->FRACTIONAL_BITS)));
}

Fixed::Fixed(const Fixed &other)
{
	this->_fixedPointNum = other._fixedPointNum;
}

// Destructor
Fixed::~Fixed() {}

// Asignement operator
Fixed &Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
	{
		this->_fixedPointNum = rhs._fixedPointNum;
	}
	return *this;
}

// Getter / Setters
int Fixed::getRawBits() const
{
	return this->_fixedPointNum;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointNum = raw;
}

//  Member functions
float Fixed::toFloat() const
{
	int raw_bits = this->_fixedPointNum;
	return static_cast<float>(raw_bits) / (1 << FRACTIONAL_BITS);
}

int Fixed::toInt() const
{
	return this->_fixedPointNum >> this->FRACTIONAL_BITS;
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

// Comparison operators
bool Fixed::operator==(const Fixed &rhs) const
{
	return this->_fixedPointNum == rhs._fixedPointNum;
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return !(*this == rhs);
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return this->_fixedPointNum < rhs._fixedPointNum;
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

// Arithmatic operators
Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed result;
	const int a = this->_fixedPointNum;
	const int b = rhs._fixedPointNum;

	if (a > 0 && a > std::numeric_limits<int>::max() - b)
	{
		throw std::overflow_error("\033[0;31mError: Addition overflow\033[0m");
	}
	if (a < 0 && a < std::numeric_limits<int>::min() - b)
	{
		throw std::overflow_error("\033[0;31mError: Addition overflow\033[0m");
	}
	result._fixedPointNum = a + b;
	return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed result;
	const int a = this->_fixedPointNum;
	const int b = rhs._fixedPointNum;

	if (b > 0 && a < std::numeric_limits<int>::min() + b)
	{
		throw std::overflow_error("\033[0;31mError: Subtraction overflow\033[0m");
	}
	if (b < 0 && a > std::numeric_limits<int>::max() + b)
	{
		throw std::overflow_error("\033[0;31mError: Subtraction overflow\033[0m");
	}
	result._fixedPointNum = a - b;
	return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	// TODO: 算術オーバーフローを検出する
	return  Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	Fixed result;
	const int a = this->_fixedPointNum;
	const int b = rhs._fixedPointNum;

	if (b == 0)
	{
		throw std::invalid_argument("\033[0;31mError: Division by zero\033[0m");
	}
	if (a == std::numeric_limits<int>::min() && b == -1)
	{
		throw std::overflow_error("\033[0;31mError: Division overflow\033[0m");
	}
	result._fixedPointNum = (a << Fixed::FRACTIONAL_BITS) / b;
	return result;
}

/** Increment and decrement operators */
Fixed Fixed::operator++()
{
	this->_fixedPointNum = this->_fixedPointNum + (1 << FRACTIONAL_BITS);
	return *this;
}

Fixed Fixed::operator--()
{
	this->_fixedPointNum = this->_fixedPointNum - (1 << FRACTIONAL_BITS);
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
