#ifndef WRONGCAT_HPP_
#define WRONGCAT_HPP_

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
 public:
  WrongCat();
  WrongCat(const WrongCat& origin);
  WrongCat& operator=(const WrongCat& origin);
  ~WrongCat();

  void makeSound(void) const;
};

#endif
