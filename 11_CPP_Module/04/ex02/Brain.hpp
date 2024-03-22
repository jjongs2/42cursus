#ifndef BRAIN_HPP_
#define BRAIN_HPP_

#include <string>

#include "constant.hpp"

class Brain {
 public:
  Brain();
  Brain(const Brain& origin);
  Brain& operator=(const Brain& origin);
  virtual ~Brain();

  const std::string& getIdea(const int index) const;
  void setIdea(const int index, const std::string& idea); 

 private:
  std::string ideas_[kNumOfIdeas];
};

#endif
