<h1 align="center">get_next_line</h1>

<p align="center"><strong>Reading a line from a fd is way too tedious</strong></p>

<div align="center">
  <strong>
    <a href="#summary">Summary</a> |
    <a href="#peer-review">Peer Review</a>
  </strong>
</div>

<br>

## Summary

**get_next_line**은 파일 디스크립터에서 한 줄을 읽어 반환하는 함수를 구현하는 프로젝트입니다.

### Learning Objectives

- 정적 변수의 사용법을 배웁니다.
- 파일 디스크립터를 통해 파일로부터 입력을 받습니다.

### Instructions

- 프로젝트는 C 언어로 작성되어야 합니다.
- [Norm](https://github.com/42School/norminette/blob/master/pdf/ko.norm.pdf)에 따라 코드를 작성해야 합니다.
- 함수가 예기치 않게 종료되어서는 안 됩니다. (segmentation fault, bus error, double free 등)
- 메모리 누수가 발생해서는 안 됩니다.
- `-Wall -Wextra -Werror` 플래그와 함께 소스 파일을 컴파일해야 합니다.

### Mandatory Part

|           항목 | 내용                                                                           |
| -------------: | :----------------------------------------------------------------------------- |
|  **함수 이름** | `get_next_line`                                                                |
| **프로토타입** | `char *get_next_line(int fd);`                                                 |
|  **제출 파일** | `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`                  |
|   **파라미터** | `fd`: 읽을 파일 디스크립터                                                     |
|    **반환 값** | 읽은 줄이 있으면 정상 동작, 읽을 것이 더 이상 없거나 에러가 발생한 경우 `NULL` |
|  **외부 함수** | `read`, `malloc`, `free`                                                       |
|       **설명** | 파일 디스크립터에서 한 줄을 읽어 반환하는 함수                                 |

### Bouns Part

- 하나의 정적 변수를 사용하여 `get_next_line`을 구현해야 합니다.
- 여러 파일 디스크립터를 동시에 관리할 수 있어야 합니다.

<br>

## Peer Review

|  닉네임  | 리뷰                                                                                                                                                                                                                                                                                                                                                                                                               |
| :------: | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|  epark   | 현재 libft 과제를 하던 중 get_next_line 과제를 평가하게 되었습니다! 기초적인 개념만 훑어 본 상태에서 평가를 진행하게 되었는데, 깔끔한 코드와 설명으로 이해하기 쉽게 평가를 진행해주신 덕분에 많은 지식을 얻어갈 수 있었습니다! 테스터기에서 정확하게 돌아가는 것을 확인했고, 논외로 libft 과제에 대한 질문들도 많이 했는데 모두 친절히 답해 주신 덕분에 많은 것들 알아갈 수 있는 시간이었습니다~! 고생하셨습니다!! |
|   soum   | 서브젝트 확인후에 소스코드 확인하면서 평가 진행하였습니다. 처음부터 끝까지 함수 하나하나 다 잘 설명해주셨습니다. 과제 금방 끝내신거 같은데 다음평가도 만점받으시고 다음 과제들도 화이팅하시길 바라겠습니다 고생하셨습니다                                                                                                                                                                                          |
| heecjang | 처음 본 문제였는대 이해하기 쉽게 설명을 잘 해주셨습니다. 제가 궁금했던 부분들에 대해서도 잘 알려주셔서 너무 감사했습니다. 보너스 부분들에 대해서 잘 알려주셨습니다. 각 함수들에 대해서도 어떻게 작동하는지도 잘 알려주셨습니다. 앞으로도 화이팅하시길 바랍니다. 수고하셨습니다.                                                                                                                                    |
