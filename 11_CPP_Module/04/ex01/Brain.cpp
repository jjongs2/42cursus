#include "Brain.hpp"

#include <iostream>

Brain::Brain() {
  std::cout << kBrain << kMessages[kDefaultConstructor] << kSuffix << '\n';
  for (int i = 0; i < kNumOfIdeas; ++i) {
    this->ideas_[i] = kUndefined;
  }
}

Brain::Brain(const Brain& origin) {
  std::cout << kBrain << kMessages[kCopyConstructor] << kSuffix << '\n';
  *this = origin;
}

Brain& Brain::operator=(const Brain& origin) {
  std::cout << kBrain << kMessages[kCopyAssignmentOperator] << kSuffix << '\n';
  if (this != &origin) {
    for (int i = 0; i < kNumOfIdeas; ++i) {
      this->ideas_[i] = origin.getIdea(i);
    }
  }
  return *this;
}

Brain::~Brain() {
  std::cout << kBrain << kMessages[kDestructor] << kSuffix << std::endl;
}

std::string Brain::getIdea(const int index) const {
  return this->ideas_[index];
}

void Brain::setIdea(const int index, const std::string& idea) {
  this->ideas_[index] = idea;
}
