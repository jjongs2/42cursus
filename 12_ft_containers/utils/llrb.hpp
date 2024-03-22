#ifndef LLRB_HPP_
#define LLRB_HPP_

#include <algorithm>
#include <iterator>
#include <memory>

#include "compare.hpp"
#include "distance.hpp"
#include "pair.hpp"
#include "reverse_iterator.hpp"

namespace ft {

enum node_color { kBlack = false, kRed = true };

template <typename T>
struct llrb_node {
  typedef T value_type;
  typedef llrb_node* link_type;
  typedef const llrb_node* const_link_type;

  llrb_node(const value_type& value)
      : color(kRed), value(value), parent(NULL), left(NULL), right(NULL) {}

  static link_type min(link_type link) {
    while (link->left) {
      link = link->left;
    }
    return link;
  }

  static const_link_type min(const_link_type link) {
    while (link->left) {
      link = link->left;
    }
    return link;
  }

  static link_type max(link_type link) {
    while (link->right) {
      link = link->right;
    }
    return link;
  }

  static const_link_type max(const_link_type link) {
    while (link->right) {
      link = link->right;
    }
    return link;
  }

  static link_type increment(link_type link) {
    if (link->right) {
      return llrb_node::min(link->right);
    }
    link_type parent = link->parent;
    while (link == parent->right) {
      link = parent;
      parent = link->parent;
    }
    return parent;
  }

  static const_link_type increment(const_link_type link) {
    if (link->right) {
      return llrb_node::min(link->right);
    }
    link_type parent = link->parent;
    while (link == parent->right) {
      link = parent;
      parent = link->parent;
    }
    return parent;
  }

  static link_type decrement(link_type link) {
    if (link->left) {
      return llrb_node::max(link->left);
    }
    link_type parent = link->parent;
    while (link == parent->left) {
      link = parent;
      parent = link->parent;
    }
    return parent;
  }

  static const_link_type decrement(const_link_type link) {
    if (link->left) {
      return llrb_node::max(link->left);
    }
    link_type parent = link->parent;
    while (link == parent->left) {
      link = parent;
      parent = link->parent;
    }
    return parent;
  }

  bool color;
  value_type value;
  link_type parent;
  link_type left;
  link_type right;
};

template <typename T>
struct llrb_iterator {
  typedef T value_type;
  typedef T& reference;
  typedef T* pointer;
  typedef llrb_node<T> node;
  typedef node* link_type;
  typedef ptrdiff_t difference_type;
  typedef std::bidirectional_iterator_tag iterator_category;

  explicit llrb_iterator(link_type link = NULL) : link(link) {}

  reference operator*() const { return link->value; }
  pointer operator->() const { return &(operator*()); }

  llrb_iterator& operator++() {
    link = node::increment(link);
    return *this;
  }

  llrb_iterator operator++(int) {
    llrb_iterator before = *this;
    link = node::increment(link);
    return before;
  }

  llrb_iterator& operator--() {
    link = node::decrement(link);
    return *this;
  }

  llrb_iterator operator--(int) {
    llrb_iterator before = *this;
    link = node::decrement(link);
    return before;
  }

  bool operator==(const llrb_iterator& rhs) const { return (link == rhs.link); }
  bool operator!=(const llrb_iterator& rhs) const { return (link != rhs.link); }

  link_type link;
};

template <typename T>
struct llrb_const_iterator {
  typedef T value_type;
  typedef const T& reference;
  typedef const T* pointer;
  typedef llrb_node<T> node;
  typedef const node* const_link_type;
  typedef ptrdiff_t difference_type;
  typedef std::bidirectional_iterator_tag iterator_category;

  explicit llrb_const_iterator(const_link_type link = NULL) : link(link) {}
  llrb_const_iterator(const llrb_iterator<value_type>& origin)
      : link(origin.link) {}

  reference operator*() const { return link->value; }
  pointer operator->() const { return &(operator*()); }

  llrb_const_iterator& operator++() {
    link = node::increment(link);
    return *this;
  }

  llrb_const_iterator operator++(int) {
    llrb_const_iterator before = *this;
    link = node::increment(link);
    return before;
  }

  llrb_const_iterator& operator--() {
    link = node::decrement(link);
    return *this;
  }

  llrb_const_iterator operator--(int) {
    llrb_const_iterator before = *this;
    link = node::decrement(link);
    return before;
  }

  bool operator==(const llrb_const_iterator& rhs) const {
    return (link == rhs.link);
  }

  bool operator!=(const llrb_const_iterator& rhs) const {
    return (link != rhs.link);
  }

  const_link_type link;
};

template <typename T>
bool operator==(const llrb_iterator<T>& lhs,
                const llrb_const_iterator<T>& rhs) {
  return (lhs.link == rhs.link);
}

template <typename T>
bool operator!=(const llrb_iterator<T>& lhs,
                const llrb_const_iterator<T>& rhs) {
  return (lhs.link != rhs.link);
}

template <typename Key, typename T, typename Compare, typename Allocator>
class llrb {
 public:
  typedef Key key_type;
  typedef T value_type;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef Compare key_compare;
  typedef Allocator allocator_type;
  typedef llrb_node<value_type> node;
  typedef typename Allocator::template rebind<node>::other node_allocator;

  typedef typename node_allocator::reference reference;
  typedef typename node_allocator::const_reference const_reference;
  typedef typename node_allocator::pointer pointer;
  typedef typename node_allocator::const_pointer const_pointer;

  typedef llrb_iterator<value_type> iterator;
  typedef llrb_const_iterator<value_type> const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

  typedef node* link_type;
  typedef const node* const_link_type;

  explicit llrb(const key_compare& compare = key_compare(),
                const allocator_type& allocator = allocator_type())
      : allocator_(allocator),
        key_comp_(compare),
        root_(NULL),
        begin_(new_node()),
        end_(begin_),
        size_(0) {
    end_->color = kBlack;
  }

  llrb(const llrb& origin)
      : allocator_(origin.allocator_),
        key_comp_(origin.key_comp_),
        root_(NULL),
        begin_(new_node()),
        end_(begin_),
        size_(0) {
    end_->color = kBlack;
    insert(origin.begin(), origin.end());
  }

  ~llrb() {
    if (empty()) {
      delete_node(end_);
      return;
    }
    delete_tree(root_);
  }

  llrb& operator=(const llrb& origin) {
    if (this != &origin) {
      llrb temp(origin);
      swap(temp);
    }
    return *this;
  }

  allocator_type get_allocator(void) { return allocator_; }
  key_compare key_comp(void) const { return key_comp_; }

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

  bool empty(void) const { return (size_ == 0); }
  size_type size(void) const { return size_; }
  size_type max_size(void) const { return allocator_.max_size(); }

  void clear(void) {
    llrb temp(key_comp_, allocator_);
    swap(temp);
  }

  ft::pair<iterator, bool> insert(const_reference value) {
    link_type new_link = new_node(value);
    ft::pair<link_type, bool> result = insert_node(new_link, root_, NULL);
    if (!result.second) {
      delete_node(new_link);
      return ft::make_pair(iterator(result.first), false);
    }
    size_ += 1;
    root_ = result.first;
    root_->color = kBlack;
    return ft::make_pair(iterator(new_link), true);
  }

  template <typename ForwardIterator>
  ForwardIterator insert(ForwardIterator position, const_reference value) {
    static_cast<void>(position);
    return insert(value).first;
  }

  template <typename InputIterator>
  void insert(InputIterator first, InputIterator last) {
    while (first != last) {
      insert(*first);
      ++first;
    }
  }

  template <typename InputIterator>
  void erase(InputIterator first, InputIterator last) {
    if (first == begin() && last == end()) {
      clear();
      return;
    }
    while (first != last) {
      InputIterator target = first;
      ++first;
      erase(*target);
    }
  }

  template <typename U>
  size_type erase(const U& value) {
    unset_bound();
    size_type old_size = size_;
    root_ = erase_node(value, root_);
    root_->color = kBlack;
    set_bound();
    return old_size - size_;
  }

  void swap(llrb& other) {
    std::swap(allocator_, other.allocator_);
    std::swap(key_comp_, other.key_comp_);
    std::swap(root_, other.root_);
    std::swap(begin_, other.begin_);
    std::swap(end_, other.end_);
    std::swap(size_, other.size_);
  }

  size_type count(const key_type& key) const {
    ft::pair<const_iterator, const_iterator> range = equal_range(key);
    return ft::distance(range.first, range.second);
  }

  iterator find(const key_type& key) { return iterator(find_node(key)); }

  const_iterator find(const key_type& key) const {
    return const_iterator(find_node(key));
  }

  ft::pair<iterator, iterator> equal_range(const key_type& key) {
    return ft::pair<iterator, iterator>(lower_bound(key), upper_bound(key));
  }

  ft::pair<const_iterator, const_iterator> equal_range(
      const key_type& key) const {
    return ft::pair<const_iterator, const_iterator>(lower_bound(key),
                                                    upper_bound(key));
  }

  iterator lower_bound(const key_type& key) {
    return iterator(lower_node(key));
  }

  const_iterator lower_bound(const key_type& key) const {
    return const_iterator(lower_node(key));
  }

  iterator upper_bound(const key_type& key) {
    return iterator(upper_node(key));
  }

  const_iterator upper_bound(const key_type& key) const {
    return const_iterator(upper_node(key));
  }

 private:
  template <typename U1, typename U2>
  bool is_equal(const U1& lhs, const U2& rhs) {
    return !key_comp_(lhs, rhs) && !key_comp_(rhs, lhs);
  }

  bool is_red(link_type link) { return link ? link->color : false; }

  void switch_color(link_type link) { link->color = !link->color; }

  void flip_color(link_type parent) {
    switch_color(parent);
    switch_color(parent->left);
    switch_color(parent->right);
  }

  link_type rotate_left(link_type pivot) {
    link_type child = pivot->right;
    pivot->right = child->left;
    if (pivot->right) {
      pivot->right->parent = pivot;
    }
    child->left = pivot;
    child->parent = pivot->parent;
    pivot->parent = child;
    child->color = pivot->color;
    pivot->color = kRed;
    return child;
  }

  link_type rotate_right(link_type pivot) {
    link_type child = pivot->left;
    pivot->left = child->right;
    if (pivot->left) {
      pivot->left->parent = pivot;
    }
    child->right = pivot;
    child->parent = pivot->parent;
    pivot->parent = child;
    child->color = pivot->color;
    pivot->color = kRed;
    return child;
  }

  link_type move_red_to_left(link_type link) {
    flip_color(link);
    if (link->right && is_red(link->right->left)) {
      link->right = rotate_right(link->right);
      link = rotate_left(link);
      flip_color(link);
    }
    return link;
  }

  link_type move_red_to_right(link_type link) {
    flip_color(link);
    if (link->left && is_red(link->left->left)) {
      link = rotate_right(link);
      flip_color(link);
    }
    return link;
  }

  link_type rebalance(link_type link) {
    if (is_red(link->right) && !is_red(link->left)) {
      link = rotate_left(link);
    }
    if (is_red(link->left) && is_red(link->left->left)) {
      link = rotate_right(link);
    }
    if (is_red(link->left) && is_red(link->right)) {
      flip_color(link);
    }
    return link;
  }

  void unset_bound(void) {
    if (root_) {
      end_->parent->right = NULL;
    }
  }

  void set_bound(void) {
    if (!root_) {
      begin_ = end_;
      return;
    }
    begin_ = node::min(root_);
    link_type max_link = node::max(root_);
    max_link->right = end_;
    end_->parent = max_link;
  }

  link_type new_node(const_reference value = value_type()) {
    link_type link = allocator_.allocate(1);
    allocator_.construct(link, value);
    return link;
  }

  ft::pair<link_type, bool> insert_node(link_type new_link, link_type link,
                                        link_type parent) {
    if (!link || link == end_) {
      new_link->parent = parent;
      if (!root_ || key_comp_(new_link->value, begin_->value)) {
        begin_ = new_link;
      }
      if (!root_ || key_comp_(end_->parent->value, new_link->value)) {
        new_link->right = end_;
        end_->parent = new_link;
      }
      return ft::make_pair(new_link, true);
    }
    if (key_comp_(new_link->value, link->value)) {
      ft::pair<link_type, bool> child = insert_node(new_link, link->left, link);
      if (!child.second) return child;
      link->left = child.first;
    } else if (key_comp_(link->value, new_link->value)) {
      ft::pair<link_type, bool> child =
          insert_node(new_link, link->right, link);
      if (!child.second) return child;
      link->right = child.first;
    } else {
      return ft::make_pair(link, false);
    }
    return ft::make_pair(rebalance(link), true);
  }

  link_type find_node(const key_type& key) const {
    link_type link = root_;
    while (link) {
      if (key_comp_(key, link->value)) {
        link = link->left;
      } else if (key_comp_(link->value, key)) {
        link = link->right;
      } else {
        return link;
      }
    }
    return end_;
  }

  link_type lower_node(const key_type& key) const {
    link_type link = root_;
    link_type bound = end_;
    while (link) {
      if (!key_comp_(link->value, key)) {
        bound = link;
        link = link->left;
      } else {
        link = link->right;
      }
    }
    return bound;
  }

  link_type upper_node(const key_type& key) const {
    link_type link = root_;
    link_type bound = end_;
    while (link) {
      if (key_comp_(key, link->value)) {
        bound = link;
        link = link->left;
      } else {
        link = link->right;
      }
    }
    return bound;
  }

  void set_parent(link_type child, link_type parent) {
    if (!child) return;
    child->parent = parent;
  }

  link_type swap_node(link_type link1, link_type link2) {
    link_type parent1 = link1->parent;
    link_type parent2 = link2->parent;
    link_type left1 = link1->left;
    link_type left2 = link2->left;
    link_type right1 = link1->right;
    link_type right2 = link2->right;

    if (parent1) {
      if (parent1->left == link1) {
        parent1->left = link2;
      } else {
        parent1->right = link2;
      }
      link2->parent = parent1;
    } else {
      root_ = link2;
      link2->parent = NULL;
    }

    link2->left = left1;
    set_parent(left1, link2);
    link1->left = left2;
    link1->right = right2;
    set_parent(right2, link1);

    if (link1 == parent2) {
      link2->right = link1;
      link1->parent = link2;
    } else {
      link2->right = right1;
      set_parent(right1, link2);
      parent2->left = link1;
      link1->parent = parent2;
    }
    std::swap(link1->color, link2->color);
    return link2;
  }

  link_type erase_min(link_type link) {
    if (!link->left) {
      delete_node(link);
      size_ -= 1;
      return NULL;
    }
    if (!is_red(link->left) && !is_red(link->left->left)) {
      link = move_red_to_left(link);
    }
    link->left = erase_min(link->left);
    return rebalance(link);
  }

  template <typename U>
  link_type erase_node(const U& value, link_type link) {
    if (key_comp_(value, link->value)) {
      if (link->left) {
        if (!is_red(link->left) && !is_red(link->left->left)) {
          link = move_red_to_left(link);
        }
        link->left = erase_node(value, link->left);
      }
    } else {
      if (is_red(link->left)) {
        link = rotate_right(link);
      }
      if (is_equal(value, link->value) && !link->right) {
        delete_node(link);
        size_ -= 1;
        return NULL;
      }
      if (link->right) {
        if (!is_red(link->right) && !is_red(link->right->left)) {
          link = move_red_to_right(link);
        }
        if (is_equal(value, link->value)) {
          link_type min_link = node::min(link->right);
          link = swap_node(link, min_link);
          link->right = erase_min(link->right);
        } else {
          link->right = erase_node(value, link->right);
        }
      }
    }
    return rebalance(link);
  }

  void delete_node(link_type link) {
    allocator_.destroy(link);
    allocator_.deallocate(link, 1);
  }

  void delete_tree(link_type link) {
    if (!link) return;
    delete_tree(link->left);
    delete_tree(link->right);
    delete_node(link);
  }

  node_allocator allocator_;
  key_compare key_comp_;
  link_type root_;
  link_type begin_;
  link_type end_;
  size_type size_;
};

template <typename Key, typename T, typename Compare, typename Allocator>
bool operator==(const llrb<Key, T, Compare, Allocator>& lhs,
                const llrb<Key, T, Compare, Allocator>& rhs) {
  return (lhs.size() == rhs.size()) &&
         ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool operator!=(const llrb<Key, T, Compare, Allocator>& lhs,
                const llrb<Key, T, Compare, Allocator>& rhs) {
  return !(lhs == rhs);
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool operator<(const llrb<Key, T, Compare, Allocator>& lhs,
               const llrb<Key, T, Compare, Allocator>& rhs) {
  return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(),
                                     rhs.end());
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool operator<=(const llrb<Key, T, Compare, Allocator>& lhs,
                const llrb<Key, T, Compare, Allocator>& rhs) {
  return !(rhs < lhs);
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool operator>(const llrb<Key, T, Compare, Allocator>& lhs,
               const llrb<Key, T, Compare, Allocator>& rhs) {
  return (rhs < lhs);
}

template <typename Key, typename T, typename Compare, typename Allocator>
bool operator>=(const llrb<Key, T, Compare, Allocator>& lhs,
                const llrb<Key, T, Compare, Allocator>& rhs) {
  return !(lhs < rhs);
}

template <typename Key, typename T, typename Compare, typename Allocator>
void swap(const llrb<Key, T, Compare, Allocator>& llrb1,
          const llrb<Key, T, Compare, Allocator>& llrb2) {
  llrb1.swap(llrb2);
}

}  // namespace ft

#endif
