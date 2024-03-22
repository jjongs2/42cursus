#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

#include <string>

class Animal {
 public:
  Animal();
  Animal(const Animal& origin);
  Animal& operator=(const Animal& origin);
  virtual ~Animal();

  const std::string& getType(void) const;
  void setType(const std::string& type);

  virtual void makeSound(void) const;

 protected:
  std::string type_;
};

#endif
