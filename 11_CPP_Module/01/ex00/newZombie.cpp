#include "Zombie.hpp"

Zombie* newZombie(const std::string& name) {
  Zombie* new_zombie = new Zombie(name);
  return new_zombie;
}
