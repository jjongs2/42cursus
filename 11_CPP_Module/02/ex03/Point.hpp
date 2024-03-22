#ifndef POINT_HPP_
#define POINT_HPP_

#include "Fixed.hpp"

class Point {
 public:
  Point(void);
  explicit Point(const float x_, const float y_);
  Point(const Point& origin);
  Point& operator=(const Point& origin);
  ~Point(void);

  Point operator-(const Point& right) const;

  const Fixed getX(void) const;
  const Fixed getY(void) const;

 private:
  const Fixed x;
  const Fixed y;
};

typedef Point Vector;

bool bsp(const Point a, const Point b, const Point c, const Point point);
void printResult(const Point point, bool result);

#endif
