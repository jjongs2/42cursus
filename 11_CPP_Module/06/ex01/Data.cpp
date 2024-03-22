#include "Data.hpp"

#include "constant.hpp"

std::ostream& operator<<(std::ostream& out, const Data& data) {
  out << kDataInfo[kTitle] << '\n'
      << kDataInfo[kID] << data.id << '\n'
      << kDataInfo[kTime] << ctime(&data.time)
      << kDataInfo[kMenu] << data.menu << '\n'
      << kDataInfo[kAddress] << data.address << '\n';
  return out;
}

uintptr_t serialize(Data* ptr) { return reinterpret_cast<uintptr_t>(ptr); }

Data* deserialize(uintptr_t raw) { return reinterpret_cast<Data*>(raw); }
