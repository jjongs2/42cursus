<h1 align="center">CPP Module 06</h1>

<p align="center"><strong>C++ casts</strong></p>

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

### Exercise 00: Conversion of scalar types

`ScalarConverter` 클래스를 구현합니다.

- 문자열 리터럴을 인자로 받아 `char`, `int`, `float`, `double` 타입으로 변환합니다.
- 이 클래스는 인스턴스화할 수 없습니다.
- 오직 한 개의 정적 메서드 `convert`를 가집니다.

### Exercise 01: Serialization

다음과 같은 정적 메서드를 갖는 `Serializer` 클래스를 구현합니다.

- `uintptr_t serialize(Data* ptr)`: 포인터를 `uintptr_t` 타입으로 변환합니다.
- `Data* deserialize(uintptr_t raw)`: `uintptr_t` 타입을 `Data` 포인터로 변환합니다.

### Exercise 02: Identify real type

`Base` 클래스와 이를 상속받는 3개의 빈 클래스 `A`, `B`, `C`를 구현합니다.

- `Base` 클래스는 `public` `virtual` 소멸자만을 가집니다.
- `Base *generate(void)`: `A`, `B`, `C` 중 하나를 무작위로 인스턴스화하고 `Base` 포인터로 반환합니다.
- `void identify(Base* p)`: `p`가 가리키는 객체의 실제 타입을 출력합니다.
- `void identify(Base& p)`: `p`가 가리키는 객체의 실제 타입을 출력합니다. 함수 내부에서 포인터를 사용하는 것은 금지됩니다.

<br>

## Peer Review

|  닉네임  | 리뷰                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| :------: | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| seowokim | cpp 06 평가 진행하였습니다. 마침 곧 진행할 과제여서 궁금한 점이 많았는데 피평가자분께서 제가 드린 질문을 잘 답변해주셔서 큰 도움이 될 수 있을거 같습니다. 또한 cast에 대한 설명도 상세하셨습니다. 긴시간동안 고생하셨습니다!                                                                                                                                                                                                                                    |
| yonshin  | kijsong 님의 평가를 진행했습니다. 이번 과제는 static_cast, reinterpret_cat, dynamic_cast 의 차이점을 이해하고 직접사용해보며 연습하는 것이 목표였습니다. 전체적으로 코드를 간결하게 짜셨고 상황에 따라 const 를 사용하셨으며 출력되어야 하는 문자열을 한 소스파일에 모아두어 유지보수성을 높였으며 explicit 키워드를 사용하여 실수의 가능성을 줄인점에서 전체적으로 멋진 코드를 작성하셨습니다. 또한 위 세 캐스팅에 대하여 알려주셔서 감사드립니다. 감사합니다. |
