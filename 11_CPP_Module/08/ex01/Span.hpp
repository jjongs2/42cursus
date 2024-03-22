#ifndef SPAN_HPP_
#define SPAN_HPP_

#include <algorithm>
#include <vector>

#include "constant.hpp"

typedef std::vector<int> vector;

class Span {
 public:
  Span();
  explicit Span(unsigned int N);
  Span(const Span& origin);
  Span& operator=(const Span& origin);
  virtual ~Span();

  const vector& getNumbers(void) const;
  void setNumbers(const vector& numbers);

  size_t size(void) const;
  vector::iterator begin(void);
  vector::iterator end(void);

  template <typename InputIterator>
  void insert(vector::iterator position, InputIterator first,
              InputIterator last) {
    this->numbers_.insert(position, first, last);
  }

  void addNumber(int number);
  long long shortestSpan(void) const;
  long long longestSpan(void);
  void print(size_t first, size_t last) const;

 private:
  vector numbers_;
};

#endif
