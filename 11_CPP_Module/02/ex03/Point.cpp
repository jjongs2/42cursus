#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(const float x_, const float y_) : x(x_), y(y_) {}

Point::Point(const Point& origin) { *this = origin; }

Point& Point::operator=(const Point& origin) {
  if (this != &origin) {
    const_cast<Fixed&>(this->x) = origin.getX();
    const_cast<Fixed&>(this->y) = origin.getY();
  }
  return *this;
}

Point Point::operator-(const Point& right) const {
  return Point((this->x - right.getX()).toFloat(),
               (this->y - right.getY()).toFloat());
}

Point::~Point(void) {}

const Fixed Point::getX(void) const { return this->x; }

const Fixed Point::getY(void) const { return this->y; }
