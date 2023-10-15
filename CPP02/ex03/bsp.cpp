#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
	Fixed v0 = (b.getX() - a.getX()) * (p.getY() - a.getY()) - (p.getX() - a.getX()) * (b.getY() - a.getY());
	Fixed v1 = (c.getX() - b.getX()) * (p.getY() - b.getY()) - (p.getX() - a.getX()) * (c.getY() - b.getY());
	Fixed v2 = (a.getX() - c.getX()) * (p.getY() - c.getY()) - (p.getX() - c.getX())* (a.getY() - c.getY());
	std::cout << v0 << std::endl;
	std::cout << v1 << std::endl;
	std::cout << v2 << std::endl;
	if (v0 >= Fixed(0) && v1 >= Fixed(0) && v2 >= Fixed(0))
	{
		return true;
	}
	return false;
}
