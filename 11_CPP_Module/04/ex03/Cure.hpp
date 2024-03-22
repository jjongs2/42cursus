#ifndef CURE_HPP_
#define CURE_HPP_

#include "AMateria.hpp"

class Cure : public AMateria {
 public:
  AMateria* clone(void) const;

  Cure();
  Cure(const Cure& origin);
  Cure& operator=(const Cure& origin);
  virtual ~Cure();

  void use(ICharacter& target);
};

#endif
