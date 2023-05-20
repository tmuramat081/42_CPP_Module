#include "Point.hpp"

#define BLUE "\033[0;94m"
#define GREEN "\033[0;92m"
#define YELLOW "\033[0;93m"
#define RED "\033[0;91m"
#define DEFAULT "\033[0;39m"

bool bsp(Point const a, Point const b, Point const c, Point const point);

void test(Point const a, Point const b, Point const c, Point const point, bool expected)
{
	bool res;

	std::cout << "P" << point << std::endl;

	res = bsp(a, b, c, point);
	if (res)
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
	(void)expected;
//	assert(res == expected);
}

int main()
{
	Point a(0.0f, 0.0f);
	Point b(0.0f, 1.0f);
	Point c(1.0f, 0.0f);

	std::cout << "A" << a << ", ";
	std::cout << "B" << b << ", ";
	std::cout << "C" << c << std::endl;

	// 三角形の内側
	Point p0(0.2f, 0.2f);
	test(a, b, c, p0, true);
	// 三角形の頂点上
	Point p1(0.0f, 0.0f);
	test(a, b, c, p1, true);
	// 三角形の辺上
	Point p2(0.5f, 0.0f);
	test(a, b, c, p2, true);
	// 三角形の外側
	Point p3(1.0f, 1.0f);
	test(a, b, c, p3, false);

	return 0;
}
