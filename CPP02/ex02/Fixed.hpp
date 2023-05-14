#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
public:
	Fixed();
	explicit Fixed(const int num);
	explicit Fixed(const float num);
	Fixed(const Fixed &other);
	~Fixed();

	Fixed &operator=(const Fixed &fixed);

	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(Fixed const &a, Fixed const &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(Fixed const &a, Fixed const &b);

	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;
	bool operator<(const Fixed &rhs) const;
	bool operator>(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;

	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;

	Fixed operator++();
	Fixed operator--();
	Fixed operator++(int);
	Fixed operator--(int);

private:
	int _fixedPointNum;
	static const int FRACTIONAL_BITS = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
