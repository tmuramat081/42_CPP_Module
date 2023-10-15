#include "Fixed.hpp"
#include <iostream>

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

int main()
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	Fixed const zero(0);

	a = Fixed(123.321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;

	std::cout << GREEN << ">> Test arithmatic operators." << DEFAULT << std::endl;

	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a + b + c = " << a + b + c << std::endl;
	std::cout << "a - c = " << a - c << std::endl;
	std::cout << "a - c - b = " << a - c - b << std::endl;
	std::cout << "a * c = " << a * c << std::endl;
	std::cout << "a * c * b = " << a * c * b << std::endl;
	std::cout << "a / c = " << a / c << std::endl;

	std::cout << GREEN << ">> Test increment and decrement operators." << DEFAULT << std::endl;

	Fixed e = a;
	std::cout << "e is " << e << std::endl;
	std::cout << "++e is " << ++e << std::endl;
	std::cout << "e is " << e << std::endl;
	std::cout << "e++ is " << e++ << std::endl;
	std::cout << "e is " << e << std::endl;
	std::cout << "--e is " << --e << std::endl;
	std::cout << "e is " << e << std::endl;
	std::cout << "e-- is " << e-- << std::endl;
	std::cout << "e is " << e << std::endl;

	std::cout << GREEN << ">> Test comparison operators." << DEFAULT << std::endl;

	Fixed f = a;
	std::cout << "f is " << f << std::endl;
	std::cout << "f == a: " << (f == a) << std::endl;
	std::cout << "f != a: " << (f != a) << std::endl;
	std::cout << "f < a: " << (f < a) << std::endl;
	std::cout << "f > a: " << (f > a) << std::endl;
	std::cout << "f <= a: " << (f <= a) << std::endl;
	std::cout << "f >= a: " << (f >= a) << std::endl;

	std::cout << GREEN << ">> Test min() and max() functions." << DEFAULT << std::endl;

	std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;

	std::cout << RED << ">> Test error pattern." << DEFAULT << std::endl;

	try
	{
		std::cout << "a / 0 = " << std::endl;
		a / zero;
	}
	catch (std::invalid_argument &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "8388608 / -0.002 = " << std::endl;
		Fixed(-8388608) / Fixed(-0.002f);
	}
	catch (std::overflow_error &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "8388608 + 1 = " << std::endl;
		Fixed(8388607) + Fixed(1);
	}
	catch (std::overflow_error &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "-8388608 - 1 = " << std::endl;
		Fixed(-8388608) - Fixed(1);
	}
	catch (std::overflow_error &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
