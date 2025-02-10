#include "../include/Point.hpp"

int cross_product(const Point& a, const Point& b, const Point& p);

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	const int d1 = cross_product(a, b, point);
	const int d2 = cross_product(b, c, point);
	const int d3 = cross_product(c, a, point);

	if ((d1 > 0 && d2 > 0 && d3 > 0)
		|| (d1 < 0 && d2 < 0 && d3 < 0))
		return true;
	return false;
}

// TODO: make it return a float so it does not lose precision
int cross_product(const Point& a, const Point& b, const Point& p)
{
	const Fixed r = (b.getX() - a.getX()) * (p.getY() - a.getY()) - (b.getY() - a.getY()) * (p.getX() - a.getX());
	return (r.toInt());
}
