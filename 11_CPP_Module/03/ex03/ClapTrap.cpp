#include "ClapTrap.hpp"

#include <iostream>

#include "constant.hpp"

ClapTrap::ClapTrap()
    : name_(kUndefined),
      type_(kTraps[kClap]),
      hit_points_(kClapHP),
      energy_points_(kClapEP),
      attack_damage_(kClapAD) {
  std::cout << this->type_ << kMessages[kDefaultConstructor]
            << kSuffix[kMessage] << '\n';
}

ClapTrap::ClapTrap(const std::string& name)
    : name_(name),
      type_(kTraps[kClap]),
      hit_points_(kClapHP),
      energy_points_(kClapEP),
      attack_damage_(kClapAD) {
  std::cout << this->type_ << kMessages[kNameConstructor] << kSuffix[kMessage]
            << '\n';
}

ClapTrap::ClapTrap(const ClapTrap& origin) {
  std::cout << kTraps[kClap] << kMessages[kCopyConstructor] << kSuffix[kMessage]
            << '\n';
  *this = origin;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& origin) {
  std::cout << kTraps[kClap] << kMessages[kCopyAssignmentOperator]
            << kSuffix[kMessage] << '\n';
  if (this != &origin) {
    this->name_ = origin.getName();
    this->hit_points_ = origin.getHitPoints();
    this->energy_points_ = origin.getEnergyPoints();
    this->attack_damage_ = origin.getAttackDagmage();
  }
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << kTraps[kClap] << kMessages[kDestructor] << kSuffix[kMessage]
            << std::endl;
}

std::string ClapTrap::getName(void) const { return this->name_; }

std::string ClapTrap::getType(void) const { return this->type_; }

unsigned int ClapTrap::getHitPoints(void) const { return this->hit_points_; }

unsigned int ClapTrap::getEnergyPoints(void) const {
  return this->energy_points_;
}

unsigned int ClapTrap::getAttackDagmage(void) const {
  return this->attack_damage_;
}

void ClapTrap::setName(std::string& name) { this->name_ = name; }

void ClapTrap::setType(std::string& type) { this->type_ = type; }

void ClapTrap::setHitPoints(unsigned int hit_points) {
  this->hit_points_ = hit_points;
}

void ClapTrap::setEnergyPoints(unsigned int energy_points) {
  this->energy_points_ = energy_points;
}

void ClapTrap::setAttackDagmage(unsigned int attack_damage) {
  this->attack_damage_ = attack_damage;
}

void ClapTrap::attack(const std::string& target) {
  if (this->hit_points_ == 0 || this->energy_points_ == 0) return;
  this->energy_points_ -= 1;
  std::cout << this->type_ << this->name_ << " attacks " << target
            << ", causing " << this->attack_damage_ << " point(s) of damage!\n";
  this->displayStatus();
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (this->hit_points_ == 0) return;
  amount = amount > this->hit_points_ ? this->hit_points_ : amount;
  this->hit_points_ -= amount;
  std::cout << this->type_ << this->name_ << " takes " << amount
            << " point(s) of damage!\n";
  this->displayStatus();
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (this->hit_points_ == 0 || this->energy_points_ == 0) return;
  this->energy_points_ -= 1;
  this->hit_points_ += amount;
  std::cout << this->type_ << this->name_ << " repairs itself, getting "
            << amount << " hit point(s) back!\n";
  this->displayStatus();
}

void ClapTrap::displayStatus(void) {
  std::cout << kStatus[kName] << this->name_ << kStatus[kHP]
            << this->hit_points_ << kStatus[kEP] << this->energy_points_
            << "\n\n";
}
