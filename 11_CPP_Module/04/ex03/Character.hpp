#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "AMateria.hpp"
#include "constant.hpp"

class Character : public ICharacter {
 public:
  Character();
  explicit Character(const std::string& type);
  Character(const Character& origin);
  Character& operator=(const Character& origin);
  virtual ~Character();

  const std::string& getName(void) const;
  AMateria* getMateria(const int idx) const;

  void setName(const std::string& name);
  void setMateria(const int index, AMateria* materia);

  void equip(AMateria* materia);
  void unequip(int index);
  void use(int index, ICharacter& target);

 private:
  std::string name_;
  AMateria* materias_[kNumOfMaterias];
};

#endif
