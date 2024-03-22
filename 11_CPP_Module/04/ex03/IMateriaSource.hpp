#ifndef IMATERIASOURCE_HPP_
#define IMATERIASOURCE_HPP_

#include "AMateria.hpp"

class IMateriaSource {
 public:
  virtual AMateria* createMateria(const std::string& type) = 0;

  virtual ~IMateriaSource() {}

  virtual void learnMateria(AMateria* materia) = 0;
};

#endif
