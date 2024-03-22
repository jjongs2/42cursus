#include <cstdlib>

#include "Array.hpp"
#include "constant.hpp"

int main(void) {
  Array<int> numbers(kArraySize);
  int* mirror = new int[kArraySize];

  srand(time(NULL));
  for (int i = 0; i < kArraySize; i++) {
    const int value = rand();
    numbers[i] = value;
    mirror[i] = value;
  }

  // SCOPE
  {
    numbers.print("Constructor");

    Array<int> tmp = numbers;
    if (tmp.size() >= kMaxPrint) {
      tmp[kMaxPrint - 1] = 21;
    }
    tmp.print("Copy Assignment Operator");

    Array<int> test(tmp);
    if (test.size() >= kMaxPrint) {
      test[kMaxPrint - 1] = 42;
    }
    test.print("Copy Constructor");
  }

  for (int i = 0; i < kArraySize; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << kErrors[kPrefix] << "didn't save the same value!!"
                << std::endl;
      return 1;
    }
  }

  try {
    numbers[-2] = 0;
  } catch (const std::exception& e) {
    std::cerr << kErrors[kPrefix] << e.what() << '\n';
  }

  try {
    numbers[kArraySize] = 0;
  } catch (const std::exception& e) {
    std::cerr << kErrors[kPrefix] << e.what() << '\n';
  }

  for (int i = 0; i < kArraySize; i++) {
    numbers[i] = rand();
  }

  delete[] mirror;
  return 0;
}
