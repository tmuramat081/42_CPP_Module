#include "point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed a = ((v[1].x - v[0].x) * (p.y - v[0].y) - (p.x - v[0].x) * (v[1].y - v[0].y)) / 2.0f;
	a[1] = ((v[2].x - v[1].x) * (p.y - v[1].y) - (p.x - v[1].x) * (v[2].y - v[1].y)) / 2.0f;
	a[2] = ((v[0].x - v[2].x) * (p.y - v[2].y) - (p.x - v[2].x) * (v[0].y - v[2].y)) / 2.0f;

	if (a[0] >= 0.0f && a[1] >= 0.0f && a[2] >= 0.0f)
		return (true);
	return (false);
}

#endif
