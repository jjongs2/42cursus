#ifndef DIAMONDTRAP_HPP_
#define DIAMONDTRAP_HPP_

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
 public:
  using ScavTrap::attack;

  DiamondTrap();
  explicit DiamondTrap(const std::string& name);
  DiamondTrap(const DiamondTrap& origin);
  DiamondTrap& operator=(const DiamondTrap& origin);
  virtual ~DiamondTrap();

  void whoAmI(void);

 private:
  std::string name_;
};

#endif
