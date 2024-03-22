#ifndef SCAVTRAP_HPP_
#define SCAVTRAP_HPP_

#include <string>

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
 public:
  ScavTrap();
  explicit ScavTrap(const std::string& name);
  ScavTrap(const ScavTrap& origin);
  ScavTrap& operator=(const ScavTrap& origin);
  virtual ~ScavTrap();

  void attack(const std::string& target);
  void guardGate(void);
};

#endif
