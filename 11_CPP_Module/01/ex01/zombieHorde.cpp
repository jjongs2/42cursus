#include "Zombie.hpp"

Zombie* zombieHorde(const int N, const std::string& name) {
  Zombie* horde = new Zombie[N];
  for (int i = 0; i < N; ++i) {
    horde[i].setName(name);
  }
  return horde;
}
