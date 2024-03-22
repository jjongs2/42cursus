#include <iostream>

#include "ClapTrap.hpp"

int main(void) {
  ClapTrap foo("Foo");
  std::cout << '\n';
  ClapTrap bar("Bar");
  std::cout << '\n';
  ClapTrap c1(foo);
  std::cout << '\n';
  ClapTrap c2;
  c2 = bar;
  std::cout << '\n';

  foo.attack("Bar");
  bar.takeDamage(foo.getAttackDagmage());
  bar.beRepaired(2);
  return 0;
}
