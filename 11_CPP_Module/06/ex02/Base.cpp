#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
  std::srand(std::clock());
  const int random = std::rand() % 3;
  switch (random) {
    case 0: {
      return new A();
    }
    case 1: {
      return new B();
    }
    case 2: {
      return new C();
    }
    default: {
      return NULL;
    }
  }
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p)) {
    std::cout << kPrefix << "A\n";
  } else if (dynamic_cast<B*>(p)) {
    std::cout << kPrefix << "B\n";
  } else if (dynamic_cast<C*>(p)) {
    std::cout << kPrefix << "C\n";
  }
}

void identify(Base& p) {
  try {
    static_cast<void>(dynamic_cast<A&>(p));
    std::cout << kPrefix << "A\n";
    return;
  } catch (std::exception&) {
  }
  try {
    static_cast<void>(dynamic_cast<B&>(p));
    std::cout << kPrefix << "B\n";
    return;
  } catch (std::exception&) {
  }
  try {
    static_cast<void>(dynamic_cast<C&>(p));
    std::cout << kPrefix << "C\n";
    return;
  } catch (std::exception&) {
  }
}
