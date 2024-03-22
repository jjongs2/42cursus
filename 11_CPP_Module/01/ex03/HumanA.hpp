#ifndef HUMANA_HPP_
#define HUMANA_HPP_

#include "Weapon.hpp"

const std::string kAttackMessageA = " attacks with their ";

class HumanA {
 public:
  explicit HumanA(const std::string& name, Weapon& weapon);

  void attack(void) const;

 private:
  std::string name_;
  Weapon& weapon_;
};

#endif
