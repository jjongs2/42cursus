#ifndef CONSTANT_HPP_
#define CONSTANT_HPP_

#include <string>

enum IndexOfMessages {
  kAnnounce,
  kDestroy,
};

const int kNumOfMessages = 2;

const std::string kMessages[kNumOfMessages] = {"BraiiiiiiinnnzzzZ...",
                                               " is destroyed."};

#endif
