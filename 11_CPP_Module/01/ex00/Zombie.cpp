#include "Zombie.hpp"

#include <iostream>

#include "constant.hpp"

Zombie::Zombie(const std::string& name) : name_(name) {}

Zombie::~Zombie() {
  std::cout << this->name_ << kMessages[kDestroy] << std::endl;
}

void Zombie::announce(void) {
  std::cout << this->name_ << ": " << kMessages[kAnnounce] << '\n';
}
