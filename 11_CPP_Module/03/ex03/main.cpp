#include <iostream>

#include "DiamondTrap.hpp"

int main(void) {
  DiamondTrap foo("Foo");
  std::cout << '\n';
  DiamondTrap bar("Bar");
  std::cout << '\n';
  DiamondTrap d1(foo);
  std::cout << '\n';
  DiamondTrap d2;
  d2 = bar;
  std::cout << '\n';

  foo.attack("Bar");
  bar.takeDamage(foo.getAttackDagmage());
  bar.beRepaired(2);
  bar.guardGate();
  bar.highFivesGuys();
  bar.whoAmI();
  return 0;
}
