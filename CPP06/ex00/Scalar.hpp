#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>

class Scalar
{
public:
	Scalar();
	Scalar(const Scalar &other);
	Scalar &operator=(const Scalar &rhs);
	~Scalar();

	template<typename T>
	void setValues(T value)
	{
		if (typeid(T) == typeid(char))
		{
			as_char = static_cast<char>(value);
			as_int = static_cast<int>(value);
			as_float = static_cast<float>(value);
			as_double = static_cast<double>(value);
		}
		else if (typeid(T) == typeid(int))
		{
			as_char = value >= 0 && value <= 127 ? static_cast<char>(value) : 0;
			char_possible = value >= 0 && value <= 127;
			as_int = static_cast<int>(value);
			as_float = static_cast<float>(value);
			as_double = static_cast<double>(value);
		}
		else if (typeid(T) == typeid(float))
		{
			as_char = value >= 0 && value <= 127 ? static_cast<char>(value) : 0;
			char_possible = value >= 0 && value <= 127;
			if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
				as_int = static_cast<int>(value);
			else
				int_possible = false;
			as_float = static_cast<float>(value);
			as_double = static_cast<double>(value);
		}
		else if (typeid(T) == typeid(double))
		{
			as_char = value >= 0 && value <= 127 ? static_cast<char>(value) : 0;
			char_possible = value >= 0 && value <= 127;
			if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
				as_int = static_cast<int>(value);
			else
				int_possible = false;
			if (value >= std::numeric_limits<float>::min() && value <= std::numeric_limits<float>::max())
				as_float = static_cast<float>(value);
			else
				float_possible = false;
			as_double = static_cast<double>(value);
		}
	}

	bool	char_possible;
	bool	int_possible;
	bool	float_possible;
	bool	double_possible;

	char	as_char;
	int		as_int;
	float	as_float;
	double	as_double;


};

std::ostream &operator<<(std::ostream &os, const Scalar &scalar);

#endif
