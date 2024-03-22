#include <iostream>
#include <vector>

#include "easyfind.hpp"

int main(void) {
  try {
    std::vector<int> vec;
    for (int i = 0; i <= 100; i += 2) {
      vec.push_back(i);
    }
    // std::cout << *easyfind(vec, 21) << std::endl;
    std::cout << *easyfind(vec, 42) << std::endl;
  } catch (std::exception& e) {
    std::cout << kErrors[kPrefix] << e.what() << std::endl;
    return 1;
  }
  return 0;
}
