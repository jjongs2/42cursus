#include "replace.hpp"

#include <sstream>

std::string readFile(std::ifstream& file) {
  std::ostringstream content;
  content << file.rdbuf();
  return content.str();
}

void replace(std::string& base, const std::string& s1, const std::string& s2) {
  if (s1.empty()) {
    return;
  }
  const size_t s1_size = s1.size();
  const size_t s2_size = s2.size();
  size_t pos = 0;
  while (true) {
    pos = base.find(s1, pos);
    if (pos == std::string::npos) return;
    base.erase(pos, s1_size);
    base.insert(pos, s2);
    pos += s2_size;
  }
}
