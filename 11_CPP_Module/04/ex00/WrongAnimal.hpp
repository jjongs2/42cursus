#ifndef WRONGANIMAL_HPP_
#define WRONGANIMAL_HPP_

#include <string>

class WrongAnimal {
 public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal& origin);
  WrongAnimal& operator=(const WrongAnimal& origin);
  ~WrongAnimal();

  const std::string& getType(void) const;
  void setType(const std::string& type);

  void makeSound(void) const;

 protected:
  std::string type_;
};

#endif
