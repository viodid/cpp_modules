#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"

class Point
{
public:
	Point();
	Point(float a, float b);
	Point(const Point& obj);
	~Point();

private:
	const Fixed _x;
	const Fixed _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
