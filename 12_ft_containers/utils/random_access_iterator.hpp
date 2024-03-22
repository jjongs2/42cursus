#ifndef RANDOM_ACCEESS_ITERATOR_HPP_
#define RANDOM_ACCEESS_ITERATOR_HPP_

#include <iterator>

#include "iterator_traits.hpp"

namespace ft {

template <typename T>
class random_access_iterator
    : public std::iterator<std::random_access_iterator_tag, T> {
 public:
  typedef T* iterator_type;
  typedef
      typename iterator_traits<iterator_type>::difference_type difference_type;
  typedef typename iterator_traits<iterator_type>::pointer pointer;
  typedef typename iterator_traits<iterator_type>::reference reference;

  explicit random_access_iterator(iterator_type iterator = iterator_type())
      : current_(iterator) {}

  template <typename U>
  random_access_iterator(const random_access_iterator<U>& origin)
      : current_(origin.base()) {}

  template <typename U>
  random_access_iterator operator=(const random_access_iterator<U>& origin) {
    current_ = origin.base();
    return *this;
  }

  iterator_type base(void) const { return current_; }
  reference operator*() const { return *current_; }
  pointer operator->() const { return current_; }
  reference operator[](difference_type index) const { return current_[index]; }

  random_access_iterator& operator++() {
    current_ += 1;
    return *this;
  }

  random_access_iterator operator++(int) {
    random_access_iterator before = *this;
    current_ += 1;
    return before;
  }

  random_access_iterator& operator+=(difference_type difference) {
    current_ += difference;
    return *this;
  }

  random_access_iterator operator+(difference_type difference) const {
    return random_access_iterator(current_ + difference);
  }

  random_access_iterator& operator--() {
    current_ -= 1;
    return *this;
  }

  random_access_iterator operator--(int) {
    random_access_iterator before = *this;
    current_ -= 1;
    return before;
  }

  random_access_iterator& operator-=(difference_type difference) {
    current_ -= difference;
    return *this;
  }

  random_access_iterator operator-(difference_type difference) const {
    return random_access_iterator(current_ - difference);
  }

 private:
  iterator_type current_;
};

template <typename Iterator1, typename Iterator2>
bool operator==(const random_access_iterator<Iterator1>& left,
                const random_access_iterator<Iterator2>& right) {
  return (left.base() == right.base());
}

template <typename Iterator1, typename Iterator2>
bool operator!=(const random_access_iterator<Iterator1>& left,
                const random_access_iterator<Iterator2>& right) {
  return !(left == right);
}

template <typename Iterator1, typename Iterator2>
bool operator<(const random_access_iterator<Iterator1>& left,
               const random_access_iterator<Iterator2>& right) {
  return (left.base() < right.base());
}

template <typename Iterator1, typename Iterator2>
bool operator<=(const random_access_iterator<Iterator1>& left,
                const random_access_iterator<Iterator2>& right) {
  return !(right < left);
}

template <typename Iterator1, typename Iterator2>
bool operator>(const random_access_iterator<Iterator1>& left,
               const random_access_iterator<Iterator2>& right) {
  return (right < left);
}

template <typename Iterator1, typename Iterator2>
bool operator>=(const random_access_iterator<Iterator1>& left,
                const random_access_iterator<Iterator2>& right) {
  return !(left < right);
}

template <typename Iterator>
random_access_iterator<Iterator> operator+(
    typename random_access_iterator<Iterator>::difference_type difference,
    const random_access_iterator<Iterator>& iterator) {
  return random_access_iterator<Iterator>(iterator.base() + difference);
}

template <typename Iterator1, typename Iterator2>
typename random_access_iterator<Iterator1>::difference_type operator-(
    const random_access_iterator<Iterator1>& left,
    const random_access_iterator<Iterator2>& right) {
  return left.base() - right.base();
}

}  // namespace ft

#endif
