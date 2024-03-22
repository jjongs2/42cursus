#include "Zombie.hpp"

#include <iostream>

#include "constant.hpp"

Zombie::Zombie() {}

Zombie::Zombie(const std::string& name) : name_(name) {}

Zombie::~Zombie() {
  std::cout << this->name_ << kMessages[kDestroy] << std::endl;
}

void Zombie::setName(const std::string& name) { this->name_ = name; }

void Zombie::announce(void) {
  std::cout << this->name_ << ": " << kMessages[kAnnounce] << '\n';
}
