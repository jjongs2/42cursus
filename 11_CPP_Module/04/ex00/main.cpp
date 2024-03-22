#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void) {
  std::cout << "[ Constructor ]\n";
  const Animal* meta = new Animal();
  std::cout << '\n';
  const Animal* dog = new Dog();
  std::cout << '\n';
  const Animal* cat = new Cat();
  std::cout << '\n';

  std::cout << "[ Member ]\n";
  std::cout << "Type: " << dog->getType() << " " << '\n';
  std::cout << "Type: " << cat->getType() << " " << '\n';
  cat->makeSound();  // will output the cat sound!
  dog->makeSound();
  meta->makeSound();
  std::cout << '\n';

  std::cout << "[ Destructor ]\n";
  delete meta;
  std::cout << '\n';
  delete dog;
  std::cout << '\n';
  delete cat;
  std::cout << '\n';

  std::cout << "[ WrongCat ]\n";
  const WrongAnimal* wrong_cat = new WrongCat();
  std::cout << '\n';

  std::cout << "Type: " << wrong_cat->getType() << " " << '\n';
  wrong_cat->makeSound();
  std::cout << '\n';

  delete wrong_cat;
  return 0;
}
