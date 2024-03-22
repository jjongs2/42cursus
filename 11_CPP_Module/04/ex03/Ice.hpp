#ifndef ICE_HPP_
#define ICE_HPP_

#include "AMateria.hpp"

class Ice : public AMateria {
 public:
  AMateria* clone(void) const;

  Ice();
  Ice(const Ice& origin);
  Ice& operator=(const Ice& origin);
  virtual ~Ice();

  void use(ICharacter& target);
};

#endif
