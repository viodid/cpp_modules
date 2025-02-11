#include "../include/Point.hpp"

static float cross_product(const Point& a, const Point& b, const Point& p);

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	const float d1 = cross_product(a, b, point);
	const float d2 = cross_product(b, c, point);
	const float d3 = cross_product(c, a, point);

	if ((d1 > 0 && d2 > 0 && d3 > 0)
		|| (d1 < 0 && d2 < 0 && d3 < 0))
		return true;
	return false;
}

static float cross_product(const Point& a, const Point& b, const Point& p)
{
	const Fixed r = (b.getX() - a.getX()) * (p.getY() - a.getY()) - (b.getY() - a.getY()) * (p.getX() - a.getX());
	return (r.toFloat());
}
