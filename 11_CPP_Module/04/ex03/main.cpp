#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main(void) {
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter* me = new Character("me");

  AMateria* tmp0 = src->createMateria("ice");
  me->equip(tmp0);
  AMateria* tmp1 = src->createMateria("cure");
  me->equip(tmp1);

  ICharacter* bob = new Character("bob");

  me->use(0, *bob);
  me->use(1, *bob);
  me->use(2, *bob);
  me->use(4, *bob);

  me->unequip(1);
  me->unequip(2);
  me->unequip(4);

  me->use(1, *bob);

  delete tmp1;
  delete bob;
  delete me;
  delete src;
  return 0;
}
