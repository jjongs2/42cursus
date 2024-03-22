#include <iostream>

const std::string kDefaultMessage = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

std::string StrToUpper(const std::string& str) {
  const size_t str_size = str.size();
  std::string upper_str;
  for (size_t i = 0; i < str_size; ++i) {
    upper_str += std::toupper(str.at(i));
  }
  return upper_str;
}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    std::cout << kDefaultMessage << std::endl;
    return 0;
  }
  for (int i = 1; i < argc; ++i) {
    std::cout << StrToUpper(argv[i]);
  }
  std::cout << std::endl;
  return 0;
}
