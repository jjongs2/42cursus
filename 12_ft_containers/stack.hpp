#ifndef STACK_HPP_
#define STACK_HPP_

#include "vector.hpp"

namespace ft {

template <typename T, typename Container = vector<T> >
class stack {
 public:
  typedef Container container_type;
  typedef typename container_type::value_type value_type;
  typedef typename container_type::size_type size_type;
  typedef typename container_type::reference reference;
  typedef typename container_type::const_reference const_reference;

  explicit stack(const container_type& container = container_type())
      : c(container) {}

  reference top(void) { return c.back(); }
  const_reference top(void) const { return c.back(); }

  bool empty(void) const { return c.empty(); }
  size_type size(void) const { return c.size(); }

  void push(const value_type& element) { c.push_back(element); }
  void pop(void) { c.pop_back(); }

  template <typename V, typename C>
  friend bool operator==(const stack<V, C>& left, const stack<V, C>& right);

  template <typename V, typename C>
  friend bool operator<(const stack<V, C>& left, const stack<V, C>& right);

 protected:
  container_type c;
};

template <typename T, typename Container>
bool operator==(const stack<T, Container>& left,
                const stack<T, Container>& right) {
  return (left.c == right.c);
}

template <typename T, typename Container>
bool operator!=(const stack<T, Container>& left,
                const stack<T, Container>& right) {
  return !(left == right);
}

template <typename T, typename Container>
bool operator<(const stack<T, Container>& left,
               const stack<T, Container>& right) {
  return (left.c < right.c);
}

template <typename T, typename Container>
bool operator<=(const stack<T, Container>& left,
                const stack<T, Container>& right) {
  return !(right < left);
}

template <typename T, typename Container>
bool operator>(const stack<T, Container>& left,
               const stack<T, Container>& right) {
  return (right < left);
}

template <typename T, typename Container>
bool operator>=(const stack<T, Container>& left,
                const stack<T, Container>& right) {
  return !(left < right);
}

}  // namespace ft

#endif
