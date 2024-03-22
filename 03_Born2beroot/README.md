<h1 align="center">Born2beroot</h1>

<p align="center"><strong>System Administration related exercise</strong></p>

<div align="center">
  <strong>
    <a href="#summary">Summary</a> |
    <a href="#peer-review">Peer Review</a>
  </strong>
</div>

<br>

## Summary

**Born2beroot**는 가상 머신을 주어진 지침에 따라 설정하는 프로젝트입니다.

### Instructions

- VirtualBox를 사용해야 합니다.

### Mandatory Part

#### 가상 머신 설정

- 최신 안정 버전의 Debian 또는 Rocky 중 하나를 선택해야 합니다.

#### 서버 설정

- 서버 설정에는 그래픽 인터페이스가 불필요하므로 X.org 또는 다른 그래픽 서버 설치가 금지됩니다.
- 최소 2개의 암호화된 파티션을 LVM을 사용하여 생성해야 합니다.

#### 보안 설정

- 4242번 포트에서만 SSH 서비스가 실행되어야 하며, root 계정으로의 SSH 접속은 허용되지 않습니다.
- UFW(Rocky의 경우 firewalld)를 사용하여 오직 4242번 포트만 열어야 합니다.
- 비밀번호는 최소 10자 이상이며 대문자, 소문자, 숫자를 포함해야 하고, 3개 이상의 연속된 동일 문자를 포함해서는 안 됩니다. 비밀번호는 30일마다 만료되어야 하며, 변경 전 최소 2일, 비밀번호 만료 7일 전에 경고 메시지를 받아야 합니다.
- sudo 사용 시 인증 시도는 3회로 제한되며, 오류 메시지를 정의해야 합니다. sudo로 수행한 모든 작업은 /var/log/sudo/ 폴더에 아카이브되어야 합니다.

#### 유저 및 호스트 설정

- 가상 머신의 호스트 이름은 유저 닉네임 뒤에 42를 붙여 설정해야 합니다. (예: user42)
- root 유저 외에도 유저 로그인 이름과 동일한 유저 계정을 만들어야 하며, 이 유저는 user42 및 sudo 그룹에 속해야 합니다.

#### 모니터링 스크립트

- 서버 시작 시 매 10분마다 시스템의 주요 정보(운영 체제의 아키텍처, 커널 버전, 물리 및 가상 프로세서 수, RAM 및 메모리 사용률, 프로세서 사용률, 마지막 부팅 시간, LVM 사용 여부, 활성 연결 수, 서버를 사용하는 유저 수, 서버의 IPv4 및 MAC 주소, sudo 프로그램으로 실행된 명령어 수 등)를 터미널에 표시해야 합니다.

### Bouns Part

- lighttpd, MariaDB, PHP를 포함한 워드프레스 웹사이트를 설정합니다.
- 그 외에 유용하다고 생각하는 서비스(NGINX / Apache2를 제외)를 설정합니다.

<br>

## Peer Review

| 닉네임  | 리뷰                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| :-----: | :--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| yejinam | 우선 라피신하실때 제가 러쉬평가 갔던분을 다시 만나게 되어서 너무 반가웠습니다!! 본과정 시작하신지 얼마 안되셧는데 저를 앞지르셨네요..ㅎㅎ 본투비 루트 평가를 여러번 해보앗는데 진행하는동안 notion같은걸 보지않고 진행하신분은 처음이라 너무 신기하고 멋있으셨습니다!! 설명들도 다 깔끔했고 놓치는 부분없이 꼼꼼히 설명해주셔서 막힘없이 평가를 진행할수 잇었습니다! 솔직히 본투비과제를 이렇게나 이해하실수 있으신게 너무 신기하네요 ㅎㅎ 수고하셨고 이번에는 꼭 125점 받으실수있으시길 바랍니다!!! |
| yehyun  | 저번에도 본투비루트 평가를 한번 진행했었는데, 이번에 다시 한번 진행하게 되었습니다. 전에와 달랐던 점은 쉘스크립트를 짜실 때 본인만의 방법대로 진행하셨다는 점이 달랐습니다. awk나 head tail 등의 명령어와 필요한 정보를 불러오는 명령어들을 제자리에 잘 고르신 것 같습니다. 이번에는 꼭 125점 꽉꽉 맞으셨으면 좋겠습니다. 수고하셨습니다!                                                                                                                                                            |
| kyuhkim | 훌륭하시네요 :) 코드 부분이 아닌 영역에서도 공부 많이 하시고, 내용들 깔끔하게 잘 정리하셨습니다. 보너스 부분도 유의미한 아이템을 선정하여 앞으로가 매우 기대됩니다. 고생 많으셨습니다 ^^                                                                                                                                                                                                                                                                                                             |