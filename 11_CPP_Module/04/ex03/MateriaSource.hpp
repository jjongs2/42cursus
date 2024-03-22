#ifndef MATERIASOURCE_HPP_
#define MATERIASOURCE_HPP_

#include "IMateriaSource.hpp"
#include "constant.hpp"

class MateriaSource : public IMateriaSource {
 public:
  AMateria* createMateria(const std::string& type);

  MateriaSource();
  MateriaSource(const MateriaSource& origin);
  MateriaSource& operator=(const MateriaSource& origin);
  virtual ~MateriaSource();

  AMateria* getMateria(const int index) const;
  void setMateria(const int index, AMateria* materia);

  void learnMateria(AMateria* materia);

 private:
  AMateria* materias_[kNumOfMaterias];
};

#endif
