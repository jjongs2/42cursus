<h1 align="center">CPP Module 01</h1>

<p align="center"><strong>Memory allocation, pointers to members, references, switch statement</strong></p>

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

### Exercise 00: BraiiiiiiinnnzzzZ

`Zombie` 클래스를 구현해야 합니다.

#### 속성

- `name`: 문자열

#### 멤버 함수

- `void announce(void)`: 좀비가 자신을 다음과 같이 공지합니다: `<name>: BraiiiiiiinnnzzzZ...`
- `Zombie* newZombie(std::string name)`: 주어진 이름의 좀비를 생성하여 반환합니다.
- `void randomChump(std::string name)`: 주어진 이름의 좀비를 생성하고, 생성된 좀비가 자신을 공지하도록 합니다.

#### 유의 사항

- 스택과 힙 할당의 차이를 이해하고 적절히 사용합니다.
- 좀비가 더 이상 필요 없을 때 소멸되어야 하며, 소멸자는 디버깅 목적으로 좀비의 이름을 출력합니다.

### Exercise 01: Moar brainz!

함수 `Zombie* zombieHorde(int N, std::string name)`를 구현해야 합니다.

- 이름이 `name`인 `N`개의 `Zombie` 객체를 한 번의 할당으로 생성하여 첫 번째 좀비에 대한 포인터를 반환합니다.
- 생성된 모든 좀비가 `announce()`를 통해 자신을 공지하도록 합니다.
- 모든 좀비 객체를 할당 해제하고 메모리 누수가 없는지 확인합니다.

### Exercise 02: HI THIS IS BRAIN

- 문자열 변수 하나를 "HI THIS IS BRAIN"으로 초기화합니다.
- 해당 문자열 변수를 가리키는 포인터(`stringPTR`)와 참조(`stringREF`)를 선언합니다.
- 문자열 변수의 메모리 주소, `stringPTR`이 가리키는 주소, `stringREF`가 가리키는 주소를 출력합니다.
- 문자열 변수의 값, `stringPTR`을 통해 접근한 값, `stringREF`를 통해 접근한 값을 출력합니다.

### Exercise 03: Unnecessary violence

- `Weapon` 클래스: 문자열 속성 `type`과 멤버 함수 `getType()`, `setType()`을 가집니다.
- `HumanA`, `HumanB` 클래스: 속성 `Weapon`과 `name`을 가지며, 멤버 함수 `attack()`을 통해 공격을 공지합니다.
- `HumanA`는 생성자에서 `Weapon`을 받지만, `HumanB`는 그렇지 않습니다.
- `HumanB`는 무기가 없을 수 있으나, `HumanA`는 항상 무기를 지니고 있습니다.

### Exercise 04: Sed is for losers

- 프로그램은 3개의 인자(`filename`, `s1`, `s2`)를 받습니다.
- 지정된 파일을 열고, 내용에서 나타나는 모든 `s1`을 `s2`로 대체하여 새 파일 `<filename>.replace`에 복사합니다.

### Exercise 05: Harl 2.0

- `Harl` 클래스: `private` 멤버 함수(`debug()`, `info()`, `warning()`, `error()`)를 가집니다.
- `void complain(std::string level)` 멤버 함수: 주어진 레벨에 따라 적절한 함수를 호출합니다.

### Exercise 06: Harl filter

- 프로그램은 위의 4가지 레벨 중 하나를 인자로 받습니다.
- 지정된 레벨 이상의 모든 메시지를 출력합니다.
- `switch` 구문을 통해 각 레벨에 맞는 메시지를 필터링하고 출력합니다.

<br>

## Peer Review

|  닉네임  | 리뷰                                                                                                                                                                                                                                                                                                                                                         |
| :------: | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| younhwan | kijsong님의 CPP module 01 평가를 했습니다. Makefile에서의 flag들도 모두 빈틈없이 동작하고 있었고, leak 또한 검출되지 않았습니다. 구현이 매우 깔끔하게 되어있어서 크게 직접 테스트를 해볼 필요 조차 없었던 코드였다고 생각됩니다. 금방 뚫으실거라 생각되고 5서클, 6서클까지 파이팅하세요!! :)                                                                 |
|  joyoo   | CPP 01번 과제 평가를 진행했습니다. 제가 C++를 이전에 공부했던 경험이 도움이 되어, 평가를 빠르게 진행할 수 있었던 것 같습니다. 3서클 과제 빠르게 밀고 CPP 과제를 진행하고자 하는데 이번 평가로 인해 CPP에서 어떤 문제들을 다루는지 개요를 알게 되었고, 궁금한 키워드들에 대해서 친절하게 설명해주셔서 저도 빨리 CPP 풀고 싶어지네요 ㅎㅎ 수고하셨습니다! ^\_^ |
