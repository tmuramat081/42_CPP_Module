#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <cmath>

class Scalar
{
public:
	Scalar();
	Scalar(const Scalar &other);
	Scalar &operator=(const Scalar &rhs);
	~Scalar();

	template<typename T>
	void setChar(T value)
	{
		if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max())
		{
			as_char = static_cast<char>(value);
			char_possible = true;
		}
	}

	template<typename T>
	void setInt(T value)
	{
		if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
		{
			as_int = static_cast<int>(value);
			int_possible = true;
		}
	}

	template<typename T>
	void setFloat(T value)
	{
		if (std::isnan(value) || std::isinf(value))
		{
			as_float = static_cast<float>(value);
			float_possible = true;
		}
		else if (value >= -std::numeric_limits<float>::max() && value <= std::numeric_limits<float>::max())
		{
			as_float = static_cast<float>(value);
			float_possible = true;
		}
	}

	template<typename T>
	void setDouble(T value)
	{
		if (std::isnan(value) || std::isinf(value))
		{
			as_double = static_cast<double>(value);
			double_possible = true;
		}
		else if (value >= -std::numeric_limits<double>::max() && value <= std::numeric_limits<double>::max())
		{
			as_double = static_cast<double>(value);
			double_possible = true;
		}
	}

	char	getChar() const;
	int		getInt() const;
	float	getFloat() const;
	double	getDouble() const;

private:
	char	as_char;
	int		as_int;
	float	as_float;
	double	as_double;
	bool	char_possible;
	bool	int_possible;
	bool	float_possible;
	bool	double_possible;

};

std::ostream &operator<<(std::ostream &os, const Scalar &scalar);

#endif
