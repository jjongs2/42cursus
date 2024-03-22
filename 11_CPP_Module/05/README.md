<h1 align="center">CPP Module 05</h1>

<p align="center"><strong>Repetition and Exceptions</strong></p>

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

### Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!

`Bureaucrat` 클래스를 구현합니다.

#### 속성

- 이름
- 등급 (최고 1, 최저 150)

#### 멤버 함수

- 등급을 증가/감소시키는 함수

#### 추가 사항

- 등급이 유효하지 않은 경우 `Bureaucrat::GradeTooHighException` 또는 `Bureaucrat::GradeTooLowException` 예외가 발생합니다.
- 객체의 상태를 출력하는 `<<` 연산자 오버로딩을 구현합니다.

### Exercise 01: Form up, maggots!

`Form` 클래스를 구현합니다.

#### 속성

- 이름
- 서명 여부
- 서명/집행에 요구되는 등급 (최고 1, 최저 150)

#### 멤버 함수

- `beSigned()`: `Bureaucrat` 객체를 인자로 받아 서명을 시도합니다.
- `signForm()`: 서명 성공/실패 메시지를 출력합니다.

#### 추가 사항

- 모든 속성은 `private`으로 선언됩니다.

### Exercise 02: No, you need form 28B, not 28C...

`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm` 클래스를 구현합니다.

| 이름                     | 서명 요구 등급 | 집행 요구 등급 | 설명                                                                              |
| ------------------------ | -------------- | -------------- | --------------------------------------------------------------------------------- |
| `ShrubberyCreationForm`  | 145            | 137            | 작업 디렉터리에 `<target>_shrubbery` 파일을 생성하고 ASCII 트리를 그립니다.       |
| `RobotomyRequestForm`    | 72             | 45             | 드릴 소리를 내며 대상이 로봇화에 성공/실패했다고 알립니다. 성공 확률은 50%입니다. |
| `PresidentialPardonForm` | 25             | 5              | 대상이 Zaphod Beeblebrox에 의해 사면받았다고 알립니다.                            |

#### 추가 사항

- 모든 클래스는 `target`을 인자로 받는 생성자를 가집니다.
- 기존의 `Form` 클래스는 추상 클래스 `AForm`으로 변경됩니다.
- `AForm` 클래스에 멤버 함수 `void execute(Bureaucrat const & executor)`를 추가합니다.
- `Bureaucrat` 클래스에 멤버 함수 `void executeForm(AForm const & form)`를 추가합니다.

### Exercise 03: At least this beats coffee-making

`Intern` 클래스를 구현합니다.

#### 속성

- 인턴에게는 이름과 등급이 없습니다.

#### 멤버 함수

- `makeForm()`: 폼 이름과 `target`을 인자로 받아 해당 폼 객체를 생성하여 반환합니다.

<br>

## Peer Review

|  닉네임  | 리뷰                                                                                                                                                                                                                                                                                                                                                                                    |
| :------: | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|  ekwak   | cpp 두번째 평가여서 클래스 구조에 대해 아주 조금 아는 상태로 설명을 들었는데 설명을 정말 깔끔하게 잘 해주셔서 이해하는데 문제가 없었고 코드 구성이 깔끔하셔서 놀랐습니다 과제에서 요구하는 바를 정확하게 맞춰서 코딩하셨다는 느낌을 많이 받았습니다 수고하셨습니다!                                                                                                                     |
| seojulee | 객체지향의 개념 정도만 알고 C++ 언어에 대해서 전혀 모르는 상태에서 잡힌 CPP Module 과제 평가여서 평가전에 걱정도 많았고 부담도 있었는데 친절하고 막힘없이 설명해주시고, 질문한 C++의 명령어나 객체지향적인 문법에 대해서도 충분히 설명을 해주셔서 평가를 하는데 어려움이 없었습니다. 이 평가를 하고나서 C++ 코드를 보면 어느정도 이해할 수 있을것 같습니다. 평가받느라 수고하셨습니다!! |
