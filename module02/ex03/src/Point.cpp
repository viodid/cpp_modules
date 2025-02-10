#include "../include/Point.hpp"

Point::Point() : _x(0), _y(0) { }

Point::Point(const float a, const float b) : _x(a), _y(b) { }

Point::Point(const Point& obj) : _x(obj.getX()), _y(obj.getY()) { }

Point::~Point() { }

Fixed Point::getX() const { return _x; }

Fixed Point::getY() const { return _y; }
