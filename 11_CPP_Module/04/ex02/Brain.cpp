#include "Brain.hpp"

#include <cstring>
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

const std::string& Brain::getIdea(const int index) const {
  if (index < 0 || index >= kNumOfIdeas) {
    return kError;
  }
  return this->ideas_[index];
}

void Brain::setIdea(const int index, const std::string& idea) {
  if (index < 0 || index >= kNumOfIdeas) return;
  this->ideas_[index] = idea;
}
