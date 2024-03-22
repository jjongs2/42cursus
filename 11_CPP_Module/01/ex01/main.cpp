#include <iostream>

#include "Zombie.hpp"
#include "constant.hpp"

int main(void) {
  Zombie* horde = zombieHorde(kNumOfZombies, "Heap");
  for (int i = 0; i < kNumOfZombies; ++i) {
    horde[i].announce();
  }
  std::cout << '\n';

  delete[] horde;
  return 0;
}
