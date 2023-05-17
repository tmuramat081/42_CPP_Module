class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &);
	Fixed &operator=(const Fixed &);
	~Fixed();
	int getRawBits() const;
	void setRawBits(int const raw);

private:
	int _fixedPointNum;
	static const int _rawBits = 8;
};
