#ifndef MUTANTSTACK_HPP_
#define MUTANTSTACK_HPP_

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  typedef typename std::stack<T>::container_type container;
  typedef typename container::iterator iterator;
  typedef typename container::reverse_iterator reverse_iterator;
  typedef typename container::const_iterator const_iterator;
  typedef typename container::const_reverse_iterator const_reverse_iterator;

  MutantStack() : std::stack<T>() {}
  MutantStack(const MutantStack& origin) : std::stack<T>() { *this = origin; }
  MutantStack& operator=(const MutantStack& origin) {
    std::stack<T>::operator=(origin);
    return *this;
  }
  ~MutantStack() {}

  iterator begin(void) { return this->c.begin(); }
  iterator end(void) { return this->c.end(); }
  reverse_iterator rbegin(void) { return this->c.rbegin(); }
  reverse_iterator rend(void) { return this->c.rend(); }
  const_iterator cbegin(void) { return this->c.cbegin(); }
  const_iterator cend(void) { return this->c.cend(); }
  const_reverse_iterator crbegin(void) { return this->c.crbegin(); }
  const_reverse_iterator crend(void) { return this->c.crend(); }
};

template <typename InputIterator>
void print(InputIterator first, InputIterator last) {
  if (first >= last) return;
  while (true) {
    std::cout << *first;
    if (first == last - 1) break;
    std::cout << ", ";
    first += 1;
  }
  std::cout << '\n';
}

#endif
