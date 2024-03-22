#include <iostream>

#include "Zombie.hpp"

int main(void) {
  Zombie* dynamic = newZombie("Heap");
  dynamic->announce();
  delete dynamic;
  std::cout << '\n';

  randomChump("Stack");
  return 0;
}
