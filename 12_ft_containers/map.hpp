#ifndef MAP_HPP_
#define MAP_HPP_

#include <functional>
#include <memory>

#include "exception.hpp"
#include "llrb.hpp"
#include "pair.hpp"
#include "reverse_iterator.hpp"

namespace ft {

template <typename Key, typename T, typename Compare = std::less<Key>,
          typename Allocator = std::allocator<ft::pair<const Key, T> > >
class map {
 public:
  typedef Key key_type;
  typedef T mapped_type;
  typedef ft::pair<const key_type, mapped_type> value_type;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef Compare key_compare;
  typedef Allocator allocator_type;

  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;

  class value_compare
      : public std::binary_function<value_type, value_type, bool> {
    friend class map;

   public:
    bool operator()(const value_type& lhs, const value_type& rhs) const {
      return compare_(lhs.first, rhs.first);
    }

    bool operator()(const value_type& lhs, const key_type& rhs) const {
      return compare_(lhs.first, rhs);
    }

    bool operator()(const key_type& lhs, const value_type& rhs) const {
      return compare_(lhs, rhs.first);
    }

    bool operator()(const key_type& lhs, const key_type& rhs) const {
      return compare_(lhs, rhs);
    }

   protected:
    value_compare(key_compare compare) : compare_(compare) {}
    key_compare compare_;
  };

 private:
  typedef typename ft::llrb<key_type, value_type, value_compare, allocator_type>
      llrb;

 public:
  typedef typename llrb::iterator iterator;
  typedef typename llrb::const_iterator const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

  map() : tree_(value_compare(key_compare()), allocator_type()) {}

  explicit map(const value_compare& compare,
               const allocator_type& allocator = allocator_type())
      : tree_(compare, allocator) {}

  template <typename InputIterator>
  map(InputIterator first, InputIterator last,
      const value_compare& compare = value_compare(key_compare()),
      const allocator_type& allocator = allocator_type())
      : tree_(compare, allocator) {
    tree_.insert(first, last);
  }

  map(const map& origin) : tree_(origin.tree_) {}

  ~map() {}

  map& operator=(const map& origin) {
    if (this != &origin) {
      tree_ = origin.tree_;
    }
    return *this;
  }

  allocator_type get_allocator(void) const { return tree_.get_allocator(); }

  mapped_type& at(const key_type& key) {
    iterator position = lower_bound(key);
    if (position == end() || key_comp()(key, position->first)) {
      throw ft::out_of_range(kMap);
    }
    return position->second;
  }

  const mapped_type& at(const key_type& key) const {
    const_iterator position = lower_bound(key);
    if (position == end() || key_comp()(key, position->first)) {
      throw ft::out_of_range(kMap);
    }
    return position->second;
  }

  mapped_type& operator[](const key_type& key) {
    iterator position = lower_bound(key);
    if (position == end() || key_comp()(key, position->first)) {
      position = insert(position, value_type(key, mapped_type()));
    }
    return position->second;
  }

  iterator begin(void) { return tree_.begin(); }
  const_iterator begin(void) const { return tree_.begin(); }
  iterator end(void) { return tree_.end(); }
  const_iterator end(void) const { return tree_.end(); }
  reverse_iterator rbegin(void) { return tree_.rbegin(); }
  const_reverse_iterator rbegin(void) const { return tree_.rbegin(); }
  reverse_iterator rend(void) { return tree_.rend(); }
  const_reverse_iterator rend(void) const { return tree_.rend(); }

  bool empty(void) const { return tree_.empty(); }
  size_type size(void) const { return tree_.size(); }
  size_type max_size(void) const { return tree_.max_size(); }

  void clear(void) { tree_.clear(); }

  ft::pair<iterator, bool> insert(const_reference value) {
    return tree_.insert(value);
  }

  iterator insert(iterator position, const_reference value) {
    return tree_.insert(position, value);
  }

  template <class InputIterator>
  void insert(InputIterator first, InputIterator last) {
    tree_.insert(first, last);
  }

  void erase(iterator position) { tree_.erase(*position); }
  void erase(iterator first, iterator last) { tree_.erase(first, last); }
  size_type erase(const key_type& key) { return tree_.erase(key); }

  void swap(map& other) { tree_.swap(other.tree_); }

  size_type count(const key_type& key) const {
    return (tree_.find(key) != tree_.end()) ? 1 : 0;
  }

  iterator find(const key_type& key) { return tree_.find(key); }
  const_iterator find(const key_type& key) const { return tree_.find(key); }

  ft::pair<iterator, iterator> equal_range(const key_type& key) {
    return tree_.equal_range(key);
  }

  ft::pair<const_iterator, const_iterator> equal_range(
      const key_type& key) const {
    return tree_.equal_range(key);
  }

  iterator lower_bound(const key_type& key) { return tree_.lower_bound(key); }

  const_iterator lower_bound(const key_type& key) const {
    return tree_.lower_bound(key);
  }

  iterator upper_bound(const key_type& key) { return tree_.upper_bound(key); }

  const_iterator upper_bound(const key_type& key) const {
    return tree_.upper_bound(key);
  }

  key_compare key_comp(void) const { return tree_.key_comp().compare_; }
  value_compare value_comp(void) const { return tree_.key_comp(); }

  template <typename K, typename M, typename Comp, typename Alloc>
  friend bool operator==(const map<K, M, Comp, Alloc>& lhs,
                         const map<K, M, Comp, Alloc>& rhs);

  template <typename K, typename M, typename Comp, typename Alloc>
  friend bool operator<(const map<K, M, Comp, Alloc>& lhs,
                        const map<K, M, Comp, Alloc>& rhs);

 private:
  llrb tree_;
};

template <typename Key, typename T, typename Compare, typename Allocator>
bool operator==(const map<Key, T, Compare, Allocator>& lhs,
                const map<Key, T, Compare, Allocator>& rhs) {
  return (lhs.tree_ == rhs.tree_);
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool operator!=(const map<Key, T, Compare, Allocator>& lhs,
                const map<Key, T, Compare, Allocator>& rhs) {
  return !(lhs == rhs);
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool operator<(const map<Key, T, Compare, Allocator>& lhs,
               const map<Key, T, Compare, Allocator>& rhs) {
  return (lhs.tree_ < rhs.tree_);
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool operator<=(const map<Key, T, Compare, Allocator>& lhs,
                const map<Key, T, Compare, Allocator>& rhs) {
  return !(rhs < lhs);
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool operator>(const map<Key, T, Compare, Allocator>& lhs,
               const map<Key, T, Compare, Allocator>& rhs) {
  return (rhs < lhs);
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool operator>=(const map<Key, T, Compare, Allocator>& lhs,
                const map<Key, T, Compare, Allocator>& rhs) {
  return !(lhs < rhs);
}

template <typename Key, typename T, typename Compare, typename Allocator>
void swap(map<Key, T, Compare, Allocator>& map1,
          map<Key, T, Compare, Allocator>& map2) {
  map1.swap(map2);
}

}  // namespace ft

#endif
