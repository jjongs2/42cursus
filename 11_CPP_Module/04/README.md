<h1 align="center">CPP Module 04</h1>

<p align="center"><strong>Subtype polymorphism, abstract classes, interfaces</strong></p>

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
- 모든 클래스는 Orthodox Canonical Form에 따라 기본 생성자, 복사 생성자, 복사 할당 연산자, 소멸자를 가져야 합니다.

### Exercise 00: Polymorphism

기본 클래스 `Animal`과 파생 클래스 `Dog`, `Cat`을 구현합니다.

- `Animal` 클래스는 `protected` 속성 `std::string type`을 가집니다.
- `Dog`, `Cat` 클래스는 동물의 종류에 맞게 `type` 필드를 초기화합니다.
- 모든 클래스는 해당 동물의 울음소리를 출력하는 `makeSound()` 멤버 함수를 가집니다.

### Exercise 01: I don’t want to set the world on fire

`Brain` 클래스를 구현하여 `Dog`와 `Cat` 클래스에 추가합니다.

- `Brain` 클래스는 `std::string ideas[100]`를 속성으로 가집니다.
- `Dog`, `Cat` 클래스는 `Brain` 객체에 대한 포인터를 `private` 속성으로 가집니다.
- `Dog`, `Cat` 객체가 생성/소멸될 때 `Brain` 객체도 생성/소멸되어야 합니다.
- 객체 복사 시 깊은 복사가 이루어지도록 합니다.

### Exercise 02: Abstract class

`Animal` 클래스를 인스턴스화할 수 없도록 만듭니다.

### Exercise 03: Interface & recap

순수 추상 클래스를 이용하여 인터페이스를 구현합니다.

#### `AMateria` 클래스

- `AMateria* clone()`: Materia의 복제본을 생성하여 반환합니다.
- `void use(ICharacter& target)`: Materia가 사용될 때 특정 효과를 적용합니다.

#### `ICharacter` 인터페이스

- 캐릭터는 최대 4개의 Materia를 장착할 수 있습니다.
- `void equip(AMateria* m)`: 새로운 Materia를 장착합니다.
- `void unequip(int idx)`: Materia를 장착 해제하지만, 삭제하지는 않습니다.
- `void use(int idx, ICharacter& target)`: 장착된 Materia를 사용합니다.

#### `IMateriaSource` 인터페이스

- `void learnMateria(AMateria*)`: 새로운 Materia 타입을 학습합니다.
- `AMateria* createMateria(std::string const & type)`: 학습된 타입에 해당하는 새로운 Materia를 생성하여 반환합니다.

<br>

## Peer Review

|  닉네임  | 리뷰                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| :------: | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| yonhong  | 제가 C++을 사용해보지도 않았고, C++ 모듈 과제도 처음 평가하는 것이라 평가 받으시기가 많이 힘들으셨을텐데, C언어에 비유해주시면서 설명해줘가지고 이해하는데 있어서 너무 좋았습니다. 과제 자체도 하나하나 설명해주셔서 과제를 모르는 입장에서 하나도 불편함이 없었습니다. 감사합니다!!                                                                                                                                                                          |
| taeypark | 설명을 너무 잘 해주셔서 많은 것들을 배울 수 있어서 좋았습니다. 깊은 복사와 클래스에서 순수 가상 함수가 하나라도 있으면 추상 클래스가 되는데, 이 추상 클래스는 말 그대로 추상이어서 인스터스화는 안 되고, 상속을 받는 클래스에서 만들어준다는 걸 알려주셨습니다. 그리고 클래스의 모든 멤버 함수가 순수 가상 함수이고 생성자가 없으면 인터페이스 같은 역할을 하는 클래스를 만들 수 있다는 것도 알려주셨습니다. 설명을 잘 해주셔서 감사드립니다. 수고하셨습니다. |
