#include "Data.hpp"

int main(void) {
  Data baemin = {42, time(NULL), "김치찜",
                 "서울특별시 강남구 개포로 416 새롬관"};
  std::cout << baemin << '\n';
  std::cout << *deserialize(serialize(&baemin)) << std::endl;
  return 0;
}
