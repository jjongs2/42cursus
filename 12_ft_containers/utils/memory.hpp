#ifndef MEMORY_HPP_
#define MEMORY_HPP_

namespace ft {

template <typename InputIterator, typename NoThrowForwardIterator,
          typename Allocator>
NoThrowForwardIterator uninitialized_copy(InputIterator first,
                                          InputIterator last,
                                          NoThrowForwardIterator d_first,
                                          Allocator allocator) {
  NoThrowForwardIterator current = d_first;
  try {
    while (first != last) {
      allocator.construct(current, *first);
      ++current;
      ++first;
    }
    return current;
  } catch (...) {
    while (d_first != current) {
      allocator.destroy(d_first);
      ++d_first;
    }
    throw;
  }
}

template <typename ForwardIterator, typename Size, typename T,
          typename Allocator>
ForwardIterator uninitialized_fill_n(ForwardIterator first, Size count,
                                     const T& value, Allocator allocator) {
  ForwardIterator current = first;
  try {
    while (count > 0) {
      allocator.construct(current, value);
      ++current;
      count -= 1;
    }
    return current;
  } catch (...) {
    while (first != current) {
      allocator.destroy(first);
      ++first;
    }
    throw;
  }
}

}  // namespace ft

#endif
