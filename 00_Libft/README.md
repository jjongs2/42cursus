<h1 align="center">Libft</h1>

<p align="center"><strong>Your very first own library</strong></p>

<div align="center">
  <strong>
    <a href="#summary">Summary</a> |
    <a href="#structure">Structure</a> |
    <a href="#peer-review">Peer Review</a> |
		<a href="https://man7.org/linux/man-pages/index.html">Reference</a>
  </strong>
</div>

<br>

## Summary

**Libft**는 나만의 C 라이브러리를 구현하는 프로젝트입니다.

### Learning Objectives

- 표준 라이브러리 함수들의 동작 방식을 이해합니다.
- 리스트와 같은 기본적인 자료 구조를 직접 구현해 보며 이해도를 높입니다.
- 라이브러리를 생성하고 관리하는 방법을 배웁니다.
- 프로젝트의 빌드 프로세스를 자동화하기 위한 `Makefile` 작성법을 배웁니다.

### Instructions

- 프로젝트는 C 언어로 작성되어야 합니다.
- [Norm](https://github.com/42School/norminette/blob/master/pdf/ko.norm.pdf)에 따라 코드를 작성해야 합니다.
- 함수가 예기치 않게 종료되어서는 안 됩니다. (segmentation fault, bus error, double free 등)
- 메모리 누수가 발생해서는 안 됩니다.
- `-Wall -Wextra -Werror` 플래그와 함께 소스 파일을 컴파일해야 합니다.
- Makefile은 `$(NAME)`, `all`, `clean`, `fclean`, `re` 규칙을 포함해야 합니다.

<br>

## Structure

```shell
libft
├── include
│   ├── ft_ctype.h
│   ├── ft_list.h
│   ├── ft_stdio.h
│   ├── ft_stdlib.h
│   ├── ft_string.h
│   └── get_next_line.h
├── src
│   ├── ctype
│   │   ├── ft_isalnum.c
│   │   ├── ft_isalpha.c
│   │   ├── ft_isascii.c
│   │   ├── ft_isblank.c
│   │   ├── ft_isdigit.c
│   │   ├── ft_islower.c
│   │   ├── ft_isprint.c
│   │   ├── ft_isspace.c
│   │   ├── ft_isupper.c
│   │   ├── ft_tolower.c
│   │   └── ft_toupper.c
│   ├── list
│   │   ├── ft_lstadd_back.c
│   │   ├── ft_lstadd_front.c
│   │   ├── ft_lstclear.c
│   │   ├── ft_lstdelone.c
│   │   ├── ft_lstiter.c
│   │   ├── ft_lstlast.c
│   │   ├── ft_lstmap.c
│   │   ├── ft_lstnew.c
│   │   └── ft_lstsize.c
│   ├── stdio
│   │   ├── ft_putchar_fd.c
│   │   ├── ft_putendl_fd.c
│   │   ├── ft_putnbr_fd.c
│   │   ├── ft_putstr_fd.c
│   │   └── get_next_line.c
│   ├── stdlib
│   │   ├── ft_atoi.c
│   │   ├── ft_bsearch.c
│   │   ├── ft_calloc.c
│   │   ├── ft_free.c
│   │   └── ft_itoa.c
│   └── string
│       ├── ft_bzero.c
│       ├── ft_memchr.c
│       ├── ft_memcmp.c
│       ├── ft_memcpy.c
│       ├── ft_memmove.c
│       ├── ft_memset.c
│       ├── ft_split.c
│       ├── ft_strchr.c
│       ├── ft_strcmp.c
│       ├── ft_strcspn.c
│       ├── ft_strdup.c
│       ├── ft_striteri.c
│       ├── ft_strjoin.c
│       ├── ft_strlcat.c
│       ├── ft_strlcpy.c
│       ├── ft_strlen.c
│       ├── ft_strmapi.c
│       ├── ft_strncmp.c
│       ├── ft_strnstr.c
│       ├── ft_strrchr.c
│       ├── ft_strsep.c
│       ├── ft_strspn.c
│       ├── ft_strstr.c
│       ├── ft_strtok.c
│       ├── ft_strtrim.c
│       └── ft_substr.c
├── Makefile
└── README.md
```

<br>

## Peer Review

| 닉네임  | 리뷰                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| :-----: | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| euiclee | 코드를 하나하나씩 보면서 리뷰를 진행하였는데 전체적으로 코드를 가독성이 쉽고 간결하게 작성하신 것 같습니다. 특히 코드를 리뷰하면서 조건문 연산자를 사용하신 점이나, 어느 상황에서 배열과 포인터를 사용해서 코드를 구현해야 하는지 정확히 알고 계시는 것 같습니다. 코드 리뷰를 하면서 libft에 들어있는 함수들을 모두 명확히 숙지하시어 함수를 사용하신 것 같다는 느낌을 받았습니다. split함수에서 메모리 오류가 있었던 부분을 확인했는데 크게 문제가 없어서 이번에는 통과하실 것 같습니다. 코드를 리뷰하면서 정말 많이 배운 것 같습니다. 평가 받으시느라 수고 많으셨습니다! |
| sanhan  | 오랜만에 libft를 봐서 잘 기억이 나지 않는 함수들도 있었는데 친절하게 꼼꼼히 설명을 해주셨습니다. tester에서도 문제가 없었고 직접 main함수를 만들어 확인해 보았던 케이스들에서도 문제가 없었습니다. 125점 만점으로 통과하시기를 바라겠습니다. 과제 하시느라 고생하셨습니다. 좋은 하루 되세요:)                                                                                                                                                                                                                                                                              |
| junlee2 | 3번째 트라이이시다고 하셨는데, 그 경험이 잘 보이는 평가였던 것 같습니다. 노미네이트, 메이크파일, 컴파일, 테스터기 모두 문제 없이 잘 돌아갔고, 또 제가 질문하는 부분들에서 잘 디펜스를 해 주셨습니다. 또 테스터기 일부에서 NULL이 입력으로 들어왔을때, 크래쉬가 나지 않도록 잘 방어를 해 주셨기에 아웃스텐딩을 드립니다. 수고 많으셨습니다!! 감 화이팅 !!!!                                                                                                                                                                                                                 |
