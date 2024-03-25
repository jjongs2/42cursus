<h1 align="center">Philosophers</h1>

<p align="center"><strong>I never thought philosophy would be so deadly</strong></p>

<div align="center">
  <strong>
    <a href="#summary">Summary</a> |
    <a href="#getting-started">Getting Started</a> |
    <a href="#peer-review">Peer Review</a>
  </strong>
</div>

<br>

## Summary

**Philosophers**는 [식사하는 철학자 문제](https://en.wikipedia.org/wiki/Dining_philosophers_problem)를 해결하는 프로젝트입니다.

### Learning Objectives

- 스레드/프로세스를 생성하고 사용하는 방법을 배웁니다.
- 뮤텍스/세마포어의 개념과 사용법을 배웁니다.
- 동시성, 교착 상태와 같은 문제들을 이해하고 해결합니다.
- 스레드와 프로세스의 차이를 이해합니다.

### Instructions

- 프로젝트는 C 언어로 작성되어야 합니다.
- [Norm](https://github.com/42School/norminette/blob/master/pdf/ko.norm.pdf)에 따라 코드를 작성해야 합니다.
- 프로그램이 예기치 않게 종료되어서는 안 됩니다. (segmentation fault, bus error, double free 등)
- 메모리 누수가 발생해서는 안 됩니다.
- `-Wall -Wextra -Werror` 플래그와 함께 소스 파일을 컴파일해야 합니다.
- Makefile은 `$(NAME)`, `all`, `clean`, `fclean`, `re` 규칙을 포함해야 합니다.
- 각 철학자는 1부터 `number_of_philosophers`까지 인접한 순서대로 번호가 매겨집니다.
- 철학자의 상태 변화는 로그로 기록되어야 하며, 사망 메시지는 사망한 시점으로부터 10ms 이내에 표시되어야 합니다.
- 데이터 레이스가 발생하지 않도록 주의해야 합니다.
- 프로그램은 다음과 같은 인자를 받습니다. 모든 시간 단위는 밀리초(ms)입니다.

  | 이름                                        | 설명                                                                                                                                       |
  | ------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------ |
  | `number_of_philosophers`                    | 철학자의 수                                                                                                                                |
  | `time_to_die`                               | 철학자가 마지막 식사를 시작한 시점으로부터 `time_to_die` 밀리초가 지나면 사망합니다.                                                       |
  | `time_to_eat`                               | 철학자가 식사하는 데 필요한 시간. 식사 시간 동안 철학자는 두 포크를 모두 들고 있어야 합니다.                                               |
  | `time_to_sleep`                             | 철학자가 잠을 자는 데 필요한 시간                                                                                                          |
  | `number_of_times_each_philosopher_must_eat` | 모든 철학자가 이 횟수만큼 식사를 마치면 시뮬레이션이 종료됩니다. 지정되지 않은 경우, 어느 한 철학자가 사망했을 때 시뮬레이션이 종료됩니다. |

### Mandatory Part

- 각 철학자는 스레드로 구현되어야 합니다.
- 각 쌍의 철학자 사이에는 하나의 포크가 있습니다.
- 철학자가 포크를 중복해서 사용하지 않도록 각 포크의 상태는 뮤텍스로 보호되어야 합니다.

### Bouns Part

- 모든 포크는 테이블 중앙에 위치합니다.
- 포크의 수는 세마포어로 표현됩니다.
- 각 철학자는 프로세스로 구현되어야 하며, 메인 프로세스는 철학자가 아니어야 합니다.

<br>

## Getting Started

```shell
# 저장소 복제
$ git clone <저장소 URL>
$ cd <디렉터리 이름>

# 빌드
$ make

# 실행
$ ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [<number_of_times_each_philosopher_must_eat>]
```

<br>

## Peer Review

|  닉네임  | 리뷰                                                                                                                                                                                                                         |
| :------: | :--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| junhjeon | 제가 아직 시작하지않은 생소한 과제여서 난감했는데 서브젝트부터 코드까지 자세하게 설명해주신 덕분에 잘 이해할 수 있었습니다. 좋은 설명 감사합니다 ! :)                                                                        |
|  jmaing  | 코드도 모두 확인한 결과 subject, 평가지의 요구사항을 모두 만족하는 것을 확인할 수 있었습니다. 고생하셨습니다 :)                                                                                                              |
|  junseo  | 제가 하지 않았던 보너스 문제를 해결하셨기에 쏙쏙 잘 뽑아갑니닷,,! 확실히 다른 코드 컨벤션을 갖고 하시는 것 같아 저도 많이 배울 수 있었던 것 같습니다. 일요일 늦은 시간에 설명해 주시느라 정말 고생 많으셨습니다! 감사합니다. |
