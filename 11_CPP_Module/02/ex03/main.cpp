#include "Point.hpp"

int main(void) {
  Point a(1, 1);
  Point b(2, 4);
  Point c(4, 2);

  Point p_in(2, 2);
  Point p_out(4, 4);
  Point p_vertex(4, 2);
  Point p_edge(3, 3);

  bool result_in = bsp(a, b, c, p_in);
  bool result_out = bsp(a, b, c, p_out);
  bool result_vertex = bsp(a, b, c, p_vertex);
  bool result_edge = bsp(a, b, c, p_edge);

  printResult(p_in, result_in);
  printResult(p_out, result_out);
  printResult(p_vertex, result_vertex);
  printResult(p_edge, result_edge);
  return 0;
}
