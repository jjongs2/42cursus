#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed const b(10);
  Fixed const c(42.42f);
  Fixed const d(b);
  a = Fixed(1234.4321f);

  std::cout << "a is " << a << '\n'
            << "b is " << b << '\n'
            << "c is " << c << '\n'
            << "d is " << d << '\n';

  std::cout << "a is " << a.toInt() << " as integer" << '\n'
            << "b is " << b.toInt() << " as integer" << '\n'
            << "c is " << c.toInt() << " as integer" << '\n'
            << "d is " << d.toInt() << " as integer" << '\n';
  return 0;
}
