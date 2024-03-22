#ifndef PAIR_HPP_
#define PAIR_HPP_

namespace ft {

template <typename T1, typename T2>
struct pair {
  typedef T1 first_type;
  typedef T2 second_type;

  pair() : first(first_type()), second(second_type()) {}

  explicit pair(const first_type& value1, const second_type& value2)
      : first(value1), second(value2) {}

  template <typename U1, typename U2>
  pair(const pair<U1, U2>& origin)
      : first(origin.first), second(origin.second) {}

  pair& operator=(const pair& origin) {
    if (this != &origin) {
      first = origin.first;
      second = origin.second;
    }
    return *this;
  }

  first_type first;
  second_type second;
};

template <typename T1, typename T2>
pair<T1, T2> make_pair(T1 value1, T2 value2) {
  return pair<T1, T2>(value1, value2);
}

template <typename T1, typename T2>
bool operator==(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return (left.first == right.first) && (left.second == right.second);
}

template <typename T1, typename T2>
bool operator!=(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return !(left == right);
}

template <typename T1, typename T2>
bool operator<(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  if (left.first < right.first) return true;
  if (left.first > right.first) return false;
  if (left.second < right.second) return true;
  return false;
}

template <typename T1, typename T2>
bool operator<=(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return !(right < left);
}

template <typename T1, typename T2>
bool operator>(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return (right < left);
}

template <typename T1, typename T2>
bool operator>=(const pair<T1, T2>& left, const pair<T1, T2>& right) {
  return !(left < right);
}

}  // namespace ft

#endif
