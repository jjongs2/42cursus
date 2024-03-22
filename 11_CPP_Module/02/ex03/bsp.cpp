#include "Point.hpp"

static Fixed cross(Vector v1, Vector v2) {
  return (v1.getX() * v2.getY() - v2.getX() * v1.getY());
}

bool bsp(const Point a, const Point b, const Point c, const Point point) {
  Fixed p1 = cross(b - a, point - a);
  Fixed p2 = cross(c - b, point - b);
  Fixed p3 = cross(a - c, point - c);

  bool all_positive = (p1 > 0) && (p2 > 0) && (p3 > 0);
  bool all_negative = (p1 < 0) && (p2 < 0) && (p3 < 0);
  return (all_positive ^ all_negative);
}

void printResult(const Point point, bool result) {
  const std::string side = result ? "내" : "외";
  std::cout << "점 (" << point.getX() << ", " << point.getY()
            << ")은(는) 삼각형 ABC의 " << side << "부에 있습니다." << '\n';
}
