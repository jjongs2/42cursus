#ifndef HUMANB_HPP_
#define HUMANB_HPP_

#include "Weapon.hpp"

const std::string kAttackMessageB = " attacks with their ";

class HumanB {
 public:
  explicit HumanB(const std::string& name);

  void setWeapon(Weapon& weapon);
  void attack(void) const;

 private:
  std::string name_;
  Weapon* weapon_;
};

#endif
