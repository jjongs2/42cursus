#ifndef DISTANCE_HPP_
#define DISTANCE_HPP_

#include "iterator_traits.hpp"

namespace ft {

template <typename InputIterator>
typename iterator_traits<InputIterator>::difference_type distance(
    InputIterator first, InputIterator last) {
  typename iterator_traits<InputIterator>::difference_type n = 0;
  while (first != last) {
    ++first;
    n += 1;
  }
  return n;
}

}  // namespace ft

#endif
