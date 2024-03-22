#include <iostream>

#include "FragTrap.hpp"

int main(void) {
  FragTrap foo("Foo");
  std::cout << '\n';
  FragTrap bar("Bar");
  std::cout << '\n';
  FragTrap f1(foo);
  std::cout << '\n';
  FragTrap f2;
  f2 = bar;
  std::cout << '\n';

  foo.attack("Bar");
  bar.takeDamage(foo.getAttackDagmage());
  bar.beRepaired(2);
  bar.highFivesGuys();
  return 0;
}
