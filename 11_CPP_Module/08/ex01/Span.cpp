#include "Span.hpp"

#include <iostream>
#include <numeric>

Span::Span() {}

Span::Span(unsigned int N) { this->numbers_.reserve(N); }

Span::Span(const Span& origin) { *this = origin; }

Span& Span::operator=(const Span& origin) {
  if (this != &origin) {
    this->numbers_ = origin.getNumbers();
  }
  return *this;
}

Span::~Span() {}

const vector& Span::getNumbers(void) const { return this->numbers_; }

void Span::setNumbers(const vector& numbers) { this->numbers_ = numbers; }

size_t Span::size(void) const { return this->numbers_.size(); }

vector::iterator Span::begin(void) { return this->numbers_.begin(); }

vector::iterator Span::end(void) { return this->numbers_.end(); }

void Span::addNumber(int number) {
  if (this->size() == this->numbers_.capacity()) {
    throw std::out_of_range(kErrors[kOverflow]);
  }
  this->numbers_.push_back(number);
}

long long Span::shortestSpan(void) const {
  if (this->size() < 2) {
    throw std::logic_error(kErrors[kNoSpan]);
  }
  vector sorted(this->numbers_);
  std::sort(sorted.begin(), sorted.end());

  std::vector<long long> distances(sorted.size());
  std::adjacent_difference(sorted.begin(), sorted.end(), distances.begin());
  return *std::min_element(distances.begin() + 1, distances.end());
}

long long Span::longestSpan(void) {
  if (this->size() < 2) {
    throw std::logic_error(kErrors[kNoSpan]);
  }
  int min = *std::min_element(this->begin(), this->end());
  int max = *std::max_element(this->begin(), this->end());
  return max - min;
}

void Span::print(size_t first, size_t last) const {
  if (last > this->size()) {
    throw std::out_of_range(kErrors[kRange]);
  }
  for (size_t i = first; i < last; ++i) {
    std::cout << this->numbers_.at(i);
    if (i == last - 1) break;
    std::cout << ", ";
  }
  std::cout << '\n';
}
