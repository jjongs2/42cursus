#ifndef DOG_HPP_
#define DOG_HPP_

#include "Animal.hpp"

class Dog : public Animal {
 public:
  Dog();
  Dog(const Dog& origin);
  Dog& operator=(const Dog& origin);
  virtual ~Dog();

  void makeSound(void) const;
};

#endif
