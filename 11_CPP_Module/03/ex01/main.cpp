#include <iostream>

#include "ScavTrap.hpp"

int main(void) {
  ScavTrap foo("Foo");
  std::cout << '\n';
  ScavTrap bar("Bar");
  std::cout << '\n';
  ScavTrap s1(foo);
  std::cout << '\n';
  ScavTrap s2;
  s2 = bar;
  std::cout << '\n';

  foo.attack("Bar");
  bar.takeDamage(foo.getAttackDagmage());
  bar.beRepaired(2);
  bar.guardGate();
  return 0;
}
