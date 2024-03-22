#ifndef COMPARE_HPP_
#define COMPARE_HPP_

namespace ft {

template <typename InputIterator1, typename InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
  while (first1 != last1) {
    if (!(*first1 == *first2)) return false;
    ++first1;
    ++first2;
  }
  return true;
}

template <typename InputIterator1, typename InputIterator2,
          typename BinaryPredicate>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
           BinaryPredicate predicate) {
  while (first1 != last1) {
    if (!predicate(*first1, *first2)) return false;
    ++first1;
    ++first2;
  }
  return true;
}

template <typename InputIterator1, typename InputIterator2>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                             InputIterator2 first2, InputIterator2 last2) {
  while ((first1 != last1) && (first2 != last2)) {
    if (*first1 < *first2) return true;
    if (*first2 < *first1) return false;
    ++first1;
    ++first2;
  }
  return (first1 == last1) && (first2 != last2);
}

template <typename InputIterator1, typename InputIterator2, typename Compare>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                             InputIterator2 first2, InputIterator2 last2,
                             Compare compare) {
  while ((first1 != last1) && (first2 != last2)) {
    if (compare(*first1, *first2)) return true;
    if (compare(*first2, *first1)) return false;
    ++first1;
    ++first2;
  }
  return (first1 == last1) && (first2 != last2);
}

}  // namespace ft

#endif
