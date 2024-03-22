#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#include <algorithm>
#include <iterator>

#include "compare.hpp"
#include "distance.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "memory.hpp"
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "validator.hpp"

namespace ft {

template <typename T, typename Allocator = std::allocator<T> >
class vector {
 public:
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;

  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;

  typedef random_access_iterator<value_type> iterator;
  typedef random_access_iterator<const value_type> const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

  explicit vector(const allocator_type& allocator = allocator_type())
      : begin_(NULL),
        end_(NULL),
        end_of_allocated_(NULL),
        allocator_(allocator) {}

  explicit vector(size_type count, const_reference value = value_type(),
                  const allocator_type& allocator = allocator_type())
      : allocator_(allocator) {
    initialize(count);
    ft::uninitialized_fill_n(begin_, count, value, allocator);
  }

  template <typename InputIterator>
  vector(InputIterator first, InputIterator last,
         const allocator_type& allocator = allocator_type(),
         typename enable_if<!is_integral<InputIterator>::value>::type* = NULL)
      : allocator_(allocator) {
    initialize(ft::distance(first, last));
    ft::uninitialized_copy(first, last, begin_, allocator);
  }

  vector(const vector& origin) : allocator_(origin.allocator_) {
    initialize(origin.size());
    ft::uninitialized_copy(origin.begin_, origin.end_, begin_, allocator_);
  }

  ~vector() {
    destroy(begin_, end_);
    deallocate(begin_, capacity());
  }

  vector& operator=(const vector& origin) {
    if (this != &origin) {
      assign(origin.begin_, origin.end_);
    }
    return *this;
  }

  void assign(size_type count, const_reference value) {
    if (count > capacity()) {
      vector temp(count, value, allocator_);
      swap(temp);
      return;
    }
    if (count > size()) {
      std::fill(begin_, end_, value);
      end_ = ft::uninitialized_fill_n(end_, count - size(), value, allocator_);
      return;
    }
    std::fill_n(begin_, count, value);
    erase(begin() + count, end());
  }

  template <typename InputIterator>
  void assign(
      InputIterator first, InputIterator last,
      typename enable_if<!is_integral<InputIterator>::value>::type* = NULL) {
    iterator current(begin_);
    while (current != end() && first != last) {
      *current = *first;
      current += 1;
      ++first;
    }
    if (current == end()) {
      insert(end(), first, last);
      return;
    }
    erase(current, end());
  }

  allocator_type get_allocator(void) const { return allocator_; }

  reference at(size_type index) {
    validator::vector_range(index, size());
    return begin_[index];
  }
  const_reference at(size_type index) const {
    validator::vector_range(index, size());
    return begin_[index];
  }
  reference operator[](size_type index) { return begin_[index]; }
  const_reference operator[](size_type index) const { return begin_[index]; }
  reference front(void) { return *begin_; }
  const_reference front(void) const { return *begin_; }
  reference back(void) { return *(end_ - 1); }
  const_reference back(void) const { return *(end_ - 1); }
  pointer data(void) { return pointer(begin_); }
  const_pointer data(void) const { return const_pointer(begin_); }

  iterator begin(void) { return iterator(begin_); }
  const_iterator begin(void) const { return const_iterator(begin_); }
  iterator end(void) { return iterator(end_); }
  const_iterator end(void) const { return const_iterator(end_); }
  reverse_iterator rbegin(void) { return reverse_iterator(end()); }
  const_reverse_iterator rbegin(void) const {
    return const_reverse_iterator(end());
  }
  reverse_iterator rend(void) { return reverse_iterator(begin()); }
  const_reverse_iterator rend(void) const {
    return const_reverse_iterator(begin());
  }

  bool empty(void) const { return (begin_ == end_); }
  size_type size(void) const { return size_type(end_ - begin_); }
  size_type max_size(void) const { return allocator_.max_size(); }

  void reserve(size_type new_cap) {
    if (new_cap <= capacity()) return;
    size_type count = size();
    pointer allocated = allocate(new_cap);
    try {
      ft::uninitialized_copy(begin_, end_, allocated, allocator_);
    } catch (...) {
      deallocate(allocated, new_cap);
      throw;
    }
    deallocate(begin_, end_of_allocated_ - begin_);
    begin_ = allocated;
    end_ = begin_ + count;
    end_of_allocated_ = begin_ + new_cap;
  }

  size_type capacity(void) const {
    return size_type(end_of_allocated_ - begin_);
  }

  void clear(void) { erase(begin(), end()); }

  iterator insert(iterator position, const_reference value) {
    difference_type index = position - begin();
    insert(position, 1, value);
    return begin() + index;
  }

  void insert(iterator position, size_type count, const_reference value) {
    difference_type index = position - begin();
    if (count > size_type(end_of_allocated_ - end_)) {
      reserve(new_capacity(size() + count));
    }
    pointer new_position = begin_ + index;
    pointer old_end = end_;
    size_type count_to_copy = old_end - new_position;
    if (count <= count_to_copy) {
      ft::uninitialized_copy(end_ - count, end_, end_, allocator_);
      end_ += count;
      std::copy_backward(new_position, old_end - count, old_end);
      std::fill(new_position, new_position + count, value);
    } else {
      size_type count_to_fill = count - count_to_copy;
      ft::uninitialized_fill_n(end_, count_to_fill, value, allocator_);
      end_ += count_to_fill;
      ft::uninitialized_copy(new_position, old_end, end_, allocator_);
      end_ += count_to_copy;
      std::fill(new_position, old_end, value);
    }
  }

  template <typename InputIterator>
  void insert(
      iterator position, InputIterator first, InputIterator last,
      typename enable_if<!is_integral<InputIterator>::value>::type* = NULL) {
    while (first != last) {
      position = insert(position, *first) + 1;
      ++first;
    }
  }

  iterator erase(iterator position) {
    if (position + 1 != end()) {
      std::copy(position + 1, end(), position);
    }
    pop_back();
    return position;
  }

  iterator erase(iterator first, iterator last) {
    const difference_type count = last - first;
    std::copy(last, end(), first);
    destroy(end_ - count, end_);
    end_ -= count;
    return first;
  }

  void push_back(const_reference value) {
    if (end_ == end_of_allocated_) {
      reserve(new_capacity(size() + 1));
    }
    allocator_.construct(end_, value);
    end_ += 1;
  }

  void pop_back(void) {
    end_ -= 1;
    allocator_.destroy(end_);
  }

  void resize(size_type count, value_type value = value_type()) {
    const size_type old_size = size();
    if (count < old_size) {
      erase(begin() + count, end());
      return;
    }
    insert(end(), count - old_size, value);
  }

  void swap(vector& other) {
    std::swap(begin_, other.begin_);
    std::swap(end_, other.end_);
    std::swap(end_of_allocated_, other.end_of_allocated_);
    std::swap(allocator_, other.allocator_);
  }

 private:
  size_type new_capacity(size_type target_cap) {
    size_type new_cap = capacity();
    if (new_cap == 0) {
      new_cap = 1;
    }
    while (new_cap < target_cap) {
      new_cap <<= 1;
    }
    return new_cap;
  }

  pointer allocate(size_type size) {
    validator::vector_capacity(size, max_size());
    return allocator_.allocate(size);
  }

  void deallocate(pointer ptr, size_type size) {
    if (!ptr) return;
    allocator_.deallocate(ptr, size);
  }

  void destroy(pointer first, pointer last) {
    while (first != last) {
      allocator_.destroy(first);
      first += 1;
    }
  }

  void initialize(size_type size) {
    begin_ = allocate(size);
    end_ = begin_ + size;
    end_of_allocated_ = end_;
  }

  pointer begin_;
  pointer end_;
  pointer end_of_allocated_;
  allocator_type allocator_;
};

template <typename T, typename Allocator>
bool operator==(const vector<T, Allocator>& left,
                const vector<T, Allocator>& right) {
  return (left.size() == right.size()) &&
         ft::equal(left.begin(), left.end(), right.begin());
}

template <typename T, typename Allocator>
bool operator!=(const vector<T, Allocator>& left,
                const vector<T, Allocator>& right) {
  return !(left == right);
}

template <typename T, typename Allocator>
bool operator<(const vector<T, Allocator>& left,
               const vector<T, Allocator>& right) {
  return ft::lexicographical_compare(left.begin(), left.end(), right.begin(),
                                     right.end());
}

template <typename T, typename Allocator>
bool operator<=(const vector<T, Allocator>& left,
                const vector<T, Allocator>& right) {
  return !(right < left);
}

template <typename T, typename Allocator>
bool operator>(const vector<T, Allocator>& left,
               const vector<T, Allocator>& right) {
  return (right < left);
}

template <typename T, typename Allocator>
bool operator>=(const vector<T, Allocator>& left,
                const vector<T, Allocator>& right) {
  return !(left < right);
}

template <typename T, typename Allocator>
void swap(vector<T, Allocator>& vector1, vector<T, Allocator>& vector2) {
  vector1.swap(vector2);
}

}  // namespace ft

#endif
