#ifndef HARL_HPP_
#define HARL_HPP_

#include <string>

class Harl {
 public:
  void complain(const std::string& level);

 private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
  void nothing(void);
};

#endif
