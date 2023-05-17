#include "Point.hpp"

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point a(0, 0);
	Point b(0, 6);
	Point c(8, 0);
	Point p(2, 2);

	std::cout << "A" << a << ", ";
	std::cout << "B" << b << ", ";
	std::cout << "C" << c << ", ";
	std::cout << "P" << p << std::endl;

	if (bsp(p, a, b, c))
	{
		std::cout << GREEN;
		std::cout << "○ P is inside the triangle.";
		std::cout << DEFAULT << std::endl;
	}
	else
	{
		std::cout << RED;
		std::cout << "x P is outside the triangle.";
		std::cout << DEFAULT << std::endl;
	}

	return 0;
}
