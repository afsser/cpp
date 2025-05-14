#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point& Point::operator=(const Point &copy) {
	(void)copy;
	return *this;
}

Point::Point(const Point &copy) : _x(copy._x), _y(copy._y) {}

Point::~Point() {}