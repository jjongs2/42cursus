#ifndef CONSTANT_HPP_
#define CONSTANT_HPP_

#include <string>

enum IndexOfDataInfo {
  kTitle,
  kID,
  kTime,
  kMenu,
  kAddress,
};

const int kNumOfDataInfo = 5;

const std::string kDataInfo[kNumOfDataInfo] = {
    "[ 주문상세 ]", "주문번호: ", "주문시간: ", "주문내역: ", "배달주소: "};

#endif
