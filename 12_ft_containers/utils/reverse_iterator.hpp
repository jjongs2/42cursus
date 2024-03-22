#ifndef REVERSE_ITERATOR_HPP_
#define REVERSE_ITERATOR_HPP_

#include <iterator>

#include "iterator_traits.hpp"

namespace ft {

template <typename Iterator>
class reverse_iterator
    : public std::iterator<
          typename iterator_traits<Iterator>::iterator_category,
          typename iterator_traits<Iterator>::value_type,
          typename iterator_traits<Iterator>::difference_type,
          typename iterator_traits<Iterator>::pointer,
          typename iterator_traits<Iterator>::reference> {
 public:
  typedef Iterator iterator_type;
  typedef typename iterator_traits<Iterator>::difference_type difference_type;
  typedef typename iterator_traits<Iterator>::pointer pointer;
  typedef typename iterator_traits<Iterator>::reference reference;

  explicit reverse_iterator(iterator_type iterator = iterator_type())
      : current_(iterator) {}

  template <typename T>
  reverse_iterator(const reverse_iterator<T>& origin)
      : current_(origin.base()) {}

  template <typename T>
  reverse_iterator operator=(const reverse_iterator<T>& origin) {
    current_ = origin.base();
    return *this;
  }

  iterator_type base(void) const { return current_; }
  reference operator*() const {
    iterator_type temp = current_;
    return *(--temp);
  }
  pointer operator->() const { return &(operator*()); }
  reference operator[](difference_type index) const { return *(*this + index); }

  reverse_iterator& operator++() {
    --current_;
    return *this;
  }

  reverse_iterator operator++(int) {
    reverse_iterator before = *this;
    --current_;
    return before;
  }

  reverse_iterator& operator+=(difference_type difference) {
    current_ -= difference;
    return *this;
  }

  reverse_iterator operator+(difference_type difference) const {
    return reverse_iterator(current_ - difference);
  }

  reverse_iterator& operator--() {
    ++current_;
    return *this;
  }

  reverse_iterator operator--(int) {
    reverse_iterator before = *this;
    ++current_;
    return before;
  }

  reverse_iterator& operator-=(difference_type difference) {
    current_ += difference;
    return *this;
  }

  reverse_iterator operator-(difference_type difference) const {
    return reverse_iterator(current_ + difference);
  }

 private:
  iterator_type current_;
};

template <typename Iterator1, typename Iterator2>
bool operator==(const reverse_iterator<Iterator1>& left,
                const reverse_iterator<Iterator2>& right) {
  return (left.base() == right.base());
}

template <typename Iterator1, typename Iterator2>
bool operator!=(const reverse_iterator<Iterator1>& left,
                const reverse_iterator<Iterator2>& right) {
  return !(left == right);
}

template <typename Iterator1, typename Iterator2>
bool operator<(const reverse_iterator<Iterator1>& left,
               const reverse_iterator<Iterator2>& right) {
  return (right.base() < left.base());
}

template <typename Iterator1, typename Iterator2>
bool operator<=(const reverse_iterator<Iterator1>& left,
                const reverse_iterator<Iterator2>& right) {
  return !(right < left);
}

template <typename Iterator1, typename Iterator2>
bool operator>(const reverse_iterator<Iterator1>& left,
               const reverse_iterator<Iterator2>& right) {
  return (right < left);
}

template <typename Iterator1, typename Iterator2>
bool operator>=(const reverse_iterator<Iterator1>& left,
                const reverse_iterator<Iterator2>& right) {
  return !(left < right);
}

template <typename Iterator>
reverse_iterator<Iterator> operator+(
    typename reverse_iterator<Iterator>::difference_type difference,
    const reverse_iterator<Iterator>& iterator) {
  return reverse_iterator<Iterator>(iterator.base() - difference);
}

template <typename Iterator1, typename Iterator2>
typename reverse_iterator<Iterator1>::difference_type operator-(
    const reverse_iterator<Iterator1>& left,
    const reverse_iterator<Iterator2>& right) {
  return right.base() - left.base();
}

}  // namespace ft

#endif
