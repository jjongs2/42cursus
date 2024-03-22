#ifndef DOG_HPP_
#define DOG_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
 public:
  Dog();
  Dog(const Dog& origin);
  Dog& operator=(const Dog& origin);
  virtual ~Dog();

  Brain* getBrain(void) const;
  void setBrain(Brain* brain);

  void makeSound(void) const;

 private:
  Brain* brain_;
};

#endif
