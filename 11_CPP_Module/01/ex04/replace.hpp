#ifndef REPLACE_HPP_
#define REPLACE_HPP_

#include <fstream>
#include <string>

const std::string kFilenamePostfix = ".replace";

std::string readFile(std::ifstream& file);
void replace(std::string& base, const std::string& s1, const std::string& s2);

#endif
