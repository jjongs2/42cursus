#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
  std::cout << "[ Constructor ]\n";
  Animal* animals[kNumOfAnimals];
  for (int i = 0; i < kNumOfAnimals; ++i) {
    // animals[i] = new Animal();
    if (i & 1) {
      animals[i] = new Dog();
    } else {
      animals[i] = new Cat();
    }
    std::cout << '\n';
  }

  std::cout << "[ Destructor ]\n";
  for (int i = 0; i < kNumOfAnimals; ++i) {
    delete animals[i];
    std::cout << '\n';
  }

  std::cout << "[ Deep Copy ]\n";
  Cat cat;
  std::cout << '\n';
  Cat copy_cat(cat);
  std::cout << '\n';

  cat.getBrain()->setIdea(0, "츄르..");
  std::cout << "cat: " << cat.getBrain()->getIdea(0) << '\n';
  std::cout << "copy_cat: " << copy_cat.getBrain()->getIdea(0) << "\n\n";
  return 0;
}
