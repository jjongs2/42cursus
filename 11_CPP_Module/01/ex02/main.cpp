#include <iostream>

int main(void) {
  std::string stringVAR = "HI THIS IS BRAIN";
  std::string* stringPTR = &stringVAR;
  std::string& stringREF = stringVAR;

  std::cout << "Memory address of string variable: " << &stringVAR << '\n'
            << "Memory address held by stringPTR: " << stringPTR << '\n'
            << "Memory address held by stringREF: " << &stringREF << '\n';
  std::cout << '\n';

  std::cout << "Value of string variable: " << stringVAR << '\n'
            << "Value pointed to by stringPTR: " << *stringPTR << '\n'
            << "Value pointed to by stringREF: " << stringREF << std::endl;
  return 0;
}
