#include <iostream>

#include "error.hpp"
#include "replace.hpp"

int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::cout << kErrorMessages[kArgument] << std::endl;
    return 1;
  }

  const std::string filename(argv[1]);
  std::ifstream infile(filename.c_str());
  if (!infile.is_open()) {
    std::cout << kErrorMessages[kOpen] << std::endl;
    return 1;
  }
  std::ofstream outfile((filename + kFilenamePostfix).c_str());
  if (!outfile.is_open()) {
    infile.close();
    std::cout << kErrorMessages[kOpen] << std::endl;
    return 1;
  }

  std::string file_content = readFile(infile);
  infile.close();
  replace(file_content, argv[2], argv[3]);
  outfile << file_content;
  outfile.close();
  return 0;
}
