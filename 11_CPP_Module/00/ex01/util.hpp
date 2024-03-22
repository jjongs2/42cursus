#ifndef UTIL_HPP_
#define UTIL_HPP_

#include <string>

const int kNumOfColumns = 4;

const std::string kDisplayFields[kNumOfColumns] = {"index", "first name",
                                                   "last name", "nickname"};

void DisplayHead(void);
std::string SafeGetline(bool prompt = true);
int StrictStoi(int max_value, const std::string& input);

#endif
