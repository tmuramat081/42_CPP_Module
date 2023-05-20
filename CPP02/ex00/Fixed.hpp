#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
public:
	// Constructors
	Fixed();
	Fixed(const Fixed &other);

	// Destructor
	~Fixed();

	// Operator
	Fixed &operator=(const Fixed &rhs);

	// Getters / Setter
	int getRawBits() const;
	void setRawBits(int const raw);

private:
	int _fixedPointNum;
	static const int _FRACTIONAL_BITS = 8;
};

#endif
