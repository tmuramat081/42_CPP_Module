#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
public:
	// Constructors
	Fixed();
	explicit Fixed(const int num);
	explicit Fixed(const float num);
	Fixed(const Fixed &other);

	// Destructor
	~Fixed();

	// Operater
	Fixed &operator=(const Fixed &fixed);

	// Member functions
	float toFloat() const;
	int toInt() const;

	// Setter / Getter
	int getRawBits() const;
	void setRawBits(int const raw);

private:
	int _fixedPointNum;
	static const int FRACTIONAL_BITS = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
