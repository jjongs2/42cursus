#include <stdexcept>

#include "Convert.hpp"
#include "constant.hpp"

int main(int argc, char* argv[]) {
  try {
    if (argc != 2) {
      throw std::invalid_argument(kErrors[kINVAL]);
    }
    std::cout << Convert(argv[1]);
  } catch (std::exception& e) {
    std::cout << kErrors[kPrefix] << e.what() << std::endl;
    return 1;
  }
  return 0;
}
