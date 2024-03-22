#ifndef CAT_HPP_
#define CAT_HPP_

#include "Animal.hpp"

class Cat : public Animal {
 public:
  Cat();
  Cat(const Cat& origin);
  Cat& operator=(const Cat& origin);
  virtual ~Cat();

  void makeSound(void) const;
};

#endif
