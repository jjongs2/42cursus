<h1 align="center">CPP Module 00</h1>

<p align="center"><strong>Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuff</strong></p>

<div align="center">
  <strong>
    <a href="#summary">Summary</a> |
    <a href="#peer-review">Peer Review</a>
  </strong>
</div>

<br>

## Summary

### Instructions

- 프로젝트는 C++98 표준을 준수해야 합니다.
- `-Wall -Wextra -Werror` 플래그와 함께 소스 파일을 컴파일해야 합니다.
- 클래스 이름은 UpperCamelCase 형식으로 작성되어야 합니다.
- STL 사용이 금지됩니다.
- 메모리 누수가 발생해서는 안 됩니다.

### Exercise 00: Megaphone

- 입력된 문자열을 대문자로 출력하는 간단한 기능을 수행합니다.
- 입력이 없을 경우 "LOUD AND UNBEARABLE FEEDBACK NOISE"를 출력합니다.

### Exercise 01: My Awesome PhoneBook

#### 기능

- 프로그램은 최대 8개의 연락처를 저장할 수 있습니다. 9번째 연락처를 추가하려고 할 때는 가장 오래된 연락처를 새 연락처로 대체합니다.
- 프로그램 시작 시 전화번호부는 비어 있으며, 사용자는 ADD, SEARCH, EXIT의 세 가지 명령어를 입력할 수 있습니다.

#### ADD 명령어

- 새 연락처 정보(이름, 성, 별명, 전화번호, 비밀)를 입력받습니다.
- 비어 있는 필드는 존재할 수 없습니다.

#### SEARCH 명령어

- 저장된 연락처를 4개의 열(인덱스, 이름, 성, 별명)로 표시합니다.
- 각 열의 너비는 10자로 고정되며, 보다 긴 텍스트는 '.'으로 잘려야 합니다.
- 사용자로부터 연락처의 인덱스를 입력받아 해당 연락처의 세부 정보를 표시합니다.

#### EXIT 명령어

- 프로그램을 종료하며, 저장된 연락처 정보는 제거됩니다.

### Exercise 02: The Job Of Your Dreams

- 실수로 삭제된 `Account.cpp` 파일을 복구하는 작업을 수행합니다.
- `Account.hpp` 헤더 파일과 로그 파일을 참고하여 `Account.cpp`를 재작성해야 합니다.

<br>

## Peer Review

|  닉네임  | 리뷰                                                                                                                                                                                                                          |
| :------: | :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| sangwoki | c++에 대해서 너무 잘 배웠습니다. 제가 그 전에 평가했던 과제였는데, 그 전 분은 02를 안하셨지만 이 분은 다 하셔서 많이 배울 수 있었습니다. 코드가 깔끔하고 가독성이 높아서 너무 많이 배웠고 재밌었습니다. 고생 많이 하셨습니다. |
|  namkim  | c++00평가는 처음입니다! 함수를 최대한 감싸서 재사용하는 부분이 인상깊었습니다. 삼항연산자를 사용한 구조나 ctime 라이브러리를 사용한 strftime등의 스킬을 배워갑니다! 평가받으시느라 수고하셨습니다.                            |
