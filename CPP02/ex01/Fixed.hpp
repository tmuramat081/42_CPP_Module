#include <iostream>

class Fixed
{
public:
	Fixed();
	explicit Fixed(const int num);
	explicit Fixed(const float num);
	Fixed(const Fixed &);
	Fixed &operator=(const Fixed &fixed);
	~Fixed();
	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

private:
	int _fixedPointNum;
	static const int _rawBits = 8;
};

std::ostream &operator <<(std::ostream &os, const Fixed &fixed);