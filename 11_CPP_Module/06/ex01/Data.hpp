#ifndef DATA_HPP_
#define DATA_HPP_

#include <cstdint>
#include <ctime>
#include <iostream>

struct Data {
  int id;
  time_t time;
  std::string menu;
  std::string address;
};

std::ostream& operator<<(std::ostream& out, const Data& data);

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif
