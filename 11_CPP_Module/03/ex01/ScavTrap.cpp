#include "ScavTrap.hpp"

#include <iostream>

#include "constant.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
  this->type_ = kTraps[kScav];
  this->hit_points_ = kScavHP;
  this->energy_points_ = kScavEP;
  this->attack_damage_ = kScavAD;
  std::cout << this->type_ << kMessages[kDefaultConstructor] << kSuffix << '\n';
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
  this->type_ = kTraps[kScav];
  this->hit_points_ = kScavHP;
  this->energy_points_ = kScavEP;
  this->attack_damage_ = kScavAD;
  std::cout << this->type_ << kMessages[kNameConstructor] << kSuffix << '\n';
}

ScavTrap::ScavTrap(const ScavTrap& origin) : ClapTrap() {
  std::cout << kTraps[kScav] << kMessages[kCopyConstructor] << kSuffix << '\n';
  *this = origin;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& origin) {
  std::cout << kTraps[kScav] << kMessages[kCopyAssignmentOperator] << kSuffix
            << '\n';
  if (this != &origin) {
    this->name_ = origin.getName();
    this->type_ = origin.getType();
    this->hit_points_ = origin.getHitPoints();
    this->energy_points_ = origin.getEnergyPoints();
    this->attack_damage_ = origin.getAttackDagmage();
  }
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << kTraps[kScav] << kMessages[kDestructor] << kSuffix << std::endl;
}

void ScavTrap::attack(const std::string& target) {
  if (this->hit_points_ == 0 || this->energy_points_ == 0) return;
  this->energy_points_ -= 1;
  std::cout << this->type_ << this->name_ << " attacks " << target
            << ", causing " << this->attack_damage_ << " point(s) of damage!\n";
  this->displayStatus();
}

void ScavTrap::guardGate(void) {
  if (this->hit_points_ == 0 || this->energy_points_ == 0) return;
  this->energy_points_ -= 1;
  std::cout << this->type_ << this->name_ << " is now in Gate keeper mode!\n";
  this->displayStatus();
}
