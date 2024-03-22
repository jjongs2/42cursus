#ifndef EASYFIND_HPP_
#define EASYFIND_HPP_

#include <algorithm>

#include "constant.hpp"

template <typename T>
typename T::const_iterator easyfind(const T& container, int target) {
  typename T::const_iterator iter =
      std::find(container.begin(), container.end(), target);
  if (iter == container.end()) {
    throw std::runtime_error(kErrors[kNOENT]);
  }
  return iter;
}

#endif
