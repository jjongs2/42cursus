#ifndef CAT_HPP_
#define CAT_HPP_

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 public:
  Cat();
  Cat(const Cat& origin);
  Cat& operator=(const Cat& origin);
  virtual ~Cat();

  Brain* getBrain(void) const;
  void setBrain(Brain* brain);

  void makeSound(void) const;

 private:
  Brain* brain_;
};

#endif
