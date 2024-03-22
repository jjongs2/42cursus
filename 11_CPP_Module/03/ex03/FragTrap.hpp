#ifndef FRAGTRAP_HPP_
#define FRAGTRAP_HPP_

#include <string>

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
 public:
  FragTrap();
  explicit FragTrap(const std::string& name);
  FragTrap(const FragTrap& origin);
  FragTrap& operator=(const FragTrap& origin);
  virtual ~FragTrap();

  void highFivesGuys(void);
};

#endif
