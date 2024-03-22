#ifndef CONSTANT_HPP_
#define CONSTANT_HPP_

#include <string>

enum IndexOfCommands {
  kAdd,
  kSearch,
  kExit,
};
enum IndexOfMessages {
  kDefault,
  kCommandError,
  kInputError,
};

const int kColumnWidth = 10;
const int kError = 0;
const int kNumOfCommands = 3;
const int kNumOfMessages = 3;

const std::string kFieldSeparator = "|";
const std::string kCommands[kNumOfCommands] = {"ADD", "SEARCH", "EXIT"};
const std::string kCommandMessages[kNumOfCommands] = {
    "추가할 연락처의 정보를 입력해 주세요.",
    "검색할 연락처의 인덱스를 입력해 주세요.", "프로그램을 종료합니다."};
const std::string kMessages[kNumOfMessages] = {
    "명령어를 입력해 주세요.", "명령어를 찾을 수 없습니다.",
    "입력값이 올바르지 않습니다. 다시 입력해 주세요."};

#endif
