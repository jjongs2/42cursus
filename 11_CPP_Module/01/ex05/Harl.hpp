#ifndef HARL_HPP_
#define HARL_HPP_

#include "constant.hpp"

class Harl {
 public:
  Harl();

  void complain(const std::string& level);

 private:
  void (Harl::*functions[kNumOfLevels])(void);
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
};

#endif
